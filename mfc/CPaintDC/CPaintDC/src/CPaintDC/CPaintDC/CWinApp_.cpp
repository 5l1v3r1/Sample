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
	m_pMainWnd = pFrameWnd_;	// m_pMainWnd��pFrameWnd_���Z�b�g.

	// CFrameWnd_�̍쐬
	pFrameWnd_->Create(NULL, _T("CPaintDC"));	// Create��CFrameWnd_�̃C���X�^���X�̃E�B���h�E���쐬.

	// CFrameWnd_�̕\��
	pFrameWnd_->ShowWindow(m_nCmdShow);	// ShowWindow�ŃE�B���h�E��\��.

	// CFrameWnd_�̍X�V
	pFrameWnd_->UpdateWindow();	// UpdateWindow�ŃE�B���h�E���X�V.

	// ����������
	return TRUE;	// �����������Ȃ�TRUE��Ԃ�.

}