// �w�b�_�t�@�C���̃C���N���[�h
#include <afxwin.h>	// MFC�W��
#include <tchar.h>	// TCHAR�^

// CWinApp�̔h���N���XCWinApp_�̒�`
class CWinApp_ : public CWinApp{	// �A�v���P�[�V�����N���X

	// private�����o
	private:

		// private�����o�ϐ�
		BOOL m_bInitState;	// InitInstance�ɐ���������TRUE, ���s������FALSE.

	// public�����o
	public:

		// public�����o�֐�
		// ���N���X�̃����o�֐��̃I�[�o�[���C�h
		virtual BOOL InitInstance();	// �C���X�^���X�̏���������
		virtual int Run();				// ���b�Z�[�W���[�v	
		virtual int ExitInstance();		// �C���X�^���X�̏I������

};

// �A�v���P�[�V�����C���X�^���X�̐錾
CWinApp_ theApp;	// CWinApp_�̃C���X�^���XtheApp��錾.