// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_1)
END_MESSAGE_MAP()

// CFrameWnd_�̃����o�̒�`
// �R���X�g���N�^CFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// ����������

}

// ���b�Z�[�W�n���h��OnCommand()
BOOL CFrameWnd_::OnCommand(WPARAM wParam, LPARAM lParam){	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.

	// �ǂ̃��j���[���ڂ��I�����ꂽ���𔻒肷��.
	switch (LOWORD(wParam)){	// LOWORD(wParam)�őI�����ꂽ���j���[���ڂ�ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

		// �擾����ID���Ƃɏ����𕪊�.
		// Item1-1���I�����ꂽ��.
		case ID_ITEM_1_1:

			// ID_ITEM_1_1�u���b�N
			{

				// ���b�Z�[�W�{�b�N�X��\��.
				AfxMessageBox(_T("Item1-1"), MB_OK | MB_ICONASTERISK);	// AfxMessageBox��"Item1-1"�ƕ\��.
							
				// TRUE��Ԃ�.
				return TRUE;	// ���������̂Ŗ߂�l�Ƃ���TRUE��Ԃ�.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ����ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// �����ɗ��鎞�͏������Ă��Ȃ���.
	return FALSE;	// �������Ă��Ȃ��̂�FALSE��Ԃ�.

}

// �n���h��OnUpdateItem1_1()
void CFrameWnd_::OnUpdateItem1_1(CCmdUI* pCmdUI){	// ���j���[����Item1_1��UI�X�V�n���h��

	// ���j���[����Item1_1��UI�X�V
	if (pCmdUI){	// pCmdUI��NULL�łȂ��Ȃ�.

		// ���j���[����Item1_1�̗L����
		pCmdUI->Enable();	// Enable��Item1_1��L���ɂ���.(�f�t�H���g������TRUE.)

	}

}