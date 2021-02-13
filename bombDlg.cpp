// bombDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bomb.h"
#include "bombDlg.h"
#include "oddslas.h"
#include <cmath>
#include <stdio.h>
#include "MalGrupp.h"

#define skarmupplosning 1
#define delay 100
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

HWND CBombDlg::HittaSpelFonster(int timeout)
{
	HWND hWnd;
	int retry = 0;
	if (!UNIBETSPEL(m_speltyp))
	{
		do
		{
			::Sleep(100);
			hWnd = ::FindWindow(NULL,"Svenska Spel - Spelbutiken - Microsoft Internet Explorer");
			if (hWnd == NULL)
				hWnd = ::FindWindow(NULL,"Svenska Spel - Spelbutiken - Windows Internet Explorer");
			if (hWnd == NULL)
				hWnd = ::FindWindow(NULL,"Svenska Spel - Spelbutiken - Microsoft Internet Explorer - Tele2Internet");
			if (hWnd == NULL)
				hWnd = ::FindWindow(NULL,"Svenska Spel - Spelbutiken - Microsoft Internet Explorer - Everyday Free2Connect by Tele2 and Everyday.");
			if (hWnd == NULL)
				hWnd = ::FindWindow(NULL,"https://secure.svenskaspel.se - Svenska Spel - Spelbutiken - Microsoft Internet Explorer");
			retry++;
		}
		while(hWnd == NULL && retry < timeout/100);
	}
	// Spel pa Unibet
	else if (UNIBETSPEL(m_speltyp))
	{
		hWnd = ::FindWindow(NULL,"Superscore - Current Coupon - Microsoft Internet Explorer");
		if (hWnd == NULL)
			hWnd = ::FindWindow(NULL,"Superscore - Current Coupon - Windows Internet Explorer");
		if (hWnd==NULL)
			hWnd = ::FindWindow(NULL,"Unibet - Superscore - Microsoft Internet Explorer");
		if (hWnd==NULL)
			hWnd = ::FindWindow(NULL,"Unibet - Superscore - Windows Internet Explorer");
		if (hWnd==NULL)
			hWnd = ::FindWindow(NULL,"Superscore - Windows Internet Explorer");
	}
	return hWnd;
}
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
// CBombDlg dialog

CBombDlg::CBombDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBombDlg::IDD, pParent)
	, m_KryssaAktiv(FALSE)
	, m_MinMalGrp(0)
	, m_MaxMalGrp(0)
	, m_DelayClp(0)
	, m_m4_ett(0)
	, m_m4_kryss(0)
	, m_m4_tva(0)
	, m_m4_ett_talj(0)
	, m_m4_kryss_talj(0)
	, m_m4_tva_talj(0)
	, m_m4_minmal_hemma(0)
	, m_m4_maxmal_hemma(0)
	, m_m4_minmal_borta(0)
	, m_m4_maxmal_borta(0)
	, m_antalitabell4(0)
	, m_VistaYoffs(0)
	, m_VistaXoffs(0)
	, m_en_krona_ospelad(FALSE)
{
	//{{AFX_DATA_INIT(CBombDlg)
	m_m1_minmal_hemma = 0;
	m_sannodds = 0.0f;
	m_placering = 0;
	m_m1_ett_talj = 0;
	m_m1_kryss_talj = 0;
	m_m1_tva_talj = 0;
	m_m2_ett_talj = 0;
	m_m2_kryss_talj = 0;
	m_m2_tva_talj = 0;
	m_m3_ett_talj = 0;
	m_m3_kryss_talj = 0;
	m_m3_tva_talj = 0;
	m_m1_maxmal_hemma = 0;
	m_m1_minmal_borta = 0;
	m_m1_maxmal_borta = 0;
	m_m2_minmal_hemma = 0;
	m_m2_maxmal_hemma = 0;
	m_m2_minmal_borta = 0;
	m_m2_maxmal_borta = 0;
	m_m3_minmal_hemma = 0;
	m_m3_maxmal_hemma = 0;
	m_m3_minmal_borta = 0;
	m_m3_maxmal_borta = 0;
	m_antalitabell1 = 0;
	m_antalitabell2 = 0;
	m_antalitabell3 = 0;
	m_minkvot = 0.0f;
	m_MatchIDNr = 0;
	m_minnomodds = 0;
	m_speltyp = -1;
	m_maxkostnad = 0.0f;
	m_omsattning = 0;
	m_mininsats = 0.0f;
	m_maxsida = 0;
	m_m1_ett = 0;
	m_OddsNum = 0;
	m_AterBet = 0.0f;
	m_KvotJust = 0.0f;
	m_AutoInlasning = FALSE;
	m_StartTimme = 0;
	m_StartMinut = 0;
	m_utvardering = -1;
	m_OspeladeForvalt = FALSE;
	m_OddsOspelActive = FALSE;
	m_OddsOspelade = 0;
	m_BombbNr = 0;
	m_minsida = 0;
	m_Instanserr = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBombDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBombDlg)
	DDX_Text(pDX, IDC_EDIT21, m_m1_minmal_hemma);
	DDX_Text(pDX, IDC_EDIT2, m_m1_kryss);
	DDX_Text(pDX, IDC_EDIT3, m_m1_tva);
	DDX_Text(pDX, IDC_EDIT4, m_m2_ett);
	DDX_Text(pDX, IDC_EDIT5, m_m2_kryss);
	DDX_Text(pDX, IDC_EDIT6, m_m2_tva);
	DDX_Text(pDX, IDC_EDIT7, m_m3_ett);
	DDX_Text(pDX, IDC_EDIT9, m_m3_tva);
	DDX_Text(pDX, IDC_EDIT8, m_m3_kryss);
	DDX_Text(pDX, IDC_EDIT11, m_sannodds);
	DDX_Text(pDX, IDC_EDIT10, m_placering);
	DDX_Text(pDX, IDC_EDIT12, m_m1_ett_talj);
	DDX_Text(pDX, IDC_EDIT13, m_m1_kryss_talj);
	DDX_Text(pDX, IDC_EDIT14, m_m1_tva_talj);
	DDX_Text(pDX, IDC_EDIT15, m_m2_ett_talj);
	DDX_Text(pDX, IDC_EDIT16, m_m2_kryss_talj);
	DDX_Text(pDX, IDC_EDIT17, m_m2_tva_talj);
	DDX_Text(pDX, IDC_EDIT18, m_m3_ett_talj);
	DDX_Text(pDX, IDC_EDIT19, m_m3_kryss_talj);
	DDX_Text(pDX, IDC_EDIT20, m_m3_tva_talj);
	DDX_Text(pDX, IDC_EDIT22, m_m1_maxmal_hemma);
	DDX_Text(pDX, IDC_EDIT23, m_m1_minmal_borta);
	DDX_Text(pDX, IDC_EDIT24, m_m1_maxmal_borta);
	DDX_Text(pDX, IDC_EDIT25, m_m2_minmal_hemma);
	DDX_Text(pDX, IDC_EDIT26, m_m2_maxmal_hemma);
	DDX_Text(pDX, IDC_EDIT27, m_m2_minmal_borta);
	DDX_Text(pDX, IDC_EDIT28, m_m2_maxmal_borta);
	DDX_Text(pDX, IDC_EDIT29, m_m3_minmal_hemma);
	DDX_Text(pDX, IDC_EDIT30, m_m3_maxmal_hemma);
	DDX_Text(pDX, IDC_EDIT31, m_m3_minmal_borta);
	DDX_Text(pDX, IDC_EDIT32, m_m3_maxmal_borta);
	DDX_Text(pDX, IDC_EDIT33, m_antalitabell1);
	DDX_Text(pDX, IDC_EDIT34, m_antalitabell2);
	DDX_Text(pDX, IDC_EDIT35, m_antalitabell3);
	DDX_Text(pDX, IDC_EDIT36, m_minkvot);
	DDV_MinMaxFloat(pDX, m_minkvot, 0.f, 1000.f);
	DDX_Text(pDX, IDC_EDIT37, m_MatchIDNr);
	DDX_Text(pDX, IDC_EDIT38, m_minnomodds);
	DDX_Radio(pDX, IDC_RADIO1, m_speltyp);
	DDX_Text(pDX, IDC_EDIT39, m_omsattning);
	DDX_Text(pDX, IDC_EDIT40, m_mininsats);
	DDX_Text(pDX, IDC_EDIT41, m_maxsida);
	DDX_Text(pDX, IDC_EDIT1, m_m1_ett);
	DDX_Text(pDX, IDC_EDIT42, m_OddsNum);
	DDX_Text(pDX, IDC_ATERBET_EDIT, m_AterBet);
	DDV_MinMaxFloat(pDX, m_AterBet, 0.f, 10.f);
	DDX_Text(pDX, IDC_KVOTJUSTERING_EDIT, m_KvotJust);
	DDV_MinMaxFloat(pDX, m_KvotJust, 0.f, 10.f);
	DDX_Check(pDX, IDC_AUTOINLASNING, m_AutoInlasning);
	DDX_Text(pDX, IDC_EDIT_STARTTIMME, m_StartTimme);
	DDV_MinMaxInt(pDX, m_StartTimme, 0, 23);
	DDX_Text(pDX, IDC_EDIT_STARTMINUT, m_StartMinut);
	DDV_MinMaxInt(pDX, m_StartMinut, 0, 59);
	DDX_Radio(pDX, IDC_RADIO6, m_utvardering);
	DDX_Check(pDX, IDC_CHECK1, m_OspeladeForvalt);
	DDX_Check(pDX, IDC_CHECK2, m_OddsOspelActive);
	DDX_Text(pDX, IDC_EDIT43, m_OddsOspelade);
	DDX_Text(pDX, IDC_EDIT44, m_BombbNr);
	DDX_Text(pDX, IDC_EDIT45, m_minsida);
	DDX_Text(pDX, IDC_EDIT46, m_Instanserr);
	DDV_MinMaxInt(pDX, m_Instanserr, 1, 10);
	//}}AFX_DATA_MAP
	DDX_Check(pDX, IDC_CHECK3, m_KryssaAktiv);
	DDX_Text(pDX, IDC_EDIT47, m_MinMalGrp);
	DDX_Text(pDX, IDC_EDIT48, m_MaxMalGrp);
	DDX_Text(pDX, IDC_EDIT49, m_DelayClp);
	DDX_Text(pDX, IDC_EDIT50, m_m4_ett);
	DDX_Text(pDX, IDC_EDIT51, m_m4_kryss);
	DDX_Text(pDX, IDC_EDIT52, m_m4_tva);
	DDX_Text(pDX, IDC_EDIT53, m_m4_ett_talj);
	DDX_Text(pDX, IDC_EDIT54, m_m4_kryss_talj);
	DDX_Text(pDX, IDC_EDIT55, m_m4_tva_talj);
	DDX_Text(pDX, IDC_EDIT56, m_m4_minmal_hemma);
	DDX_Text(pDX, IDC_EDIT57, m_m4_maxmal_hemma);
	DDX_Text(pDX, IDC_EDIT58, m_m4_minmal_borta);
	DDX_Text(pDX, IDC_EDIT59, m_m4_maxmal_borta);
	DDX_Text(pDX, IDC_EDIT60, m_antalitabell4);
	DDX_Check(pDX, IDC_CHECK4, m_WV);
	DDX_Text(pDX, IDC_EDIT61, m_VistaYoffs);
	DDX_Text(pDX, IDC_EDIT62, m_VistaXoffs);
	DDX_Check(pDX, IDC_CHECK5, m_en_krona_ospelad);
}

BEGIN_MESSAGE_MAP(CBombDlg, CDialog)
	//{{AFX_MSG_MAP(CBombDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, Onkalkylera_sant_odds)
	ON_BN_CLICKED(IDC_BUTTON1, Onkalk_sanna_odds)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnSkapaRapportfil)
	ON_WM_CLOSE()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON10, OnAutoInlasning)
	ON_BN_CLICKED(IDC_RADIO1, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_CBN_SELCHANGE(IDC_COMBO1, Onkalkylera_sant_odds)
	ON_CBN_SELCHANGE(IDC_COMBO2, Onkalkylera_sant_odds)
	ON_CBN_SELCHANGE(IDC_COMBO3, Onkalkylera_sant_odds)
	ON_BN_CLICKED(IDC_RADIO2, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO3, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO4, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO5, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO8, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO10, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO11, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO12, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO13, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO14, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO15, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO16, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO9, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO7, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_RADIO6, OnSpelTypRadio)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT51, &CBombDlg::OnEnChangeEdit51)
	ON_EN_CHANGE(IDC_EDIT52, &CBombDlg::OnEnChangeEdit52)
	ON_EN_CHANGE(IDC_EDIT59, &CBombDlg::OnEnChangeEdit59)
	ON_BN_CLICKED(IDOK, &CBombDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT50, &CBombDlg::OnEnChangeEdit50)
	ON_BN_CLICKED(IDC_BUTTON4, &CBombDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_RADIO17, &CBombDlg::OnBnClickedRadio17)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBombDlg message handlers

