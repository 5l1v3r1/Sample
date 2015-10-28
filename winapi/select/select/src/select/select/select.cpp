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
	int send_len;					// ���M�������b�Z�[�W������̒���send_len.
	int client_acc[5];				// �N���C�A���g�̃A�N�Z�v�g�\�P�b�g�z��client_acc.(�ő�5�N���C�A���g����M�\.)
	fd_set mask;					// select�p��fd_set�^mask.
	int range;						// �Ď�����\�P�b�g�͈̔�range.
	int i;							// ���[�v�p�ϐ�i.
	int count;						// �ڑ����̃N���C�A���g�̐�count.
	struct timeval timeout;			// timeval�^�^�C���A�E�g�ltimeout.
	int select_result;				// select�̖߂�lselect_result.
	int pos;						// �󂫗v�f�C���f�b�N�X�ꎞ�ۑ��ppos.
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

	// �N���C�A���g�̃A�N�Z�v�g�\�P�b�g�z��̏�����.
	for (i = 0; i < 5; i++){	// 0����4�܂ŌJ��Ԃ�.

		// �N���C�A���g�A�N�Z�v�g�\�P�b�g��-1�ɏ�����.
		client_acc[i] = -1;	// client_acc��S��-1�ɃZ�b�g.

	}
	count = 0;	// �ڑ����̃N���C�A���g��count��0.

	// �A�N�Z�v�g���[�v
	while (TRUE){	// ���TRUE(�^)�Ȃ̂Ŗ������[�v

		// �}�X�N�̏�����
		FD_ZERO(&mask);	// FD_ZERO�}�N����mask��������.
		FD_SET(soc, &mask);	// FD_SET�ŊĎ�����\�P�b�g�ƃ}�X�N��R�t����.
		range = soc + 1;	// �̎��_�ŊĎ�����͈͂�soc����.(������, range�ɂ͂�����1����soc + 1�Ǝw�肷��.)
		for (i = 0; i < count; i++){	// �A�N�Z�v�g�\�P�b�g������ꍇ, ������Ď��Ώ̂ɂ�, count�̐������J��Ԃ�.
			if (client_acc[i] != -1){	// client_acc[i]��-1�łȂ��ꍇ.
				FD_SET(client_acc[i], &mask);	// client_acc[i]���}�X�N�ƕR�t��.
				if (client_acc[i] + 1 > range){	// client_acc[i] + 1��range�𒴂���ꍇ.
					range = client_acc[i] + 1;	// range��client_acc[i] + 1�ɍX�V.
				}
			}
		}
		printf("count = %d\n", count);	// �ڑ����̃N���C�A���g�����o��.

		// �^�C���A�E�g�l�̐ݒ�.
		timeout.tv_sec = 5;		// 5�b.
		timeout.tv_usec = 0;	// 0�}�C�N���b.

		// select�ɂ��\�P�b�g�t�@�C���f�B�X�N���v�^�Ď�.
		select_result = select(range, (fd_set *)&mask, NULL, NULL, &timeout);	// select��range�͈̔͂�mask�ŃZ�b�g�����\�P�b�g���Ď�.
		if (select_result < 0){	// 0�ȉ��Ȃ�G���[.
			printf("select error!\n");	// "select error!"���o��.
		}
		else if (select_result == 0){	// 0�̓^�C���A�E�g.
			printf("timeout!\n");	// "timeout!"���o��.
		}
		else{	// ����ȊO.

			// �����̂������\�P�b�g���Ƃɏ���.
			// �T�[�o�\�P�b�g�̏ꍇ.
			if (FD_ISSET(soc, &mask)){	// soc�̏ꍇ.

				// �A�N�Z�v�g.
				// accept�ɓn��client_addr_len�̃Z�b�g.
				client_addr_len = sizeof(client_addr);	// client_addr_len��sizeof(client_addr)�ŃT�C�Y���Z�b�g.(��������Ȃ���, �N���C�A���g���client_addr�Ɋi�[����Ȃ�.)

				// �A�N�Z�v�g(�ڑ���)�҂�
				acc = accept(soc, (struct sockaddr *)&client_addr, &client_addr_len);	// accept�ŃA�N�Z�v�g������, �N���C�A���g�\�P�b�g��acc�Ɋi�[.
				if (acc == -1){	// acc��-1�̎��̓G���[.

					// �G���[����
					printf("accept error!\n");	// "accept error!"�Əo��.
          
				}

				// �N���C�A���g���̕\��
				client_ip_addr_str = inet_ntoa(client_addr.sin_addr);	// inet_ntoa�ŃN���C�A���g��client_addr.sin_addr��IP�A�h���X������ɕϊ�.
				client_port = ntohs(client_addr.sin_port);	// ntohs�ŃN���C�A���g��client_addr.sin_port�𕄍��Ȃ�10�i�����̃|�[�g�ԍ��ɕϊ�.
				printf("accept!(IPAddress = %s, Port = %hu)\n", client_ip_addr_str, client_port);	// IP�A�h���X�ƃ|�[�g��\��.

				// client_acc�ւ̊i�[.
				pos = -1;	// pos��-1�ɏ�����.
				for (i = 0; i < count; i++){	// count�̕���������.
					if (client_acc[i] == -1){
						pos = i;
					}
				}
				if (pos == -1){	// �󂢂ĂȂ�.
					if (count >= 5){	// �{���ɋ󂢂Ă��Ȃ�.
						printf("error!(client_acc full!)\n");	// "error!(client_acc full!)"�Əo��.
						closesocket(acc);	// acc��closesocket�ŕ���.
					}
					else{	// ����ȊO.
						pos = count;	// pos��count�̈ʒu�Ƃ���.
						count++;	// count�𑝂₷.
					}
				}
				if (pos != -1){	// pos��-1����Ȃ��ꍇ.
					client_acc[pos] = acc;	// acc��client_acc[pos]�Ɋi�[.
				}

			}

			// �A�N�Z�v�g�\�P�b�g�̏ꍇ.
			for (i = 0; i < count; i++){	// count�̕������J��Ԃ�.
				if (client_acc[i] != -1){	// client_acc[i]��-1�ł͂Ȃ���.
					if (FD_ISSET(client_acc[i], &mask)){	// client_acc[i]�̎�.
						// ����M.
						// �o�b�t�@�N���A.
						memset(buf, 0, sizeof(char) * 256);	// memset��buf��0�Ŗ��߂�.
						recv_len = recv(client_acc[i], buf, sizeof(char) * 256, 0);	// recv��client_acc[i]����̃��b�Z�[�W��buf�Ɋi�[.
						if (recv_len <= 0){	// 0�ȉ��̎�.
							closesocket(client_acc[i]);	// ����.
							client_acc[i] = -1;	// �s�v��client_acc��-1�ɂ��čė��p�\��.
							continue;	// ����.
						}
						// ���s�R�[�h�̏���
						buf[recv_len - 1] = '\0';	// "\r\n"��buf�ɓ����Ă��܂��̂�, �Ō�̕�������"\n"������.
						buf[recv_len - 2] = '\0';	// "\r\n"��buf�ɓ����Ă��܂��̂�, �Ōォ��2�Ԗڂ̕�������"\r"������.
						// server_exit����.
						if (strcmp(buf, "end") == 0){	// "end"�Ȃ�.
							closesocket(client_acc[i]);	// ����.
							client_acc[i] = -1;	// �s�v��client_acc��-1�ɂ��čė��p�\��.
							server_exit = 1;	// server_exit = 1�Ƃ���.
							break;	// ������.
						}
						// buf�̓��e���o��.
						printf("%s\n", buf);	// printf��buf�̓��e���o��.
						// �����������s�R�[�h���Ăѕt����.
						buf[recv_len - 1] = '\n';	// '\n'��t����.
						buf[recv_len - 2] = '\r';	// '\r'��t����.
						//buf�̓��e�𑗂�Ԃ�.
						send_len = send(client_acc[i], buf, strlen(buf), 0);	// send��buf�̓��e��Ԃ�.
						if (send_len <= 0){	// send_len��0�ȉ�.
							closesocket(client_acc[i]);	// ����.
							client_acc[i] = -1;	// �s�v��client_acc��-1�ɂ��čė��p�\��.
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

	// clinet_acc��S�ĕ���.
	for (i = 0; i < 5; i++){	// 5�S��.
		if (client_acc[i] != -1){	// -1����Ȃ���.
			closesocket(client_acc[i]);	// closesocket��client_acc[i]�����.
		}
	}

	// �T�[�o�\�P�b�g�t�@�C���f�B�X�N���v�^�����.
	closesocket(soc);	// closesocket��soc�����.

	// WinSock�̏I������.
	WSACleanup();	// WSACleanup�ŏI������.

	// �v���O�����̏I��
	return 0;

}