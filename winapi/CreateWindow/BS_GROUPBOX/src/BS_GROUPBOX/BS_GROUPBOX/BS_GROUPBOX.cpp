// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <commctrl.h>	// �R�����R���g���[��

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
	wc.lpszClassName = _T("BS_GROUPBOX");						// �E�B���h�E�N���X����"BS_GROUPBOX".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("BS_GROUPBOX"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �����񃊃\�[�X�̃��[�h
	LoadString(hInstance, IDS_WINDOW_NAME, tszWindowName, 256);	// LoadString��STRINGTABLE����IDS_WINDOW_NAME�ɂ����镶��������[�h��, tszWindowName�Ɋi�[.

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("BS_GROUPBOX"), tszWindowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"BS_GROUPBOX"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("BS_GROUPBOX"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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

				// �ϐ��̐錾
				HWND hButton;			// �{�^���̃E�B���h�E�n���h��hButton.
				HWND hStatic;			// �X�^�e�B�b�N�R���g���[���̃E�B���h�E�n���h��hStatic.
				HWND hEdit;				// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit.
				HWND hCheck;			// �`�F�b�N�{�b�N�X�R���g���[���̃E�B���h�E�n���h��hCheck.
				HWND hRadio1;			// ���W�I�{�^���R���g���[���̃E�B���h�E�n���h��hRadio1.
				HWND hRadio2;			// ���W�I�{�^���R���g���[���̃E�B���h�E�n���h��hRadio2.
				HWND hRadio3;			// ���W�I�{�^���R���g���[���̃E�B���h�E�n���h��hRadio3.
				HWND hGroup;			// �O���[�v�{�b�N�X�R���g���[���̃E�B���h�E�n���h��hGroup.
				LPCREATESTRUCT lpCS;	// CreateStruct�\���̂̃|�C���^lpCS.

				// �A�v���P�[�V�����C���X�^���X�n���h���̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����, lpCS�Ɋi�[.

				// �{�^���̍쐬.
				hButton = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE, 50, 00, 100, 30, hwnd, (HMENU)ID_BUTTON1, lpCS->hInstance, NULL);	// CreateWindow��WC_BUTTON�Ń{�^��"Button1"���쐬.
				if (hButton == NULL){	// hButton��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// �X�^�e�B�b�N�R���g���[��(�e�L�X�g)�̍쐬.
				hStatic = CreateWindow(WC_STATIC, _T("StaticText1"), WS_CHILD | WS_VISIBLE, 50, 30, 100, 30, hwnd, (HMENU)ID_STATIC1, lpCS->hInstance, NULL);	// CreateWindow��WC_STATIC�ŃX�^�e�B�b�N�R���g���[��(�e�L�X�g)"StaticText1"���쐬.
				if (hStatic == NULL){	// hStatic��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// �G�f�B�b�g�R���g���[���̍쐬.
				hEdit = CreateWindow(WC_EDIT, _T("Edit1"), WS_CHILD | WS_BORDER | WS_VISIBLE, 50, 60, 150, 30, hwnd, (HMENU)ID_EDIT1, lpCS->hInstance, NULL);	// CreateWindow��WC_EDIT�ŃG�f�B�b�g�R���g���[��"Edit1"���쐬.
				if (hEdit == NULL){	// hEdit��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// �`�F�b�N�{�b�N�X�̍쐬.
				hCheck = CreateWindow(WC_BUTTON, _T("CheckBox1"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX, 50, 90, 100, 30, hwnd, (HMENU)ID_CHECK1, lpCS->hInstance, NULL);	// CreateWindow��WC_BUTTON��BS_CHECKBOX�Ń`�F�b�N�{�b�N�X"CheckBox1"���쐬.
				if (hCheck == NULL){	// hCheck��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// �O���[�v�{�b�N�X1�̍쐬.
				hGroup = CreateWindow(WC_BUTTON, _T("GroupBox1"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 50, 120, 410, 150, hwnd, (HMENU)ID_GROUP1, lpCS->hInstance, NULL);	// CreateWindow��WC_BUTTON��BS_GROUPBOX�ŃO���[�v�{�b�N�X"GroupBox1"���쐬.
				if (hGroup == NULL){	// hGroup��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// ���W�I�{�^��1�̍쐬.
				hRadio1 = CreateWindow(WC_BUTTON, _T("RadioButton1"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON | WS_GROUP, 20, 20, 120, 30, hGroup, (HMENU)ID_RADIO1, lpCS->hInstance, NULL);	// CreateWindow��WC_BUTTON��BS_RADIOBUTTON�Ń��W�I�{�^��"RadioButton1"���쐬.(hGroup�̎q�E�B���h�E�Ƃ��č쐬. �O���[�v�̍ŏ��̃R���g���[���ɂ�WS_GROUP������.)
				if (hRadio1 == NULL){	// hRadio1��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// ���W�I�{�^��2�̍쐬.
				hRadio2 = CreateWindow(WC_BUTTON, _T("RadioButton2"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, 140, 20, 120, 30, hGroup, (HMENU)ID_RADIO2, lpCS->hInstance, NULL);	// CreateWindow��WC_BUTTON��BS_RADIOBUTTON�Ń��W�I�{�^��"RadioButton2"���쐬.(hGroup�̎q�E�B���h�E�Ƃ��č쐬.)
				if (hRadio2 == NULL){	// hRadio2��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// ���W�I�{�^��3�̍쐬.
				hRadio3 = CreateWindow(WC_BUTTON, _T("RadioButton3"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, 260, 20, 120, 30, hGroup, (HMENU)ID_RADIO3, lpCS->hInstance, NULL);	// CreateWindow��WC_BUTTON��BS_RADIOBUTTON�Ń��W�I�{�^��"RadioButton3"���쐬.(hGroup�̎q�E�B���h�E�Ƃ��č쐬.)
				if (hRadio3 == NULL){	// hRadio3��NULL�Ȃ�.

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
							MessageBox(NULL, _T("Item1-2"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item1-2"�ƕ\��.

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
							MessageBox(NULL, _T("Item1-3"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item1-3"�ƕ\��.

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
							MessageBox(NULL, _T("Item2-1"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item2-1"�ƕ\��.

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
							MessageBox(NULL, _T("Item2-2"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item2-2"�ƕ\��.

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
							MessageBox(NULL, _T("Item2-3"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item2-3"�ƕ\��.

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
							MessageBox(NULL, _T("Item3-1"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item3-1"�ƕ\��.

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
							MessageBox(NULL, _T("Item3-2"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item3-2"�ƕ\��.

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
							MessageBox(NULL, _T("Item3-3"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Item3-3"�ƕ\��.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Button1�������ꂽ��.
					case ID_BUTTON1:

						// ID_BUTTON1�u���b�N
						{

							// �ϐ��̐錾.
							HWND hGroup;	// GroupBox1�̃E�B���h�E�n���h��.

							// GroupBox1�̃E�B���h�E�n���h�����擾.
							hGroup = GetDlgItem(hwnd, ID_GROUP1);		// GetDlgItem��ID_GROUP1�̃n���h���擾.

							// RadioButton1�Ƀ`�F�b�N������.
							CheckRadioButton(hGroup, ID_RADIO1, ID_RADIO3, ID_RADIO1);	// CheckRadioButton��ID_RADIO1�݂̂Ƀ`�F�b�N������.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// CheckBox1�������ꂽ��.
					case ID_CHECK1:

						// ID_CHECK1�u���b�N
						{

							// ���b�Z�[�W�{�b�N�X��\��.
							MessageBox(NULL, _T("CheckBox1 Cliked!"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBox��"CheckBox1 Cliked!"�ƕ\��.
							
							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// RadioButton1�������ꂽ�Ƃ�.
					case ID_RADIO1:

						// ID_RADIO1�u���b�N
						{

							// ID_RADIO1�Ƀ`�F�b�N������.(���ۂɂ�ID_RADIO1��, ID_GROUP1�̎q�E�B���h�E�ɂȂ��Ă��邽��, �����ɂ͗��Ȃ�.)
							CheckRadioButton(hwnd, ID_RADIO1, ID_RADIO3, ID_RADIO1);	// CheckRadioButton��ID_RADIO1�݂̂Ƀ`�F�b�N������.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// RadioButton2�������ꂽ�Ƃ�.
					case ID_RADIO2:

						// ID_RADIO2�u���b�N
						{

							// ID_RADIO2�Ƀ`�F�b�N������.(���ۂɂ�ID_RADIO2��, ID_GROUP1�̎q�E�B���h�E�ɂȂ��Ă��邽��, �����ɂ͗��Ȃ�.)
							CheckRadioButton(hwnd, ID_RADIO1, ID_RADIO3, ID_RADIO2);	// CheckRadioButton��ID_RADIO2�݂̂Ƀ`�F�b�N������.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// RadioButton3�������ꂽ�Ƃ�.
					case ID_RADIO3:

						// ID_RADIO3�u���b�N
						{

							// ID_RADIO3�Ƀ`�F�b�N������.(���ۂɂ�ID_RADIO3��, ID_GROUP1�̎q�E�B���h�E�ɂȂ��Ă��邽��, �����ɂ͗��Ȃ�.)
							CheckRadioButton(hwnd, ID_RADIO1, ID_RADIO3, ID_RADIO3);	// CheckRadioButton��ID_RADIO3�݂̂Ƀ`�F�b�N������.

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

		default:

			// ������.
			break;	// break�Ŕ�����.

	}

	// �����ɗ���Ƃ��͏����ł��Ă��Ȃ�.
	return FALSE;	// �����ł��Ă��Ȃ��̂�FALSE.

}