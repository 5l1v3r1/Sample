// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <cstdio>		// �W�����o��
#include <tchar.h>		// TCHAR�Ή�

// �O������Q�Ƃł���֐��̐錾.
extern "C" __declspec(dllexport) void DllFunc(void);	// �֐�DllFunc

// DllMain�֐��̒�`
int WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){	// DLL�̓ǂݍ��ݎ��������ɌĂ΂��G���g���|�C���g.

	// DllMain���Ăяo�����R��\���}�N�����i�[���ꂽfdwReason���ƂɐU�蕪����.
	switch (fdwReason){	// fdwReason���Ƃ�switch-case���ŕ���.

		// �v���Z�X���A�^�b�`���ꂽ��.
		case DLL_PROCESS_ATTACH:	// DLL_PROCESS_ATTACH�̎�.

			// DLL_PROCESS_ATTACH�u���b�N
			{

				// "DLL_PROCESS_ATTACH\n"���o��.
				_tprintf(_T("DLL_PROCESS_ATTACH\n"));	// _tprintf��"DLL_PROCESS_ATTACH\n"�Əo��.

			}

			// ������.
			break;	// break�Ŕ�����.

		// �v���Z�X���f�^�b�`���ꂽ��.
		case DLL_PROCESS_DETACH:	// DLL_PROCESS_DETACH�̎�.

			// DLL_PROCESS_DETACH�u���b�N
			{

				// "DLL_PROCESS_DETACH\n"���o��.
				_tprintf(_T("DLL_PROCESS_DETACH\n"));	// _tprintf��"DLL_PROCESS_DETACH\n"�Əo��.

			}

			// ������.
			break;	// break�Ŕ�����.

		// �X���b�h���A�^�b�`���ꂽ��.
		case DLL_THREAD_ATTACH:	// DLL_THREAD_ATTACH�̎�.
			
			// DLL_THREAD_ATTACH�u���b�N
			{

				// "DLL_THREAD_ATTACH\n"���o��.
				_tprintf(_T("DLL_THREAD_ATTACH\n"));	// _tprintf��"DLL_THREAD_ATTACH\n"�Əo��.

			}

			// ������.
			break;	// break�Ŕ�����.

		// �X���b�h���f�^�b�`���ꂽ��.
		case DLL_THREAD_DETACH:	// DLL_THREAD_DETACH�̎�.

			// DLL_THREAD_DETACH�u���b�N
			{

				// "DLL_THREAD_DETACH\n"���o��.
				_tprintf(_T("DLL_THREAD_DETACH\n"));	// _tprintf��"DLL_THREAD_DETACH\n"�Əo��.

			}

			// ������.
			break;	// break�Ŕ�����.

		// ����ȊO.
		default:

			// ������.
			break;	// break�Ŕ�����.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// �����DllMain�̏����𐬌��Ƃ���̂�TRUE.

}

// �֐�DllFunc�̒�`.
extern "C" __declspec(dllexport) void DllFunc(void){	// �O������Ăяo����֐�DllFunc.

	// "DllFunc 1!\n"�Əo��.
	_tprintf(_T("DllFunc 1!\n"));	// _tprintf��"DllFunc 1!\n"�Əo��.

}