// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <rasdlg.h>		// RAS�_�C�A���O

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �\���̂̏�����
	RASENTRYDLG rasDlg = {0};	// RASENTRYDLG�^rasDlg��0�ŏ�����.

	// �\���̂ɒl��ݒ�.
	rasDlg.dwSize = sizeof(RASENTRYDLG);	// sizeof��RASENTRYDLG�̃T�C�Y���擾��, rasDlg.dwSize�Ɋi�[.
	rasDlg.dwFlags = RASEDFLAG_NewEntry;	// dwFlags��RASEDFLAG_NewEntry(�V�����G���g���[�̒ǉ�)���Z�b�g.

	// RAS�_�C�A���O�̕\��.
	if (RasEntryDlg(NULL, _T("RasEntryDlg"), &rasDlg)){	// RasEntryDlg�ŃG���g���쐬�ɐ����Ȃ�.

		// ���b�Z�[�W�{�b�N�X�ŕ\��.
		MessageBox(NULL, _T("RasEntryDlg Success!"), _T("RasEntryDlg"), MB_OK);	// "RasEntryDlg Success!"�ƕ\��.

	}

	// �v���O�����̏I��
	return 0;

}