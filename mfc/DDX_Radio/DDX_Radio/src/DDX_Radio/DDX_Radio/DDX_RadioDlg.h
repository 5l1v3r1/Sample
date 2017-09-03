// DDX_RadioDlg.h : ヘッダー ファイル
//

#pragma once


// CDDX_RadioDlg ダイアログ
class CDDX_RadioDlg : public CDialog
{
// コンストラクション
public:
	CDDX_RadioDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_DDX_RADIO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_xvRadio1;
	afx_msg void OnBnClickedButton1();
};
