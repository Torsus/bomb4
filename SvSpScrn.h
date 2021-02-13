// SvSpScrn.h: interface for the CSvSpScrn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SVSPSCRN_H__6B704794_35A4_4537_99C7_A963D86E9F50__INCLUDED_)
#define AFX_SVSPSCRN_H__6B704794_35A4_4537_99C7_A963D86E9F50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "defs.h"
class CSvSpScrn  
{
public:
	CSvSpScrn();
	virtual ~CSvSpScrn();
	BITMAP bm;			// Bitmap för spelfönstret
	BYTE *pb;			// Pekare till pixelbitarna
	int		PixelBytes;	// Antal bytes per pixel
	bool Read(HWND hChild);				// Uppdatera pixlar
	int LasRes(HWND hChild, int xoffs, int yoffs, TBONG *bong, int ant); // Läs ikryssade match-resultat (ant=antal matcher). Returnerar antal rader
	int LasResUnibet(HWND hChild, TBONG *bong, int ant, XPOSTYPE *pXPos); // Läs ikryssade match-resultat (ant=antal matcher). Returnerar antal rader
	bool BetOK();		// Klart att klicka på OK-ruta vid betalning
	bool HamtarData();	// True ifall dialogrutan visas mitt på på skärmen
	bool OddsInlast(HWND hChild, int xoffs, int yoffs);	// True ifall odds för "Mitt vad" ar lästs in
	bool OddsInlastUnibet(int ypos);	
	bool BetalaRuta();	// True om betala-ruta visas i fönstret

	int GetUnibetYpos(HWND hChild);	// Returnerar pos för mörkgrön underkant
	int GetUnibetYpos2(HWND hChildint, int AntalMatcher);	// Returnerar pos för rosa överkant i första matchen
	int GetPixel(int xpos, int ypos); // Returnerar 32-bitars pixelvärde
	// Returnerar X koordinater
	int GetXposUnibet(HWND hChild, XPOSTYPE *pXpos, int ant);
};

#endif // !defined(AFX_SVSPSCRN_H__6B704794_35A4_4537_99C7_A963D86E9F50__INCLUDED_)
