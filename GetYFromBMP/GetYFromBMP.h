
// GetYFromBMP.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGetYFromBMPApp: 
// �йش����ʵ�֣������ GetYFromBMP.cpp
//

class CGetYFromBMPApp : public CWinApp
{
public:
	CGetYFromBMPApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGetYFromBMPApp theApp;