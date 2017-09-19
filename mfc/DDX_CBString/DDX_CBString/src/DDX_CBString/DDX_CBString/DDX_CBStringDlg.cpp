// DDX_CBStringDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "DDX_CBString.h"
#include "DDX_CBStringDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDX_CBStringDlg �_�C�A���O




CDDX_CBStringDlg::CDDX_CBStringDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDX_CBStringDlg::IDD, pParent)
	, m_xvComboBox1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDX_CBStringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_xcComboBox1);
	DDX_CBString(pDX, IDC_COMBO1, m_xvComboBox1);
}

BEGIN_MESSAGE_MAP(CDDX_CBStringDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDDX_CBStringDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDDX_CBStringDlg ���b�Z�[�W �n���h��

BOOL CDDX_CBStringDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	// �A�C�e���̒ǉ�.
	m_xcComboBox1.AddString(_T("Item1"));	// m_xcComboBox1.AddString��"Item1"��ǉ�.
	m_xcComboBox1.AddString(_T("Item2"));	// m_xcComboBox1.AddString��"Item2"��ǉ�.
	m_xcComboBox1.AddString(_T("Item3"));	// m_xcComboBox1.AddString��"Item3"��ǉ�.

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CDDX_CBStringDlg::OnPaint()
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
HCURSOR CDDX_CBStringDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDDX_CBStringDlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	// �X�V.
	UpdateData();	// UpdateData�Ńf�[�^�̍X�V.
	// �I�����ꂽ�A�C�e���̕������\��.
	AfxMessageBox(m_xvComboBox1);	// m_xvComboBox1��\��.
}
