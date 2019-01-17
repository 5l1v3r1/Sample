// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <shlguid.h>	// �V�F��GUID
#include <shobjidl.h>	// �V�F���I�u�W�F�N�gIDL

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// COM�̏�����.
	CoInitialize(NULL);	// CoInitialize��COM��������.

	// �|�C���^�̏�����.
	IShellLink *pShellLink = NULL;	// IShellLink�C���^�[�t�F�[�X�|�C���^pShellLink��NULL�ŏ�����.

	// �C���X�^���X�쐬.
	HRESULT hr = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (void **)&pShellLink);	// CoCreateInstance��IShellLink�̃C���X�^���X�|�C���^��pShellLink�Ɋi�[.
	if (FAILED(hr)){	// ���s.
		_tprintf(_T("CoCreateInstance failed!\n"));	// "CoCreateInstance failed!"�Əo��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return 0;	// 0��Ԃ��ďI��.
	}

	// ����.
	_tprintf(_T("pShellLink success!, pShellLink = 0x%08x\n"), (unsigned int)pShellLink);	// "pShellLink success!"�ƂƂ���pShellLink�̒l���o��.

	// ���.
	pShellLink->Release();	// pShellLink->Release�ŉ��.

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}