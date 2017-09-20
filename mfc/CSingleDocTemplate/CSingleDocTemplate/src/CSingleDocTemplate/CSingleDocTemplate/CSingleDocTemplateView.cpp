// CSingleDocTemplateView.cpp : CSingleDocTemplateView �N���X�̎���
//

#include "stdafx.h"
#include "CSingleDocTemplate.h"

#include "CSingleDocTemplateDoc.h"
#include "CSingleDocTemplateView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleDocTemplateView

IMPLEMENT_DYNCREATE(CSingleDocTemplateView, CEditView)

BEGIN_MESSAGE_MAP(CSingleDocTemplateView, CEditView)
END_MESSAGE_MAP()

// CSingleDocTemplateView �R���X�g���N�V����/�f�X�g���N�V����

CSingleDocTemplateView::CSingleDocTemplateView()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CSingleDocTemplateView::~CSingleDocTemplateView()
{
}

BOOL CSingleDocTemplateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ���[�h ���b�v���g�p�\�ɂ��܂�

	return bPreCreated;
}


// CSingleDocTemplateView �f�f

#ifdef _DEBUG
void CSingleDocTemplateView::AssertValid() const
{
	CEditView::AssertValid();
}

void CSingleDocTemplateView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CSingleDocTemplateDoc* CSingleDocTemplateView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDocTemplateDoc)));
	return (CSingleDocTemplateDoc*)m_pDocument;
}
#endif //_DEBUG


// CSingleDocTemplateView ���b�Z�[�W �n���h��
