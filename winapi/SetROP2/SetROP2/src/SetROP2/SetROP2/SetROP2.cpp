// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��̐錾
	HWND hWnd;			// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;			// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;		// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("SetROP2");						// �E�B���h�E�N���X����"SetROP2".
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
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("SetROP2"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("SetROP2"), _T("SetROP2"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"SetROP2"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL) {	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("SetROP2"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.

		// �E�B���h�E���b�Z�[�W�̑��o
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

	}

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �X�^�e�B�b�N�ϐ��̐錾
	static HPEN hPen1;	// HPEN�^�X�^�e�B�b�N�ϐ�hPen1.
	static HBRUSH hBrush1;	// HBRUSH�^�X�^�e�B�b�N�ϐ�hBrush1.
	static HPEN hPen2;	// HPEN�^�X�^�e�B�b�N�ϐ�hPen2.
	static HBRUSH hBrush2;	// HBRUSH�^�X�^�e�B�b�N�ϐ�hBrush2.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg) {	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// �Ԃ��y���ƐԂ��u���V�̍쐬.
				hPen1 = CreatePen(PS_SOLID, 1, RGB(0xFF, 0x00, 0x00));	// �Ԃ��y��hPen1.
				hBrush1 = CreateSolidBrush(RGB(0xFF, 0x00, 0x00));	// �Ԃ̃u���VhBrush1.

				// ���y���Ɛ��u���V�̍쐬.
				hPen2 = CreatePen(PS_SOLID, 1, RGB(0x00, 0x00, 0xFF));	// ���y��hPen2.
				hBrush2 = CreateSolidBrush(RGB(0x00, 0x00, 0xFF));	// �̃u���VhBrush2.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// ���y���Ɛ��u���V�̔j��.
				DeleteObject(hPen2);	// ���y��hPen2���폜.
				DeleteObject(hBrush2);	// ���u���VhBrush2���폜.

				// �Ԃ��y���ƐԂ��u���V�̔j��.
				DeleteObject(hPen1);	// �Ԃ��y��hPen1���폜.
				DeleteObject(hBrush1);	// �Ԃ��u���VhBrush1���폜.

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.(����ƃ��b�Z�[�W���[�v��GetMessage�̖߂�l��0�ɂȂ�̂�, ���b�Z�[�W���[�v���甲����.)

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ��ʂ̕`���v�����ꂽ��.
		case WM_PAINT:		// ��ʂ̕`���v�����ꂽ��.(uMsg��WM_PAINT�̎�.)

			// WM_PAINT�u���b�N
			{

				// ���̃u���b�N�̃��[�J���ϐ��E�z��̐錾�Ə�����.
				HDC hDC;		// �f�o�C�X�R���e�L�X�g�n���h�����i�[����HDC�^�ϐ�hDC.
				PAINTSTRUCT ps;	// �y�C���g�����Ǘ�����PAINTSTRUCT�\���̌^�̕ϐ�ps.
				HPEN hOldPen;		// SelectObject�����܂Ŏg���Ă����Â��y���̃n���h��hOldPen.
				HBRUSH hOldBrush;	// SelectObject�����܂Ŏg���Ă����Â��u���V�̃n���h��hOldBrush.

				// �E�B���h�E�̕`��J�n
				hDC = BeginPaint(hwnd, &ps);	// BeginPaint�ł��̃E�B���h�E�̕`��̏���������. �߂�l�ɂ̓f�o�C�X�R���e�L�X�g�n���h�����Ԃ�̂�, hDC�Ɋi�[.

				// �w�i�ƕ`��F�������Ȃ甽�].
				SetROP2(hDC, R2_XORPEN);	// SetROP2��R2_XORPEN���[�h.

				// 2�̔�����`��`��.
				Rectangle(hDC, 10, 10, 100, 100);	// ����
				Rectangle(hDC, 60, 60, 160, 160);	// �E��

				// �V�K�ɍ쐬�����Ԃ��y���ƐԂ��u���V��I��.
				hOldPen = (HPEN)SelectObject(hDC, hPen1);	// hPen1��I��.
				hOldBrush = (HBRUSH)SelectObject(hDC, hBrush1);	// hBrush1��I��.

				// �Ԃ���`��`��.
				Rectangle(hDC, 300, 300, 400, 400);	// Rectangle�ŋ�`��`��.

				// �V�K�ɍ쐬�������y���Ɛ��u���V��I��.
				(HPEN)SelectObject(hDC, hPen2);	// hPen2��I��.
				(HBRUSH)SelectObject(hDC, hBrush2);	// hBrush2��I��.

				// ����`��`��.
				Rectangle(hDC, 350, 350, 450, 450);	// Rectangle�ŋ�`��`��.

				// ���ɖ߂�.
				(HPEN)SelectObject(hDC, hOldPen);	// hOldPen��I��.
				(HBRUSH)SelectObject(hDC, hOldBrush);	// hOldBrush��I��.

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