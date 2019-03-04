// SpeakMouthDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SpeakMouth.h"
#include "SpeakMouthDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_RECOEVENT	WM_USER+101	
/////////////////////////////////////////////////////////////////////////////
// Mouth Mapping Array (from Microsoft's TTSApp Example)

const int g_iMapVisemeToImage[22] = {
	0,  // SP_VISEME_0 = 0,    // Silence
    11, // SP_VISEME_1,        // AE, AX, AH
    11, // SP_VISEME_2,        // AA
    11, // SP_VISEME_3,        // AO
    10, // SP_VISEME_4,        // EY, EH, UH
    11, // SP_VISEME_5,        // ER
    9,  // SP_VISEME_6,        // y, IY, IH, IX
    2,  // SP_VISEME_7,        // w, UW
    13, // SP_VISEME_8,        // OW
    9,  // SP_VISEME_9,        // AW
    12, // SP_VISEME_10,       // OY
    11, // SP_VISEME_11,       // AY
    9,  // SP_VISEME_12,       // h
    3,  // SP_VISEME_13,       // r
    6,  // SP_VISEME_14,       // l
    7,  // SP_VISEME_15,       // s, z
    8,  // SP_VISEME_16,       // SH, CH, JH, ZH
    5,  // SP_VISEME_17,       // TH, DH
    4,  // SP_VISEME_18,       // f, v
    7,  // SP_VISEME_19,       // d, t, n
    9,  // SP_VISEME_20,       // k, g, NG
    1	// SP_VISEME_21,       // p, b, m
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpeakMouthDlg dialog

CSpeakMouthDlg::CSpeakMouthDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpeakMouthDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpeakMouthDlg)
	m_sText = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_iMouthBmp = 0;
}

void CSpeakMouthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpeakMouthDlg)
	DDX_Control(pDX, IDC_MOUTH_IMG, m_cMouth);
	DDX_Text(pDX, IDC_TEXT, m_sText);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSpeakMouthDlg, CDialog)
	//{{AFX_MSG_MAP(CSpeakMouthDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_SPEAK_BTN, OnSpeak)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_RECOEVENT, OnMouthEvent)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpeakMouthDlg message handlers

BOOL CSpeakMouthDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon((HICON)(LoadImage(AfxGetResourceHandle(), 
		MAKEINTRESOURCE(IDR_MAINFRAME), IMAGE_ICON, 16, 16, 0)), FALSE);

	m_sError=_T("");
	if (!InitializationSAPI()) {
		AfxMessageBox(m_sError);		
		DestroySAPI();
	}

	InitMouthImageList();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSpeakMouthDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSpeakMouthDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CDialog::OnPaint();
		// Draw into memory DC
		m_cMouthList.Draw(&dc, 0, m_cMouthRect.TopLeft(), INDEXTOOVERLAYMASK(m_iMouthBmp)); 
		
		if (m_iMouthBmp % 6 == 2) {
			m_cMouthList.Draw(&dc, WEYESNAR, m_cMouthRect.TopLeft(), 0 ); 
		} else if (m_iMouthBmp % 6 == 5) {
			m_cMouthList.Draw(&dc, WEYESCLO, m_cMouthRect.TopLeft(), 0 ); 
		}
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSpeakMouthDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSpeakMouthDlg::OnDestroy() 
{
	
	DestroySAPI();
	CDialog::OnDestroy();
		
}

BOOL CSpeakMouthDlg::InitializationSAPI()
{
	if (FAILED(CoInitialize(NULL))) {
		
		m_sError=_T("Error intialization COM");
		return FALSE;
	}

    HRESULT hRes;
	
	hRes = IpVoice.CoCreateInstance(CLSID_SpVoice);
	
	if (FAILED(hRes)) {
		m_sError=_T("Error creating voice");
		return FALSE;
	}
	
	hRes = IpVoice->SetInterest(SPFEI(SPEI_VISEME), SPFEI(SPEI_VISEME));	

	if (FAILED(hRes)) {
		m_sError=_T("Error creating interest...seriously");
		return FALSE;
	}
	
	hRes = IpVoice->SetNotifyWindowMessage(m_hWnd, WM_RECOEVENT, 0, 0);
	
	if (FAILED(hRes)) {
		m_sError=_T("Error setting notification window");
		return FALSE;
	}

	return TRUE;
}

BOOL CSpeakMouthDlg::DestroySAPI()
{
	if (IpVoice) {
		IpVoice.Release();
	}
	return TRUE;
}

BOOL CSpeakMouthDlg::InitMouthImageList()
{
	m_cMouth.GetClientRect(&m_cMouthRect);
	m_cMouth.ClientToScreen(&m_cMouthRect);
	ScreenToClient(&m_cMouthRect);

	CBitmap bmp;

    m_cMouthList.Create(CHARACTER_WIDTH, CHARACTER_HEIGHT, ILC_COLOR32 | ILC_MASK, 1, 0);

	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICFULL));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH2));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH3));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH4));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH5));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH6));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH7));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH8));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH9));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH10));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH11));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH12));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICMOUTH13));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICEYESNAR));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_MICEYESCLO));
	m_cMouthList.Add(&bmp, RGB(255,0,255));
	bmp.Detach();
	
	m_cMouthList.SetOverlayImage(1, 1);
	m_cMouthList.SetOverlayImage(2, 2);
	m_cMouthList.SetOverlayImage(3, 3);
	m_cMouthList.SetOverlayImage(4, 4);
	m_cMouthList.SetOverlayImage(5, 5);
	m_cMouthList.SetOverlayImage(6, 6);
	m_cMouthList.SetOverlayImage(7, 7);
	m_cMouthList.SetOverlayImage(8, 8);
	m_cMouthList.SetOverlayImage(9, 9);
	m_cMouthList.SetOverlayImage(10, 10);
	m_cMouthList.SetOverlayImage(11, 11);
	m_cMouthList.SetOverlayImage(12, 12);
	m_cMouthList.SetOverlayImage(13, 13);
	m_cMouthList.SetOverlayImage(14, WEYESNAR);
	m_cMouthList.SetOverlayImage(15, WEYESCLO);

	return TRUE;
}

LRESULT CSpeakMouthDlg::OnMouthEvent(WPARAM wParam, LPARAM lParam) 
{
    CSpEvent event;  
	
    while (event.GetFrom(IpVoice) == S_OK) {
        switch (event.eEventId) {
			case SPEI_VISEME:
				m_iMouthBmp = g_iMapVisemeToImage[event.Viseme()];
				InvalidateRect(m_cMouthRect, false);
				break;
        }
    }

	return 0;
}

void CSpeakMouthDlg::OnSpeak() 
{
	UpdateData();
	
	USES_CONVERSION;
	IpVoice->Speak(m_sText.AllocSysString(), SPF_ASYNC, NULL);		
}
