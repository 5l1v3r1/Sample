// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <string.h>		// C�����񏈗�
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <commctrl.h>	// �R�����R���g���[��

// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�XID

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��̐錾
	HWND hWnd;			// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;			// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;		// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("SetClipboardData");			// �E�B���h�E�N���X����"SetClipboardData".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);		// ���j���[�ɂ�IDR_MAINMENU��MAKEINTRESOURCE�}�N���Ŏw��.
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("SetClipboardData"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("SetClipboardData"), _T("SetClipboardData"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"SetClipboardData"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL) {	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("SetClipboardData"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.

		// �E�B���h�E���b�Z�[�W����
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

	}

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg) {	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{
				
				// �ϐ��̐錾
				HWND hEdit;				// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit.
				LPCREATESTRUCT lpCS;	// CreateStruct�\���̂̃|�C���^lpCS.

				// �A�v���P�[�V�����C���X�^���X�n���h���̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����, lpCS�Ɋi�[.

				// �G�f�B�b�g�R���g���[���̍쐬.
				hEdit = CreateWindow(WC_EDIT, _T("Edit1"), WS_CHILD | WS_BORDER | WS_VISIBLE | ES_MULTILINE | ES_WANTRETURN, 50, 50, 250, 200, hwnd, (HMENU)ID_EDIT1, lpCS->hInstance, NULL);	// CreateWindow��WC_EDIT�ŃG�f�B�b�g�R���g���[��"Edit1"���쐬.
				if (hEdit == NULL){	// hEdit��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.(����ƃ��b�Z�[�W���[�v��GetMessage�̖߂�l��0�ɂȂ�̂�, ���b�Z�[�W���[�v���甲����.)

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.
		case WM_COMMAND:	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.(uMsg��WM_COMMAND�̎�.)

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃��j���[���ڂ��I�����ꂽ���𔻒肷��.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�őI�����ꂽ���j���[���ڂ�ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// �擾����ID���Ƃɏ����𕪊�.
					// Open���I�����ꂽ��.
					case ID_ITEM_OPEN:

						// ID_ITEM_OPEN�u���b�N
						{

							// �ϐ��̐錾
							HANDLE hFile;		// HANDLE�^�t�@�C���n���h��hFile
							BYTE btBuf[128];	// BYTE�^�z��btBuf(����128)
							DWORD dwReadBytes;	// DWORD�^�ǂݍ��񂾃o�C�g��dwReadBytes.
							HWND hEdit1;	// ID_EDIT1�̃n���h��hEdit1.
							int iLen;	// �o�b�t�@�ɕK�v�Ȓ���iLen.
							TCHAR *ptszBuf;	// TCHAR�o�b�t�@�|�C���^ptszBuf.

							// �t�@�C�����J��
							hFile = CreateFile(_T("test.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��"test.txt"���J����, �擾�����n���h����hFile�Ɋi�[.
							if (hFile != INVALID_HANDLE_VALUE){	// hFile��INVALID_HANDLE_VALUE�łȂ����.

								// �t�@�C���̓��e��ǂݍ���.
								ReadFile(hFile, btBuf, 128, &dwReadBytes, NULL);	// ReadFile��hFile�̓��e��btBuf�ɓǂݍ���.
								btBuf[dwReadBytes] = 0x0;	// ������'\0'( = 0x0)�Ŗ��߂�.

								// ����.
								CloseHandle(hFile);	// CloseHandle��hFile�����.

								// �}���`�o�C�g����������C�h������ɕϊ�.
								iLen = MultiByteToWideChar(CP_ACP, 0, (char *)btBuf, -1, NULL, 0);	// MultiByteToWideChar�ŕK�v�ȃo�b�t�@�̒��������߂�.
								ptszBuf = new TCHAR[iLen];	// ����iLen��TCHAR�o�b�t�@���m�ۂ�, ptszBuf�Ɋi�[.
								MultiByteToWideChar(CP_ACP, 0, (char *)btBuf, -1, ptszBuf, iLen);	// MultiByteToWideChar��btBuf��ptszBuf�ɕϊ�.
								
								// �G�f�B�b�g�R���g���[���ɃZ�b�g.
								hEdit1 = GetDlgItem(hwnd, ID_EDIT1);	// ID_EDIT1�̃n���h��hEdit1���擾.
								SetWindowText(hEdit1, ptszBuf);	// SetWindowText��hEdit1��ptszBuf���Z�b�g.							

								// ���������.
								delete [] ptszBuf;	// ptszBuf�����.

							}

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Save���I�����ꂽ��.
					case ID_ITEM_SAVE:

						// ID_ITEM_SAVE�u���b�N
						{

							// �ϐ��̐錾
							HWND hEdit1;	// ID_EDIT1�̃n���h��hEdit1.
							int iLen;	// �o�b�t�@�ɕK�v�Ȓ���iLen.
							TCHAR *ptszBuf;	// �擾������.
							int iBufLen;	// �o�b�t�@�̒���iBufLen.
							char *pszBuf;	// char�^�o�b�t�@�|�C���^pszBuf.
							HANDLE hFile;			// HANDLE�^�t�@�C���n���h��hFile
							DWORD dwWrittenBytes;	// DWORD�^�������񂾃o�C�g��dwWrittenBytes.

							// �G�f�B�b�g�R���g���[������擾.
							hEdit1 = GetDlgItem(hwnd, ID_EDIT1);	// ID_EDIT1�̃n���h��hEdit1���擾.
							iLen = GetWindowTextLength(hEdit1);	// ID_EDIT1�̃e�L�X�g�̒����𒲂ׂ�.
							ptszBuf = new TCHAR[iLen + 1];	// iLen + 1�̃o�b�t�@���m��.
							GetWindowText(hEdit1, ptszBuf, iLen + 1);	// ��������擾.
							ptszBuf[iLen] = _T('\0');	// �Ō��_T('\0')���i�[.

							// ���C�h�������}���`�o�C�g�����ɕϊ�����.
							iBufLen = WideCharToMultiByte(CP_ACP, 0, ptszBuf, -1, NULL, 0, NULL, NULL);	// �܂��͒������擾.
							pszBuf = new char[iBufLen];	// iBufLen��char�^�o�b�t�@���m��.
							WideCharToMultiByte(CP_ACP, 0, ptszBuf, -1, pszBuf, iBufLen, NULL, NULL);	// �ϊ�.

							// �t�@�C�����J��
							hFile = CreateFile(_T("test.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��"test.txt"�������݃��[�h(GENERIC_WRITE)�J����, �擾�����n���h����hFile�Ɋi�[.
							if (hFile != INVALID_HANDLE_VALUE){	// hFile��INVALID_HANDLE_VALUE�łȂ����.

								// �t�@�C���̓��e����������.
								WriteFile(hFile, pszBuf, iBufLen - 1, &dwWrittenBytes, NULL);	// WriteFile��hFile��pszBuf����������.

								// ����.
								CloseHandle(hFile);	// CloseHandle��hFile�����.

							}

							// �I������.
							delete [] ptszBuf;	// delete[]��ptszBuf�̉��
							delete [] pszBuf;	// delete[]��pszBuf�̉��.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Copy���I�����ꂽ��.
					case ID_ITEM_COPY:

						// ID_ITEM_COPY�u���b�N
						{

							// �ϐ��̐錾
							BOOL bOpen;	// �J�������ǂ����̌���bOpen.
							BOOL bEmpty;	// ��ɂł������ǂ����̌���bEmpty.
							HGLOBAL hGlobal;	// �O���[�o���n���h��hGlobal.
							PTSTR ptszText;	// PTSTR�^�e�L�X�g.
							HWND hEdit1;	// ID_EDIT1�̃n���h��hEdit1.
							int iLen;	// �e�L�X�g�̒���iLen.

							// �e�L�X�g���擾.
							hEdit1 = GetDlgItem(hwnd, ID_EDIT1);	// ID_EDIT1�̃n���h��hEdit1���擾.
							iLen = GetWindowTextLength(hEdit1);	// �e�L�X�g�̒������擾.
							ptszText = new TCHAR[iLen + 1];	// new�Ŋm��.
							GetWindowText(hEdit1, ptszText, iLen + 1);	// �e�L�X�g���擾.

							// ���C�h�������}���`�o�C�g�����ɕϊ�����.
							int iBufLen;	// �o�b�t�@�̒���.
							char *pszBuf;	// char�^�o�b�t�@�|�C���^pszBuf.
							iBufLen = WideCharToMultiByte(CP_ACP, 0, ptszText, -1, NULL, 0, NULL, NULL);	// �܂��͒������擾.
							pszBuf = new char[iBufLen];	// iBufLen��char�^�o�b�t�@���m��.
							WideCharToMultiByte(CP_ACP, 0,  ptszText, -1, pszBuf, iBufLen, NULL, NULL);	// �ϊ�.
							delete [] ptszText;	// �s�v�Ȃ̂ŉ��.

							// �O���[�o���������̊m��.
							PSTR pszGlobalBuf;
							hGlobal = GlobalAlloc(GHND | GMEM_SHARE, iBufLen);	// ����iBufLen�̃��������m��.
							pszGlobalBuf = (PSTR)GlobalLock(hGlobal);	// ���b�N����pszGlobalBuf�擾.
							strcpy(pszGlobalBuf, pszBuf);	// �R�s�[.
							GlobalUnlock(hGlobal);	// �A�����b�N.
							delete [] pszBuf;	// �s�v�Ȃ̂ŉ��.
							
							// �N���b�v�{�[�h���J��.
							bOpen = OpenClipboard(hwnd);	// OpenClipboard�ŃN���b�v�{�[�h���J��.
							if (bOpen){	// ����.
								bEmpty = EmptyClipboard();	// EmptyClipboard�ŃN���b�v�{�[�h����ɂ���.
								if (bEmpty){	// ����.
									SetClipboardData(CF_TEXT, hGlobal);	// SetClipboardData��hGlobal���e�L�X�g�Ƃ��ăN���b�v�{�[�h�ɃR�s�[.
								}
								CloseClipboard();	// CloseClipboard�ŃN���b�v�{�[�h�����.
							}

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Paste���I�����ꂽ��.
					case ID_ITEM_PASTE:

						// ID_ITEM_PASTE�u���b�N
						{

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// ��L�ȊO�̎�.
					default:

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

				}

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ��L�ȊO�̎�.
		default:	// ��L�ȊO�̒l�̎��̊��菈��.

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂�DefWindowProc�Ɋ���̏�����C����.

}