// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <shlwapi.h>	// �V�F��API
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�
#include <structs.h>	// Info-ZIP(DLL)

// typedef
typedef int (WINAPI * _DLL_UNZIP)(int, char **, int, char **, LPDCL, LPUSERFUNCTIONS);

// �֐��|�C���^�̐錾
_DLL_UNZIP fpWiz_SingleEntryUnzip;	// Wiz_SingleEntryUnzip�̊֐��|�C���^

// �O���[�o���ϐ��̐錾
HANDLE g_hUF = (HANDLE)NULL;	// ���[�U�t�@���N�V�����n���h��.
LPUSERFUNCTIONS g_lpUserFunctions;	// ���[�U�t�@���N�V�����|�C���^.
HINSTANCE g_hUnzipDll;	// DLL�̃n���h��.
HANDLE g_hDCL = (HANDLE)NULL;	// DCL�n���h��.
LPDCL g_lpDCL;	// DCL�|�C���^.

// GetReplaceDlgRetVal
int WINAPI GetReplaceDlgRetVal(LPSTR filename, unsigned fnbufsiz){
	return 1;
}
// password
int WINAPI password(LPSTR p, int n, LPCSTR m, LPCSTR name){
	return 1;
}
// DisplayBuf
int WINAPI DisplayBuf(LPSTR buf, unsigned long size){
	printf("%s", (char *)buf);
	return (int)(unsigned int)size;
}
// ReceiveDllMessage
void WINAPI ReceiveDllMessage(z_uint8 ucsize, z_uint8 csiz, unsigned cfactor, unsigned mo, unsigned dy, unsigned yr, unsigned hh, unsigned mm, TCHAR c, LPCSTR filename, LPCSTR methbuf, unsigned long crc, CHAR fCrypt){

}

// main�֐��̒�`
int main(int argc, char *argv[]){	// main�֐�

	// �ϐ��̐錾
	char szPath[MAX_PATH];	// �p�X.
	char szDest[MAX_PATH];	// �o�͐�.
	int ret;	// Wiz_SingleEntryUnzip�̖߂�l.

	// ���������m��.
	g_hUF = GlobalAlloc(GPTR, (DWORD)sizeof(USERFUNCTIONS));	// GlobalAlloc�Ŋm��.
	g_hDCL = GlobalAlloc(GPTR, (DWORD)sizeof(DCL));	// GlobalAlloc�Ŋm��.

	// �|�C���^���擾.
	g_lpUserFunctions = (LPUSERFUNCTIONS)GlobalLock(g_hUF);	// g_hUF�Ń��b�N.
	g_lpDCL = (LPDCL)GlobalLock(g_hDCL);	// GlobalLock�Ń��b�N.

	// ���[�U�t�@���N�V�����̃Z�b�g.
	g_lpUserFunctions->password = password;	// �p�X���[�h
	g_lpUserFunctions->print = DisplayBuf;	// �o�b�t�@�\��
	g_lpUserFunctions->sound = NULL;	// NULL
	g_lpUserFunctions->replace = GetReplaceDlgRetVal;	// ���v���[�X
	g_lpUserFunctions->SendApplicationMessage = ReceiveDllMessage;	// DLL���b�Z�[�W��M

	// DLL�̃��[�h.
	g_hUnzipDll = LoadLibrary("unzip32.dll");	// LoadLibrary��"unzip32.dll"�����[�h.

	// �֐��|�C���^�̎擾.
	fpWiz_SingleEntryUnzip = (_DLL_UNZIP)GetProcAddress(g_hUnzipDll, "Wiz_SingleEntryUnzip");	// Wiz_SingleEntryUnzip�̃|�C���^�擾.

	// g_lpDCL�̏�����.
	memset(g_lpDCL, 0, sizeof(DCL));	// memset��g_lpDCL��0�ŏ�����.
	g_lpDCL->StructVersID = UZ_DCL_STRUCTVER;
	g_lpDCL->ndflag = 1;
	g_lpDCL->noflag = 1;
	GetModuleFileName(NULL, szPath, MAX_PATH);	// ���W���[���p�X���擾.
	PathRemoveFileSpec(szPath);	// �Ō�̃t�@�C���v�f���폜.
	strcpy(szDest, szPath);	// �p�X���R�s�[.
	g_lpDCL->lpszExtractDir = szDest;	// �o�͐�.
	strcat(szPath, "\\test.zip");	// "\test.zip"��A��.
	g_lpDCL->lpszZipFN = szPath;	// �𓀌�.

	// Wiz_SingleEntryUnzip�ɂ���(�A�[�J�C�u�W�J).
	ret = (*fpWiz_SingleEntryUnzip)(0, NULL, 0, NULL, g_lpDCL, g_lpUserFunctions);
	if (ret == 0){	// ����.
		MessageBox(NULL, "OK", "Wiz_SingleEntryUnzip", MB_OK);
	}

	// DLL�̃A�����[�h.
	FreeLibrary(g_hUnzipDll);	// FreeLibrary�ŉ��.

	// �A�����b�N
	GlobalUnlock(g_hUF);	// GlobalUnlock�ŃA�����b�N.
	GlobalUnlock(g_hDCL);	// GlobalUnlock�ŃA�����b�N.

	// ���
	GlobalFree(g_hUF);	// GlobalFree�ŉ��.
	GlobalFree(g_hDCL);	// GlobalFree�ŉ��.

	// �v���O�����̏I��.
	return 0;

}