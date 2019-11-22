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
	hGlobal = GlobalAlloc(GMEM_FIXED, 16);	// GlobalAlloc�ŃT�C�Y16�̌Œ胁�������m�ۂ�, �n���h����hGlobal�ɕԂ�.

	// �������̃��b�N.
	lpszText = (LPSTR)GlobalLock(hGlobal);	// GlobalLock�Ń������̈�����b�N��, �������̐擪�A�h���X��lpszText�ɕԂ�.

	// �Œ胁�����̏ꍇ�̓n���h��hGlobal�ƃ|�C���^lpszText�̒l�͓���.
	printf("hGlobal = 0x%08x\n", (unsigned int)hGlobal);	// hGlobal�̒l���o��.
	printf("lpszText = 0x%08x\n", (unsigned int)lpszText);	// lpszText�̒l���o��.

	// ��������m�ۂ����������ɃR�s�[.
	strcpy((LPSTR)hGlobal, "ABCDE");	// strcpy��hGlobal��"ABCDE"���R�s�[.(hGlobal��LPSTR�ɃL���X�g.)

	// ������̏o��.
	printf("hGlobal = %s\n", (LPSTR)hGlobal);	// printf��hGlobal���o��.(hGlobal��LPSTR�ɃL���X�g.)
	printf("lpszText = %s\n", lpszText);	// printf��lpszText���o��.

	// �������̃A�����b�N.
	GlobalUnlock(hGlobal);	// GlobalUnlock��hGlobal�̃������̈���A�����b�N.

	// ���������.
	GlobalFree(hGlobal);	// GlobalFree��hGlobal�̃��������.

	// �Ăу������m��.
	hGlobal = GlobalAlloc(GHND | GMEM_SHARE, 16);	// GlobalAlloc�ŃT�C�Y16�̈ړ��\��0�ŏ��������ꂽ���������m�ۂ�, �n���h����hGlobal�ɕԂ�.

	// �������̃��b�N.
	lpszText = (LPSTR)GlobalLock(hGlobal);	// GlobalLock�Ń������̈�����b�N��, �������̐擪�A�h���X��lpszText�ɕԂ�.

	// �ړ��\�������̏ꍇ�̓n���h��hGlobal�ƃ|�C���^lpszText�̒l���قȂ�.
	printf("hGlobal = 0x%08x\n", (unsigned int)hGlobal);	// hGlobal�̒l���o��.
	printf("lpszText = 0x%08x\n", (unsigned int)lpszText);	// lpszText�̒l���o��.

	// ��������m�ۂ����������ɃR�s�[.
	strcpy(lpszText, "ABCDE");	// strcpy��lpszText��"ABCDE"���R�s�[.

	// ������̏o��.
	printf("lpszText = %s\n", lpszText);	// printf��lpszText���o��.

	// �������̃A�����b�N.
	GlobalUnlock(hGlobal);	// GlobalUnlock��hGlobal�̃������̈���A�����b�N.

	// ���������.
	GlobalFree(hGlobal);	// GlobalFree��hGlobal�̃��������.

	// �v���O�����̏I��.
	return 0;

}