// �w�b�_�t�@�C���̃C���N���[�h
#include "CWinApp_.h"	// CWinApp_�N���X

// CWinApp_�̃����o�̒�`
// �����o�֐�InitInstance()
BOOL CWinApp_::InitInstance(){	// �C���X�^���X�̏���������

	// �ϐ��E�|�C���^�̐錾
	CFrameWnd *pFrameWnd;	// CFrameWnd�̃I�u�W�F�N�g�|�C���^
	int iRet;				// ���b�Z�[�W�{�b�N�X�ŉ����I�����ꂽ�����i�[����int�^�ϐ�iRet.

	// �t���[���E�B���h�E�̍쐬
	pFrameWnd = new CFrameWnd();	// new��CFrameWnd�̃C���X�^���X���쐬��, pFrameWnd�Ɋi�[.
	m_pMainWnd = pFrameWnd;	// m_pMainWnd��pFrameWnd���Z�b�g.
	pFrameWnd->Create(NULL, _T("InitInstance"));	// Create��"InitInstance"�Ƃ����E�B���h�E���̃t���[���E�B���h�E�쐬.
	pFrameWnd->ShowWindow(m_nCmdShow);	// ShowWindow�ŃE�B���h�E��\��.
	pFrameWnd->UpdateWindow();	// UpdateWindow�ŃE�B���h�E���X�V.

	// ���b�Z�[�W�{�b�N�X��"�͂�", "������"��I��.
	iRet = MessageBox(NULL, _T("YesNo?"), _T("InitInstance"), MB_YESNO);	// MessageBox��"�͂�", "������"�I���^�̃��b�Z�[�W�{�b�N�X��\��.
	if (iRet == IDYES){	// "�͂�"
		m_bInitState = TRUE;	// m_bInitState��TRUE�ɂ���.
		return TRUE;	// �����������Ƃ���TRUE��Ԃ�.
	}
	else{	// "������"
		m_bInitState = FALSE;	// m_bInitState��FALSE�ɂ���.
		return FALSE;	// ���������s�Ƃ���FALSE��Ԃ�.
	}

}

// �����o�֐�Run()
int CWinApp_::Run(){	// ���b�Z�[�W���[�v

	// �ϐ��̐錾
	int iRet;	// Run�̖߂�l���i�[����int�^�ϐ�iRet.

	// ���b�Z�[�W�{�b�N�X��p�ӂ�, �\�������΂����ɗ��Ă���.
	MessageBox(NULL, _T("Run before"), _T("Run"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Run before"�ƕ\��.

	// �e�N���X�̃��b�Z�[�W���[�v���g��.
	iRet = CWinApp::Run();	// CWinApp��Run���Ă��, �߂�l��iRet�Ɋi�[.(�E�B���h�E�����܂�Run�͔����Ȃ�.)

	// Run�̌�ɂ����ɗ���.
	MessageBox(NULL, _T("Run after"), _T("Run"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Run after"�ƕ\��.

	// ���b�Z�[�W���[�v�̏I��.
	return iRet;	// Run�̖߂�liRet��Ԃ�.

}

// �����o�֐�ExitInstance()
int CWinApp_::ExitInstance(){	// �C���X�^���X�̏I������

	// �ϐ��̐錾
	MSG msg;	// ExitInstance���ɂ�, ���b�Z�[�W�{�b�N�X���\������Ȃ����ۑ΍�.

	// InitInstance�̖߂�l��FALSE�̎��̂�, �\������Ȃ����ۑ΍�����s����.
	if (!m_bInitState){	// m_bInitState��FALSE�̎�.

		// GetMessage��WM_QUIT�����������܂ő҂�.
		while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage�̖߂�l��0�ȉ��ɂȂ�܂ő҂�.

		}

	}

	// �C���X�^���X�I�����ɗ���.
	MessageBox(NULL, _T("ExitInstance"), _T("ExitInstance"), MB_OK | MB_ICONASTERISK);	// MessageBox��"ExitInstance"�ƕ\��.
	
	// �I�������̏I��.
	return CWinApp::ExitInstance();	// �e�N���X��ExitInstance�̖߂�l��Ԃ�.

}