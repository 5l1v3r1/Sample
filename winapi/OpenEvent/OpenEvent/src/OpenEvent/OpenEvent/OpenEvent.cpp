// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// �C�x���g���̒�`
#define EVENT_NAME _T("Event")

// �X���b�h�̈����Ƃ��ēn���\����THREAD_PARAM�̒�`.
typedef struct{
	int m_iNo;					// �X���b�h�ԍ�
	TCHAR m_tszMessage[32];		// �X���b�h���o�͂��郁�b�Z�[�W.
}THREAD_PARAM;	// �����THREAD_PARAM�^�̊���.

// ThreadProc�֐��̒�`
DWORD WINAPI ThreadProc(LPVOID lpParameter){

	// �ϐ��̐錾
	int i;	// ���[�v�p�ϐ�i
	THREAD_PARAM *pTP;	// THREAD_PARAM�^�|�C���^pTP.
	HANDLE hEvent;	// HANDLE�^�C�x���g�n���h���ϐ�hEvent.

	// ����lpParameter��THREAD_PARAM�^�̃|�C���^�ɃL���X�g.
	pTP = (THREAD_PARAM *)lpParameter;	// lpParameter��THREAD_ARG�^�̃|�C���^�ɃL���X�g����, pTP�Ɋi�[.

	// �C�x���g���J��.
	hEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, EVENT_NAME);	// OpenEvent�ŃC�x���gEVENT_NAME("Event")���J��.

	// �C�x���g���V�O�i����ԂɂȂ�܂ő҂�.
	WaitForSingleObject(hEvent, INFINITE);	// WaitForSingleObject�ŃC�x���g���V�O�i����ԂɂȂ�܂ő҂�.

	// ��V�O�i����Ԃɂ���.
	ResetEvent(hEvent);	// ResetEvent��hEvent���V�O�i����Ԃɂ���.

	// 1����5�܂ł��o��.
	for (i = 1; i <= 5; i++){	// 1����5�܂�5��J��Ԃ�.

		// i, pTP->m_iNo, pTP->m_tszMessage���o��.
		_tprintf(_T("i = %d, m_iNo = %d, m_tszMessage = %s\n"), i, pTP->m_iNo, pTP->m_tszMessage);	// _tprintf��i, pTP->m_iNo, pTP->m_tszMessage�̒l���o��.
		Sleep(1000);	// Sleep��1�b�x�~.

	}

	// �C�x���g�n���h�������.
	CloseHandle(hEvent);	// CloseHandle��hEvent�����.

	// �X���b�h�̏I��
	ExitThread((DWORD)pTP->m_iNo);	// ExitThread��pTP->m_iNo��(DWORD)�ɃL���X�g�������̂�n���ăX���b�h���I������.

}

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �z��̐錾
	HANDLE hThread[5];		// HANDLE�^�X���b�h�n���h���z��hThread(�v�f��5)
	DWORD dwThreadId[5];	// DWORD�^�X���b�hID�z��dwThreadId(�v�f��5)
	THREAD_PARAM tp[5];		// �����Ƃ��ēn��THREAD_PARAM�^�z��tp.(�v�f��5)
	int i;					// ���[�v�p�ϐ�i.
	DWORD dwExitCode[5];	// DWORD�^�I���R�[�h�z��dwExitCode(�v�f��5)
	HANDLE hEvent;			// HANDLE�^�C�x���g�n���h���ϐ�hEvent.

	// �C�x���g�̍쐬
	hEvent = CreateEvent(NULL, TRUE, FALSE, EVENT_NAME);	// CreateEvent��EVENT_NAME("Event")�ȃC�x���g���쐬.(�蓮���Z�b�g�ŏ�����Ԃ͔�V�O�i��.)

	// �X���b�h[0]�̊J�n
	tp[0].m_iNo = 0;	// m_iNo = 0
	_tcscpy(tp[0].m_tszMessage, _T("No.0"));	// m_tszMessage = "No.0"
	hThread[0] = CreateThread(NULL, 0, ThreadProc, &tp[0], 0, &dwThreadId[0]);	// CreateThread�ŃX���b�h�����y�ъJ�n.(������tp[0]��n���Ă���.)

	// �V�O�i����Ԃɂ���.
	SetEvent(hEvent);	// SetEvent�ŃV�O�i����Ԃɂ���.

	// �X���b�h�I���܂ő҂�.
	WaitForSingleObject(hThread[0], INFINITE);	// WaitForSingleObject�ŏI���܂ő҂�.

	// �X���b�h[1]�̊J�n
	tp[1].m_iNo = 1;	// m_iNo = 1
	_tcscpy(tp[1].m_tszMessage, _T("No.1"));	// m_tszMessage = "No.1"
	hThread[1] = CreateThread(NULL, 0, ThreadProc, &tp[1], 0, &dwThreadId[1]);	// CreateThread�ŃX���b�h�����y�ъJ�n.(������tp[1]��n���Ă���.)

	// 1�b�x�~.
	Sleep(1000);	// Sleep��1�b�x�~.

	// �V�O�i����Ԃɂ���.
	SetEvent(hEvent);	// SetEvent�ŃV�O�i����Ԃɂ���.

	// �X���b�h�I���܂ő҂�.
	WaitForSingleObject(hThread[1], INFINITE);	// WaitForSingleObject�ŏI���܂ő҂�.

	// �X���b�h[2]�̊J�n
	tp[2].m_iNo = 2;	// m_iNo = 2
	_tcscpy(tp[2].m_tszMessage, _T("No.2"));	// m_tszMessage = "No.2"
	hThread[2] = CreateThread(NULL, 0, ThreadProc, &tp[2], 0, &dwThreadId[2]);	// CreateThread�ŃX���b�h�����y�ъJ�n.(������tp[2]��n���Ă���.)
	
	// 2�b�x�~.
	Sleep(2000);	// Sleep��2�b�x�~.

	// �V�O�i����Ԃɂ���.
	SetEvent(hEvent);	// SetEvent�ŃV�O�i����Ԃɂ���.

	// �X���b�h�I���܂ő҂�.
	WaitForSingleObject(hThread[2], INFINITE);	// WaitForSingleObject�ŏI���܂ő҂�.

	// �X���b�h[3]�̊J�n
	tp[3].m_iNo = 3;	// m_iNo = 3
	_tcscpy(tp[3].m_tszMessage, _T("No.3"));	// m_tszMessage = "No.3"
	hThread[3] = CreateThread(NULL, 0, ThreadProc, &tp[3], 0, &dwThreadId[3]);	// CreateThread�ŃX���b�h�����y�ъJ�n.(������tp[3]��n���Ă���.)
	
	// 3�b�x�~.
	Sleep(3000);	// Sleep��3�b�x�~.

	// �V�O�i����Ԃɂ���.
	SetEvent(hEvent);	// SetEvent�ŃV�O�i����Ԃɂ���.

	// �X���b�h�I���܂ő҂�.
	WaitForSingleObject(hThread[3], INFINITE);	// WaitForSingleObject�ŏI���܂ő҂�.
	
	// �X���b�h[4]�̊J�n
	tp[4].m_iNo = 4;	// m_iNo = 4
	_tcscpy(tp[4].m_tszMessage, _T("No.4"));	// m_tszMessage = "No.4"
	hThread[4] = CreateThread(NULL, 0, ThreadProc, &tp[4], 0, &dwThreadId[4]);	// CreateThread�ŃX���b�h�����y�ъJ�n.(������tp[4]��n���Ă���.)

	// 4�b�x�~.
	Sleep(4000);	// Sleep��4�b�x�~.

	// �V�O�i����Ԃɂ���.
	SetEvent(hEvent);	// SetEvent�ŃV�O�i����Ԃɂ���.

	// �X���b�h�I���܂ő҂�.
	WaitForSingleObject(hThread[4], INFINITE);	// WaitForSingleObject�ŏI���܂ő҂�.

	// �I���R�[�h�擾.
	for (i = 0; i < 5; i++){	// 5��J��Ԃ�.

		// i�ԖڃX���b�h�̏I���R�[�h���擾.
		GetExitCodeThread(hThread[i], &dwExitCode[i]);	// GetExitCodeThread�Ŋe�X���b�h�̏I���R�[�h���擾.
		_tprintf(_T("dwExitCode[%d] = %lu\n"), i, dwExitCode[i]);	// dwExitCode[i]�̒l���o��.
		if (hThread[i] != NULL){	// hThread[i]��NULL�łȂ�.
			CloseHandle(hThread[i]);	// CloseHandle��hThread[i]�����.
		}

	}

	// �C�x���g�n���h�������.
	CloseHandle(hEvent);	// CloseHandle��hEvent�����.

	// �v���O�����̏I��
	return 0;

}