BOOL CBombDlg::OnInitDialog()
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
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	Odds = new COdds;	

	Odds->MatchOdds[0][0]=&m_m1_ett;	Odds->MatchOdds[1][0]=&m_m1_kryss;	Odds->MatchOdds[2][0]=&m_m1_tva;
	Odds->MatchOdds[0][1]=&m_m2_ett;	Odds->MatchOdds[1][1]=&m_m2_kryss;	Odds->MatchOdds[2][1]=&m_m2_tva;
	Odds->MatchOdds[0][2]=&m_m3_ett;	Odds->MatchOdds[1][2]=&m_m3_kryss;	Odds->MatchOdds[2][2]=&m_m3_tva;
	Odds->MinKvot=&m_minkvot;
	Odds->MinIns=&m_mininsats;
	Odds->Oms=&m_omsattning;
	Odds->MaxNomOdds = &m_minnomodds;
	Odds->AterBet = &m_AterBet;
	Odds->KvotJust = &m_KvotJust;
	Odds->OddsOspelActive = &m_OddsOspelActive;
	Odds->OddsOspelade = &m_OddsOspelade;

	m_m1_ett	= 220;
	m_m1_kryss	= 260;
	m_m1_tva	= 245;
	
	m_m2_ett	= 235;
	m_m2_kryss	= 260;
	m_m2_tva	= 230;

	m_m3_ett	= 190;
	m_m3_kryss	= 275;
	m_m3_tva	= 280;

	m_m4_ett	= 185;
	m_m4_kryss	= 275;
	m_m4_tva	= 290;


	m_minnomodds = 1000000;
	m_omsattning = 1000000;
	m_speltyp = 3;
	m_utvardering = 0;
	m_mininsats = 0.5;
	m_AterBet = 0.6;
	m_KvotJust = 1.0;
	m_MatchIDNr = 3267;
	m_minsida   =  0;
	m_maxsida   = 5;
	m_OspeladeForvalt = true;
	m_OddsOspelade = 200000;
	m_MinMalGrp = 0; 
	m_MaxMalGrp = 2;
	m_Instanserr = 1;			// Antal instanser
	m_DelayClp = 80;
	XPos.xh1 = 0;
	int a;  
	for(a = 0;a<281;a++)
	{
		oddsfrekvens_etta[a] = 0;
		oddsfrekvens_kryss[a] = 0;
		oddsfrekvens_tva[a] = 0;
	}
	for(a = 0;a<281;a++)
	{
		for(int b = 0;b<MAXRES;b++)
		{
			for(int c = 0;c<MAXRES;c++)
			{
				antal[a][b][c] = 0;
				antalX[a][b][c] = 0;
			}
		}
	}
	m_firsttime = true;
	m_minkvot = 1.5;

	// Kolla om programmet kör under Windows Vista
	OSVERSIONINFO VersionInformation;
	VersionInformation.dwOSVersionInfoSize = sizeof(OSVERSIONINFO); 
	::GetVersionEx(&VersionInformation); 
	m_WV = (VersionInformation.dwMajorVersion > 5);

	m_VistaXoffs=4;	
	m_VistaYoffs=34;	
	
	UpdateData(false);
	OnSpelTypRadio() ;  // Initiering av värden för vald speltyp
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBombDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBombDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBombDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBombDlg::OnOK() 
{
	// Generering kan ske endast en gång
	if  (Odds->Num != 0)
		return;

	CComboBox* pLC1 = (CComboBox*) GetDlgItem(IDC_COMBO1);
	CComboBox* pLC2 = (CComboBox*) GetDlgItem(IDC_COMBO2);
	CComboBox* pLC3 = (CComboBox*) GetDlgItem(IDC_COMBO3);
	CComboBox* pLC4 = (CComboBox*) GetDlgItem(IDC_COMBO4);
	UpdateData(true);
	las_oddsfrekvens(); // Tilldela antal[], antalX[]
	Odds->m_speltyp = m_speltyp;
	Odds->m_utvardering = m_utvardering;
	kalkylera_maxmal();		  // Kalkylera max mål i varje match
	kalkylera_alla_nominella_odds();   // Tilldela Odds->..
	double o1;
	int sindexmatch1,sindexmatch2,sindexmatch3,sindexmatch4,ai1,ai2,ai3,ai4;
	int antalitabell1,antalitabell2,antalitabell3,antalitabell4;
	sindexmatch1 = 0;
	sindexmatch2 = 0;
	sindexmatch3 = 0;
	sindexmatch4 = 0;
	antalitabell1 = 0;
	antalitabell2 = 0;
	antalitabell3 = 0;
	antalitabell4 = 0;
	ai1 = 0;
	ai2 = 0;
	ai3 = 0;
	ai4 = 0;
	int minmal,maxmal;
	minmal = 10;
	maxmal = 0;
	for(int a = 0;a<MAXRES;a++)
	{
		for(int b = 0;b<MAXRES;b++)
		{
			CString tempstring;
			char buffer[12];
			tempstring = itoa(a,buffer,10);
			tempstring +=  "-";
			tempstring += itoa(b,buffer,10);
			tempstring += "    ";
			o1 = berakna_sannt_odds_for_en_kombination(a,b,1,true);
			
			tempstring += gcvt(o1,4,buffer);
			if(o1 > 0)
			{
				if(ai1 == 0)
				{
					m_m1_minmal_hemma = (sindexmatch1/MAXRES);
				}
				if (minmal > (sindexmatch1%MAXRES))
					minmal = (sindexmatch1%MAXRES);
				if (maxmal < (sindexmatch1%MAXRES))
					maxmal = (sindexmatch1%MAXRES);
				pLC1->InsertString(-1, tempstring);
				antalitabell1++;
				SantIndexMatch1[ai1] = sindexmatch1;
				sindexmatch1++;
				ai1++;
			}
			else
				sindexmatch1++;
			
		}
	}
	m_m1_ett_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(1,0,1,false);
	m_m1_kryss_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(0,0,1,false);
	m_m1_tva_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(0,1,1,false);
	m_m1_maxmal_hemma = (SantIndexMatch1[ai1-1]/MAXRES);
	m_m1_minmal_borta = minmal;
	m_m1_maxmal_borta = maxmal;
	m_antalitabell1 = antalitabell1;
	minmal = 9;
	maxmal = 0;
	UpdateData(false);
	pLC1->SetCurSel(0);

	
	// Ej periodspel svensk hockey -->
	if (m_speltyp !=9)
	{
	for(int a = 0;a<MAXRES;a++)
	{
		for(int b = 0;b<MAXRES;b++)
		{
			CString tempstring;
			char buffer[12];
			tempstring = itoa(a,buffer,10);
			tempstring +=  "-";
			tempstring += itoa(b,buffer,10);
			tempstring += "    ";
			o1 = berakna_sannt_odds_for_en_kombination(a,b,2,true);
			tempstring += gcvt(o1,4,buffer);
			if(o1 > 0)
			{
				if(ai2 == 0)
				{
					m_m2_minmal_hemma = (sindexmatch2/MAXRES);
				}
				if (minmal > (sindexmatch2%MAXRES))
					minmal = (sindexmatch2%MAXRES);
				if (maxmal < (sindexmatch2%MAXRES))
					maxmal = (sindexmatch2%MAXRES);
				pLC2->InsertString(-1, tempstring);
				antalitabell2++;
				SantIndexMatch2[ai2] = sindexmatch2;
				sindexmatch2++;
				ai2++;
			}
			else
				sindexmatch2++;
		}
	}
	m_m2_ett_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(1,0,2,false);
	m_m2_kryss_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(0,0,2,false);
	m_m2_tva_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(0,1,2,false);
	m_m2_maxmal_hemma = (SantIndexMatch2[ai2-1]/MAXRES);
	m_m2_minmal_borta = minmal;
	m_m2_maxmal_borta = maxmal;
	m_antalitabell2 = antalitabell2;
	minmal = 9;
	maxmal = 0;
	}
	UpdateData(false);
	pLC2->SetCurSel(0);

	
	// Fotboll eller ishockey/bandy med 3 matcher -->
	if(m_speltyp ==0 || m_speltyp == 3 || m_speltyp == 5 || m_speltyp == 6 || m_speltyp == 8 || m_speltyp == 10 || m_speltyp == 11 || m_speltyp == 12)
	{
	for(int a = 0;a<MAXRES;a++)
	{
		for(int b = 0;b<MAXRES;b++)
		{
			CString tempstring;
			char buffer[12];
			tempstring = itoa(a,buffer,10);
			tempstring +=  "-";
			tempstring += itoa(b,buffer,10);
			tempstring += "    ";
			o1 = berakna_sannt_odds_for_en_kombination(a,b,3,true);
			tempstring += gcvt(o1,4,buffer);
			if(o1 > 0)
			{
				if(ai3 == 0)
				{
					m_m3_minmal_hemma = (sindexmatch3/MAXRES);
				}
				if (minmal > (sindexmatch3%MAXRES))
					minmal = (sindexmatch3%MAXRES);
				if (maxmal < (sindexmatch3%MAXRES))
					maxmal = (sindexmatch3%MAXRES);
				pLC3->InsertString(-1, tempstring);
				antalitabell3++;
				SantIndexMatch3[ai3] = sindexmatch3;
				sindexmatch3++;
				ai3++;
			}
			else
				sindexmatch3++;
		}
	}
	m_m3_ett_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(1,0,3,false);
	m_m3_kryss_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(0,0,3,false);
	m_m3_tva_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(0,1,3,false);
	m_m3_maxmal_hemma = (SantIndexMatch3[ai3-1]/MAXRES);
	m_m3_minmal_borta = minmal;
	m_m3_maxmal_borta = maxmal;
	m_antalitabell3 = antalitabell3;
	}
	UpdateData(false);
	pLC3->SetCurSel(0);

	//fjärde matchen
  if(m_speltyp == 11)
	{
	for(int a = 0;a<MAXRES4;a++)
	{
		for(int b = 0;b<MAXRES4;b++)
		{
			CString tempstring;
			char buffer[12];
			tempstring = itoa(a,buffer,10);
			tempstring +=  "-";
			tempstring += itoa(b,buffer,10);
			tempstring += "    ";
			o1 = berakna_sannt_odds_for_en_kombination(a,b,4,true);
			tempstring += gcvt(o1,4,buffer);
			if(o1 > 0)
			{
				if(ai4 == 0)
				{
					m_m4_minmal_hemma = (sindexmatch4/MAXRES4);
				}
				if (minmal > (sindexmatch4%MAXRES4))
					minmal = (sindexmatch4%MAXRES4);
				if (maxmal < (sindexmatch4%MAXRES4))
					maxmal = (sindexmatch4%MAXRES4);
				pLC4->InsertString(-1, tempstring);
				antalitabell4++;
				SantIndexMatch4[ai4] = sindexmatch4;
				sindexmatch4++;
				ai4++;
			}
			else
				sindexmatch4++;
		}
	}
	m_m4_ett_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(1,0,4,false);
	m_m4_kryss_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(0,0,4,false);
	m_m4_tva_talj = (unsigned int) berakna_sannt_odds_for_en_kombination(0,1,4,false);
	m_m4_maxmal_hemma = (SantIndexMatch4[ai4-1]/MAXRES4);
	m_m4_minmal_borta = minmal;
	m_m4_maxmal_borta = maxmal;
	m_antalitabell4 = antalitabell4;
	}
	//slut fjärde matchen
	
	UpdateData(false);
	pLC4->SetCurSel(0);
//	CDialog::OnOK();
}

