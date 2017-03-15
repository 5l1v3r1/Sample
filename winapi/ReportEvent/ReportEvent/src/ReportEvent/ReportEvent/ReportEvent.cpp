// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐�
	HANDLE hEventLog;		// �C�x���g���O����ɕK�v�ȃn���h��HANDLE�^hEventLog.
	TCHAR *ptszText;		// �C�x���g���O��������i�[����TCHAR *�^�o�b�t�@�|�C���^ptszText.
	
	// ���O������̃Z�b�g.
	ptszText = new TCHAR[1024];	// TCHAR�^���I�z��(����1024)���m��.
	_tcscpy(ptszText, _T("Test EventLog Message"));	// ptszText��"Test EventLog Message"���Z�b�g.

	// �C�x���g�\�[�X�̓o�^.
	hEventLog = RegisterEventSource(NULL, _T("ReportEvent"));	// RegisterEventSource�ŃC�x���g�\�[�X"ReportEvent"��o�^��, hEventLog���擾.
	if (hEventLog == NULL){	// �o�^���s.

		// �G���[���b�Z�[�W�o��.
		_tprintf(_T("Error!\n"));	// "Error!"�Əo��.
		delete[] ptszText;	// ptszText�����.
		return -1;	// -1��Ԃ��ďI��.

	}

	// �C�x���g���O����������.
	ReportEvent(hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1001, NULL, 1, 0, (LPCTSTR *)&ptszText, NULL);	// ReportEvent��hEventLog�ɃC�x���g���O����������.

	// �C�x���g���O�̃n���h�������.
	DeregisterEventSource(hEventLog);	// DeregisterEventSource��hEventLog�����.
	delete[] ptszText;	// ptszText�����.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��ďI��.

}