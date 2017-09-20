// CSingleDocTemplateDoc.cpp : CSingleDocTemplateDoc �N���X�̎���
//

#include "stdafx.h"
#include "CSingleDocTemplate.h"

#include "CSingleDocTemplateDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleDocTemplateDoc

IMPLEMENT_DYNCREATE(CSingleDocTemplateDoc, CDocument)

BEGIN_MESSAGE_MAP(CSingleDocTemplateDoc, CDocument)
END_MESSAGE_MAP()


// CSingleDocTemplateDoc �R���X�g���N�V����/�f�X�g���N�V����

CSingleDocTemplateDoc::CSingleDocTemplateDoc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CSingleDocTemplateDoc::~CSingleDocTemplateDoc()
{
}

BOOL CSingleDocTemplateDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CSingleDocTemplateDoc �V���A����

void CSingleDocTemplateDoc::Serialize(CArchive& ar)
{
	// CEditView �́A���ׂẴV���A��������������G�f�B�b�g �R���g���[�����܂�ł��܂��B
	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
}


// CSingleDocTemplateDoc �f�f

#ifdef _DEBUG
void CSingleDocTemplateDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSingleDocTemplateDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSingleDocTemplateDoc �R�}���h
