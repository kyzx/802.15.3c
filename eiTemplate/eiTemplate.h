
// eiTemplate.h : eiTemplate Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

// CeiTemplateApp:
// �йش����ʵ�֣������ eiTemplate.cpp
//

class CeiTemplateApp : public CWinApp
{
public:
	CeiTemplateApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CeiTemplateApp theApp;