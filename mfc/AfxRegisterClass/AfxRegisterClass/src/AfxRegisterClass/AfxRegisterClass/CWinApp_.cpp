// �w�b�_�t�@�C���̃C���N���[�h
#include "CWinApp_.h"	// CWinApp_�N���X

// CWinApp_�̃����o�̒�`
// �����o�֐�InitInstance()
BOOL CWinApp_::InitInstance(){	// �C���X�^���X�̏���������

	// �\���̂̐錾
	WNDCLASS wc = {0};		// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc��{0}�ŏ�����.
	CFrameWnd *pFrameWnd;	// CFrameWnd�̃I�u�W�F�N�g�|�C���^

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("AfxRegisterClass");				// �E�B���h�E�N���X����"AfxRegisterClass".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = AfxWndProc;							// MFC����̃E�B���h�E�v���V�[�W��AfxWndProc��ݒ�.
	wc.hInstance = AfxGetInstanceHandle();					// AfxGetInstanceHandle�Ŏ擾�������݂̃C���X�^���X�n���h��.
	wc.hIcon = LoadIcon(IDI_APPLICATION);					// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(IDC_ARROW);						// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// �w�i�͍��u���V.
	wc.lpszMenuName = NULL;									// ���j���[�͂Ȃ�.
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	AfxRegisterClass(&wc);	// AfxRegisterClass�ŃE�B���h�E�N���X��o�^.

	// CFrameWnd�̃C���X�^���X�쐬
	pFrameWnd = new CFrameWnd();	// new��CFrameWnd�̃C���X�^���X���쐬��, pFrameWnd�Ɋi�[.
	m_pMainWnd = pFrameWnd;			// m_pMainWnd��pFrameWnd���Z�b�g.

	// CFrameWnd�̍쐬
	pFrameWnd->Create(_T("AfxRegisterClass"), _T("AfxRegisterClass"));	// Create��CFrameWnd�̃C���X�^���X�̃E�B���h�E���쐬.

	// CFrameWnd�̕\��
	pFrameWnd->ShowWindow(m_nCmdShow);	// ShowWindow�ŃE�B���h�E��\��.

	// CFrameWnd�̍X�V
	pFrameWnd->UpdateWindow();	// UpdateWindow�ŃE�B���h�E���X�V.

	// ����������
	return TRUE;	// �����������Ȃ�TRUE��Ԃ�.

}