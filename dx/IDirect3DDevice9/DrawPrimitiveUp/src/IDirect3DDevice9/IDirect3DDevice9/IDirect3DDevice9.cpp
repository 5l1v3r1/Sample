// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <d3d9.h>		// DirectX Graphics Direct3D 9
#include <d3dx9.h>		// Direct3DX 9(�w���p�[���[�e�B���e�B���C�u����)

// �}�N���̒�`
// �|�C���^����p�}�N��SAFE_RELEASE
#define SAFE_RELEASE(p) { if (p) { (p)->Release(); (p)=NULL; } }

// ���_�̒�`
typedef struct tagVertex{	// ���_tagVertex�̒�`.
	float x;		// ���_���Wx
	float y;		// ���_���Wy
	float z;		// ���_���Wz
	float rhw;		// ���Z��
	DWORD color;	// 32bit�J���[
	float u;		// �e�N�X�`�����Wu
	float v;		// �e�N�X�`�����Wv
} Vertex;	// tagVertex��Vertex�Ƃ���.

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o���N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){
 
	// �ϐ��̐錾
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.
	int lCount = 0;				// �E�B���h�E���b�Z�[�W�����Ȃ��������̉񐔂�ێ�����int�^�ϐ�lCount�̏����l��0�Ƃ���.
	HDC hDC = NULL;				// ���̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC��NULL�ɏ�����.
	int iPhase = 0;				// �t�F�[�Y��\��int�^�ϐ�iPhase��0�ɏ�����.
	HRESULT hResult = S_FALSE;	// ���ʂ��i�[����HRESULT�^�ϐ�hResult��S_FALSE�ɏ�����.
	
	LPDIRECT3D9 lpD3D = NULL;				// IDirect3D9�I�u�W�F�N�g�|�C���^lpD3D��NULL�ɏ�����.
	D3DDISPLAYMODE d3ddm;					// D3DDISPLAYMODE�^d3ddm.
	D3DPRESENT_PARAMETERS d3dpp;			// D3DPRESENT_PARAMETERS�^d3dpp.
	LPDIRECT3DDEVICE9 lpD3DDevice = NULL;	// IDirect3DDevice9�I�u�W�F�N�g�|�C���^lpD3DDevice��NULL�ɏ�����.
	LPDIRECT3DTEXTURE9 lpD3DTexture = NULL;	// IDirect3DDevice9�I�u�W�F�N�g�|�C���^lpD3DTexture��NULL�ɏ�����.
	Vertex vertex[4];						// Vertex�^�z��vertex.(�v�f��4)

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("IDirect3DDevice9");				// �E�B���h�E�N���X����"IDirect3DDevice9".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("IDirect3DDevice9"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)
 
	}
 
	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("IDirect3DDevice9"), _T("IDirect3DDevice9"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"IDirect3DDevice9"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.
 
		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("IDirect3DDevice9"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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

				// Direct3D�I�u�W�F�N�g�̐���
				lpD3D = Direct3DCreate9(D3D_SDK_VERSION);	// Direct3DCreate9��Direct3D�I�u�W�F�N�g�𐶐�, lpD3D�Ƀ|�C���^���i�[�����.
				if (lpD3D == NULL){	// lpD3D��NULL�Ȃ�.
					// ������.
					break;	// break�Ŕ�����.
				}

				// �f�B�X�v���C���[�h�̎擾
				ZeroMemory(&d3ddm, sizeof(d3ddm));	// ZeroMemory��d3ddm��0�ŏ�����.
				hResult = lpD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);	// lpD3D->GetAdapterDisplayMode�Ńf�B�X�v���C���[�h���擾.
				if (FAILED(hResult)){	// FAILED�Ȃ�.
					// ������.
					break;	// break�Ŕ�����.
				}

				// �v���[���e�[�V�����p�����[�^�̐ݒ�
				ZeroMemory(&d3dpp, sizeof(d3dpp));	// ZeroMemory��d3dpp��0�ŏ�����.
				d3dpp.BackBufferWidth = 640;	// ����640.
				d3dpp.BackBufferHeight = 480;	// ������480.
				d3dpp.BackBufferFormat = d3ddm.Format;	// ���݂̃f�B�X�v���C�t�H�[�}�b�g.
				d3dpp.Windowed = FALSE;	// �t���X�N���[�����[�h.
				d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// �œK�ȕ��@�������ݒ�.
				d3dpp.BackBufferCount = 1;	// �o�b�N�o�b�t�@�̐���1.

				// Direct3D�f�o�C�X�I�u�W�F�N�g�̐���
				hResult = lpD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice);	// lpD3D->CreateDevice�Ńf�o�C�X�I�u�W�F�N�g�쐬.(�`��ƒ��_�������n�[�h�E�F�A�ōs��.)
				if (FAILED(hResult)){	// FAILED�Ȃ�.
					hResult = lpD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice);	// lpD3D->CreateDevice�Ńf�o�C�X�I�u�W�F�N�g�쐬.(�`����n�[�h�E�F�A, ���_������CPU�ōs��.)
					if (FAILED(hResult)){	// FAILED�Ȃ�.
						hResult = lpD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice);	// lpD3D->CreateDevice�Ńf�o�C�X�I�u�W�F�N�g�쐬.(�`��ƒ��_������CPU�ōs��.)
						if (FAILED(hResult)){	// FAILED�Ȃ�.
							// ������.
							break;	// break�Ŕ�����.
						}
					}
				}

				// test.bmp��ǂݍ����, �e�N�X�`�����쐬.
				hResult = D3DXCreateTextureFromFile(lpD3DDevice, _T("test.bmp"), &lpD3DTexture);	// D3DXCreateTextureFromFile��"test.bmp"����e�N�X�`���쐬.
				if (FAILED(hResult)){	// FAILED�Ȃ�.
					// ������.
					break;	// break�Ŕ�����.
				}
				
				// �X�v���C�g�̒��_��ݒ�.
				vertex[0].x = 640.0f;
				vertex[0].y = 0.0f;
				vertex[0].z = 0.0f;
				vertex[0].rhw = 1.0f;
				vertex[0].color = 0xffffffff;
				vertex[0].u = 1.0f;
				vertex[0].v = 0.0;
				vertex[1].x = 640.0f;
				vertex[1].y = 480.0f;
				vertex[1].z = 0.0f;
				vertex[1].rhw = 1.0f;
				vertex[1].color = 0xffffffff;
				vertex[1].u = 1.0f;
				vertex[1].v = 1.0f;
				vertex[2].x = 0.0f;
				vertex[2].y = 0.0f;
				vertex[2].z = 0.0f;
				vertex[2].rhw = 1.0f;
				vertex[2].color = 0xffffffff;
				vertex[2].u = 0.0f;
				vertex[2].v = 0.0f;
				vertex[3].x = 0.0f;
				vertex[3].y = 480.0f;
				vertex[3].z = 0.0f;
				vertex[3].rhw = 1.0f;
				vertex[3].color = 0xffffffff;
				vertex[3].u = 0.0f;
				vertex[3].v = 1.0f;

				// ���[�v�����Ɉڍs.
				iPhase = 1;	// iPhase��1�ɂ���, ���[�v�����Ɉڍs.

			}
			else{	// ���[�v����(iPhase == 1)
				
				// ESC�L�[�������ꂽ�甲����.
				if (GetKeyState(VK_ESCAPE) & 0x80){	// GetKeyState��VK_ESCAPE�������ꂽ��.
					SendMessage(hWnd, WM_CLOSE, NULL, NULL);	// SendMessage��WM_CLOSE��hWnd�ɑ��邱�Ƃŕ���.
				}

				// �`��J�n
				hResult = lpD3DDevice->BeginScene();	// lpD3DDevice->BeginScene�ŕ`��J�n.
				if (SUCCEEDED(hResult)){	// SUCCEEDED�Ȃ�.

					// �N���A
					lpD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);	// lpD3DDevice->Clear�ŃN���A.

					// test.bmp�̃X�v���C�g�`��.
					lpD3DDevice->SetTexture(0, lpD3DTexture);	// lpD3DDevice->SetTexture�Ńe�N�X�`�����Z�b�g.
					lpD3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);	// ���_�t�H�[�}�b�g�̓`�B.
					lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex, sizeof(Vertex));	// lpD3DDevice->DrawPrimitiveUp�Ńv���~�e�B�u��`��.

					// �`��I��
					lpD3DDevice->EndScene();	// lpD3DDevice->EndScene�ŕ`��I��.

				}
				// �v���C�}���[�o�b�t�@�ɓ]��.
				lpD3DDevice->Present(NULL, NULL, NULL, NULL);	// lpD3DDevice->Present�œ]��.

			}

		}

	}

	// �I������(iPhase == 2)
	SAFE_RELEASE(lpD3DTexture);	// lpD3DTexture��SAFE_RELEASE�ŉ��.
	SAFE_RELEASE(lpD3DDevice);	// lpD3DDevice��SAFE_RELEASE�ŉ��.
	SAFE_RELEASE(lpD3D);		// lpD3D��SAFE_RELEASE�ŉ��.

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