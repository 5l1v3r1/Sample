// DDX_CheckDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once


// CDDX_CheckDlg �_�C�A���O
class CDDX_CheckDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CDDX_CheckDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^

// �_�C�A���O �f�[�^
	enum { IDD = IDD_DDX_CHECK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g


// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_xvCheck1;
	afx_msg void OnBnClickedButton1();
};
