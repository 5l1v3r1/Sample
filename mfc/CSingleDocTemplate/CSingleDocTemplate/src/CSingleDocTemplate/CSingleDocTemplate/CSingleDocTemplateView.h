// CSingleDocTemplateView.h : CSingleDocTemplateView �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CSingleDocTemplateView : public CEditView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CSingleDocTemplateView();
	DECLARE_DYNCREATE(CSingleDocTemplateView)

// ����
public:
	CSingleDocTemplateDoc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����
public:
	virtual ~CSingleDocTemplateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CSingleDocTemplateView.cpp �̃f�o�b�O �o�[�W����
inline CSingleDocTemplateDoc* CSingleDocTemplateView::GetDocument() const
   { return reinterpret_cast<CSingleDocTemplateDoc*>(m_pDocument); }
#endif

