// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_PAINT()	// OnPaint�̃��b�Z�[�W�}�N��
END_MESSAGE_MAP()

// CFrameWnd_�̃����o�̒�`
// �R���X�g���N�^CFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// ����������

}

// ���b�Z�[�W�n���h��OnPaint()
void CFrameWnd_::OnPaint(){	// ��ʂ̕`���v�����ꂽ��.

	// �I�u�W�F�N�g�̐錾
	CPaintDC dc(this);	// CPaintDC�I�u�W�F�N�g�̃R���X�g���N�^��this(CFrameWnd_�̃C���X�^���X���g)��n��.

	// ������̕`��
	dc.TextOut(0, 0, _T("CPaintDC"), (int)_tcslen(_T("CPaintDC")));	// dc�̃����o�֐�TextOut��"CPaintDC"�ƕ`��.(BeginPaint��EndPaint�͕s�v.)

}