// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <stdio.h>		// C�W�����o��
#include <string.h>		// C�����񏈗�

// main�֐��̒�`
int main(int argc, TCHAR *argv[]){	// main�֐�

	// �ϐ��̐錾.
	LPSTR lpszText;	// ������|�C���^lpszText

	// �������m��.
	lpszText = (LPSTR)VirtualAlloc(NULL, 128, MEM_COMMIT, PAGE_READWRITE);	// VirtualAlloc�Ń������m��.

	// ��������m�ۂ����������ɃR�s�[.
	strcpy(lpszText, "ABCDE");	// strcpy��lpszText��"ABCDE"���R�s�[.

	// ������̏o��.
	printf("lpszText(Virtual) = %s\n", lpszText);	// printf��lpszText���o��.

	// ���������.
	VirtualFree((LPVOID)lpszText, 0, MEM_RELEASE);	// VirtualFree�Ń��������.

	// �v���O�����̏I��.
	return 0;

}