void CBombDlg::las_oddsfrekvens()
{
	int status,tempodds,varv;
	char c[1];
	FILE *stream;
	status = 0;
	tempodds = 0;
	varv = 0;

	if(m_speltyp == 0 || m_speltyp == 3 || m_speltyp == 6 || m_speltyp ==11 || m_speltyp ==12  || m_speltyp ==14)
		stream  = fopen( "FOTBFIL.txt", "r+" );
	
	else if (m_speltyp == 1 || m_speltyp == 4 || m_speltyp == 5 || m_speltyp == 7 || m_speltyp == 8 || m_speltyp ==9 || m_speltyp ==13)
		stream = fopen( "ISHFIL.txt", "r+" );

	

	else if (m_speltyp ==2 || m_speltyp == 10)
		stream = fopen ("BANFIL.txt", "r+" );

		
	if( stream  == NULL )
      MessageBox( "The odds file was not opened\n" );
    else
    //  MessageBox( "The file 'fotbfil.txt' was opened\n" );
	do
	{
		
	    fread( c, sizeof( char ), 1, stream );
		if(c[0] < '0' ||c[0] > '9')
			status = 10;
		else
		{
			tempodds = c[0] - 48;
			fread( c, sizeof( char ), 1, stream );
			tempodds*=10;
			tempodds += (c[0] - 48);
			fread( c, sizeof( char ), 1, stream );
			tempodds*=10;
			tempodds += c[0] - 48;
			fread( c, sizeof( char ), 1, stream );
			if(c[0] != ' ')
			{
				tempodds*=10;
				tempodds += c[0] - 48;
				fread( c, sizeof( char ), 1, stream );
			}

			//Första oddset identifierat////
			m_odds1 = (tempodds-100)/5;
			if(m_odds1 > 1000)
			{
				char b[2];
				int numwritten;
				b[0] = 'q';
				fseek(stream,0,SEEK_CUR);
				numwritten = fwrite(b,sizeof( char ),1,stream);
				fclose(stream);
			}
			oddsfrekvens_etta[m_odds1]++;

			tempodds = 0;
			fread( c, sizeof( char ), 1, stream );
			tempodds = c[0] - 48;
			fread( c, sizeof( char ), 1, stream );
			tempodds*=10;
			tempodds += (c[0] - 48);
			fread( c, sizeof( char ), 1, stream );
			tempodds*=10;
			tempodds += c[0] - 48;
			fread( c, sizeof( char ), 1, stream );
			if(c[0] != ' ')
			{
				tempodds*=10;
				tempodds += c[0] - 48;
				fread( c, sizeof( char ), 1, stream );
			}
		//Andra oddset identifierat///////
			m_odds2 = (tempodds-100)/5;
			oddsfrekvens_kryss[m_odds2]++;
			tempodds = 0;
			fread( c, sizeof( char ), 1, stream );
			tempodds = c[0] - 48;
			fread( c, sizeof( char ), 1, stream );
			tempodds*=10;
			tempodds += (c[0] - 48);
			fread( c, sizeof( char ), 1, stream );
			tempodds*=10;
			tempodds += c[0] - 48;
			fread( c, sizeof( char ), 1, stream );
			if(c[0] != ' ')
			{
				tempodds*=10;
				tempodds += c[0] - 48;
				fread( c, sizeof( char ), 1, stream );
			}
		//tredje oddset identifierat///////
			m_odds3 = (tempodds-100)/5;
			oddsfrekvens_tva[m_odds3]++;
		//Läs nu målen för hemmalaget//////////////////////
			int mal1;
			mal1 = 0;
			fread( c, sizeof( char ), 1, stream );
			mal1 += c[0] - 48;
			fread( c, sizeof( char ), 1, stream );
			if(c[0] != ' ')
			{
				mal1*=10;
				mal1 += c[0] - 48;
				fread( c, sizeof( char ), 1, stream );
			}
		//Läs nu målen för bortalaget//////////////////////
			int mal2;
			mal2 = 0;
			fread( c, sizeof( char ), 1, stream );
			mal2 += c[0] - 48;
			fread( c, sizeof( char ), 1, stream );
			if(c[0] != ' ' && c[0]!=10)
			{
				mal2*=10;
				mal2 += c[0] - 48;
				fread( c, sizeof( char ), 1, stream );
			}
			if (mal1>mal2)
			{
				antal[m_odds1][mal1][mal2]++;
			}
			else if(mal2>mal1)
			{
				antal[m_odds3][mal2][mal1]++;
			}
			else if(mal1 == mal2)
			{
				antalX[m_odds2][mal1][mal2]++;
			}
		//	fread( c, sizeof( char ), 1, stream );
		}
	}
	while (status <10);
//	char b[2];
//	int numwritten;
//	b[0] = 'q';
//	b[1] = 'q';
//	fseek(stream,0,SEEK_CUR);
//	numwritten = fwrite(b,sizeof( char ),2,stream);
//	fclose(stream);
//	MessageBox("inläsning klar!");
}
float CBombDlg::berakna_sannt_odds_for_en_kombination(int r1,int r2,int match,bool kvot)
{
	int oddstyp;
	
	// Tilldel oddstyp: 0=Fotboll, 1=Hockey, 2=Bandy
	if (m_speltyp==0  || m_speltyp==3 || m_speltyp == 6 || m_speltyp == 11 || m_speltyp == 12 || m_speltyp ==14)
		oddstyp = 0;
	else if (m_speltyp==1  || m_speltyp==4 || m_speltyp==5 || m_speltyp == 7 || m_speltyp == 8 || m_speltyp == 9  || m_speltyp ==13)
		oddstyp = 1;
	else
		oddstyp = 2;


	if(r1 > r2)
	{
		int index,nedre_index,ovre_index,funna_odds,max_funna_odds,namnare,taljare;
		funna_odds = 0;
		namnare = 0;
		taljare = 0;
	
		max_funna_odds = 3;
		if(match == 1)
			index = (m_m1_ett-100)/5;
		else if(match == 2)
			index = (m_m2_ett-100)/5;
		else if(match == 3)
			index = (m_m3_ett-100)/5;
		else
			index = (m_m4_ett-100)/5;
		nedre_index = index;
		ovre_index = index;
		if(oddstyp == 1 && index == 37)
			max_funna_odds = 7;
		else if(oddstyp == 1 && index == 28)
			max_funna_odds = 3;
		else if(oddstyp == 1 && index == 29)
			max_funna_odds = 5;
		else if(oddstyp == 1 && index == 31)
			max_funna_odds = 4;
		else if(oddstyp == 1 && index == 34)
			max_funna_odds = 5;
		else if(oddstyp == 1 && index == 39)
			max_funna_odds = 7;
		else if(oddstyp == 1 && index == 42)
			max_funna_odds = 8;
		else if(oddstyp == 1 && index == 46)
			max_funna_odds = 9;
		else if(oddstyp == 1 && index == 52)
			max_funna_odds = 10;
		else if(oddstyp == 1 && index == 57)
			max_funna_odds = 9;
		else if(oddstyp == 1 && index == 1)
			max_funna_odds = 2;
		else if(oddstyp == 1 && index == 64)
			max_funna_odds = 8;
		else if(oddstyp == 1 && index == 75)
			max_funna_odds = 8;
		else if(oddstyp == 1 && index == 158)
			max_funna_odds = 7;
		else if(oddstyp == 1 && index == 136)
			max_funna_odds = 9;
                else if(oddstyp == 0 && index == 56)
			max_funna_odds = 11;
		else if(oddstyp == 0 && index == 77)
			max_funna_odds = 11;
		else if(oddstyp == 0 && index == 83)
			max_funna_odds = 12;
		else if(oddstyp == 0 && index == 52)
			max_funna_odds = 9;
		else if(oddstyp == 0 && index == 38)
			max_funna_odds = 5;
		else if(oddstyp == 0 && index == 43)
			max_funna_odds = 6;
		else if(oddstyp == 0 && index == 67)
			max_funna_odds = 13;
		else if(oddstyp == 0 && index == 1)
			max_funna_odds = 2;
		else if(oddstyp == 0 && index == 72)
			max_funna_odds = 16;
		else if(oddstyp == 0 && index == 40)
			max_funna_odds = 7;
		else if(oddstyp == 0 && index == 90)
			max_funna_odds = 13;
		else if(oddstyp == 0 && index == 220)
			max_funna_odds = 14;
		else if(oddstyp == 0 && index == 47)
			max_funna_odds = 7;
		else if(oddstyp == 0 && index == 100)
			max_funna_odds = 13;
		else if(oddstyp == 0 && index == 240)
			max_funna_odds = 8;
		else if(oddstyp == 0 && index == 36)
			max_funna_odds = 5;
		else if(oddstyp == 0 && index == 60)
			max_funna_odds = 12;
		else if(oddstyp == 0 && index == 35)
			max_funna_odds = 5;
		else if(oddstyp == 0 && index == 116)
			max_funna_odds = 13;
		else if(oddstyp == 0 && index == 45)
			max_funna_odds = 6;
                else if(oddstyp == 0 && index == 83)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 37)
			max_funna_odds = 5;
                else if(oddstyp == 0 && index == 39)
			max_funna_odds = 7;
                else if(oddstyp == 0 && index == 42)
			max_funna_odds = 7;
                else if(oddstyp == 0 && index == 48)
			max_funna_odds = 7;
                else if(oddstyp == 0 && index == 49)
			max_funna_odds = 8;
                else if(oddstyp == 0 && index == 57)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 62)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 63)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 70)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 80)
			max_funna_odds = 11;
                else if(oddstyp == 0 && index == 89)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 97)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 103)
			max_funna_odds = 11;
                else if(oddstyp == 0 && index == 108)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 119)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 148)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 107)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 106)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 87)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 82)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 78)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 75)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 69)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 65)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 59)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 55)
			max_funna_odds = 11;
                else if(oddstyp == 0 && index == 51)
			max_funna_odds = 8;
                else if(oddstyp == 0 && index == 44)
			max_funna_odds = 6;
                else if(oddstyp == 0 && index == 41)
			max_funna_odds = 7;
                else if(oddstyp == 0 && index == 2)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 3)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 4)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 5)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 6)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 7)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 8)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 9)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 10)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 11)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 12)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 13)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 14)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 15)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 16)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 17)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 18)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 19)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 20)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 21)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 22)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 23)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 24)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 25)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 26)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 27)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 28)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 29)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 30)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 31)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 32)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 33)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 34)
			max_funna_odds = 3;
                else if(oddstyp == 2 && index == 1)
			max_funna_odds = 2;
		else if(oddstyp == 2 && index == 2)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 3)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 4)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 5)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 6)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 7)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 8)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 9)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 10)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 11)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 12)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 13)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 14)
			max_funna_odds = 3;
                else if(oddstyp == 2 && index == 15)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 16)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 17)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 18)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 19)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 20)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 21)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 22)
			max_funna_odds = 3;
		// Fick fel "blocks nested too deeply" GB
		if(oddstyp == 2 && index == 23)
			max_funna_odds = 5;
		else if(oddstyp == 2 && index == 25)
			max_funna_odds = 5;
		else if(oddstyp == 2 && index == 27)
			max_funna_odds = 5;
		else if(oddstyp == 2 && index == 29)
			max_funna_odds = 5;
		else if(oddstyp == 2 && index == 31)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 34)
			max_funna_odds = 5;
                else if(oddstyp == 2 && index == 37)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 41)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 46)
			max_funna_odds = 7;
		else if(oddstyp == 2 && index == 52)
			max_funna_odds = 8;
		else if(oddstyp == 2 && index == 61)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 86)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 90)
			max_funna_odds = 4;
		if(oddsfrekvens_etta[index] + oddsfrekvens_tva[index] > 0)
		{
			funna_odds = 1;
			namnare = antal[index][r1][r2];
			taljare = oddsfrekvens_etta[index] + oddsfrekvens_tva[index];
		}
		do
		{
			nedre_index--;
			if(nedre_index > 0)
			{
				if(oddsfrekvens_etta[nedre_index] + oddsfrekvens_tva[nedre_index] > 0)
				{
					funna_odds++;
					namnare += antal[nedre_index][r1][r2];
					taljare += oddsfrekvens_etta[nedre_index] + oddsfrekvens_tva[nedre_index];
				}
			}
			ovre_index++;
			if(ovre_index < 280)
			{
				if(oddsfrekvens_etta[ovre_index] + oddsfrekvens_tva[ovre_index] > 0)
				{
					funna_odds++;
					namnare += antal[ovre_index][r1][r2];
					taljare += oddsfrekvens_etta[ovre_index] + oddsfrekvens_tva[ovre_index];
				}
			}
		}
		while(funna_odds < max_funna_odds);
		double returvarde;
		
		if(kvot)
		{
			if(Odds->m_utvardering==1)
			{
				namnare--;
				taljare--;
			}
			if(namnare > 1)
				returvarde = ((double)taljare/(double)namnare);
			else returvarde = 0;
			return returvarde;
		}
		else
		{
			if(Odds->m_utvardering==1)
			{
				taljare--;
			}
			return taljare;
		}
	}
	else if(r1 < r2)
	{
		int index,nedre_index,ovre_index,funna_odds,max_funna_odds,namnare,taljare;
		funna_odds = 0;
		max_funna_odds = 3;
		namnare = 0;
		taljare = 0;
		if(match == 1)
			index = (m_m1_tva-100)/5;
		else if(match == 2)
			index = (m_m2_tva-100)/5;
		else if(match == 3)
			index = (m_m3_tva-100)/5;
		else
			index = (m_m4_tva-100)/5;
		nedre_index = index;
		ovre_index = index;
		if(oddstyp == 1 && index == 37)
			max_funna_odds = 7;
		else if(oddstyp == 1 && index == 28)
			max_funna_odds = 3;
		else if(oddstyp == 1 && index == 29)
			max_funna_odds = 5;
		else if(oddstyp == 1 && index == 31)
			max_funna_odds = 4;
		else if(oddstyp == 1 && index == 34)
			max_funna_odds = 5;
		else if(oddstyp == 1 && index == 39)
			max_funna_odds = 7;
		else if(oddstyp == 1 && index == 42)
			max_funna_odds = 8;
		else if(oddstyp == 1 && index == 46)
			max_funna_odds = 9;
		else if(oddstyp == 1 && index == 52)
			max_funna_odds = 10;
		else if(oddstyp == 1 && index == 57)
			max_funna_odds = 9;
		else if(oddstyp == 1 && index == 1)
			max_funna_odds = 2;
		else if(oddstyp == 1 && index == 64)
			max_funna_odds = 8;
		else if(oddstyp == 1 && index == 75)
			max_funna_odds = 8;
		else if(oddstyp == 1 && index == 158)
			max_funna_odds = 7;
		else if(oddstyp == 1 && index == 136)
			max_funna_odds = 9;
                else if(oddstyp == 0 && index == 56)
			max_funna_odds = 11;
		else if(oddstyp == 0 && index == 77)
			max_funna_odds = 11;
		else if(oddstyp == 0 && index == 83)
			max_funna_odds = 12;
		else if(oddstyp == 0 && index == 52)
			max_funna_odds = 9;
		else if(oddstyp == 0 && index == 38)
			max_funna_odds = 5;
		else if(oddstyp == 0 && index == 43)
			max_funna_odds = 6;
		else if(oddstyp == 0 && index == 67)
			max_funna_odds = 13;
		else if(oddstyp == 0 && index == 1)
			max_funna_odds = 2;
		else if(oddstyp == 0 && index == 72)
			max_funna_odds = 16;
		else if(oddstyp == 0 && index == 40)
			max_funna_odds = 7;
		else if(oddstyp == 0 && index == 90)
			max_funna_odds = 13;
		else if(oddstyp == 0 && index == 220)
			max_funna_odds = 14;
		else if(oddstyp == 0 && index == 47)
			max_funna_odds = 7;
		else if(oddstyp == 0 && index == 100)
			max_funna_odds = 13;
		else if(oddstyp == 0 && index == 240)
			max_funna_odds = 8;
		else if(oddstyp == 0 && index == 36)
			max_funna_odds = 5;
		else if(oddstyp == 0 && index == 60)
			max_funna_odds = 12;
		else if(oddstyp == 0 && index == 35)
			max_funna_odds = 5;
		else if(oddstyp == 0 && index == 116)
			max_funna_odds = 13;
		else if(oddstyp == 0 && index == 45)
			max_funna_odds = 6;
                else if(oddstyp == 0 && index == 83)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 37)
			max_funna_odds = 5;
                else if(oddstyp == 0 && index == 39)
			max_funna_odds = 7;
                else if(oddstyp == 0 && index == 42)
			max_funna_odds = 7;
                else if(oddstyp == 0 && index == 48)
			max_funna_odds = 7;
                else if(oddstyp == 0 && index == 49)
			max_funna_odds = 8;
                else if(oddstyp == 0 && index == 57)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 62)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 63)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 70)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 80)
			max_funna_odds = 11;
                else if(oddstyp == 0 && index == 89)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 97)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 103)
			max_funna_odds = 11;
                else if(oddstyp == 0 && index == 108)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 119)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 148)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 107)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 106)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 87)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 82)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 78)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 75)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 69)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 65)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 59)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 55)
			max_funna_odds = 11;
                else if(oddstyp == 0 && index == 51)
			max_funna_odds = 8;
                else if(oddstyp == 0 && index == 44)
			max_funna_odds = 6;
                else if(oddstyp == 0 && index == 41)
			max_funna_odds = 7;
                else if(oddstyp == 0 && index == 2)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 3)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 4)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 5)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 6)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 7)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 8)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 9)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 10)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 11)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 12)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 13)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 14)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 15)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 16)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 17)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 18)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 19)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 20)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 21)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 22)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 23)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 24)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 25)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 26)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 27)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 28)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 29)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 30)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 31)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 32)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 33)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 34)
			max_funna_odds = 3;
                else if(oddstyp == 2 && index == 1)
			max_funna_odds = 2;
		else if(oddstyp == 2 && index == 2)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 3)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 4)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 5)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 6)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 7)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 8)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 9)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 10)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 11)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 12)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 13)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 14)
			max_funna_odds = 3;
                else if(oddstyp == 2 && index == 15)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 16)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 17)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 18)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 19)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 20)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 21)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 22)
			max_funna_odds = 3;
		// Samma fel igen
		if(oddstyp == 2 && index == 23)
			max_funna_odds = 5;
		else if(oddstyp == 2 && index == 25)
			max_funna_odds = 5;
		else if(oddstyp == 2 && index == 27)
			max_funna_odds = 5;
		else if(oddstyp == 2 && index == 29)
			max_funna_odds = 5;
		else if(oddstyp == 2 && index == 31)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 34)
			max_funna_odds = 5;
                else if(oddstyp == 2 && index == 37)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 41)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 46)
			max_funna_odds = 7;
		else if(oddstyp == 2 && index == 52)
			max_funna_odds = 8;
		else if(oddstyp == 2 && index == 61)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 86)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 90)
			max_funna_odds = 4;

		if(oddsfrekvens_etta[index] + oddsfrekvens_tva[index] > 0)
		{
			funna_odds = 1;
			namnare = antal[index][r2][r1];
			taljare = oddsfrekvens_etta[index] + oddsfrekvens_tva[index];
		}
		do
		{
			nedre_index--;
			if(nedre_index > 0)
			{
				if(oddsfrekvens_etta[nedre_index] + oddsfrekvens_tva[nedre_index] > 0)
				{
					funna_odds++;
					namnare += antal[nedre_index][r2][r1];
					taljare += oddsfrekvens_etta[nedre_index] + oddsfrekvens_tva[nedre_index];
				}
			}
			ovre_index++;
			if(ovre_index < 280)
			{
				if(oddsfrekvens_etta[ovre_index] + oddsfrekvens_tva[ovre_index] > 0)
				{
					funna_odds++;
					namnare += antal[ovre_index][r2][r1];
					taljare += oddsfrekvens_etta[ovre_index] + oddsfrekvens_tva[ovre_index];
				}
			}
		}
		while(funna_odds < max_funna_odds);
		double returvarde;
		if(kvot)
		{
			if(Odds->m_utvardering==1)
			{
				namnare--;
				taljare--;
			}
			if(namnare > 1)
				returvarde = ((double)taljare/(double)namnare);
			else
				returvarde = 0;
			return returvarde;
		}
		else
		{
			if(Odds->m_utvardering==1)
			{
				taljare--;
			}
			return taljare;
		}
	}
	else if(r1 == r2)
	{
		int index,nedre_index,ovre_index,funna_odds,max_funna_odds,namnare,taljare;
		funna_odds = 0;
		max_funna_odds = 3;
		namnare = 0;
		taljare = 0;
		if(match == 1)
			index = (m_m1_kryss-100)/5;
		else if(match == 2)
			index = (m_m2_kryss-100)/5;
		else if(match == 3)
			index = (m_m3_kryss-100)/5;
		else
			index = (m_m4_kryss-100)/5;
		nedre_index = index;
		ovre_index = index;
		if(oddstyp == 1 && index == 54)
			max_funna_odds = 5;
		else if(oddstyp == 1 && index == 53)
			max_funna_odds = 4;
               	else if(oddstyp == 1 && index == 55)
			max_funna_odds = 5;
		else if(oddstyp == 1 && index == 122)
			max_funna_odds = 6;
		else if(oddstyp == 1 && index == 57)
			max_funna_odds = 5;
		else if(oddstyp == 1 && index == 58)
			max_funna_odds = 7;
		else if(oddstyp == 1 && index == 60)
			max_funna_odds = 5;
		else if(oddstyp == 1 && index == 62)
			max_funna_odds = 6;
		else if(oddstyp == 1 && index == 65)
			max_funna_odds = 3;
		else if(oddstyp == 1 && index == 66)
			max_funna_odds = 3;
		else if(oddstyp == 1 && index == 67)
			max_funna_odds = 2;
		else if(oddstyp == 1 && index == 74)
			max_funna_odds = 5;
		else if(oddstyp == 1 && index == 78)
			max_funna_odds = 6;
		else if(oddstyp == 1 && index == 79)
			max_funna_odds = 6;
		else if(oddstyp == 1 && index == 86)
			max_funna_odds = 8;
		else if(oddstyp == 1 && index == 92)
			max_funna_odds = 6;
		else if(oddstyp == 1 && index == 98)
			max_funna_odds = 6;
		else if(oddstyp == 1 && index == 120)
			max_funna_odds = 8;
                else if(oddstyp == 0 && index == 50)
			max_funna_odds = 8;
		else if(oddstyp == 0 && index == 46)
			max_funna_odds = 7;
		else if(oddstyp == 0 && index == 43)
			max_funna_odds = 5;
		else if(oddstyp == 0 && index == 55)
			max_funna_odds = 10;
		else if(oddstyp == 0 && index == 60)
			max_funna_odds = 11;
		else if(oddstyp == 0 && index == 66)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 91)
			max_funna_odds = 11;
                else if(oddstyp == 0 && index == 35)
			max_funna_odds = 1;
                else if(oddstyp == 0 && index == 34)
			max_funna_odds = 1;
                else if(oddstyp == 0 && index == 33)
			max_funna_odds = 1;
                else if(oddstyp == 0 && index == 32)
			max_funna_odds = 1;
		else if(oddstyp == 0 && index == 92)
			max_funna_odds = 6;
                else if(oddstyp == 0 && index == 82)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 72)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 58)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 56)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 53)
			max_funna_odds = 12;
                else if(oddstyp == 0 && index == 51)
			max_funna_odds = 8;
                else if(oddstyp == 0 && index == 49)
			max_funna_odds = 8;
                else if(oddstyp == 0 && index == 48)
			max_funna_odds = 7;
                else if(oddstyp == 0 && index == 47)
			max_funna_odds = 7;
                else if(oddstyp == 0 && index == 45)
			max_funna_odds = 5;
                else if(oddstyp == 0 && index == 44)
			max_funna_odds = 5;
                else if(oddstyp == 0 && index == 70)
			max_funna_odds = 11;
                else if(oddstyp == 0 && index == 76)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 62)
			max_funna_odds = 10;
                else if(oddstyp == 0 && index == 57)
			max_funna_odds = 13;
                else if(oddstyp == 0 && index == 22)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 23)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 24)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 25)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 26)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 27)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 28)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 29)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 30)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 31)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 36)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 37)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 38)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 39)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 40)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 41)
			max_funna_odds = 3;
                else if(oddstyp == 0 && index == 42)
			max_funna_odds = 3;
                else if(oddstyp == 2 && index == 82)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 83)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 85)
			max_funna_odds = 4;
		else if(oddstyp == 2 && index == 88)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 92)
			max_funna_odds = 3;
                else if(oddstyp == 2 && index == 95)
			max_funna_odds = 2;
		else if(oddstyp == 2 && index == 99)
			max_funna_odds = 4;
		else if(oddstyp == 2 && index == 101)
			max_funna_odds = 5;
		else if(oddstyp == 2 && index == 108)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 114)
			max_funna_odds = 7;
                else if(oddstyp == 2 && index == 119)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 125)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 132)
			max_funna_odds = 6;
		else if(oddstyp == 2 && index == 140)
			max_funna_odds = 3;
		else if(oddstyp == 2 && index == 148)
			max_funna_odds = 2;
		if(oddsfrekvens_kryss[index] > 0)
		{
			funna_odds = 1;
			namnare = antalX[index][r1][r2];
			taljare = oddsfrekvens_kryss[index];
		}
		do
		{
			if (max_funna_odds==1)
				break;

			nedre_index--;
			if(nedre_index > 0)
			{
				if(oddsfrekvens_kryss[nedre_index] > 0)
				{
					funna_odds++;
					namnare += antalX[nedre_index][r1][r2];
					taljare += oddsfrekvens_kryss[nedre_index];
				}
			}
			ovre_index++;
			if(ovre_index < 280)
			{
				if(oddsfrekvens_kryss[ovre_index] > 0)
				{
					funna_odds++;
					namnare += antalX[ovre_index][r1][r2];
					taljare += oddsfrekvens_kryss[ovre_index];
				}
			}
		}
		while(funna_odds < max_funna_odds);
		double returvarde;
		if(kvot)
		{
			if(Odds->m_utvardering==1)
			{
				namnare--;
				taljare--;
			}
			if(namnare > 1)
				returvarde = ((double)taljare/(double)namnare);
			else
				returvarde = 0;
			return returvarde;
		}
		else
		{
			if(Odds->m_utvardering==1)
			{
				taljare--;
			}
			return taljare;
		}
	}
}

