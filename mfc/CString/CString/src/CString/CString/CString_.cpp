// �w�b�_�t�@�C���̃C���N���[�h
#include <afxwin.h>	// MFC�W��
#include <tchar.h>	// TCHAR�^
#include <stdio.h>	// C�W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR* argv[]){	// main�֐���TCHAR��.

	// �I�u�W�F�N�g�̐錾�E������
	TCHAR tszInput[128];			// _tscanf�ɂ����͗p��TCHAR�^�z��tszInput.(����128)
	CString cstrInput;				// CString�̃I�u�W�F�N�gcstrInput
	CString cstrStr1;				// CString�̃I�u�W�F�N�gcstrStr1
	CString cstrStr2(_T("ABCDE"));	// CString�̃I�u�W�F�N�gcstrStr2���R���X�g���N�^��"ABCDE"�ɏ�����.
	CString cstrStr3 = _T("XYZ");	// CString�̃I�u�W�F�N�gcstrStr3��'='��"XYZ"�ɏ�����.

	// cstrStr1, cstrStr2, cstrStr3���o��.
	_tprintf(_T("cstrStr1 = %s\n"), cstrStr1);	// _tprintf��cstrStr1���o��.(���̂悤��C����̊֐���CString�̃I�u�W�F�N�g�����̂܂ܓn����̂�std::string�ɖ�������.)
	_tprintf(_T("cstrStr2 = %s\n"), cstrStr2);	// _tprintf��cstrStr2���o��.(���̂悤��C����̊֐���CString�̃I�u�W�F�N�g�����̂܂ܓn����̂�std::string�ɖ�������.)
	_tprintf(_T("cstrStr3 = %s\n"), cstrStr3);	// _tprintf��cstrStr2���o��.(���̂悤��C����̊֐���CString�̃I�u�W�F�N�g�����̂܂ܓn����̂�std::string�ɖ�������.)

	// cstrStr1�ւ̕�������.
	cstrStr1 = _T("ABC");	// cstrStr1�ɕ�����"ABC"����.

	// 1�s�󂯂�.
	_tprintf(_T("\n"));	// _tprintf��"\n"���o�͂��邱�Ƃ�1�s�󂯂�.

	// cstrStr1, cstrStr2, cstrStr3���o��.
	_tprintf(_T("cstrStr1 = %s\n"), cstrStr1);	// _tprintf��cstrStr1���o��.
	_tprintf(_T("cstrStr2 = %s\n"), cstrStr2);	// _tprintf��cstrStr2���o��.
	_tprintf(_T("cstrStr3 = %s\n"), cstrStr3);	// _tprintf��cstrStr2���o��.

	// cstrStr2�ւ�CString�I�u�W�F�N�g�̑��.
	cstrStr2 = cstrStr1;	// cstrStr2��cstrStr1����.

	// 1�s�󂯂�.
	_tprintf(_T("\n"));	// _tprintf��"\n"���o�͂��邱�Ƃ�1�s�󂯂�.

	// cstrStr1, cstrStr2, cstrStr3���o��.
	_tprintf(_T("cstrStr1 = %s\n"), cstrStr1);	// _tprintf��cstrStr1���o��.
	_tprintf(_T("cstrStr2 = %s\n"), cstrStr2);	// _tprintf��cstrStr2���o��.
	_tprintf(_T("cstrStr3 = %s\n"), cstrStr3);	// _tprintf��cstrStr2���o��.

	// cstrStr2��cstrStr3�̘A��.
	cstrStr2 = cstrStr2 + cstrStr3;	// cstrStr2�̕������cstrStr3�̕����񂪘A�������.

	// 1�s�󂯂�.
	_tprintf(_T("\n"));	// _tprintf��"\n"���o�͂��邱�Ƃ�1�s�󂯂�.

	// cstrStr1, cstrStr2, cstrStr3���o��.
	_tprintf(_T("cstrStr1 = %s\n"), cstrStr1);	// _tprintf��cstrStr1���o��.
	_tprintf(_T("cstrStr2 = %s\n"), cstrStr2);	// _tprintf��cstrStr2���o��.
	_tprintf(_T("cstrStr3 = %s\n"), cstrStr3);	// _tprintf��cstrStr2���o��.

	// 1�s�󂯂�.
	_tprintf(_T("\n"));	// _tprintf��"\n"���o�͂��邱�Ƃ�1�s�󂯂�.

	// cstrInput�ɕ���������.
	_tprintf(_T("cstrInput: "));	// cstrInput�̓��̓t�H�[��
	_tscanf(_T("%s"), tszInput);	// ��U, ���͂��ꂽ�������tszInput�Ɋi�[.
	cstrInput = tszInput;			// cstrInput��tszInput�̒��g���R�s�[.
	if (cstrInput == cstrStr2){	// cstrInput��cstrStr2������������̏ꍇ.
		_tprintf(_T("Match! cstrInput( = %s) == cstrStr2( = %s)\n"), cstrInput, cstrStr2);	// "Match!"�Əo�͂�, cstrInput��cstrStr2�̒��g���o��.
	}
	else{	// cstrInput��cstrStr2���Ⴄ������̏ꍇ.
		_tprintf(_T("cstrInput( = %s) != cstrStr2( = %s)\n"), cstrInput, cstrStr2);	// cstrInput��cstrStr2�̒��g���o��.
	}

	// �v���O�����̏I��
	return 0;

}