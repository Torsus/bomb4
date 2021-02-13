// bombDlg.h : header file
//

#if !defined(AFX_BOMBDLG_H__CB201DC7_626B_11D5_9F03_B5D2BC811835__INCLUDED_)
#define AFX_BOMBDLG_H__CB201DC7_626B_11D5_9F03_B5D2BC811835__INCLUDED_
#include <afxtempl.h>
#include <afxcoll.h>
#include <afxinet.h>
#include "SvSpScrn.h"
#include "defs.h"

//#include "MalGrupp.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBombDlg dialog


struct resultat
{
	char r1;
	char r2;
	char r3;
	char r4;
	char r5;
	char r6;
	int odds;
};

class CBombDlg : public CDialog
{
// Construction
public:
	bool m_firsttime;
	void kalkylera_maxmal();
	void kalkylera_alla_nominella_odds();
	HWND HittaSpelFonster(int timeout);
	
	XPOSTYPE	XPos;
	resultat m_resultat[40001];
	float berakna_sannt_odds_for_en_kombination(int r1,int r2,int match,bool kvot);
	int m_odds3;
	int m_odds2;
	int m_odds1;
	int antalX[280][11][11];
	int antal[280][11][11];
	int UnibetYpos;
	int SantIndexMatch1[125],SantIndexMatch2[125],SantIndexMatch3[125],SantIndexMatch4[125];
	void las_oddsfrekvens();
	int oddsfrekvens_etta[280],oddsfrekvens_kryss[280],oddsfrekvens_tva[280];

	CSvSpScrn scrn;

	void MouseClickLeft(DWORD Xpos,DWORD Ypos);
	void MouseClickRight(DWORD Xpos,DWORD Ypos);

	float GetMinNomOdds(TBONG *bong);// Returnerar lägsta nominella odds för en bong
	bool HarAllaKvoter(TBONG *bong); // Returnerar true om alla resultat har blivit tilldelade en kvot
	bool SplittaBong(TBONG *bong1, TBONG *bong2, TBONG *bong3);

	bool ArMalMed(int mal, int *list, int sz);
	bool KryssaBong(RECT *rc, TBONG *bong1, TBONG *bong2);
	bool KryssaBongUnibet(RECT *rc, TBONG *bong1, TBONG *bong2);
	bool InList(int m, int *list, int len);

	void LasOddsiSpelFonster(); 
	bool LasOddsiSpelfonster();		// Läser odds i spelfönster mha klippbok	

	CBombDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBombDlg)
	enum { IDD = IDD_BOMB_DIALOG };
	UINT	m_m1_minmal_hemma;
	UINT	m_m1_kryss;
	UINT	m_m1_tva;
	UINT	m_m2_ett;
	UINT	m_m2_kryss;
	UINT	m_m2_tva;
	UINT	m_m3_ett;
	UINT	m_m3_tva;
	UINT	m_m3_kryss;
	float	m_sannodds;
	UINT	m_placering;
	UINT	m_m1_ett_talj;
	UINT	m_m1_kryss_talj;
	UINT	m_m1_tva_talj;
	UINT	m_m2_ett_talj;
	UINT	m_m2_kryss_talj;
	UINT	m_m2_tva_talj;
	UINT	m_m3_ett_talj;
	UINT	m_m3_kryss_talj;
	UINT	m_m3_tva_talj;
	UINT	m_m1_maxmal_hemma;
	UINT	m_m1_minmal_borta;
	UINT	m_m1_maxmal_borta;
	UINT	m_m2_minmal_hemma;
	UINT	m_m2_maxmal_hemma;
	UINT	m_m2_minmal_borta;
	UINT	m_m2_maxmal_borta;
	UINT	m_m3_minmal_hemma;
	UINT	m_m3_maxmal_hemma;
	UINT	m_m3_minmal_borta;
	UINT	m_m3_maxmal_borta;
	UINT	m_antalitabell1;
	UINT	m_antalitabell2;
	UINT	m_antalitabell3;
	float	m_minkvot;
	UINT	m_MatchIDNr;
	UINT	m_minnomodds;
	int		m_speltyp;
	float	m_maxkostnad;
	UINT	m_omsattning;
	float	m_mininsats;
	UINT	m_maxsida;
	UINT	m_m1_ett;
	int		m_OddsNum;
	float	m_AterBet;
	float	m_KvotJust;
	BOOL	m_AutoInlasning;
	int		m_StartTimme;
	int		m_StartMinut;
	int		m_utvardering;
	BOOL	m_OspeladeForvalt;
	BOOL	m_OddsOspelActive;
	UINT	m_OddsOspelade;
	int		m_BombbNr;
	int		m_minsida;
	int		m_Instanserr;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBombDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBombDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void Onkalkylera_sant_odds();
	afx_msg void Onkalk_sanna_odds();
	afx_msg void OnButton5();
	afx_msg void OnSkapaRapportfil();
	afx_msg void OnClose();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	afx_msg void OnFileImport();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnAutoInlasning();
	afx_msg void OnSpelTypRadio();
	afx_msg void OnButton11();
	afx_msg void OnEditPaste();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_KryssaAktiv;
public:
	int m_MinMalGrp;
public:
	int m_MaxMalGrp;
public:
	int m_DelayClp;
public:
	UINT m_m4_ett;
public:
	UINT m_m4_kryss;
public:
	afx_msg void OnEnChangeEdit51();
public:
	afx_msg void OnEnChangeEdit52();
public:
	UINT m_m4_tva;
public:
	UINT m_m4_ett_talj;
public:
	UINT m_m4_kryss_talj;
public:
	UINT m_m4_tva_talj;
public:
	UINT m_m4_minmal_hemma;
public:
	UINT m_m4_maxmal_hemma;
public:
	UINT m_m4_minmal_borta;
public:
	afx_msg void OnEnChangeEdit59();
public:
	UINT m_m4_maxmal_borta;
public:
	UINT m_antalitabell4;
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnEnChangeEdit50();
public:
	BOOL m_WV;  // True om Windows Visa är vald
	int m_VistaYoffs;
	int m_VistaXoffs;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedRadio17();
	BOOL m_en_krona_ospelad;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOMBDLG_H__CB201DC7_626B_11D5_9F03_B5D2BC811835__INCLUDED_)
