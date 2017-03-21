
// MFCThucHanh5.h : main header file for the MFCThucHanh5 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCThucHanh5App:
// See MFCThucHanh5.cpp for the implementation of this class
//

class CMFCThucHanh5App : public CWinApp
{
public:
	CMFCThucHanh5App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCThucHanh5App theApp;
