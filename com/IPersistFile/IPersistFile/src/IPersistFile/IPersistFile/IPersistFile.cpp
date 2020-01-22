// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <stdio.h>		// C�W�����o��
#include <string.h>		// C�����񏈗�
#include <shlwapi.h>	// �V�F��API
#include <shlguid.h>	// �V�F��GUID
#include <shobjidl.h>	// �V�F���I�u�W�F�N�gIDL

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// COM�̏�����.
	CoInitialize(NULL);	// CoInitialize��COM��������.

	// �|�C���^�̏�����.
	IShellLink *pShellLink = NULL;	// IShellLink�C���^�[�t�F�[�X�|�C���^pShellLink��NULL�ŏ�����.
	IPersistFile *pPersistFile = NULL;	// IPersistFile�C���^�[�t�F�[�X�|�C���^pPersistFile��NULL�ŏ�����.
	TCHAR tszSrcPath[MAX_PATH] = {0};	// tszSrcPath(����MAX_PATH)��{0}�ŏ�����.

	// ���s�t�@�C��������t�H���_�̃p�X���擾.
	GetModuleFileName(NULL, tszSrcPath, MAX_PATH);	// GetModuleFileName�ł��̎��s�t�@�C���̃t���p�X���擾.
	PathRemoveFileSpec(tszSrcPath);	// PathRemoveFileSpec�Ńt�@�C�����̕�������菜��.

	// �t�@�C���̎��̂͏�L�p�X�̉���"test.txt".
	_tcscat(tszSrcPath, _T("\\test.txt"));	// ��L�p�X��"\test.txt"��A��.

	// ���̃p�X���o��.
	_tprintf(_T("tszSrcPath = %s\n"), tszSrcPath);	// tszSrcPath���o��.

	// �C���X�^���X�쐬.
	HRESULT hr = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (void **)&pShellLink);	// CoCreateInstance��IShellLink�̃C���X�^���X�|�C���^��pShellLink�Ɋi�[.
	if (FAILED(hr)){	// ���s.
		_tprintf(_T("CoCreateInstance failed!\n"));	// "CoCreateInstance failed!"�Əo��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return 0;	// 0��Ԃ��ďI��.
	}

	// ����.
	_tprintf(_T("pShellLink success!, pShellLink = 0x%08x\n"), (unsigned int)pShellLink);	// "pShellLink success!"�ƂƂ���pShellLink�̒l���o��.

	// �t�@�C�����̂̃p�X���Z�b�g.
	pShellLink->SetPath(tszSrcPath);	// pShellLink->SetPath��tszSrcPath���Z�b�g.

	// �m�F�̂��߃p�X���擾.
	TCHAR tszPath[MAX_PATH] = {0};	// tszPath(����MAX_PATH)��{0}�ŏ�����.
	pShellLink->GetPath(tszPath, MAX_PATH, NULL, SLGP_UNCPRIORITY);	// pShellLink->GetPath�Ńp�X��tszPath�Ɋi�[.

	// �p�X���o��.
	_tprintf(_T("tszPath = %s\n"), tszPath);	// tszPath���o��.

	// IPersistFile�C���^�[�t�F�[�X�|�C���^���擾.
	hr = pShellLink->QueryInterface(IID_PPV_ARGS(&pPersistFile));	// pShellLink->QueryInterface��IPersistFile�C���^�[�t�F�[�X�|�C���^pPersistFile���擾.
	if (FAILED(hr)){	// ���s.
		_tprintf(_T("pShellLink->QueryInterface failed!\n"));	// "pShellLink->QueryInterface failed!"�Əo��.
		pShellLink->Release();	// pShellLink->Release�ŉ��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return 0;	// 0��Ԃ��ďI��.
	}

	// ����.
	_tprintf(_T("pPersistFile success!, pPersistFile = 0x%08x\n"), (unsigned int)pPersistFile);

	// ���.
	pPersistFile->Release();	// pPersistFile->Release�ŉ��.
	pShellLink->Release();	// pShellLink->Release�ŉ��.

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}