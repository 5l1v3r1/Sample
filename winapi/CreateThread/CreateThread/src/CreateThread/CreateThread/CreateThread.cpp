// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// ThreadProc�֐��̒�`
DWORD WINAPI ThreadProc(LPVOID lpParameter){

	// �ϐ��̐錾
	int i;	// ���[�v�p�ϐ�i

	// 1����5�܂ł��o��.
	for (i = 1; i <= 5; i++){	// 1����5�܂�5��J��Ԃ�.

		// i���o��.
		_tprintf(_T("i = %d\n"), i);	// _tprintf��i�̒l���o��.
		Sleep(1000);	// Sleep��1�b�x�~.

	}

	// �X���b�h�̏I��
	return 0;	// 0��Ԃ�.

}

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �z��̐錾
	int i;					// ���[�v�^�ϐ�i.
	HANDLE hThread[5];		// HANDLE�^�X���b�h�n���h���z��hThread(�v�f��5).
	DWORD dwThreadId[5];	// DWORD�^�X���b�hID�z��dwThreadId(�v�f��5).

	// �X���b�h�̈�ĊJ�n
	for (i = 0; i < 5; i++){	// 5��J��Ԃ�.

		// �X���b�h�J�n
		hThread[i] = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThreadId[i]);	// CreateThread�ŃX���b�h�����y�ъJ�n.
		if (hThread[i] != NULL){	// hThread[i]��NULL�łȂ�.
			CloseHandle(hThread[i]);	// CloseHandle��hThread[i]�����.
		}

	}

	// �X���b�h���I���܂ŋx�~.
	Sleep(5000);	// Sleep��5�b�x�~.

	// �v���O�����̏I��
	return 0;

}