// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>	// TCHAR�^
#include <iostream>	// C++�W�����o��
#include <string>	// std::string

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// _tmain�֐��̒�`
int _tmain() {

	// "oauth/token"�Əo��.
	std::wcout << L"oauth/token" << std::endl;	// �o�͉��Z�q��"oauth/token"�Əo��.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ�.

}