// �w�b�_�t�@�C���̃C���N���[�h
#include "CDialog_.h"	// CDialog_�N���X

// CDialog_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CDialog_, CDialog)
	ON_WM_LBUTTONDOWN()	// OnLButtonDown�̃��b�Z�[�W�}�N��
	ON_WM_CLOSE()	// OnClose�̃��b�Z�[�W�}�N��
END_MESSAGE_MAP()

// CDialog_�̃����o�̒�`
// ���b�Z�[�W�n���h��OnLButtonDown()
void CDialog_::OnLButtonDown(UINT nFlags, CPoint point){	// �}�E�X�̍��{�^���������ꂽ��.

	// IDOK
	EndDialog(IDOK);	// EndDialog��"OK"�Ƃ��ďI������.

}

// ���b�Z�[�W�n���h��OnClose()
void CDialog_::OnClose(){	// �_�C�A���O�̕���{�^���������ꂽ��.

	// IDCANCEL
	EndDialog(IDCANCEL);	// EndDialog��"�L�����Z��"�Ƃ��ďI������.

}