// CListCtrlDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CListCtrl.h"
#include "CListCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListCtrlDlg �_�C�A���O




CListCtrlDlg::CListCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CListCtrlDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CListCtrlDlg ���b�Z�[�W �n���h��

BOOL CListCtrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	// �^�C�g���p�[�ɃA�C�R���̕\��.
	CWinApp *pApp = AfxGetApp();	// AfxGetApp()��theApp�̃|�C���^�擾.
	HICON hIcon = ::LoadIcon(pApp->m_hInstance, MAKEINTRESOURCE(IDI_ICON1));	// ::LoadIcon��IDI_ICON1(icon1.ico)�����[�h, �n���h����hIcon�Ɋi�[.
	SetIcon(hIcon, TRUE);	// CWnd::SetIcon��hIcon���Z�b�g.(TRUE�Ȃ̂ő傫���A�C�R���ɃZ�b�g.)
	SetIcon(hIcon, FALSE);	// CWnd::SetIcon��hIcon���Z�b�g.(FALSE�Ȃ̂ŏ������A�C�R���ɃZ�b�g.)

	// ���X�g�R���g���[���ɃJ����(��)�w�b�_�Ɗe�A�C�e��(�s����)�}��.
	CListCtrl *pListCtrl1 = (CListCtrl *)GetDlgItem(IDC_LIST1);	// GetDlgItem�Ń��X�g�R���g���[��IDC_LIST1�̃I�u�W�F�N�g�|�C���^��pListCtrl1�Ɋi�[.((CListCtrl *)�ɃL���X�g.)
	// �J����1�̑}��.
	LVCOLUMN lvCol1;	// �J����1
	lvCol1.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;	// �z�u, �w�b�_��, �����Z�b�g.
	lvCol1.fmt = LVCFMT_LEFT;		// ����.
	lvCol1.pszText = _T("Name");	// �w�b�_����"Name".
	lvCol1.cx = 120;	// ����120.
	pListCtrl1->InsertColumn(0, &lvCol1);	// pListCtrl1->InsertColumn�ŃJ�����w�b�_��lvCol1��}��.
	// �J����2�̑}��.
	LVCOLUMN lvCol2;	// �J����2
	lvCol2.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;	// �z�u, �w�b�_��, �����Z�b�g.
	lvCol2.fmt = LVCFMT_LEFT;		// ����.
	lvCol2.pszText = _T("Age");		// �w�b�_����"Age".
	lvCol2.cx = 120;	// ����120.
	pListCtrl1->InsertColumn(1, &lvCol2);	// pListCtrl1->InsertColumn�ŃJ�����w�b�_��lvCol2��}��.
	// �J����3�̑}��.
	LVCOLUMN lvCol3;	// �J����3
	lvCol3.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;	// �z�u, �w�b�_��, �����Z�b�g.
	lvCol3.fmt = LVCFMT_LEFT;		// ����.
	lvCol3.pszText = _T("Address");		// �w�b�_����"Address".
	lvCol3.cx = 120;	// ����120.
	pListCtrl1->InsertColumn(2, &lvCol3);	// pListCtrl1->InsertColumn�ŃJ�����w�b�_��lvCol3��}��.
	// �A�C�e��1_1�`1_3�̑}��.
	LVITEM lvItem1_1;	// �A�C�e��1_1
	lvItem1_1.mask = LVIF_TEXT;	// �A�C�e���e�L�X�g�̂݃Z�b�g.
	lvItem1_1.pszText = _T("Taro");	// �A�C�e���e�L�X�g��"Taro".
	lvItem1_1.iItem = 0;	// 0�s
	lvItem1_1.iSubItem = 0;	// 0��
	pListCtrl1->InsertItem(&lvItem1_1);	// pListCtrl1->InsertItem��lvItem1_1��}��.
	LVITEM lvItem1_2;	// �A�C�e��1_2
	lvItem1_2.mask = LVIF_TEXT;	// �A�C�e���e�L�X�g�̂݃Z�b�g.
	lvItem1_2.pszText = _T("20");	// �A�C�e���e�L�X�g��"20".
	lvItem1_2.iItem = 0;	// 0�s
	lvItem1_2.iSubItem = 1;	// 1��
	pListCtrl1->SetItem(&lvItem1_2);	// pListCtrl1->SetItem��lvItem1_2��}��.(���m�ɂ̓Z�b�g.)
	LVITEM lvItem1_3;	// �A�C�e��1_3
	lvItem1_3.mask = LVIF_TEXT;	// �A�C�e���e�L�X�g�̂݃Z�b�g.
	lvItem1_3.pszText = _T("Tokyo");	// �A�C�e���e�L�X�g��"Tokyo".
	lvItem1_3.iItem = 0;	// 0�s
	lvItem1_3.iSubItem = 2;	// 2��
	pListCtrl1->SetItem(&lvItem1_3);	// pListCtrl1->SetItem��lvItem1_3��}��.(���m�ɂ̓Z�b�g.)
	// �A�C�e��2_1�`2_3�̑}��.
	LVITEM lvItem2_1;	// �A�C�e��2_1
	lvItem2_1.mask = LVIF_TEXT;	// �A�C�e���e�L�X�g�̂݃Z�b�g.
	lvItem2_1.pszText = _T("Jiro");	// �A�C�e���e�L�X�g��"Jiro".
	lvItem2_1.iItem = 1;	// 1�s
	lvItem2_1.iSubItem = 0;	// 0��
	pListCtrl1->InsertItem(&lvItem2_1);	// pListCtrl1->InsertItem��lvItem2_1��}��.
	LVITEM lvItem2_2;	// �A�C�e��2_2
	lvItem2_2.mask = LVIF_TEXT;	// �A�C�e���e�L�X�g�̂݃Z�b�g.
	lvItem2_2.pszText = _T("18");	// �A�C�e���e�L�X�g��"18".
	lvItem2_2.iItem = 1;	// 1�s
	lvItem2_2.iSubItem = 1;	// 1��
	pListCtrl1->SetItem(&lvItem2_2);	// pListCtrl1->SetItem��lvItem2_2��}��.(���m�ɂ̓Z�b�g.)
	LVITEM lvItem2_3;	// �A�C�e��2_3
	lvItem2_3.mask = LVIF_TEXT;	// �A�C�e���e�L�X�g�̂݃Z�b�g.
	lvItem2_3.pszText = _T("Osaka");	// �A�C�e���e�L�X�g��"Osaka".
	lvItem2_3.iItem = 1;	// 1�s 
	lvItem2_3.iSubItem = 2;	// 2��
	pListCtrl1->SetItem(&lvItem2_3);	// pListCtrl1->SetItem��lvItem2_3��}��.(���m�ɂ̓Z�b�g.)
	// �A�C�e��3_1�`3_3�̑}��.
	LVITEM lvItem3_1;	// �A�C�e��3_1
	lvItem3_1.mask = LVIF_TEXT;	// �A�C�e���e�L�X�g�̂݃Z�b�g.
	lvItem3_1.pszText = _T("Saburo");	// �A�C�e���e�L�X�g��"Saburo".
	lvItem3_1.iItem = 2;	// 2�s
	lvItem3_1.iSubItem = 0;	// 0��
	pListCtrl1->InsertItem(&lvItem3_1);	// pListCtrl1->InsertItem��lvItem3_1��}��.
	LVITEM lvItem3_2;	// �A�C�e��3_2
	lvItem3_2.mask = LVIF_TEXT;	// �A�C�e���e�L�X�g�̂݃Z�b�g.
	lvItem3_2.pszText = _T("16");	// �A�C�e���e�L�X�g��"16".
	lvItem3_2.iItem = 2;	// 2�s
	lvItem3_2.iSubItem = 1;	// 1��
	pListCtrl1->SetItem(&lvItem3_2);	// pListCtrl1->SetItem��lvItem3_2��}��.(���m�ɂ̓Z�b�g.)
	LVITEM lvItem3_3;	// �A�C�e��3_3
	lvItem3_3.mask = LVIF_TEXT;	// �A�C�e���e�L�X�g�̂݃Z�b�g.
	lvItem3_3.pszText = _T("Nagoya");	// �A�C�e���e�L�X�g��"Nagoya".
	lvItem3_3.iItem = 2;	// 2�s 
	lvItem3_3.iSubItem = 2;	// 2��
	pListCtrl1->SetItem(&lvItem3_3);	// pListCtrl1->SetItem��lvItem3_3��}��.(���m�ɂ̓Z�b�g.)

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CListCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

