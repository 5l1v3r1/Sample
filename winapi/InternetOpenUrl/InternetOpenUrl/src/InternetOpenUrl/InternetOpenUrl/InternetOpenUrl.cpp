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

	// WinInet�̏�����.
	hInternet = InternetOpen(_T("B.G-STATION Sample InternetOpen"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);	// InternetOpen��WinInet������������, �߂�l�̃C���^�[�l�b�g�n���h����hInternet�Ɋi�[����.

	// �C���^�[�l�b�g�n���h���̏o��.
	_tprintf(_T("hInternet = %08x\n"), hInternet);	// _tprintf��hInternet�𕶎���ɕϊ����ďo��.

	// �w���URL���J��.
	hInetFile = InternetOpenUrl(hInternet, _T("http://bgstation0.com/sample/index.html"), NULL, 0, INTERNET_FLAG_RELOAD, 0);	// InternetOpenUrl��"http://bgstation0.com/sample/index.html"���J����, URL�n���h����hInetFile�Ɋi�[.

	// URL�n���h���̏o��.
	_tprintf(_T("hInetFile = %08x\n"), hInetFile);	// _tprintf��hInetFile�𕶎���ɕϊ����ďo��.

	// URL�n���h�������.
	InternetCloseHandle(hInetFile);	// InternetCloseHandle��hInetFile�����.

	// �C���^�[�l�b�g�n���h�������.
	InternetCloseHandle(hInternet);	// InternetCloseHandle��hInternet�����.

	// �v���O�����̏I��.
	return 0;

}