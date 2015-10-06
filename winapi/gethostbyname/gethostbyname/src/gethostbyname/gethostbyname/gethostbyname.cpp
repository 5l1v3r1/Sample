// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <winsock2.h>	// Windows�\�P�b�g
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	WSADATA wsaData;		// WinSock�̏������ɕK�v��WSADATA�\���̕ϐ�wsaData.
	char hostname[256];		// �z�X�g��hostname.
	struct hostent *host;	// �z�X�g�����i�[����hostent�\���̂ւ̃|�C���^host.
	int iRet;				// �������̌���iRet.

	// WinSock�̏�����
	iRet = WSAStartup(MAKEWORD(2, 2), &wsaData);	// WSAStartup��WinSock�̏�����.
	if (iRet){	// 0�łȂ��ꍇ.

		// �G���[����.
		_tprintf(_T("Error!(iRet = %d.)\n"), iRet);	// �߂�l���o��.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// �������������b�Z�[�W.
	_tprintf(_T("WSAStartup success!\n"));	// "WSAStartup success!"�Əo��.

	// �z�X�g���̓���.
	_tprintf(_T("hostname: "));	// hostname�̓��̓t�H�[��.
	scanf("%s", hostname);	// ���͂��ꂽ�z�X�g����hostname�Ɋi�[.

	// �z�X�g���̎擾.
	host = gethostbyname(hostname);	// gethostbyname�Ŏw�肵���z�X�g���̃z�X�g�����擾.
	if (host == NULL){	// host��NULL�Ȃ�.

		// �G���[
		_tprintf(_T("gethostbyname Error!\n"));	// �G���[���b�Z�[�W�o��.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��ďI��.

	}

	// �z�X�g�����瓱���o���ꂽIP�A�h���X���.
	_tprintf(_T("host->h_addr_list[0][0] = %02x, host->h_addr_list[0][1] = %02x, host->h_addr_list[0][3] = %02x, host->h_addr_list[0][3] = %02x\n"), host->h_addr_list[0][0], host->h_addr_list[0][1], host->h_addr_list[0][2], host->h_addr_list[0][3]);	// host->h_addr_list�̒��g���o��.

	// WinSock�̏I������.
	WSACleanup();	// WSACleanup�ŏI������.

	// �v���O�����̏I��.
	return 0;

}