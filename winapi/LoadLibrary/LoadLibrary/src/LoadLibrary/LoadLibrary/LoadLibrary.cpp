// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <cstdio>		// �W�����o��
#include <tchar.h>		// TCHAR�Ή�

// DllMain�֐��̒�`
int WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){	// DLL�̓ǂݍ��ݎ��������ɌĂ΂��G���g���|�C���g.

	// "DllMain"�Əo��.
	_tprintf(_T("DllMain\n"));	// _tprintf��"DllMain\n"�Əo��.

	// �����Ȃ�TRUE.
	return TRUE;	// �����DllMain�̏����𐬌��Ƃ���̂�TRUE.

}