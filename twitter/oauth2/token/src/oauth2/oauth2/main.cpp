// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>			// TCHAR�^
#include <iostream>			// C++�W�����o��
#include <string>			// std::string
#include <openssl/bio.h>	// BIO 

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
	BIO *buffer = NULL;	// �o�b�t�@�p�t�B���^BIO�ւ̃|�C���^buffer��NULL�ɏ�����.

	// buffer�̍쐬.
	buffer = BIO_new(BIO_f_buffer());	// BIO_new��BIO_f_buffer�̖߂�l��n�����Ƃ�buffer���쐬.

	// buffer���o��.
	_tprintf(_T("buffer = %08x\n"), buffer);	// _tprintf��buffer���o��.

	// buffer�̉��.
	BIO_free(buffer);	// BIO_free��buffer�����.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ�.

}