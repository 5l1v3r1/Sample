// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.
LRESULT CALLBACK WindowProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �q�̃E�B���h�E�̃E�B���h�E�v���V�[�W��WindowProc2.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;		// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;		// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wcParent;	// �e�̃E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wcParent.
	WNDCLASS wcChild;	// �q�̃E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wcChild.

	// �e�̃E�B���h�E�N���X�̐ݒ�
	wcParent.lpszClassName = _T("WNDCLASS_Parent");					// �E�B���h�E�N���X����"WNDCLASS_Parent".
	wcParent.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wcParent.lpfnWndProc = WindowProc;								// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wcParent.hInstance = hInstance;									// �C���X�^���X�n���h����_tWinMain�̈���.
	wcParent.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wcParent.hCursor = LoadCursor(NULL, IDC_ARROW);					// �J�[�\���͖��.
	wcParent.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wcParent.lpszMenuName = NULL;									// �Ȃ�
	wcParent.cbClsExtra = 0;										// 0�ł���.
	wcParent.cbWndExtra = 0;										// 0�ł���.

	// �e�̃E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wcParent)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.
 
		// �G���[����
		MessageBox(NULL, _T("Parent: RegisterClass failed!"), _T("WNDCLASS"), MB_OK | MB_ICONHAND);	// MessageBox��"Parent: RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)
 
	}

	// �q�̃E�B���h�E�N���X�̐ݒ�
	wcChild.lpszClassName = _T("WNDCLASS_Child");					// �E�B���h�E�N���X����"WNDCLASS_Child".
	wcChild.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wcChild.lpfnWndProc = WindowProc2;								// �E�B���h�E�v���V�[�W���͎q�̃E�B���h�E�p��WindowProc2.
	wcChild.hInstance = hInstance;									// �C���X�^���X�n���h����_tWinMain�̈���.
	wcChild.hIcon = NULL;											// �A�C�R���͂Ȃ�.
	wcChild.hCursor = NULL;											// �J�[�\���͂Ȃ�.
	wcChild.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);	// �w�i�͒W�D�F�u���V.
	wcChild.lpszMenuName = NULL;									// �Ȃ�
	wcChild.cbClsExtra = 0;											// 0�ł���.
	wcChild.cbWndExtra = 0;											// 0�ł���.

	// �q�̃E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wcChild)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.
 
		// �G���[����
		MessageBox(NULL, _T("Child: RegisterClass failed!"), _T("WNDCLASS"), MB_OK | MB_ICONHAND);	// MessageBox��"Child: RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)
 
	}

	// �e�̃E�B���h�E�̍쐬.
	hWnd = CreateWindow(_T("WNDCLASS_Parent"), _T("WNDCLASS"), WS_OVERLAPPEDWINDOW, 50, 50, 640, 480, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"WNDCLASS_Parent"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("Parent: CreateWindow failed!"), _T("WNDCLASS"), MB_OK | MB_ICONHAND);	// MessageBox��"Parent: CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -3;	// �ُ�I��(3)
 
	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�Đe�̃E�B���h�E�̕\��.

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
				HWND hChild;	// �q�̃E�B���h�E�n���h��hChild.
				LPCREATESTRUCT lpCS;	// CreateStruct�\���̂̃|�C���^lpCS.

				// �A�v���P�[�V�����C���X�^���X�n���h���̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����, lpCS�Ɋi�[.

				// �q�̃E�B���h�E�̍쐬.
				hChild = CreateWindow(_T("WNDCLASS_Child"), _T(""), WS_CHILD | WS_VISIBLE, 50, 50, 250, 250, hwnd, (HMENU)501, lpCS->hInstance, NULL);	// CreateWindow�Ŏq�̃E�B���h�E���쐬.
				if (hChild == NULL){	// hChild��NULL�Ȃ�.

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

		// ��L�ȊO�̎�.
		default:	// ��L�ȊO�̒l�̎��̊��菈��.
 
			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.
 
	}
 
	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂�DefWindowProc�Ɋ���̏�����C����.

}

// WindowProc2�֐��̒�`
LRESULT CALLBACK WindowProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �q�̃E�B���h�E�̃E�B���h�E�v���V�[�W��WindowProc2.

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂�DefWindowProc�Ɋ���̏�����C����.

}