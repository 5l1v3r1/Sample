// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <shlwapi.h>	// �V�F��API

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	TCHAR tszModulePath[MAX_PATH] = {0};	// tszModulePath(����MAX_PATH)��{0}�ŏ�����.
	HANDLE hFile = NULL;	// HANDLE�^�t�@�C���n���h��hFile��NULL�ŏ�����.
	DWORD dwFileSize = 0;	// �t�@�C���T�C�YdwFileSize��0�ŏ�����.
	BYTE *pBytes = NULL;	// BYTE���I�z��|�C���^pBytes��NULL�ŏ�����.
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
	LONG lFlag = 0;	// LONG�^lFlag��0�ŏ�����.
	HGLOBAL hDevMode = NULL;	// HGLOBAL�^hDevMode��NULL�ŏ�����.
	DOC_INFO_1 di1 = {0};	// DOC_INFO_1�\����di1��{0}�ŏ�����.
	DWORD dwJob = 0;	// DWORD�^dwJob��0�ŏ�����.
	BOOL bPage = FALSE;	// BOOL�^��bPage��FALSE�ŏ�����.
	BOOL bWrite = FALSE;	// BOOL�^��bWrite��FALSE�ŏ�����.
	DWORD dwWritten = 0;	// DWORD�^��dwWritten��0�ŏ�����.

	// test_text.txt�̃p�X�𐶐�.
	GetModuleFileName(NULL, tszModulePath, MAX_PATH);	// GetModuleFileName�ł��̎��s�t�@�C���̃t���p�X���擾.
	PathRemoveFileSpec(tszModulePath);	// PathRemoveFileSpec�Ńt�@�C�����̕�������菜��.
	_tcscat(tszModulePath, _T("\\test_text.txt"));	// _tcscat��"\test_text.txt"��A��.
	_tprintf(_T("tszModulePath = %s\n"), tszModulePath);	// tszModulePath���o��.

	// test_text.txt�̓ǂݍ���.
	hFile = CreateFile(tszModulePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��tszModulePath���J����, �擾�����n���h����hFile�Ɋi�[.
	if (hFile == INVALID_HANDLE_VALUE){	// hFile��INVALID_HANDLE_VALUE�Ȃ�.
		_tprintf(_T("test_text.txt not found.\n"));	// "test_text.txt not found."���o��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}
	dwFileSize = GetFileSize(hFile, NULL);	// GetFileSize��"test_text.txt"�̃t�@�C���T�C�Y���擾����.
	_tprintf(_T("dwFileSize = %lu\n"), dwFileSize);	// dwFileSize�̏o��.
	pBytes = new BYTE[dwFileSize];	// BYTE�z����m��.
	ReadFile(hFile, pBytes, dwFileSize, &dwFileSize, NULL);	// ReadFile��hFile�̓��e��pBytes�ɓǂݍ���.
	CloseHandle(hFile);	// CloseHandle��hFile�����.

	// �o�b�t�@�T�C�Y���擾.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinter��NULL��n���ăo�b�t�@�T�C�Y���擾.

	// �o�b�t�@�̊m��.
	ptszBuf = new TCHAR[dwSize];	// �T�C�YdwSize���̃o�b�t�@�m��.

	// ����̃v�����^�����擾.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinter�Ńv�����^�����擾��, �o�b�t�@�Ɋi�[.

	// ����̃v�����^���̏o��.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBuf���o��.

	// �ݒ�ύX.
	// �v�����^���J��.
	//pd.DesiredAccess = PRINTER_ACCESS_USE;	// ���[�U����.
	pd.DesiredAccess = PRINTER_ALL_ACCESS;	// �S�Ă̌���.
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
							if (pi2->pDevMode != NULL){	// DEVMODE�ւ̃|�C���^�������.
								_tprintf(_T("GetPrinter Get OK!\n"));	// "GetPrinter Get OK!"�Əo��.
								// ���܂��܂ȏ����o��.
								_tprintf(_T("pi2->pDevMode->dmDeviceName = %s\n"), pi2->pDevMode->dmDeviceName);	// pi2->pDevMode->dmDeviceName���o��.
								_tprintf(_T("pi2->pPrinterName = %s\n"), pi2->pPrinterName);	// pi2->pPrinterName���o��.
								_tprintf(_T("pi2->pPortName = %s\n"), pi2->pPortName);	// pi2->pPortName���o��.
								_tprintf(_T("pi2->pDriverName = %s\n"), pi2->pDriverName);	// pi2->pDriverName���o��.
								_tprintf(_T("pi2->pPrintProcessor = %s\n"), pi2->pPrintProcessor);	// pi2->pPrintProcessor���o��.
								_tprintf(_T("pi2->pDatatype = %s\n"), pi2->pDatatype);	// pi2->pDatatype���o��.
								// ������������ɂ���.
								pi2->pDevMode->dmFields = DM_ORIENTATION;	// ������ݒ�.
								pi2->pDevMode->dmOrientation = DMORIENT_LANDSCAPE;	// ���ɐݒ�.
								lFlag = DocumentProperties(NULL, hPrinter, ptszBuf, pi2->pDevMode, pi2->pDevMode, DM_IN_BUFFER | DM_OUT_BUFFER);	// DocumentProperties�Ńf�o�C�X�ˑ������̃A�b�v�f�[�g.
								if (lFlag == IDOK){	// IDOK�Ȃ�.
									_tprintf(_T("DocumentProperties Update OK!\n"));	// "DocumentProperties Update OK!"�Əo��.
									lFlag = SetPrinter(hPrinter, 2, (LPBYTE)pi2, 0);	// SetPrinter�ōX�V�����ݒ���v�����^�ɔ��f.
									if (lFlag > 0){	// 0�ȏ�.
										_tprintf(_T("SetPrinter OK!\n"));	// "SetPrinter OK!"���o��.
									}
									else{	// ���̒l.
										DWORD e = GetLastError();	// GetLstError�ŃG���[�ԍ��擾.
										_tprintf(_T("SetPrinter NG! e = %lu\n"), e);	// "SetPrinter NG!"�ƃG���[�ԍ����o��.
									}
								}
							}
							else{	// DEVMODE�̃|�C���^��NULL�̎�.
								_tprintf(_T("pi2->pDevMode == NULL!\n"));	// NULL�ł��邱�Ƃ��o��.
								// DocumentProperties�Ŏ擾������@.
								dwNeeded = DocumentProperties(NULL, hPrinter, ptszBuf, NULL, NULL, 0);	// �܂��T�C�Y���擾.
								if (dwNeeded > 0){	// 0���傫��.
									hDevMode = GlobalAlloc(GHND, dwNeeded);	// dwNeeded���̃������m��.
									if (hDevMode != NULL){	// NULL�łȂ���.
										pi2->pDevMode = (DEVMODE *)GlobalLock(hDevMode);	// pi2->pDevMode�Ƀ��b�N�����������̃|�C���^���i�[.
										if (pi2->pDevMode != NULL){	// NULL�łȂ�.
											lFlag = DocumentProperties(NULL, hPrinter, ptszBuf, pi2->pDevMode, NULL, DM_OUT_BUFFER);	// DocumentProperties��DEVMODE���擾.
											if (lFlag == IDOK){	// IDOK�Ȃ�.
												_tprintf(_T("DocumentProperties Get OK!\n"));	// "DocumentProperties Get OK!"�Əo��.
												// ������������ɂ���.
												pi2->pDevMode->dmFields = DM_ORIENTATION;	// ������ݒ�.
												pi2->pDevMode->dmOrientation = DMORIENT_LANDSCAPE;	// ���ɐݒ�.
												lFlag = DocumentProperties(NULL, hPrinter, ptszBuf, pi2->pDevMode, pi2->pDevMode, DM_IN_BUFFER | DM_OUT_BUFFER);	// DocumentProperties�Ńf�o�C�X�ˑ������̃A�b�v�f�[�g.
												if (lFlag == IDOK){	// IDOK�Ȃ�.
													_tprintf(_T("DocumentProperties Update OK!\n"));	// "DocumentProperties Update OK!"�Əo��.
													lFlag = SetPrinter(hPrinter, 2, (LPBYTE)pi2, 0);	// SetPrinter�ōX�V�����ݒ���v�����^�ɔ��f.
													if (lFlag > 0){	// 0���傫��.
														_tprintf(_T("SetPrinter OK!\n"));	// "SetPrinter OK!"���o��.
													}
													else{	// ���̒l.
														DWORD e = GetLastError();	// GetLstError�ŃG���[�ԍ��擾.
														_tprintf(_T("SetPrinter NG! e = %lu\n"), e);	// "SetPrinter NG!"�ƃG���[�ԍ����o��.
													}
												}
											}
											GlobalUnlock(hDevMode);	// �A�����b�N.
										}
										GlobalFree(hDevMode);	// ���.
									}
								}
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

	// ���.
	// �v�����^���J��.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, NULL);	// OpenPrinter�Ńv�����^��ptszBuf�ƂȂ�v�����^���J��.
	if (bOpen){	// �v�����^���J������.
		if (hPrinter != NULL){	// NULL�ł͂Ȃ�.
			_tprintf(_T("hPrinter = 0x%08x\n"), (unsigned long)hPrinter);	// hPrinter�̒l���o��.
			// di1�̐ݒ�.
			di1.pDocName = _T("StartPagePrinter");	// �h�L�������g����"StartPagePrinter".
			di1.pOutputFile = NULL;	// �o�̓t�@�C���͂ЂƂ܂�NULL.
			di1.pDatatype = _T("TEXT");	// "TEXT"���[�h�ɂ��Ă݂�.
			// �h�L�������g�̊J�n.
			dwJob = StartDocPrinter(hPrinter, 1, (LPBYTE)&di1);	// StartDocPrinter�Ńh�L�������g�J�n, dwJob���擾.
			if (dwJob > 0){	// 0���傫���Ȃ琬��.
				_tprintf(_T("dwJob = %lu\n"), dwJob);	// dwJob���o��.
				// �y�[�W�̊J�n.
				bPage = StartPagePrinter(hPrinter);	// StartPagePrinter�Ńy�[�W�̊J�n.
				if (bPage){	// TRUE�Ȃ琬��.
					bWrite = WritePrinter(hPrinter, pBytes, dwFileSize, &dwWritten);	// WritePrinter�ŏ�������.
					if (bWrite){	// TRUE�Ȃ琬��.
						_tprintf(_T("dwFileSize = %lu\n"), dwFileSize);	// dwFileSize���o��.
						_tprintf(_T("dwWritten = %lu\n"), dwWritten);	// dwWritten���o��.
					}
					EndPagePrinter(hPrinter);	// EndPagePrinter�Ńy�[�W�̏I��.
				}
				EndDocPrinter(hPrinter);	// �h�L�������g�̏I��.
			}
			ClosePrinter(hPrinter);	// ClosePrinter��hPrinter�����.
		}
	}

	// �o�b�t�@�̉��.
	delete[] ptszBuf;	// ptszBuf�̉��.
	delete[] pBytes;	// pBytes�����.

	// �v���O�����̏I��.
	return 0;

}