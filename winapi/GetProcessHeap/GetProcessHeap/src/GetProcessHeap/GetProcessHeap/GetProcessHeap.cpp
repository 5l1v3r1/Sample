// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <stdio.h>		// C�W�����o��
#include <string.h>		// C�����񏈗�

// main�֐��̒�`
int main(int argc, TCHAR *argv[]){	// main�֐�

	// �ϐ��̐錾.
	HANDLE hHeap;	// �q�[�v�n���h��hHeap

	// ���̃v���Z�X�̃q�[�v���擾.
	hHeap = GetProcessHeap();	// GetProcessHeap�ł��̃v���Z�X�̃q�[�v�n���h�����擾.

	// �q�[�v�n���h���̒l���o��.
	printf("hHeap = 0x%08x\n", hHeap);	// printf��hHeap���o��.

	// �v���O�����̏I��.
	return 0;

}