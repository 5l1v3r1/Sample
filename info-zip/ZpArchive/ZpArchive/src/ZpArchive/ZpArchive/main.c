// �}�N���̐錾
#define API

// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <shlwapi.h>	// �V�F��API
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�
#include <structs.h>	// Info-ZIP(DLL)

// typedef
typedef int (WINAPI * _DLL_ZIP)(ZCL, LPZPOPT);
typedef int (WINAPI * _ZIP_USER_FUNCTIONS)(LPZIPUSERFUNCTIONS);

// �֐��|�C���^�̐錾
_DLL_ZIP fpZpArchive;	// ZpArchive�̊֐��|�C���^
_ZIP_USER_FUNCTIONS fpZpInit;	// ZpInit�̊֐��|�C���^

// �O���[�o���ϐ��̐錾
HANDLE g_hZUF = (HANDLE)NULL;	// ���[�U�t�@���N�V�����̃n���h����(HANDLE)NULL�ŏ�����.
LPZIPUSERFUNCTIONS g_lpZipUserFunctions;	// ���[�U�t�@���N�V�����|�C���^.
HINSTANCE g_hZipDll;	// DLL�̃n���h��.
ZPOPT g_ZpOpt;	// �I�v�V�������̍\����.
ZCL g_ZpZCL;	// �R�}���h���C�����̍\����.
HANDLE g_hFileList;	// �t�@�C�����X�g�̃n���h��.

// DummyPrint
int WINAPI DummyPrint(char far *buf, unsigned long size){
	return (unsigned int) size;
}
// DummyPassword
int WINAPI DummyPassword(LPSTR p, int n, LPCSTR m, LPCSTR name){
	return 1;
}
// DummyComment
int WINAPI DummyComment(char far *szBuf){
	szBuf[0] = '\0';
	return TRUE;
}

// main�֐��̒�`
int main(int argc, char *argv[]){	// main�֐�

	// �ϐ��̐錾
	int iInit;	// ZpInit�̖߂�l.
	char szFullPath[PATH_MAX];	// DLL�̂���t�H���_�ʒu�̃t���p�X.
	LPSTR szFileList;	// �t�@�C�����X�g������|�C���^.
	char **index;	// �t�@�C�����X�g�C���f�b�N�X.
	int cc;	// �|�C���^�T�C�Yx�t�@�C����.
	char *file;	// �t�@�C��������.
	int ret;	// ZpArchive�̖߂�l.
	char szPath[PATH_MAX];	// �p�X.

	// ���[�U�t�@���N�V�����̃��������m��.
	g_hZUF = GlobalAlloc(GPTR, (DWORD)sizeof(ZIPUSERFUNCTIONS));	// GlobalAlloc�Ŋm��.
	g_lpZipUserFunctions = (LPZIPUSERFUNCTIONS)GlobalLock(g_hZUF);	// GlobalLock�Ń��b�N.

	// ���[�U�t�@���N�V�����̃Z�b�g.
	g_lpZipUserFunctions->print = DummyPrint;	// �_�~�[�o��
	g_lpZipUserFunctions->password = DummyPassword;	// �_�~�[�p�X���[�h
	g_lpZipUserFunctions->comment = DummyComment;	// �_�~�[�R�����g

	// DLL�̃��[�h.
	g_hZipDll = LoadLibrary("zip32z64.dll");	// LoadLibrary��"zip32z64.dll"�����[�h.

	// �֐��|�C���^�̎擾.
	(_ZIP_USER_FUNCTIONS)fpZpInit = (_ZIP_USER_FUNCTIONS)GetProcAddress(g_hZipDll, "ZpInit");	// ZpInit�̃|�C���^�擾.
	(_DLL_ZIP)fpZpArchive = (_DLL_ZIP)GetProcAddress(g_hZipDll, "ZpArchive");	// ZpArchive�̃|�C���^�擾.

	// ZpInit�ɂ�鏉�����̎��s.
	iInit = (*fpZpInit)(g_lpZipUserFunctions);

	// g_ZpOpt�̏�����.
	memset(&g_ZpOpt, 0, sizeof(g_ZpOpt));	// memset��g_ZpOpt��0�ŏ�����.
	g_ZpOpt.fLevel = '6';	// ���x��6.
	g_ZpOpt.szRootDir = szFullPath;	// ���[�g�f�B���N�g���� szFullPath��.
	GetModuleFileName(NULL, szPath, MAX_PATH);	// ���W���[���p�X���擾.
	PathRemoveFileSpec(szPath);	// �Ō�̃t�@�C���v�f���폜.
	strcpy(szFullPath, szPath);	// szPath���R�s�[.

	// g_ZpZCL�̏�����.
	g_ZpZCL.argc = 1;	// 1�Ƃ���.
	g_ZpZCL.lpszZipFN = "test.zip";	// "test.zip"�Ƃ���.

	// �t�@�C�����X�g�̍쐬.
	g_hFileList = GlobalAlloc(GPTR, 0x10000);	// GlobalAlloc�Ŋm��.
	szFileList = (char *)GlobalLock(g_hFileList);	// GlobalLock�Ń��b�N.
	index = (char **)szFileList;	// �擪�A�h���X��char�̃|�C���^�|�C���^�ɃL���X�g����index�Ɋi�[.
	cc = (sizeof(char *) * g_ZpZCL.argc);	// �|�C���^�T�C�Yx�t�@�C����.
	file = szFileList + cc;	// file��cc��.
	cc = lstrlen("test.txt");	// "test.txt"��ǉ�.
    lstrcpy(file, "test.txt");	// file�ɃR�s�[.
    index[0] = file;	// file��0�Ԗڂ�.
    file += (cc + 1);	// file��i�߂�.
	g_ZpZCL.FNV = (char **)szFileList;	// �t�@�C�����X�g��ǉ�.

	// ZpArchive�ɂ�鈳�k(�A�[�J�C�u�쐬)
	ret = (*fpZpArchive)(g_ZpZCL, &g_ZpOpt);
	if (ret == 0){	// ����.
		MessageBox(NULL, "OK", "ZpArchive", MB_OK);
	}

	// �t�@�C�����X�g�̉��.
	GlobalUnlock(g_hFileList);	// GlobalUnlock�ŃA�����b�N.
	GlobalFree(g_hFileList);	// GlobalFree�ŉ��.

	// DLL�̃A�����[�h.
	FreeLibrary(g_hZipDll);	// FreeLibrary�ŉ��.

	// ���[�U�t�@���N�V�����̉��.
	GlobalUnlock(g_hZUF);	// GlobalLock�ŃA�����b�N.
	GlobalFree(g_hZUF);	// GlobalFree�ŉ��.

	// �v���O�����̏I��.
	return 0;

}