// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <cstdio>		// �W�����o��
#include <tchar.h>		// TCHAR�Ή�

#include "IUnknown__h.h"	// MIDL����
#include "IUnknown__i.c"	// GUID

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	CoInitialize(NULL);
	IUnknown_* pUnknown = NULL;

	HRESULT hr = CoGetClassObject(CLSID_CUnknown, CLSCTX_INPROC_SERVER, NULL, IID_IUnknown_, reinterpret_cast<void**>(&pUnknown));

	if (FAILED(hr)){
		_tprintf(_T("CoCreateInstance failed!\n"));
		CoUninitialize();
		return 0;
	}

	pUnknown->Method();

	pUnknown->Release();

	CoUninitialize();

	// �v���O�����̏I��
	return 0;

}