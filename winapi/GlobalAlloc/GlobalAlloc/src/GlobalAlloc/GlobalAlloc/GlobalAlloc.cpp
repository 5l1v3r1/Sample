// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <stdio.h>		// C�W�����o��
#include <string.h>		// C�����񏈗�

// main�֐��̒�`
int main(int argc, TCHAR *argv[]){	// main�֐�

	// �ϐ��̐錾.
	HGLOBAL hGlobal;	// �q�[�v�n���h��hGlobal
	LPSTR lpszText;		// ������|�C���^lpszText

	// �������m��.
	hGlobal = GlobalAlloc(GMEM_FIXED, 16);	// GlobalAlloc�ŃT�C�Y16�̌Œ胁�������m�ۂ�, �q�[�v�n���h����hGlobal�ɕԂ�.
	
	// �������̃��b�N.
	lpszText = (LPSTR)GlobalLock(hGlobal);	// GlobalLock�Ń������̈�����b�N��, �������̐擪�A�h���X��lpszText�ɕԂ�.

	// ��������m�ۂ����������ɃR�s�[.
	strcpy(lpszText, "ABCDE");	// strcpy��lpszText��"ABCDE"���R�s�[.

	// ������̏o��.
	printf("lpszText(hGlobal) = %s\n", lpszText);	// printf��lpszText���o��.

	// �������̃A�����b�N.
	GlobalUnlock(hGlobal);	// GlobalUnlock��hGlobal�̃������̈���A�����b�N.

	// ���������.
	GlobalFree(hGlobal);	// GlobalFree��hGlobal�̃��������.

	// �v���O�����̏I��.
	return 0;

}