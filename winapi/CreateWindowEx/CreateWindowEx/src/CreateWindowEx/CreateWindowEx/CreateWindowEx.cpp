// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �Ǝ��̃E�B���h�E�v���V�[�W��WindowProc.

// _tWindMain�֐�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��̐錾
	HWND hWnd;		// �E�B���h�E�n���h��hWnd
	MSG msg;		// �E�B���h�E���b�Z�[�W���msg
	WNDCLASS wc;	// �E�B���h�E�N���Xwc

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("CreateWindowEx");				// �Ǝ��ɒ�`�����E�B���h�E�N���X"CreateWindowEx".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �Ƃ肠����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �Ǝ��ɒ�`�����E�B���h�E�v���V�[�W��WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h��hInstance���w��.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);		// �A�v���P�[�V��������A�C�R��IDI_APPLICATION.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);			// ����̖��J�[�\��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔�(WHITE_BRUSH).
	wc.lpszMenuName = NULL;									// ���j���[�͂Ȃ�.
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CreateWindowEx"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("CreateWindowEx"), _T("CreateWindowEx"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"CreateWindowEx"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreateWindowEx"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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

				// ���̃u���b�N�̃��[�J���ϐ��錾.
				HWND hStatic;	// "STATIC"�E�B���h�E�N���X(WC_STATIC)�̎q�E�B���h�E�̃n���h��hStatic.
				LPCREATESTRUCT lpCS;	// CreateStruct�\���̂̃|�C���^lpCS.

				// lParam��lpCS�ɕϊ�.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����lpCS�Ɋi�[.
				if (lpCS != NULL){	// lpCS��NULL�łȂ����.

					// �q�E�B���h�E�쐬
					hStatic = CreateWindowEx(WS_EX_CLIENTEDGE, _T("STATIC"), _T("CreateWindowEx"), WS_CHILD | WS_VISIBLE, 50, 50, 250, 50, hwnd, (HMENU)501, lpCS->hInstance, NULL);	// CreateWindowEx��"STATIC"�E�B���h�E�N���X�̎q�E�B���h�E���쐬.(WS_EX_CLIENTEDGE�Œ���ł���悤�Ɍ�����.)
					if (hStatic != NULL){	// hStatic��NULL�łȂ���ΐ���.
						
						// �E�B���h�E�쐬����
						return 0;	// 0��Ԃ�.

					}

				}

				// �E�B���h�E�쐬���s
				return -1;	// -1��Ԃ�.

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
 
				// ���̃u���b�N�̃��[�J���ϐ��̐錾.
				HDC hDC;	// �f�o�C�X�R���e�L�X�g�n���h�����i�[����HDC�^�ϐ�hDC.
				PAINTSTRUCT ps;		// �y�C���g�����Ǘ�����PAINTSTRUCT�\���̌^�̕ϐ�ps.

				// �E�B���h�E�̕`��J�n
				hDC = BeginPaint(hwnd, &ps);	// BeginPaint�ł��̃E�B���h�E�̕`��̏���������. �߂�l�ɂ̓f�o�C�X�R���e�L�X�g�n���h�����Ԃ�̂�, hDC�Ɋi�[.

				// �E�B���h�E�̕`��I��
				EndPaint(hwnd, &ps);	// EndPaint�ł��̃E�B���h�E�̕`�揈�����I������.
 
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