// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){	// TCHAR�Ή���

	// �f�o�b�O�p�̕�������o�͂���.
	OutputDebugString(_T("ABCDE\n"));	// �f�o�b�O�p�̕�����Ƃ���"ABCDE"�Ɖ��s���o�͂���.

	// �v���O�����̐���I��
	return 0;	// 0��Ԃ��Đ���I��.

}