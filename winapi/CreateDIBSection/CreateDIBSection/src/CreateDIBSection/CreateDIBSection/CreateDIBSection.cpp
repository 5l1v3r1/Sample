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
	wc.lpszClassName = _T("CreateDIBSection");				// �E�B���h�E�N���X����"CreateDIBSection".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CreateDIBSection"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("CreateDIBSection"), _T("CreateDIBSection"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"CreateDIBSection"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreateDIBSection"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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
	static HBITMAP hBackBitmap;		// �o�b�N�o�b�t�@�p�r�b�g�}�b�v�̃n���h�����i�[����HBITMAP�^�X�^�e�B�b�N�ϐ�hBackBitmap.
	static LPBYTE lpBitsPixel;		// DIB�Z�N�V�����̃s�N�Z���r�b�g��lpBitsPixel.
	static HBITMAP hDIBSection;		// DIB�Z�N�V�����̃r�b�g�}�b�v�n���h��hDIBSection.
	static HDC hBackMemDC;			// hBackBitmap�p�̃f�o�C�X�R���e�L�X�ghBackMemDC.
	static HDC hDIBSectionMemDC;	// hDIBSection�p�̃f�o�C�X�R���e�L�X�ghDIBSectionMemDC.
	static HBITMAP hOldBackBitmap;	// �I��O�̃o�b�N�o�b�t�@�r�b�g�}�b�vhOldBackBitmap.
	static HBITMAP hOldDIBSection;	// DIB�Z�N�V������I������O�̃r�b�g�}�b�vhOldDIBSection.
	static BITMAPINFO bi;			// BITMAPINFO�\���̕ϐ�bi.
	static BITMAPFILEHEADER bfh;	// BITMAPFILEHEADER�\���̕ϐ�bfh.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// ���̃u���b�N�̃��[�J���ϐ��̐錾�E������
				HDC hDC = NULL;			// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC��NULL�ɏ�����.(�݊��r�b�g�}�b�v�쐬�ɕK�v.)
				HANDLE hFile;			// �t�@�C���n���h��hFile.
				DWORD dwSize;			// �t�@�C���T�C�YdwSize.
				DWORD dwReadBytes;		// �ǂݍ��񂾒���dwReadBytes.

				// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾.
				hDC = GetDC(hwnd);	// GetDC�ŃE�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾��, hDC�Ɋi�[.

				// �o�b�N�o�b�t�@�p�r�b�g�}�b�v�𐶐�.
				hBackBitmap = (HBITMAP)CreateCompatibleBitmap(hDC, 640, 480);	// CreateCompatibleBitmap�ŃT�C�Y(640, 480)��hDC�ƌ݊����̂���r�b�g�}�b�vhBackBitmap���쐬.

				// �t�@�C�����J��
				hFile = CreateFile(_T("test.bmp"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��"test.bmp"���J����, �擾�����n���h����hFile�Ɋi�[.
				if (hFile == INVALID_HANDLE_VALUE){	// hFile��INVALID_HANDLE_VALUE�Ȃ�.

					// �G���[����
					DeleteObject(hBackBitmap);	// DeleteObject��hBackBitmap���폜.
					ReleaseDC(hwnd, hDC);	// ReleaseDC��hDC�����.
					hDC = NULL;	// hDC��NULL�ɂ���.
					return -1;	// -1��Ԃ�.

				}

				// �t�@�C���T�C�Y�̎擾.
				dwSize = GetFileSize(hFile, NULL);	// GetFileSize��"test.bmp"�̃t�@�C���T�C�Y���擾����.

				// BITMAPFILEHEADER�̓ǂݍ���.
				ReadFile(hFile, &bfh, sizeof(BITMAPFILEHEADER), &dwReadBytes, NULL);	// ReadFile��BITMAPFILEHEADER��ǂݍ���.

				// BITMAPINFOHEADER�̓ǂݍ���.(BITMAPINFO�\���̂�BITMAPINFOHEADER�̂ݓǂݍ���.)
				ReadFile(hFile, &bi, sizeof(BITMAPINFOHEADER), &dwReadBytes, NULL);	// ReadFile��BITMAPINFO�̍\���̕ϐ���BITMAPINFOHEADER�̃f�[�^�̂ݓǂݍ���.

				// DIB�Z�N�V�����̍쐬.
				hDIBSection = CreateDIBSection(hDC, &bi, DIB_RGB_COLORS, (void **)&lpBitsPixel, NULL, 0);	// CreateDIBSection��DIB�Z�N�V�������쐬.

				// �s�N�Z����̓ǂݍ���.
				ReadFile(hFile, lpBitsPixel, dwSize - bfh.bfOffBits, &dwReadBytes, NULL);	// ReadFile�Ńs�N�Z�����ǂݍ���.

				// hBackBitmap�p�̃������f�o�C�X�R���e�L�X�g���쐬.
				hBackMemDC = CreateCompatibleDC(hDC);		// CreateCompatibleDC��hBackBitmap�p�̃������f�o�C�X�R���e�L�X�g���쐬.

				// hDIBSection�p�̃������f�o�C�X�R���e�L�X�g���쐬.
				hDIBSectionMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDC��hDIBSection�p�̃������f�o�C�X�R���e�L�X�g���쐬.

				// �o�b�N�o�b�t�@�r�b�g�}�b�v�̑I��.
				hOldBackBitmap = (HBITMAP)SelectObject(hBackMemDC, hBackBitmap);		// SelectObject��hBackBitmap��I��.

				// DIB�Z�N�V�����̑I��.
				hOldDIBSection = (HBITMAP)SelectObject(hDIBSectionMemDC, hDIBSection);	// SelectObject��hDIBSection��I��.

				// ����.
				CloseHandle(hFile);	// CloseHandle��hFile�����.

				// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�����.
				ReleaseDC(hwnd, hDC);	// ReleaseDC��hDC�����.
				hDC = NULL;	// hDC��NULL�ɂ���.

				// 0��Ԃ�.
				return 0;	// return 0.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.
		
		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// ���[�J���ϐ��̐錾.
				HANDLE hFile;			// �t�@�C���n���h��hFile.
				DWORD dwBytes;			// �������݃o�C�g��.

				// ���ɖ߂�.
				SelectObject(hDIBSectionMemDC, hOldDIBSection);	// SelectObject��hOldDIBSection�ɖ߂�.

				// ���ɖ߂�.
				SelectObject(hBackMemDC, hOldBackBitmap);	// SelectObject��hOldBackBitmap�ɖ߂�.

				// �t�@�C���ɏ�������.
				hFile = CreateFile(_T("test2.bmp"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��"test2.bmp"���쐬.
				WriteFile(hFile, &bfh, sizeof(BITMAPFILEHEADER), &dwBytes, NULL);			// WriteFile��bfh����������.
				WriteFile(hFile, &bi, sizeof(BITMAPINFOHEADER), &dwBytes, NULL);			// WriteFile��bi����������.
				WriteFile(hFile, lpBitsPixel, bi.bmiHeader.biSizeImage, &dwBytes, NULL);	// WriteFile��lpBitsPixel����������.
				CloseHandle(hFile);	// ����.

				// hDIBSectionMemDC�̍폜
				if (hDIBSectionMemDC){	// hDIBSectionMemDC��NULL�łȂ���.
					DeleteDC(hDIBSectionMemDC);	// DeleteDC��hDIBSectionMemDC���폜.
					hDIBSectionMemDC = NULL;	// NULL����.
				}

				// hBackMemDC�̍폜
				if (hBackMemDC){	// hBackMemDC��NULL�łȂ���.
					DeleteDC(hBackMemDC);	// DeleteDC��hBackMemDC���폜.
					hBackMemDC = NULL;		// NULL����.
				}

				// DIB�Z�N�V�����̍폜.
				if (hDIBSection){	// hDIBSection��NULL�łȂ���.
					DeleteObject(hDIBSection);	// DeleteObject��hDIBSection���폜.
					hDIBSection = NULL;	// NULL����.
				}

				// �s�N�Z�����DIB�Z�N�V�����̍폜���Ɏ����ŉ��.
				lpBitsPixel = NULL;	// NULL�͑�����Ă���.

				// �o�b�N�o�b�t�@�p�r�b�g�}�b�v�̍폜.
				if (hBackBitmap){	// hBackBitmap��NULL�łȂ���.
					DeleteObject(hBackBitmap);	// DeleteObject��hBackBitmap���폜.
					hBackBitmap = NULL;		// NULL����.
				}

				// ���b�Z�[�W���[�v�𔲂���.
				PostQuitMessage(0);	// PostQuitMessage�Ŕ�����.

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

				// �E�B���h�E�̕`��J�n
				hDC = BeginPaint(hwnd, &ps);	// BeginPaint�ł��̃E�B���h�E�̕`��̏���������. �߂�l�ɂ̓f�o�C�X�R���e�L�X�g�n���h�����Ԃ�̂�, hDC�Ɋi�[.

				// DIB�Z�N�V�����̕`��.
				BitBlt(hBackMemDC, 0, 0, bi.bmiHeader.biWidth, bi.bmiHeader.biHeight, hDIBSectionMemDC, 0, 0, SRCCOPY);	// BitBlt��hDIBSectionMemDC��hBackMemDC�ɕ`��.
				BitBlt(hDC, 0, 0, 640, 480, hBackMemDC, 0, 0, SRCCOPY);	// BitBlt��hBackMemDC��hDC�ɕ`��.

				// �E�B���h�E�̕`��I��
				EndPaint(hwnd, &ps);	// EndPaint�ł��̃E�B���h�E�̕`�揈�����I������.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}