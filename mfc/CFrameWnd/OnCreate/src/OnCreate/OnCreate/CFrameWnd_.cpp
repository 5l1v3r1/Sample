// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_CREATE()	// OnCreate�̃��b�Z�[�W�}�N��
END_MESSAGE_MAP()

// CFrameWnd_�̃����o�̒�`
// �R���X�g���N�^CFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// ����������

}

// ���b�Z�[�W�n���h��OnCreate()
int CFrameWnd_::OnCreate(LPCREATESTRUCT lpCreateStruct){	// �E�B���h�E���쐬���ꂽ��.

	// �ϐ��E�I�u�W�F�N�g�̐錾
	CString cstrMsg;	// ���b�Z�[�W�{�b�N�X�ŕ\�����镶������i�[����cstrMsg.
	CString cstrTmp;	// �����ϊ��p�ꎞ������cstrTmp.

	// cstMsg��lpCreateStruct�̓��e�̈ꕔ��ǉ�����.
	cstrMsg = cstrMsg + _T("OnCreate");													// �܂���"OnCreate"��ǉ�.
	cstrTmp.Format(_T("\nm_hWnd = 0x%08x"), m_hWnd);									// ����cstrTmp��m_hWnd��Format�����o�֐��ŕ\��������ɂ������̂��Z�b�g.
	cstrMsg = cstrMsg + cstrTmp;														// cstrTmp��ǉ�.
	cstrTmp.Format(_T("\nlpCreateStruct->lpszName = %s"), lpCreateStruct->lpszName);	// ����cstrTmp��lpCreateStruct->lpszName��Format�����o�֐��ŕ\��������ɂ������̂��Z�b�g.
	cstrMsg = cstrMsg + cstrTmp;														// cstrTmp��ǉ�.
	cstrTmp.Format(_T("\nlpCreateStruct->x = %d"), lpCreateStruct->x);					// ����cstrTmp��lpCreateStruct->x��Format�����o�֐��ŕ\��������ɂ������̂��Z�b�g.
	cstrMsg = cstrMsg + cstrTmp;														// cstrTmp��ǉ�.
	cstrTmp.Format(_T("\nlpCreateStruct->y = %d"), lpCreateStruct->y);					// ����cstrTmp��lpCreateStruct->y��Format�����o�֐��ŕ\��������ɂ������̂��Z�b�g.
	cstrMsg = cstrMsg + cstrTmp;														// cstrTmp��ǉ�.

	// cstrMsg��\��.
	AfxMessageBox(cstrMsg, MB_OK | MB_ICONASTERISK);	// AfxMessageBox��cstrMsg��\��.

	// �E�B���h�E�쐬����
	return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

}