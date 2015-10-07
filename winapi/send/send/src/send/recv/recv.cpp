// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�
#include <winsock2.h>	// Windows�\�P�b�g
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	WSADATA wsaData;				// WinSock�̏������ɕK�v��WSADATA�\���̕ϐ�wsaData.
	int iRet;						// �������̌���iRet.
	int soc;						// �\�P�b�g�t�@�C���f�B�X�N���v�^soc.
	u_short ns_port;				// �|�[�g�ԍ��̃l�b�g���[�N�o�C�g�I�\�_�l.
	struct sockaddr_in server_addr;	// �A�h���X��������sockaddr_in�\����server_addr.
	int optval = 1;					// �I�v�V�����loptval��1�ɏ�����.
	int acc;						// �A�N�Z�v�g�\�P�b�g�t�@�C���f�B�X�N���v�^acc.
	struct sockaddr_in client_addr;	// �A�N�Z�v�g�����N���C�A���g�̃A�h���X���client_addr.
	int client_addr_len;			// client_addr�̃T�C�Yclient_addr_len.
	char *client_ip_addr_str;		// �N���C�A���g��IP�A�h���X������client_ip_addr_str.
	u_short client_port;			// �A�N�Z�v�g�����N���C�A���g�̃{�[�g�ԍ�.
	char buf[256];					// char�^�o�b�t�@buf.
	int exit_flg = 0;				// ���b�Z�[�W���[�v�𔲂���t���Oexit_flg��0�ɏ�����.
	int recv_len;					// ��M�������b�Z�[�W�̒���recv_len.

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

	// �o�C���h����A�h���X���server_addr�̐ݒ�.
	server_addr.sin_family = AF_INET;				// IPv4�t�@�~���[AF_INET
	server_addr.sin_port = ns_port;					// �|�[�g�ԍ���ns_port( == 4000).
	server_addr.sin_addr.S_un.S_addr = INADDR_ANY;	// ���ׂẴ��[�J���C���^�[�t�F�C�X�Ƀo�C���h.(UNIX��in_addr�Ƃ�����ƈႤ.)

	// SO_REUSEADDR�̗L����.
	if (setsockopt(soc, SOL_SOCKET, SO_REUSEADDR, (const char *)&optval, sizeof(optval)) == -1){	// setsockopt��SO_REUSEADDR��L����.

		// �G���[����
		_tprintf(_T("setsockopt(SO_REUSEADDR) error!\n"));	// "setsockopt(SO_REUSEADDR) error!"�Əo��.
		closesocket(soc);	// closesocket��soc�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// ����������"setsockopt(SO_REUSEADDR) success."�Əo��.
	_tprintf(_T("setsockopt(SO_REUSEADDR) success.\n"));	// "setsockopt(SO_REUSEADDR) success."�Əo��.

	// soc��server_addr���o�C���h.
	if (bind(soc, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){	// �߂�l��-1�̎��̓G���[.

		// �G���[����
		_tprintf(_T("bind Error!\n"));	// "bind Error!"�Əo��.
		closesocket(soc);	// closesocket��soc�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// ����������"bind Success.".
	_tprintf(_T("bind Success.\n"));	// "bind Success."�Əo��.

	// ���b�X���J�n.
	if (listen(soc, 5) == -1){	// listen��5�܂Őڑ������b�X������.

		// �G���[����
		_tprintf(_T("listen Error!\n"));	// "listen Error!"�Əo��.
		closesocket(soc);	// closesocket��soc�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// ����������"listen success."�Əo��.
	_tprintf(_T("listen success.\n"));	// "listen success."�Əo��.

	// accept�ɓn��client_addr_len�̃Z�b�g.
	client_addr_len = sizeof(client_addr);	// client_addr_len��sizeof(client_addr)���Z�b�g.

	// �A�N�Z�v�g�҂�.
	acc = accept(soc, (struct sockaddr *)&client_addr, &client_addr_len);	// accept�ŃA�N�Z�v�g������, �N���C�A���g�\�P�b�g��acc�Ɋi�[.
	if (acc == -1){	// acc��-1�Ȃ�.

		// �G���[����
		_tprintf(_T("accept Error!\n"));	// "accept Error!"�Əo��.
		closesocket(soc);	// closesocket��soc�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// �A�N�Z�v�g�\�P�b�g�t�@�C���f�B�X�N���v�^�̏o��.
	_tprintf(_T("acc = %d\n"), acc);	// acc���o��.

	// �N���C�A���g��IP�A�h���X��������o��.
	client_ip_addr_str = inet_ntoa(client_addr.sin_addr);								// inet_ntoa�ŃN���C�A���g��client_addr.sin_addr��IP�A�h���X������ɕϊ�.
	client_port = ntohs(client_addr.sin_port);											// ntohs�ŃN���C�A���g�̃|�[�g�ԍ����z�X�g�o�C�g�I�[�_�ɕϊ�.
	printf("accept!(IPAddress = %s, Port = %hu)\n", client_ip_addr_str, client_port);	// IP�A�h���X�ƃ|�[�g�ԍ����o��.

	// �o�b�t�@���N���A.
	memset(buf, 0, sizeof(char) * 256);	// memset��buf��0�Ŗ��߂�.

	// ���b�Z�[�W�������[�v
	while (!exit_flg){	// exit_flg == 1�Ȃ�, ���̃��[�v���甲����.

		// �N���C�A���g���烁�b�Z�[�W��M.
		recv_len = recv(acc, buf, sizeof(char) * 256, 0);	// recv��acc����̃��b�Z�[�W��Ǎ���, buf�Ɋi�[.(�ǂݍ��񂾃��b�Z�[�W�̒�����recv_len�Ɋi�[.)

		// ���s�R�[�h�̏���.
		buf[recv_len - 1] = '\0';	// "\r\n"��buf�ɓ����Ă��܂��̂�, �Ō�̕�������"\n"������.
		buf[recv_len - 2] = '\0';	// "\r\n"��buf�ɓ����Ă��܂��̂�, �Ōォ��2�Ԗڂ̕�������"\r"������.

		// "end"�Ȃ甲����.
		if (strcmp(buf, "end") == 0){	// strcmp�Ŕ�r����"end"�Ȃ�.

			// ������.
			exit_flg = 1;	// exit_flg��1�ɂ���.

		}
		else{	// �����łȂ��Ȃ�buf�̓��e���o��.

			// buf���o��.
			printf("%s\n", buf);	// printf��buf���o��.

		}

	}

	// �A�N�Z�v�g�\�P�b�g�����.
	closesocket(acc);	// closesocket��acc�����.

	// �\�P�b�g�t�@�C���f�B�X�N���v�^�����.
	closesocket(soc);	// closesocket��soc�����.

	// WinSock�̏I������.
	WSACleanup();	// WSACleanup�ŏI������.

	// �v���O�����̏I��.
	return 0;

}