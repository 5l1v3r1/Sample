// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// �֐��v���g�^�C�v�錾
VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR * lpszArgv);	// �T�[�r�X�̒��j����.
VOID WINAPI Handler(DWORD fdwControl);	// �T�[�r�X����v���ɑ΂���n���h������.

// �O���[�o���ϐ��̏�����.
SERVICE_STATUS_HANDLE g_hStatus = NULL;	// �T�[�r�X��ԃn���h��SERVICE_STATUS_HANDLE�^g_hStatus��NULL�ŏ�����.
SERVICE_STATUS g_ss = {0};				// �T�[�r�X��ԍ\���̕ϐ�SERVICE_STATUS�^g_ss��0�ŏ�����.
HANDLE g_hEventLog = NULL;				// �C�x���g���O����ɕK�v�ȃn���h��HANDLE�^g_hEventLog��NULL�ŏ�����.
BOOL bRun = FALSE;						// �T�[�r�X���s���ł��邩�ǂ���������BOOL�^bRun��FALSE�ɏ�����.

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �\���̔z��̏�����
	SERVICE_TABLE_ENTRY ste[] = {{_T("ServiceMain"), ServiceMain}, {NULL, NULL}};	// SERVICE_TABLE_ENTRY�\���̔z��ste���T�[�r�X��"ServiceMain"�ƃT�[�r�X���C���֐�ServiceMain�ŏ�����.(�Ō��NULL�I�[�̕K�v����.)

	// �C�x���g�\�[�X�̓o�^.
	g_hEventLog = RegisterEventSource(NULL, _T("ServiceMain"));	// RegisterEventSource�ŃC�x���g�\�[�X"ServiceMain"��o�^��, g_hEventLog���擾.
	if (g_hEventLog == NULL){	// �o�^���s.
		return -1;	// -1��Ԃ��ďI��.
	}

	// ServiceMain�̓o�^
	StartServiceCtrlDispatcher(ste);	// StartServiceCtrlDispatcher��ste��o�^.

	// �C�x���g���O�̃n���h�������.
	DeregisterEventSource(g_hEventLog);	// DeregisterEventSource��g_hEventLog�����.

	// �v���O�����̏I��
	return 0;

}

// ServiceMain�֐��̒�`
VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR * lpszArgv){	// �T�[�r�X�̒��j����.

	// �T�[�r�X����v���ɑ΂���n���h���̓o�^.
	g_hStatus = RegisterServiceCtrlHandler(_T("ServiceMain"), Handler);	// RegisterServiceCtrlHandler��Handler��o�^��, �n���h����g_hStatus�Ɋi�[.

	// �T�[�r�X��Ԃ̏�����.
	g_ss.dwServiceType = SERVICE_WIN32_OWN_PROCESS;	// �T�[�r�X�͎��g�̓Ɨ�����Win32�v���Z�X�œ���.
	g_ss.dwCurrentState = SERVICE_START_PENDING;	// �T�[�r�X�J�n�ۗ̕�.
	g_ss.dwControlsAccepted = SERVICE_ACCEPT_STOP;	// ��~�R�}���h���󂯕t����.
	g_ss.dwWin32ExitCode = NO_ERROR;	// �I���R�[�h�͂ЂƂ܂�NO_ERROR.
	g_ss.dwServiceSpecificExitCode = 0;	// ����͂Ƃ肠����0.
	g_ss.dwCheckPoint = 1;	// �J�n��҂��Ă���󋵂ɂ��邽��, �Ƃ肠����1�ɃZ�b�g.
	g_ss.dwWaitHint = 10 * 1000;	// �҂����ݎ��Ԃ�10�b���炢.
	SetServiceStatus(g_hStatus, &g_ss);	// SetServiceStatus�ŏ�L���Z�b�g.

	// �C�x���g���O��"SERVICE_START_PENDING"���o��.
	const TCHAR *ptszText1 = _T("SERVICE_START_PENDING");	// ptszText1��"SERVICE_START_PENDING"���Z�b�g.
	ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1001, NULL, 1, 0, &ptszText1, NULL);	// ReportEvent��ptszText1���C�x���g���O�ɏo��.

	// �T�[�r�X�J�n���̏����������ɏ���.(����͉������Ȃ�.)

	// �T�[�r�X��Ԃ�"���s��"�ɂ���.
	g_ss.dwCurrentState = SERVICE_RUNNING;	// SERVICE_RUNNING(���s��)�ɃZ�b�g.
	g_ss.dwCheckPoint = 0;	// �҂󋵂łȂ��Ȃ����̂�0�ɃZ�b�g.
	g_ss.dwWaitHint = 0;	// �҂󋵂łȂ��Ȃ����̂�0�ɃZ�b�g.
	SetServiceStatus(g_hStatus, &g_ss);	// SetServiceStatus�ŏ�L���Z�b�g.

	// �C�x���g���O��"SERVICE_RUNNING"���o��.
	const TCHAR *ptszText2 = _T("SERVICE_RUNNING");	// ptszText2��"SERVICE_RUNNING"���Z�b�g.
	ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1002, NULL, 1, 0, &ptszText2, NULL);	// ReportEvent��ptszText2���C�x���g���O�ɏo��.

	// �T�[�r�X���s���Ƃ���.
	bRun = TRUE;	// bRun��TRUE�ɂ���.

	// �T�[�r�X���C�����[�v�ɓ���.
	while (bRun){	// bRun���^�Ȃ烋�[�v�𑱂���.

		// �C�x���g���O��"ServiceMainLoop!"���o��.
		const TCHAR *ptszText3 = _T("ServiceMainLoop!");	// ptszText3��"ServiceMainLoop!"���Z�b�g.
		ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1003, NULL, 1, 0, &ptszText3, NULL);	// ReportEvent��ptszText3���C�x���g���O�ɏo��.

		// 1�b�҂�.
		Sleep(1000);	// 1�b�x�~.

	}

	// �T�[�r�X��Ԃ��~�ɂ���.
	g_ss.dwCurrentState = SERVICE_STOPPED;	// �T�[�r�X��~.
	g_ss.dwCheckPoint = 0;	// 0�ɃZ�b�g.
	g_ss.dwWaitHint = 0;	// 0�ɃZ�b�g.
	SetServiceStatus(g_hStatus, &g_ss);	// SetServiceStatus�ŏ�L���Z�b�g.

	// �C�x���g���O��"SERVICE_STOPPED"���o��.
	const TCHAR *ptszText6 = _T("SERVICE_STOPPED");	// ptszText6��"SERVICE_STOPPED"���Z�b�g.
	ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1006, NULL, 1, 0, &ptszText6, NULL);	// ReportEvent��ptszText6���C�x���g���O�ɏo��.

}

