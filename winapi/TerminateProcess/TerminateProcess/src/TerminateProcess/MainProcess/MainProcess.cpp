// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�E������
	PROCESS_INFORMATION pi;		// �v���Z�X���pi
	STARTUPINFO si = {0};		// �X�^�[�g�A�b�v���si��0�ŏ�����.
	TCHAR tszArg[256] = {0};	// �R�}���h���C������tszArg��0�ŏ�����.
	DWORD dwExitCode = 0;		// �I���R�[�hdwExitCode��0�ŏ�����.

	// �X�^�[�g�A�b�v���̏�����.
	si.cb = sizeof(STARTUPINFO);			// si.cb��STARTUPINFO�̃T�C�Y���Z�b�g.
	_tcscpy(tszArg, _T("SubProcess.exe"));	// tszArg��"SubProcess.exe"���Z�b�g.

	// "MainProcess Start!"�Əo��.
	_tprintf(_T("MainProcess Start!\n"));	// "MainProcess Start!"�Əo��.

	// �V�����v���Z�X�̐���.
	CreateProcess(NULL, tszArg, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);	// CreateProcess�ŐV�����v���Z�X"SubProcess.exe"�����s.(��1�����̓t���p�X�łȂ��Ƃ����Ȃ���, ������NULL�ɂ��đ�2�������g����, ���΃p�X�ł����s�ł���.)

	// �������ꂽ�V�����v���Z�X�̃X���b�h�n���h���͎g��Ȃ��̂ŕ���.
	CloseHandle(pi.hThread);	// CloseHandle��pi.hThread�����.

	// 10�b�x�~������V�����v���Z�X�������I��.(�V�����v���Z�X��30�b�Ԑ����Ă���̂ŋ����I�ɏI�������邱�ƂɂȂ�.)
	Sleep(10000);	// Sleep��10000�~���b�x�~.
	TerminateProcess(pi.hProcess, 100);	// TerminateProcess�Ńv���Z�X�������I��.(�I���R�[�h��100.)

	// TerminateProcess���Ă�ł����I���R�[�h�����ɍs����, 259(STILL_ACTIVE)���Ԃ��Ă���̂�1�b�قǋx�~.
	Sleep(1000);	// Sleep��1000�~���b�x�~.

	// �V�����v���Z�X�̏I���R�[�h���擾.(�V�����v���Z�X��TerminateProcess�ŋ����I�����ꂽ�̂�, ���ɏI����Ă�����.)
	GetExitCodeProcess(pi.hProcess, &dwExitCode);	// GetExitCodeProcess�ŏI���R�[�h���擾.
	_tprintf(_T("SubProcess's dwExitCode = %lu\n"), dwExitCode);	// dwExitCode�̒l���o��.  

	// �V�����v���Z�X�̃v���Z�X�n���h�������.(�V�����v���Z�X��TerminateProcess�ŋ����I�����ꂽ�̂�, ���ɏI����Ă�����.)
	CloseHandle(pi.hProcess);	// CloseHandle��pi.hProcess�����.

	// "MainProcess End!"�Əo��.
	_tprintf(_T("MainProcess End!\n"));	// "MainProcess End!"�Əo��.

	// �v���O�����̏I��
	return 0;

}