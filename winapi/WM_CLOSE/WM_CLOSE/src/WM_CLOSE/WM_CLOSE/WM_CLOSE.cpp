// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <commctrl.h>	// �R�����R���g���[��

// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�XID

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("WM_CLOSE");							// �E�B���h�E�N���X����"WM_CLOSE".
	wc.style = CS_HREDRAW | CS_VREDRAW;								// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;									// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;										// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(hInstance, NULL);							// �A�C�R����NULL.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);						// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);			// �w�i�͔��u���V.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);				// ���j���[�ɂ�IDR_MAINMENU��MAKEINTRESOURCE�}�N���Ŏw��.
	wc.cbClsExtra = 0;												// 0�ł���.
	wc.cbWndExtra = 0;												// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("WM_CLOSE"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("WM_CLOSE"), _T("WM_CLOSE"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"WM_CLOSE"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("WM_CLOSE"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.

		// �E�B���h�E���b�Z�[�W�̑��o
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

	}

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// WindowProc�֐��̒�`
inline LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾
				HWND hButton;			// �{�^���̃E�B���h�E�n���h��hButton.
				LPCREATESTRUCT lpCS;	// CreateStruct�\���̂̃|�C���^lpCS.

				// �A�v���P�[�V�����C���X�^���X�n���h���̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����, lpCS�Ɋi�[.

				// �{�^���̍쐬.
				hButton = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE, 50, 50, 100, 100, hwnd, (HMENU)ID_BUTTON1, lpCS->hInstance, NULL);	// CreateWindow��WC_BUTTON�Ń{�^��"Button1"���쐬.
				if (hButton == NULL){	// hButton��NULL�Ȃ�.

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

			// �E�B���h�E���j�����ꂽ���̃f�o�b�O���O.
			OutputDebugString(_T("WM_DESTROY\n"));	// "WM_DESTROY"�Əo��.

			// �I�����b�Z�[�W�̑��M.
			PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.(����ƃ��b�Z�[�W���[�v��GetMessage�̖߂�l��0�ɂȂ�̂�, ���b�Z�[�W���[�v���甲����.)

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E������ꂽ��.
		case WM_CLOSE:	// �E�B���h�E������ꂽ��.(uMsg��WM_CLOSE�̎�.)

			// WM_CLOSE�u���b�N
			{

				// �E�B���h�E����邩�ǂ������b�Z�[�W�{�b�N�X�Ŋm�F.
				int iRet = MessageBox(hwnd, _T("Close?"), _T("WM_CLOSE"), MB_ICONQUESTION | MB_OKCANCEL);	// MessageBox��"Close?"��\����, MB_OKCANCEL�̌��ʂ�iRet�Ɋi�[.
				if (iRet != IDOK){	// IDOK�ł͂Ȃ�.

					// 0��Ԃ��ăE�B���h�E��j�����Ȃ�.
					return 0;	// 0��Ԃ�.

				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵��, �R�}���h������������.
		case WM_COMMAND:	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵��, �R�}���h������������.(uMsg��WM_COMMAND�̎�.)

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃��j���[����, �܂��̓R���g���[�����I�����ꂽ���𔻒肷��.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�őI�����ꂽ���j���[����, �܂��̓R���g���[����ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// �擾����ID���Ƃɏ����𕪊�.
					// Item1-1���I�����ꂽ��.
					case ID_ITEM_1_1:

						// ID_ITEM_1_1�u���b�N
						{

							// ���j���[�A�C�e�����I�����ꂽ���̃f�o�b�O���O.(before)
							OutputDebugString(_T("ID_ITEM_1_1 before\n"));	// "ID_ITEM_1_1 before"�Əo��.

							// �E�B���h�E�����悤�ɖ��߂���.
							SendMessage(hwnd, WM_CLOSE, 0, 0);	// SendMessage��WM_CLOSE�𑗐M.

							// ���j���[�A�C�e�����I�����ꂽ���̃f�o�b�O���O.(after)
							OutputDebugString(_T("ID_ITEM_1_1 after\n"));	// "ID_ITEM_1_1 after"�Əo��.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Button1�������ꂽ��.
					case ID_BUTTON1:

						// ID_BUTTON1�u���b�N
						{

							// �{�^���������ꂽ���̃f�o�b�O���O.(before)
							OutputDebugString(_T("ID_BUTTON1 before\n"));	// "ID_BUTTON1 before"�Əo��.

							// �E�B���h�E�����悤�ɖ��߂���.
							SendMessage(hwnd, WM_CLOSE, 0, 0);	// SendMessage��WM_CLOSE�𑗐M.

							// �{�^���������ꂽ���̃f�o�b�O���O.(after)
							OutputDebugString(_T("ID_BUTTON1 after\n"));	// "ID_BUTTON1 after"�Əo��.

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