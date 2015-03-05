// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){	// TCHAR�Ή���

	// �ϐ��̐錾
	int iRetYesNo;		// "�͂�"/"������"��I������^�C�v�̃��b�Z�[�W�{�b�N�X�̌��ʂ��i�[����int�^�ϐ�iRetYesNo.
	int iRetOKCancel;	// "OK"/"�L�����Z��"��I������^�C�v�̃��b�Z�[�W�{�b�N�X�̌��ʂ��i�[����int�^�ϐ�iRetOKCancel.

	// ���b�Z�[�W�{�b�N�X�e�X�g�̊J�n
	iRetYesNo = MessageBox(NULL, _T("MessageBox Test Start?"), _T("MessageBox"), MB_YESNO | MB_ICONQUESTION);	// MessageBox��"MessageBox Test Start?"�ƕ\��.(�{�^����, "�͂�"/"������"�I���^, �A�C�R����, �^�╄�A�C�R��.)
	if (iRetYesNo == IDYES){	// "�͂�"��I�����ꂽ�Ƃ�.

		// ���b�Z�[�W�{�b�N�X�e�X�g���p�����邩���~���邩�̊m�F.
		iRetOKCancel = MessageBox(NULL, _T("MessageBox Test Processing."), _T("MessageBox"), MB_OKCANCEL | MB_ICONEXCLAMATION);	// MessageBox��"MessageBox Test Processing."�ƕ\��.(�{�^����, "OK"/"�L�����Z��"�I���^, �A�C�R����, ���Q���A�C�R��.)
		if (iRetOKCancel == IDOK){	// "OK"��I�����ꂽ�Ƃ�.

			// ���b�Z�[�W�{�b�N�X�e�X�g�̊���
			MessageBox(NULL, _T("MessageBox Test Finished!"), _T("MessageBox"), MB_OK | MB_ICONASTERISK);	// MessageBox��"MessageBox Test Finished!"�ƕ\��.(�{�^����, "OK"�m�F�^, �A�C�R����, ���A�C�R��.)

		}
		else{	// "�L�����Z��"��I�����ꂽ�Ƃ�.

			// ���b�Z�[�W�{�b�N�X�e�X�g�̒��~
			MessageBox(NULL, _T("MessageBox Test Cancelled!"), _T("MessageBox"), MB_OK | MB_ICONHAND);	// MessageBox��"MessageBox Test Cancelled!"�ƕ\��.(�{�^����, "OK"�m�F�^, �A�C�R����, ���~�A�C�R��.)

			// �v���O�����ُ̈�I��(1)
			return -1;	// -1��Ԃ�.

		}

	}
	else{	// "������"��I�����ꂽ�Ƃ�.

		// ���b�Z�[�W�{�b�N�X�e�X�g���J�n���Ȃ�.
		MessageBox(NULL, _T("MessageBox Test Not Started!"), _T("MessageBox"), MB_OK | MB_ICONHAND);	// MessageBox��"MessageBox Test Not Started!"�ƕ\��.(�{�^����, "OK"�m�F�^, �A�C�R����, ���~�A�C�R��.)

		// �v���O�����ُ̈�I��(2)
		return -2;	// -2��Ԃ�.

	}

	// �v���O�����̏I�����b�Z�[�W
	MessageBox(NULL, _T("MessageBox Test End."), _T("MessageBox"), MB_OK);	// MessageBox��"MessageBox Test End."�ƕ\��.(�{�^����, "OK"�m�F�^, �A�C�R���͂Ȃ�.)

	// �v���O�����̐���I��
	return 0;

}