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

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.
	HDC hDC = NULL;				// ���̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC��NULL�ɏ�����.
	HMENU hMenu = NULL;			// ���̃E�B���h�E�̃��C�����j���[�n���h��hMenu��NULL�ɏ�����.
	HMENU hPopupMenu1 = NULL;	// hMenu�̎q���j���[�ƂȂ�|�b�v�A�b�v���j���[�̃n���h��hPopupMenu1��NULL�ɏ�����.
	HMENU hPopupMenu2 = NULL;	// hMenu�̎q���j���[�ƂȂ�|�b�v�A�b�v���j���[�̃n���h��hPopupMenu2��NULL�ɏ�����.
	HMENU hPopupMenu3 = NULL;	// hMenu�̎q���j���[�ƂȂ�|�b�v�A�b�v���j���[�̃n���h��hPopupMenu3��NULL�ɏ�����.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("CreatePopupMenu");				// �E�B���h�E�N���X����"CreatePopupMenu".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CreatePopupMenu"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// ���j���[�쐬
	hMenu = CreateMenu();	// CreateMenu�Ń��j���[���쐬��, �n���h�����Ԃ�̂�hMenu�Ɋi�[.

	// �|�b�v�A�b�v���j���[(�h���b�v�_�E�����j���[)�쐬
	hPopupMenu1 = CreatePopupMenu();	// CreatePopupMenu�Ń|�b�v�A�b�v���j���[���쐬��, �n���h����hPopupMenu1�Ɋi�[.
	hPopupMenu2 = CreatePopupMenu();	// CreatePopupMenu�Ń|�b�v�A�b�v���j���[���쐬��, �n���h����hPopupMenu2�Ɋi�[.
	hPopupMenu3 = CreatePopupMenu();	// CreatePopupMenu�Ń|�b�v�A�b�v���j���[���쐬��, �n���h����hPopupMenu3�Ɋi�[.

	// �|�b�v�A�b�v���j���[hPopupMenu1�Ƀ��j���[���ڂ�ǉ�.
	AppendMenu(hPopupMenu1, MF_ENABLED | MF_STRING, ID_ITEM_1_1, _T("Item1-1(&B)"));	// AppendMenu��hPopupMenu1�Ƀ��j���[����Item1-1��ǉ�.
	AppendMenu(hPopupMenu1, MF_ENABLED | MF_STRING, ID_ITEM_1_2, _T("Item1-2(&C)"));	// AppendMenu��hPopupMenu1�Ƀ��j���[����Item1-2��ǉ�.
	AppendMenu(hPopupMenu1, MF_ENABLED | MF_STRING, ID_ITEM_1_3, _T("Item1-3(&D)"));	// AppendMenu��hPopupMenu1�Ƀ��j���[����Item1-3��ǉ�.

	// �|�b�v�A�b�v���j���[hPopupMenu2�Ƀ��j���[���ڂ�ǉ�.
	AppendMenu(hPopupMenu2, MF_ENABLED | MF_STRING, ID_ITEM_2_1, _T("Item2-1(&F)"));	// AppendMenu��hPopupMenu2�Ƀ��j���[����Item2-1��ǉ�.
	AppendMenu(hPopupMenu2, MF_ENABLED | MF_STRING, ID_ITEM_2_2, _T("Item2-2(&G)"));	// AppendMenu��hPopupMenu2�Ƀ��j���[����Item2-2��ǉ�.
	AppendMenu(hPopupMenu2, MF_ENABLED | MF_STRING, ID_ITEM_2_3, _T("Item2-3(&H)"));	// AppendMenu��hPopupMenu2�Ƀ��j���[����Item2-3��ǉ�.

	// �|�b�v�A�b�v���j���[hPopupMenu3�Ƀ��j���[���ڂ�ǉ�.
	AppendMenu(hPopupMenu3, MF_ENABLED | MF_STRING, ID_ITEM_3_1, _T("Item3-1(&J)"));	// AppendMenu��hPopupMenu3�Ƀ��j���[����Item3-1��ǉ�.
	AppendMenu(hPopupMenu3, MF_ENABLED | MF_STRING, ID_ITEM_3_2, _T("Item3-2(&K)"));	// AppendMenu��hPopupMenu3�Ƀ��j���[����Item3-2��ǉ�.
	AppendMenu(hPopupMenu3, MF_ENABLED | MF_STRING, ID_ITEM_3_3, _T("Item3-3(&L)"));	// AppendMenu��hPopupMenu3�Ƀ��j���[����Item3-3��ǉ�.

	// ���j���[hMenu�Ƀ|�b�v�A�b�v���j���[hPopupMenu1, hPopupMenu2, hPopupMenu3��ǉ�.
	AppendMenu(hMenu, MF_ENABLED | MF_POPUP, (UINT_PTR)hPopupMenu1, _T("Item1(&A)"));	// AppendMenu��hMenu��hPopupMenu1��ǉ�.
	AppendMenu(hMenu, MF_ENABLED | MF_POPUP, (UINT_PTR)hPopupMenu2, _T("Item2(&E)"));	// AppendMenu��hMenu��hPopupMenu2��ǉ�.
	AppendMenu(hMenu, MF_ENABLED | MF_POPUP, (UINT_PTR)hPopupMenu3, _T("Item3(&I)"));	// AppendMenu��hMenu��hPopupMenu3��ǉ�.
		
	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("CreatePopupMenu"), _T("CreatePopupMenu"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, hMenu, hInstance, NULL);	// CreateWindow��, ��œo�^����"CreatePopupMenu"�E�B���h�E�N���X�̃E�B���h�E���쐬.(9�Ԗڂ�hMenu���w�肷��.)
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreatePopupMenu"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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


		// ��L�ȊO�̎�.
		default:	// ��L�ȊO�̒l�̎��̊��菈��.

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂�DefWindowProc�Ɋ���̏�����C����.

}