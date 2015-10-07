// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <winsock2.h>	// Windows�\�P�b�g
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	WSADATA wsaData;				// WinSock�̏������ɕK�v��WSADATA�\���̕ϐ�wsaData.
	char hostname[256];				// �z�X�g��hostname.
	int port;						// �|�[�g�ԍ�port.
	u_short ns_port;				// �|�[�g�ԍ��̃l�b�g���[�N�o�C�g�I�\�_�l.
	struct hostent *host;			// �z�X�g�����i�[����hostent�\���̂ւ̃|�C���^host.
	int iRet;						// �������̌���iRet.
	int soc;						// �\�P�b�g�t�@�C���f�B�X�N���v�^soc.
	struct sockaddr_in target_addr;	// �ڑ���T�[�o�̂̏��target_addr.
	char tmp = '\0';				// ���s�����ǂݔ�΂��p�ϐ�tmp��'\0'�ɏ�����.

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
	ns_port = htons(port);	// htons�Ń|�[�g�ԍ����l�b�g���[�N�o�C�g�I�\�_�ɕϊ�.

	// �|�[�g�ԍ��̏o��.
	_tprintf(_T("port = %04x, ns_port = %04x\n"), port, ns_port);	// �|�[�g�ԍ��ƃl�b�g���[�N�o�C�g�I�\�_�ȃ|�[�g�ԍ����o��.

	// �ڑ���T�[�o���target_addr�̐ݒ�.
	target_addr.sin_family = AF_INET;									// IPv4�t�@�~���[AF_INET
	target_addr.sin_port = ns_port;										// �|�[�g�ԍ���ns_port.
	target_addr.sin_addr.S_un.S_addr = *(u_long *)host->h_addr_list[0];	// host��IP�A�h���X�����Z�b�g.(u_long�Ƃ���.)

	// �ڑ�
	if (connect(soc, (struct sockaddr *)&target_addr, sizeof(target_addr)) == -1){	// connect�Őڑ���T�[�o�ɐڑ�.(-1���Ԃ�����G���[.)

		// �G���[����
		_tprintf(_T("connect Error!\n"));	// "connectt Error!"�Əo��.
		closesocket(soc);	// closesocket��soc�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// ����������"connect success."
	_tprintf(_T("connect success.\n"));	// _tprintf��"connect success."�Əo��.

	// �\�P�b�g�����.
	closesocket(soc);	// closesocket��soc�����.

	// WinSock�̏I������.
	WSACleanup();	// WSACleanup�ŏI������.

	// �v���O�����̏I��.
	return 0;

}