// �w�b�_�t�@�C���̃C���N���[�h
#include "CWinApp_.h"	// CWinApp_�N���X
#include "resource.h"	// ���\�[�XID

// CWinApp_�̃����o�̒�`
// �����o�֐�InitInstance()
BOOL CWinApp_::InitInstance(){	// �C���X�^���X�̏���������

	// �\���̂̐錾
	CFrameWnd *pFrameWnd;			// CFrameWnd�̃I�u�W�F�N�g�|�C���^

	// CFrameWnd�̃C���X�^���X�쐬
	pFrameWnd = new CFrameWnd();	// new��CFrameWnd�̃C���X�^���X���쐬��, pFrameWnd�Ɋi�[.
	m_pMainWnd = pFrameWnd;			// m_pMainWnd��pFrameWnd���Z�b�g.

	// �t���[�������\�[�X���烍�[�h���ăE�B���h�E���쐬.
	pFrameWnd->LoadFrame(IDR_MAINFRAME);	// LoadFrame�ŋ��L���\�[�XID��IDR_MAINFRAME�ƂȂ�t���[�������[�h.

	// CFrameWnd�̕\��
	pFrameWnd->ShowWindow(m_nCmdShow);	// ShowWindow�ŃE�B���h�E��\��.

	// CFrameWnd�̍X�V
	pFrameWnd->UpdateWindow();	// UpdateWindow�ŃE�B���h�E���X�V.

	// ����������
	return TRUE;	// �����������Ȃ�TRUE��Ԃ�.

}