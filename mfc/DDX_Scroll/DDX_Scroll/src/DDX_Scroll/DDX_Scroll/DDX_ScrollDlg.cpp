// DDX_ScrollDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "DDX_Scroll.h"
#include "DDX_ScrollDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDX_ScrollDlg �_�C�A���O




CDDX_ScrollDlg::CDDX_ScrollDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDX_ScrollDlg::IDD, pParent)
	, m_xvScrollBar1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDX_ScrollDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_xcScrollBar1);
	DDX_Scroll(pDX, IDC_SCROLLBAR1, m_xvScrollBar1);
}

BEGIN_MESSAGE_MAP(CDDX_ScrollDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDDX_ScrollDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDDX_ScrollDlg ���b�Z�[�W �n���h��

BOOL CDDX_ScrollDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	// �X�N���[���o�[�̏�����.
	m_xcScrollBar1.SetScrollRange(0, 100);	// m_xcScrollBar1.SetScrollRange�Ŕ͈͂�(0, 100)�Ƃ���.
	m_xcScrollBar1.SetScrollPos(50);	// m_xcScrollBar1.SetScrollPos�ňʒu��50�ɂ���.
	
	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CDDX_ScrollDlg::OnPaint()
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
HCURSOR CDDX_ScrollDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDDX_ScrollDlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	// �X�V.
	UpdateData();	// UpdateData�Ńf�[�^�̍X�V.
	// �܂݈ʒu�̕\��..
	TCHAR tszPos[32] = {0};	// TCHAR�^������o�b�t�@tszPos(����32)��0�ŏ�����.
	_stprintf(tszPos, _T("tszPos = %d\n"), m_xvScrollBar1);	// _stprintf��m_xvScrollBar1��tszPos�ɕϊ�.
	AfxMessageBox(tszPos);	// tszPos��\��.
}
