// ��d�C���N���[�h�h�~
#pragma once	// VisualC++�Ǝ��̃v���v���Z�b�T#pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <afxwin.h>	// MFC�W��
#include <tchar.h>	// TCHAR�^

// CDialog�̔h���N���XCDialog_�̒�`
class CDialog_ : public CDialog{	// �t���[���E�B���h�E�N���X

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^
		CDialog_(UINT nIDTemplate) : CDialog(nIDTemplate){};	// �R���X�g���N�^CDialog_(nIDTemplate)��CDialog�̃R���X�g���N�^������nIDTemplate��n��, �Ǝ��̏����͒�`���Ȃ�.

		// �n���h��
		virtual void OnLButtonDown(UINT nFlags, CPoint point);	// �}�E�X�̍��{�^���������ꂽ��.
		virtual void OnClose();	// �_�C�A���O�̕���{�^���������ꂽ��.

		// ���b�Z�[�W�}�b�v
		DECLARE_MESSAGE_MAP()	// ���b�Z�[�W�}�b�v�̗��p��錾.

};