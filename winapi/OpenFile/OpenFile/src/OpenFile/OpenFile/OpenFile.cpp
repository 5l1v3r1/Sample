// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HFILE hFile;			// HFILE�^�t�@�C���n���h��hFile
	OFSTRUCT ofst = {0};	// OFSTRUCT�\����ofst��0�ŏ�����.

	// �t�@�C�����J��
	hFile = OpenFile("test.txt", &ofst, OF_READ);	// OpenFile��"test.txt"���J����, �擾�����t�@�C���n���h����hFile�Ɋi�[.
	if (hFile == HFILE_ERROR){	// HFILE_ERROR�Ȃ�.

		// �G���[����
		_tprintf(_T("OpenFile Error!\n"));	// _tprintf��"OpenFile Error!"�Əo��.
		return -1;	// -1��Ԃ�.

	}

	// hFile�̒l���o��.
	_tprintf(_T("hFile = 0x%08x\n"), hFile);	// _tprintf��hFile�̒l���o��.

	// ����.
	CloseHandle((HANDLE)hFile);	// CloseHandle��hFile�����.

	// �v���O�����̏I��.
	return 0;

}