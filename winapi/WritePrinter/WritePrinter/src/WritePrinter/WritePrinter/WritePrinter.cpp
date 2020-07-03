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

	// �v�����^���J��.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, NULL);	// OpenPrinter�Ńv�����^��ptszBuf�ƂȂ�v�����^���J��.
	if (bOpen){	// �v�����^���J������.
		if (hPrinter != NULL){	// NULL�ł͂Ȃ�.
			_tprintf(_T("hPrinter = 0x%08x\n"), (unsigned long)hPrinter);	// hPrinter�̒l���o��.
			// di1�̐ݒ�.
			di1.pDocName = _T("WritePrinter");	// �h�L�������g����"WritePrinter".
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