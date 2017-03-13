// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <winsock2.h>	// Windows�\�P�b�g
#include <iphlpapi.h>	// IP�w���p�[API
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.
	
	// �ϐ��̏�����
	PIP_INTERFACE_INFO pIpInterfaceInfo = NULL;	// �C���^�[�t�F�[�X���pIpInterfaceInfo��NULL�ɏ�����.
	DWORD dwOutBufLen = 0;	// �C���^�[�t�F�[�X���̃T�C�YdwOutBufLen��0�ɏ�����.
	int i = 0;	// ���[�v�p�ϐ�i��0�ɏ�����.

	// �C���^�[�t�F�[�X�����i�[����̂ɕK�v�ȃo�b�t�@�T�C�Y���擾.
	GetInterfaceInfo(NULL, &dwOutBufLen);	// GetInterfaceInfo�̑�1������NULL���w�肷��ƕK�v�ȃo�b�t�@�T�C�Y���擾�ł���.

	// �o�b�t�@���m��.
	pIpInterfaceInfo = (PIP_INTERFACE_INFO)new BYTE[dwOutBufLen];	// new��dwOutBufLen���̃��������m�ۂ�, PIP_INTERFACE_INFO�ɃL���X�g����, pIpInterfaceInfo�Ɋi�[.

	// �C���^�[�t�F�[�X���̎擾.
	GetInterfaceInfo(pIpInterfaceInfo, &dwOutBufLen);	// GetInterfaceInfo�ŃC���^�[�t�F�[�X�����擾��, pIpInterfaceInfo�Ɋi�[.

	// �C���^�[�t�F�[�X�ꗗ�̗�.
	for (i = 0; i < pIpInterfaceInfo->NumAdapters; i++){	// for����pIpInterfaceInfo->NumAdapters�̕������J��Ԃ�.

		// �C���^�[�t�F�[�X��Index��Name���.
		_tprintf(_T("pIpInterfaceInfo->Adapter[%d].Index = %u, pIpInterfaceInfo->Adapter[%d].Name = %s\n"), i, pIpInterfaceInfo->Adapter[i].Index, i, pIpInterfaceInfo->Adapter[i].Name);	// _tprintf��pIpInterfaceInfo->Adapter[i].Index��pIpInterfaceInfo->Adapter[i].Name���o��.

	}

	// �o�b�t�@�̔j��.
	delete [] pIpInterfaceInfo;

	// �v���O�����̏I��
	return 0;

}