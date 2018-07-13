// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// ���j���[�̃��\�[�XID�̒�`.
#define ID_MENU_ITEM1 101
#define ID_MENU_ITEM1_1	10101
#define ID_MENU_ITEM1_2	10102
#define ID_MENU_ITEM1_3	10103
#define ID_MENU_ITEM2 102
#define ID_MENU_ITEM2_1	10201
#define ID_MENU_ITEM2_2	10202
#define ID_MENU_ITEM2_3	10203

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;				// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;				// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;			// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.
	HDC hDC = NULL;			// ���̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC��NULL�ɏ�����.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("InsertMenuItem");				// �E�B���h�E�N���X����"InsertMenuItem".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = NULL;									// �Ƃ肠���������ł�NULL�ɂ��Ă���.
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("InsertMenuItem"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("InsertMenuItem"), _T("InsertMenuItem"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"InsertMenuItem"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("InsertMenuItem"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

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

				// �E�B���h�E���b�Z�[�W�̑��o
				TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
				DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

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

	// �ϐ��̐錾
	static HMENU hMenu;		// ���C�����j���[�̃n���h��hMenu���X�^�e�B�b�N�ϐ��Ő錾.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// ���j���[�̍쐬.
				hMenu = CreateMenu();	// CreateMenu�Ń��j���[���쐬��, �n���h����hMenu�Ɋi�[.

				// �|�b�v�A�b�v���j���[�n���h��1�̏�����.
				HMENU hPopupMenu1 = NULL;	// hPopupMenu1��NULL�ŏ�����.
				// �|�b�v�A�b�v���j���[1�̍쐬.
				hPopupMenu1 = CreatePopupMenu();	// hPopupMenu1�̍쐬.
				// ���j���[�A�C�e�����\���̂̐錾.
				MENUITEMINFO mii1;	// mii1��錾.
				// ������.
				ZeroMemory(&mii1, sizeof(MENUITEMINFO));	// mii1��ZeroMemory�ŏ�����.
				// �l�̃Z�b�g.
				mii1.cbSize = sizeof(MENUITEMINFO);	// �T�C�Y.
				mii1.fMask = MIIM_TYPE | MIIM_SUBMENU;	// �T�u���j���[.
				mii1.fType = MFT_STRING;	// ������.
				mii1.fState = MFS_ENABLED;	// �L��.
				mii1.wID = ID_MENU_ITEM1;	// ID_MENU_ITEM1.
				mii1.hSubMenu = hPopupMenu1;	// hPopupMenu1���T�u���j���[�Ƃ���.
				mii1.dwTypeData = _T("Item1");	// "Item1".
				// �}��.
				InsertMenuItem(hMenu, 0, TRUE, &mii1);	// InsertMenuItem��mii1��}��.

				// �T�u�A�C�e��1-1�̍쐬.
				MENUITEMINFO mii11;	// mii11��錾.
				// ������.
				ZeroMemory(&mii11, sizeof(MENUITEMINFO));	// mii11��ZeroMemory�ŏ�����.
				// �l�̃Z�b�g.
				mii11.cbSize = sizeof(MENUITEMINFO);	// �T�C�Y.
				mii11.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii11.fType = MFT_STRING;	// ������.
				mii11.fState = MFS_ENABLED;	// �L��.
				mii11.wID = ID_MENU_ITEM1_1;	// ID_MENU_ITEM1_1.
				mii11.dwTypeData = _T("Item1-1");	// "Item1-1".
				// �}��.
				InsertMenuItem(hPopupMenu1, 0, TRUE, &mii11);	// InsertMenuItem��mii11��hPopupMenu1�ɑ}��.

				// �T�u�A�C�e��1-2�̍쐬.
				MENUITEMINFO mii12;	// mii12��錾.
				// ������.
				ZeroMemory(&mii12, sizeof(MENUITEMINFO));	// mii12��ZeroMemory�ŏ�����.
				// �l�̃Z�b�g.
				mii12.cbSize = sizeof(MENUITEMINFO);	// �T�C�Y.
				mii12.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii12.fType = MFT_STRING;	// ������.
				mii12.fState = MFS_ENABLED;	// �L��.
				mii12.wID = ID_MENU_ITEM1_2;	// ID_MENU_ITEM1_2.
				mii12.dwTypeData = _T("Item1-2");	// "Item1-2".
				// �}��.
				InsertMenuItem(hPopupMenu1, 1, TRUE, &mii12);	// InsertMenuItem��mii12��hPopupMenu1�ɑ}��.

				// �T�u�A�C�e��1-3�̍쐬.
				MENUITEMINFO mii13;	// mii13��錾.
				// ������.
				ZeroMemory(&mii13, sizeof(MENUITEMINFO));	// mii13��ZeroMemory�ŏ�����.
				// �l�̃Z�b�g.
				mii13.cbSize = sizeof(MENUITEMINFO);	// �T�C�Y.
				mii13.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii13.fType = MFT_STRING;	// ������.
				mii13.fState = MFS_ENABLED;	// �L��.
				mii13.wID = ID_MENU_ITEM1_3;	// ID_MENU_ITEM1_3.
				mii13.dwTypeData = _T("Item1-3");	// "Item1-3".
				// �}��.
				InsertMenuItem(hPopupMenu1, 2, TRUE, &mii13);	// InsertMenuItem��mii13��hPopupMenu1�ɑ}��.

				// �|�b�v�A�b�v���j���[�n���h��2�̏�����.
				HMENU hPopupMenu2 = NULL;	// hPopupMenu2��NULL�ŏ�����.
				// �|�b�v�A�b�v���j���[2�̍쐬.
				hPopupMenu2 = CreatePopupMenu();	// hPopupMenu2�̍쐬.
				// ���j���[�A�C�e�����\���̂̐錾.
				MENUITEMINFO mii2;	// mii2��錾.
				// ������.
				ZeroMemory(&mii2, sizeof(MENUITEMINFO));	// mii2��ZeroMemory�ŏ�����.
				// �l�̃Z�b�g.
				mii2.cbSize = sizeof(MENUITEMINFO);	// �T�C�Y.
				mii2.fMask = MIIM_TYPE | MIIM_SUBMENU;	// �T�u���j���[.
				mii2.fType = MFT_STRING;	// ������.
				mii2.fState = MFS_ENABLED;	// �L��.
				mii2.wID = ID_MENU_ITEM2;	// ID_MENU_ITEM2.
				mii2.hSubMenu = hPopupMenu2;	// hPopupMenu2���T�u���j���[�Ƃ���.
				mii2.dwTypeData = _T("Item2");	// "Item2".
				// �}��.
				InsertMenuItem(hMenu, ID_MENU_ITEM2, FALSE, &mii2);	// InsertMenuItem��mii2��}��.

				// �T�u�A�C�e��2-1�̍쐬.
				MENUITEMINFO mii21;	// mii21��錾.
				// ������.
				ZeroMemory(&mii21, sizeof(MENUITEMINFO));	// mii21��ZeroMemory�ŏ�����.
				// �l�̃Z�b�g.
				mii21.cbSize = sizeof(MENUITEMINFO);	// �T�C�Y.
				mii21.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii21.fType = MFT_STRING;	// ������.
				mii21.fState = MFS_ENABLED;	// �L��.
				mii21.wID = ID_MENU_ITEM2_1;	// ID_MENU_ITEM2_1.
				mii21.dwTypeData = _T("Item2-1");	// "Item2-1".
				// �}��.
				InsertMenuItem(hPopupMenu2, ID_MENU_ITEM2_1, FALSE, &mii21);	// InsertMenuItem��mii21��hPopupMenu2�ɑ}��.

				// �T�u�A�C�e��2-2�̍쐬.
				MENUITEMINFO mii22;	// mii22��錾.
				// ������.
				ZeroMemory(&mii22, sizeof(MENUITEMINFO));	// mii22��ZeroMemory�ŏ�����.
				// �l�̃Z�b�g.
				mii22.cbSize = sizeof(MENUITEMINFO);	// �T�C�Y.
				mii22.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii22.fType = MFT_STRING;	// ������.
				mii22.fState = MFS_ENABLED;	// �L��.
				mii22.wID = ID_MENU_ITEM2_2;	// ID_MENU_ITEM2_2.
				mii22.dwTypeData = _T("Item2-2");	// "Item2-2".
				// �}��.
				InsertMenuItem(hPopupMenu2, ID_MENU_ITEM2_2, FALSE, &mii22);	// InsertMenuItem��mii22��hPopupMenu2�ɑ}��.

				// �T�u�A�C�e��2-3�̍쐬.
				MENUITEMINFO mii23;	// mii23��錾.
				// ������.
				ZeroMemory(&mii23, sizeof(MENUITEMINFO));	// mii23��ZeroMemory�ŏ�����.
				// �l�̃Z�b�g.
				mii23.cbSize = sizeof(MENUITEMINFO);	// �T�C�Y.
				mii23.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii23.fType = MFT_STRING;	// ������.
				mii23.fState = MFS_ENABLED;	// �L��.
				mii23.wID = ID_MENU_ITEM2_3;	// ID_MENU_ITEM2_3.
				mii23.dwTypeData = _T("Item2-3");	// "Item2-3".
				// �}��.
				InsertMenuItem(hPopupMenu2, ID_MENU_ITEM2_3, FALSE, &mii23);	// InsertMenuItem��mii23��hPopupMenu2�ɑ}��.

				// ���j���[�̃Z�b�g.
				SetMenu(hwnd, hMenu);	// SetMenu��hMenu�̃Z�b�g.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// ���j���[�j��
				DestroyMenu(hMenu);	// DestroyMenu��hMenu��j��.

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.(����ƃ��b�Z�[�W���[�v��GetMessage�̖߂�l��0�ɂȂ�̂�, ���b�Z�[�W���[�v���甲����.)

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