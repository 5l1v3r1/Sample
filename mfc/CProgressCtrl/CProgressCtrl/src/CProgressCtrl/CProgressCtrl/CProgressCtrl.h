// CProgressCtrl.h : PROJECT_NAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"		// ���C�� �V���{��


// CProgressCtrlApp:
// ���̃N���X�̎����ɂ��ẮACProgressCtrl.cpp ���Q�Ƃ��Ă��������B
//

class CProgressCtrlApp : public CWinApp
{
public:
	CProgressCtrlApp();

// �I�[�o�[���C�h
	public:
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern CProgressCtrlApp theApp;