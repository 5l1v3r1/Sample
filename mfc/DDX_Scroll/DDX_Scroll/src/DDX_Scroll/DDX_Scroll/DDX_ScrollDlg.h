// DDX_ScrollDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once
#include "afxwin.h"


// CDDX_ScrollDlg �_�C�A���O
class CDDX_ScrollDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CDDX_ScrollDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^

// �_�C�A���O �f�[�^
	enum { IDD = IDD_DDX_SCROLL_DIALOG };

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
	CScrollBar m_xcScrollBar1;
	int m_xvScrollBar1;
	afx_msg void OnBnClickedButton1();
};
