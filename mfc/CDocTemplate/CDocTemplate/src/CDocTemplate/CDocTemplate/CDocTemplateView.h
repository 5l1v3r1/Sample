// CDocTemplateView.h : CDocTemplateView �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDocTemplateView : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDocTemplateView();
	DECLARE_DYNCREATE(CDocTemplateView)

// ����
public:
	CDocTemplateDoc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����
public:
	virtual ~CDocTemplateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CDocTemplateView.cpp �̃f�o�b�O �o�[�W����
inline CDocTemplateDoc* CDocTemplateView::GetDocument() const
   { return reinterpret_cast<CDocTemplateDoc*>(m_pDocument); }
#endif

