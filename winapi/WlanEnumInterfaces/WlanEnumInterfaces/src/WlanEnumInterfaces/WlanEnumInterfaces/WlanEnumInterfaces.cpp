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
	WLAN_INTERFACE_INFO_LIST *pwiiList;	// WLAN_INTERFACE_INFO_LIST *�^�|�C���^pwiiList
	unsigned long ul;	// ���[�v�punsigned long�^�ϐ�ul

	// WLAN�̃n���h�����J��.
	dwRet = WlanOpenHandle(WLAN_API_MAKE_VERSION(1, 0), NULL, &dwVer, &hClient);	// WlanOpenHandle�Ńn���h�����J��.(���ʂ�dwRet�Ɋi�[.)
	if (dwRet != ERROR_SUCCESS){

		// �G���[���b�Z�[�W�o��.
		_tprintf(_T("Error!: dwRet = %lu\n"), dwRet);	// "Error!"��dwRet�̒l���o��.
		return -1;	// -1��Ԃ��ďI��.

	}

	// �����C���^�[�t�F�[�X�ꗗ���擾.
	WlanEnumInterfaces(hClient, NULL, &pwiiList);	// WlanEnumInterfaces�ŃC���^�[�t�F�[�X���X�g���擾��, pwiiList�Ɋi�[.

	// �����C���^�[�t�F�[�X�ꗗ�̏o��.
	for (ul = 0; ul < pwiiList->dwNumberOfItems; ul++){

		// �o��.
		_tprintf(_T("pwiiList->InterfaceInfo[%lu].strInterfaceDescription = %s\n"), ul, pwiiList->InterfaceInfo[ul].strInterfaceDescription);	// pwiiList->InterfaceInfo[ul].strInterfaceDescription�̓��e���o��.

	}

	// ���������.
	WlanFreeMemory(pwiiList);	// WlanFreeMemory��pwiiList�̃��������������K�v����.

	// WLAN�̃n���h�������.
	WlanCloseHandle(hClient, NULL);	// WlanCloseHandle�Ńn���h�������.

	// �v���O�����̏I��
	return 0;

}