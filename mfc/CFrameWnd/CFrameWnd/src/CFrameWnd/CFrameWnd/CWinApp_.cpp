// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "CWinApp_.h"	// CWinApp_�N���X

// CWinApp_�̃����o�̒�`
// �����o�֐�InitInstance()
BOOL CWinApp_::InitInstance(){	// �C���X�^���X�̏���������

	// �E�B���h�E�N���X�̃C���X�^���X�쐬
	m_pMainWnd = new CFrameWnd_();	// new��CFrameWnd_�̃C���X�^���X���쐬��, m_pMainWnd�Ɋi�[.

	// �E�B���h�E�̕\��
	m_pMainWnd->ShowWindow(m_nCmdShow);	// ShowWindow�ŃE�B���h�E��\��.

	// �E�B���h�E�̍X�V
	m_pMainWnd->UpdateWindow();	// UpdateWindow�ŃE�B���h�E���X�V.

	// ����������
	return TRUE;	// �����������Ȃ�TRUE��Ԃ�.

}