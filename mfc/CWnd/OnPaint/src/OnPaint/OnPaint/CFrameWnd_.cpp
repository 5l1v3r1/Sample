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

	// �ϐ��̐錾
	HDC hDC;		// ���̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC.
	PAINTSTRUCT ps;	// �y�C���g�����Ǘ�����PAINTSTRUCT�\���̕ϐ�ps.

	// ������̕`��
	hDC = ::BeginPaint(m_hWnd, &ps);	// WindowsAPI��BeginPaint�ŕ`��̏�������, �f�o�C�X�R���e�L�X�g�n���h�����擾.
	::TextOut(hDC, 0, 0, _T("OnPaint"), (int)_tcslen(_T("OnPaint")));	// WindowsAPI��TextOut��"OnPaint"�ƕ`��.
	::EndPaint(m_hWnd, &ps);	// WindowsAPI��EndPaint�ŕ`����I��.

}