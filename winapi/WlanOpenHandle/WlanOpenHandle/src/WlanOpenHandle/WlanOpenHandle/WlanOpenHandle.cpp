// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <wlanapi.h>	// WLAN(����LAN)API

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	DWORD dwRet;	// WlanOpenHandle�̖߂�l���i�[����DWORD�^dwRet.
	DWORD dwVer;	// �����Ŏg��WLANAPI�̃o�[�W����dwVer.
	HANDLE hClient;	// �N���C�A���g�n���h��hClient

	// WLAN�̃n���h�����J��.
	dwRet = WlanOpenHandle(2, NULL, &dwVer, &hClient);	// WlanOpenHandle�Ńn���h�����J��.(���ʂ�dwRet�Ɋi�[.�o�[�W������2.)
	if (dwRet != ERROR_SUCCESS){

		// �G���[���b�Z�[�W�o��.
		_tprintf(_T("Error!: dwRet = %lu\n"), dwRet);	// "Error!"��dwRet�̒l���o��.
		return -1;	// -1��Ԃ��ďI��.

	}

	// �o�[�W�����ƃN���C�A���g�n���h�����o��.
	_tprintf(_T("dwVer = %u, hClient = 0x%08x\n"), dwVer, (DWORD)hClient);	// dwVer��hClient���o��.

	// WLAN�̃n���h�������.
	WlanCloseHandle(hClient, NULL);	// WlanCloseHandle�Ńn���h�������.

	// �v���O�����̏I��
	return 0;

}