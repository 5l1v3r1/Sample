// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̏�����.
	HKEY hKey = NULL;	// �쐬�����L�[�̃n���h��HKEY�^hKey��NULL�ɏ�����.
	LONG lRet = 0;	// RegCreateKey�̖߂�lLONG�^lRet��0�ɏ�����.

	// "HKEY_CURRENT_USER\Software\RegCreateKey"�Ƃ������W�X�g���L�[�̍쐬.
	lRet = RegCreateKey(HKEY_CURRENT_USER, _T("Software\\RegCreateKey"), &hKey);	// RegCreateKey�ŃL�["HKEY_CURRENT_USER\Software\RegCreateKey"���쐬.
	if (lRet != ERROR_SUCCESS){	// ����(ERROR_SUCCESS)�łȂ����.

		// "ERROR!"�Əo��.
		_tprintf(_T("ERROR!\n"));	// "ERROR!"�Əo��.
		return -1;	// -1��Ԃ��ďI��.

	}

	// "SUCCESS!"�Əo��.
	_tprintf(_T("SUCCESS!\n"));	// "SUCCESS!"�Əo��.

	// hKey�����.
	RegCloseKey(hKey);	// RegCloseKey��hKey�����.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��ďI��.

}