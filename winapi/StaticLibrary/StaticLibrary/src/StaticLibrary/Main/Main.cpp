// �w�b�_�t�@�C���̃C���N���[�h
#include <cstdio>				// �W�����o��
#include <tchar.h>				// TCHAR�Ή�
#include "StaticLibrary_1.h"	// �֐�StaticLibraryFunc_1
#include "StaticLibrary_2.h"	// �֐�StaticLibraryFunc_2

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// StaticLibraryFunc_1���Ă�.
	StaticLibraryFunc_1();	// �X�^�e�B�b�N���C�u����(StaticLibrary.lib)�ɒ�`����Ă���֐�StaticLibraryFunc_1���Ă�.

	// StaticLibraryFunc_2���Ă�.
	StaticLibraryFunc_2();	// �X�^�e�B�b�N���C�u����(StaticLibrary.lib)�ɒ�`����Ă���֐�StaticLibraryFunc_2���Ă�.

	// �v���O�����̏I��
	return 0;

}