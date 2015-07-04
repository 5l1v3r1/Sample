// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�XID

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �_�C�A���O�̏���������R�[���o�b�N�֐�DialogProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.
	TCHAR tszWindowName[256];	// �E�B���h�E�����i�[����TCHAR�^�z��tszWindowName.(����256)
	HDC hDC = NULL;				// ���̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC��NULL�ɏ�����.
	HACCEL hAccel = NULL;		// �A�N�Z�����[�^�e�[�u���̃n���h�����i�[����HAACEL�^�ϐ�hAccel��NULL�ɏ�����.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("GetWindowText");						// �E�B���h�E�N���X����"GetWindowText".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;									// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));	// �A�C�R���ɂ͍쐬�����A�C�R��"icon1.ico"(MAKEINTRESOURCE(IDI_ICON1))��LoadIcon�Ń��[�h���Ďg��.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// �w�i�͔��u���V.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);			// ���j���[�ɂ�IDR_MAINMENU��MAKEINTRESOURCE�}�N���Ŏw��.
	wc.cbClsExtra = 0;											// 0�ł���.
	wc.cbWndExtra = 0;											// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetWindowText"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �����񃊃\�[�X�̃��[�h
	LoadString(hInstance, IDS_WINDOW_NAME, tszWindowName, 256);	// LoadString��STRINGTABLE����IDS_WINDOW_NAME�ɂ����镶��������[�h��, tszWindowName�Ɋi�[.

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("GetWindowText"), tszWindowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"GetWindowText"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetWindowText"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

	// �A�N�Z�����[�^�e�[�u���̃��[�h
	hAccel =  LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_MAINMENU));	// LoadAccelerators�ŃA�N�Z�����[�^�e�[�u�������[�h.(�A�N�Z�����[�^�e�[�u���̃��\�[�XID�̓��j���[�Ɠ���IDR_MAINMENU.)

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// �f�o�C�X�R���e�L�X�g�̎擾.
	hDC = GetDC(hWnd);	// GetDC�Ńf�o�C�X�R���e�L�X�g�n���h��hDC���擾.

	// PeekMessage�ɂ�郁�C�����[�v.
	while (TRUE){	// ��ɐ^(TRUE)�Ȃ̂Ŗ������[�v.

		// �E�B���h�E���b�Z�[�W�����Ă��邩���m�F����.
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)){	// PeekMessage�ŃE�B���h�E���b�Z�[�W�����Ă��邩���m�F��, �^�Ȃ痈�Ă���.(PM_NOREMOVE�Ȃ̂Ń��b�Z�[�W�L���[���炱�̃��b�Z�[�W���폜���Ȃ�.����GetMessage�����̃��b�Z�[�W����������.)

			// ���Ă����炻�̃��b�Z�[�W���擾.
			if (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage��PeekMessage�Ŋm�F�������b�Z�[�W���擾.

				// �A�N�Z�����[�^�L�[�̏���.
				if (!TranslateAccelerator(hWnd, hAccel, &msg)){	// TranslateAccelerator�ŃA�N�Z�����[�^�L�[��WM_COMMAND�ɕϊ��ł����ꍇ��, �ȉ��̃��b�Z�[�W�����͂��Ȃ�.

					// �E�B���h�E���b�Z�[�W�̑��o
					TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
					DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

				}

			}
			else{	// ����I��(0), �܂��̓G���[�ɂ��ُ�I��(-1).

				// ���C�����[�v�𔲂���.
				break;	// break�Ń��C�����[�v�𔲂���.

			}

		}
		else{	// �U�Ȃ�E�B���h�E���b�Z�[�W�����Ă��Ȃ��Ƃ�.

			// �������Ȃ�.

		}

	}

	// �f�o�C�X�R���e�L�X�g�̉��.
	if (hDC != NULL){	// hDC���������Ă��Ȃ����.

		// �f�o�C�X�R���e�L�X�g���������.
		ReleaseDC(hWnd, hDC);	// ReleaseDC��hDC�����.
		hDC = NULL;	// NULL���Z�b�g.

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

		// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵��, �R�}���h������������.
		case WM_COMMAND:	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵��, �R�}���h������������.(uMsg��WM_COMMAND�̎�.)

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃��j���[���ڂ��I�����ꂽ���𔻒肷��.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�őI�����ꂽ���j���[���ڂ�ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// �擾����ID���Ƃɏ����𕪊�.
					// Item1-1���I�����ꂽ��.
					case ID_ITEM_1_1:

						// ID_ITEM_1_1�u���b�N
						{

							// �ϐ��̐錾
							HINSTANCE hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h��

							// hInstance���擾
							hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);	// GetWindowLong�ŃA�v���P�[�V�����C���X�^���X�n���h�����擾��, hInstance�Ɋi�[.

							// �_�C�A���O�{�b�N�X�̕\��
							DialogBox(hInstance, MAKEINTRESOURCEW(IDD_DIALOG), hwnd, DialogProc);	// DialogBox�Ń_�C�A���O�{�b�N�X��\��.(�_�C�A���O�̏�����DialogProc�ɏ����Ă���.)

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item1-2���I�����ꂽ��.
					case ID_ITEM_1_2:

						// ID_ITEM_1_2�u���b�N
						{

							// ���b�Z�[�W�{�b�N�X��\��.
							MessageBox(NULL, _T("Item1-2"), _T("GetWindowText"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item1-2"�ƕ\��.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item1-3���I�����ꂽ��.
					case ID_ITEM_1_3:

						// ID_ITEM_1_3�u���b�N
						{

							// ���b�Z�[�W�{�b�N�X��\��.
							MessageBox(NULL, _T("Item1-3"), _T("GetWindowText"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item1-3"�ƕ\��.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item2-1���I�����ꂽ��.
					case ID_ITEM_2_1:

						// ID_ITEM_2_1�u���b�N
						{

							// ���b�Z�[�W�{�b�N�X��\��.
							MessageBox(NULL, _T("Item2-1"), _T("GetWindowText"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item2-1"�ƕ\��.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item2-2���I�����ꂽ��.
					case ID_ITEM_2_2:

						// ID_ITEM_2_2�u���b�N
						{

							// ���b�Z�[�W�{�b�N�X��\��.
							MessageBox(NULL, _T("Item2-2"), _T("GetWindowText"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item2-2"�ƕ\��.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item2-3���I�����ꂽ��.
					case ID_ITEM_2_3:

						// ID_ITEM_2_3�u���b�N
						{

							// ���b�Z�[�W�{�b�N�X��\��.
							MessageBox(NULL, _T("Item2-3"), _T("GetWindowText"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item2-3"�ƕ\��.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item3-1���I�����ꂽ��.
					case ID_ITEM_3_1:

						// ID_ITEM_3_1�u���b�N
						{

							// ���b�Z�[�W�{�b�N�X��\��.
							MessageBox(NULL, _T("Item3-1"), _T("GetWindowText"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item3-1"�ƕ\��.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item3-2���I�����ꂽ��.
					case ID_ITEM_3_2:

						// ID_ITEM_3_2�u���b�N
						{

							// ���b�Z�[�W�{�b�N�X��\��.
							MessageBox(NULL, _T("Item3-2"), _T("GetWindowText"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item3-2"�ƕ\��.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item3-3���I�����ꂽ��.
					case ID_ITEM_3_3:

						// ID_ITEM_3_3�u���b�N
						{

							// ���b�Z�[�W�{�b�N�X��\��.
							MessageBox(NULL, _T("Item3-3"), _T("GetWindowText"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item3-3"�ƕ\��.

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

		// ��L�ȊO�̎�.
		default:	// ��L�ȊO�̒l�̎��̊��菈��.

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂�DefWindowProc�Ɋ���̏�����C����.

}

// DialogProc�֐��̒�`
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �_�C�A���O�̏���������R�[���o�b�N�֐�.

	// �_�C�A���O�̃��b�Z�[�W����
	switch (uMsg){	// uMsg�̓��e�Ŕ��f.

		// �_�C�A���O������ꂽ��.
		case WM_CLOSE:	// �_�C�A���O������ꂽ��.(uMsg��WM_CLOSE�̎�.)

			// WM_CLOSE�u���b�N
			{

				// �_�C�A���O���I������.
				EndDialog(hwndDlg, IDOK);	// EndDialog�Ń_�C�A���O���I������.

				// TRUE��Ԃ�.
				return TRUE;	// �����ł����̂�TRUE.

			}

			// ������.
			break;	// break�Ŕ�����.

		// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵��, �R�}���h������������.
		case WM_COMMAND:	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵��, �R�}���h������������.(uMsg��WM_COMMAND�̎�.)

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃R���g���[�����𔻒肷��.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�ŃR���g���[���̃��\�[�XID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// Button1�̎�.
					case ID_BUTTON1:

						// ID_BUTTON1�u���b�N
						{

							// �ϐ��̐錾
							HWND hEdit;			// �G�f�B�b�g�R���g���[���̃n���h��hEdit.
							int len;			// �E�B���h�E���̕�����len.
							TCHAR *ptszText;	// �E�B���h�E���ւ̃|�C���^ptszText.

							// ���̃_�C�A���O��̃R���g���[���̃��\�[�XID���擾.
							hEdit = GetDlgItem(hwndDlg, ID_EDIT1);		// GetDlgItem��ID_EDIT1�̃n���h�����擾.

							// �E�B���h�E���̕��������擾.
							len = GetWindowTextLength(hEdit);	// GetWindowTextLength��hEdit�̃E�B���h�E���̕��������擾.

							// �o�b�t�@��p��.
							ptszText = new TCHAR[len + 1];	// new�Œ���len + 1��TCHAR�z��o�b�t�@��p��.

							// �E�B���h�E���̎擾.
							GetWindowText(hEdit, ptszText, len + 1);	// GetWindowText�ŃE�B���h�E����ptszText�Ɋi�[.

							// �E�B���h�E���̕\��.
							MessageBox(NULL, ptszText, _T("GetWindowText"), MB_OK | MB_ICONASTERISK);

							// �o�b�t�@�̉��.
							delete [] ptszText;	// delete��ptszText�����.

							// TRUE��Ԃ�.
							return TRUE;	// �����ł����̂�TRUE.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����.

					// ��L�ȊO�̎�.
					default:

						// ����̏����֌�����.
						break;	// break�Ŕ�����.

				}

			}

			// ������.
			break;	// break�Ŕ�����.

		default:

			// ������.
			break;	// break�Ŕ�����.

	}

	// �����ɗ���Ƃ��͏����ł��Ă��Ȃ�.
	return FALSE;	// �����ł��Ă��Ȃ��̂�FALSE.

}