// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o���N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;			// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;			// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;		// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("DefWindowProc");					// �E�B���h�E�N���X����"DefWindowProc".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = NULL;									// ���j���[�͂Ȃ�.
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("DefWindowProc"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("DefWindowProc"), _T("DefWindowProc"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"DefWindowProc"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("DefWindowProc"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (TRUE){	// ���TRUE(�^)��, �ȉ���break�ȊO�ł͔����Ȃ�.

		// �E�B���h�E���b�Z�[�W�̎擾
		GetMessage(&msg, NULL, 0, 0);	// GetMessage�ŃE�B���h�E���b�Z�[�W���擾.
		if (msg.message == WM_NCLBUTTONDOWN && msg.wParam == HTCLOSE){	// ����, �E�B���h�E���b�Z�[�W��WM_NCLBUTTONDOWN(��N���C�A���g�̈�Ń}�E�X�̍��{�^���������ꂽ)����HTCLOSE(����{�^����)�̂Ƃ�.

			// ���b�Z�[�W���[�v�̏I��
			break;	// break�Ń��b�Z�[�W���[�v�𔲂���.

		}

		// �E�B���h�E���b�Z�[�W�̑��o
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

	}

	// �E�B���h�E�̔j��
	DestroyWindow(hWnd);	// DestroyWindow�ŃE�B���h�E��j��.

	// �v���O�����̏I��
	return 0;

}

// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// static�ϐ��̐錾
	// WindowProc�ŕԂ��߂�l�̃p�^�[��iPattern.
	// 1: WM_CREATE, ����ȊO, �Ƃ���DefWindowProc.
	// 2: WM_CREATE��0, ����ȊO��DefWindowProc.
	// 3: WM_CREATE��DefWindowProc, ����ȊO��0.
	// 4: WM_CREATE, ����ȊO, �Ƃ���0.
	static int iPattern;	// ��L�p�^�[���̒l���i�[����static��int�^�ϐ�iPattern.(�����l��static�Ȃ̂�0.)

	// �p�^�[���̑I��
	if (uMsg == WM_CREATE && iPattern == 0){	// �p�^�[�������܂��Ă��Ȃ��ꍇ.
		int iRet = MessageBox(hwnd, _T("Pattern1?"), _T("DefWindowProc"), MB_YESNO | MB_ICONQUESTION);	// MB_YESNO��MessageBox��"Pattern1?"�ƕ\����, Pattern1���ǂ�����I��������.
		if (iRet == IDYES){	// "�͂�"�̂Ƃ�.
			iPattern = 1;	// iPattern��1�ɃZ�b�g.
		}
		else{	// "������"�̂Ƃ�.
			iRet = MessageBox(hwnd, _T("Pattern2?"), _T("DefWindowProc"), MB_YESNO | MB_ICONQUESTION);	// MB_YESNO��MessageBox��"Pattern2?"�ƕ\����, Pattern2���ǂ�����I��������.
			if (iRet == IDYES){	// "�͂�"�̂Ƃ�.
				iPattern = 2;	// iPattern��2�ɃZ�b�g.
			}
			else{	// "������"�̂Ƃ�.
				iRet = MessageBox(hwnd, _T("Pattern3?"), _T("DefWindowProc"), MB_YESNO | MB_ICONQUESTION);	// MB_YESNO��MessageBox��"Pattern3?"�ƕ\����, Pattern3���ǂ�����I��������.
				if (iRet == IDYES){	// "�͂�"�̂Ƃ�.
					iPattern = 3;	// iPattern��3�ɃZ�b�g.
				}
				else{	// "������"�̂Ƃ�.
					iPattern = 4;	// iPattern��4�ɃZ�b�g.
				}
			}
		}
	}

	// ���b�Z�[�W�̏���
	if (iPattern == 1){	// iPattern��1�̂Ƃ�.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// ���DefWindowProc�̖߂�l��Ԃ�.
	}
	else if (iPattern == 2){	// iPattern��2�̂Ƃ�.
		if (uMsg == WM_CREATE){	// WM_CREATE�̂Ƃ�.
			return 0;	// 0��Ԃ�.
		}
		else{	// ����ȊO.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�̖߂�l��Ԃ�.
		}
	}
	else if (iPattern == 3){	// iPattern��3�̂Ƃ�.
		if (uMsg == WM_CREATE){	// WM_CREATE�̂Ƃ�.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�̖߂�l��Ԃ�.
		}
		else{	// ����ȊO.
			return 0;	// 0��Ԃ�.
		}
	}
	else if (iPattern == 4){	// iPattern��4�̂Ƃ�.
		return 0;	// ���0��Ԃ�.
	}
	else{	// ����ȊO�̂Ƃ�.(iPattern��0�̂Ƃ��Ȃ�.)
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// ���DefWindowProc�̖߂�l��Ԃ�.
	}

}