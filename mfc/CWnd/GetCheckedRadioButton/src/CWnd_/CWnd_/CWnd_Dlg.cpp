// CWnd_Dlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CWnd_.h"
#include "CWnd_Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWnd_Dlg �_�C�A���O




CWnd_Dlg::CWnd_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWnd_Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWnd_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWnd_Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CWnd_Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CWnd_Dlg ���b�Z�[�W �n���h��

BOOL CWnd_Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	CWinApp *pApp = AfxGetApp();	// AfxGetApp()��theApp�̃|�C���^�擾.
	HICON hIcon = ::LoadIcon(pApp->m_hInstance, MAKEINTRESOURCE(IDI_ICON1));	// ::LoadIcon��IDI_ICON1(icon1.ico)�����[�h, �n���h����hIcon�Ɋi�[.
	SetIcon(hIcon, TRUE);	// CWnd::SetIcon��hIcon���Z�b�g.(TRUE�Ȃ̂ő傫���A�C�R���ɃZ�b�g.)
	SetIcon(hIcon, FALSE);	// CWnd::SetIcon��hIcon���Z�b�g.(FALSE�Ȃ̂ŏ������A�C�R���ɃZ�b�g.)

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CWnd_Dlg::OnPaint()
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
HCURSOR CWnd_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CWnd_Dlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	// ���W�I�{�^�����ǂ��ɃZ�b�g����Ă��邩���m�F����.
	int id = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO3);	// GetCheckedRadioButton��IDC_RADIO1����IDC_RADIO3�܂ł̃��W�I�{�^���̂ǂꂪ�`�F�b�N����Ă��邩���m�F����.
	if (id == IDC_RADIO1){	// IDC_RADIO1�̎�.
		AfxMessageBox(_T("IDC_RADIO1"), MB_OK | MB_ICONASTERISK);	// "IDC_RADIO1"�ƕ\��.
	}
	else if (id == IDC_RADIO2){	// IDC_RADIO2�̎�.
		AfxMessageBox(_T("IDC_RADIO2"), MB_OK | MB_ICONASTERISK);	// "IDC_RADIO2"�ƕ\��.
	}
	else if (id == IDC_RADIO3){	// IDC_RADIO3�̎�.
		AfxMessageBox(_T("IDC_RADIO3"), MB_OK | MB_ICONASTERISK);	// "IDC_RADIO3"�ƕ\��.
	}
	else{	// �I������Ă��Ȃ���.
		AfxMessageBox(_T("Not Selected"), MB_OK | MB_ICONASTERISK);	// "Not Selected"�ƕ\��.
	}
}
