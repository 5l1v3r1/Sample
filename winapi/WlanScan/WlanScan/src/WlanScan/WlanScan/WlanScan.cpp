// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <wlanapi.h>	// WLAN(����LAN)API

// �����ʒm�R�[���o�b�N�֐�
static void WlanNotificationCallback(PWLAN_NOTIFICATION_DATA Arg1, PVOID Arg2){

	// �ʒm���ꂽ��Ԃ��o��.
	if (Arg1->NotificationSource == WLAN_NOTIFICATION_SOURCE_ACM){	// �ʒm����ACM�̎�.
		_tprintf(_T("WLAN_NOTIFICATION_SOURCE_ACM\n"));	// "WLAN_NOTIFICATION_SOURCE_ACM"�Əo��.
	}

}

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	DWORD dwRet;	// WlanOpenHandle�̖߂�l���i�[����DWORD�^dwRet.
	DWORD dwVer;	// �����Ŏg��WLANAPI�̃o�[�W����dwVer.
	HANDLE hClient;	// �N���C�A���g�n���h��hClient
	WLAN_INTERFACE_INFO_LIST *pwiiList;	// WLAN_INTERFACE_INFO_LIST *�^�|�C���^pwiiList
	WLAN_INTERFACE_INFO *pwii;	// WLAN_INTERFACE_INFO * �^�|�C���^pwii
	unsigned long ul;	// ���[�v�punsigned long�^�ϐ�ul
	DWORD dwPrevNotifSource;	// �ȑO�̒ʒm��.
	DWORD dwResult;	// �R�[���o�b�N�o�^�̌���.
	int iRet;	// �v���O�����̖߂�l.

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
	iRet = 0;	// iRet��0����.
	for (ul = 0; ul < pwiiList->dwNumberOfItems; ul++){

		// �ϐ��̏�����.
		unsigned long ul2 = 0;	// ���[�v�pul2��0�ŏ�����.
		WLAN_AVAILABLE_NETWORK_LIST *pNetworkList = NULL;	// WLAN_AVAILABLE_NETWORK_LIST�\���̃|�C���^pNetworkList��NULL�ŏ�����.
		DWORD dwRet = 0;	// ����dwRet��0�ŏ�����.

		// pwii�̎擾.
		pwii = (WLAN_INTERFACE_INFO *)&pwiiList->InterfaceInfo[ul];	// ul�Ԗڂ̃C���^�[�t�F�[�X����pwii�Ɋi�[.

		// �o��.
		_tprintf(_T("pwiiList->InterfaceInfo[%lu].strInterfaceDescription = %s\n"), ul, pwiiList->InterfaceInfo[ul].strInterfaceDescription);	// pwiiList->InterfaceInfo[ul].strInterfaceDescription�̓��e���o��.

		// �R�[���o�b�N�o�^.
		dwResult = WlanRegisterNotification(hClient, WLAN_NOTIFICATION_SOURCE_ACM, FALSE, (WLAN_NOTIFICATION_CALLBACK)WlanNotificationCallback, NULL, NULL, &dwPrevNotifSource);	// WlanRegisterNotification��WlanNotificationCallback��o�^.
		_tprintf(_T("dwResult = %lu, dwPrevNotifSource = %lu\n"), dwResult, dwPrevNotifSource);	// dwResult��dwPrevNotifSource���o��.
		if (dwResult != ERROR_SUCCESS){	// �G���[.

			// �G���[���b�Z�[�W�o��.
			_tprintf(_T("RegisterError!: dwRet = %lu\n"), dwRet);	// "RegisterError!"��dwRet�̒l���o��.
			iRet = -1;	// iRet��-1����.
			break;	// ������.

		}

		// �X�L����.
		dwResult = WlanScan(hClient, &pwii->InterfaceGuid, NULL, NULL, NULL);	// WlanScan�ŃX�L����.
		if (dwResult != ERROR_SUCCESS){	// �G���[.

			// �G���[���b�Z�[�W�o��.
			_tprintf(_T("ScanError!: dwRet = %lu\n"), dwRet);	// "ScanError!"��dwRet�̒l���o��.
			iRet = -1;	// iRet��-1����.
			break;	// ������.

		}

		// ��莞�ԋx�~.
		Sleep(500);	// 0.5�b�x�~.

		// �l�b�g���[�N���X�g�̎擾.
		dwRet = WlanGetAvailableNetworkList(hClient, &pwiiList->InterfaceInfo[ul].InterfaceGuid, 0, NULL, &pNetworkList);	// WlanGetAvailableNetworkList�Ńl�b�g���[�N���X�g�̎擾.
		if (dwRet == ERROR_SUCCESS){	// ����.

			// SSID�ꗗ�̏o��.
			for (ul2 = 0; ul < pNetworkList->dwNumberOfItems; ul2++){

				// network���擾����SSID�o��.
				WLAN_AVAILABLE_NETWORK *network = &pNetworkList->Network[ul2];	// netowrk�̎擾.
				DOT11_SSID *ssid = &network->dot11Ssid;	// ssid�̎擾.
				wchar_t wszSSID[256] = {0};	// wszSSID��{0}�ŏ�����.
				mbstowcs(wszSSID, (const char *)ssid->ucSSID, ssid->uSSIDLength);	// mbstowcs�ŕϊ�.
				wprintf(L"wszSSID = %s\n", wszSSID);	// wszSSID���o��.

			}

			// �l�b�g���[�N���X�g�̉��
			WlanFreeMemory(pNetworkList);	// WlanFreeMemory��pNetworkList�����.

		}

	}

	// �R�[���o�b�N����.
	if (hClient != NULL){	// hClient��NULL�łȂ��ꍇ.
		dwResult = WlanRegisterNotification(hClient, WLAN_NOTIFICATION_SOURCE_NONE, TRUE, NULL, NULL, NULL, &dwPrevNotifSource);	// NULL���Z�b�g���ĉ���.
		_tprintf(_T("dwResult = %lu, dwPrevNotifSource = %lu\n"), dwResult, dwPrevNotifSource);	// dwResult��dwPrevNotifSource���o��.
	}

	// ���������.
	WlanFreeMemory(pwiiList);	// WlanFreeMemory��pwiiList�̃��������������K�v����.

	// WLAN�̃n���h�������.
	WlanCloseHandle(hClient, NULL);	// WlanCloseHandle�Ńn���h�������.

	// �v���O�����̏I��
	return iRet;	// iRet��Ԃ�.

}