void CBombDlg::Onkalkylera_sant_odds() 
{
	// TODO: Add your control notification handler code here
	CComboBox* pLC1 = (CComboBox*) GetDlgItem(IDC_COMBO1);
	CComboBox* pLC2 = (CComboBox*) GetDlgItem(IDC_COMBO2);
	CComboBox* pLC3 = (CComboBox*) GetDlgItem(IDC_COMBO3);
	CComboBox* pLC4 = (CComboBox*) GetDlgItem(IDC_COMBO4);

	int tmp,m1,m2;
	tmp = pLC1->GetCurSel();
	tmp = SantIndexMatch1[tmp];
	m2 = tmp % MAXRES;
	m1 = (tmp/MAXRES);
	float s1;
	s1 = berakna_sannt_odds_for_en_kombination(m1,m2,1,true);
	float s2;
	tmp = pLC2->GetCurSel();
	tmp = SantIndexMatch2[tmp];
	m2 = tmp % MAXRES;
	m1 = (tmp/MAXRES);
	s2 = berakna_sannt_odds_for_en_kombination(m1,m2,2,true);
	float s3;
	tmp = pLC3->GetCurSel();
	tmp = SantIndexMatch3[tmp];
	m2 = tmp % MAXRES;
	m1 = (tmp/MAXRES);

	// Fotboll eller ishockey/bandy med 3 matcher -->
	if(m_speltyp ==0 || m_speltyp == 3 || m_speltyp == 5 || m_speltyp == 6 || m_speltyp == 8 || m_speltyp == 10 || m_speltyp == 11 || m_speltyp == 12)
	{
		s3 = berakna_sannt_odds_for_en_kombination(m1,m2,3,true);
		m_sannodds = s1*s2*s3;
	}
	else
		m_sannodds = s1*s2;

	// Fotboll med 4 matcher -->
	if(m_speltyp ==11)
	{
		float s4;
		tmp = SantIndexMatch2[ pLC4->GetCurSel() ];
		m2 = tmp % MAXRES4;
		m1 = (tmp/MAXRES4);
		s4 = berakna_sannt_odds_for_en_kombination(m1,m2,4,true);
		m_sannodds = m_sannodds*s4;

	}

	UpdateData(false);
}

void CBombDlg::Onkalk_sanna_odds() 
{
	// TODO: Add your control notification handler code here
	int antal_resultat = 1;
	resultat temp_resultat;
	for(int a1 = 0; a1 < MAXRES; a1++)
		for(int a2 = 0; a2 < MAXRES; a2++)
			for(int a3 = 0; a3 < MAXRES; a3++)
				for(int a4 = 0; a4 < MAXRES; a4++)
					for(int a5 = 0; a5 < MAXRES; a5++)
						for(int a6 = 0; a6 < MAXRES; a6++)
						{
							double s1,s2,s3;
							s1 = berakna_sannt_odds_for_en_kombination(a1,a2,1,true);
							s2 = berakna_sannt_odds_for_en_kombination(a3,a4,2,true);
							s3 = berakna_sannt_odds_for_en_kombination(a5,a6,3,true);
					        if((s1*s2*s3 != 0)&& (antal_resultat < 40001))
							{
								int index1,index2,index3,antal1,antal2,antal3;
								if(a1>a2)
								{
									index1 = (m_m1_ett-100)/5;
									antal1 = antal[index1][a1][a2];
								}
								else if(a1<a2)
								{
									index1 = (m_m1_tva-100)/5;
									antal1 = antal[index1][a2][a1];
								}
								else
								{
									index1 = (m_m1_kryss-100)/5;
									antal1 = antalX[index1][a1][a2];
								}
							///////////////////////////////////////////
								if(a3>a4)
								{
									index2 = (m_m2_ett-100)/5;
									antal2 = antal[index2][a3][a4];
								}
								else if(a3<a4)
								{
									index2 = (m_m2_tva-100)/5;
									antal2 = antal[index2][a4][a3];
								}
								else
								{
									index2 = (m_m2_kryss-100)/5;
									antal2 = antalX[index2][a3][a4];
								}
								//////////////////////////////////////
								if(a5>a6)
								{
									index3 = (m_m3_ett-100)/5;
									antal3 = antal[index3][a5][a6];
								}
								else if(a5<a6)
								{
									index3 = (m_m3_tva-100)/5;
									antal3 = antal[index3][a6][a5];
								}
								else
								{
									index3 = (m_m3_kryss-100)/5;
									antal3 = antalX[index3][a5][a6];
								}
								if(antal1 > 1 && antal2 > 1 && antal3 > 1)
								{
									temp_resultat.r1 = (char) a1;
									temp_resultat.r2 = (char) a2;
									temp_resultat.r3 = (char) a3;
									temp_resultat.r4 = (char) a4;
									temp_resultat.r5 = (char) a5;
									temp_resultat.r6 = (char) a6;
									temp_resultat.odds = s1*s2*s3;
									m_resultat[antal_resultat] = temp_resultat;
									antal_resultat++;
								}
							}
						}
//	MessageBox("kalkylerat alla sanna odds!");
//	m_progress.SetRange( 0, 400 );
	temp_resultat = m_resultat[1];
	for(int s1 = 1;s1 < antal_resultat-1;s1++)
	{
		for(int s2 = s1+1;s2<antal_resultat;s2++)
		{
			if(m_resultat[s1].odds> m_resultat[s2].odds)
			{
				temp_resultat = m_resultat[s1];
				m_resultat[s1] = m_resultat[s2];
				m_resultat[s2] = temp_resultat;
			}
		}
	//	m_progress.SetPos(s1/100);
	//	if(s1 == 10000)
	//		MessageBox("hit!");
	//    if(s1 == 20000)
	//		MessageBox("hit!");
	//	if(s1 == 30000)
	//		MessageBox("hit!");
	}
//	MessageBox("Sortering klar!");
	CComboBox* pLC1 = (CComboBox*) GetDlgItem(IDC_COMBO1);
	CComboBox* pLC2 = (CComboBox*) GetDlgItem(IDC_COMBO2);
	CComboBox* pLC3 = (CComboBox*) GetDlgItem(IDC_COMBO3);
	int tmp,m1,m2,m3,m4,m5,m6;
	tmp = pLC1->GetCurSel();
	m2 = tmp % 11;
	m1 = (tmp/11);
	tmp = pLC2->GetCurSel();
	m4 = tmp % 11;
	m3 = (tmp/11);
	tmp = pLC3->GetCurSel();
	m6 = tmp % 11;
	m5 = (tmp/11);
	int position = 1;
	bool hittat = false;
	do
	{
		if(m_resultat[position].r1 == m1 &&
		   m_resultat[position].r2 == m2 &&
		   m_resultat[position].r3 == m3 &&
		   m_resultat[position].r4 == m4 &&
		   m_resultat[position].r5 == m5 &&
		   m_resultat[position].r6 == m6)
		   hittat = true;
		else position++;
	}
	while(!hittat && position < antal_resultat);
	m_placering = position;
	UpdateData(false);
}

void CBombDlg::OnAutoInlasning() 
{
	// Knapp för automatisk oddsinläsniing 
 	UpdateData(true);
	m_AutoInlasning = !m_AutoInlasning;
	UpdateData(false);
	if (m_AutoInlasning)
		SetTimer(1, 2000, 0);
}

void CBombDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your control notification handler code here
#define DayMin(h,m) ((3600*(h))+(60*(m)))

	KillTimer(nIDEvent);
	// Automatisk oddsinläsning från spelfönster
	if (m_AutoInlasning )
	{
		CTime theTime = CTime::GetCurrentTime();
		if (DayMin( theTime.GetHour(), theTime.GetMinute()) >= DayMin(m_StartTimme, m_StartMinut)) 
		{
			// Starta trådinläsning 
			OnButton5();
			m_AutoInlasning = false;
			UpdateData(false);
		}
		else 
		{
			SetTimer(1, 2000, 0);
			return;
		}
	}

}


void CBombDlg::kalkylera_maxmal()
{
	int	H1maxmal = 0, B1maxmal = 0, H2maxmal = 0, B2maxmal = 0, H3maxmal = 0, B3maxmal = 0, H4maxmal = 0, B4maxmal = 0;
	// Match 1
	for (int h=0; h<11; h++)
		for (int b=0; b<11; b++)
			if (berakna_sannt_odds_for_en_kombination(h,b,1,true) > 0.0)
			{
				if (h>H1maxmal)
					H1maxmal = h;
				if (b>B1maxmal)
					B1maxmal = b;
			}
	if (m_speltyp!=9)
	{
		// Match 2
		for (int h=0; h<11; h++)
			for (int b=0; b<11; b++)
				if (berakna_sannt_odds_for_en_kombination(h,b,2,true) > 0.0)
				{
					if (h>H2maxmal)
						H2maxmal = h;
					if (b>B2maxmal)
						B2maxmal = b;
				}
	}

	if (ANTALMATCHER(m_speltyp) >= 3)
	{
		// Match 3
		for (int h=0; h<11; h++)
			for (int b=0; b<11; b++)
				if (berakna_sannt_odds_for_en_kombination(h,b,3,true) > 0.0)
				{
					if (h>H3maxmal)
						H3maxmal = h;
					if (b>B3maxmal)
						B3maxmal = b;
				}
	}

	if (ANTALMATCHER(m_speltyp) == 4)
	{
		// Match 4
		for (int h=0; h<11; h++)
			for (int b=0; b<11; b++)
				if (berakna_sannt_odds_for_en_kombination(h,b,4,true) > 0.0)
				{
					if (h>H4maxmal)
						H4maxmal = h;
					if (b>B4maxmal)
						B4maxmal = b;
				}
	}

	Odds->AlloceraKB(H1maxmal, B1maxmal, H2maxmal, B2maxmal, H3maxmal, B3maxmal, H4maxmal, B4maxmal);
	
}
void CBombDlg::kalkylera_alla_nominella_odds()
{
	int a,b,c,d,e,f,g,h;
	float t1,t2,t3,t4;
	// Radera tidigar odds
	Odds->Num = 0;

	//Tommy 2008-01-31 START
	if(m_speltyp ==0 || m_speltyp == 3 || m_speltyp ==5 || m_speltyp == 6 || m_speltyp == 8 || m_speltyp ==10 || m_speltyp ==12)
	{
		for(a=0;a<MAXRES;a++)
		{
			for(b=0;b<MAXRES;b++)
			{
				t1 = berakna_sannt_odds_for_en_kombination(a,b,1,true);
				for(c=0;c<MAXRES;c++)
				{
					for(d=0;d<MAXRES;d++)
					{
						t2 = berakna_sannt_odds_for_en_kombination(c,d,2,true);
						for(e=0;e<MAXRES;e++)
						{
							for(f=0;f<MAXRES;f++)
							{
								t3 = berakna_sannt_odds_for_en_kombination(e,f,3,true);
								// Lägg in i oddslista
								if  (t1*t2*t3 > 0.0)
									Odds->NyttOdds(a, b, c, d, e, f,0,0, t1*t2*t3);
								
							}
						}
					}
				}
			}
		}
	}

	//Tommy 2008-01-31 START
	else if(m_speltyp == 11)
	{
		for(a=0;a<MAXRES;a++)
		{
			for(b=0;b<MAXRES;b++)
			{
				t1 = berakna_sannt_odds_for_en_kombination(a,b,1,true);
				for(c=0;c<MAXRES;c++)
				{
					for(d=0;d<MAXRES;d++)
					{
						t2 = berakna_sannt_odds_for_en_kombination(c,d,2,true);
						for(e=0;e<MAXRES;e++)
						{
							for(f=0;f<MAXRES;f++)
							{
								t3 = berakna_sannt_odds_for_en_kombination(e,f,3,true);
								for(g=0;g<MAXRES4;g++)
									for(h=0;h<MAXRES4;h++)
									{
										t4 = berakna_sannt_odds_for_en_kombination(g,h,4,true);
								// Lägg in i oddslista
								if  (t1*t2*t3*t4 > 0.0)
									Odds->NyttOdds(a, b, c, d, e, f,g,h, t1*t2*t3*t4);
								// Odds->KB[a][b][c][d][e][f]->NOdds = t1*t2*t3;
									}
							}
						}
					}
				}
			}
		}
	}
	//Tommy 2008-01-31 SLUT

	// Ishockey eller  Bandy med 2 matcher-->
	else if (m_speltyp != 9)
	{
		for(a=0;a<MAXRES;a++)
		{
			for(b=0;b<MAXRES;b++)
			{
				t1 = berakna_sannt_odds_for_en_kombination(a,b,1,true);
				for(c=0;c<MAXRES;c++)
				{
					for(d=0;d<MAXRES;d++)
					{
						t2 = berakna_sannt_odds_for_en_kombination(c,d,2,true);
						if  (t1*t2 > 0.0)
							Odds->NyttOdds(a, b, c, d, 0, 0,0,0, t1*t2);
					}
				}
			}
		}
						
	}
	// Ishockey 1 match med tre perioder-->
	else 
	{

	////Tommy Hagberg 071124////////////////////////
		FILE *str;
		CStdioFile *pFile;
		long antal_simu,antal_utfall;
	//	char list[170];	// GB changed for mem.check  2008-10-11
		char list[17000000];
	//	char scantext[15];
		int aa,bb,cc,dd,ee,ff,status,index;

		//pFile = fopen_s( &str, "permu.txt", "r+" );
		//stream = fopen ("BANFIL.txt", "r+" );
		// fread( c, sizeof( char ), 1, stream );
		int err;
		err = fopen_s( &str, "permu.txt", "r" );
	//	str = fopen("permu.txt", "r+");
		fread( list, sizeof( char ), 17000000, str);
		//antal__simu = 0;
		//char filename[32];
		//char text[64];
		sscanf(list,"%i-%i %i-%i %i-%i  %d",&aa,&bb,&cc,&dd,&ee,&ff,&antal_utfall);
		sscanf(list, "Antal simuleringar: %d\n", &antal_simu);
	//	scantext[0] = '\0';
	//	sprintf(scantext,"a-b c-d e-f  00");
	//	scantext[13] = '%';
	//	scantext[14] = 'd';
		index = 25;
		for(a=0;a<10;a++)
		{
			for(b=0;b<10;b++)
			{
				for(c=0;c<10;c++)
				{
					for(d=0;d<10;d++)
					{
						for(e=0;e<10;e++)
						{
							for(f=0;f<10;f++)
							{
								//fread( list, sizeof( char ), 35, str);
								/*scantext[0] = __toascii(a+48);
								scantext[2] = __toascii(b+48);
								scantext[4] = __toascii(c+48);
								scantext[6] = __toascii(d+48);
								scantext[8] = __toascii(e+48);
								scantext[10] = __toascii(f+48);*/
							//	sscanf(list, scantext,&antal_utfall);
							//int dummy;
							//ff=0;antal_utfall =0;
							//dummy =	sscanf(list,"%d-%d %d-%d %d-%d  %d",&aa,&bb,&cc,&dd,&ee,&ff,&antal_utfall);
								status = 0;
								antal_utfall = 0;
								do
								{
									if((status==0)&&(list[index++]=='-'))
									{
										aa = (list[index-2] - 48);
										bb = (list[index] - 48);
										index++;
										status = 1;
									}
									else if((status==1)&&(list[index++]=='-'))
									{
										cc = (list[index-2] -48);
										dd = (list[index] - 48);
										index++;
										status = 2;
									}
									else if((status ==2)&&(list[index++]=='-'))
									{
										ee = (list[index-2] -48);
										ff = (list[index] - 48);
										index++;
										status = 3;
									}
									else if((status ==3)&&((list[index]<'0')||(list[index]>'9')))
									{
										status = 3;
										index++;
									}
									else if((status ==3)&&((list[index]>='0')&&(list[index]<='9')))
									{
										antal_utfall=(list[index] -48);
										index++;
										status = 4;
									}
									else if((status ==4)&&((list[index]>='0')&&(list[index]<='9')))
									{
										antal_utfall = antal_utfall*10;
										antal_utfall = antal_utfall +(list[index]-48);
										//antal_utfall*=10+(list[index] -48);
										index++;
										status = 4;
									}
									else if((status ==4)&&((list[index]<'0')||(list[index]>'9')))
									{
										status = 10;
									}
									
								}while(status<10);
								float tempnomodds;
								tempnomodds = (float)antal_utfall/(float)antal_simu;
								if(tempnomodds >0)
								{
									tempnomodds = 1/tempnomodds;
								}
								else
								{
									tempnomodds = 0;
								}
								t1 = berakna_sannt_odds_for_en_kombination(a+c+e,b+d+f,1,true);
								tempnomodds = tempnomodds*t1;

								if ((tempnomodds > 0) && MAXRESOK(a, b, c, d, e, f,0,0))
									Odds->NyttOdds(a, b, c, d, e, f,0,0, tempnomodds);
								//if(a==9)
								//{
								//	int aaa;
								//	aaa=1;
								//}
							}
						}
					}
				}
			}
		}
//int test;
//test = 0;
		/////////////////////////////////////////////////////////////
	/*	for(a=0;a<11;a++)
		{
			for(b=0;b<11;b++)
			{
				t1 = berakna_sannt_odds_for_en_kombination(a,b,1,true);
				if  (t1 > 0.0)
						Odds->NyttOdds(a, b, 0, 0, 0, 0, t1);
			}
		}*/
		/////////////////////////////////////////////////////////////				
	}
}

