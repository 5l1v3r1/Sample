// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <cstdio>		// �W�����o��
#include <tchar.h>		// TCHAR�Ή�

// DllFunc�p�̊֐��|�C���^�^
typedef void (*DLLFUNC)(void);	// typedef�ň���, �߂�l, �Ƃ���void�Ȋ֐��|�C���^�^DLLFUNC���`.

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HMODULE hDll;		// HMODULE�^�n���h��hDll
	DLLFUNC DllFunc;	// GetProcAddress���Ԃ��w�������֐��ւ̃|�C���^.

	// LoadLibrary�ɂ��DLL�̓ǂݍ��ݑO.
	_tprintf(_T("LoadLibrary before.\n"));	// _tprintf��"LoadLibrary before.\n"�Əo��.

	// GetProcAddress.dll�̓ǂݍ���.
	hDll = LoadLibrary(_T("GetProcAddress.dll"));	// LoadLibrary��"GetProcAddress.dll"�����[�h��, �߂�l��hDll�Ɋi�[.

	// LoadLibrary��NULL�Ȃ玸�s.
	if (hDll == NULL){	// NULL�Ȃ玸�s.

		// �G���[����.
		_tprintf(_T("LoadLibrary failed!\n"));	// _tprintf��"LoadLibrary failed!\n"�Əo��.
		return -1;

	}

	// NULL�łȂ����, hDll���o��.
	_tprintf(_T("hDll = %08x\n"), hDll);	// _tprintf��hDll�̒l���o��.

	// DLL�ɂ���O���Q�Ɖ\�Ȋ֐��ւ̃|�C���^���擾����.
	DllFunc = (DLLFUNC)GetProcAddress(hDll, "DllFunc");	// GetProcAddress��"DllFunc"�ւ̃|�C���^���擾.
	if (DllFunc == NULL){	// DllFunc�Ȃ�Ăяo�����s.

		// �G���[����.
		FreeLibrary(hDll);	// FreeLibrary��hDll�����.
		_tprintf(_T("GetProcAddress failed!\n"));	// _tprintf��"GetProcAddress failed!\n"�Əo��.
		return -1;

	}

	// DllFunc���Ă�.
	DllFunc();	// GetProcAddress�Ŏ擾����DllFunc���Ăяo��.

	// GetProcAddress.dll�̉��.
	FreeLibrary(hDll);	// FreeLibrary��hDll�����.

	// FreeLibrary�ɂ��DLL�̉����.
	_tprintf(_T("FreeLibrary after.\n"));	// _tprintf��"FreeLibrary after.\n"�Əo��.

	// �v���O�����̏I��
	return 0;

}