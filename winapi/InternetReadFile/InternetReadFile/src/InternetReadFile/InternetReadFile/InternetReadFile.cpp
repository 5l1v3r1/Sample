// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <wininet.h>	// Win32�C���^�[�l�b�g�g���@�\

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HINTERNET hInternet;	// InternetHandle�ŕԂ��ꂽ�C���^�[�l�b�g�n���h�����i�[����HINTERNET�^�ϐ�hInternet.
	HINTERNET hInetFile;	// InternetOpenUrl�ŕԂ��ꂽURL�n���h�����i�[����HINTERNET�^�ϐ�hInetFile.
	DWORD dwReadSize;		// �ǂݍ��񂾃o�C�g��dwReadSize.
	BYTE btBuf[1024 + 1];	// �o�b�t�@btBuf.(����1025)

	// WinInet�̏�����.
	hInternet = InternetOpen(_T("B.G-STATION Sample InternetOpen"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);	// InternetOpen��WinInet������������, �߂�l�̃C���^�[�l�b�g�n���h����hInternet�Ɋi�[����.

	// �C���^�[�l�b�g�n���h���̏o��.
	_tprintf(_T("hInternet = %08x\n"), hInternet);	// _tprintf��hInternet�𕶎���ɕϊ����ďo��.

	// �w���URL���J��.
	hInetFile = InternetOpenUrl(hInternet, _T("http://bgstation0.com/sample/index.html"), NULL, 0, INTERNET_FLAG_RELOAD, 0);	// InternetOpenUrl��"http://bgstation0.com/sample/index.html"���J����, URL�n���h����hInetFile�Ɋi�[.

	// URL�n���h���̏o��.
	_tprintf(_T("hInetFile = %08x\n"), hInetFile);	// _tprintf��hInetFile�𕶎���ɕϊ����ďo��.

	// �w���URL�ɃA�N�Z�X���ĕԂ��ꂽHTTP���X�|���X��ǂݍ���.
	while (1){	// �������[�v.

		// ���X�|���X�̓ǂݍ���.
		if (!InternetReadFile(hInetFile, btBuf, 1024, &dwReadSize)){	// InternetReadFile�Ń��X�|���X��ǂݍ����, btBuf��1024�o�C�g���i�[. �G���[�Ȃ�FALSE.

			// �G���[����.
			_tprintf(_T("InternetReadFile Error!\n"));	// "InternetReadFile Error!"�Əo��.
			InternetCloseHandle(hInetFile);				// InternetCloseHandle��hInetFile�����.
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

	// URL�n���h�������.
	InternetCloseHandle(hInetFile);	// InternetCloseHandle��hInetFile�����.

	// �C���^�[�l�b�g�n���h�������.
	InternetCloseHandle(hInternet);	// InternetCloseHandle��hInternet�����.

	// �v���O�����̏I��.
	return 0;

}