void CBombDlg::OnSkapaRapportfil() 
{
	// Skapa spelfil först
	UpdateData(true);

	Odds->m_speltyp = m_speltyp;

	if (!Odds->SkapaSpel())
	{
		MessageBox("Kunde inte skapa spelfil", "Fel!");
		return;
	}
/*Tommy nytt 20120224*/
	CStdioFile beting;
	/*Tommy slut nytt 20120224*/
	CStdioFile report;
	char	filename[32];

	if (m_speltyp == 0)
		sprintf(filename, "SvenskFotboll.txt" ); 
	else if (m_speltyp == 1)
		sprintf(filename, "SvenskHockey.txt" ); 
	else if (m_speltyp == 2)
		sprintf(filename, "SvenskBandy.txt" ); 
	else if (m_speltyp == 3)
		sprintf(filename, "FinskFotboll.txt" ); 
	else if (m_speltyp == 4)
		sprintf(filename, "FinskHockey2Matcher.txt" ); 
	else if (m_speltyp == 5)
		sprintf(filename, "FinskHockey3Matcher.txt" ); 
	else if (m_speltyp == 6)
		sprintf(filename, "NorskFotboll.txt" ); 
	else if (m_speltyp == 7)
		sprintf(filename, "NorskHockey.txt" ); 
	else if (m_speltyp == 8)
		sprintf(filename, "SvenskHockey3Matcher.txt" ); 
	else if (m_speltyp == 9)
		sprintf(filename, "SvenskHockey3Perioder.txt" ); 
	else if (m_speltyp == 10)
		sprintf(filename, "SvenskBandy3Matcher.txt" ); 
	else if (m_speltyp == 11)
		sprintf(filename, "SvenskFotboll4Matcher.txt" ); 
	else if (m_speltyp == 12)
		sprintf(filename, "UnibetFotboll3Matcher.txt" ); 
	else if (m_speltyp == 13)
		sprintf(filename, "UnibetHockey2Matcher.txt" ); 
	else if (m_speltyp == 14)
		sprintf(filename, "UnibetFotboll2Matcher.txt" ); 



	if (report.Open( filename, CFile::modeWrite | CFile::modeCreate   , 0 ))
	{
	/*Tommy nytt 20120224*/
		beting.Open( "beting.txt", CFile::modeWrite | CFile::modeCreate   , 0 );
		float betingvektor[11][11][4];
		/*Tommy slut 20120224*/
		float TotBerIns = 0.0;			  // Total beräknad insats	
		float  SumSpelat = 0.0;
		float  SumSpelatHighOdds = 0.0;
		char buf[250];
		float  BerVinstChans = 0.0;	// Beräknad vinstchans	
		float Bervh = 0.0;
		float Bervl = 0.0;
		int anttot,anthog,antlag;
		anttot = 0;
		anthog = 0;
		antlag = 0;
/*Tommy nytt 20120224*/
		for(int ii=0;ii<11;ii++)
			for(int jj=0;jj<11;jj++)
				for(int kk=0;kk<4;kk++)
					betingvektor[ii][jj][kk]=0.0;
		/*Tommy slut 20120224*/
		report.WriteString("   Komb             Odds    Kvot Spelat belopp Beräknat spelbelopp\n");
		if(1 || Odds->m_speltyp == 0)
		{
			// Odds->BerIns();
			for (int i=0; i<MAXRES; i++)
				for (int j=0; j<MAXRES; j++)
					for (int k=0; k<MAXRES; k++)
						for( int l=0;l<MAXRES;l++)
							for(int m=0;m<MAXRES;m++)
								for(int n=0;n<MAXRES;n++)
									for(int o=0;o<MAXRES4;o++)
										for(int p=0;p<MAXRES4;p++)
									if (Odds->KBs(i,j,k,l,m,n,o,p) !=NULL)
									// if (Odds->KB[i][j][k][l][m][n][o][p] !=NULL)
									// if (Odds->KB[i][j][k][l][m][n] !=NULL &&
									//	(Odds->KB[i][j][k][l][m][n]->kvot >= m_minkvot || Odds->KB[i][j][k][l][m][n]->EjSpelad) &&
									//	(Odds->KB[i][j][k][l][m][n]->NOdds<m_minnomodds || m_minnomodds==0))
			
			{

 				// if(BerIns >= m_mininsats)
 				if (Odds->KBs(i,j,k,l,m,n,o,p)->insats > 0 || Odds->KBs(i,j,k,l,m,n,o,p)->spelad)
				{
					char KvotStr[32];
					if (Odds->KBs(i,j,k,l,m,n,o,p)->EjSpelad)
						sprintf(KvotStr, "Ej Spelad");
					else
						sprintf(KvotStr, "%6.3f" ,Odds->KBs(i,j,k,l,m,n,o,p)->kvot);

					// Spel i finland
					if (m_speltyp==3 || m_speltyp==4 || m_speltyp==5)
					{
						sprintf(buf, "%2d-%2d\t%2d-%2d\t%2d-%2d\t%12.2f\t%s\t%.2f\t%2.1f\n", i,j,k,l,m,n,
										Odds->KBs(i,j,k,l,m,n,0,0)->NOdds, KvotStr, 
										Odds->KBs(i,j,k,l,m,n,0,0)->optins,
										Odds->KBs(i,j,k,l,m,n,0,0)->spelat );
						/*Tommy nytt 20120224*/
					betingvektor[i][j][0]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					betingvektor[k][l][1]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					betingvektor[m][n][2]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					/*Tommy slut 20120224*/
					}
					// Svensk fotboll med 4 matcher
					else if (m_speltyp==11)
					{
						sprintf(buf, "%2d-%2d\t%2d-%2d\t%2d-%2d\t%2d-%2d\t%12.2f\t%s\t%.2f\t%2.0f\n", i,j,k,l,m,n,o,p,
										Odds->KBs(i,j,k,l,m,n,o,p)->NOdds, KvotStr, 
										Odds->KBs(i,j,k,l,m,n,o,p)->optins,
										Odds->KBs(i,j,k,l,m,n,o,p)->spelat );
/*Tommy nytt 20120224*/
					betingvektor[i][j][0]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					betingvektor[k][l][1]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					betingvektor[m][n][2]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					betingvektor[o][p][3]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					/*Tommy slut 20120224*/
					}
					// Unibet
					else if (m_speltyp==12 || m_speltyp==13 || m_speltyp==14)
					{
						sprintf(buf, "%2d-%2d\t%2d-%2d\t%2d-%2d\t%12.2f\t%s\t%.2f\t%.2f\n", i,j,k,l,m,n,
										Odds->KBs(i,j,k,l,m,n,o,p)->NOdds, KvotStr, 
										Odds->KBs(i,j,k,l,m,n,o,p)->optins,
										Odds->KBs(i,j,k,l,m,n,o,p)->spelat );
	/*Tommy nytt 20120224*/
					betingvektor[i][j][0]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					betingvektor[k][l][1]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					betingvektor[m][n][2]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					/*Tommy slut 20120224*/
					}

					// Sverige/Norge
					else
					{
						sprintf(buf, "%2d-%2d\t%2d-%2d\t%2d-%2d\t%12.2f\t%s\t%.2f\t%2.0f\n", i,j,k,l,m,n,
										Odds->KBs(i,j,k,l,m,n,o,p)->NOdds, KvotStr, 
										Odds->KBs(i,j,k,l,m,n,o,p)->optins,
										Odds->KBs(i,j,k,l,m,n,o,p)->spelat );
	/*Tommy nytt 20120224*/
					betingvektor[i][j][0]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					betingvektor[k][l][1]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					betingvektor[m][n][2]+=1/(Odds->KBs(i,j,k,l,m,n,o,p)->NOdds);
					/*Tommy slut 20120224*/
					}
					report.WriteString(buf);

					TotBerIns += Odds->KBs(i,j,k,l,m,n,o,p)->insats;
					
					// Beräkning av vinstchans
					if (Odds->KBs(i,j,k,l,m,n,o,p)->spelat > 0)
						BerVinstChans +=  1.0/Odds->KBs(i,j,k,l,m,n,o,p)->NOdds;
					
					anttot++;
					// Öka spelsumma
					SumSpelat += Odds->KBs(i,j,k,l,m,n,o,p)->spelat;
						
					// Spelsumma fö högoddsare
					if ( Odds->KBs(i,j,k,l,m,n,o,p)->NOdds  > m_omsattning/10.0)
						SumSpelatHighOdds += Odds->KBs(i,j,k,l,m,n,o,p)->spelat;

					if (Odds->KBs(i,j,k,l,m,n,o,p)->insats >= 10)
					{
						anthog++;
						Bervh+=1/Odds->KBs(i,j,k,l,m,n,o,p)->NOdds;
					}
					else if (Odds->KBs(i,j,k,l,m,n,o,p)->insats <= 1)
					{
						antlag++;
						Bervl+=1/Odds->KBs(i,j,k,l,m,n,o,p)->NOdds;
					}
				

				//	anttot++;
				}
			//sprintf(buf, "%2d-%2d\t%2d-%2d\t%2d-%2d\t %.2f  %.3f %.0f", i,j,k,l,m,n,Odds->KB[i][j][k][l][m][n]->NOdds*Odds->KB[i][j][k][l][m][n]->kvot, Odds->KB[i][j][k][l][m][n]->kvot,BerIns);
		//	report.WriteString(buf);
		//	report.WriteString("\n");
			//	BerVinstChans+=1/Odds->KB[i][j][k][l][m][n]->NOdds;
			}
		}
		sprintf(buf,"Beräknad vinstchans: %.2f Totsumma: %.1f Spelat %.1f\n", BerVinstChans, TotBerIns, SumSpelat);
		report.WriteString(buf);
		sprintf(buf,"Antal spelbara: %d Antal över 10: %d Antal enkronor: %d\n",anttot,anthog,antlag);
		report.WriteString(buf);
		sprintf(buf,"Vinstchans med komb. över 10 kronor: %.2f Vinstchans med enkronor: %.2f \n",Bervh,Bervl);
		report.WriteString(buf);

		sprintf(buf,"Spelat på odds över %.2f : %.2f kr\n", m_omsattning/10.0, SumSpelatHighOdds);
		report.WriteString(buf);

		report.Close();
	/*Tommy nytt 20120224*/
		sprintf(buf,"hemmaodds: %d    %d    %d    %d\n",m_m1_ett,m_m2_ett,m_m3_ett,m_m4_ett);
		beting.WriteString(buf);
		sprintf(buf,"Resultat   match1 match2 match3 match4\n");
		beting.WriteString(buf);
		for(int iii=0;iii<11;iii++)
			for(int jjj=0;jjj<11;jjj++)
			{
			//	sprintf(buf,"%d %d     ",iii,jjj);
				for(int kkk=0;kkk<4;kkk++)
				{
					double so;
					so = berakna_sannt_odds_for_en_kombination(iii,jjj,kkk+1,true);
					betingvektor[iii][jjj][kkk]*=so;
				//	
				//	sprintf(buf,"%.2f   ",betingvektor[iii][jjj][kkk]);
				}
				if((iii ==10)&&(jjj==10))
				{
					sprintf(buf,"F-F        %.2f   %.2f   %.2f   %.2f\n",betingvektor[iii][jjj][0],betingvektor[iii][jjj][1],betingvektor[iii][jjj][2],betingvektor[iii][jjj][3]);
					beting.WriteString(buf);
				}
				else if(jjj==10)
				{
					sprintf(buf,"%d-F        %.2f   %.2f   %.2f   %.2f\n",iii,betingvektor[iii][jjj][0],betingvektor[iii][jjj][1],betingvektor[iii][jjj][2],betingvektor[iii][jjj][3]);
					beting.WriteString(buf);
				}
				else if(iii==10)
				{
					sprintf(buf,"F-%d        %.2f   %.2f   %.2f   %.2f\n",jjj,betingvektor[iii][jjj][0],betingvektor[iii][jjj][1],betingvektor[iii][jjj][2],betingvektor[iii][jjj][3]);
					beting.WriteString(buf);
				}
				else
				{
				sprintf(buf,"%d-%d        %.2f   %.2f   %.2f   %.2f\n",iii,jjj,betingvektor[iii][jjj][0],betingvektor[iii][jjj][1],betingvektor[iii][jjj][2],betingvektor[iii][jjj][3]);
				beting.WriteString(buf);
				}
			}
		
		beting.Close();
		/*Tommy slut 20120224*/
		char cmdstr[64];
		sprintf(cmdstr, "notepad.exe  %s", filename);
		::WinExec(cmdstr, SW_SHOWNORMAL);  
	}
}


void CBombDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	delete Odds;
	CDialog::OnClose();
}

void CBombDlg::OnFileSave() 
{
	char name[100];
	UpdateData(true);
	CTime theTime = CTime::GetCurrentTime();
	sprintf(name, ".\\Bomb%02d%02d.txt", theTime.GetMonth(), theTime.GetDay());
	static char BASED_CODE szFilter[] = "Bombfiler (*.txt)|*.txt|All Files (*.*)|*.*||";

	CFileDialog dlg(FALSE, "txt", name, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, szFilter);

	dlg.m_ofn.lpstrTitle = "Spara spelomgång";

	if (dlg.DoModal() == IDOK && !Odds->Save( (LPCTSTR) dlg.GetPathName() ))
		MessageBox("Kunde inte spara", "Fel!");
}

void CBombDlg::OnFileOpen() 
{
	char name[100];
	CTime theTime = CTime::GetCurrentTime();
	sprintf(name, ".\\Bomb%02d%02d.txt", theTime.GetMonth(), theTime.GetDay());
	static char BASED_CODE szFilter[] = "Bombfiler (*.txt)|*.txt|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, "txt", name, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, szFilter);
	dlg.m_ofn.lpstrTitle = "Öppna spelomgång";

	if (dlg.DoModal() == IDOK && !Odds->Read(true, (LPCTSTR) dlg.GetPathName() ))
		MessageBox("Kunde inte öppna fil", "Fel!");
	m_OddsNum = Odds->NumOdds;

	UpdateData(false);
	Invalidate();
}
void CBombDlg::OnFileImport() 
{
	char name[100];
	CTime theTime = CTime::GetCurrentTime();
	sprintf(name, ".\\Bomb%02d%02d.txt", theTime.GetMonth(), theTime.GetDay());
	static char BASED_CODE szFilter[] = "Bombfiler (*.txt)|*.txt|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, "txt", name, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, 
		szFilter);
	dlg.m_ofn.lpstrTitle = "Importera odds";

	UpdateData(true);
	Odds->m_OspeladeForvalt = m_OspeladeForvalt;
	if (dlg.DoModal() == IDOK && !Odds->Read( false, (LPCTSTR) dlg.GetPathName() ))
		MessageBox("Kunde inte importera fil", "Fel!");
	m_OspeladeForvalt = Odds->m_OspeladeForvalt;

	m_OddsNum = Odds->NumOdds;
	UpdateData(false);
	Invalidate();
	
}


void CBombDlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	Odds->m_speltyp = m_speltyp;
	if (Odds->EgnaRader(m_BombbNr))
		MessageBox("EgnaRader-fil(er) skapade", "Meddelande");
	//	::WinExec("notepad.exe EgnaRader.txt", SW_SHOWNORMAL);  
	
}

// Starta trådinläsning 
void CBombDlg::OnButton5() 
{
	COddsLas dialog;

	UpdateData(true);
	Odds->m_Instanser = m_Instanserr;
	Odds->m_speltyp = m_speltyp;
	Odds->m_minsida = m_minsida;
	Odds->m_maxsida = m_maxsida;
	Odds->m_OspeladeForvalt = m_OspeladeForvalt;
	Odds->m_UpprepaForvalt = m_AutoInlasning;	// Vid autostart

	Odds->mh1 = m_m1_maxmal_hemma;
	Odds->mb1 = m_m1_maxmal_borta;
	Odds->mh2 = m_m2_maxmal_hemma;
	Odds->mb2 = m_m2_maxmal_borta;
	Odds->mh3 = m_m3_maxmal_hemma;
	Odds->mb3 = m_m3_maxmal_borta;
	Odds->mh4 = m_m4_maxmal_hemma;
	Odds->mb4 = m_m4_maxmal_borta;
	Odds->m_matchid = m_MatchIDNr;
	Odds->m_omsattning = m_omsattning;
	Odds->m_en_krona_ospelad = m_en_krona_ospelad;
	Odds->MissadeSidor = 0;
	ShowWindow(SW_SHOWMINIMIZED);
	
	dialog.DoModal();
	// dialog->InitModalIndirect(this);

	ShowWindow(SW_SHOWNORMAL);
	// Visa inslästa odds
	m_OddsNum = Odds->NumOdds;
	m_OspeladeForvalt = false;
	UpdateData(false);
	Invalidate(false);
	RedrawWindow();

	//delete dialog; 
	//CWinThread
}

