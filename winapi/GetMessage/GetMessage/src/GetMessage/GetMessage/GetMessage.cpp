// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;			// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;			// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	TCHAR tszMsg[128];	// �E�B���h�E���b�Z�[�W�ԍ���������i�[����TCHAR�^�z��tszMsg.(����128)

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("STATIC"), _T(""), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��"STATIC"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetMessage"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W�̎擾
	GetMessage(&msg, NULL, 0, 0);	// GetMessage�ŃE�B���h�E���b�Z�[�W���擾����msg�Ɋi�[.
	_stprintf(tszMsg, _T("msg.message = 0x%08x"), msg.message);	// ���b�Z�[�W�ԍ�msg.message���܂ޕ�������쐬.
	MessageBox(hWnd, tszMsg, _T("GetMessage"), MB_OK | MB_ICONASTERISK);	// MessageBox�Ŏ擾�������b�Z�[�W�ԍ���\��.

	// �E�B���h�E�̔j��
	DestroyWindow(hWnd);	// DestroyWindow��hWnd��j��.

	// �v���O�����̏I��
	return 0;

}