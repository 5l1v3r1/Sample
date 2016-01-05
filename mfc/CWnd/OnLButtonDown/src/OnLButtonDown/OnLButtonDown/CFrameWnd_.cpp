// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_PAINT()		// OnPaint�̃��b�Z�[�W�}�N��
	ON_WM_LBUTTONDOWN()	// OnLButtonDown�̃��b�Z�[�W�}�N��
END_MESSAGE_MAP()

// CFrameWnd_�̃����o�̒�`
// �R���X�g���N�^CFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// ����������

	// �����o�ϐ��̏�����
	m_x = 0;	// m_x�̏����l��0.
	m_y = 0;	// m_y�̏����l��0.

}

// ���b�Z�[�W�n���h��OnPaint()
void CFrameWnd_::OnPaint(){	// ��ʂ̕`���v�����ꂽ��.

	// �I�u�W�F�N�g�̐錾
	CPaintDC dc(this);	// CPaintDC�I�u�W�F�N�g�̃R���X�g���N�^��this(CFrameWnd_�̃C���X�^���X���g)��n��.
	CString cstrPoint;	// �}�E�X�J�[�\���̈ʒu���W��\��������cstrPoint.

	// �}�E�X�J�[�\���̈ʒu���W��\���������cstrPoint�ɃZ�b�g.
	cstrPoint.Format(_T("(x, y) = (%d, %d)"), m_x, m_y);	// cstrPoint�̃����o�֐�Format��m_x��m_y���g������������Z�b�g.

	// ������̕`��
	dc.TextOut(0, 0, cstrPoint, cstrPoint.GetLength());	// dc�̃����o�֐�TextOut��cstrPoint��`��.(GetLength�����o�֐��͕����񒷂�Ԃ�.)

}

// ���b�Z�[�W�n���h��OnLButtonDown()
void CFrameWnd_::OnLButtonDown(UINT nFlags, CPoint point){	// �}�E�X�̍��{�^���������ꂽ��.

	// �}�E�X�J�[�\���̈ʒu���W��n��.
	m_x = point.x;	// point�œn���ꂽ���W��x��m_x�ɑ��.
	m_y = point.y;	// point�œn���ꂽ���W��y��m_y�ɑ��.

	// ��ʂ̍X�V��v��.
	Invalidate();	// Invalidate�ŉ�ʑS�̂̍X�V��v��.(�����Ȃ��̓f�t�H���g��TRUE�Ȃ̂Ŕw�i��������.)

}