void CBombDlg::OnSpelTypRadio() 
{
	UpdateData(true);	

	// Spel i sverige
	if (m_speltyp  < 3  || 5 < m_speltyp)
	{
		m_mininsats = 0.5;
		m_AterBet = 0.6;

		if (m_speltyp==0 || m_speltyp==6 || m_speltyp==11)  // --> Fotboll
		{
			m_omsattning = 100000;
			m_minkvot = 1.2;
		}
		else if (m_speltyp==1 || m_speltyp==2 || m_speltyp==7 || m_speltyp==8 || m_speltyp==10)  // --> Hockey/Bandy
		{
			m_omsattning = 570000;
			m_minkvot = 1.35;
		}
		// --> Spel pa Unibet fotboll
		else if (m_speltyp==12)  
		{
			m_omsattning = 2500;
			m_minkvot = 1.2;
			m_mininsats = 0.05;
			m_AterBet = 0.8;
		}

		// --> Spel pa Unibet hockey eller fotboll 2 matcher
		else if (m_speltyp==13 || m_speltyp==13)  
		{
			m_omsattning = 2500;
			m_minkvot = 1.35;
			m_mininsats = 0.05;
			m_AterBet = 0.8;
		}
	} else {	// Spel i finland
		m_mininsats = 0.1;
		m_AterBet = 0.7;
	}

	if (m_speltyp==11)
			SetWindowPos(&CWnd::wndTop, 0, 0, 830, 550, SWP_NOMOVE);
	else
			SetWindowPos(&CWnd::wndTop, 0, 0, 600, 550, SWP_NOMOVE);

	UpdateData(false);	
}


void CBombDlg::OnEditPaste() 
{
	char buf[255];

	UpdateData(true);
	if (! ::IsClipboardFormatAvailable(CF_TEXT)  ||  !::OpenClipboard(NULL))
	{
		MessageBox("Kan ej läsa klippbok", "Message!");
		return;
	}
	// Läs från klippboken och scanna odds 
	char  *pClb;
	int sret, H1, O1, B1, H2, O2, B2, H3, O3, B3, H4, O4, B4;

	pClb = (char *)::GetClipboardData( CF_TEXT );

	// Specialkopiera sträng i klippbok
	for (int i=0; i<sizeof(buf); i++)
	{
		char c;
		c=pClb[i];
		// olika teckenvarianter av '-'
		if (c== -106)
			c='-';

		buf[i]=c;
		if (c=='\0')
			break;
	}
	buf[ sizeof(buf)-1 ]='\0';


	sret=sscanf(buf, "%d%d%d -%d%d%d -%d%d%d -%d%d%d", &H1, &O1, &B1, &H2, &O2, &B2, &H3, &O3, &B3, &H4, &O4, &B4);
	
	

	// Fotboll eller hocky/bandy med 3 matcher  -->
	if (sret==9 && (m_speltyp==0 || m_speltyp==3 || m_speltyp==6 || m_speltyp==8 || m_speltyp==10 || m_speltyp==12))
	{
		m_m1_ett	= H1;
		m_m1_kryss	= O1;
		m_m1_tva	= B1;
		m_m2_ett	= H2;
		m_m2_kryss	= O2;
		m_m2_tva	= B2;
		m_m3_ett	= H3;
		m_m3_kryss	= O3;
		m_m3_tva	= B3;

		UpdateData(false);
	}
	// Hocky/Bandy/Fotboll med 2 matcher -->
	else if (sret==6 && (m_speltyp==1 || m_speltyp==2 || m_speltyp==4 || m_speltyp==7 || m_speltyp==13 || m_speltyp==14))
	{
		m_m1_ett	= H1;
		m_m1_kryss	= O1;
		m_m1_tva	= B1;
		m_m2_ett	= H2;
		m_m2_kryss	= O2;
		m_m2_tva	= B2;
		m_m3_ett	= 0;
		m_m3_kryss	= 0;
		m_m3_tva	= 0;


		UpdateData(false);
	}
	// Fotboll med 4 matcher  -->
	else if (sret==12 && m_speltyp==11)
	{
		m_m1_ett	= H1;
		m_m1_kryss	= O1;
		m_m1_tva	= B1;
		m_m2_ett	= H2;
		m_m2_kryss	= O2;
		m_m2_tva	= B2;
		m_m3_ett	= H3;
		m_m3_kryss	= O3;
		m_m3_tva	= B3;
		m_m4_ett	= H4;
		m_m4_kryss	= O4;
		m_m4_tva	= B4;

		UpdateData(false);
	}
	else 
		MessageBox("Kan ej läsa klippbok", "Message!");



//230 295 210 - 200 300 240 - 250 310 190
//230 295 210 200 300 240 250 310 190
									

	::CloseClipboard();

}

void CBombDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	LasOddsiSpelFonster();
}
// Returnerar lägsta nominella odds för en
float CBombDlg::GetMinNomOdds(TBONG *bong)
{	float ret =  10000000.0; // Initiera till omrimlig stort värde

	for (int i=0; i<bong->h1index; i++)
 	  for (int j=0; j<bong->b1index; j++)
		for (int k=0; k<bong->h2index; k++)
		  for (int l=0; l<bong->b2index; l++)
			for (int m=0; m<bong->h3index; m++)
			  for (int n=0; n<bong->b3index; n++)
				  for(int o=0; o<bong->h4index;o++)
					  for(int p=0;p<bong->b4index;p++)
			// Check mot max antal mål
			if (MAXRESOK(bong->h1list[i], bong->b1list[j], bong->h2list[k], bong->b2list[l],
				         bong->h3list[m], bong->b3list[n], bong->h4list[o], bong->b4list[p]))
			{
				TKombination *K;
				K = Odds->KBs(	bong->h1list[i], bong->b1list[j], bong->h2list[k], bong->b2list[l], 
								bong->h3list[m], bong->b3list[n], bong->h4list[o], bong->b4list[p]);

				// Om nominells odds finns tillgänglig OCH lägst hittills
				if (K != NULL && K->NOdds > 0.0  && K->NOdds < ret)
					ret = K->NOdds;
			}
	return ret;
}

