// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <ddraw.h>		// DirectDraw

// �}�N���̒�`
// �|�C���^����p�}�N��SAFE_RELEASE
#define SAFE_RELEASE(p) { if (p) { (p)->Release(); (p)=NULL; } }

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o���N�֐�WindowProc.
 
// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){
 
	// �ϐ��̐錾
	HWND hWnd;									// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;									// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;								// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.
	int lCount = 0;								// �E�B���h�E���b�Z�[�W�����Ȃ��������̉񐔂�ێ�����int�^�ϐ�lCount�̏����l��0�Ƃ���.
	HDC hDC = NULL;								// ���̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC��NULL�ɏ�����.
	int iPhase = 0;								// �t�F�[�Y��\��int�^�ϐ�iPhase��0�ɏ�����.
	HRESULT hResult = S_FALSE;					// ���ʂ��i�[����HRESULT�^�ϐ�hResult��S_FALSE�ɏ�����.
	LPDIRECTDRAW7 lpDD = NULL;					// IDirectDraw7�I�u�W�F�N�g�|�C���^lpDD��NULL�ɏ�����.
	LPDIRECTDRAWCLIPPER lpClip = NULL;			// �N���b�p�[lpClip��NULL�ɏ�����.
	DDSURFACEDESC2 ddsd;						// �T�[�t�F�C�X�f�B�X�N���v�^ddsd.
	LPDIRECTDRAWSURFACE7 lpDDSPrimary = NULL;	// �v���C�}���T�[�t�F�C�XlpDDSPrimary��NULL�ɏ�����.
	HBITMAP hBitmap = NULL;						// HBITMAP�^hBitmap��NULL�ɏ�����.
	HDC hMemDC = NULL;							// HDC�^�������f�o�C�X�R���e�L�X�ghMemDC��NULL�ɏ�����.
	HBITMAP hOldBitmap = NULL;					// HBTIMAP�^hOldBitmap��NULL�ɏ�����.
	BITMAP bitmap = {0};						// BITMAP�^bitmap��0�ŏ�����.
	LPDIRECTDRAWSURFACE7 lpDDSBitmap = NULL;	// �r�b�g�}�b�v��`�悵���T�[�t�F�C�XlpDDSBitmap��NULL�ɏ�����.
	DDSURFACEDESC2 ddsdBitmap;					// lpDDSBitmap�̃T�[�t�F�C�X�f�B�X�N���v�^ddsdBitmap.
	HDC hDDSBitmapDC = NULL;					// lpDDSBitmap�̃f�o�C�X�R���e�L�X�ghDDSBitmapDC��NULL�ɏ�����.
	RECT rc = {0};								// RECT�^rc��0�ŏ�����.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("IDirectDrawSurface7");			// �E�B���h�E�N���X����"IDirectDrawSurface7".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("IDirectDrawSurface7"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)
 
	}
 
	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("IDirectDrawSurface7"), _T("IDirectDrawSurface7"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"IDirectDrawSurface7"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.
 
		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("IDirectDrawSurface7"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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

			// 0�Ƀ��Z�b�g.
			lCount = 0;	// lCount��0�Ƀ��Z�b�g.

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

			// lCount����.
			lCount++;	// lCount��1���₷.

			// ���C������
			if (iPhase == 0){	// ������(iPhase == 0)

				// DirectDraw�I�u�W�F�N�g�̐���
				hResult = DirectDrawCreateEx(NULL, (LPVOID *)&lpDD, IID_IDirectDraw7, NULL);	// DirectDrawCreateEx��DirectDraw�I�u�W�F�N�g�𐶐�, lpDD�Ƀ|�C���^���i�[�����.
				if (FAILED(hResult)){	// FAILED�Ȃ�.
					// ������.
					break;	// break�Ŕ�����.
				}

				// �������x���ݒ�
				hResult = lpDD->SetCooperativeLevel(hWnd, DDSCL_NORMAL);	// ����͒ʏ�̃E�B���h�E�A�v���P�[�V�����Ƃ���̂�, lpDD->SetCooperativeLevel�ł�DDSCL_NORMAL���w��.
				if (FAILED(hResult)){	// FAILED�Ȃ�.
					// ������.
					break;	// break�Ŕ�����.
				}

				// �N���b�p�[�̍쐬
				hResult = lpDD->CreateClipper(NULL, &lpClip, NULL);	// lpDD->CreateClipper�ŃN���b�p�[���쐬, lpClip�Ƀ|�C���^���i�[�����.
				if (FAILED(hResult)){	// FAILED�Ȃ�.
					// ������.
					break;	// break�Ŕ�����.
				}
				lpClip->SetHWnd(0, hWnd);	// lpClip->SetHWnd�ŃE�B���h�E�n���h���̃Z�b�g.

				// �v���C�}���T�[�t�F�C�X�f�B�X�N���v�^�ݒ�
				ZeroMemory(&ddsd, sizeof(ddsd));	// ZeroMemory��ddsd��0�Ŗ��߂ď�����.
				ddsd.dwSize = sizeof(ddsd);	// �T�C�Y�ݒ�
				ddsd.dwFlags = DDSD_CAPS;	// �t���O��DDSD_CAPS�̂�.
				ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;	// �v���C�}���T�[�t�F�C�X�̂�.

				// �v���C�}���T�[�t�F�C�X�̍쐬
				hResult = lpDD->CreateSurface(&ddsd, &lpDDSPrimary, NULL);	// lpDD->CreateSurface�Ńv���C�}���T�[�t�F�C�X���쐬.
				if (FAILED(hResult)){	// FAILED�Ȃ�.
					// ������.
					break;	// break�Ŕ�����.
				}

				// �v���C�}���T�[�t�F�C�X�ɃN���b�p�[���Z�b�g.
				lpDDSPrimary->SetClipper(lpClip);	// lpDDSPrimary->SetClipper��lpClip���Z�b�g.

				// �r�b�g�}�b�v�̃��[�h
				hBitmap = (HBITMAP)LoadImage(hInstance, _T("test.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImage��"test.bmp"�����[�h.
				if (hBitmap == NULL){	// NULL�Ȃ�.
					// ������.
					break;	// break�Ŕ�����.
				}

				// �������f�o�C�X�R���e�L�X�g�̍쐬.
				hMemDC = CreateCompatibleDC(NULL);	// CreateCompatibleDC�Ń������f�o�C�X�R���e�L�X�g�쐬.
				if (hMemDC == NULL){	// NULL�Ȃ�.
					// ������.
					break;	// break�Ŕ�����.
				}

				// �������f�o�C�X�R���e�L�X�g�ƃr�b�g�}�b�v�̕R�t��.
				hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);	// SelectObject��hMemDC��hBitmap��R�t��.

				// �r�b�g�}�b�v���̎擾.
				GetObject(hBitmap, sizeof(BITMAP), &bitmap);	// GetObject�Ńr�b�g�}�b�v�����擾��, bitmap�Ɋi�[.

				// �r�b�g�}�b�v�T�[�t�F�C�X�f�B�X�N���v�^�ݒ�
				ZeroMemory(&ddsdBitmap, sizeof(ddsdBitmap));	// ZeroMemory��ddsdBitmap��0�Ŗ��߂ď�����.
				ddsdBitmap.dwSize = sizeof(ddsdBitmap);	// �T�C�Y�ݒ�
				ddsdBitmap.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;	// �t���O��DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT.
				ddsdBitmap.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;	// �V�X�e���������ŃI�t�X�N���[��.
				ddsdBitmap.dwWidth = bitmap.bmWidth;	// �r�b�g�}�b�v�̕����Z�b�g.
				ddsdBitmap.dwHeight = bitmap.bmHeight;	// �r�b�g�}�b�v�̍������Z�b�g.

				// �r�b�g�}�b�v�T�[�t�F�C�X�̍쐬
				hResult = lpDD->CreateSurface(&ddsdBitmap, &lpDDSBitmap, NULL);	// lpDD->CreateSurface�Ńr�b�g�}�b�v�T�[�t�F�C�X���쐬.
				if (FAILED(hResult)){	// FAILED�Ȃ�.
					// ������.
					break;	// break�Ŕ�����.
				}

				// �r�b�g�}�b�v�T�[�t�F�C�X�̃f�o�C�X�R���e�L�X�g���擾.
				lpDDSBitmap->GetDC(&hDDSBitmapDC);	// lpDDSBitmap->GetDC�Ńf�o�C�X�R���e�L�X�g���擾��, hDDSBitmapDC�Ɋi�[.

				// �������f�o�C�X�R���e�L�X�g����r�b�g�}�b�v�T�[�t�F�C�X�֓]��.
				BitBlt(hDDSBitmapDC, 0, 0, ddsdBitmap.dwWidth, ddsdBitmap.dwHeight, hMemDC, 0, 0, SRCCOPY);	// BitBlt��hMemDC����hDDSBitmapDC�ɓ]��.

				// �r�b�g�}�b�v�T�[�t�F�C�X�̃f�o�C�X�R���e�L�X�g�����.
				lpDDSBitmap->ReleaseDC(hDDSBitmapDC);	// lpDDSBitmap->ReleaseDC�Ńf�o�C�X�R���e�L�X�ghDDSBitmapDC�����.
				hDDSBitmapDC = NULL;	// hDDSBitmapDC��NULL���Z�b�g.

				// ���[�v�����Ɉڍs.
				iPhase = 1;	// iPhase��1�ɂ���, ���[�v�����Ɉڍs.

			}
			else{	// ���[�v����(iPhase == 1)

				// �T�[�t�F�C�X�̕`��
				GetWindowRect(hWnd, &rc);	// �E�B���h�E��`���擾.
				rc.left += GetSystemMetrics(SM_CXSIZEFRAME);	// ���E���̕���������.
				rc.top += GetSystemMetrics(SM_CYSIZEFRAME) + GetSystemMetrics(SM_CYCAPTION);	// ���E���ƃ^�C�g���o�[�̕���������.
				rc.right = rc.left + ddsdBitmap.dwWidth;	// rc.left��ddsdBitmap.dwWidth�̕���������.
				rc.bottom = rc.top + ddsdBitmap.dwHeight;	// rc.top��ddsdBitmap.dwHeight�̕���������.
				lpDDSPrimary->Blt(&rc, lpDDSBitmap, NULL, DDBLT_WAIT, NULL);	// lpDDSPrimary->Blt��lpDDSPrimary��lpDDSBitmap��`��.
				
			}

		}

	}

	// �I������(iPhase == 2)
	if (hOldBitmap != NULL){	// NULL�łȂ����.
		SelectObject(hMemDC, hOldBitmap);	// ���ɖ߂�.
		hOldBitmap = NULL;	// hOldBitmap��NULL���Z�b�g.
	}
	if (hMemDC != NULL){	// NULL�łȂ����.
		DeleteDC(hMemDC);	// DeleteDC��hMemDC���폜.
		hMemDC = NULL;		// hMemDC��NULL���Z�b�g.
	}
	if (hBitmap != NULL){	// NULL�łȂ����.
		DeleteObject(hBitmap);	// DeleteObject��hBitmap���폜.
		hBitmap = NULL;		// hBitmap��NULL���Z�b�g.
	}
	SAFE_RELEASE(lpDDSBitmap);	// lpDDSBitmap��SAFE_RELEASE�ŉ��.
	SAFE_RELEASE(lpDDSPrimary);	// lpDDSPrimary��SAFE_RELEASE�ŉ��.
	SAFE_RELEASE(lpClip);	// lpClip��SAFE_RELEASE�ŉ��.
	SAFE_RELEASE(lpDD);	// lpDD��SAFE_RELEASE�ŉ��.

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

		// ��L�ȊO�̎�.
		default:	// ��L�ȊO�̒l�̎��̊��菈��.
 
			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.
 
	}
 
	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂�DefWindowProc�Ɋ���̏�����C����.

}