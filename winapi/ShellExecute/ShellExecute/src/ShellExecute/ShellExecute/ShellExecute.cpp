// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// "test.txt"������̃v���O�����ŊJ��.
	_tprintf(_T("open test.txt!\n"));	// "open test.txt!"�Əo��.
	ShellExecute(NULL, _T("open"), _T("test.txt"), NULL, NULL, SW_SHOW);	// ShellExecute��"test.txt"������̃v���O�����ŊJ��.("open"�͎w��̃t�@�C��������̃v���O�����ŊJ���Ƃ�������. ���̏ꍇ, ����̃e�L�X�g�G�f�B�^(�������Ȃ�)��"test.txt"���J�����.)
	
	// �v���O�����̏I��
	return 0;

}