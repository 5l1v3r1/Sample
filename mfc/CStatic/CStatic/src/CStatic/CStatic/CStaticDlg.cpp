// CStaticDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CStatic.h"
#include "CStaticDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaticDlg �_�C�A���O




CStaticDlg::CStaticDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStaticDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStaticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStaticDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CStaticDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CStaticDlg ���b�Z�[�W �n���h��

BOOL CStaticDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	HICON hIcon = theApp.LoadIcon(IDI_ICON1);	// CWnd::LoadIcon��IDI_ICON1�����[�h.(theApp��extern�Ȃ̂�, ����������Ăׂ�.)
	SetIcon(hIcon, TRUE);	// CWnd::SetIcon��hIcon���Z�b�g.(TRUE�Ȃ̂ő傫���A�C�R���ɃZ�b�g.)
	SetIcon(hIcon, FALSE);	// CWnd::SetIcon��hIcon���Z�b�g.(FALSE�Ȃ̂ŏ������A�C�R���ɃZ�b�g.)

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CStaticDlg::OnPaint()
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
HCURSOR CStaticDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CStaticDlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	// �{�^���������ꂽ��, IDC_STATIC1��"Hello, world!", IDC_STATIC2��bitmap1.bmp(IDB_BITMAP1)���Z�b�g.
	CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_STATIC1);	// GetDlgItem�ŃX�^�e�B�b�N�R���g���[��IDC_STATIC1�̃I�u�W�F�N�g�|�C���^��pStatic1�Ɋi�[.((CStatic *)�ɃL���X�g.)
	pStatic1->SetWindowText(_T("Hello, world!"));	// pStatic1->SetWindowText��IDC_STATIC1��"Hello, world!"���Z�b�g.
	m_cBitmap.LoadBitmap(IDB_BITMAP1);	// m_cBitmap.LoadBitmap��IDB_BITMAP1�����[�h.
	CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_STATIC2);	// GetDlgItem�ŃX�^�e�B�b�N�R���g���[��IDC_STATIC2�̃I�u�W�F�N�g�|�C���^��pStatic2�Ɋi�[.((CStatic *)�ɃL���X�g.)
	pStatic2->SetBitmap(m_cBitmap);	// pStatic2->SetBitmap��IDC_STATIC2��m_cBitmap���Z�b�g.
}
