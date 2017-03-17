// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̏�����.
	HANDLE hNamedPipe;	// ���O�t���p�C�v�n���h��HANDLE�^hNamedPipe.
	TCHAR tszBuf[1024];	// �o�b�t�@TCHAR�^�z��tszBuf(����1024)

	// ���O�t���p�C�v�̍쐬.
	hNamedPipe = CreateNamedPipe(_T("\\\\.\\pipe\\TEST"), PIPE_ACCESS_DUPLEX, PIPE_TYPE_BYTE, 1, 0, 0, 3000, NULL);	//  CreateNamedPipe�Ŗ��O�t���p�C�v"\\.\pipe\TEST"���쐬��, hNamedPipe�Ɋi�[.
	if (hNamedPipe == INVALID_HANDLE_VALUE){	// �p�C�v�쐬�Ɏ��s�Ȃ�.

		// �G���[�̏o��.
		_tperror(_T("Error: CreateNamedPipe!"));	// _tperror��"Error: CreateNamedPipe!"�Əo��.
		return -1;	// -1��Ԃ��ďI��.

	}

	// ���O�t���p�C�v�ɐڑ�.
	if (!ConnectNamedPipe(hNamedPipe, NULL)){	// ConnectNamedPipe��hNamedPipe�ɐڑ���, ���s�Ȃ�.

		// �G���[�̏o��.
		_tperror(_T("Error: ConnectNamedPipe!"));	// _tperror��"Error: ConnectNamedPipe!"�Əo��.
		CloseHandle(hNamedPipe);	// hNamedPipe�����.
		return -2;	// -2��Ԃ��ďI��.

	}

	// 3�b�҂�.
	Sleep(3000);	// 3�b�x�~.

	// hNamedPipe�ɏ�������.
	char szBuf[1024] = {0};	// char�^�o�b�t�@szBuf��0�ŏ�����.
	_tcscpy(tszBuf, _T("I am Parent!"));	// tszBuf��"I am Parent!"���Z�b�g.
	DWORD len = WideCharToMultiByte(CP_ACP, 0, tszBuf, -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_ACP, 0, tszBuf, -1, szBuf, len, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.
	DWORD written = 0;
	_tprintf(_T("Parent: %s\n"), tszBuf);	// tszBuf���o��.
	if (!WriteFile(hNamedPipe, szBuf, (DWORD)strlen(szBuf), &written, NULL)){	// WriteFile��szBuf��hNamedPipe�ɏ�������, ���s�Ȃ�.

		// �G���[�̏o��.
		_tperror(_T("Error: WriteFile!"));	// _tperror��"Error: WriteFile!"�Əo��.
		CloseHandle(hNamedPipe);	// hNamedPipe�����.
		return -3;	// -3��Ԃ��ďI��.

	}

	// 9�b�҂�.
	Sleep(9000);	// 9�b�x�~.

	// hNamedPipe����ǂݍ���.
	char szBuf2[1024] = {0};	// char�^�o�b�t�@szBuf2��0�ŏ�����.
	DWORD read = 0;
	if (!ReadFile(hNamedPipe, szBuf2, 1024, &read, NULL)){	// ReadFile��szBuf2��hNamedPipe����ǂݍ��񂾓��e���i�[��, ���s�Ȃ�.

		// �G���[�̏o��.
		_tperror(_T("Error: ReadFile!"));	// _tperror��"Error: ReadFile!"�Əo��.
		CloseHandle(hNamedPipe);	// hNamedPipe�����.
		return -4;	// -4��Ԃ��ďI��.

	}
	TCHAR tszBuf2[1024] = {0};	// TCHAR�^tszBuf2��0�ŏ�����.
	DWORD len2 = MultiByteToWideChar(CP_ACP, 0, szBuf2, -1, NULL, 0);	// ���C�h�����ɕϊ����邽�߂̃T�C�Y�擾.
	MultiByteToWideChar(CP_ACP, 0, szBuf2, -1, tszBuf2, len2);	// ���C�h�����ɕϊ�.
	_tprintf(_T("Parent: %s\n"), tszBuf2);	// tszBuf2���o��.

	// �I������.
	FlushFileBuffers(hNamedPipe);	// FlushFileBuffers�Ńo�b�t�@���t���b�V��.
	DisconnectNamedPipe(hNamedPipe);	// DisconnectNamedPipe�Ńp�C�v�Ƃ̒ʐM��ؒf.
	CloseHandle(hNamedPipe);	// hNamePipe�����.

	// �v���O�����̏I��
	return 0;

}