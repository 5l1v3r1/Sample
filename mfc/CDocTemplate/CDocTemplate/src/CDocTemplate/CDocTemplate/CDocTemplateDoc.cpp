// CDocTemplateDoc.cpp : CDocTemplateDoc �N���X�̎���
//

#include "stdafx.h"
#include "CDocTemplate.h"

#include "CDocTemplateDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocTemplateDoc

IMPLEMENT_DYNCREATE(CDocTemplateDoc, CDocument)

BEGIN_MESSAGE_MAP(CDocTemplateDoc, CDocument)
END_MESSAGE_MAP()


// CDocTemplateDoc �R���X�g���N�V����/�f�X�g���N�V����

CDocTemplateDoc::CDocTemplateDoc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDocTemplateDoc::~CDocTemplateDoc()
{
}

BOOL CDocTemplateDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDocTemplateDoc �V���A����

void CDocTemplateDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �i�[����R�[�h�������ɒǉ����Ă��������B
	}
	else
	{
		// TODO: �ǂݍ��ރR�[�h�������ɒǉ����Ă��������B
	}
}


// CDocTemplateDoc �f�f

#ifdef _DEBUG
void CDocTemplateDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDocTemplateDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDocTemplateDoc �R�}���h
