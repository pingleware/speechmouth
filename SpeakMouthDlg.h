// SpeakMouthDlg.h : header file
//

#if !defined(AFX_SPEAKMOUTHDLG_H__70A66784_8F83_4F52_AC72_DE3E01BE9341__INCLUDED_)
#define AFX_SPEAKMOUTHDLG_H__70A66784_8F83_4F52_AC72_DE3E01BE9341__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#include "sapi.h"
#include <sphelper.h>

// CONTANTS OF MOUTH
#define CHARACTER_WIDTH         128
#define CHARACTER_HEIGHT        128
#define WEYESNAR                14              // eye positions
#define WEYESCLO                15

/////////////////////////////////////////////////////////////////////////////
// CSpeakMouthDlg dialog

class CSpeakMouthDlg : public CDialog
{
// Construction
public:
	CSpeakMouthDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSpeakMouthDlg)
	enum { IDD = IDD_SPEAKMOUTH_DIALOG };
	CStatic	m_cMouth;
	CString	m_sText;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpeakMouthDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CString m_sError;
	BOOL InitMouthImageList();
	BOOL DestroySAPI();
	BOOL InitializationSAPI();
	
	///////////////////////////////////////////////////////
	// Speech API Variables
	
	CComPtr<ISpVoice> IpVoice;
	CImageList	m_cMouthList;
	int	m_iMouthBmp;
	CRect m_cMouthRect;
    ///////////////////////////////////////////////////////

	// Generated message map functions
	//{{AFX_MSG(CSpeakMouthDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnSpeak();
	//}}AFX_MSG
	afx_msg LRESULT OnMouthEvent(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPEAKMOUTHDLG_H__70A66784_8F83_4F52_AC72_DE3E01BE9341__INCLUDED_)
