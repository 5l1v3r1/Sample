// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>			// TCHAR�^
#include <iostream>			// C++�W�����o��
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

// �֐��̃v���g�^�C�v�錾
void urlencode(char dst[], const char src[], int src_len);	// URL�G���R�[�h.

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
	char redirect_uri[1024] = { 0 };	// char�^���_�C���N�gURI utf-8�������0�ŏ�����.
	char urlencoded_redirect_uri[1024] = { 0 };	// URL�G���R�[�h�ς݂̃��_�C���N�gURI utf-8�������0�ŏ�����.
	TCHAR urlencoded_redirect_uri_tstr[1024] = { 0 };	// URL�G���R�[�h�ς݂̃��_�C���N�gURI TCHAR�������0�ŏ�����.

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

	// �����R�[�h�ϊ���URL�G���R�[�h
	len = WideCharToMultiByte(CP_UTF8, 0, REDIRECT_URI, -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_UTF8, 0, REDIRECT_URI, -1, redirect_uri, len, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.
	urlencode(urlencoded_redirect_uri, redirect_uri, len - 1);	// ����֐�urlencode��redirect_uri��URL�G���R�[�h.
	len = MultiByteToWideChar(CP_UTF8, 0, urlencoded_redirect_uri, -1, NULL, 0);	// ���C�h�����ɕϊ����邽�߂̃T�C�Y�擾.
	MultiByteToWideChar(CP_UTF8, 0, urlencoded_redirect_uri, -1, urlencoded_redirect_uri_tstr, len);	// ���C�h�����ɕϊ�.

	// GET���N�G�X�g������̍쐬.
	request_tstr = _T("GET /o/oauth2/auth?client_id=");	// request_tstr��"GET /o/oauth2/auth?client_id="���i�[.
	request_tstr = request_tstr + CLIENT_ID;	// request_tstr��CLIENT_ID��A��.
	request_tstr = request_tstr + _T("&redirect_uri=");	// request_tstr��"&redirect_uri="��A��.
	request_tstr = request_tstr + urlencoded_redirect_uri_tstr;	// request_tstr��urlencoded_redirect_uri_tstr��A��.
	request_tstr = request_tstr + _T("&response_type=");	// request_tstr��"&response_type="��A��.
	request_tstr = request_tstr + _T("code");	// request_tstr��"code"��A��.
	request_tstr = request_tstr + _T("&scope=");	// request_tstr��"&scope="��A��.
	request_tstr = request_tstr + SCOPE;	// request_tstr��SCOPE��A��.]
	request_tstr = request_tstr + _T("&approval_prompt=");	// request_tstr��"&approval_prompt="��A��.
	request_tstr = request_tstr + _T("force");	// request_tstr��"force"��A��.
	request_tstr = request_tstr + _T("&access_type=");	// request_tstr��"&access_type="��A��.
	request_tstr = request_tstr + _T("offline");	// request_tstr��"offline"��A��.
	request_tstr = request_tstr + _T(" HTTP/1.0");	// request_tstr��" HTTP/1.0"��A��.(1.1���ƂȂ���BadRequest�ɂȂ�.)
	request_tstr = request_tstr + _T("\r\n");	// ���s
	request_tstr = request_tstr + _T("Host: accounts.google.com");	// request_tstr��"Host: accounts.google.com"��A��.
	request_tstr = request_tstr + _T("\r\n");	// ���s
	request_tstr = request_tstr + _T("User-Agent: bgst1yt1test");	// request_tstr��"User-Agent: bgst1yt1test"��A��.
	request_tstr = request_tstr + _T("\r\n\r\n");	// ��s

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

// URL�G���R�[�h.
void urlencode(char dst[], const char src[], int src_len) {

	// �ϐ��̐錾.
	int i = 0;	// ���[�v�p�ϐ�i��0�ŏ�����.
	int j = 0;	// �i�[��̈ʒu�ϐ�j��0�ŏ�����.
	char c;	// ���o��������c.
	char urlenc[4];	// �ϊ��ςݕ�����urlenc.
	char buf[1024] = { 0 };	// �ꎞ�o�b�t�@��0�ŏ�����.

	// src��buf�ɃR�s�[.(src�͈ێ�����Ă�Ƃ͌���Ȃ��̂�.)
	strcpy_s(buf, sizeof(char) * 1024, src);	// strcpy_s��src��buf�ɃR�s�[.

	// URL�G���R�[�h����.
	for (i = 0; i < src_len; i++) {	// len�̐������J��Ԃ�.
		c = buf[i];	// buf��i�Ԗڂ�c�Ɋi�[.
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.' || c == '~') {	// �A���t�@�x�b�g, ����, �n�C�t��, �A���_�[�X�R�A, �h�b�g, �`���_�Ȃ�.
			dst[j] = c;	// dst[j]��c���i�[.
			dst[j + 1] = '\0';	// dst[j + 1]��'\0'���i�[.
			j++;	// j��1���₷.
		}
		else {
			snprintf(urlenc, sizeof(urlenc), "%%%02x", c & 0xff);	// c��"%xx"�`���ɂ���urlenc�Ɋi�[.
			for (int k = 0; k < 3; k++) {
				urlenc[k] = toupper(urlenc[k]);
			}
			strcat_s(dst, sizeof(char) * 1024, urlenc);	// urlenc��dst�ɘA��.
			j = j + 3;	// j��3���₷.
		}
	}

}