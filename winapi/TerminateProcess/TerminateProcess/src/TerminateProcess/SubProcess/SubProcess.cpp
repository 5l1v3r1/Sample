// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// "SubProcess Start!"�Əo��.
	_tprintf(_T("SubProcess Start!\n"));	// "SubProcess Start!"�Əo��.

	// 30�b�x�~
	Sleep(30000);	// Sleep��30000�~���b�x�~.

	// "SubProcess End!"�Əo��.
	_tprintf(_T("SubProcess End!\n"));	// "SubProcess End!"�Əo��.

	// �v���O�����̏I��
	ExitProcess(10);	// ExitProcess�ŏI���R�[�h�Ƃ���10��Ԃ�.

}