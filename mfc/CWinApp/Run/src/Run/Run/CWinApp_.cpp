// �w�b�_�t�@�C���̃C���N���[�h
#include "CWinApp_.h"	// CWinApp_�N���X

// CWinApp_�̃����o�̒�`
// �����o�֐�InitInstance()
BOOL CWinApp_::InitInstance(){	// �C���X�^���X�̏���������

	// �|�C���^�̐錾
	CFrameWnd *pFrameWnd;	// CFrameWnd�̃I�u�W�F�N�g�|�C���^

	// �E�B���h�E�N���X�̃C���X�^���X�쐬
	pFrameWnd = new CFrameWnd();	// new��CFrameWnd�̃C���X�^���X���쐬��, pFrameWnd�Ɋi�[.

	// ���C���E�B���h�E�̃Z�b�g
	m_pMainWnd = pFrameWnd;	// m_pMainWnd��pFrameWnd���Z�b�g.

	// �t���[���E�B���h�E�̍쐬.
	pFrameWnd->Create(NULL, _T("Run"));	// Create��"Run"�Ƃ����E�B���h�E���̃t���[���E�B���h�E�쐬.

	// �E�B���h�E�̕\��
	pFrameWnd->ShowWindow(m_nCmdShow);	// ShowWindow�ŃE�B���h�E��\��.

	// �E�B���h�E�̍X�V
	pFrameWnd->UpdateWindow();	// UpdateWindow�ŃE�B���h�E���X�V.

	// ����������
	return TRUE;	// �����������Ȃ�TRUE��Ԃ�.

}

// �����o�֐�Run()
int CWinApp_::Run(){	// ���b�Z�[�W���[�v

	// �ϐ��̐錾
	int iRet;	// Run�̖߂�l���i�[����int�^�ϐ�iRet.
	
	// �e�N���X�̃��b�Z�[�W���[�v���g��.
	iRet = CWinApp::Run();	// CWinApp��Run���Ă��, �߂�l��iRet�Ɋi�[.(�E�B���h�E�����܂�Run�͔����Ȃ�.)

	// �e�N���X��Run�𔲂����烁�b�Z�[�W�{�b�N�X�\��.
	AfxMessageBox(_T("Exit Run!"), MB_OK | MB_ICONASTERISK);	// AfxMessageBox��"Exit Run!"�ƕ\��.

	// ���b�Z�[�W���[�v�̖߂�l��Ԃ�.
	return iRet;	// iRet��Ԃ�.

}