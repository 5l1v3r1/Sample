// CDocTemplateView.cpp : CDocTemplateView �N���X�̎���
//

#include "stdafx.h"
#include "CDocTemplate.h"

#include "CDocTemplateDoc.h"
#include "CDocTemplateView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocTemplateView

IMPLEMENT_DYNCREATE(CDocTemplateView, CView)

BEGIN_MESSAGE_MAP(CDocTemplateView, CView)
END_MESSAGE_MAP()

// CDocTemplateView �R���X�g���N�V����/�f�X�g���N�V����

CDocTemplateView::CDocTemplateView()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDocTemplateView::~CDocTemplateView()
{
}

BOOL CDocTemplateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDocTemplateView �`��

void CDocTemplateView::OnDraw(CDC* /*pDC*/)
{
	CDocTemplateDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}


// CDocTemplateView �f�f

#ifdef _DEBUG
void CDocTemplateView::AssertValid() const
{
	CView::AssertValid();
}

void CDocTemplateView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocTemplateDoc* CDocTemplateView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocTemplateDoc)));
	return (CDocTemplateDoc*)m_pDocument;
}
#endif //_DEBUG


// CDocTemplateView ���b�Z�[�W �n���h��
