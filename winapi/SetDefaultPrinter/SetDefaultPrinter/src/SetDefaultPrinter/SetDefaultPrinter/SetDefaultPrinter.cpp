// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	DWORD dwSize = 0;	// �T�C�YdwSize��0�ŏ�����.
	TCHAR *ptszBuf = NULL;	// ������o�b�t�@�|�C���^ptszBuf��NULL�ŏ�����.
	TCHAR tszNew[256] = {0};	// TCHAR�z��(����256)tszNew��{0}�ŏ�����.

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
	ptszBuf = NULL;	// NULL���Z�b�g.

	// ���̓t�H�[���̏o��.
	_tprintf(_T("New Default Printer: "));	// �V��������̃v�����^�̓��̓t�H�[���̏o��.

	// ���͂̎�t.
	_fgetts(tszNew, 256, stdin);	// ���͕������tszNew�Ɋi�[.

	// ���s�̏���.
	tszNew[_tcslen(tszNew) - 1] = _T('\0');	// ������NULL�������Z�b�g.

	// ����̃v�����^�ɃZ�b�g.
	SetDefaultPrinter(tszNew);	// SetDefaultPrinter��tszNew������̃v�����^�ɃZ�b�g.

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
	ptszBuf = NULL;	// NULL���Z�b�g.

	// �v���O�����̏I��.
	return 0;

}