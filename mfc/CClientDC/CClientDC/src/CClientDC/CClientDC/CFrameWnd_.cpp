// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_LBUTTONDOWN()	// OnLButtonDown�̃��b�Z�[�W�}�N��
END_MESSAGE_MAP()

// CFrameWnd_�̃����o�̒�`
// �R���X�g���N�^CFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// ����������

}

// ���b�Z�[�W�n���h��OnLButtonDown()
void CFrameWnd_::OnLButtonDown(UINT nFlags, CPoint point){	// �}�E�X�̍��{�^���������ꂽ��.

	// �I�u�W�F�N�g�̐錾
	CClientDC dc(this);	// CClientDC�I�u�W�F�N�g�̃R���X�g���N�^��this(CFrameWnd_�̃C���X�^���X���g)��n��.
	CString cstrPoint;	// �}�E�X�J�[�\���̈ʒu���W��\��������cstrPoint.

	// �}�E�X�J�[�\���̈ʒu���W��\���������cstrPoint�ɃZ�b�g.
	cstrPoint.Format(_T("(x, y) = (%d, %d)"), point.x, point.y);	// cstrPoint�̃����o�֐�Format�� point.x�� point.y���g������������Z�b�g.

	// ������̕`��
	dc.TextOut(0, 0, cstrPoint, cstrPoint.GetLength());	// dc�̃����o�֐�TextOut��cstrPoint��`��.(GetLength�����o�֐��͕����񒷂�Ԃ�.)

}