// Returnerar true om alla resultat har blivit tilldelade en kvot
bool CBombDlg::HarAllaKvoter(TBONG *bong)
{
	for (int i=0; i<bong->h1index; i++)
 	  for (int j=0; j<bong->b1index; j++)
		for (int k=0; k<bong->h2index; k++)
		  for (int l=0; l<bong->b2index; l++)
			for (int m=0; m<bong->h3index; m++)
			  for (int n=0; n<bong->b3index; n++)
				  for(int o=0;o<bong->h4index; o++)
					  for(int p=0;p<bong->b4index; p++)

			// Check mot max antal mål
			if (MAXRESOK(bong->h1list[i], bong->b1list[j], bong->h2list[k], bong->b2list[l],
				         bong->h3list[m], bong->b3list[n], bong->h4list[o], bong->b4list[p]))
			{
				TKombination *K;
				K = Odds->KBs(	bong->h1list[i], bong->b1list[j], bong->h2list[k], bong->b2list[l], 
								bong->h3list[m], bong->b3list[n], bong->h4list[o], bong->b4list[p]);

				// Om nominellt odds finns men inte kvot --> returnera false
				if (K != NULL && K->NOdds > 0.0  && K->kvot == 0.0 && !K->EjSpelad)
					return false;
			}
	return true;
}
bool CBombDlg::SplittaBong(TBONG *bong1, TBONG *bong2, TBONG *bong3)
{
	bool splittad = false;
	// Initiera 
	memcpy(bong2, bong1, sizeof(TBONG));
	memcpy(bong3, bong1, sizeof(TBONG));

	if (bong1->h1index == 2)
	{
		bong3->h1list[0] = bong3->h1list[1];
		bong2->h1index = 1;
		bong3->h1index = 1;
		return true;
	}
	if (bong1->b1index == 2)
	{
		bong3->b1list[0] = bong3->b1list[1];
		bong2->b1index = 1;
		bong3->b1index = 1;
		return true;
	}
	if (bong1->h2index == 2)
	{
		bong3->h2list[0] = bong3->h2list[1];
		bong2->h2index = 1;
		bong3->h2index = 1;
		return true;
	}
	if (bong1->b2index == 2)
	{
		bong3->b2list[0] = bong3->b2list[1];
		bong2->b2index = 1;
		bong3->b2index = 1;
		return true;
	}
	if (bong1->h3index == 2)
	{
		bong3->h3list[0] = bong3->h3list[1];
		bong2->h3index = 1;
		bong3->h3index = 1;
		return true;
	}
	if (bong1->b3index == 2)
	{
		bong3->b3list[0] = bong3->b3list[1];
		bong2->b3index = 1;
		bong3->b3index = 1;
		return true;
	}

	if (bong1->h1index == 6)
	{
		bong3->h1list[0] = bong3->h1list[3]; 
		bong3->h1list[1] = bong3->h1list[4]; 
		bong3->h1list[2] = bong3->h1list[5];
		bong2->h1index = 3;
		bong3->h1index = 3;
		return true;
	}
	if (bong1->b1index == 6)
	{
		bong3->b1list[0] = bong3->b1list[3]; 
		bong3->b1list[1] = bong3->b1list[4]; 
		bong3->b1list[2] = bong3->b1list[5];
		bong2->b1index = 3;
		bong3->b1index = 3;
		return true;
	}
	if (bong1->h2index == 6)
	{
		bong3->h2list[0] = bong3->h2list[3]; 
		bong3->h2list[1] = bong3->h2list[4]; 
		bong3->h2list[2] = bong3->h2list[5];
		bong2->h2index = 3;
		bong3->h2index = 3;
		return true;
	}
	if (bong1->b2index == 6)
	{
		bong3->b2list[0] = bong3->b2list[3]; 
		bong3->b2list[1] = bong3->b2list[4]; 
		bong3->b2list[2] = bong3->b2list[5];
		bong2->b2index = 3;
		bong3->b2index = 3;
		return true;
	}
	if (bong1->h3index == 6)
	{
		bong3->h3list[0] = bong3->h3list[3]; 
		bong3->h3list[1] = bong3->h3list[4]; 
		bong3->h3list[2] = bong3->h3list[5];
		bong2->h3index = 3;
		bong3->h3index = 3;
		return true;
	}
	if (bong1->b3index == 6)
	{
		bong3->b3list[0] = bong3->b3list[3]; 
		bong3->b3list[1] = bong3->b3list[4]; 
		bong3->b3list[2] = bong3->b3list[5];
		bong2->b3index = 3;
		bong3->b3index = 3;
		return true;
	}
	return false;
}
void CBombDlg::MouseClickLeft(DWORD Xpos, DWORD Ypos)
{
	
    mouse_event(MOUSEEVENTF_LEFTUP |MOUSEEVENTF_ABSOLUTE |MOUSEEVENTF_MOVE,	Xpos, Ypos, 120, 0);
	mouse_event(MOUSEEVENTF_ABSOLUTE |MOUSEEVENTF_LEFTDOWN,					Xpos, Ypos, 0, 0);
	mouse_event(MOUSEEVENTF_ABSOLUTE |MOUSEEVENTF_LEFTUP,					Xpos, Ypos, 0, 0 );

}
void CBombDlg::MouseClickRight(DWORD Xpos, DWORD Ypos)
{
	
    mouse_event(MOUSEEVENTF_RIGHTUP |MOUSEEVENTF_ABSOLUTE |MOUSEEVENTF_MOVE,	Xpos, Ypos, 120, 0);
	mouse_event(MOUSEEVENTF_ABSOLUTE |MOUSEEVENTF_RIGHTDOWN,					Xpos, Ypos, 0, 0);
	mouse_event(MOUSEEVENTF_ABSOLUTE |MOUSEEVENTF_RIGHTUP,						Xpos, Ypos, 0, 0 );

}
void CBombDlg::LasOddsiSpelFonster() 
{
	HWND		hChild;
    RECT		Childrc;
	CMalGrupp	MalGrupp;
	TBONG		bong1, bong2;
	int			i, delay1 = 350;	// Väntetid mellan kryssning och läsning
	bool		err = false;

	UpdateData( true );
	if ((hChild=HittaSpelFonster(5000)) == NULL)
	{
		MessageBox( "Hitta inte fönstret: Svenska Spel - Microsoft Internet Explorer - Tele2Internet",  "Timeout!", MB_OK );
		return;
	}
	::GetWindowRect(hChild, &Childrc);
	MouseClickLeft(XPOS(Childrc.left+250), YPOS(Childrc.top+10));  // Wake up window

	// Svensk Bandy eller ishockey med 2 matcher  eller UNIBET med två matcher-->
	if (m_speltyp == 1 || m_speltyp == 2  || m_speltyp == 13 || m_speltyp == 14)
	{ 

		bong1.h1index =MAXRES;
		bong1.b1index =MAXRES;
		bong1.h2index =1;
		bong1.b2index =1;
		bong1.h3index =1;  // 0 - 0 i match 3 och 4
		bong1.b3index =1;
		bong1.h4index =1;
		bong1.b4index =1;
		
		for (i=0; i<12; i++)
		{
			bong1.h1list[i] = i;
			bong1.b1list[i] = i;
		}
		bong1.h3list[0] = 0;
		bong1.b3list[0] = 0;
		bong1.h4list[0] = 0;
		bong1.b4list[0] = 0;

		for (i= 0; i<MAXRES; i++)
		  for (int j= 0; j<MAXRES; j++)
		  {

			bong1.h2list[0] = i;
			bong1.b2list[0] = j;

			float minnoodds;
			minnoodds = GetMinNomOdds(&bong1);


			if (!HarAllaKvoter(&bong1) &&
				  ((!m_OddsOspelActive && (minnoodds < m_omsattning * m_AterBet / 1.2) && (minnoodds < m_minnomodds))
				||  (m_OddsOspelActive && (minnoodds < m_OddsOspelade))))
			{

				// Kryssa bong i spelfönster mha "bong2"
				// Spel i Sverige --> 	
				if (!UNIBETSPEL(m_speltyp))
					scrn.LasRes(hChild, VXOFFS(m_WV), VYOFFS(m_WV), &bong2, ANTALMATCHER(m_speltyp));
				else {
					UnibetYpos = scrn.GetUnibetYpos2(hChild, ANTALMATCHER(m_speltyp));
					if (UnibetYpos==0)
					{
						MessageBox("Ypos är noll\nFörsök igen.", "Fel!");
						return;
					}
					if (XPos.xh1 == 0)
					{
						MessageBox( "Utför Postest", MB_OK );
						return;
					}
					scrn.LasResUnibet(hChild, &bong2, ANTALMATCHER(m_speltyp), &XPos);
				}

				// Spel i Sverige --> 	
				if (!UNIBETSPEL(m_speltyp) && !KryssaBong(&Childrc, &bong1, &bong2))
				{
					MessageBox("Kunde inte kryssa  bong.\nFörsök igen.", "Fel!");
					err = true;
				}
				// Spel på Unibet -->
				if (UNIBETSPEL(m_speltyp) && !KryssaBongUnibet(&Childrc, &bong1, &bong2))
				{
					MessageBox("Kunde inte kryssa  bong.\nFörsök igen.", "Fel!");
					err = true;
				}
				// Läs odds i spelfönster mha klippbok
				if (!err && !LasOddsiSpelfonster())
					err = true;

				// Har alla odds i "bong1" lästs in
				if (!err && !HarAllaKvoter(&bong1))
				{
					MessageBox("Alla odds kunde inte läsas.\nFörsök igen.", "Fel!");
					err = true;
				}
				// Spara till fil
				if (!err && !Odds->SparaSomDagfil()) 
				{
					MessageBox("Kunde inte spara", "Fel!");
					err = true;
				}
				// Error occured --> Leave
				if (err)
				{
					m_KryssaAktiv = false;
					UpdateData(false);	
					Invalidate(false);
					SetFocus();
					return;	
				}
				m_OddsNum = Odds->NumOdds;
				UpdateData(false);
				Invalidate(false);
				RedrawWindow();
			}
		 }
	
	
	}
	// Fotboll, Bandy eller ishockey  med 3 matcher -->
	else if (TRE(m_speltyp))
	{ 
	  int InlasNr = 0;									// Inläsnings nummer  (används för att spara till fil).
	  int max_mh1, max_mb1, max_mh2, max_mb2, max_mh3;	
	  
	  // Spel i Sverige --> 	
	  if (m_speltyp!=12)
	  {
		max_mh1 = 3;
		max_mb1 = 3;
		max_mh2 = 4;
		max_mb2 = 6;
		max_mh3 = 6;
	  }
	  // Spel på Unibet --> 	
	  else
	  {
		max_mh1 = 4;
		max_mb1 = 4;
		max_mh2 = 6;
		max_mb2 = 6;
		max_mh3 = 6;
	  }
	  for (int mh1 = 0; mh1<max_mh1; mh1++)
	   for (int mb1 = 0; mb1<max_mb1; mb1++)
	    for (int mh2 = 0; mh2<max_mh2; mh2++)
	     for (int mb2 = 0; mb2<max_mb2; mb2++)
	      for (int mh3 = 0; mh3<max_mh3; mh3++)
	       for (int mb3 = m_MinMalGrp; mb3<=m_MaxMalGrp; mb3++)


			{
				float minnoodds;
				
				// Spel i Sverige --> 	
				if (m_speltyp!=12)
				  MalGrupp.GetBongHocky3A(mh1,mb1,mh2,mb2,mh3,mb3,&bong1);
				else
				  MalGrupp.GetBongUnibet3(mh1,mb1,mh2,mb2,mh3,mb3,&bong1);

				minnoodds = GetMinNomOdds(&bong1);

				if (!HarAllaKvoter(&bong1) &&
					  ((!m_OddsOspelActive && (minnoodds < m_omsattning * m_AterBet / 1.2) && (minnoodds < m_minnomodds))
					||  (m_OddsOspelActive && (minnoodds < m_OddsOspelade))))
					
				{	// Spela/Läs en bong	

					
					// Kryssa bong i spelfönster mha "bong2"
					// Spel i Sverige --> 	
					if (m_speltyp!=12)
						scrn.LasRes(hChild, VXOFFS(m_WV), VYOFFS(m_WV), &bong2, ANTALMATCHER(m_speltyp));
					else {
						UnibetYpos = scrn.GetUnibetYpos2(hChild, ANTALMATCHER(m_speltyp));
						if (UnibetYpos==0)
						{
							MessageBox("Ypos är noll\nFörsök igen.", "Fel!");
							return;
						}
						if (XPos.xh1 == 0)
						{
							MessageBox( "Utför Postest", MB_OK );
							return;
						}
						scrn.LasResUnibet(hChild, &bong2, ANTALMATCHER(m_speltyp), &XPos);
					}
					// Spel i Sverige --> 	
					if (m_speltyp!=12 && !KryssaBong(&Childrc, &bong1, &bong2))
					{
						MessageBox("Kunde inte kryssa  bong.\nFörsök igen.", "Fel!");
						err = true;
					}
					// Spel på Unibet -->
					if (m_speltyp==12 && !KryssaBongUnibet(&Childrc, &bong1, &bong2))
					{
						MessageBox("Kunde inte kryssa  bong.\nFörsök igen.", "Fel!");
						err = true;
					}
					// Läs odds i spelfönster mha klippbok
					if (!err && !LasOddsiSpelfonster())
						err = true;
					// Har alla odds i "bong1" lästs in
					if (!err && !HarAllaKvoter(&bong1))
					{
						MessageBox("Alla odds kunde inte läsas.\nFörsök igen.", "Fel!");
						err = true;	
					}
					// Spara var  20:de inläsning till fil
					if (!err && (InlasNr%20 == 0) && !Odds->SparaSomDagfil()) 
					{
						MessageBox("Kunde inte spara", "Fel!");
						err = true;
					}
					InlasNr ++; // Incrementera här så att spara alltid sker första gången

					// Error occured --> Leave
					if (err)
					{
						m_KryssaAktiv = false;
						UpdateData(false);	
						Invalidate(false);
						SetFocus();
						return;	
					}
					m_OddsNum = Odds->NumOdds;
					UpdateData(false);
					Invalidate(false);
					RedrawWindow();
				}
				// Starta timer igen
				//int timID =SetTimer(1, 50, 0);
			}
	}  
	// Svensk Fotboll med 4 matcher -->
	else if (m_speltyp==11)
	{ 
	  int InlasNr = 0;									// Inläsnings nummer  (används för att spara till fil).
	  // Inläsning enligt modell 3x2 - 2x2 - 2x2 -2x2
	  // Maxgränser med 6 resultat blir
	  for (int mh1 = 0; mh1<2; mh1++)
	  for (int mb1 = 0; mb1<3; mb1++)
	  for (int mh2 = 0; mh2<3; mh2++)
	  for (int mb2 = 0; mb2<3; mb2++)
	  for (int mh3 = 0; mh3<3; mh3++)
	  for (int mb3 = 0; mb3<3; mb3++)
	  for (int mh4 = 0; mh4<3; mh4++)
	  for (int mb4 = m_MinMalGrp; mb4<=m_MaxMalGrp; mb4++)
		// for (int b4 = m_MinMalGrp; b4<=m_MaxMalGrp && b4<MAXRES4; b4++)
			{
				float minnoodds;
				MalGrupp.GetBongFotboll4(mh1,mb1,mh2,mb2,mh3,mb3,mh4,mb4,&bong1);
				
				minnoodds = GetMinNomOdds(&bong1);

				if (!HarAllaKvoter(&bong1) &&
					  ((!m_OddsOspelActive && (minnoodds < m_omsattning * m_AterBet / 1.2) && (minnoodds < m_minnomodds))
					||  (m_OddsOspelActive && (minnoodds < m_OddsOspelade))))
					
				{	// Spela/Läs en bong	

					
					// Kryssa bong i spelfönster mha "bong2"
					scrn.LasRes(hChild, VXOFFS(m_WV), VYOFFS(m_WV), &bong2, ANTALMATCHER(m_speltyp));

					if (!KryssaBong(&Childrc, &bong1, &bong2))
					{
						MessageBox("Kunde inte kryssa  bong.\nFörsök igen.", "Fel!");
						err = true;
					}
					// Läs odds i spelfönster mha klippbok
					if (!err && !LasOddsiSpelfonster())
						err = true;
					// Har alla odds i "bong1" lästs in
					if (!err && !HarAllaKvoter(&bong1))
					{
						MessageBox("Alla odds kunde inte läsas.\nFörsök igen.", "Fel!");
						err = true;	
					}
					// Spara var  20:de inläsning till fil
					if (!err && (InlasNr%20 == 0) && !Odds->SparaSomDagfil()) 
					{
						MessageBox("Kunde inte spara", "Fel!");
						err = true;
					}
					InlasNr ++; // Incrementera här så att spara alltid sker första gången

					// Error occured --> Leave
					if (err)
					{
						m_KryssaAktiv = false;
						UpdateData(false);	
						Invalidate(false);
						SetFocus();
						return;	
					}
					m_OddsNum = Odds->NumOdds;
					UpdateData(false);
					Invalidate(false);
					RedrawWindow();
				}
				// Starta timer igen
				//int timID =SetTimer(1, 50, 0);
			}
	}  

	//	Inläsning klar
	m_KryssaAktiv = false;;
	UpdateData(false);	
	Invalidate();
}
bool CBombDlg::LasOddsiSpelfonster()
{
	HWND hChild;
    RECT Childrc;
	int i, AntalOdds = 0;	// Antal inlästa odds

	if ((hChild=HittaSpelFonster(5000)) == NULL)
	{
		MessageBox( "Hitta inte fönstret: Svenska Spel - Microsoft Internet Explorer  - Tele2Internet",  "Timeout!", MB_OK );
		return false;
	}
	::GetWindowRect(hChild, &Childrc);

	// Spel i Sverige --> Välj Mitt Vad som alternativ
	if (!UNIBETSPEL(m_speltyp))
	{
		MouseClickLeft(XPOS(Childrc.left+VXOFFS(m_WV)+400), YPOS(Childrc.top+VYOFFS(m_WV)+154));
		::Sleep(2 * m_DelayClp);
		for (i=0; i<100 && !scrn.OddsInlast(hChild, VXOFFS(m_WV), VYOFFS(m_WV)); i++)
			::Sleep(100);

		if (!scrn.OddsInlast(hChild, VXOFFS(m_WV), VYOFFS(m_WV)))
		{
			MessageBox("Odds presenteras inte i spelfönster", "Message!");
			return false;
		}
		// Använd ctrl-A + ctrl-C för att kopiera till klippbok
		MouseClickLeft(XPOS(Childrc.left+VXOFFS(m_WV)+400), YPOS(Childrc.top+VYOFFS(m_WV)+270));
		::Sleep(m_DelayClp);
		keybd_event(VK_CONTROL,0, 0, 0);
		::Sleep(m_DelayClp);
		keybd_event('A',0, 0, 0);
		::Sleep(m_DelayClp);
		keybd_event('C',0, 0, 0);
		::Sleep(m_DelayClp);
		keybd_event(VK_CONTROL,0, KEYEVENTF_KEYUP, 0);
		::Sleep(m_DelayClp);

		/* MouseClickRight(XPOS(Childrc.left+VXOFFS(m_WV)+400), YPOS(Childrc.top+VYOFFS(m_WV)+270));
		::Sleep(m_DelayClp/2);
		MouseClickLeft(XPOS(Childrc.left+VXOFFS(m_WV)+430), YPOS(Childrc.top+VYOFFS(m_WV)+354));
		::Sleep(m_DelayClp/2);

		MouseClickRight(XPOS(Childrc.left+VXOFFS(m_WV)+400), YPOS(Childrc.top+VYOFFS(m_WV)+270));
		::Sleep(m_DelayClp/2);

		MouseClickLeft(XPOS(Childrc.left+VXOFFS(m_WV)+430), YPOS(Childrc.top+VYOFFS(m_WV)+300));
		::Sleep(m_DelayClp/2);
		*/
	}
	// Spel på Unibet --> Välj ??? alternativ
	if (UNIBETSPEL(m_speltyp))
	{
		::Sleep(200);

		// mouse_event(MOUSEEVENTF_LEFTUP |MOUSEEVENTF_ABSOLUTE |MOUSEEVENTF_MOVE,	
		//	XPOS(Childrc.left+600), YPOS(UnibetYpos+Childrc.top-102), 120, 0);
		//::Sleep(150);

		// Klicka på info-flält
		::Sleep(350);
		MouseClickLeft(XPOS(Childrc.left+600), YPOS(UnibetYpos+Childrc.top+6));
		::Sleep(350);

		//Klicka på odds-fält
		MouseClickLeft(XPOS(Childrc.left+600), YPOS(UnibetYpos+Childrc.top-10));
		::Sleep(300);
		scrn.Read(hChild);
		for (i=0; i<70 && !scrn.OddsInlastUnibet(UnibetYpos+44-10); i++)
		{
			::Sleep(100);
			scrn.Read(hChild);
		}

		keybd_event(VK_CONTROL,0, 0, 0);
		::Sleep(100);
		keybd_event('A',0, 0, 0);
		::Sleep(100);
		keybd_event('C',0, 0, 0);
		::Sleep(100);
		keybd_event(VK_CONTROL,0, KEYEVENTF_KEYUP, 0);
		::Sleep(100);
	}



	for (i=0; i<20 && !::IsClipboardFormatAvailable(CF_TEXT); i++)
		::Sleep(200);
	
	::Sleep(m_DelayClp);
	if (! ::IsClipboardFormatAvailable(CF_TEXT))
	{
		MessageBox("Kan ej läsa klippboksformat", "Message!");
		return false;
	}
	// Läs från klippboken
	char  *pClb, *p;
	if ( !::OpenClipboard(hChild))
		MessageBox("Kan inte öppna klippbok","Meddelande",  MB_OK);
	
	else if ((pClb = (char *)::GetClipboardData( CF_TEXT )) != NULL)
	{
    	p=pClb;
		CListBox* pL1 = (CListBox *)GetDlgItem(IDC_LIST1);
		while (*p != NULL)
		{
			int H1, B1, H2, B2, H3, B3, H4, B4, sret;
			float Bel1, Bel2, Bel3, BelL, Bel, BelH;
			char str[250];

			/*for (i=0; (p[i]!=NULL && p[i]!='\n' && i<250-1); i++)
				str[i] = p[i];
			str[i] ='\0';
			*/

			char *q=str;

			for (i=0; (p[i]!=NULL && p[i]!='\n' && i<250-1); i++)
				if (p[i] == '+')
					;
				else
					*q++ = p[i];

			*q ='\0';

			if (TRE(m_speltyp))
			{
				char *q, ch1, cb1, ch2, cb2, ch3, cb3;

				 	
				if (m_speltyp!=12)	// Spel i Sverige -->
					sret=sscanf(str, "%c-%c %c-%c %c-%c%f%f%f", &ch1, &cb1, &ch2, &cb2, &ch3, &cb3, &Bel1, &Bel2, &Bel3);
				else				// Spel pa Unibet -->
					sret=sscanf(str, "%c-%c %c-%c %c-%c%f,%f%f", &ch1, &cb1, &ch2, &cb2, &ch3, &cb3, &Bel1, &Bel2, &Bel3);

				if (sret >5)
				{
					char str[100];
				
					H1 = (ch1=='F') ? 10 : ch1-'0';
					B1 = (cb1=='F') ? 10 : cb1-'0';
					H2 = (ch2=='F') ? 10 : ch2-'0';
					B2 = (cb2=='F') ? 10 : cb2-'0';
					H3 = (ch3=='F') ? 10 : ch3-'0';
				
					B3 = (cb3=='F') ? 10 : cb3-'0';

					if (sret == 6)  // Ej spelad
						Bel=0;
					else if (sret == 7)
						Bel=Bel1;
					else if (sret == 8)
						Bel = Bel1*1000.0 + Bel2;
					else
						Bel = Bel1*1000000.0 + Bel2*1000.0 + Bel3;

					if (MAXRESOK(H1,B1,H2,B2,H3,B3,0,0) && Odds->KBs(H1,B1,H2,B2,H3,B3,0,0) != NULL)
					{
						// Spel i Sverige(och Unibet) -->

						if(Odds->KBs(H1,B1,H2,B2,H3,B3,0,0)->NOdds > 0)
						{
							// Odds > Oms*0.6 någon --> Kombination ospelad
							if (sret == 6)  // Ej spelad
							{						
								Odds->KBs(H1,B1,H2,B2,H3,B3,0,0)->EjSpelad = true;
								Odds->KBs(H1,B1,H2,B2,H3,B3,0,0)->kvot=0.0;
							}
							else 
								Odds->KBs(H1,B1,H2,B2,H3,B3,0,0)->kvot = m_KvotJust * Bel / Odds->KBs(H1,B1,H2,B2,H3,B3,0,0)->NOdds;
						}

						// Spel på Unibet (med aktuella odds) -->
						// else if (m_speltyp==12 && Odds->KBs(H1,B1,H2,B2,H3,B3,0,0)->NOdds > 0)
						//		Odds->KBs(H1,B1,H2,B2,H3,B3,0,0)->kvot = m_KvotJust * Bel / Odds->KBs(H1,B1,H2,B2,H3,B3,0,0)->NOdds;

						else  // Ej med i tabell
							Odds->KBs(H1,B1,H2,B2,H3,B3,0,0)->kvot= 0.0;
					}
					// Uppdatera antal inlästa odds
					if (!Odds->last[H1][B1][H2][B2][H3][B3][0][0])
						Odds->NumOdds ++;
					Odds->last[H1][B1][H2][B2][H3][B3][0][0] = true;
				}
			
			}			


			// Fotboll med fyra matcher -->
			else if (m_speltyp==11)
			{
				sret=sscanf(str, "%d-%d %d-%d %d-%d %d-%d %f%f%f", &H1, &B1, &H2, &B2, &H3, &B3, &H4, &B4, &Bel1, &Bel2, &Bel3);
				if (sret>7)
				{
					char str[100];

					if (sret == 9)
						Bel=Bel1;
					else if (sret == 10)
						Bel = Bel1*1000.0 + Bel2;
					else
						Bel = Bel1*1000000.0 + Bel2*1000.0 + Bel3;

					if (H1==0&&B1==0 && H2==0&&B2==0 && H3==0&&B3==0 && H4==0&&B4==0)
						H1=0;

					if (MAXRESOK(H1,B1,H2,B2,H3,B3,H4,B4) && Odds->KBs(H1,B1,H2,B2,H3,B3,H4,B4) != NULL)
					{
						if(Odds->KBs(H1,B1,H2,B2,H3,B3,H4,B4)->NOdds > 0)
						{
							// Justera oddsbelopp					
							float s4 = berakna_sannt_odds_for_en_kombination(H4,B4,4,true);

							// Odds > Oms*0.6 någon --> Kombination ospelad
							if (m_KvotJust*Bel > m_omsattning*m_AterBet* 0.5/m_mininsats)
							{						
								Odds->KBs(H1,B1,H2,B2,H3,B3,H4,B4)->EjSpelad = true;
								Odds->KBs(H1,B1,H2,B2,H3,B3,H4,B4)->kvot=0.0;
							}
							else {	
								float fodds = Bel; // Faktiskt odds enl gamla modellen (med dittills satsade belopp)
								float namnare = 1.0* (int( m_AterBet*m_omsattning/Bel + 0.500001 ) - 1 );
								if (namnare > 0)
									fodds = m_AterBet * m_omsattning  / namnare;

								Odds->KBs(H1,B1,H2,B2,H3,B3,H4,B4)->kvot = m_KvotJust * fodds / Odds->KBs(H1,B1,H2,B2,H3,B3,H4,B4)->NOdds;
							}
						}
						else  // Ej med i tabell
							Odds->KBs(H1,B1,H2,B2,H3,B3,H4,B4)->kvot= 0.0;

						// Uppdatera antal inlästa odds
						if (!Odds->last[H1][B1][H2][B2][H3][B3][H4][B4])
							Odds->NumOdds ++;
						Odds->last[H1][B1][H2][B2][H3][B3][H4][B4] = true;

					}

				}
			
			} else {	// 2 matcher -->
				char *q, ch1, cb1, ch2, cb2;
				// sret=sscanf(str, "%c-%c %c-%c%f,%f%f", &ch1, &cb1, &ch2, &cb2, &Bel1, &Bel2, &Bel3);
				sret=sscanf(str, "%d-%d %d-%d%f,%f%f", &H1, &B1, &H2, &B2, &Bel1, &Bel2, &Bel3);
				if (sret>3)
				{
					// H1 = (ch1=='F') ? 10 : ch1-'0';
					// B1 = (cb1=='F') ? 10 : cb1-'0';
					// H2 = (ch2=='F') ? 10 : ch2-'0';
					// B2 = (cb2=='F') ? 10 : cb2-'0';

					if (sret == 5)
						Bel=Bel1;
					else if (sret == 6)
						Bel = Bel1*1000.0 + Bel2;
					else
						Bel = Bel1*1000000.0 + Bel2*1000.0 + Bel3;

					if (MAXRESOK(H1,B1,H2,B2,0,0,0,0) && Odds->KBs(H1,B1,H2,B2,0,0,0,0) != NULL)
					{
						if(Odds->KBs(H1,B1,H2,B2,0,0,0,0)->NOdds > 0)
						{
							if (sret == 4)  // Ej spelad
							{						
								Odds->KBs(H1,B1,H2,B2,0,0,0,0)->EjSpelad = true;
								Odds->KBs(H1,B1,H2,B2,0,0,0,0)->kvot=0.0;
							}
							else 
								Odds->KBs(H1,B1,H2,B2,0,0,0,0)->kvot = m_KvotJust * Bel / Odds->KBs(H1,B1,H2,B2,0,0,0,0)->NOdds;
						}
					}
					// Uppdatera antal inlästa odds
					if (!Odds->last[H1][B1][H2][B2][0][0][0][0])
						Odds->NumOdds ++;
					Odds->last[H1][B1][H2][B2][0][0][0][0] = true;
				}
			}
			while (*p!=NULL && *p!='\n')
				p++;
			if (*p=='\n')
				p++;
		}
		::EmptyClipboard();
	}
	::CloseClipboard();
	// Klicka på spelfönstret för att få bort "blå"-markeringen
	if (m_speltyp!=12 && m_speltyp!=13)	// Spel i Sverige -->
		MouseClickLeft(XPOS(Childrc.left+VXOFFS(m_WV)+35), YPOS(Childrc.top+VYOFFS(m_WV)+35));
	else				// Unibet
	{
		MouseClickLeft(XPOS(Childrc.left+600), YPOS(UnibetYpos+Childrc.top-10));
		::Sleep(500);
		// GB 101026: Bortkommenterat
		/* int retry=0;
		do {
			::Sleep(200);
			if (retry++ > 15)
				return false;
			scrn.Read(hChild);	
		} while	(scrn.GetPixel(330,UnibetYpos+30-102) != 0xffffff);
		*/
	}
	return true;
}

