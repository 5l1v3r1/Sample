// �w�b�_�t�@�C���̃C���N���[�h
#include "CWinApp_.h"	// CWinApp_�N���X
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CWinApp_�̃����o�̒�`
// �����o�֐�InitInstance()
BOOL CWinApp_::InitInstance(){	// �C���X�^���X�̏���������

	// �\���̂̐錾
	CFrameWnd_ *pFrameWnd_;			// CFrameWnd_�̃I�u�W�F�N�g�|�C���^

	// CFrameWnd_�̃C���X�^���X�쐬
	pFrameWnd_ = new CFrameWnd_();	// new��CFrameWnd_�̃C���X�^���X���쐬��, pFrameWnd_�Ɋi�[.
	m_pMainWnd = pFrameWnd_;		// m_pMainWnd��pFrameWnd_���Z�b�g.

	// �t���[�������\�[�X���烍�[�h���ăE�B���h�E���쐬.
	pFrameWnd_->LoadFrame(IDR_MAINFRAME);	// LoadFrame�ŋ��L���\�[�XID��IDR_MAINFRAME�ƂȂ�t���[�������[�h.

	// CFrameWnd_�̕\��
	pFrameWnd_->ShowWindow(m_nCmdShow);	// ShowWindow�ŃE�B���h�E��\��.

	// CFrameWnd_�̍X�V
	pFrameWnd_->UpdateWindow();	// UpdateWindow�ŃE�B���h�E���X�V.
	
	// ����������
	return TRUE;	// �����������Ȃ�TRUE��Ԃ�.

}