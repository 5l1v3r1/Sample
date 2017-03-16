// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HANDLE hPipe1[2];	// �e����q�ւ̃p�C�v.(hPipe1[0]�͎g��Ȃ�.)
	HANDLE hPipe2[2];	// �q����e�ւ̃p�C�v.(hPipe2[1]�͎g��Ȃ�.)
	HANDLE hChildRead;	// �q���e����̓ǂݍ��݂Ɏg���p�C�v.
	HANDLE hChildWrite;	// �q���e�ւ̏������݂Ɏg���p�C�v.

	// �e����q�ւ̃p�C�v���쐬.
	if (!CreatePipe(&hPipe1[0], &hPipe1[1], NULL, 0)){	// CreatePipe�Őe����q�ւ̃p�C�v�쐬.(��������p���s�̃p�C�v���쐬.)

		// perror�ŃG���[�o��.
		_tperror(_T("CreatePipe(hPipe1)"));	// _tperror��"CreatePipe(hPipe1)"�ƃG���[�o��.
		return -1;	// -1��Ԃ��ďI��.

	}

	// �q�v���Z�X�̓ǂݍ��݃n���h���̕���.
	if (!DuplicateHandle(GetCurrentProcess(), hPipe1[0], GetCurrentProcess(), &hChildRead, 0, TRUE, DUPLICATE_SAME_ACCESS)){	// DuplicateHandle��hPipe1[0]��hChildRead�ɕ���.

		// perror�ŃG���[�o��.
		_tperror(_T("DuplicateHandle(hChildRead)"));	// _tperror��"DuplicateHandle(hChildRead)"�Əo��.
		CloseHandle(hPipe1[0]);	// hPipe1[0]�����.
		CloseHandle(hPipe1[1]);	// hPipe1[1]�����.
		return -2;	// -2��Ԃ��ďI��.

	}

	// �g��Ȃ��n���h�������.
	CloseHandle(hPipe1[0]);	// hPipe1[0]�����.

	// �q����e�ւ̃p�C�v���쐬.
	if (!CreatePipe(&hPipe2[0], &hPipe2[1], NULL, 0)){	// CreatePipe�Ŏq����e�ւ̃p�C�v�쐬.(��������p���s�̃p�C�v���쐬.)

		// perror�ŃG���[�o��.
		_tperror(_T("CreatePipe(hPipe2)"));	// _tperror��"CreatePipe(hPipe2)"�ƃG���[�o��.
		CloseHandle(hPipe1[1]);	// hPipe1[1]�����.
		CloseHandle(hChildRead);	// hChildRead�����.
		return -3;	// -3��Ԃ��ďI��.

	}

	// �q�v���Z�X�̏������݃n���h���̕���.
	if (!DuplicateHandle(GetCurrentProcess(), hPipe2[1], GetCurrentProcess(), &hChildWrite, 0, TRUE, DUPLICATE_SAME_ACCESS)){	// DuplicateHandle��hPipe2[1]��hChildWrite�ɕ���.

		// perror�ŃG���[�o��.
		_tperror(_T("DuplicateHandle(hChildWrite)"));	// _tperror��"DuplicateHandle(hChildWrite)"�Əo��.
		CloseHandle(hPipe2[0]);	// hPipe2[0]�����.
		CloseHandle(hPipe2[1]);	// hPipe2[1]�����.
		CloseHandle(hPipe1[1]);	// hPipe1[1]�����.
		CloseHandle(hChildRead);	// hChildRead�����.
		return -4;	// -4��Ԃ��ďI��.

	}

	// �g��Ȃ��n���h�������.
	CloseHandle(hPipe2[1]);	// hPipe2[1]�����.

	// �v���Z�X�̐���.
	STARTUPINFO si;	// STARTUPINFO�^si.
	TCHAR command[1024];
	_tcscpy(command, _T("ChildProcess.exe"));	// command��"ChildProcess.exe"���R�s�[.
	ZeroMemory(&si, sizeof(si));	// si��ZeroMemory�ŏ�����.
	si.cb = sizeof(STARTUPINFO);	// STARTUPINFO�̃T�C�Y.
	si.dwFlags = STARTF_USESTDHANDLES;	// �W�����o�͂̃��_�C���N�g.
	si.hStdInput = hChildRead;		// �q�v���Z�X�̓��͂�hChildRead.
	si.hStdOutput = hChildWrite;	// �q�v���Z�X�̏o�͂�hChildWrite.
	si.hStdError = GetStdHandle(STD_ERROR_HANDLE);	// �q�v���Z�X�̃G���[�o�͂�GetStdHandle�Ŏ擾�����W���G���[�o��.
	PROCESS_INFORMATION pi;	// PROCESS_INFORMATION�^pi.
	ZeroMemory(&pi, sizeof(pi));	// pi��ZeroMemory�ŏ�����.
	if (!CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)){

		// ���ׂẴp�C�v�����.
		CloseHandle(hPipe1[1]);		// hPipe1[1]�����.
		CloseHandle(hPipe2[0]);		// hPipe2[0]�����.
		CloseHandle(hChildRead);	// hChildRead�����.
		CloseHandle(hChildWrite);	// hChildWrite�����.
		return -5;	// -5��Ԃ��ďI��.

	}
	CloseHandle(pi.hThread);	// pi.hThread�����.
	CloseHandle(hChildRead);	// �e���ł͎g��Ȃ��̂ŕ���.
	CloseHandle(hChildWrite);	// �e���ł͎g��Ȃ��̂ŕ���.

	// 3�b�҂�.
	Sleep(3000);	// 3�b�x�~.

	// �q�v���Z�X�ւ̏�������.
	TCHAR tmsg[512];	// TCHAR�^�z��tmsg.
	TCHAR outtmsg[512];	// TCHAR�^�z��outtmsg.
	char msg[1024];		// char�^�z��msg.
	_tcscpy(tmsg, _T("I am Parent!"));	// tmsg��"I am Parent!"���R�s�[.
	_stprintf(outtmsg, _T("Parent: %s"), tmsg);	// �O��"Parent: "�Ƃ���outtmsg��.
	_tperror(outtmsg);	// outtmsg���o��.
	DWORD len = WideCharToMultiByte(CP_ACP, 0, tmsg, -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_ACP, 0, tmsg, -1, msg, len, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.
	DWORD written = 0;	// ���ۂ̏������݃o�C�g��wrtten��0�ɏ�����.
	if (!WriteFile(hPipe1[1], msg, (DWORD)strlen(msg), &written, NULL)){

		// ���ׂẴp�C�v�����.
		CloseHandle(hPipe1[1]);		// hPipe1[1]�����.
		CloseHandle(hPipe2[0]);		// hPipe2[0]�����.
		return -6;	// -6��Ԃ��ďI��.

	}

	// �e����q�ւ̏������݂�������.
	CloseHandle(hPipe1[1]);		// hPipe1[1]�����.

	// 9�b�҂�.
	Sleep(9000);	// 9�b�x�~.

	// �q�v���Z�X����̓ǂݍ���.
	TCHAR tbuf[512];	// TCHAR�^�z��tbuf.
	TCHAR outtbuf[512];	// TCHAR�^�z��outtbuf.
	char buf[1024] = {0};	// char�^�z��buf��0�ŏ�����..
	DWORD read = 0;	// ���ۂ̓ǂݍ��݃o�C�g��read��0�ɏ�����.
	if (!ReadFile(hPipe2[0], buf, 1024, &read, NULL)){

		// ���ׂẴp�C�v�����.
		CloseHandle(hPipe2[0]);	// hPipe2[0]�����.
		return -7;	// -7��Ԃ��ďI��.

	}
	DWORD len2 = MultiByteToWideChar(CP_ACP, 0, buf, -1, NULL, 0);	// ���C�h�����ɕϊ����邽�߂̃T�C�Y�擾.
	MultiByteToWideChar(CP_ACP, 0, buf, -1, tbuf, len2);	// ���C�h�����ɕϊ�.
	_stprintf(outtbuf, _T("Parent: %s"), tbuf);	// �O��"Parent: "�Ƃ���outtbuf��.
	_tperror(outtbuf);	// �ǂݍ��񂾕�������o��. 

	// �q����e�ւ̓ǂݍ��݂�������.
	CloseHandle(hPipe2[0]);		// hPipe2[0]�����.

	// �v���O�����̏I��
	return 0;

}