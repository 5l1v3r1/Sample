// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	DWORD dwSize = 0;	// �T�C�YdwSize��0�ŏ�����.
	TCHAR *ptszBuf = NULL;	// ������o�b�t�@�|�C���^ptszBuf��NULL�ŏ�����.

	// �o�b�t�@�T�C�Y���擾.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinter��NULL��n���ăo�b�t�@�T�C�Y���擾.

	// �o�b�t�@�̊m��.
	ptszBuf = new TCHAR[dwSize];	// �T�C�YdwSize���̃o�b�t�@�m��.

	// ����̃v�����^�����擾.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinter�Ńv�����^�����擾��, �o�b�t�@�Ɋi�[.

	// ����̃v�����^���̏o��.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBuf���o��.

	// �o�b�t�@�̉��.
	delete[] ptszBuf;	// ptszBuf�̉��.

	// �v���O�����̏I��.
	return 0;

}