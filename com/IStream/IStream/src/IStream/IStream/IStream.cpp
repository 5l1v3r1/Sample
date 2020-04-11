// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <stdio.h>		// C�W�����o��
#include <string.h>		// C�����񏈗�
#include <shlwapi.h>	// �V�F��API
#include <shobjidl.h>	// �V�F���I�u�W�F�N�gIDL

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// COM�̏�����.
	CoInitialize(NULL);	// CoInitialize��COM��������.

	// �ϐ��̐錾�Ə�����.
	TCHAR tszPath[MAX_PATH] = {0};	// tszPath(����MAX_PATH)��{0}�ŏ�����.
	HANDLE hFile;	// �t�@�C���n���h��hFile
	DWORD dwFileSize;	// �t�@�C���T�C�YhFileSize
	HGLOBAL hGlobal;	// �O���[�o���n���h��hGlobal
	LPVOID lpBuf;	// �o�b�t�@�|�C���^lpBuf
	IStream *pStream;	// IStream�|�C���^pStream

	// ���s�t�@�C��������t�H���_�̃p�X���擾.
	GetModuleFileName(NULL, tszPath, MAX_PATH);	// GetModuleFileName�ł��̎��s�t�@�C���̃t���p�X���擾.
	PathRemoveFileSpec(tszPath);	// PathRemoveFileSpec�Ńt�@�C�����̕�������菜��.

	// �t�@�C���̎��̂͏�L�p�X�̉���"test.txt".
	_tcscat(tszPath, _T("\\test.txt"));	// ��L�p�X��"\test.txt"��A��.

	// ���̃p�X���o��.
	_tprintf(_T("tszPath = %s\n"), tszPath);	// tszPath���o��.

	// �摜�t�@�C�����J��.
	hFile = CreateFile(tszPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// "test.txt"���J��.

	// �t�@�C���T�C�Y���擾.
	dwFileSize = GetFileSize(hFile, NULL);	// GetFileSize�Ńt�@�C���T�C�Y���擾.

	// �������m��.
	hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwFileSize);	// dwFileSize���������m��.

	// ���b�N.
	lpBuf = GlobalLock(hGlobal);	// ���b�N���ă|�C���^�擾.

	// �ǂݍ���.
	ReadFile(hFile, lpBuf, dwFileSize, &dwFileSize, NULL);	// ReadFile�œǂݍ���.

	// ����.
	CloseHandle(hFile);	// �t�@�C���n���h�������.

	// �A�����b�N
	GlobalUnlock(hGlobal);	// �A�����b�N.

	// �O���[�o������������IStream���쐬.
	HRESULT hr = CreateStreamOnHGlobal(hGlobal, TRUE, &pStream);	// CreateStreamOnHGlobal��pStream��IStream�|�C���^���i�[�����.
	if (SUCCEEDED(hr)){
		
		// pStream->Stat�ŃX�g���[�������擾.
		STATSTG statstg = {0};	// statstg��{0}�ŏ�����.
		pStream->Stat(&statstg, 0);	// pStream->Stat�ŃX�g���[������statstg�Ɋi�[.
		_tprintf(_T("statstg.cbSize = %d\n"), statstg.cbSize);	// �X�g���[���T�C�Ystatstg.cbSize���o��.

		// ���.
		pStream->Release();	// IStream�I�u�W�F�N�g�|�C���^�����.

	}

	// ���.
	GlobalFree(hGlobal);	// ���.

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}