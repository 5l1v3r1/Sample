// CWndDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once


// CWndDlg �_�C�A���O
class CWndDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CWndDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^

// �_�C�A���O �f�[�^
	enum { IDD = IDD_CWND_DIALOG };

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
	CString m_xvEdit1;
	afx_msg void OnBnClickedButton1();
};