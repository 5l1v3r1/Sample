// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <winsock2.h>	// Windows�\�P�b�g
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	WSADATA wsaData;	// WinSock�̏������ɕK�v��WSADATA�\���̕ϐ�wsaData.
	int iRet;			// �������̌���iRet.
	SOCKET soc;			// SOCKET�^�̃\�P�b�g�t�@�C���f�B�X�N���v�^soc.

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

	// �\�P�b�g�̍쐬
	soc = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, 0);	// WSASocket�Ń\�P�b�g�쐬.
	if (soc == INVALID_SOCKET){	// soc��INVALID_SOCKET( == -1)�Ȃ�.

		// �G���[����
		_tprintf(_T("WSASocket Error!\n"));	// "WSASocket Error!"�Əo��.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// soc�̒l���o��.
	_tprintf(_T("soc = %lu\n"), soc);	// soc�̒l���o��.

	// �\�P�b�g�t�@�C���f�B�X�N���v�^�����.
	closesocket(soc);	// closesocket��soc�����.

	// WinSock�̏I������.
	WSACleanup();	// WSACleanup�ŏI������.

	// �v���O�����̏I��.
	return 0;

}