bool CBombDlg::ArMalMed(int mal, int *list, int sz)
{
	// returnerar true om målet finns med i listan
	for (int i=0; i<sz; i++)
			if (mal == list[i])
				return true;
	return false;
}
bool CBombDlg::InList(int m, int *list, int len)
{
	for (int i=0; i<len; i++)
		if (list[i] == m)
			return true;
	return false;
}

//  Returnerar true om rätt kobination blev kryssa, false vid timeout
bool CBombDlg::KryssaBong(RECT *rc, TBONG *bong1, TBONG *bong2)
{
#define XOR(a,b) ((a) && !(b) || !(a) && (b))
 
	int AntalKryss  = 0;

	int i, SleepTime = 0;  
	bool diff = true;


	for (i=0; i<MAXRES; i++)
	{
		if (XOR(ArMalMed(i, bong1->h1list, bong1->h1index), ArMalMed(i, bong2->h1list, bong2->h1index))) 
		{
			MouseClickLeft(XPOS(rc->left + VXOFFS(m_WV) + KLXPOS(m_speltyp,XH1M2,XH1M3,XH1M4)), YPOS(rc->top + VYOFFS(m_WV)+YTOP + int(16.3*i) ));
			AntalKryss ++;
			::Sleep(SleepTime);
		}
	}
	for (i=0; i<MAXRES; i++)
	{
		if (XOR(ArMalMed(i, bong1->b1list, bong1->b1index), ArMalMed(i, bong2->b1list, bong2->b1index))) 
		{
			MouseClickLeft(XPOS(rc->left + VXOFFS(m_WV) + KLXPOS(m_speltyp,XH1M2,XH1M3,XH1M4) + XWD), YPOS(rc->top + VYOFFS(m_WV)+YTOP + int(16.3*i)));
			AntalKryss ++;
			::Sleep(SleepTime);
		}
	}
	for (i=0; i<MAXRES; i++)
		if (XOR(ArMalMed(i, bong1->h2list, bong1->h2index), ArMalMed(i, bong2->h2list, bong2->h2index))) 
		{
			MouseClickLeft(XPOS(rc->left + VXOFFS(m_WV) + KLXPOS(m_speltyp,XH2M2,XH2M3,XH2M4)), YPOS(rc->top + VYOFFS(m_WV)+YTOP + int(16.3*i)));
			AntalKryss ++;
			::Sleep(SleepTime);
		}
	for (i=0; i<MAXRES; i++)
		if (XOR(ArMalMed(i, bong1->b2list, bong1->b2index), ArMalMed(i, bong2->b2list, bong2->b2index))) 
		{
			MouseClickLeft(XPOS(rc->left + VXOFFS(m_WV) + KLXPOS(m_speltyp,XH2M2,XH2M3,XH2M4) + XWD), YPOS(rc->top + VYOFFS(m_WV)+YTOP + int(16.3*i)));
			AntalKryss ++;
			::Sleep(SleepTime);
		}

	// 3 eller fler matcher -->	
	if (TRE(m_speltyp)|| m_speltyp==11) 
	{
		for (i=0; i<MAXRES; i++)
			if (XOR(ArMalMed(i, bong1->h3list, bong1->h3index), ArMalMed(i, bong2->h3list, bong2->h3index))) 
			{
				MouseClickLeft(XPOS(rc->left + VXOFFS(m_WV) + KLXPOS(m_speltyp,0,XH3M3,XH3M4)), YPOS(rc->top + VYOFFS(m_WV)+YTOP + int(16.3*i)));
				AntalKryss ++;
				::Sleep(SleepTime);
			}
		for (i=0; i<MAXRES; i++)
			if (XOR(ArMalMed(i, bong1->b3list, bong1->b3index), ArMalMed(i, bong2->b3list, bong2->b3index))) 
			{
				MouseClickLeft(XPOS(rc->left + VXOFFS(m_WV) + KLXPOS(m_speltyp,0,XH3M3,XH3M4) + XWD), YPOS(rc->top + VYOFFS(m_WV)+YTOP + int(16.3*i)));
				AntalKryss ++;
				::Sleep(SleepTime);
			}
	}
	// 4 matcher -->	
	if (m_speltyp==11) 
	{
		for (i=0; i<MAXRES4; i++)
			if (XOR(ArMalMed(i, bong1->h4list, bong1->h4index), ArMalMed(i, bong2->h4list, bong2->h4index))) 
			{
				MouseClickLeft(XPOS(rc->left + VXOFFS(m_WV) + XH4M4), YPOS(rc->top + VYOFFS(m_WV)+YTOP + int(16.3*i)));
				AntalKryss ++;
				::Sleep(SleepTime);
			}
		for (i=0; i<MAXRES4; i++)
			if (XOR(ArMalMed(i, bong1->b4list, bong1->b4index), ArMalMed(i, bong2->b4list, bong2->b4index))) 
			{
				MouseClickLeft(XPOS(rc->left + VXOFFS(m_WV) + XH4M4 + XWD), YPOS(rc->top + VYOFFS(m_WV)+YTOP + int(16.3*i)));
				AntalKryss ++;
				::Sleep(SleepTime);
			}
	}

	//  Vänta tills bong är korrekt ifylld
	TBONG kryssad;
	for (int retry = 0; retry<10 && diff; retry++)
	{
		scrn.LasRes(HittaSpelFonster(100), VXOFFS(m_WV), VYOFFS(m_WV), &kryssad, ANTALMATCHER( m_speltyp ));
		diff = false;
		for (int i=0; i<MAXRES && !diff; i++)
		{
			if (bong1->h1index != kryssad.h1index  
				||	(i<bong1->h1index && !InList(kryssad.h1list[i], bong1->h1list, bong1->h1index))
				||	(i<bong1->h1index && !InList(bong1->h1list[i], kryssad.h1list, kryssad.h1index)))

				diff = true;

			if (bong1->b1index != kryssad.b1index 
				|| 	(i<bong1->b1index && !InList(kryssad.b1list[i], bong1->b1list, bong1->b1index))
				||	(i<bong1->b1index && !InList(bong1->b1list[i], kryssad.b1list, kryssad.b1index)))

				diff = true;
			
			if (bong1->h2index != kryssad.h2index 
				|| 	(i<bong1->h2index && !InList(kryssad.h2list[i], bong1->h2list, bong1->h2index))
				||	(i<bong1->h2index && !InList(bong1->h2list[i], kryssad.h2list, kryssad.h2index)))

			if (bong1->b2index != kryssad.b2index || 
					(i<bong1->b2index && !InList(kryssad.b2list[i], bong1->b2list, bong1->b2index))
				||	(i<bong1->b2index && !InList(bong1->b2list[i], kryssad.b2list, kryssad.b2index)))

				diff = true;
			
			if (bong1->h3index != kryssad.h3index 
				|| 	(i<bong1->h3index && !InList(kryssad.h3list[i], bong1->h3list, bong1->h3index))
				||	(i<bong1->h3index && !InList(bong1->h3list[i], kryssad.h3list, kryssad.h3index)))

				diff = true;
			
			if (bong1->b3index != kryssad.b3index 
				|| 	(i<bong1->b3index && !InList(kryssad.b3list[i], bong1->b3list, bong1->b3index))
				||	(i<bong1->b3index && !InList(bong1->b3list[i], kryssad.b3list, kryssad.b3index)))
				
				diff = true;
		}
		if (diff)
			::Sleep(300);
	}
		
		
	return !diff;
}

//  Returnerar true om rätt kobination blev kryssa, false vid timeout
bool CBombDlg::KryssaBongUnibet(RECT *rc, TBONG *bong1, TBONG *bong2)
{
#define XOR(a,b) ((a) && !(b) || !(a) && (b))
 
	int AntalKryss  = 0;

	int i, SleepTime = 50;  
	bool diff = true;

	int ypos = scrn.GetUnibetYpos2(HittaSpelFonster(100), ANTALMATCHER(m_speltyp));

	// Hittar inte position -->
	if (ypos==0)
		return false;

	for (i=0; i<MAXRES; i++)
	{
		if (XOR(ArMalMed(i, bong1->h1list, bong1->h1index), ArMalMed(i, bong2->h1list, bong2->h1index))) 
		{
			MouseClickLeft(XPOS(rc->left + XPos.xh1), YPOS(rc->top+ypos + UB_YTOP + UB_ROWDIFF*i));
			AntalKryss ++;
			::Sleep(SleepTime);
		}
	}
	for (i=0; i<MAXRES; i++)
	{
		if (XOR(ArMalMed(i, bong1->b1list, bong1->b1index), ArMalMed(i, bong2->b1list, bong2->b1index))) 
		{
			MouseClickLeft(XPOS(rc->left + XPos.xb1), YPOS(rc->top+ypos + UB_YTOP + UB_ROWDIFF*i));
			AntalKryss ++;
			::Sleep(SleepTime);
		}
	}
	for (i=0; i<MAXRES; i++)
		if (XOR(ArMalMed(i, bong1->h2list, bong1->h2index), ArMalMed(i, bong2->h2list, bong2->h2index))) 
		{
			MouseClickLeft(XPOS(rc->left + XPos.xh2), YPOS(rc->top+ypos + UB_YTOP + UB_ROWDIFF*i));
			AntalKryss ++;
			::Sleep(SleepTime);
		}
	for (i=0; i<MAXRES; i++)
		if (XOR(ArMalMed(i, bong1->b2list, bong1->b2index), ArMalMed(i, bong2->b2list, bong2->b2index))) 
		{
			MouseClickLeft(XPOS(rc->left + XPos.xb2), YPOS(rc->top+ypos + UB_YTOP + UB_ROWDIFF*i));
			AntalKryss ++;
			::Sleep(SleepTime);
		}

	// 3 eller fler matcher -->	
	if (TRE(m_speltyp)|| m_speltyp==11) 
	{
		for (i=0; i<MAXRES; i++)
			if (XOR(ArMalMed(i, bong1->h3list, bong1->h3index), ArMalMed(i, bong2->h3list, bong2->h3index))) 
			{
				MouseClickLeft(XPOS(rc->left + XPos.xh3), YPOS(rc->top+ypos + UB_YTOP + UB_ROWDIFF*i));
				AntalKryss ++;
				::Sleep(SleepTime);
			}
		for (i=0; i<MAXRES; i++)
			if (XOR(ArMalMed(i, bong1->b3list, bong1->b3index), ArMalMed(i, bong2->b3list, bong2->b3index))) 
			{
				MouseClickLeft(XPOS(rc->left + XPos.xb3), YPOS(rc->top+ypos + UB_YTOP + UB_ROWDIFF*i));
				AntalKryss ++;
				::Sleep(SleepTime);
			}
	}

	//  Vänta tills bong är korrekt ifylld
	TBONG kryssad;
	for (int retry = 0; retry<10 && diff; retry++)
	{
		scrn.LasResUnibet(HittaSpelFonster(100), &kryssad, ANTALMATCHER( m_speltyp ), &XPos);
		diff = false;
		for (int i=0; i<MAXRES && !diff; i++)
		{
			if (bong1->h1index != kryssad.h1index  
				||	(i<bong1->h1index && !InList(kryssad.h1list[i], bong1->h1list, bong1->h1index))
				||	(i<bong1->h1index && !InList(bong1->h1list[i], kryssad.h1list, kryssad.h1index)))

				diff = true;

			if (bong1->b1index != kryssad.b1index 
				|| 	(i<bong1->b1index && !InList(kryssad.b1list[i], bong1->b1list, bong1->b1index))
				||	(i<bong1->b1index && !InList(bong1->b1list[i], kryssad.b1list, kryssad.b1index)))

				diff = true;
			
			if (bong1->h2index != kryssad.h2index 
				|| 	(i<bong1->h2index && !InList(kryssad.h2list[i], bong1->h2list, bong1->h2index))
				||	(i<bong1->h2index && !InList(bong1->h2list[i], kryssad.h2list, kryssad.h2index)))

			if (bong1->b2index != kryssad.b2index || 
					(i<bong1->b2index && !InList(kryssad.b2list[i], bong1->b2list, bong1->b2index))
				||	(i<bong1->b2index && !InList(bong1->b2list[i], kryssad.b2list, kryssad.b2index)))

				diff = true;
			
			if (bong1->h3index != kryssad.h3index 
				|| 	(i<bong1->h3index && !InList(kryssad.h3list[i], bong1->h3list, bong1->h3index))
				||	(i<bong1->h3index && !InList(bong1->h3list[i], kryssad.h3list, kryssad.h3index)))

				diff = true;
			
			if (bong1->b3index != kryssad.b3index 
				|| 	(i<bong1->b3index && !InList(kryssad.b3list[i], bong1->b3list, bong1->b3index))
				||	(i<bong1->b3index && !InList(bong1->b3list[i], kryssad.b3list, kryssad.b3index)))
				
				diff = true;
		}
		if (diff)
			::Sleep(300);
	}
		
		
	return !diff;
}

void CBombDlg::OnEnChangeEdit52()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CBombDlg::OnEnChangeEdit59()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CBombDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CBombDlg::OnEnChangeEdit50()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
void CBombDlg::OnEnChangeEdit51()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CBombDlg::OnBnClickedButton4()
{
	int h1pos, b1pos, h2pos, b2pos, h3pos, b3pos;
	char msg[200];
	HWND hChild;

    UpdateData(true);	
	if ((hChild=HittaSpelFonster(5000)) == NULL)
	{
		MessageBox( "Hitta inte fönstret: Svenska Spel - Microsoft Internet Explorer ",  "Timeout!", MB_OK );
		return ;
	}
	scrn.GetXposUnibet(hChild,  &XPos, ANTALMATCHER(m_speltyp));
	sprintf(msg, "H1=%d\tB1=%d\tH2=%d\tB2=%d\tH3=%d\tB3=%d", XPos.xh1, XPos.xb1, XPos.xh2, XPos.xb2, XPos.xh3, XPos.xb3
		);
	MessageBox(msg, "X-positioner", MB_OK);
}

void CBombDlg::OnBnClickedRadio17()
{
	// TODO: Add your control notification handler code here
}
