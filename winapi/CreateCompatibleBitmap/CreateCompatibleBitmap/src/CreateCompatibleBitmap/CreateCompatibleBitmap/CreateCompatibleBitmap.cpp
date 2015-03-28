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
	wc.lpszClassName = _T("CreateCompatibleBitmap");		// �E�B���h�E�N���X����"CreateCompatibleBitmap".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CreateCompatibleBitmap"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)
 
	}
 
	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("CreateCompatibleBitmap"), _T("CreateCompatibleBitmap"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"CreateCompatibleBitmap"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.
 
		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreateCompatibleBitmap"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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

	// �E�B���h�E�v���V�[�W���S�̂Ŏg����X�^�e�B�b�N�ϐ��̐錾.
	static HBITMAP hLoadBitmap;	// ���[�h�����r�b�g�}�b�v�̃n���h�����i�[����HBITMAP�^�X�^�e�B�b�N�ϐ�hLoadBitmap.
	static HBITMAP hBackBitmap;	// �o�b�N�o�b�t�@�p�r�b�g�}�b�v�̃n���h�����i�[����HBITMAP�^�X�^�e�B�b�N�ϐ�hBackBitmap.
	static int iMode;			// �ʏ탂�[�h: 0, �_�u���o�b�t�@�����O���[�h: 1.
	static int x;				// ��`��`�悷��ʒu��x���W.
	static int y;				// ��`��`�悷��ʒu��y���W.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.
 
		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)
 
			// WM_CREATE�u���b�N
			{

				// ���̃u���b�N�̃��[�J���ϐ��̐錾�E������
				LPCREATESTRUCT lpcs;	// lParam����n���ꂽCREATESTRUCT�ւ̃|�C���^���i�[����lpcs.
				int iRet;				// MessageBox�̖߂�l���i�[����int�^�ϐ�iRet.
				HDC hDC = NULL;			// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC��NULL�ɏ�����.(�݊��r�b�g�}�b�v�쐬�ɕK�v.)

				// lParam��lpcs�ɓn��.
				lpcs = (LPCREATESTRUCT)lParam; // lParam��LPCREATESTRUCT�ɃL���X�g����lpcs�Ɋi�[.

				// �ʏ탂�[�h���_�u���o�b�t�@�����O���[�h����I��.
				iRet = MessageBox(hwnd, _T("Use DoubleBufferingMode?"), _T("CreateCompatibleBitmap"), MB_YESNO | MB_ICONQUESTION);	// MessageBox�Ń_�u���o�b�t�@�����O���[�h���g�����ǂ����̃��b�Z�[�W�{�b�N�X��\��.
				if (iRet == IDYES){	// "�͂�"��I�������ꍇ.

					// �`�惂�[�h���_�u���o�b�t�@�����O���[�h�ɃZ�b�g.
					iMode = 1;	// iMode���_�u���o�b�t�@�����O���[�h( = 1)�ɂ���.

					// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾.
					hDC = GetDC(hwnd);	// GetDC�ŃE�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾��, hDC�Ɋi�[.

					// �o�b�N�o�b�t�@�p�r�b�g�}�b�v�𐶐�.
					hBackBitmap = (HBITMAP)CreateCompatibleBitmap(hDC, 640, 480);	// CreateCompatibleBitmap�ŃT�C�Y(640, 480)��hDC�ƌ݊����̂���r�b�g�}�b�vhBackBitmap���쐬.

					// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�����.
					ReleaseDC(hwnd, hDC);	// ReleaseDC��hDC�����.
					hDC = NULL;	// hDC��NULL�ɂ���.

				}

				// �r�b�g�}�b�v�̃��[�h
				hLoadBitmap = (HBITMAP)LoadImage(lpcs->hInstance, _T("test.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImage��"test.bmp"�����[�h��, �߂�l�̃r�b�g�}�b�v�n���h����hLoadBitmap�Ɋi�[����.
				if (hLoadBitmap == NULL){	// hLoadBitmap��NULL�Ȃ烍�[�h���s.

					// �G���[����
					MessageBox(hwnd, _T("LoadImage failed!"), _T("CreateCompatibleBitmap"), MB_OK | MB_ICONHAND);	// MessageBox��"LoadImage failed!"�ƃG���[���b�Z�[�W��\��.
					if (iMode == 1){	// �_�u���o�b�t�@�����O���[�h�̏ꍇ.
						if (hBackBitmap != NULL){	// �o�b�N�o�b�t�@�p�r�b�g�}�b�v���j������Ă��Ȃ��ꍇ.
							DeleteObject(hBackBitmap);	// DeleteObject��hBackBitmap��j��.
							hBackBitmap = NULL;	// hBackBitmap��NULL�ɂ��Ă���.
						}
					}
					return -1;	// �ُ�I���Ȃ̂�-1��Ԃ���, �E�B���h�E�������s�Ƃ���.

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

				// �_�u���o�b�t�@�����O���[�h�Ȃ�o�b�N�o�b�t�@�̏I������.
				if (iMode == 1){	// �_�u���o�b�t�@�����O���[�h�̏ꍇ.
					if (hBackBitmap != NULL){	// �o�b�N�o�b�t�@�p�r�b�g�}�b�v���j������Ă��Ȃ��ꍇ.
						DeleteObject(hBackBitmap);	// DeleteObject��hBackBitmap��j��.
						hBackBitmap = NULL;	// hBackBitmap��NULL�ɂ��Ă���.
					}
				}

				// ���[�h�����r�b�g�}�b�v�̏I������
				if (hLoadBitmap != NULL){	// hLoadBitmap��NULL�łȂ��ꍇ.(���[�h�����܂܂̏�Ԃ̏ꍇ.)

					// ���[�h�����r�b�g�}�b�v�̔j��
					DeleteObject(hLoadBitmap);	// DeleteObject��hLoadBitmap�̔j��.
					hLoadBitmap = NULL;	// hLoadBitmap��NULL�ɂ��Ă���.

				}

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
				HDC hDC;				// �f�o�C�X�R���e�L�X�g�n���h�����i�[����HDC�^�ϐ�hDC.
				PAINTSTRUCT ps;			// �y�C���g�����Ǘ�����PAINTSTRUCT�\���̌^�̕ϐ�ps.
				HDC	hLoadMemDC;			// �E�B���h�E�f�o�C�X�R���e�L�X�g�ƌ݊����̂��郍�[�h�����r�b�g�}�b�v�p�������f�o�C�X�R���e�L�X�g�n���h�����i�[����HDC�^�ϐ�hLoadMemDC.
				HDC hBackMemDC;			// �E�B���h�E�f�o�C�X�R���e�L�X�g�ƌ݊����̂���o�b�N�o�b�t�@�p�������f�o�C�X�R���e�L�X�g�n���h�����i�[����HDC�^�ϐ�hBackMemDC.
				HBITMAP hOldLoadBitmap;	// hLoadMemDC��SelectObject�����܂őI�����Ă����Â��r�b�g�}�b�v�̃n���h��hOldLoadBitmap.
				HBITMAP	hOldBackBitmap;	// hBackMemDC��SelectObject�����܂őI�����Ă����Â��r�b�g�}�b�v�̃n���h��hOldBackBitmap.

				// �E�B���h�E�̕`��J�n
				hDC = BeginPaint(hwnd, &ps);	// BeginPaint�ł��̃E�B���h�E�̕`��̏���������. �߂�l�ɂ̓f�o�C�X�R���e�L�X�g�n���h�����Ԃ�̂�, hDC�Ɋi�[.
				
				// �������f�o�C�X�R���e�L�X�g�̐���
				hLoadMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDC�ŃE�B���h�E�̃f�o�C�X�R���e�L�X�ghDC�ƌ݊����̂��郁�����f�o�C�X�R���e�L�X�ghLoadMemDC�𐶐�.
				if (iMode == 1){	// �_�u���o�b�t�@�����O���[�h�̏ꍇ.
					hBackMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDC�ŃE�B���h�E�̃f�o�C�X�R���e�L�X�ghDC�ƌ݊����̂��郁�����f�o�C�X�R���e�L�X�ghBackMemDC�𐶐�.
				}

				// �f�o�C�X�R���e�L�X�g�̑I��.
				hOldLoadBitmap = (HBITMAP)SelectObject(hLoadMemDC, hLoadBitmap);	// SelectObject��hLoadMemDC��hLoadBitmap��I��.(���[�h�p�������f�o�C�X�R���e�L�X�g�̓��[�h�p�r�b�g�}�b�v.)
				if (iMode == 1){	// �_�u���o�b�t�@�����O���[�h�̏ꍇ.
					hOldBackBitmap = (HBITMAP)SelectObject(hBackMemDC, hBackBitmap);	// SelectObject��hBackMemDC��hBackBitmap��I��.(�o�b�N�o�b�t�@�p�������f�o�C�X�R���e�L�X�g�̓o�b�N�o�b�t�@�p�r�b�g�}�b�v.)
				}

				// BitBlt��Rectangle�ɂ��_�u���o�b�t�@�����O.
				if (iMode == 1){	// �_�u���o�b�t�@�����O���[�h�̏ꍇ.
					BitBlt(hBackMemDC, 0, 0, 640, 480, hLoadMemDC, 0, 0, SRCCOPY);	// BitBlt��hLoadMemDC��hBackMemDC�ɓ]��.(1���ڂ͔w�i�Ƃ���"test.bmp"�̃s�N�Z������o�b�N�o�b�t�@�ɓ]��.)
					Rectangle(hBackMemDC, x, y, x + 100, y + 100);	// Rectangle�ŋ�`��(x, y)��hBackMemDC�ɕ`��.(2���ڂ͓����I�u�W�F�N�g�Ƃ��ċ�`��`��.)
					BitBlt(hDC, 0, 0, 640, 480, hBackMemDC, 0, 0, SRCCOPY);	// hDC��hBackMemDC�̓��e���R�s�[.
				}
				else{	// �ʏ�`��.
					BitBlt(hDC, 0, 0, 640, 480, hLoadMemDC, 0, 0, SRCCOPY);	// BitBlt��hLoadMemDC��hDC�ɓ]��.
					Rectangle(hDC, x, y, x + 100, y + 100);	// Rectangle�ŋ�`��(x, y)��hDC�ɕ`��.
				}

				// �r�b�g�}�b�v�̏�Ԃ�߂�.
				SelectObject(hLoadMemDC, hOldLoadBitmap);	// hLoadMemDC�Ɍ���hOldLoadBitmap�ɖ߂��悤�ɑI��������.
				if (iMode == 1){	// �_�u���o�b�t�@�����O���[�h�̏ꍇ.
					SelectObject(hBackMemDC, hOldBackBitmap);	// hBackMemDC�Ɍ���hOldBackBitmap�ɖ߂��悤�ɑI��������.
				}

				// �������f�o�C�X�R���e�L�X�g�̔j��
				DeleteDC(hLoadMemDC);	// DeleteDC��hLoadMemDC��j��.
				if (iMode == 1){	// �_�u���o�b�t�@�����O���[�h�̏ꍇ.
					DeleteDC(hBackMemDC);	// DeleteDC��hBackMemDC��j��.
				}

				// �E�B���h�E�̕`��I��
				EndPaint(hwnd, &ps);	// EndPaint�ł��̃E�B���h�E�̕`�揈�����I������.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �L�[�{�[�h�̔C�ӂ̃L�[�������ꂽ��.
		case WM_KEYDOWN:	// �L�[�{�[�h�̔C�ӂ̃L�[�������ꂽ��.(uMsg��WM_KEYDOWN�̎�.)

			// WM_KEYDOWN�u���b�N
			{

				// ��`��x���W��y���W��1���₷.
				x += 1;	// x��1���₷.
				y += 1;	// y��1���₷.
				InvalidateRect(hwnd, NULL, FALSE);	// ��ʂ̍X�V��v��.

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