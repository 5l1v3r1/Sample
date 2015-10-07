// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�
#include <winsock2.h>	// Windows�\�P�b�g
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�E������.
	WSADATA wsaData;					// WinSock�̏������ɕK�v��WSADATA�\���̕ϐ�wsaData.
	int iRet;							// �������̌���iRet.
	SOCKET soc;							// SOCKET�^�̃\�P�b�g�t�@�C���f�B�X�N���v�^soc.
	u_short ns_port;					// �|�[�g�ԍ��̃l�b�g���[�N�o�C�g�I�\�_�l.
	struct sockaddr_in saiServerAddr;	// �A�h���X��������sockaddr_in�\����saiServerAddr.
	int optval = 1;						// �I�v�V�����loptval��1�ɏ�����.
	SOCKET acc;							// SOCKET�^�̃A�N�Z�v�g�\�P�b�g�t�@�C���f�B�X�N���v�^acc.
	struct sockaddr_in saiClientAddr;	// �A�N�Z�v�g�����N���C�A���g�̃A�h���X���saiClientAddr.
	int iClientAddrLen;					// saiClientAddr�̃T�C�YiClientAddrLen.
	char *client_ip_addr_str;			// �N���C�A���g��IP�A�h���X������client_ip_addr_str.
	u_short client_port;				// �A�N�Z�v�g�����N���C�A���g�̃|�[�g�ԍ�.
	WSABUF wsaBuf;						// WSABUF�^�ϐ�wsaBuf.
	BYTE btBuf[256];					// BYTE�^�o�b�t�@btBuf.
	DWORD dwRecvLen = 0;				// ��M�������b�Z�[�W�̒���dwRecvLen.
	int iExitFlag = 0;					// ���b�Z�[�W���[�v�𔲂���t���OiExitFlag��0�ɏ�����.
	int iResult;						// WSARecv�̌��ʂ��i�[����iResult.
	DWORD dwFlags = 0;					// WSARecv�Ɏw�肷��t���O.(�K�v.)

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

	// �|�[�g�ԍ��̕ϊ�.
	WSAHtons(soc, 4000, &ns_port);	// WSAHtons�Ń|�[�g�ԍ����l�b�g���[�N�o�C�g�I�\�_�ɕϊ�.

	// �|�[�g�ԍ��̏o��.
	_tprintf(_T("port = %04x, ns_port = %04x\n"), 4000, ns_port);	// �|�[�g�ԍ��ƃl�b�g���[�N�o�C�g�I�\�_�ȃ|�[�g�ԍ����o��.

	// �o�C���h����A�h���X���addr�̐ݒ�.
	saiServerAddr.sin_family = AF_INET;					// IPv4�t�@�~���[AF_INET
	saiServerAddr.sin_port = ns_port;					// �|�[�g�ԍ���ns_port( == 4000).
	saiServerAddr.sin_addr.S_un.S_addr = INADDR_ANY;	// ���ׂẴ��[�J���C���^�[�t�F�C�X�Ƀo�C���h.(UNIX��in_addr�Ƃ�����ƈႤ.)

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

	// soc��saiServerAddr���o�C���h.
	if (bind(soc, (struct sockaddr *)&saiServerAddr, sizeof(saiServerAddr)) == -1){	// �߂�l��-1�̎��̓G���[.

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

	// accept�ɓn��iClientAddrLen�̃Z�b�g.
	iClientAddrLen = sizeof(saiClientAddr);	// iClientAddrLen��sizeof(saiClientAddr)�ŃT�C�Y���Z�b�g.

	// �A�N�Z�v�g�҂�.
	acc = WSAAccept(soc, (struct sockaddr *)&saiClientAddr, &iClientAddrLen, NULL, NULL);	// WSAAccept�ŃA�N�Z�v�g������, �N���C�A���g�\�P�b�g��acc�Ɋi�[.
	if (acc == INVALID_SOCKET){	// acc��INVALID_SOCKET( == -1)�Ȃ�.

		// �G���[����
		_tprintf(_T("accept Error!\n"));	// "accept Error!"�Əo��.
		closesocket(soc);	// closesocket��soc�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// �A�N�Z�v�g�\�P�b�g�t�@�C���f�B�X�N���v�^�̏o��.
	_tprintf(_T("acc = %d\n"), acc);	// acc���o��.

	// �N���C�A���g��IP�A�h���X������ƃ|�[�g�ԍ����o��.
	client_ip_addr_str = inet_ntoa(saiClientAddr.sin_addr);								// inet_ntoa�ŃN���C�A���g��saiClientAddr.sin_addr��IP�A�h���X������ɕϊ�.
	WSANtohs(acc, saiClientAddr.sin_port, &client_port);								// WSANtohs�ŃN���C�A���g�̃|�[�g�ԍ����z�X�g�o�C�g�I�[�_�ɕϊ�.
	printf("accept!(IPAddress = %s, Port = %hu)\n", client_ip_addr_str, client_port);	// IP�A�h���X�ƃ|�[�g�ԍ����o��.

	// �o�b�t�@���N���A.
	memset(btBuf, 0, sizeof(BYTE) * 256);	// memset��btBuf��0�Ŗ��߂�.

	// wsaBuf�̃Z�b�g.
	wsaBuf.buf = (char *)btBuf;	// wsaBuf.buf��btBuf���L���X�g���ăZ�b�g.
	wsaBuf.len = sizeof(BYTE) * 256;	// wsaBuf.len��sizeof(BYTE) * 256���Z�b�g.

	// ���b�Z�[�W�������[�v
	while (!iExitFlag){	// iExitFlag == 1�Ȃ�, ���̃��[�v���甲����.

		// �N���C�A���g���烁�b�Z�[�W��M.
		iResult = WSARecv(acc, &wsaBuf, 1, &dwRecvLen, &dwFlags, NULL, NULL);	// WSARecv�Ŏ�M.(��2������WSABUF�^�z��̐擪�|�C���^��n���̂�, ��3�����͂��̔z��̗v�f��������1�ƂȂ�.�܂���5�����͕K�v.)
		if (iResult == SOCKET_ERROR){	// SOCKET_ERROR�Ȃ�.

			// �G���[����.
			_tprintf(_T("WSARecv Error!\n"));	// "WSARecv Error!"�Əo��.
			break;	// ������.

		}

		// ���s�R�[�h�̏���.
		btBuf[dwRecvLen - 1] = 0x0;	// "\r\n"��btBuf�ɓ����Ă��܂��̂�, �Ō�̕�������"\n"������.
		btBuf[dwRecvLen - 2] = 0x0;	// "\r\n"��btBuf�ɓ����Ă��܂��̂�, �Ōォ��2�Ԗڂ̕�������"\r"������.

		// "end"�Ȃ甲����.
		if (strcmp((char *)btBuf, "end") == 0){	// strcmp�Ŕ�r����"q"�Ȃ�.

			// ������.
			iExitFlag = 1;	// iExitFlag��1�ɂ���.

		}
		else{	// �����łȂ��Ȃ�btBuf�̓��e���o��.

			// btBuf���o��.
			printf("%s\n", (char *)btBuf);	// printf��btBuf���o��.

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