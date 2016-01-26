// CEditDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CEdit.h"
#include "CEditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditDlg �_�C�A���O




CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CEditDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CEditDlg ���b�Z�[�W �n���h��

BOOL CEditDlg::OnInitDialog()
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

void CEditDlg::OnPaint()
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
HCURSOR CEditDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CEditDlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	// �{�^���������ꂽ��, IDC_EDIT1�ɃZ�b�g���ꂽ��������擾����, MessageBox�ŕ\��.
	CEdit *pEdit1 = (CEdit *)GetDlgItem(IDC_EDIT1);	// GetDlgItem�ŃG�f�B�b�g�R���g���[��IDC_EDIT1�̃I�u�W�F�N�g�|�C���^��pEdit1�Ɋi�[.((CEdit *)�ɃL���X�g.)
	TCHAR tszBuf[256];	// TCHAR�^�o�b�t�@tszBuf(�v�f��256).
	int iLen = pEdit1->GetLine(0, tszBuf, 255);	// pEdit1->GetLine��0�s�ڂ̕�������擾��, tszBuf�Ɋi�[(�ő�255����), �߂�l�̃R�s�[������������iLen�Ɋi�[.
	tszBuf[iLen] = _T('\0');	// �Ō�̕����̎��ɂ�'\0'������.
	MessageBox(tszBuf, _T("CEdit"), MB_ICONASTERISK);	// MessageBox��tszBuf��\��.
}
