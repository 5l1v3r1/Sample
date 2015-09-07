// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HANDLE hFile;	// HANDLE�^�t�@�C���n���h��hFile
	DWORD dwSize;	// DWORD�^�t�@�C���T�C�YdwSize

	// �t�@�C�����J��
	hFile = CreateFile(_T("test.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��"test.txt"���J����, �擾�����n���h����hFile�Ɋi�[.
	if (hFile == INVALID_HANDLE_VALUE){	// hFile��INVALID_HANDLE_VALUE�Ȃ�.

		// �G���[����
		_tprintf(_T("CreateFile Error!\n"));	// _tprintf��"CreateFile Error!"�Əo��.
		return -1;	// -1��Ԃ�.

	}

	// �t�@�C���T�C�Y�̎擾.
	dwSize = GetFileSize(hFile, NULL);	// GetFileSize��"test.txt"�̃t�@�C���T�C�Y���擾����.

	// �t�@�C���T�C�Y�̏o��.
	_tprintf(_T("dwSize = %lu\n"), dwSize);	// _tprintf��dwSize���o��.

	// ����.
	CloseHandle(hFile);	// CloseHandle��hFile�����.

	// �v���O�����̏I��.
	return 0;

}