// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	SYSTEMTIME st1;		// SYSTEMTIME�\���̕ϐ�st1
	SYSTEMTIME st2;		// SYSTEMTIME�\���̕ϐ�st2
	DWORD dwStart;		// �v���J�n����dwStart.
	DWORD dwEnd;		// �v���I������dwEnd.
	DWORD dwElapsed;	// �o�ߎ���dwElapsed.

	// ���[�J������(JST)���擾.(1���)
	GetLocalTime(&st1);	// GetLocalTime�Ń��[�J������(JST)���擾��, st1�Ɋi�[����.

	// ���[�J������(JST)�̏o��.(1���)
	_tprintf(_T("[JST(1)]: %d/%d/%d %d:%02d:%02d\n"), st1.wYear, st1.wMonth, st1.wDay, st1.wHour, st1.wMinute, st1.wSecond);	// st1�̊e�v�f(�N���������b)���o��.

	// �v���J�n.
	dwStart = GetTickCount();	// GetTickCount�Ōv���J�n�������擾.

	// Sleep��5�b�x��.
	Sleep(5000);	// Sleep��5�b(5000�~���b)CPU���x�܂���.

	// �v���I��.
	dwEnd = GetTickCount();		// GetTickCount�Ōv���I���������擾.

	// ���[�J������(JST)���擾.(2���)
	GetLocalTime(&st2);	// GetLocalTime�Ń��[�J������(JST)���擾��, st2�Ɋi�[����.

	// ���[�J������(JST)�̏o��.(2���)
	_tprintf(_T("[JST(2)]: %d/%d/%d %d:%02d:%02d\n"), st2.wYear, st2.wMonth, st2.wDay, st2.wHour, st2.wMinute, st2.wSecond);	// st2�̊e�v�f(�N���������b)���o��.

	// �o�ߎ��Ԃ̌v�Z�Əo��.
	dwElapsed = dwEnd - dwStart;	// dwElapsed��dwEnd - dwStart�̌��ʂ��i�[.
	_tprintf(_T("dwElapsed = %lu\n"), dwElapsed);	// dwElapsed�̒l���o��.

	// �v���O�����̏I��.
	return 0;

}