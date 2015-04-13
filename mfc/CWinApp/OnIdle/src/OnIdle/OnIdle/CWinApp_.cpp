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
	pFrameWnd_->Create(NULL, _T("OnIdle"));	// Create��CFrameWnd_�̃C���X�^���X�̃E�B���h�E���쐬.

	// CFrameWnd_�̕\��
	pFrameWnd_->ShowWindow(m_nCmdShow);	// ShowWindow�ŃE�B���h�E��\��.

	// CFrameWnd_�̍X�V
	pFrameWnd_->UpdateWindow();	// UpdateWindow�ŃE�B���h�E���X�V.

	// ����������
	return TRUE;	// �����������Ȃ�TRUE��Ԃ�.

}

// �����o�֐�OnIdle()
BOOL CWinApp_::OnIdle(LONG lCount){	// �A�C�h�����̏���(���b�Z�[�W�����Ȃ����̏���.)

	// �I�u�W�F�N�g�̐錾
	CClientDC dc(m_pMainWnd);	// CClientDC�I�u�W�F�N�g�̃R���X�g���N�^��m_pMainWnd(CFrameWnd_�̃C���X�^���X)��n��.
	CString cstrLCount;			// lCount�̒l��\��������cstrLCount.

	// lCount�̒l��\���������cstrLCount�ɃZ�b�g.
	cstrLCount.Format(_T("lCount = %d"), lCount);	// cstrLCount�̃����o�֐�Format��lCount���g������������Z�b�g.

	// ������̕`��
	dc.TextOut(0, 0, cstrLCount, cstrLCount.GetLength());	// dc�̃����o�֐�TextOut��cstrLCount��`��.(GetLength�����o�֐��͕����񒷂�Ԃ�.)

	// lCount��50000�ȏ�ɂȂ�����, �A�C�h����Ԃ���߂�.
	if (lCount >= 50000){	// lCount��50000�ȏ�ɂȂ�����.
		return FALSE;	// FALSE��Ԃ��ăA�C�h����Ԃ���߂�.
	}

	// lCount��50000�����Ȃ�A�C�h����Ԃ��p������.
	return TRUE;	// TRUE��Ԃ��ăA�C�h����Ԃ��p������.

}