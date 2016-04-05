// CComboBoxDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CComboBox.h"
#include "CComboBoxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComboBoxDlg �_�C�A���O




CComboBoxDlg::CComboBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComboBoxDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CComboBoxDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CComboBoxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CComboBoxDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CComboBoxDlg ���b�Z�[�W �n���h��

BOOL CComboBoxDlg::OnInitDialog()
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

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CComboBoxDlg::OnPaint()
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
HCURSOR CComboBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CComboBoxDlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	// �R���{�{�b�N�X�̃G�f�B�b�g�̈�̕�������R���{�{�b�N�X�̃��X�g�̈�ɒǉ�����.
	CComboBox *pComboBox1 = (CComboBox *)GetDlgItem(IDC_COMBO1);	// GetDlgItem�ŃR���{�{�b�N�X�R���g���[��IDC_COMBO1�̃I�u�W�F�N�g�|�C���^��pComboBox1�Ɋi�[.((CComboBox *)�ɃL���X�g.)
	int len = pComboBox1->GetWindowTextLength();	// pComboBox1->GetWindowTextLength�ŃG�f�B�b�g�̈�̕�����̒������擾.
	TCHAR *ptszText = new TCHAR[len + 1];	// ����len + 1�̃o�b�t�@���m��.
	pComboBox1->GetWindowText(ptszText, len + 1);	// pComboBox1->GetWindowText�Ńe�L�X�g���擾��, ptszText�Ɋi�[.
	pComboBox1->AddString(ptszText);	// pComboBox1->AddString�Ń��X�g�̈�ɒǉ�����.
	delete [] ptszText;					// ptszText�����.
}

void CComboBoxDlg::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	// �I���������ڂ̃e�L�X�g�����b�Z�[�W�{�b�N�X�ŕ\��.
	CComboBox *pComboBox1 = (CComboBox *)GetDlgItem(IDC_COMBO1);	// GetDlgItem�ŃR���{�{�b�N�X�R���g���[��IDC_COMBO1�̃I�u�W�F�N�g�|�C���^��pComboBox1�Ɋi�[.((CComboBox *)�ɃL���X�g.)
	int idx = pComboBox1->GetCurSel();	// pComboBox1->GetCurSel�őI�����ꂽ���ڂ̃C���f�b�N�X���擾.
	int len = pComboBox1->GetLBTextLen(idx);	// pComboBox1->GetLBTextLen�őI�����ꂽ���ڂ̕�����̒������擾.
	TCHAR *ptszText = new TCHAR[len + 1];	// ����len + 1�̃o�b�t�@���m��.
	pComboBox1->GetLBText(idx, ptszText);	// pComboBox1->GetLBText�őI�����ꂽ���ڂ̃e�L�X�g���擾.
	AfxMessageBox(ptszText, MB_OK | MB_ICONASTERISK);	// AfxMessageBox��ptszText���o��.
	delete [] ptszText;	// ptszText�����.
}
