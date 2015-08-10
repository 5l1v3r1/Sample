// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <cstdio>		// �W�����o��
#include <tchar.h>		// TCHAR�Ή�

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HMODULE hDll;	// HMODULE�^�n���h��hDll

	// LoadLibrary�ɂ��DLL�̓ǂݍ��ݑO.
	_tprintf(_T("LoadLibrary before.\n"));	// _tprintf��"LoadLibrary before.\n"�Əo��.

	// DllMain.dll�̓ǂݍ���.
	hDll = LoadLibrary(_T("DllMain.dll"));	// LoadLibrary��"DllMain.dll"�����[�h��, �߂�l��hDll�Ɋi�[.

	// LoadLibrary��NULL�Ȃ玸�s.
	if (hDll == NULL){	// NULL�Ȃ玸�s.

		// �G���[����.
		_tprintf(_T("LoadLibrary failed!\n"));	// _tprintf��"LoadLibrary failed!\n"�Əo��.
		return -1;

	}

	// NULL�łȂ����, hDll���o��.
	_tprintf(_T("hDll = %08x\n"), hDll);	// _tprintf��hDll�̒l���o��.

	// DllMain.dll�̉��.
	FreeLibrary(hDll);	// FreeLibrary��hDll�����.

	// FreeLibrary�ɂ��DLL�̉����.
	_tprintf(_T("FreeLibrary after.\n"));	// _tprintf��"FreeLibrary after.\n"�Əo��.

	// �v���O�����̏I��
	return 0;

}