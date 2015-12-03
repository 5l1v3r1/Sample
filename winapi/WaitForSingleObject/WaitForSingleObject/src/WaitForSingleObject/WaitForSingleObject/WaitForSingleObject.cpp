// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// �X���b�h�̈����Ƃ��ēn���\����THREAD_PARAM�̒�`.
typedef struct{
	int m_iNo;				// �X���b�h�ԍ�
	TCHAR m_tszMessage[32];	// �X���b�h���o�͂��郁�b�Z�[�W.
}THREAD_PARAM;	// �����THREAD_PARAM�^�̊���.

// ThreadProc�֐��̒�`
DWORD WINAPI ThreadProc(LPVOID lpParameter){

	// �ϐ��̐錾
	int i;	// ���[�v�p�ϐ�i
	THREAD_PARAM *pTP;	// THREAD_PARAM�^�|�C���^pTP.

	// ����lpParameter��THREAD_PARAM�^�̃|�C���^�ɃL���X�g.
	pTP = (THREAD_PARAM *)lpParameter;	// lpParameter��THREAD_ARG�^�̃|�C���^�ɃL���X�g����, pTP�Ɋi�[.

	// 1����5�܂ł��o��.
	for (i = 1; i <= 5; i++){	// 1����5�܂�5��J��Ԃ�.

		// i, pTP->m_iNo, pTP->m_tszMessage���o��.
		_tprintf(_T("i = %d, m_iNo = %d, m_tszMessage = %s\n"), i, pTP->m_iNo, pTP->m_tszMessage);	// _tprintf��i, pTP->m_iNo, pTP->m_tszMessage�̒l���o��.
		Sleep(1000);	// Sleep��1�b�x�~.

	}

	// �X���b�h�̏I��
	ExitThread((DWORD)pTP->m_iNo);	// ExitThread��pTP->m_iNo��(DWORD)�ɃL���X�g�������̂�n���ăX���b�h���I������.

}

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HANDLE hThread;		// HANDLE�^�X���b�h�n���h��hThread
	DWORD dwThreadId;	// DWORD�^�X���b�hID dwThreadId
	THREAD_PARAM tp;	// �����Ƃ��ēn��THREAD_PARAM�^tp
	DWORD dwExitCode;	// DWORD�^�I���R�[�hdwExitCode

	// �X���b�h�̊J�n
	tp.m_iNo = 0;	// m_iNo = 0
	_tcscpy(tp.m_tszMessage, _T("No.0"));	// m_tszMessage = "No.0"
	hThread = CreateThread(NULL, 0, ThreadProc, &tp, 0, &dwThreadId);	// CreateThread�ŃX���b�h�����y�ъJ�n.(������tp��n���Ă���.)

	// �V�O�i����ԂɂȂ�܂őҋ@.
	WaitForSingleObject(hThread, INFINITE);	// WaitForSingleObject��hThread���V�O�i����ԂɂȂ�܂őҋ@.

	// �I���R�[�h�̎擾.
	GetExitCodeThread(hThread, &dwExitCode);	// GetExitCodeThread�ŃX���b�h�̏I���R�[�h���擾.
	_tprintf(_T("dwExitCode = %lu\n"), dwExitCode);	// dwExitCode�̒l���o��.
	if (hThread != NULL){	// hThread��NULL�łȂ�.
		CloseHandle(hThread);	// CloseHandle��hThread�����.
	}

	// �v���O�����̏I��
	return 0;

}