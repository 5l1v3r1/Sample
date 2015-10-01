// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <wininet.h>	// Win32�C���^�[�l�b�g�g���@�\

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HINTERNET hInternet;				// InternetHandle�ŕԂ��ꂽ�C���^�[�l�b�g�n���h�����i�[����HINTERNET�^�ϐ�hInternet.
	HINTERNET hSession;					// InternetConnect�ŕԂ��ꂽ�Z�b�V�����n���h�����i�[����HINTERNET�^�ϐ�hSession.
	HINTERNET hRequest;					// HttpOpenRequest�ŕԂ��ꂽ���N�G�X�g�n���h�����i�[����HINTERNET�^�ϐ�hRequest.
	LPBYTE lpbtBuf;						// �o�b�t�@�ւ̃|�C���^lpbtBuf.
	TCHAR tszContentLengthBuf[32];		// Content-Length�̒l�𕶎���ɂ������̂��i�[����o�b�t�@.
	DWORD dwReadSize = 0;				// 1��œǂݍ��񂾃o�C�g��dwReadSize��0�ɏ�����.
	DWORD dwTotalReadSize = 0;			// �ǂݍ��񂾃o�C�g����dwTotalReadSize��0�ɏ�����.
	DWORD dwContentLengthBufLen = 32;	// tszContentLengthBuf�̃T�C�Y���i�[����DWORD�^�ϐ���32�ɏ�����.
	DWORD dwContentLength = 0;			// tszContentLengthBuf��DWORD�^���l�ɂ���dwContentLength��0�ɏ�����.

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

	// Content-Length�̎擾.
	HttpQueryInfo(hRequest, HTTP_QUERY_CONTENT_LENGTH, tszContentLengthBuf, &dwContentLengthBufLen, NULL);	// HttpQueryInfo��Content-Length���擾.(dwContentLengthBufLen�ɂ̓o�C�g�P�ʂ̕K�v�o�b�t�@�T�C�Y���i�[�����.)
	dwContentLength = _ttoi(tszContentLengthBuf);	// _ttoi��tszContentLengthBuf��DWORD�^���l�ɕϊ�.

	// �o�b�t�@�̐���.
	lpbtBuf = new BYTE[dwContentLength + 1];	// new��dwContentLength + 1�̒�����BYTE�^�o�b�t�@�z��𐶐���, lpbtBuf�Ƀ|�C���^���i�[.

	// �w���URL�ɃA�N�Z�X���ĕԂ��ꂽHTTP���X�|���X��ǂݍ���.
	while (1){	// �������[�v.

		// ���X�|���X�̓ǂݍ���.
		if (!InternetReadFile(hRequest, lpbtBuf + dwTotalReadSize, dwContentLength, &dwReadSize)){	// InternetReadFile�Ń��X�|���X��ǂݍ����, lpbtBuf�Ɋi�[. �G���[�Ȃ�FALSE.

			// �G���[����.
			delete [] lpbtBuf;							// delete [] ��lpbtBuf���.
			_tprintf(_T("InternetReadFile Error!\n"));	// "InternetReadFile Error!"�Əo��.
			InternetCloseHandle(hRequest);				// InternetCloseHandle��hRequest�����.
			InternetCloseHandle(hSession);				// InternetCloseHandle��hSession�����.
			InternetCloseHandle(hInternet);				// InternetCloseHandle��hInternet�����.
			return -1;	// �v���O�����ُ̈�I��.

		}

		// �ǂݍ��񂾑����̉��Z.
		dwTotalReadSize = dwTotalReadSize + dwReadSize;	// ����dwTotalReadSize��1��̓ǂݍ��ݐ�dwReadSize�����Z.

		// �S�ēǂݍ��񂾂炱�̃��[�v���甲����.
		if (dwTotalReadSize == dwContentLength){	// dwReadSize��dwContentLength�Ȃ�.

			// ������.
			break;	// break�Ŕ�����.

		}

	}

	// �ǂݍ��񂾃o�b�t�@�̏o��.
	lpbtBuf[dwTotalReadSize] = 0x0;	// �Ō��0x0�ŏI�[.
	printf("%s\n", lpbtBuf);	// printf��lpbtBuf���o��.

	// ���������
	delete [] lpbtBuf;	// delete [] ��lpbtBuf���.

	// ���N�G�X�g�n���h�������.
	InternetCloseHandle(hRequest);	// InternetCloseHandle��hRequest�����.

	// �Z�b�V�����n���h�������.
	InternetCloseHandle(hSession);	// InternetCloseHandle��hSession�����.

	// �C���^�[�l�b�g�n���h�������.
	InternetCloseHandle(hInternet);	// InternetCloseHandle��hInternet�����.

	// �v���O�����̏I��.
	return 0;

}