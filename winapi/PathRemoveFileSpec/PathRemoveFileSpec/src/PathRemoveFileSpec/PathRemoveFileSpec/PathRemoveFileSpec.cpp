// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <shlwapi.h>	// �V�F��API

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �z��̏�����
	TCHAR tszModulePath[MAX_PATH] = {0};	// tszModulePath(����MAX_PATH)��{0}�ŏ�����.

	// ���ݎ��s���̎��s�t�@�C���̃t���p�X���擾.
	GetModuleFileName(NULL, tszModulePath, MAX_PATH);	// GetModuleFileName�ł��̎��s�t�@�C���̃t���p�X���擾.

	// �p�X���o��.
	_tprintf(_T("tszModulePath = %s\n"), tszModulePath);	// tszModulePath���o��.

	// �t�@�C�����̕�������菜��, ��������t�H���_�p�X���擾����.
	PathRemoveFileSpec(tszModulePath);	// PathRemoveFileSpec�Ńt�@�C�����̕�������菜��.

	// �p�X���o��.
	_tprintf(_T("tszModulePath = %s\n"), tszModulePath);	// tszModulePath���o��.

	// �v���O�����̏I��.
	return 0;

}