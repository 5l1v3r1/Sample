// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>	// TCHAR
// �Ǝ��̃w�b�_
#include "stdafx.h"	// ATL�֘A

// _Module�̒�`.
CComModule _Module;	// ���̂͂����ɒ�`.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){	// Windows�v���O�����̃G���g���|�C���g

	// �z��̐錾.
	TCHAR tszSize[32] = {0};	// TCHAR�^tszSize(����32)��{0}�ŏ�����.

	// ������
	_Module.Init(NULL, hInstance);	// _Module.Init�ŏ�����.
	
	// �T�C�Y�𕶎���ɕϊ�.
	_stprintf(tszSize, _T("_Module.cbSize = %lu"), _Module.cbSize);	// _Module.cbSize�𕶎���ɕϊ�����tszSize�Ɋi�[.
	MessageBox(NULL, tszSize, _T("CComModule"), MB_OK);	// MessageBox��tszSize��\��.

	// �I������
	_Module.Term();	// _Module.Term�ŏI������.

	// �T�C�Y�𕶎���ɕϊ�.
	_stprintf(tszSize, _T("_Module.cbSize = %lu"), _Module.cbSize);	// _Module.cbSize�𕶎���ɕϊ�����tszSize�Ɋi�[.
	MessageBox(NULL, tszSize, _T("CComModule"), MB_OK);	// MessageBox��tszSize��\��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}