
// East Campus Guide.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CEastCampusGuideApp:
// �йش����ʵ�֣������ East Campus Guide.cpp
//

class CEastCampusGuideApp : public CWinApp
{
public:
	CEastCampusGuideApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEastCampusGuideApp theApp;