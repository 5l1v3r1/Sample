// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	SYSTEMTIME st;	// SYSTEMTIME�\���̕ϐ�st

	// ���݂̃��[�J������(JST)���擾.
	GetLocalTime(&st);	// GetLocalTime�Ō��݂̃��[�J������(JST)���擾��, st�Ɋi�[����.

	// ���݂̃��[�J������(JST)�̏o��.
	_tprintf(_T("[JST]: %d/%d/%d %d:%02d:%02d\n"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);	// st�̊e�v�f(�N���������b)���o��.

	// �v���O�����̏I��.
	return 0;

}