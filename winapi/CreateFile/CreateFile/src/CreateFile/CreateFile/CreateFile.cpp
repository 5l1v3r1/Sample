// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HANDLE hFile;			// HANDLE�^�t�@�C���n���h��hFile

	// �t�@�C�����J��
	hFile = CreateFile(_T("test.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��"test.txt"���J����, �擾�����n���h����hFile�Ɋi�[.
	if (hFile == INVALID_HANDLE_VALUE){	// hFile��INVALID_HANDLE_VALUE�Ȃ�.

		// �G���[����
		_tprintf(_T("CreateFile Error!\n"));	// _tprintf��"CreateFile Error!"�Əo��.
		return -1;	// -1��Ԃ�.

	}

	// hFile�̒l���o��.
	_tprintf(_T("hFile = 0x%08x\n"), hFile);	// _tprintf��hFile�̒l���o��.

	// ����.
	CloseHandle(hFile);	// CloseHandle��hFile�����.

	// �v���O�����̏I��.
	return 0;

}