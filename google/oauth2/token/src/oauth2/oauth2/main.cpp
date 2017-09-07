// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>			// TCHAR�^
#include <stdio.h>			// C�W�����o��
#include <iostream>			// C++�W�����o��
#include <string>			// std::string
#include <winsock2.h>		// Windows�\�P�b�g
#include <ws2tcpip.h>		// WinSock2 TCP/IP
#include <openssl/bio.h>	// BIO 
#include <openssl/ssl.h>	// SSL
#include <openssl/err.h>	// �G���[
// �Ǝ��̃w�b�_
#include "credentials.h"	// �F�؏��

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// _tmain�֐��̒�`
int _tmain() {

	// �ϐ��̐錾�Ə�����.
	WSADATA wsaData;	// WSADATA�^wsaData.
	int iRet;			// int�^iRet.
	struct addrinfo hint = { 0 };	// addrinfo�\����hint��0�ŏ�����.
	struct addrinfo *ai;	// addrinfo�\���̃|�C���^ai.
	int soc = -1;	// �\�P�b�g�t�@�C���f�B�X�N���v�^soc��-1�ɏ�����.
	SSL_CTX *ctx = NULL;	// SSL_CTX�\���̂ւ̃|�C���^ctx��NULL�ɏ�����.
	SSL *ssl = NULL;	// SSL�ڑ���������SSL�\���̂ւ̃|�C���^ssl��NULL�ɏ�����.
	tstring request_tstr;	// ���N�G�X�g������request_tstr.
	int len;	// �����R�[�h�ϊ���̒���len.
	char request_str[4096];	// �����R�[�h�ϊ���̃��N�G�X�g������request_str.
	int written = 0;	// SSL_write�ł̏������݂ɐ�����������written.
	char response_buf[1024] = { 0 };	// char�^�z��response_buf(�v�f��1024)��0�ŏ�����.
	int response_len = 0;	// SSL_read�œǂݍ��񂾒������i�[����response_len��0�ŏ�����.
	tstring code;	// tstring�^code.
	tstring body_tstr;	// �{�f�B������body_tstr.
	char body_str[1024] = { 0 };	// char�^�z��body_str(�v�f��1024)��0�ŏ�����.
	int content_length = 0;	// int�^content_length��0�ŏ�����.
	TCHAR content_length_tstr[32] = { 0 };	// TCHAR�^�z��content_length_tstr(����32)��0�ŏ�����.

	// ���͂��ꂽcode���i�[.
	std::wcout << _T("code: ");	// "code: ".
	std::wcin >> code;	// code�Ɋi�[.

	// WinSock�̏�����.
	iRet = WSAStartup(MAKEWORD(2, 2), &wsaData);	// WSAStartup��WinSock�̏�����.
	if (iRet) {	// 0�łȂ��ꍇ.

		// �G���[����.
		_tprintf(_T("Error!(iRet = %d.)\n"), iRet);	// _tprintf��iRet���o��.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ�.

	}

	// �������������b�Z�[�W.
	_tprintf(_T("WSAStartup success!\n"));	// "WSAStartup success!"�Əo��.

	// �t�@�~���[�ƃ\�P�b�g�^�C�v�̃Z�b�g.
	hint.ai_family = AF_INET;	// �t�@�~���[��AF_INET.
	hint.ai_socktype = SOCK_STREAM;	// �\�P�b�g�^�C�v��SOCK_STREAM.

	// addrinfo�\���̂̎擾.
	iRet = getaddrinfo("accounts.google.com", "https", &hint, &ai);	// getaddrinfo�Ńz�X�g���擾.
	if (iRet) {	// 0�ȊO�̓G���[.

		// �G���[����.
		_tprintf(_T("Error!(iRet = %d.)\n"), iRet);	// _tprintf��iRet���o��.
		WSACleanup();	// WSACleanup�ŏI������.
		return -2;	// -2��Ԃ�.

	}

	// �\�P�b�g�̐���.
	soc = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);	// socket��ai�̃����o��n����soc�𐶐�.
	if (soc == -1) {	// -1�ŃG���[.

		// �G���[����.
		_tprintf(_T("Error!(soc = %d.)\n"), soc);	// _tprintf��soc���o��.
		freeaddrinfo(ai);	// freeaddrinfo��ai�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -3;	// -3��Ԃ�.

	}

	// soc���o��.
	_tprintf(_T("soc = %d\n"), soc);	// _tprintf��soc���o��.

	// �ڑ�
	iRet = connect(soc, ai->ai_addr, ai->ai_addrlen);	// connect�Őڑ�.
	if (iRet == -1) {	// -1���ƃG���[.

		// �G���[����.
		closesocket(soc);	// closesocket��soc�����.
		freeaddrinfo(ai);	// freeaddrinfo��ai�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -4;	// -4��Ԃ�.

	}

	// �ڑ�����.
	_tprintf(_T("connect success!\n"));	// _tprintf��"connect success!"���o��.

	// SSL���C�u�����̏�����.
	SSL_library_init();	// SSL_library_init��SSL���C�u�����̏�����.
	SSL_load_error_strings();	// SSL_load_error_strings�ŃG���[����������[�h.

	// SSL�R���e�L�X�g�̍쐬.
	ctx = SSL_CTX_new(SSLv23_client_method());	// SSL_CTX_new��SSL�R���e�L�X�g���쐬��, SSL_CTX�^�|�C���^�Ƃ���ctx�Ɋi�[.

	// ctx�̎w���A�h���X���o��.
	_tprintf(_T("ctx = %08x\n"), (unsigned int)ctx);	// _tprintf��ctx�̎w���A�h���X���o��.

	// SSL�ڑ����̍쐬.
	ssl = SSL_new(ctx);	// SSL_new��ctx����SSL�ڑ������쐬��, �|�C���^��ssl�Ɋi�[.

	// ssl�̎w���A�h���X���o��.
	_tprintf(_T("ssl = %08x\n"), (unsigned int)ssl);	// _tprintf��ssl�̎w���A�h���X���o��.

	// SSL�ڑ����Ƀ\�P�b�g�t�@�C���f�B�X�N���v�^���Z�b�g.
	if (SSL_set_fd(ssl, soc) == 0) {	// SSL_set_fd��ssl��soc���Z�b�g.(�߂�l��0�Ȃ玸�s, 1�Ȃ琬��.)

		// �G���[����
		_tprintf(_T("SSL_set_fd error!\n"));	// "SSL_set_fd error!"�Əo��.
		ERR_print_errors_fp(stderr);	// ERR_print_errors_fp��stderr��n���ĕW���G���[�o�͂ɃG���[���b�Z�[�W���o��.
		SSL_free(ssl);	// SSL_free��ssl�����.
		SSL_CTX_free(ctx);	// SSL_CTX_free��ctx�����.
		closesocket(soc);	// closesocket��soc�����.
		freeaddrinfo(ai);	// freeaddrinfo��ai�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -5;	// -5��Ԃ�.

	}

	// ����
	_tprintf(_T("SSL_set_fd success!\n"));	// "SSL_set_fd success!"�Əo��.

	// SSL�ڑ�
	iRet = SSL_connect(ssl);	// SSL_connect��ssl��n����SSL�n���h�V�F�C�N���s��.
	if (iRet == 1) {	// ����
		_tprintf(_T("SSL_connect success!\n"));	// "SSL_connect success!"�Əo��.
	}
	else {	// �G���[

		// �G���[����
		_tprintf(_T("SSL_connect error!\n"));	// "SSL_connect error!"�Əo��.
		SSL_free(ssl);	// SSL_free��ssl�����.
		SSL_CTX_free(ctx);	// SSL_CTX_free��ctx�����.
		closesocket(soc);	// closesocket��soc�����.
		freeaddrinfo(ai);	// freeaddrinfo��ai�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -6;	// -6��Ԃ�.

	}

	// POST�{�f�B�̍쐬.
	body_tstr = body_tstr + _T("client_id=");	// body_tstr��"client_id="���i�[.
	body_tstr = body_tstr + CLIENT_ID;	// body_tstr��CLIENT_ID��A��.
	body_tstr = body_tstr + _T("&client_secret=");	// body_tstr��"&client_secret="��A��.
	body_tstr = body_tstr + CLIENT_SECRET;	// body_tstr��CLIENT_SECRET��A��.
	body_tstr = body_tstr + _T("&code=");	// body_tstr��"&code="��A��.
	body_tstr = body_tstr + code;	// body_tstr��code��A��.
	body_tstr = body_tstr + _T("&redirect_uri=");	// body_tstr��"&redirect_uri="��A��.
	body_tstr = body_tstr + REDIRECT_URI;	// body_tstr��REDIRECT_URI��A��.
	body_tstr = body_tstr + _T("&grant_type=");	// body_tstr��"&grant_type="��A��.
	body_tstr = body_tstr + _T("authorization_code");	// body_tstr��"authorization_code"��A��.

	// POST�{�f�B�̕����R�[�h�ϊ�(���ۂɂ͒��������킩���content_length���w��ł���.)
	len = WideCharToMultiByte(CP_UTF8, 0, body_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	content_length = len - 1;	// content_length��len - 1.
	_stprintf_s(content_length_tstr, _T("%d"), content_length);	// content_length��content_length_tstr�ɕϊ�.

	// ���N�G�X�g�̍쐬.
	request_tstr = _T("POST /o/oauth2/token HTTP/1.0");	// request_tstr��"POST /o/oauth2/token HTTP/1.0"���i�[.
	request_tstr = request_tstr + _T("\r\n");	// ���s
	request_tstr = request_tstr + _T("Host: accounts.google.com");	// request_tstr��"Host: accounts.google.com"��A��.
	request_tstr = request_tstr + _T("\r\n");	// ���s
	request_tstr = request_tstr + _T("Content-Type: application/x-www-form-urlencoded");	// request_tstr��"Content-Type: application/x-www-form-urlencoded"��A��.
	request_tstr = request_tstr + _T("\r\n");	// ���s
	request_tstr = request_tstr + _T("Content-Length: ");	// request_tstr��"Content-Length: "��A��.
	request_tstr = request_tstr + content_length_tstr;	// request_tstr��content_length_tstr��A��.
	request_tstr = request_tstr + _T("\r\n\r\n");	// ��s
	request_tstr = request_tstr + body_tstr;	// request_tstr��body_tstr��A��.

	// request_tstr�̕����R�[�h�ϊ�(Unicode => utf-8)
	len = WideCharToMultiByte(CP_UTF8, 0, request_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_UTF8, 0, request_tstr.c_str(), -1, request_str, len, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.

	// ���N�G�X�g�̏�������.
	written = SSL_write(ssl, request_str, len);	// SSL_write��request_str����������.
	printf("SSL_write written = %d\n", written);	// SSL_write�ŏ������ݐ����������������o��.

	// ���X�|���X�̓ǂݍ���.
	while ((response_len = SSL_read(ssl, response_buf, 1024 - 1)) > 0) {	// SSL_read�œǂݍ��񂾃��X�|���X��response_buf�Ɋi�[.(1�o�C�g�ȏ�Ȃ瑱����.)

		// response_buf�̓��e���o��.
		printf("%s", response_buf);	// printf��response_buf���o��.
		memset(response_buf, 0, sizeof(char) * 1024);	// memset��response_buf���N���A.

	}

	// ���s
	printf("\n");	// printf�ŉ��s.

	// SSL�ؒf.
	SSL_shutdown(ssl);	// SSL_shutdown��SSL�ؒf����.

	// SSL�ڑ����̔j��.
	SSL_free(ssl);	// SSL_free��ssl�����.

	// SSL�R���e�L�X�g�̉��.
	SSL_CTX_free(ctx);	// SSL_CTX_free��ctx�����.

	// soc�����.
	closesocket(soc);	// closesocket��soc�����.

	// ai�����.
	freeaddrinfo(ai);	// freeaddrinfo��ai�����.

	// WinSock�̏I������.
	WSACleanup();	// WSACleanup�ŏI������.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ�.

}