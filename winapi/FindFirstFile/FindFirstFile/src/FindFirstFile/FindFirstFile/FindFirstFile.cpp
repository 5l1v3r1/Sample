// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HANDLE hFind;			// �����n���h��hFind.
	WIN32_FIND_DATA wfd;	// �t�@�C���������wfd.

	// "test�`"�Ŏn�܂�t�@�C���̒�����ŏ��Ɍ��������t�@�C���̏����擾.
	hFind = FindFirstFile(_T("test*"), &wfd);	// FindFirstFile��"test*"�ɓ��Ă͂܂�t�@�C����T��, �ŏ��Ɍ��������t�@�C������wfd�Ɋi�[.
	if (hFind == INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUE�Ȃ玸�s.

		// �G���[����.
		_tprintf(_T("FindFirstFile Error!\n"));	// _tprintf��"FindFirstFile Error!"�Əo��.
		return -1;	// -1��Ԃ�.

	}

	// ���������t�@�C���̃t�@�C�������o��.
	_tprintf(_T("wfd.cFileName = %s\n"), wfd.cFileName);	// ���������t�@�C���̃t�@�C����wfd.cFileName���o��.

	// �n���h�������.
	FindClose(hFind);	// FindClose��hFind�����.

	// �v���O�����̏I��.
	return 0;

}