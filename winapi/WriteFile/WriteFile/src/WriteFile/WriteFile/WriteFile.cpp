// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HANDLE hFile;			// HANDLE�^�t�@�C���n���h��hFile
	DWORD dwWrittenBytes;	// DWORD�^�������񂾃o�C�g��dwWrittenBytes.

	// �t�@�C�����J��
	hFile = CreateFile(_T("test.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��"test.txt"�������݃��[�h(GENERIC_WRITE)�J����, �擾�����n���h����hFile�Ɋi�[.
	if (hFile == INVALID_HANDLE_VALUE){	// hFile��INVALID_HANDLE_VALUE�Ȃ�.

		// �G���[����
		_tprintf(_T("CreateFile Error!\n"));	// _tprintf��"CreateFile Error!"�Əo��.
		return -1;	// -1��Ԃ�.

	}

	// �t�@�C���̓��e��ǂݍ���.
	WriteFile(hFile, "ABCDE", 5, &dwWrittenBytes, NULL);	// WriteFile��hFile��"ABCDE"����������.

	// ����.
	CloseHandle(hFile);	// CloseHandle��hFile�����.

	// �v���O�����̏I��.
	return 0;

}