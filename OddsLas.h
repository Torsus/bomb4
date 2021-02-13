#if !defined(AFX_ODDSLAS_H__229A0959_F4B5_44F6_8EE3_74674F81340F__INCLUDED_)
#define AFX_ODDSLAS_H__229A0959_F4B5_44F6_8EE3_74674F81340F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// OddsLas.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COddsLas dialog

// Typ för pekare till fält-värden
typedef struct {
	int *minsida;
	int *maxsida;
	int *MissadeSidor;
	int *AntalOdds;
} FIELKDVAL_TYPE;

class COddsLas : public CDialog
{
// Construction
public:
	COddsLas(CWnd* pParent = NULL);   // standard constructor
	
	HANDLE hMapFile;				// Handle to Mapfile
	MEMFILETYPE *pMap;				// Pekare till gemensamt minne
	FIELKDVAL_TYPE field[10];		// Pekare till m_xxx - värden

	
	char buf[400];
	void NollaOdds();				// Nollställer nominella odds
	void UnibetInlasning();
	void UnibetInlasningm2();
	void Norskinlasning();
	void Svenskinlasning();
	void LasnyaSvenskaOdds();
	void LasnyaSvenskaOdds_fyra();
	void LasnyaSvenskaOdds_bandy2m();
	void LasnyaSvenskaOdds_is();
	void LasnyaSvenskaOdds_is_tre();
	void Finskinlasning(int startsida,int slutsida);
	bool ScanSvenskaOdds(char *s1, char *s2, char *s3, char *so);
	void SetOdds(int h1, int b1, int h2, int b2, int h3, int b3,int h4,int b4, float oddsval);
	CWinThread *Thread;
	int franp;
// Dialog Data
	//{{AFX_DATA(COddsLas)
	enum { IDD = IDD_ODDSLAS };
	CProgressCtrl	m_progress9;
	CProgressCtrl	m_progress8;
	CProgressCtrl	m_progress7;
	CProgressCtrl	m_progress6;
	CProgressCtrl	m_progress5;
	CProgressCtrl	m_progress4;
	CProgressCtrl	m_progress3;
	CProgressCtrl	m_progress10;
	CProgressCtrl	m_progress2;
	CProgressCtrl	m_progress;
	int		m_AntalInlastaOdds;
	BOOL	m_upprepa;
	int		m_MissadeSidor;
	int		m_maxsida1;
	int		m_maxsida10;
	int		m_maxsida2;
	int		m_maxsida3;
	int		m_maxsida4;
	int		m_maxsida5;
	int		m_maxsida6;
	int		m_maxsida7;
	int		m_maxsida8;
	int		m_maxsida9;
	int		m_minsida1;
	int		m_minsida10;
	int		m_minsida2;
	int		m_minsida3;
	int		m_minsida4;
	int		m_minsida5;
	int		m_minsida6;
	int		m_minsida7;
	int		m_minsida8;
	int		m_minsida9;
	int		m_MissadeSidor2;
	int		m_MissadeSidor10;
	int		m_MissadeSidor3;
	int		m_MissadeSidor4;
	int		m_MissadeSidor5;
	int		m_MissadeSidor6;
	int		m_MissadeSidor7;
	int		m_MissadeSidor8;
	int		m_MissadeSidor9;
	int		m_Instanser;
	int		m_InlastaOdds1;
	int		m_InlastaOdds2;
	int		m_InlastaOdds3;
	int		m_InlastaOdds4;
	int		m_InlastaOdds5;
	int		m_InlastaOdds6;
	int		m_InlastaOdds7;
	int		m_InlastaOdds8;
	int		m_InlastaOdds9;
	int		m_InlastaOdds10;
	
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COddsLas)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	afx_msg LONG COddsLas::OnOddsRead(WPARAM wParam, LPARAM lParam);
	afx_msg LONG COddsLas::OnOddsFinished(WPARAM wParam, LPARAM lParam);
	// Generated message map functions
	//{{AFX_MSG(COddsLas)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODDSLAS_H__229A0959_F4B5_44F6_8EE3_74674F81340F__INCLUDED_)
