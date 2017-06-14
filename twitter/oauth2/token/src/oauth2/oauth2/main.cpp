// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>			// TCHAR�^
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
	int iRet;	// int�^iRet.
	struct addrinfo hint = { 0 };	// addrinfo�\����hint��0�ŏ�����.
	struct addrinfo *ai;			// addrinfo�\���̃|�C���^ai.
	int soc = -1;	// �\�P�b�g�t�@�C���f�B�X�N���v�^soc��-1�ɏ�����.
	SSL_CTX *ctx = NULL;	// SSL_CTX�\���̂ւ̃|�C���^ctx��NULL�ɏ�����.
	SSL *ssl = NULL;	// SSL�ڑ���������SSL�\���̂ւ̃|�C���^ssl��NULL�ɏ�����.
	std::string credentials_str;	// �N���f���V�����\��������credentials_str.
	BIO *mem = NULL;	// �������f�[�^�V���NBIO��NULL�ɃZ�b�g.
	BIO *base64 = NULL;	// Base64�t�B���^BIO��NULL�ɃZ�b�g.
	char base64_str[1024] = { 0 };	// char�^�z��base64_str��0�ŏ�����.
	tstring request_tstr;	// ���N�G�X�g������request_tstr.
	int written = 0;	// SSL_write�ł̏������݂ɐ�����������written.
	char response_buf[1024] = { 0 };	// char�^�z��response_buf(�v�f��1024)��0�ŏ�����.
	int response_len = 0;	// SSL_read�œǂݍ��񂾒������i�[����response_len��0�ŏ�����.

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
	iRet = getaddrinfo("api.twitter.com", "https", &hint, &ai);	// getaddrinfo�Ńz�X�g���擾.
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

	// �N���f���V�����쐬.
	credentials_str = API_KEY;	// credentials_str��API_KEY���i�[.
	credentials_str = credentials_str + ":";		// ":"��A��.
	credentials_str = credentials_str + API_SECRET;	// API_SECRET��A��.

	// �N���f���V������������o��.
	printf("credentials_str = %s\n", credentials_str.c_str());

	// base64�ɕϊ�.
	mem = BIO_new(BIO_s_mem());	// BIO_new()��BIO_s_mem()��n����mem���쐬.
	base64 = BIO_new(BIO_f_base64());	// BIO_new()��BIO_f_base64()��n����base64���쐬.
	BIO_set_flags(base64, BIO_FLAGS_BASE64_NO_NL);	// BIO_set_flags��BIO_FLAGS_BASE64_NO_NL���Z�b�g���Ȃ���Base64������ɉ��s���܂܂�Ă��܂��̂ŗv����!
	BIO_push(base64, mem);	// BIO_push��base64��mem��A��.
	BIO_write(base64, credentials_str.c_str(), credentials_str.length());	// base64��credentials_str����������.
	BIO_flush(base64);	// BIO_flush�Ńt���b�V��.
	BIO_read(mem, base64_str, 1024);	// BIO_read��mem��ǂݍ���, base64_str�Ɋi�[.

	// base64_str�̏o��.
	printf("base64_str = %s\n", base64_str);	// printf��base64_str�̏o��.

	// base64_str�̕����R�[�h�ϊ�(Shift-JIS => Unicode)
	TCHAR tbase64[1024];
	DWORD len = MultiByteToWideChar(CP_ACP, 0, base64_str, -1, NULL, 0);	// ���C�h�����ɕϊ����邽�߂̃T�C�Y�擾.
	MultiByteToWideChar(CP_ACP, 0, base64_str, -1, tbase64, len);	// ���C�h�����ɕϊ�.

	// POST���N�G�X�g������̍쐬.
	request_tstr = _T("POST /oauth2/token HTTP/1.1");	// request_tstr��"POST /oauth2/token HTTP/1.1"���i�[.
	request_tstr = request_tstr + _T("\r\n");	// ���s
	request_tstr = request_tstr + _T("Host: api.twitter.com");	// request_tstr��"Host: api.twitter.com"��A��.
	request_tstr = request_tstr + _T("\r\n");	// ���s
	request_tstr = request_tstr + _T("User-Agent: bgst1tw1test1");	// request_tstr��"User-Agent: bgst1tw1test1"��A��.
	request_tstr = request_tstr + _T("\r\n");	// ���s
	request_tstr = request_tstr + _T("Authorization: Basic ");	// request_tstr��"Authorization: Basic "��A��.
	request_tstr = request_tstr + tbase64;	// request_tstr��tbase64��A��.
	request_tstr = request_tstr + _T("\r\n");	// ���s
	request_tstr = request_tstr + _T("Content-Type: application/x-www-form-urlencoded;charset=UTF-8");	// request_tstr��"Content-Type: application/x-www-form-urlencoded;charset=UTF-8"��A��.
	request_tstr = request_tstr + _T("\r\n");	// ���s
	request_tstr = request_tstr + _T("Content-Length: 29");	// request_tstr��"Content-Length: 29"��A��.
	request_tstr = request_tstr + _T("\r\n\r\n");	// ��s
	request_tstr = request_tstr + _T("grant_type=client_credentials");	// request_tstr��"grant_type=client_credentials"��A��.

	// request_tstr�̕����R�[�h�ϊ�(Unicode => utf-8)
	char request_str[4096];
	DWORD len2 = WideCharToMultiByte(CP_UTF8, 0, request_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_UTF8, 0, request_tstr.c_str(), -1, request_str, len2, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.

	// ���N�G�X�g�̏�������.
	written = SSL_write(ssl, request_str, len2);	// SSL_write��request_str����������.
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

	// ���
	BIO_free_all(base64);	// base64�ƘA�����Ă���mem����������.

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