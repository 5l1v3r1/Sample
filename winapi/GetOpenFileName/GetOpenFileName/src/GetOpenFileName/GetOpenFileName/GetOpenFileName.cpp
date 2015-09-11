// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�XID

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;			// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;			// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;		// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("GetOpenFileName");				// �E�B���h�E�N���X����"GetOpenFileName".
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
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetOpenFileName"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("GetOpenFileName"), _T("GetOpenFileName"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"GetOpenFileName"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetOpenFileName"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.

		// �E�B���h�E���b�Z�[�W�̑��o
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.

	}

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)
		
			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾�E������
				LPCREATESTRUCT lpcs;	// CreateStruct�\���̂̃|�C���^lpcs.
				HINSTANCE hInstance;	// HINSTANCE�^hInstance.
				HWND hEdit = NULL;	// �G�f�B�b�g�{�b�N�X�̃E�B���h�E�n���h��hEdit.

				// CreateStruct�\���̂̃|�C���^�擾.
				lpcs = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����, lpcs�Ɋi�[.

				// hInstance�̎擾.
				hInstance = lpcs->hInstance;	// lpcs����hInstance���擾.

				// �G�f�B�b�g�{�b�N�X�̎q�E�B���h�E�쐬.
				hEdit = CreateWindow(_T("EDIT"), _T(""), WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN, 0, 0, 640, 480, hwnd, (HMENU)ID_EDIT1, hInstance, NULL);	// CreateWindow�ŃG�f�B�b�g�{�b�N�X�𐶐�.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// ���b�Z�[�W���[�v�𔲂���.
				PostQuitMessage(0);	// PostQuitMessage�Ŕ�����.

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
					case ID_FILE_OPEN:

						// ID_FILE_OPEN�u���b�N
						{

							// �ϐ��̐錾�E������.
							OPENFILENAME ofn = {0};	// OPENFILENAME�\���̕ϐ�ofn��0�ŏ�����.
							TCHAR tszFilePath[260] = {0};	// �t�@�C���p�X���i�[����TCHAR�^�z��(����260)��0�ŏ�����.
							HANDLE hFile = NULL;	// �t�@�C���n���h��hFile��NULL�ɏ�����.
							DWORD dwSize;	// DWORD�^�t�@�C���T�C�YdwSize
							LPBYTE lpBytes;	// �e�L�X�g�t�@�C���̓��e���i�[����BYTE�^�������ւ̃|�C���^lpBytes.
							HWND hEdit;	// �G�f�B�b�g�{�b�N�X�̃E�B���h�E�n���h��hEdit.

							// ofn�ɒl���Z�b�g.
							ofn.lStructSize = sizeof(OPENFILENAME);	// �\���̂̃T�C�Y.
							ofn.hwndOwner = hwnd;	// �I�[�i�[�E�B���h�E.
							ofn.lpstrFilter = _T("Text Files(*.txt)\0*.txt\0\0");	// �t�B���^(�w�肵���p�^�[���̃t�@�C������������.)
							ofn.lpstrFile = tszFilePath;	// �t�@�C���p�X.
							ofn.nMaxFile = 260;	// �t�@�C���p�X�̍ő咷.
							ofn.Flags = OFN_FILEMUSTEXIST;	// �t�@�C�������݂��Ȃ�������x���\��.

							// �t�@�C���I��.
							if (!GetOpenFileName(&ofn)){	// GetOpenFileName�Ńt�@�C����I��.

								// �I�����Ȃ������ꍇ.(�L�����Z��)
								return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.


							}

							// �t�@�C���̊J��.
							hFile = CreateFile(tszFilePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile�őI�������t�@�C�����J����, �擾�����n���h����hFile�Ɋi�[.
							if (hFile == INVALID_HANDLE_VALUE){	// hFile��INVALID_HANDLE_VALUE�Ȃ�.

								// �G���[����
								MessageBox(NULL, _T("Error!\n"), _T("GetOpenFileName"), MB_ICONHAND);	// MessageBox�ŃG���[���b�Z�[�W.
								return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

							}

							// �t�@�C���T�C�Y�̎擾.
							dwSize = GetFileSize(hFile, NULL);	// GetFileSize�Ńt�@�C���T�C�Y���擾����.

							// �������̊m��.
							lpBytes = new BYTE[dwSize + 1];	// dwSize + 1���������m��.

							// �t�@�C���̓ǂݍ���.
							ReadFile(hFile, lpBytes, dwSize, &dwSize, NULL);	// ReadFile�œǂݍ���.
							lpBytes[dwSize] = '\0';	// dwSize�Ԗ�(��ԍŌ�)��'\0'�Ŗ��߂�.

							// �G�f�B�b�g�{�b�N�X�̃n���h���擾.
							hEdit = GetDlgItem(hwnd, ID_EDIT1);	// GetDlgItem��ID_EDIT1�̃n���h���擾.

							// �G�f�B�b�g�{�b�N�X�ɃZ�b�g.
							SetWindowTextA(hEdit, (LPCSTR)lpBytes);	// SetWindowTextA(SetWindowText��ASCII(ShiftJIS)��)�ŃG�f�B�b�g�{�b�N�X�ɓǂݍ��񂾃e�L�X�g���Z�b�g.

							// ���������.
							delete [] lpBytes;	// delete�Ń��������.

							// �t�@�C�������.
							CloseHandle(hFile);	// CloseHandle�Ńt�@�C�������.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

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

		// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
		case WM_SIZE:	// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.(uMsg��WM_SIZE�̎�.)

			// WM_SIZE�u���b�N
			{
				
				// �ϐ��̐錾
				int width;	// �N���C�A���g�̈�̕�.
				int height;	// �N���C�A���g�̈�̍���.
				HWND hEdit;	// �G�f�B�b�g�{�b�N�X�̃E�B���h�E�n���h��.

				// �N���C�A���g�̈�̕ύX��̃T�C�Y���擾.
				width = LOWORD(lParam);		// LOWORD(lParam)�ŃN���C�A���g�̈�̕����擾.
				height = HIWORD(lParam);	// HIWORD(lParam)�ŃN���C�A���g�̈�̍������擾.

				// �G�f�B�b�g�{�b�N�X�̃T�C�Y����.
				hEdit = GetDlgItem(hwnd, ID_EDIT1);	// GetDlgItem��ID_EDIT1�̃E�B���h�E�n���h���擾.
				MoveWindow(hEdit, 0, 0, width, height, TRUE);	// MoveWindow�ŃN���C�A���g�̈��t�ɃG�f�B�b�g�{�b�N�X���L����.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ����ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}