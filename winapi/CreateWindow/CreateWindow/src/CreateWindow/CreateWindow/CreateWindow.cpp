// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;			// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	TCHAR tszHWnd[128];	// hWnd�̒l��16�i�����̕�����ɕϊ��������̂��i�[����TCHAR�^�z��tszHWnd.(����128)

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("STATIC"), _T(""), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��"STATIC"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreateWindow"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��

	}

	// �E�B���h�E�n���h���̕\��
	_stprintf(tszHWnd, _T("CreateWindow succeed!(hWnd = 0x%08x)"), hWnd);	// _stprintf��hWnd��16�i�����l�𕶎���ɕϊ�����tszHWnd�Ɋi�[.
	MessageBox(hWnd, tszHWnd, _T("CreateWindow"), MB_OK | MB_ICONASTERISK);	// MessageBox��tszHWnd��\��.

	// �E�B���h�E�̔j��
	DestroyWindow(hWnd);	// DestroyWindow��hWnd��j��.

	// �v���O�����̏I��
	return 0;

}