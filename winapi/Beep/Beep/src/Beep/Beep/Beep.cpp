// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �J�n
	_tprintf(_T("Beep 440Hz Start!\n"));	// "Beep 440Hz Start!"�Əo��.

	// �r�[�v����炷.
	Beep(440, 3000);	// Beep��440Hz�̉���3�b�Ԗ炷.

	// �I��
	_tprintf(_T("Beep 440Hz End!\n"));	// "Beep 440Hz End!"�Əo��.

	// �v���O�����̏I��.
	return 0;

}