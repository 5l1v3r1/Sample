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
	WSAPOLLFD wsaPollFds[6];			// WSAPOLLFD�^�z��wsaPollFds.(����6.)
	int i;								// ���[�v�p�ϐ�i
	int count = 0;						// �ڑ����N���C�A���g�̐�count��0�ɏ�����.
	int poll_result;					// poll�̖߂�lpoll_result.
	struct sockaddr_in saiClientAddr;	// �A�N�Z�v�g�����N���C�A���g�̃A�h���X���saiClientAddr.
	int iClientAddrLen;					// saiClientAddr�̃T�C�YiClientAddrLen.
	SOCKET acc;							// SOCKET�^�̃A�N�Z�v�g�\�P�b�g�t�@�C���f�B�X�N���v�^acc.
	char *client_ip_addr_str;			// �N���C�A���g��IP�A�h���X������client_ip_addr_str.
	u_short client_port;				// �A�N�Z�v�g�����N���C�A���g�̃|�[�g�ԍ�.
	int pos;							// �󂫗v�f�C���f�b�N�X�ꎞ�ۑ��ppos.
	WSABUF wsaBuf;						// WSABUF�^�ϐ�wsaBuf.
	BYTE btBuf[256];					// BYTE�^�o�b�t�@btBuf.
	DWORD dwRecvLen = 0;				// ��M�������b�Z�[�W�̒���dwRecvLen.
	DWORD dwFlags = 0;					// WSARecv�Ɏw�肷��t���O.(�K�v.)
	DWORD dwSendLen = 0;				// ���M�f�[�^�̒���dwSendLen��0�ɏ�����.
	int server_exit = 0;			// server_exit��0�ɏ�����.

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

	// pollfd�\���̔z��̏�����.
	wsaPollFds[0].fd = soc;	// 0�Ԗڂ̓T�[�o�\�P�b�gsoc.
	wsaPollFds[0].events = POLLIN;	// 0�Ԗڂ�POLLIN.
	wsaPollFds[0].revents = 0;					// revents��0.
	memset(&wsaPollFds[1], 0, sizeof(WSAPOLLFD) * 5);	// memset��wsaPollFds��������.
	for (i = 1; i <= 5; i++){	// 1����5�܂�.
		wsaPollFds[i].fd = -1;	// wsaPollFds[i].fd��-1��.
	}	
	count = 0;	// count��0��.

	// �A�N�Z�v�g���[�v
	while (TRUE){	// ���TRUE(�^)�Ȃ̂Ŗ������[�v.

		// �\�P�b�g�Ď�.
		poll_result = WSAPoll(wsaPollFds, count + 1, 1000);	// WSAPoll�ŊĎ�.
	    if (poll_result < 0){	// poll_result < 0�̎�.
			printf("WSAPoll error!\n");	// "WSAPoll error!"�Əo��.
		}
		else if (poll_result == 0){	// 0�̓^�C���A�E�g.
			printf("timeout!\n");	// "timeout!"�Əo��.
		}
		else{	// ����ȊO.

			// �����̂������\�P�b�g���Ƃɏ���.
			// �T�[�o�\�P�b�gsoc.
			if (wsaPollFds[0].revents & POLLIN){	// wsaPollFds[0].revents & POLLIN���^.

				// �A�N�Z�v�g�̑O����.
				// iClientAddrLen�̃Z�b�g.
				iClientAddrLen = sizeof(saiClientAddr);	// iClientAddrLen��sizeof(saiClientAddr)�ŃT�C�Y���Z�b�g.

				// �A�N�Z�v�g�҂�.
				acc = WSAAccept(soc, (struct sockaddr *)&saiClientAddr, &iClientAddrLen, NULL, NULL);	// WSAAccept�ŃA�N�Z�v�g������, �N���C�A���g�\�P�b�g��acc�Ɋi�[.
				if (acc == INVALID_SOCKET){	// acc��INVALID_SOCKET( == -1)�Ȃ�.

					// �G���[����
					_tprintf(_T("WSAAccept Error!\n"));	// "WSAAccept Error!"�Əo��.

				}

				// �N���C�A���g��IP�A�h���X������ƃ|�[�g�ԍ����o��.
				client_ip_addr_str = inet_ntoa(saiClientAddr.sin_addr);								// inet_ntoa�ŃN���C�A���g��saiClientAddr.sin_addr��IP�A�h���X������ɕϊ�.
				WSANtohs(acc, saiClientAddr.sin_port, &client_port);								// WSANtohs�ŃN���C�A���g�̃|�[�g�ԍ����z�X�g�o�C�g�I�[�_�ɕϊ�.
				printf("accept!(IPAddress = %s, Port = %hu)\n", client_ip_addr_str, client_port);	// IP�A�h���X�ƃ|�[�g�ԍ����o��.

				// fds�ւ̊i�[.
				pos = -1;	// pos��-1�ɏ�����.
				for (i = 1; i < count + 1; i++){	// count�̕���������.
					if (wsaPollFds[i].fd == -1){
						pos = i;	// �󂢂Ă��i�Ƃ���.
					}
				}
				if (pos == -1){
					if (count >= 5){	// �{���ɋ󂢂ĂȂ�.
						printf("error!(fds full!)\n");	// ��t
						closesocket(acc);	// ����.
					}
					else{
						pos = count + 1;	// pos��count + 1�Ƃ���.
						count++;	// count���₷.
					}
				}
				if (pos != -1){	// ��������.
					wsaPollFds[pos].fd = acc;	// wsaPollFds[pos].fd��acc��.
					wsaPollFds[pos].events = POLLIN;	// wsaPollFds[pos].events��POLLIN��.
				}

			}

			// �A�N�Z�v�g�\�P�b�gwsaPollFds
			for (i = 1; i < count + 1; i++){	// count�̕��J��Ԃ�.
				if (wsaPollFds[i].fd != -1){	// wsaPollFds[i].fd��-1�ł͂Ȃ���.
					if (wsaPollFds[i].revents & POLLIN){	// wsaPollFds[i].revents & POLLIN���^.
						// ����M.
						// �o�b�t�@���N���A.
						memset(btBuf, 0, sizeof(BYTE) * 256);	// memset��btBuf��0�Ŗ��߂�.
						// wsaBuf�̃Z�b�g.
						wsaBuf.buf = (char *)btBuf;				// wsaBuf.buf��btBuf���L���X�g���ăZ�b�g.
						wsaBuf.len = sizeof(BYTE) * 256;		// wsaBuf.len��sizeof(BYTE) * 256���Z�b�g.
						// �N���C�A���g���烁�b�Z�[�W��M.
						WSARecv(wsaPollFds[i].fd, &wsaBuf, 1, &dwRecvLen, &dwFlags, NULL, NULL);	// WSARecv�Ŏ�M.
						if (dwRecvLen <= 0){	// 0�ȉ��̎�.
							closesocket(wsaPollFds[i].fd);	// ����.
							wsaPollFds[i].fd = -1;		// -1�ɂ��čė��p�\��.
							wsaPollFds[i].events = 0;	// 0�ɂ��čė��p�\��.
							wsaPollFds[i].revents = 0;	// 0�ɂ��čė��p�\��.
							continue;	// ����.
						}
						// ���s�R�[�h�̏���
						wsaBuf.buf[dwRecvLen - 1] = '\0';	// "\r\n"��wsaBuf.buf�ɓ����Ă��܂��̂�, �Ō�̕�������"\n"������.
						wsaBuf.buf[dwRecvLen - 2] = '\0';	// "\r\n"��wsaBuf.buf�ɓ����Ă��܂��̂�, �Ōォ��2�Ԗڂ̕�������"\r"������.
						// server_exit����.
						if (strcmp(wsaBuf.buf, "end") == 0){	// "end"�Ȃ�.
							closesocket(wsaPollFds[i].fd);	// ����.
							wsaPollFds[i].fd = -1;		// -1�ɂ��čė��p�\��.
							wsaPollFds[i].events = 0;	// 0�ɂ��čė��p�\��.
							wsaPollFds[i].revents = 0;	// 0�ɂ��čė��p�\��.
							server_exit = 1;	// server_exit = 1�Ƃ���.
							break;	// ������.
						}
						// wsaBuf.buf�̓��e���o��.
						printf("%s\n", wsaBuf.buf);	// printf��wsaBuf.buf�̓��e���o��.
						// �����������s�R�[�h���Ăѕt����.
						wsaBuf.buf[dwRecvLen - 1] = '\n';	// '\n'��t����.
						wsaBuf.buf[dwRecvLen - 2] = '\r';	// '\r'��t����.
						//wsaBuf.buf�̓��e�𑗂�Ԃ�.
						WSASend(wsaPollFds[i].fd, &wsaBuf, 1, &dwSendLen, dwFlags, NULL, NULL);	// WSASend�ő��M.						
						if (dwSendLen <= 0){	// dwSendLen��0�ȉ�.
							closesocket(wsaPollFds[i].fd);	// ����.
							wsaPollFds[i].fd = -1;		// -1�ɂ��čė��p�\��.
							wsaPollFds[i].events = 0;	// 0�ɂ��čė��p�\��.
							wsaPollFds[i].revents = 0;	// 00�ɂ��čė��p�\��.
							continue;	// ����.
						}
					}
				}
			}

			// �T�[�o��~.
			if (server_exit == 1){	// server_exit��1�Ȃ�.
				break;	// ������.
			}

		}

	}

	// wsaPollFds��S�ĕ���.
	for (i = 5; i >= 0; i--){	// 6�S��.
		if (wsaPollFds[i].fd != -1){	// -1����Ȃ���.
			closesocket(wsaPollFds[i].fd);	// lose��fds[i].fd�����.
			wsaPollFds[i].fd = -1;		// -1�ɂ���.
			wsaPollFds[i].events = 0;	// 0�ɂ���.
			wsaPollFds[i].revents = 0;	// 0�ɂ���.
		}
	}
	
	// WinSock�̏I������.
	WSACleanup();	// WSACleanup�ŏI������.

	// �v���O�����̏I��.
	return 0;

}