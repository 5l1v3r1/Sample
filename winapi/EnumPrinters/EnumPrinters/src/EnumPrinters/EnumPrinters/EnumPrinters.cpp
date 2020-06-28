// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	PRINTER_INFO_1 *pPrnInfo1 = NULL;	// �v�����^���PRINTER_INFO_1�̃|�C���^pPrnInfo1��NULL�ŏ�����.
	LPBYTE pPrnList = NULL;	// �v�����^���X�gpPrnList��NULL�ŏ�����.
	DWORD dwNeeded = 0;	// �K�v�ȃT�C�YdwNeeded��0�ŏ�����.
	DWORD dwReturned = 0;	// �Ԃ��Ă����T�C�YdwReturned��0�ŏ�����.
	DWORD dwIndex = 0;	// ���[�v�p�ϐ�dwIndex��0�ŏ�����.

	// �v�����^�����i�[����K�v�ȃT�C�Y���擾.
	EnumPrinters(PRINTER_ENUM_LOCAL, NULL, 1, NULL, 0, &dwNeeded, &dwReturned);	// EnumPrinters��NULL�Ȃǂ��w�肵�ĕK�v�T�C�Y���擾.

	// �K�v�ȃo�b�t�@���m��.
	pPrnList = (LPBYTE)LocalAlloc(LPTR, dwNeeded);	// LocalAlloc��dwNeeded�����������m��.

	// �v�����^�����擾.
	EnumPrinters(PRINTER_ENUM_LOCAL, NULL, 1, pPrnList, dwNeeded, &dwNeeded, &dwReturned);	// EnumPrinters�Ńv�����^�����擾.

	// �v�����^���X�g�|�C���^��PRINTER_INFO_1�|�C���^�ɃL���X�g.
	pPrnInfo1 = (PRINTER_INFO_1 *)pPrnList;	// pPrnInfo1�ɃL���X�g.

	// for���Ńv�����^�����o��.
	for (dwIndex = 0; dwIndex < dwReturned; dwIndex++){	// dwReturned�̕��J��Ԃ�.
		_tprintf(_T("pPrnInfo1->pName = %s\n"), pPrnInfo1->pName);	// pPrnInfo1->pName���o��.
		pPrnInfo1++;	// pPrnInfo1���C���N�������g.
	}

	// �o�b�t�@�̉��.
	LocalFree(pPrnList);	// LocalFree��pPrnList�����.

	// �v���O�����̏I��.
	return 0;

}