// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̏�����
	HANDLE hProcess = NULL;	// �v���Z�X�n���h��hProcess��NULL�ŏ�����.
	TCHAR tszHProcess[64] = {0};	// �����z��tszHProcess(����64)��{0}�ŏ�����.

	// ���݂̃v���Z�X�̋[���n���h�����擾.(���ۂɂ͏��-1���Ԃ��Ă���d�l.�݊����̂��߂ɂ��̊֐��Ŏ擾���邱�Ƃ���������Ă���.)
	hProcess = GetCurrentProcess();	// GetCurrentProcess�̖߂�l��hProcess�Ɋi�[.
	_stprintf(tszHProcess, _T("hProcess = %d"), (int)hProcess);	// _stprintf��hProcess��tszHProcess�ɕϊ�.

	// hProcess��\��.
	MessageBox(NULL, tszHProcess, _T("GetCurrentProcess"), MB_OK);	// MessageBox��tszHProcess��\��.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}
