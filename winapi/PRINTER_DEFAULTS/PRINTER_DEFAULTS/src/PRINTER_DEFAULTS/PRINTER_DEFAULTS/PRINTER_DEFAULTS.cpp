// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <cstring>		// C�����񏈗�
#include <commctrl.h>	// �R�����R���g���[��
#include <shlwapi.h>	// �V�F��API
// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�X

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){
 
	// �ϐ��̐錾
	HWND hWnd;		// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;		// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;	// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("PRINTER_DEFAULTS");				// �E�B���h�E�N���X����"PRINTER_DEFAULTS".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("PRINTER_DEFAULTS"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)
 
	}

	// �E�B���h�E�̍쐬.
	hWnd = CreateWindow(_T("PRINTER_DEFAULTS"), _T("PRINTER_DEFAULTS"), WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"PRINTER_DEFAULTS"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.
 
		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("PRINTER_DEFAULTS"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.
 
		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)
 
			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾
				HWND hEdit1;	// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit1.
				HWND hEdit2;	// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit2.
				LPCREATESTRUCT lpCS;	// CreateStruct�\���̂̃|�C���^lpCS.
				TCHAR tszModulePath[MAX_PATH] = {0};	// tszModulePath(����MAX_PATH)��{0}�ŏ�����.

				// �A�v���P�[�V�����C���X�^���X�n���h���̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����, lpCS�Ɋi�[.

				// �G�f�B�b�g�R���g���[���̍쐬.
				hEdit1 = CreateWindow(WC_EDIT, _T(""), WS_CHILD | WS_BORDER | WS_VISIBLE, 50, 50, 300, 30, hwnd, (HMENU)ID_EDIT1, lpCS->hInstance, NULL);	// CreateWindow��WC_EDIT�ŃG�f�B�b�g�R���g���[�����쐬.
				if (hEdit1 == NULL){	// hEdit1��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}
				hEdit2 = CreateWindow(WC_EDIT, _T(""), WS_CHILD | WS_BORDER | WS_VISIBLE | ES_AUTOHSCROLL, 50, 100, 300, 30, hwnd, (HMENU)ID_EDIT2, lpCS->hInstance, NULL);	// CreateWindow��WC_EDIT�ŃG�f�B�b�g�R���g���[�����쐬.
				if (hEdit2 == NULL){	// hEdit2��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// ���ݎ��s���̎��s�t�@�C���̃t���p�X���擾.
				//GetModuleFileName(NULL, tszModulePath, MAX_PATH);	// GetModuleFileName�ł��̎��s�t�@�C���̃t���p�X���擾.

				// �t�@�C�����̕�������菜��, ��������t�H���_�p�X���擾����.
				//PathRemoveFileSpec(tszModulePath);	// PathRemoveFileSpec�Ńt�@�C�����̕�������菜��.

				// "\test.pdf"��A��.
				//_tcscat(tszModulePath, _T("\\test.pdf"));	// _tcscat��"\test.pdf"��A��.

				// hEdit2�ɃZ�b�g.
				//SetWindowText(hEdit2, tszModulePath);	// SetWindowText��hEdit2��tszModulePath���Z�b�g.

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

		// ��ʂ̕`���v�����ꂽ��.
		case WM_PAINT:		// ��ʂ̕`���v�����ꂽ��.(uMsg��WM_PAINT�̎�.)
 
			// WM_PAINT�u���b�N
			{

				// ���̃u���b�N�̃��[�J���ϐ��̐錾
				HDC hDC;			// �f�o�C�X�R���e�L�X�g�n���h�����i�[����HDC�^�ϐ�hDC.
				PAINTSTRUCT ps;		// �y�C���g�����Ǘ�����PAINTSTRUCT�\���̌^�̕ϐ�ps.

				// �E�B���h�E�̕`��J�n
				hDC = BeginPaint(hwnd, &ps);	// BeginPaint�ł��̃E�B���h�E�̕`��̏���������. �߂�l�ɂ̓f�o�C�X�R���e�L�X�g�n���h�����Ԃ�̂�, hDC�Ɋi�[.

				// �E�B���h�E�̕`��I��
				EndPaint(hwnd, &ps);	// EndPaint�ł��̃E�B���h�E�̕`�揈�����I������.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E������ꂽ��.
		case WM_CLOSE:	// �E�B���h�E������ꂽ��.(uMsg��WM_CLOSE�̎�.)

			// WM_CLOSE�u���b�N
			{

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
					// Print���I�����ꂽ��.
					case ID_ITEM_PRINT:

						// ID_ITEM_PRINT�u���b�N
						{

							// �ϐ��̐錾�Ə�����.
							PAGESETUPDLG psd = {0};	// PAGESETUPDLG�\����psd��0�ŏ�����.
							DEVMODE *pDevMode = NULL;	// DEVMODE�\���̃|�C���^pDevMode��NULL�ŏ�����.
							PRINTER_DEFAULTS pd = {0};	// PRINTER_DEFAULTS�\����pd��{0}�ŏ�����.
							BOOL bRet = FALSE;	// BOOL�^bRet��FALSE�ŏ�����.
							HANDLE hPrinter = NULL;	// HANDLE�^hPrinter��NULL�ŏ�����.

							// psd�̏����ݒ�
							psd.lStructSize = sizeof(PAGESETUPDLG);	// sizeof��PAGESETUPDLG�\���̂̃T�C�Y���w��.
							psd.hwndOwner = hwnd;		// hwnd���w��.
							psd.Flags = PSD_INHUNDREDTHSOFMILLIMETERS;	// �~���P�ʂɐݒ�.

							// PageSetupDlg�̕\��.
							bRet = PageSetupDlg(&psd);	// PageSetupDlg��psd��n���ĕ\����, �߂�l��bRet�Ɋi�[.
							if (bRet){	// TRUE�̎�.
								pDevMode = (DEVMODE *)GlobalLock(psd.hDevMode);	// psd.hDevMode�����b�N.
								if (pDevMode != NULL){	// pDevMode��NULL�łȂ���.
									//pd.DesiredAccess = PRINTER_ALL_ACCESS;	// �S�Ă̌���.
									pd.DesiredAccess = PRINTER_ACCESS_USE;	// ���[�U����.
									bRet = OpenPrinter(pDevMode->dmDeviceName, &hPrinter, &pd);	// OpenPrinter�Ńv�����^���J��.
									if (bRet){	// TRUE.
										MessageBox(hwnd, _T("OpenPrinter OK!"), _T("PRINTER_DEFAULTS"), MB_OK);	// "OpenPrinter OK!"�ƕ\��.
										ClosePrinter(hPrinter);	// ClosePrinter�ŕ���.
									}
									else{	// FALSE.
										MessageBox(hwnd, _T("OpenPrinter NG!"), _T("PRINTER_DEFAULTS"), MB_OK);	// "OpenPrinter NG!"�ƕ\��.
									}
									GlobalUnlock(psd.hDevMode);	// �A�����b�N.
								}
							}

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