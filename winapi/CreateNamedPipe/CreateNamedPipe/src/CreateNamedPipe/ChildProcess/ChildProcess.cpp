// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HANDLE hNamedPipe;	// ���O�t���p�C�v�n���h��HANDLE�^hNamedPipe.

	// ���O�t���p�C�v���J��.
	hNamedPipe = CreateFile(_T("\\\\.\\pipe\\TEST"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);	// CreateFile��"\\.\pipe\TEST"���J����, hNamedPipe�Ɋi�[.
	if (hNamedPipe == INVALID_HANDLE_VALUE){	// �p�C�v�쐬�Ɏ��s�Ȃ�.

		// �G���[�̏o��.
		_tperror(_T("Error: CreateFile!"));	// _tperror��"Error: CreateFile!"�Əo��.
		return -1;	// -1��Ԃ��ďI��.

	}

	// 6�b�҂�.
	Sleep(6000);	// 6�b�x�~.

	// hNamedPipe����ǂݍ���.
	char szBuf[1024] = {0};	// char�^�o�b�t�@szBuf��0�ŏ�����.
	DWORD read = 0;
	if (!ReadFile(hNamedPipe, szBuf, 1024, &read, NULL)){	// ReadFile��szBuf��hNamedPipe����ǂݍ��񂾓��e���i�[��, ���s�Ȃ�.

		// �G���[�̏o��.
		_tperror(_T("Error: ReadFile!"));	// _tperror��"Error: ReadFile!"�Əo��.
		CloseHandle(hNamedPipe);	// hNamedPipe�����.
		return -2;	// -2��Ԃ��ďI��.

	}
	TCHAR tszBuf[1024] = {0};	// TCHAR�^tszBuf��0�ŏ�����.
	DWORD len = MultiByteToWideChar(CP_ACP, 0, szBuf, -1, NULL, 0);	// ���C�h�����ɕϊ����邽�߂̃T�C�Y�擾.
	MultiByteToWideChar(CP_ACP, 0, szBuf, -1, tszBuf, len);	// ���C�h�����ɕϊ�.
	_tprintf(_T("Child: %s\n"), tszBuf);	// tszBuf���o��.

	// 3�b�҂�.
	Sleep(3000);	// 3�b�x�~.

	// hNamedPipe�ɏ�������.
	TCHAR tszBuf2[1024] = {0};	// �o�b�t�@TCHAR�^�z��tszBuf2(����1024)��0�ɏ�����.
	char szBuf2[1024] = {0};	// char�^�o�b�t�@szBuf2��0�ŏ�����.
	_tcscpy(tszBuf2, _T("I am Child!"));	// tszBuf2��"I am Child!"���Z�b�g.
	DWORD len2 = WideCharToMultiByte(CP_ACP, 0, tszBuf2, -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_ACP, 0, tszBuf2, -1, szBuf2, len2, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.
	DWORD written = 0;
	_tprintf(_T("Child: %s\n"), tszBuf2);	// tszBuf���o��.
	if (!WriteFile(hNamedPipe, szBuf2, (DWORD)strlen(szBuf2), &written, NULL)){	// WriteFile��szBuf2��hNamedPipe�ɏ�������, ���s�Ȃ�.

		// �G���[�̏o��.
		_tperror(_T("Error: WriteFile!"));	// _tperror��"Error: WriteFile!"�Əo��.
		CloseHandle(hNamedPipe);	// hNamedPipe�����.
		return -3;	// -3��Ԃ��ďI��.

	}

	// �I������.
	CloseHandle(hNamedPipe);	// hNamePipe�����.

	// �v���O�����̏I��
	return 0;

}