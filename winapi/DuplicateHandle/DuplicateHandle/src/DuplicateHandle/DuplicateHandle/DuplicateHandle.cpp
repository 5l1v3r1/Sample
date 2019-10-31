// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̏�����
	HANDLE hFile = NULL;				// �t�@�C���n���h��hFile��NULL�ŏ�����.
	TCHAR tszHFile[64] = {0};			// �����z��tszHFile(����64)��{0}�ŏ�����.
	HANDLE hStdOut = NULL;				// �W���o�̓n���h��hStdOut��NULL�ŏ�����.
	TCHAR tszHStdOut[64] = {0};			// �����z��tszHStdOut(����64)��{0}�ŏ�����.
	STARTUPINFO si = {0};				// �X�^�[�g�A�b�v���si��{0}�ŏ�����.
	TCHAR tszCommandString[64] = {0};	// �����z��tszCommandString(����64)��{0}�ŏ�����.
	BOOL bRet = FALSE;					// �v���Z�X��������bRet��FALSE�ŏ�����.
	PROCESS_INFORMATION pi = {0};		// �v���Z�X���pi��{0}�ŏ�����.
	DWORD dwRet = 0;					// �v���Z�X�̑ҋ@���dwRet��0�ŏ�����.

	// "ping"�R�}���h�̏o�͂��L�^����"ping.log"���쐬.
	hFile = CreateFile(_T("ping.log"), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// "ping.log"���쐬.
	if (hFile != INVALID_HANDLE_VALUE){	// ����.

		// hFile�𕶎���ɕϊ�.
		_stprintf(tszHFile, _T("hFile = 0x%08x"), (unsigned int)hFile);	// _stprintf��hFile��tszHFile�ɕϊ�.

		// hFile��\��.
		MessageBox(NULL, tszHFile, _T("DuplicateHandle"), MB_OK);	// MessageBox��tszHFile��\��.

		// �n���h���̕���(���݂̃v���Z�X�͓x�X�擾������������.)
		DuplicateHandle(GetCurrentProcess(), hFile, GetCurrentProcess(), &hStdOut, 0, TRUE, DUPLICATE_SAME_ACCESS);	// DuplicateHandle��hFile�Ɠ����t�@�C�����w��hStdOut���擾.
		if (hStdOut != INVALID_HANDLE_VALUE){	// ����.

			// hStdOut�𕶎���ɕϊ�.
			_stprintf(tszHStdOut, _T("hStdOut = 0x%08x"), (unsigned int)hStdOut);	// _stprintf��hStdOut��tszHStdOut�ɕϊ�.

			// hStdOut��\��.
			MessageBox(NULL, tszHStdOut, _T("DuplicateHandle"), MB_OK);	// MessageBox��tszHStdOut��\��.

			// �X�^�[�g�A�b�v���̃Z�b�g.
			si.cb = sizeof(STARTUPINFO);	// �T�C�Y.
			si.dwFlags = STARTF_USESTDHANDLES;	// �W�����o�̓n���h���Ɏw��̕����g��.
			si.hStdOutput = hStdOut;	// �W���o�͂�hStdOut.

			// �v���Z�X�𐶐�.
			_tcscpy(tszCommandString, _T("ping yahoo.co.jp"));	// �R�}���h���������������tszCommandString�ɃR�s�[.(yahoo.co.jp��ping��ł�.)
			bRet = CreateProcess(NULL, tszCommandString, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);	// CreateProcess��"ping"�R�}���h���N��.
			if (bRet){	// ����.

				// �X���b�h�n���h�������.
				if (pi.hThread != NULL) {	// pi.hThread��NULL�łȂ���.
					CloseHandle(pi.hThread);	// pi.hThread�����.
					pi.hThread = NULL;	// pi.hThread��NULL���Z�b�g.
				}

				// �I���܂ő҂�.
				dwRet = WaitForSingleObject(pi.hProcess, INFINITE);	// WaitForSingleObject�ŃV�O�i����Ԃ܂ő҂�.
				if (dwRet == WAIT_OBJECT_0){	// �I��.

					// "CreateProcess Finish!"�ƕ\��.
					MessageBox(NULL, _T("CreateProcess Finish!"), _T("DuplicateHandle"), MB_OK);	// MessageBox��"CreateProcess Finish!"��\��.

				}

			}
			else{	// ���s.

				// "CreateProcess failed!"�ƕ\��.
				MessageBox(NULL, _T("CreateProcess failed!"), _T("DuplicateHandle"), MB_OK);	// MessageBox��"CreateProcess failed!"��\��.

			}

			// ���������W���o�̓n���h�������.
			CloseHandle(hStdOut);	// hStdOut�����.

		}

		// "ping.log"�����.
		CloseHandle(hFile);	// hFile�����.

		// �X���b�h�n���h�������.
		if (pi.hThread != NULL){	// pi.hThread��NULL�łȂ���.
			CloseHandle(pi.hThread);	// pi.hThread�����.
			pi.hThread = NULL;	// pi.hThread��NULL���Z�b�g.
		}

		// �v���Z�X�n���h�������.
		if (pi.dwProcessId != NULL){	// pi.hProcess��NULL�łȂ���.
			CloseHandle(pi.hProcess);	// pi.hProcess�����.
			pi.hProcess = NULL;	// pi.hProcess��NULL���Z�b�g.
		}

	}

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}