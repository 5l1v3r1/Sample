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

	// WinInet�̏�����.
	hInternet = InternetOpen(_T("B.G-STATION Sample InternetOpen"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);	// InternetOpen��WinInet������������, �߂�l�̃C���^�[�l�b�g�n���h����hInternet�Ɋi�[����.

	// �C���^�[�l�b�g�n���h���̏o��.
	_tprintf(_T("hInternet = %08x\n"), hInternet);	// _tprintf��hInternet�𕶎���ɕϊ����ďo��.

	// �w��̃T�[�o�ɐڑ�.
	hSession = InternetConnect(hInternet, _T("bgstation0.com"), INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);	// InternetConnect��"bgstation0.com"��HTTP�Őڑ�.

	// �Z�b�V�����n���h���̏o��.
	_tprintf(_T("hSession = %08x\n"), hSession);	// _tprintf��hSession�𕶎���ɕϊ����ďo��.

	// �Z�b�V�����n���h�������.
	InternetCloseHandle(hSession);	// InternetCloseHandle��hSession�����.

	// �C���^�[�l�b�g�n���h�������.
	InternetCloseHandle(hInternet);	// InternetCloseHandle��hInternet�����.

	// �v���O�����̏I��.
	return 0;

}