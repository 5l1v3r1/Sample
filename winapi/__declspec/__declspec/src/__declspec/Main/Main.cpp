// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <cstdio>		// �W�����o��
#include <tchar.h>		// TCHAR�Ή�

// �O������Q�Ƃł���֐��̐錾.
extern "C" __declspec(dllimport) void DllFunc(void);	// dllimport�ɂ����, �֐����Q�Ƃł���.

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// Dllfunc���Ă�.
	DllFunc();	// �O������Q�Ƃł���֐�DllFunc���Ă�.

	// �v���O�����̏I��
	return 0;

}