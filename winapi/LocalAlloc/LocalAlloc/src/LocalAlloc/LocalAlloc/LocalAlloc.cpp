// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <stdio.h>		// C�W�����o��
#include <string.h>		// C�����񏈗�

// main�֐��̒�`
int main(int argc, TCHAR *argv[]){	// main�֐�

	// �ϐ��̐錾.
	HLOCAL hLocal;		// �q�[�v�n���h��hLocal
	LPSTR lpszText;		// ������|�C���^lpszText

	// �������m��.
	hLocal = LocalAlloc(LMEM_FIXED, 16);	// LocalAlloc�ŃT�C�Y16�̌Œ胁�������m�ۂ�, �q�[�v�n���h����hLocal�ɕԂ�.
	
	// �������̃��b�N.
	lpszText = (LPSTR)LocalLock(hLocal);	// LocalLock�Ń������̈�����b�N��, �������̐擪�A�h���X��lpszText�ɕԂ�.

	// ��������m�ۂ����������ɃR�s�[.
	strcpy(lpszText, "ABCDE");	// strcpy��lpszText��"ABCDE"���R�s�[.

	// ������̏o��.
	printf("lpszText(hLocal) = %s\n", lpszText);	// printf��lpszText���o��.

	// �������̃A�����b�N.
	LocalUnlock(hLocal);	// LocalUnlock��hLocal�̃������̈���A�����b�N.

	// ���������.
	LocalFree(hLocal);	// LocalFree��hLocal�̃��������.

	// �v���O�����̏I��.
	return 0;

}