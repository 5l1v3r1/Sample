// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "CWinApp_.h"	// CWinApp_�N���X

// CWinApp_�̃����o�̒�`
// �����o�֐�InitInstance()
BOOL CWinApp_::InitInstance(){	// �C���X�^���X�̏���������

	// �|�C���^�̐錾
	CFrameWnd_ *pFrameWnd_;	// CFrameWnd_�̃I�u�W�F�N�g�|�C���^

	// CFrameWnd_�̃C���X�^���X�쐬
	pFrameWnd_ = new CFrameWnd_();	// new��CFrameWnd_�̃C���X�^���X���쐬��, pFrameWnd_�Ɋi�[.
	m_pMainWnd = pFrameWnd_;		// m_pMainWnd(CWnd)��pFrameWnd_���Z�b�g.

	// �E�B���h�E�̍쐬
	pFrameWnd_->Create(NULL, _T("CWnd"));	// �e�Ȃ��̃E�B���h�E��CFrameWnd::Create�ł������Ȃ��̂�, pFrameWnd_����Create���Ă�.
	
	// �E�B���h�E�̕\��
	m_pMainWnd->ShowWindow(m_nCmdShow);	// m_pMainWnd(CWnd)��ShowWindow�ŃE�B���h�E��\��.

	// �E�B���h�E�̍X�V
	m_pMainWnd->UpdateWindow();	// m_pMainWnd(CWnd)��UpdateWindow�ŃE�B���h�E���X�V.

	// ����������
	return TRUE;	// �����������Ȃ�TRUE��Ԃ�.

}