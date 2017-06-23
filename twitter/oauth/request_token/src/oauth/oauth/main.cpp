// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>			// TCHAR�^
#include <stdio.h>			// C�W�����o��
#include <string.h>			// C�����񏈗�
#include <iostream>			// C++�W�����o��
#include <string>			// std::string
#include <time.h>			// ����
#include <winsock2.h>		// Windows�\�P�b�g
#include <ws2tcpip.h>		// WinSock2 TCP/IP
#include <openssl/bio.h>	// BIO 
#include <openssl/ssl.h>	// SSL
#include <openssl/err.h>	// �G���[
#include <openssl/sha.h>	// SHA
#include <openssl/evp.h>	// EVP
#include <openssl/hmac.h>	// HMAC

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
	int iRet;	// int�^iRet.
	struct addrinfo hint = { 0 };	// addrinfo�\����hint��0�ŏ�����.
	struct addrinfo *ai;			// addrinfo�\���̃|�C���^ai.
	int soc = -1;	// �\�P�b�g�t�@�C���f�B�X�N���v�^soc��-1�ɏ�����.
	SSL_CTX *ctx = NULL;	// SSL_CTX�\���̂ւ̃|�C���^ctx��NULL�ɏ�����.
	SSL *ssl = NULL;	// SSL�ڑ���������SSL�\���̂ւ̃|�C���^ssl��NULL�ɏ�����.
	char api_secret_str[1024] = { 0 };	// char�^API�V�[�N���b�gutf-8�������0�ŏ�����.
	char urlencoded_api_secret_str[1024] = { 0 };	// URL�G���R�[�h�ς݂�API�V�[�N���b�gutf-8�������0�ŏ�����.
	char signature_key[1024] = { 0 };	// �����L�[signature_key��0�ŏ�����.
	tstring request_params_tstr = _T("");	// ���N�G�X�g�p�����[�^request_params_tstr��""�ŏ�����.
	char request_params_str[1024] = { 0 };	// ���N�G�X�g�p�����[�^request_params_str(utf8)��0�ŏ�����.
	char urlencoded_request_params_str[1024] = { 0 };	// URL�G���R�[�h�ς݃p�����[�^ urlencoded_request_params_str��0�ŏ�����.
	tstring request_method_tstr = _T("POST");	// ���N�G�X�g���\�b�h��"POST".
	char request_method_str[1024] = { 0 };	// utf8.
	char urlencoded_request_method_str[1024] = { 0 };	// URL�G���R�[�h�ς�.
	tstring request_url_tstr = _T("https://api.twitter.com/oauth/request_token");	// ���N�G�X�gURL��"https://api.twitter.com/oauth/request_token".
	char request_url_str[1024] = { 0 };	// utf8.
	char urlencoded_request_url_str[1024] = { 0 };	// URL�G���R�[�h�ς�.
	char signature_data[4096] = { 0 };	// �����f�[�^signature_data��0�ŏ�����.
	char hmac_sha1[SHA_DIGEST_LENGTH + 1];	// char�^�z��hmac_sha1.
	unsigned int hmac_sha1_len;	// unsigned int�^hmac_sha1_len.
	BIO *mem = NULL;	// �������f�[�^�V���NBIO
	BIO *base64 = NULL;	// Base64�t�B���^BIO
	char base64_str[1024] = { 0 };	// char�^�z��base64_str��0�ŏ�����.

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

	// �����L�[�̍쐬.
	// API_SECRET�̕����R�[�h�ϊ�(Unicode => utf-8)
	DWORD len = WideCharToMultiByte(CP_UTF8, 0, API_SECRET, -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_UTF8, 0, API_SECRET, -1, api_secret_str, len, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.
	urlencode(urlencoded_api_secret_str, api_secret_str, len - 1);	// ����֐�urlencode��api_secret_str��URL�G���R�[�h.
	strcat_s(signature_key, sizeof(char) * 1024, urlencoded_api_secret_str);	// signature_key��urlencoded_api_secret_str��A��.
	strcat_s(signature_key, sizeof(char) * 1024, "&");	// signature_key��'&'��A��.

	// ���ݎ����̎擾.
	time_t t = time(NULL);	// time�Ŏ擾�������ݎ�����time_t�^t�Ɋi�[.
	TCHAR time_tstr[64] = { 0 };	// time_tstr��0�ŏ�����.
	_stprintf_s(time_tstr, sizeof(char) * 64, _T("%ld"), t);	// UNIX����t�𕶎���time_tstr�ɕϊ�.

	// ���N�G�X�g�p�����[�^�̍쐬.
	request_params_tstr = _T("oauth_callback");	// request_params_tstr��"oauth_callback"��A��.
	request_params_tstr = request_params_tstr + _T("=");	// "="��A��.
	request_params_tstr = request_params_tstr + CALLBACK_URL;	// CALLBACK_URL��A��.
	request_params_tstr = request_params_tstr + _T("&");	// "&"��A��.
	request_params_tstr = request_params_tstr + _T("oauth_consumer_key");	// request_params_tstr��"oauth_consumer_key"��A��.
	request_params_tstr = request_params_tstr + _T("=");	// "="��A��.
	request_params_tstr = request_params_tstr + API_KEY;	// API_KEY��A��.
	request_params_tstr = request_params_tstr + _T("&");	// "&"��A��.
	request_params_tstr = request_params_tstr + _T("oauth_signature_method");	// request_params_tstr��"oauth_signature_method"��A��.
	request_params_tstr = request_params_tstr + _T("=");	// "="��A��.
	request_params_tstr = request_params_tstr + _T("HMAC-SHA1");	// "HMAC-SHA1"��A��.
	request_params_tstr = request_params_tstr + _T("&");	// "&"��A��.
	request_params_tstr = request_params_tstr + _T("oauth_timestamp");	// request_params_tstr��"oauth_timestamp"��A��.
	request_params_tstr = request_params_tstr + _T("=");	// "="��A��.
	request_params_tstr = request_params_tstr + time_tstr;	// time_tstr��A��.
	request_params_tstr = request_params_tstr + _T("&");	// "&"��A��.
	request_params_tstr = request_params_tstr + _T("oauth_nonce");	// request_params_tstr��"oauth_nonce"��A��.
	request_params_tstr = request_params_tstr + _T("=");	// "="��A��.
	request_params_tstr = request_params_tstr + time_tstr;	// �Ƃ肠����time_tstr��������x�A��.
	request_params_tstr = request_params_tstr + _T("&");	// "&"��A��.
	request_params_tstr = request_params_tstr + _T("oauth_version");	// request_params_tstr��"oauth_version"��A��.
	request_params_tstr = request_params_tstr + _T("=");	// "="��A��.
	request_params_tstr = request_params_tstr + _T("1.0");	// "1.0"��A��.
	len = WideCharToMultiByte(CP_UTF8, 0, request_params_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_UTF8, 0, request_params_tstr.c_str(), -1, request_params_str, len, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.
	urlencode(urlencoded_request_params_str, request_params_str, len - 1);	// ����֐�urlencode��request_params_str��URL�G���R�[�h.

	// ���N�G�X�g���\�b�h�̍쐬.
	len = WideCharToMultiByte(CP_UTF8, 0, request_method_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_UTF8, 0, request_method_tstr.c_str(), -1, request_method_str, len, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.
	urlencode(urlencoded_request_method_str, request_method_str, len - 1);	// ����֐�urlencode��request_method_str��URL�G���R�[�h.

	// ���N�G�X�gURL�̍쐬.
	len = WideCharToMultiByte(CP_UTF8, 0, request_url_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_UTF8, 0, request_url_tstr.c_str(), -1, request_url_str, len, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.
	urlencode(urlencoded_request_url_str, request_url_str, len - 1);	// ����֐�urlencode��request_url_str��URL�G���R�[�h.

	// �����f�[�^�̍쐬.
	strcat_s(signature_data, sizeof(char) * 4096, urlencoded_request_method_str);	// signature_data��urlencoded_request_method_str��A��.
	strcat_s(signature_data, sizeof(char) * 4096, "&");	// "&"��A��.
	strcat_s(signature_data, sizeof(char) * 4096, urlencoded_request_url_str);	// signature_data��urlencoded_request_url_str��A��.
	strcat_s(signature_data, sizeof(char) * 4096, "&");	// "&"��A��.
	strcat_s(signature_data, sizeof(char) * 4096, urlencoded_request_params_str);	// signature_data��urlencoded_request_params_str��A��.

	// ����.
	HMAC(EVP_sha1(), (const unsigned char *)signature_key, strlen(signature_key), (const unsigned char *)signature_data, strlen(signature_data), (unsigned char *)hmac_sha1, &hmac_sha1_len);	// HMAC()��HMAC-SHA1���v�Z.

	// Base64�ϊ�.
	mem = BIO_new(BIO_s_mem());	// BIO_new()��BIO_s_mem()��n����mem���쐬.
	base64 = BIO_new(BIO_f_base64());	// BIO_new()��BIO_f_base64()��n����base64���쐬.
	BIO_push(base64, mem);	// BIO_push��base64��mem��A��.
	BIO_write(base64, hmac_sha1, hmac_sha1_len);	// base64��hmac_sha1����������.
	BIO_flush(base64);	// BIO_flush�Ńt���b�V��.
	BIO_read(mem, base64_str, 1024);	// BIO_read��mem��ǂݍ���, base64_str�Ɋi�[.
	printf("base64_str = %s\n", base64_str);	// printf��base64_str�̏o��.
	BIO_free_all(base64);	// base64�ƘA�����Ă���mem����������.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ�.

}

// URL�G���R�[�h.
void urlencode(char dst[], const char src[], int src_len){

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
			strcat_s(dst, sizeof(char) * 1024, urlenc);	// urlenc��dst�ɘA��.
			j = j + 3;	// j��3���₷.
		}
	}

}




