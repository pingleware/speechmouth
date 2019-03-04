// SpeakMouth.h : main header file for the SPEAKMOUTH application
//

#if !defined(AFX_SPEAKMOUTH_H__7052ABF5_A7D2_4A9C_BF54_2384848D984B__INCLUDED_)
#define AFX_SPEAKMOUTH_H__7052ABF5_A7D2_4A9C_BF54_2384848D984B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpeakMouthApp:
// See SpeakMouth.cpp for the implementation of this class
//

class CSpeakMouthApp : public CWinApp
{
public:
	CSpeakMouthApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpeakMouthApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSpeakMouthApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPEAKMOUTH_H__7052ABF5_A7D2_4A9C_BF54_2384848D984B__INCLUDED_)
