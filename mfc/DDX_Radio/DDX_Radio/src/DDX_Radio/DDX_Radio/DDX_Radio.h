// DDX_Radio.h : PROJECT_NAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"		// ���C�� �V���{��


// CDDX_RadioApp:
// ���̃N���X�̎����ɂ��ẮADDX_Radio.cpp ���Q�Ƃ��Ă��������B
//

class CDDX_RadioApp : public CWinApp
{
public:
	CDDX_RadioApp();

// �I�[�o�[���C�h
	public:
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern CDDX_RadioApp theApp;