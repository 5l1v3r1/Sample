// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <wininet.h>	// Win32�C���^�[�l�b�g�g���@�\

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HINTERNET hInternet;	// InternetHandle�ŕԂ��ꂽ�C���^�[�l�b�g�n���h�����i�[����HINTERNET�^�ϐ�hInternet.
	HINTERNET hSession;		// InternetConnect�ŕԂ��ꂽ�Z�b�V�����n���h�����i�[����HINTERNET�^�ϐ�hSession.
	HINTERNET hRequest;		// HttpOpenRequest�ŕԂ��ꂽ���N�G�X�g�n���h�����i�[����HINTERNET�^�ϐ�hRequest.
	DWORD dwReadSize;		// �ǂݍ��񂾃o�C�g��dwReadSize.
	BYTE btBuf[1024 + 1];	// �o�b�t�@btBuf.(����1025)

	// WinInet�̏�����.
	hInternet = InternetOpen(_T("B.G-STATION Sample InternetOpen"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);	// InternetOpen��WinInet������������, �߂�l�̃C���^�[�l�b�g�n���h����hInternet�Ɋi�[����.

	// �C���^�[�l�b�g�n���h���̏o��.
	_tprintf(_T("hInternet = %08x\n"), hInternet);	// _tprintf��hInternet�𕶎���ɕϊ����ďo��.

	// �w��̃T�[�o�ɐڑ�.
	hSession = InternetConnect(hInternet, _T("bgstation0.com"), INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);	// InternetConnect��"bgstation0.com"��HTTP�Őڑ�.
	
	// �Z�b�V�����n���h���̏o��.
	_tprintf(_T("hSession = %08x\n"), hSession);	// _tprintf��hSession�𕶎���ɕϊ����ďo��.

	// HTTP���N�G�X�g�̍쐬.
	hRequest = HttpOpenRequest(hSession, _T("GET"), _T("/sample/index.html"), NULL, _T("http://bgstation0.com/"), NULL, 0, 0);	// HttpOpenRequest��"/sample/index.html"�ւ�GET���N�G�X�g���쐬.

	// ���N�G�X�g�n���h���̏o��.
	_tprintf(_T("hRequest = %08x\n"), hRequest);	// _tprintf��hRequest�𕶎���ɕϊ����ďo��.

	// HTTP���N�G�X�g�̑��M.
	HttpSendRequest(hRequest, NULL, 0, NULL, 0);	// HttpSendRequest�ō쐬�������N�G�X�ghRequest�𑗐M.

	// �w���URL�ɃA�N�Z�X���ĕԂ��ꂽHTTP���X�|���X��ǂݍ���.
	while (1){	// �������[�v.

		// ���X�|���X�̓ǂݍ���.
		if (!InternetReadFile(hRequest, btBuf, 1024, &dwReadSize)){	// InternetReadFile�Ń��X�|���X��ǂݍ����, btBuf��1024�o�C�g���i�[. �G���[�Ȃ�FALSE.

			// �G���[����.
			_tprintf(_T("InternetReadFile Error!\n"));	// "InternetReadFile Error!"�Əo��.
			InternetCloseHandle(hRequest);				// InternetCloseHandle��hRequest�����.
			InternetCloseHandle(hSession);				// InternetCloseHandle��hSession�����.
			InternetCloseHandle(hInternet);				// InternetCloseHandle��hInternet�����.
			return -1;	// �v���O�����ُ̈�I��.

		}

		// �S�ēǂݍ��񂾂炱�̃��[�v���甲����.
		if (dwReadSize == 0){	// dwReadSize��0�Ȃ�.

			// ������.
			_tprintf(_T("\n"));	// ���s.
			break;				// break�Ŕ�����.

		}

		// �ǂݍ��񂾃o�b�t�@�̏o��.
		btBuf[dwReadSize] = 0x0;		// dwReadSize�Ԗڂ�0x0������NULL�I�[.
		printf("%s", (char *)btBuf);	// printf��btBuf���o��.

	}

	// ���N�G�X�g�n���h�������.
	InternetCloseHandle(hRequest);	// InternetCloseHandle��hRequest�����.

	// �Z�b�V�����n���h�������.
	InternetCloseHandle(hSession);	// InternetCloseHandle��hSession�����.

	// �C���^�[�l�b�g�n���h�������.
	InternetCloseHandle(hInternet);	// InternetCloseHandle��hInternet�����.

	// �v���O�����̏I��.
	return 0;

}