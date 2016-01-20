// CButtonDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CButton.h"
#include "CButtonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButtonDlg �_�C�A���O




CButtonDlg::CButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CButtonDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CButtonDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CButtonDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CButtonDlg ���b�Z�[�W �n���h��

BOOL CButtonDlg::OnInitDialog()
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

	// �{�^���ɃA�C�R�����Z�b�g.
	HICON hDefIcon = ::LoadIcon(NULL, IDI_APPLICATION);	// ::LoadIcon�Ŋ���̃A�v���A�C�R��(IDI_APPLICATION)�����[�h��, hDefIcon�Ɋi�[.(IDI_APPLICATION�̓V�X�e���A�C�R���Ȃ̂�, ��1������NULL�ɂ��Ȃ��Ǝ擾�ł��Ȃ��̂Œ���!)
	CButton *pButton1 = (CButton *)GetDlgItem(IDC_BUTTON1);	// GetDlgItem�Ń{�^���R���g���[��IDC_BUTTON1�̃I�u�W�F�N�g�|�C���^��pButton1�Ɋi�[.((CButton *)�ɃL���X�g.)
	pButton1->SetIcon(hDefIcon);	// CButton::SetIcon��hDefIcon���Z�b�g.

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CButtonDlg::OnPaint()
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
HCURSOR CButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CButtonDlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	// �{�^��������������ʂ̃A�C�R�����Z�b�g.
	HICON hIcon1 = theApp.LoadIcon(IDI_ICON1);	// theApp.LoadIcon�ŃA�C�R��IDI_ICON1�����[�h��, hIcon1�Ɋi�[.
	CButton *pButton1 = (CButton *)GetDlgItem(IDC_BUTTON1);	// GetDlgItem�Ń{�^���R���g���[��IDC_BUTTON1�̃I�u�W�F�N�g�|�C���^��pButton1�Ɋi�[.((CButton *)�ɃL���X�g.)
	pButton1->SetIcon(hIcon1);	// CButton::SetIcon��hIcon1���Z�b�g.
}
