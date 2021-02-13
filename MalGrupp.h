// MalGrupp1.h: interface for the CMalGrupp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MALGRUPP1_H__FA668C5B_8D59_46CA_BE3A_F47F23E0BCCE__INCLUDED_)
#define AFX_MALGRUPP1_H__FA668C5B_8D59_46CA_BE3A_F47F23E0BCCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "defs.h"

class CMalGrupp  
{
public:

	bool	grupp[26][10][2][10]; // Oddsgrupp, Målgrupp, Hemma/Borta, Antal Mål

	CMalGrupp();
	virtual ~CMalGrupp();
	
	int GetMalGrp(int Hodds);	// Skall kompletteras senare med oavgjort/bortaseger

	void InsertGrp(int H1odds, char *G0, char *G1, char *G2, char *G3, char *G4, 
							   char *G5, char *G6, char *G7, char *G8, char *G9);

	void Insert(int OddsGrp, int MalGrp, char *S);

	int GetBong(int M1mg, int M2mg, int M3mg, int H1odds, int H2odds, int H3odds, TBONG *bong);

	// Bong med 3 matcher i hocky/Bandy
	int GetBongHockey3(int m1, int m2, int h3, int b3, TBONG *bong);
	// Bong med 3 matcher PÅ Unibet
	int GetBongUnibet3(int mh1, int mb1, int mh2, int mb2, int mh3, int mb3,  TBONG *bong);	
	
	int GetBongHocky3A(int mh1, int mb1, int mh2, int mb2, int mh3, int mb3,  TBONG *bong);
	int GetBongFotboll4(int mh1, int mb1, int mh2, int mb2, int mh3, int mb3, int mh4, int mb4, TBONG *bong);
	
	int SetGrupp2(int m, int *list);
	int SetGrupp3(int m, int *list);
	int SetGrupp4(int m, int *list);

};

#endif // !defined(AFX_MALGRUPP1_H__FA668C5B_8D59_46CA_BE3A_F47F23E0BCCE__INCLUDED_)
