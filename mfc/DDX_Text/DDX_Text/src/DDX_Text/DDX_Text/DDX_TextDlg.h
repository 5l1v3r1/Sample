// DDX_TextDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once


// CDDX_TextDlg �_�C�A���O
class CDDX_TextDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CDDX_TextDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^

// �_�C�A���O �f�[�^
	enum { IDD = IDD_DDX_TEXT_DIALOG };

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
	int m_xvEdit1;
	int m_xvEdit2;
	afx_msg void OnBnClickedButton1();
};
