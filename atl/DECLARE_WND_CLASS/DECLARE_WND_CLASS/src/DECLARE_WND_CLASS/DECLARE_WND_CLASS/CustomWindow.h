// �J�X�^���E�B���h�E�N���XCCustomWindow�̒�`
class CCustomWindow : public CWindowImpl<CCustomWindow>{	// CWindowImpl<CCustomWindow>�̔h���N���X�Ƃ���, CCustomWindow���`.

	// public�����o
	public:

		// �E�B���h�E�N���X���o�^�}�N��
		DECLARE_WND_CLASS(NULL);	// �}�N��DECLARE_WND_CLASS��NULL���w��.

	// private�����o
	private:

		// ���b�Z�[�}�b�v�}�N��
		BEGIN_MSG_MAP(CCustomWindow)
			MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		END_MSG_MAP()

		// �����o�֐��̒�`
		// �E�B���h�E�j�����̃C�x���g�n���h��OnDestroy
		LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled){

			// �I�����b�Z�[�W�̑��M
			PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.
			return 0;	// 0��Ԃ�.

		}

};