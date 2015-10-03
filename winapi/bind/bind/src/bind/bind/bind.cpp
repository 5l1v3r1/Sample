// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <winsock2.h>	// Windows�\�P�b�g
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	WSADATA wsaData;			// WinSock�̏������ɕK�v��WSADATA�\���̕ϐ�wsaData.
	int iRet;					// �������̌���iRet.
	int soc;					// �\�P�b�g�t�@�C���f�B�X�N���v�^soc.
	u_short ns_port;			// �|�[�g�ԍ��̃l�b�g���[�N�o�C�g�I�\�_�l.
	struct sockaddr_in addr;	// �A�h���X��������sockaddr_in�\����addr.

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
	soc = socket(AF_INET, SOCK_STREAM, 0);	// socket�Ń\�P�b�g�쐬.
	if (soc == -1){	// soc��-1�Ȃ�.

		// �G���[����
		_tprintf(_T("socket Error!\n"));	// "socket Error!"�Əo��.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// soc�̒l���o��.
	_tprintf(_T("soc = %d\n"), soc);	// soc�̒l���o��.

	// �|�[�g�ԍ��̕ϊ�.
	ns_port = htons(4000);	// htons�Ń|�[�g�ԍ����l�b�g���[�N�o�C�g�I�\�_�ɕϊ�.

	// �|�[�g�ԍ��̏o��.
	_tprintf(_T("port = %04x, ns_port = %04x\n"), 4000, ns_port);	// �|�[�g�ԍ��ƃl�b�g���[�N�o�C�g�I�\�_�ȃ|�[�g�ԍ����o��.

	// �o�C���h����A�h���X���addr�̐ݒ�.
	addr.sin_family = AF_INET;				// IPv4�t�@�~���[AF_INET
	addr.sin_port = ns_port;				// �|�[�g�ԍ���ns_port( == 4000).
	addr.sin_addr.S_un.S_addr = INADDR_ANY;	// ���ׂẴ��[�J���C���^�[�t�F�C�X�Ƀo�C���h.(UNIX��in_addr�Ƃ�����ƈႤ.)
	
	// soc��addr���o�C���h.
	if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) == -1){	// �߂�l��-1�̎��̓G���[.

		// �G���[����
		_tprintf(_T("bind Error!\n"));	// "bind Error!"�Əo��.
		closesocket(soc);	// closesocket��soc�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// ����������"bind Success.".
	_tprintf(_T("bind Success.\n"));	// "bind Success."�Əo��.

	// �\�P�b�g�t�@�C���f�B�X�N���v�^�����.
	closesocket(soc);	// closesocket��soc�����.

	// WinSock�̏I������.
	WSACleanup();	// WSACleanup�ŏI������.

	// �v���O�����̏I��.
	return 0;

}