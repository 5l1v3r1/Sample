// �w�b�_�t�@�C���̃C���N���[�h
#include "CWinApp_.h"	// CWinApp_�N���X

// CWinApp_�̃����o�̒�`
// �����o�֐�InitInstance()
BOOL CWinApp_::InitInstance(){	// �C���X�^���X�̏���������

	// �ϐ��̐錾
	int iRet;	// ���b�Z�[�W�{�b�N�X�ŉ����I�����ꂽ�����i�[����int�^�ϐ�iRet.

	// ���b�Z�[�W�{�b�N�X��"�͂�", "������"��I��.
	iRet = AfxMessageBox(_T("YesNo?"), MB_YESNO);	// AfxMessageBox��"�͂�", "������"�I���^�̃��b�Z�[�W�{�b�N�X��\��.
	if (iRet == IDYES){	// "�͂�"

		// �����������Ƃ������Ƃɂ���.
		return TRUE;	// �����������Ȃ�TRUE��Ԃ�.

	}
	else{	// "������"

		// ���������s�Ƃ������Ƃɂ���.
		return FALSE;	// ���������s�Ȃ�FALSE��Ԃ�.

	}

}

// �����o�֐�Run()
int CWinApp_::Run(){	// ���b�Z�[�W���[�v

	// ���b�Z�[�W�{�b�N�X��p�ӂ�, �\�������΂����ɗ��Ă���.
	AfxMessageBox(_T("Run"), MB_OK | MB_ICONASTERISK);	// AfxMessageBox��"Run"�ƕ\��.

	// ���b�Z�[�W���[�v�̏I��.
	return 0;	// �����͈ꉞ0�ɂ��Ă���.

}