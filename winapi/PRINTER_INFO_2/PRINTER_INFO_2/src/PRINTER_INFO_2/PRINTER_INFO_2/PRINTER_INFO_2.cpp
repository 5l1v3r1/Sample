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
	PRINTER_DEFAULTS pd = {0};	// PRINTER_DEFAULTS�\����pd��{0}�ŏ�����.
	DWORD dwNeeded = 0;	// DWORD�^dwNeeded��0�ŏ�����.
	HGLOBAL hPrinterInfo2 = NULL;	// HGLOBAL�^hPrinterInfo2��NULL�ŏ�����.
	PRINTER_INFO_2 *pi2 = NULL;	// PRINTER_INFO_2�\���̃|�C���^pi2��NULL�ŏ�����.
	BOOL bRet = FALSE;	// BOOL�^bRet��FALSE�ŏ�����.
	TCHAR tszDMDeviceName[CCHDEVICENAME + 64] = {0};	// tszDMDeviceName��{0}�ŏ�����.(�T�C�Y��CCHDEVICENAME + 64.)

	// �o�b�t�@�T�C�Y���擾.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinter��NULL��n���ăo�b�t�@�T�C�Y���擾.

	// �o�b�t�@�̊m��.
	ptszBuf = new TCHAR[dwSize];	// �T�C�YdwSize���̃o�b�t�@�m��.

	// ����̃v�����^�����擾.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinter�Ńv�����^�����擾��, �o�b�t�@�Ɋi�[.

	// ����̃v�����^���̏o��.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBuf���o��.

	// �v�����^���J��.
	pd.DesiredAccess = PRINTER_ACCESS_USE;	// ���[�U����.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, &pd);	// OpenPrinter�Ńv�����^��ptszBuf�ƂȂ�v�����^���J��.(���̎�, pd��n��.)
	if (bOpen){	// �v�����^���J������.
		if (hPrinter != NULL){	// NULL�ł͂Ȃ�.
			_tprintf(_T("hPrinter = 0x%08x\n"), (unsigned long)hPrinter);	// hPrinter�̒l���o��.
			// �v�����^���(Level2)�̎擾.
			GetPrinter(hPrinter, 2, NULL, 0, &dwNeeded);	// �܂���GetPrinter��NULL��n����Level2�ŕK�v�ȃT�C�Y���擾.
			_tprintf(_T("dwNeeded = %lu\n"), dwNeeded);	// dwNeeded���o��.
			if (dwNeeded > 0){	// 0���傫��.
				// �������̊m��.
				hPrinterInfo2 = GlobalAlloc(GHND, dwNeeded);	// GlobalAlloc��dwNeeded���������m��.
				if (hPrinterInfo2 != NULL){	// �m�ې���.
					// �������̃��b�N.
					pi2 = (PRINTER_INFO_2 *)GlobalLock(hPrinterInfo2);	// GlobalLock�Ń��b�N���ă|�C���^���擾.
					if (pi2 != NULL){	// NULL�łȂ����.
						// �v�����^���̎擾.
						bRet = GetPrinter(hPrinter, 2, (LPBYTE)pi2, dwNeeded, &dwNeeded);	// GetPrinter��pi2���擾.
						if (bRet){	// TRUE�Ȃ�.
							if (pi2->pDevMode){	// DEVMODE�ւ̃|�C���^�������.
								// ���܂��܂ȏ����o��.
								_tprintf(_T("pi2->pDevMode->dmDeviceName = %s\n"), pi2->pDevMode->dmDeviceName);	// pi2->pDevMode->dmDeviceName���o��.
								_tprintf(_T("pi2->pPrinterName = %s\n"), pi2->pPrinterName);	// pi2->pPrinterName���o��.
								_tprintf(_T("pi2->pPortName = %s\n"), pi2->pPortName);	// pi2->pPortName���o��.
								_tprintf(_T("pi2->pDriverName = %s\n"), pi2->pDriverName);	// pi2->pDriverName���o��.
								_tprintf(_T("pi2->pPrintProcessor = %s\n"), pi2->pPrintProcessor);	// pi2->pPrintProcessor���o��.
								_tprintf(_T("pi2->pDatatype = %s\n"), pi2->pDatatype);	// pi2->pDatatype���o��.
							}
						}
						GlobalUnlock(hPrinterInfo2);	// �A�����b�N.
					}
					GlobalFree(hPrinterInfo2);	// ���.
				}
			}
			ClosePrinter(hPrinter);	// ClosePrinter��hPrinter�����.
		}
	}

	// �o�b�t�@�̉��.
	delete[] ptszBuf;	// ptszBuf�̉��.

	// �v���O�����̏I��.
	return 0;

}