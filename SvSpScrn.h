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
	BITMAP bm;			// Bitmap f�r spelf�nstret
	BYTE *pb;			// Pekare till pixelbitarna
	int		PixelBytes;	// Antal bytes per pixel
	bool Read(HWND hChild);				// Uppdatera pixlar
	int LasRes(HWND hChild, int xoffs, int yoffs, TBONG *bong, int ant); // L�s ikryssade match-resultat (ant=antal matcher). Returnerar antal rader
	int LasResUnibet(HWND hChild, TBONG *bong, int ant, XPOSTYPE *pXPos); // L�s ikryssade match-resultat (ant=antal matcher). Returnerar antal rader
	bool BetOK();		// Klart att klicka p� OK-ruta vid betalning
	bool HamtarData();	// True ifall dialogrutan visas mitt p� p� sk�rmen
	bool OddsInlast(HWND hChild, int xoffs, int yoffs);	// True ifall odds f�r "Mitt vad" ar l�sts in
	bool OddsInlastUnibet(int ypos);	
	bool BetalaRuta();	// True om betala-ruta visas i f�nstret

	int GetUnibetYpos(HWND hChild);	// Returnerar pos f�r m�rkgr�n underkant
	int GetUnibetYpos2(HWND hChildint, int AntalMatcher);	// Returnerar pos f�r rosa �verkant i f�rsta matchen
	int GetPixel(int xpos, int ypos); // Returnerar 32-bitars pixelv�rde
	// Returnerar X koordinater
	int GetXposUnibet(HWND hChild, XPOSTYPE *pXpos, int ant);
};

#endif // !defined(AFX_SVSPSCRN_H__6B704794_35A4_4537_99C7_A963D86E9F50__INCLUDED_)
