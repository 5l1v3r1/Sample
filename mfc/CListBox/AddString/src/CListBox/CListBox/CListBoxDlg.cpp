// CListBoxDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CListBox.h"
#include "CListBoxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListBoxDlg �_�C�A���O




CListBoxDlg::CListBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListBoxDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CListBoxDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CListBoxDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CListBoxDlg ���b�Z�[�W �n���h��

BOOL CListBoxDlg::OnInitDialog()
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

void CListBoxDlg::OnPaint()
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
HCURSOR CListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CListBoxDlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	// �G�f�B�b�g�{�b�N�X�̕���������X�g�{�b�N�X�ɒǉ�����.
	CListBox *pListBox1 = (CListBox *)GetDlgItem(IDC_LIST1);	// GetDlgItem�Ń��X�g�{�b�N�X�R���g���[��IDC_LIST1�̃I�u�W�F�N�g�|�C���^��pListBox1�Ɋi�[.((CListBox *)�ɃL���X�g.)
	CEdit *pEdit1 = (CEdit *)GetDlgItem(IDC_EDIT1);	// GetDlgItem�ŃG�f�B�b�g�{�b�N�X�R���g���[��IDC_EDIT1�̃I�u�W�F�N�g�|�C���^��pEdit1�Ɋi�[.((CEdit *)�ɃL���X�g.)
	int iLen = pEdit1->GetWindowTextLength();	// pEdit1->GetWindowTextLength�Ńe�L�X�g�̒������擾.
	TCHAR *ptszText = new TCHAR[iLen + 1];	// ����iLen + 1�̃o�b�t�@ptszText��p��.
	pEdit1->GetWindowText(ptszText, iLen + 1);	// pEdit1->GetWindowText�Ńe�L�X�g���擾.
	pListBox1->AddString(ptszText);	// pListBox1->AddString�Ń��X�g�{�b�N�X��ptszText�̓��e��ǉ�.
	delete [] ptszText;	// ptszText���.
}
