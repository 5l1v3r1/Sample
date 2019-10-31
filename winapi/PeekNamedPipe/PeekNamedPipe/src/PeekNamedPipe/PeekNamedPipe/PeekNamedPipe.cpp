// �w�b�_�t�@�C���̃C���N���[�h
#include <string>		// std::string
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̏�����
	SECURITY_ATTRIBUTES sa = {0};		// �Z�L�����e�B����sa��{0]�ŏ�����.
	BOOL bRetPipe = FALSE;				// �p�C�v��������bRetPipe��FALSE�ŏ�����.
	HANDLE hPipe[2] = {NULL, NULL};		// �z��hPipe��{NULL, NULL}�ŏ�����.
	STARTUPINFO si = {0};				// �X�^�[�g�A�b�v���si��{0}�ŏ�����.
	TCHAR tszCommandString[64] = {0};	// �����z��tszCommandString(����64)��{0}�ŏ�����.
	BOOL bRetProcess = FALSE;			// �v���Z�X��������bRetProcess��FALSE�ŏ�����.
	PROCESS_INFORMATION pi = {0};		// �v���Z�X���pi��{0}�ŏ�����.
	DWORD dwRetWait = 0;				// WaitForSingleObject�̖߂�ldwRetWait��0�ŏ�����.
	BOOL bExit = FALSE;					// ���[�v�𔲂��邩�ǂ����̔���bExit��FALSE�ŏ�����.
	BOOL bRetPeek = FALSE;				// �p�C�v�ɗ��܂��Ă���c�ʂ��擾�ł������ǂ�����\��bRetPeek��FALSE�ŏ�����.
	DWORD dwTotalLen = 0;				// �c��̍��v�T�C�YdwTotalLen��0�ŏ�����.
	BYTE btBuf[1024] = {0};				// �o�b�t�@btBuf(����1024)��{0}�ŏ�����.
	DWORD dwReadLen = 0;				// 1��̓ǂݍ��ݗ�dwReadLen��0�ŏ�����.
	std::string strResponse = "";		// �ǂݍ��ݕ�����strResponse��""�ŏ�����.
	BOOL bRead = FALSE;					// �ǂݍ��߂����ǂ����̔���bRead��FALSE�ŏ�����.

	// �Z�L�����e�B�����̐ݒ�.
	sa.nLength = sizeof(sa);		// �T�C�Y
	sa.bInheritHandle = TRUE;		// �p������.
	sa.lpSecurityDescriptor = NULL;	// NULL.

	// �p�C�v�̍쐬.
	bRetPipe = CreatePipe(&hPipe[0], &hPipe[1], &sa, 0);	// CreatePipe�Ńp�C�v�쐬.
	if (bRetPipe){	// ����.

		// �X�^�[�g�A�b�v���̃Z�b�g.
		si.cb = sizeof(STARTUPINFO);	// �T�C�Y.
		si.dwFlags = STARTF_USESTDHANDLES;	// �W�����o�̓n���h���Ɏw��̕����g��.
		si.hStdOutput = hPipe[1];	// �W���o�͂�hPipe[1]���Z�b�g.

		// �v���Z�X�𐶐�.
		_tcscpy(tszCommandString, _T("ping yahoo.co.jp"));	// �R�}���h���������������tszCommandString�ɃR�s�[.(yahoo.co.jp��ping��ł�.)
		bRetProcess = CreateProcess(NULL, tszCommandString, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);	// CreateProcess��"ping"�R�}���h���N��.
		if (bRetProcess){	// ����.

			// �X���b�h�n���h�������.
			if (pi.hThread != NULL){	// pi.hThread��NULL�łȂ���.
				CloseHandle(pi.hThread);	// pi.hThread�����.
				pi.hThread = NULL;	// pi.hThread��NULL���Z�b�g.
			}

			// �ǂݍ��݃��[�v.
			do{
				// �I���܂ő҂�.
				dwRetWait = WaitForSingleObject(pi.hProcess, INFINITE);	// WaitForSingleObject�ŃV�O�i����Ԃ܂ő҂�.
				if (dwRetWait == WAIT_OBJECT_0){	// �I��.

					// ������t���O�𗧂Ă�.
					bExit = TRUE;	// bExit��TRUE��.

				}

				// �p�C�v�ɗ��܂��Ă���c�ʂ��`�F�b�N.
				bRetPeek = PeekNamedPipe(hPipe[0], NULL, 0, NULL, &dwTotalLen, NULL);	// PeekNamedPipe�Ŏc�ʃ`�F�b�N.
				if (!bRetPeek){	// ���s

					// ������.
					break;	// break�Ŕ�����.

				}

				// ���v0�ȏ�.
				if (dwTotalLen > 0){	// dwTotalLen��0���傫��.

					// btBuf�̃N���A.
					ZeroMemory(btBuf, (sizeof(BYTE) * 1024));	// ZeroMemory��btBuf���N���A.

					// �p�C�v����ǂݍ���.
					bRead = ReadFile(hPipe[0], btBuf, (sizeof(BYTE) * 1024) - 1, &dwReadLen, NULL);	// ReadFile��hPipe[0]��ǂݍ���.
					if (!bRead){	// ���s

						// ������.
						break;	// break�Ŕ�����.

					}

					// �ǂݍ��߂���NULL�I�[.
					btBuf[dwReadLen] = '\0';	// dwReadLen�Ԗڂ�'\0'���Z�b�g.

					// �A��.
					strResponse += (char *)btBuf;	// strResponse��btBuf������.

					// ���v�ɖ����Ȃ��̂ő�����.
					if (dwReadLen < dwTotalLen){	// dwReadLen��dwTotalLen�ɖ����Ȃ�.
						bExit = FALSE;	// bExit��FALSE�ɂ���.
					}

				}

			} while (!bExit);
		}
		else{	// ���s.

			// "CreateProcess failed!"�ƕ\��.
			MessageBox(NULL, _T("CreateProcess failed!"), _T("PeekNamedPipe"), MB_OK);	// MessageBox��"CreateProcess failed!"��\��.

		}

		// �p�C�v�����.
		if (hPipe[1] != NULL){
			CloseHandle(hPipe[1]);	// hPipe[1]�����.
			hPipe[1] = NULL;	// hPipe[1]��NULL���Z�b�g.
		}
		if (hPipe[0] != NULL){
			CloseHandle(hPipe[0]);	// hPipe[0]�����.
			hPipe[0] = NULL;	// hPipe[0]��NULL���Z�b�g.
		}

		// �X���b�h�n���h�������.
		if (pi.hThread != NULL){
			CloseHandle(pi.hThread);	// pi.hThread�����.
			pi.hThread = NULL;	// pi.hThread��NULL���Z�b�g.
		}

		// �v���Z�X�n���h�������.
		if (pi.hProcess != NULL){
			CloseHandle(pi.hProcess);	// pi.hProcess�����.
			pi.hProcess = NULL;	// pi.hProcess��NULL���Z�b�g.
		}

		// strResponse�̕\��.
		MessageBoxA(NULL, strResponse.c_str(), "PeekNamedPipe", MB_OK);	// MessageBoxA��strResponse�̓��e��\��.

	}

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}