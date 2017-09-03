// DDX_RadioDlg.cpp : �����t�@�C��
//

#include <stdio.h>
#include <tchar.h>

#include "stdafx.h"
#include "DDX_Radio.h"
#include "DDX_RadioDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDX_RadioDlg �_�C�A���O




CDDX_RadioDlg::CDDX_RadioDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDX_RadioDlg::IDD, pParent)
	, m_xvRadio1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDX_RadioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_xvRadio1);
}

BEGIN_MESSAGE_MAP(CDDX_RadioDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDDX_RadioDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDDX_RadioDlg ���b�Z�[�W �n���h��

BOOL CDDX_RadioDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CDDX_RadioDlg::OnPaint()
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
HCURSOR CDDX_RadioDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDDX_RadioDlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	UpdateData();	// UpdateData�ŕϐ����X�V.
	TCHAR tszRadio1[128] = {0};	// TCHAR�^�z��tszRadio1(����128)��0�ŏ�����.
	_stprintf(tszRadio1, _T("m_xvRadio1 = %d"), m_xvRadio1);	// _stprintf��m_xvRadio1��tszRadio1�ɕϊ�.
	AfxMessageBox(tszRadio1);	// AfxMessageBox��tszRadio1��\��.
}