// Handler�֐��̒�`
VOID WINAPI Handler(DWORD fdwControl){	// �T�[�r�X����v���ɑ΂���n���h��.

	// fdwControl�̒l�ŐU�蕪����.
	switch (fdwControl){	// switch-case����fdwControl�̒l�ŐU�蕪��.

		// �T�[�r�X��~�v��
		case SERVICE_CONTROL_STOP:

			// SERVICE_CONTROL_STOP�u���b�N
			{

				// �T�[�r�X��Ԃ�"��~��"�ɃZ�b�g.
				g_ss.dwCurrentState = SERVICE_STOP_PENDING;	// �T�[�r�X��~������.
				g_ss.dwCheckPoint = 0;	// �Ƃ肠����0.
				g_ss.dwWaitHint = 10 * 1000;	// �҂����ݎ��Ԃ�10�b���炢.
				SetServiceStatus(g_hStatus, &g_ss);	// SetServiceStatus�ŏ�L���Z�b�g.

				// �C�x���g���O��"SERVICE_STOP_PENDING"���o��.
				const TCHAR *ptszText4 = _T("SERVICE_STOP_PENDING");	// ptszText4��"SERVICE_STOP_PENDING"���Z�b�g.
				ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1004, NULL, 1, 0, &ptszText4, NULL);	// ReportEvent��ptszText4���C�x���g���O�ɏo��.

				// �T�[�r�X��~����.
				bRun = FALSE;	// bRun��FALSE�ɂ��ă��[�v�𔲂�������.

			}

			// ������.
			break;	// break�Ŕ�����.

		// �T�[�r�X��Ԃ̍X�V�v��
		case SERVICE_CONTROL_INTERROGATE:

			// SERVICE_CONTROL_INTERROGATE�u���b�N
			{

				// �T�[�r�X��Ԃ�SCM�ɑ���.
				SetServiceStatus(g_hStatus, &g_ss);	// SetServiceStatus�ŏ�L���Z�b�g.

				// �C�x���g���O��"SERVICE_CONTROL_INTERROGATE"���o��.
				const TCHAR *ptszText5 = _T("SERVICE_CONTROL_INTERROGATE");	// ptszText5��"SERVICE_CONTROL_INTERROGATE"���Z�b�g.
				ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1005, NULL, 1, 0, &ptszText5, NULL);	// ReportEvent��ptszText5���C�x���g���O�ɏo��.

			}

			// ������.
			break;	// break�Ŕ�����.

		// ����ȊO.
		default:

			// ������.
			break;	// break�Ŕ�����.

	}

}