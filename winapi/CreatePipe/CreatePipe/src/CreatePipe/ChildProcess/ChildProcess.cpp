// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// 6�b�҂�.
	Sleep(6000);	// 6�b�x�~.

	// �W�����͂�ǂݍ���.
	char buf[1024] = {0};		// char�^buf��0�ŏ�����.
	TCHAR tbuf[512] = {0};		// TCHAR�^tbuf��0�ŏ�����.
	TCHAR outtbuf[512] = {0};	// TCHAR�^outtbuf��0�ŏ�����.
	fgets(buf, 1024, stdin);	// fgets�ŕW�����͂���ǂݍ���.
	DWORD len = MultiByteToWideChar(CP_ACP, 0, buf, -1, NULL, 0);	// ���C�h�����ɕϊ����邽�߂̃T�C�Y�擾.
	MultiByteToWideChar(CP_ACP, 0, buf, -1, tbuf, len);	// ���C�h�����ɕϊ�.
	_stprintf(outtbuf, _T("Child: %s"), tbuf);	// �O��"Child: "�Ƃ���outtbuf��.
	_tperror(outtbuf);	// �ǂݍ��񂾕�������o��. 

	// 3�b�҂�.
	Sleep(3000);	//3�b�x�~.

	// �W���o�͂ŏ�������.
	TCHAR tmsg[512] = {0};	// TCHAR�^�z��tmsg.
	TCHAR outtmsg[512] = {0};	// TCHAR�^�z��outtmsg.
	char msg[1024] = {0};		// char�^�z��msg.
	_tcscpy(tmsg, _T("I am Child!"));	// tmsg��"I am Parent!"���R�s�[.
	_stprintf(outtmsg, _T("Child: %s"), tmsg);	// �O��"Child: "�Ƃ���outtmsg��.
	_tperror(outtmsg);	// outtmsg���o��.
	DWORD len2 = WideCharToMultiByte(CP_ACP, 0, tmsg, -1, NULL, 0, NULL, NULL);	// �}���`�o�C�g�ɕϊ����邽�߂̃T�C�Y���擾.
	WideCharToMultiByte(CP_ACP, 0, tmsg, -1, msg, len, NULL, NULL);	// �}���`�o�C�g�ɕϊ�.
	fputs(msg, stdout);	// fputs�ŕW���o�͂ɏ�������.

	// �v���O�����̏I��
	return 0;

}