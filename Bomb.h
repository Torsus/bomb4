// bomb.h : main header file for the BOMB application
//

#if !defined(AFX_BOMB_H__CB201DC5_626B_11D5_9F03_B5D2BC811835__INCLUDED_)
#define AFX_BOMB_H__CB201DC5_626B_11D5_9F03_B5D2BC811835__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "bombDlg.h"
#include "odds.h"
// Fuskmetod för att erhålla globala klasser
#ifdef __MAIN
COdds *Odds;

#else
extern	 COdds *Odds;
#endif


#define XPOS(x)  ((x)*65535/1024)
#define YPOS(x)  ((x)*65535/768)
/////////////////////////////////////////////////////////////////////////////
// CBombApp:
// See bomb.cpp for the implementation of this class
//

class CBombApp : public CWinApp
{
public:
	CBombApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBombApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBombApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOMB_H__CB201DC5_626B_11D5_9F03_B5D2BC811835__INCLUDED_)
