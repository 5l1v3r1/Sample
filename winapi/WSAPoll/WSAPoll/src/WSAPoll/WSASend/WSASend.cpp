// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <winsock2.h>	// Windows�\�P�b�g
#include <windows.h>	// �W��WindowsAPI
#include <string.h>		// �����񏈗�

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�E������
	WSADATA wsaData;					// WinSock�̏������ɕK�v��WSADATA�\���̕ϐ�wsaData.
	char hostname[256];					// �z�X�g��hostname.
	int port;							// �|�[�g�ԍ�port.
	u_short ns_port;					// �|�[�g�ԍ��̃l�b�g���[�N�o�C�g�I�\�_�l.
	struct hostent *host;				// �z�X�g�����i�[����hostent�\���̂ւ̃|�C���^host.
	int iRet;							// �������̌���iRet.
	SOCKET soc;							// SOCKET�^�̃\�P�b�g�t�@�C���f�B�X�N���v�^soc.
	struct sockaddr_in saiTargetAddr;	// �ڑ���T�[�o�̂̏��saiTargetAddr.
	char tmp = '\0';					// ���s�����ǂݔ�΂��p�ϐ�tmp��'\0'�ɏ�����.
	WSABUF wsaBuf;						// WSABUF�^�o�b�t�@wsaBuf.
	char szInputBuf[256];				// ���͂��ꂽ���b�Z�[�W��������i�[����o�b�t�@szInputBuf.(����256)
	int iExitFlag = 0;					// ���b�Z�[�W���[�v�𔲂���t���OiExitFlag��0�ɏ�����.
	int iInputLen = 0;					// ���͂����f�[�^�̒���iInputLen��0�ɏ�����.
	DWORD dwSendLen = 0;				// ���M�f�[�^�̒���dwSendLen��0�ɏ�����.
	DWORD dwFlags = 0;					// ���M���̃t���OdwFlags��0�ɏ�����.
	int iResult = 0;					// ���M����iResult��0�ɏ�����.

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

	// �|�[�g�ԍ��̓���.
	_tprintf(_T("port: "));		// port�̓��̓t�H�[��.
	scanf("%d", &port);			// ���͂��ꂽ�|�[�g�ԍ���port�Ɋi�[.

	// ���s�ǂݔ�΂�.
	scanf("%*c", tmp);	// ���̌�̓��͂ɉe�����c���Ȃ�����.

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
	WSAHtons(soc, port, &ns_port);	// WSAHtons�Ń|�[�g�ԍ����l�b�g���[�N�o�C�g�I�\�_�ɕϊ�.

	// �|�[�g�ԍ��̏o��.
	_tprintf(_T("port = %04x, ns_port = %04x\n"), port, ns_port);	// �|�[�g�ԍ��ƃl�b�g���[�N�o�C�g�I�\�_�ȃ|�[�g�ԍ����o��.

	// �ڑ���T�[�o���saiTargetAddr�̐ݒ�.
	saiTargetAddr.sin_family = AF_INET;														// IPv4�t�@�~���[AF_INET
	saiTargetAddr.sin_port = ns_port;														// �|�[�g�ԍ���ns_port.
	saiTargetAddr.sin_addr.S_un.S_addr = *(u_long *)host->h_addr_list[0];					// host��IP�A�h���X�����Z�b�g.(u_long�Ƃ���.)

	// �ڑ�
	if (WSAConnect(soc, (struct sockaddr *)&saiTargetAddr, sizeof(saiTargetAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR){	// WSAConnect�Őڑ���, SOCKET_ERROR�Ȃ�G���[.

		// �G���[����
		_tprintf(_T("WSAConnect Error!\n"));	// "WSAConnect Error!"�Əo��.
		closesocket(soc);	// closesocket��soc�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// ����������"WSAConnect success."
	_tprintf(_T("WSAConnect success.\n"));	// _tprintf��"WSAConnect success."�Əo��.

	// ���b�Z�[�W�������[�v
	while (!iExitFlag){	// iExitFlag == 1�Ȃ�, ���̃��[�v���甲����.

		// �o�b�t�@���N���A.
		memset(szInputBuf, 0, sizeof(char) * 256);	// memset��szInputBuf��0�Ŗ��߂�.

		// ���̓t�H�[���̏o��.
		fputs(">", stdout);	// fputs�œ��̓t�H�[��">"��W���o��stdout�ɏo��.

		// ���͕�������o�b�t�@�Ɋi�[.
		fgets(szInputBuf, 256, stdin);	// fputs��szInputBuf�ɕW������stdin������͂��ꂽ��������i�[.

		// szInputBuf�̉��s("\n")������.
		iInputLen = strlen(szInputBuf);	// szInputBuf���̕�����̒�����strlen�Ŏ擾��, iInputLen�Ɋi�[.
		if (szInputBuf[iInputLen - 1] == '\n'){	// ������'\n'�Ȃ�.
			szInputBuf[iInputLen - 1] = '\0';	// '\0'������.
			iInputLen = strlen(szInputBuf);		// ���߂ď�����̒������i�[.
		}

		// "fin"���i�[����Ă�����, ���b�Z�[�W���̓��[�v�𔲂���.
		if (strcmp(szInputBuf, "fin") == 0){	// strcmp��szInputBuf��"fin"�Ȃ�.

			// ������.
			iExitFlag = 1;	// iExitFlag��1�Ƃ���.

			// "end\r\n"�𑗐M.
			wsaBuf.buf = "end\r\n";	// wsaBuf.buf��"end\r\n"���Z�b�g.
			wsaBuf.len = 5;			// wsaBuf.len��5���Z�b�g.
			WSASend(soc, &wsaBuf, 1, &dwSendLen, dwFlags, NULL, NULL);	// WSASend�ő��M.

		}
		else{	// �����łȂ��ꍇ�͐ڑ���T�[�o�ɑ��M.

			// ���s�R�[�h("\r\n")��t��.
			szInputBuf[iInputLen] = '\r';	// '\r'��t����.
			szInputBuf[iInputLen + 1] = '\n';	// '\n'��t����.

			// szInputBuf�𑗐M.
			wsaBuf.buf = szInputBuf;	// wsaBuf.buf��szInputBuf���Z�b�g.
			wsaBuf.len = iInputLen + 2;	// wsaBuf.len��iInputLen + 2���Z�b�g.
			iResult = WSASend(soc, &wsaBuf, 1, &dwSendLen, dwFlags, NULL, NULL);	// WSASend�ő��M.
			if (iResult == SOCKET_ERROR){	// SOCKET_ERROR�Ȃ�.

				// ������.
				break;	// break�Ŕ�����.

			}

		}

	}

	// �\�P�b�g�����.
	closesocket(soc);	// closesocket��soc�����.

	// WinSock�̏I������.
	WSACleanup();	// WSACleanup�ŏI������.

	// �v���O�����̏I��.
	return 0;

}