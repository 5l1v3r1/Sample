// DDX_CBString.h : PROJECT_NAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"		// ���C�� �V���{��


// CDDX_CBStringApp:
// ���̃N���X�̎����ɂ��ẮADDX_CBString.cpp ���Q�Ƃ��Ă��������B
//

class CDDX_CBStringApp : public CWinApp
{
public:
	CDDX_CBStringApp();

// �I�[�o�[���C�h
	public:
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern CDDX_CBStringApp theApp;