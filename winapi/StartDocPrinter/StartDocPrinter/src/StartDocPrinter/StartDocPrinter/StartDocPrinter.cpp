// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	DWORD dwSize = 0;	// �T�C�YdwSize��0�ŏ�����.
	TCHAR *ptszBuf = NULL;	// ������o�b�t�@�|�C���^ptszBuf��NULL�ŏ�����.
	BOOL bOpen = FALSE;	// BOOL�^��bOpen��FALSE�ŏ�����.
	HANDLE hPrinter = NULL;	// HANDLE�^hPrinter��NULL�ŏ�����.
	DOC_INFO_1 di1 = {0};	// DOC_INFO_1�\����di1��{0}�ŏ�����.
	DWORD dwJob = 0;	// DWORD�^dwJob��0�ŏ�����.

	// �o�b�t�@�T�C�Y���擾.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinter��NULL��n���ăo�b�t�@�T�C�Y���擾.

	// �o�b�t�@�̊m��.
	ptszBuf = new TCHAR[dwSize];	// �T�C�YdwSize���̃o�b�t�@�m��.

	// ����̃v�����^�����擾.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinter�Ńv�����^�����擾��, �o�b�t�@�Ɋi�[.

	// ����̃v�����^���̏o��.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBuf���o��.

	// �v�����^���J��.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, NULL);	// OpenPrinter�Ńv�����^��ptszBuf�ƂȂ�v�����^���J��.
	if (bOpen){	// �v�����^���J������.
		if (hPrinter != NULL){	// NULL�ł͂Ȃ�.
			_tprintf(_T("hPrinter = 0x%08x\n"), (unsigned long)hPrinter);	// hPrinter�̒l���o��.
			// di1�̐ݒ�.
			di1.pDocName = _T("StartDocPrinter");	// �h�L�������g����"StartDocPrinter".
			di1.pOutputFile = NULL;	// �o�̓t�@�C���͂ЂƂ܂�NULL.
			di1.pDatatype = _T("TEXT");	// "TEXT"���[�h�ɂ��Ă݂�.
			// �h�L�������g�̊J�n.
			dwJob = StartDocPrinter(hPrinter, 1, (LPBYTE)&di1);	// StartDocPrinter�Ńh�L�������g�J�n, dwJob���擾.
			if (dwJob > 0){	// 0���傫���Ȃ琬��.
				_tprintf(_T("dwJob = %lu\n"), dwJob);	// dwJob���o��.
				EndDocPrinter(hPrinter);	// �h�L�������g�̏I��.
			}
			ClosePrinter(hPrinter);	// ClosePrinter��hPrinter�����.
		}
	}

	// �o�b�t�@�̉��.
	delete[] ptszBuf;	// ptszBuf�̉��.

	// �v���O�����̏I��.
	return 0;

}