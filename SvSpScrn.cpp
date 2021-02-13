// SvSpScrn.cpp: implementation of the CSvSpScrn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "SpelaBomb.h"
#include "SvSpScrn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Temporary, to be deleted
HWND HittaSpelFonster(int timeout)
{
	HWND hWnd;
	int retry = 0;
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

	return hWnd;
}

CSvSpScrn::CSvSpScrn()
{
	pb = NULL;
}

CSvSpScrn::~CSvSpScrn()
{
	free(pb);
}
//HittaSpelFonster(1000)
bool CSvSpScrn::Read(HWND hChild)
{
	CBitmap 	bitmap;
	CDC 		memDC;
	CRect		rect;
	int			err = 0;

	CWnd *pWnd = CWnd::FromHandle(hChild);

	// CWnd *pWnd = CDialog::FindWindow(NULL, "Svenska Spel - Microsoft Internet Explorer");

	try {
		CWindowDC	dc(pWnd);

		if (!err && pWnd == NULL)
			err = 1;

		if (!err && !memDC.CreateCompatibleDC(&dc))
			err = 1;

		pWnd->GetWindowRect(rect);

		if (!err && !bitmap.CreateCompatibleBitmap(&dc, rect.Width(),rect.Height() ))
			err = 2;
	
		CBitmap* pOldBitmap;
		if (!err && (pOldBitmap = memDC.SelectObject(&bitmap)) == NULL)
			err = 3;

		if (!err && !memDC.BitBlt(0, 0, rect.Width(),rect.Height(), &dc, 0, 0, SRCCOPY))
			err = 4;

		if (!err && !bitmap.GetBitmap( &bm ))
			err = 4;

		PixelBytes = bm.bmBitsPixel / 8;
	
		// if mem not allocated (i.e. first read)  --> allocate
		if (pb == NULL)
			pb = (BYTE *) malloc(bm.bmHeight*bm.bmWidth*PixelBytes);
		
		// 
		if (!err && !bitmap.GetBitmapBits( bm.bmHeight*bm.bmWidth*PixelBytes, pb ))
			err = 5;

		memDC.DeleteDC();
		bitmap.DeleteObject( );
	}
	catch(CException *e) {
		err = 7;
	}

	return (!err);
}

#define PIXVAL(x,y) PixelBytes*((x) + bm.bmWidth*(y))

int CSvSpScrn::LasRes(HWND hChild, int xoffs, int yoffs, TBONG *bong, int ant)

{	
	// Nollställ bong
	bong->spelad = false;
	bong->insats = 0;

	bong->h1index = 0;
	bong->b1index = 0;
	bong->h2index = 0;
	bong->b2index = 0;
	bong->h3index = 0;
	bong->b3index = 0;
	bong->h4index = 0;  // 0-0 i "fjärde" match för kompabilitet
	bong->b4index = 0;

	// Spel med 2 matcher
	if (ant==2)
	{
		bong->h3index = 1;  // 0-0 i "tredje" match för kompabilitet
		bong->b3index = 1;
		bong->h3list[0] = 0;
		bong->b3list[0] = 0;
		bong->h4index = 1;  // 0-0 i "fjärde" match för kompabilitet
		bong->b4index = 1;
		bong->h4list[0] = 0;
		bong->b4list[0] = 0;

		if (Read(hChild))					// Kopiara bitmap
			  for (int i=0; i<MAXRES; i++)
			  {
				// Match 1 - Mål för hemmalaget
				if (pb[ PIXVAL(xoffs+XH1M2,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH1M2,yoffs+YTOP+int(16.3*i))+1 ]!=255)
					bong->h1list[ bong->h1index ++ ]  = i;

				// Match 1 - Mål för bortalaget
				if (pb[ PIXVAL(xoffs+XH1M2+XWD,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH1M2+XWD,yoffs+YTOP+int(16.3*i))+1 ]!=255)
					bong->b1list[ bong->b1index ++ ]  = i;

				// Match 2 - Mål för hemmalaget
				if (pb[ PIXVAL(xoffs+XH2M2,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH2M2,yoffs+YTOP+int(16.3*i))+1 ]!=255)
					bong->h2list[ bong->h2index ++ ]  = i;

				// Match 2 - Mål för bortalaget
				if (pb[ PIXVAL(xoffs+XH2M2+XWD,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH2M2+XWD,yoffs+YTOP+int(16.3*i))+1 ]!=255)
					bong->b2list[ bong->b2index ++ ]  = i;

		  }

		  // Returnera summa rader
		return	bong->h1index * bong->b1index * bong->h2index *
				bong->b2index * bong->h3index *	bong->b3index;

	}
	// Spel med 3 matcher
	else if (ant==3)
	{
		bong->h4index = 1;  // 0-0 i "fjärde" match för kompabilitet
		bong->b4index = 1;
		bong->h4list[0] = 0;
		bong->b4list[0] = 0;
		if (Read(hChild))					// Kopiara bitmap
		  for (int i=0; i<MAXRES; i++)
		  {
			// Match 1 - Mål för hemmalaget  60
			if (pb[ PIXVAL(xoffs+XH1M3,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH1M3,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->h1list[ bong->h1index ++ ]  = i;

			// Match 1 - Mål för bortalaget
			if (pb[ PIXVAL(xoffs+XH1M3+XWD,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH1M3+XWD,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->b1list[ bong->b1index ++ ]  = i;

			// Match 2 - Mål för hemmalaget
			if (pb[ PIXVAL(xoffs+XH2M3,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH2M3,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->h2list[ bong->h2index ++ ]  = i;

			// Match 2 - Mål för bortalaget
			if (pb[ PIXVAL(xoffs+XH2M3+XWD,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH2M3+XWD,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->b2list[ bong->b2index ++ ]  = i;

			// Match 3 - Mål för hemmalaget
			if (pb[ PIXVAL(xoffs+XH3M3,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH3M3,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->h3list[ bong->h3index ++ ]  = i;

			// Match 3 - Mål för bortalaget
			if (pb[ PIXVAL(xoffs+XH3M3+XWD,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH3M3+XWD,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->b3list[ bong->b3index ++ ]  = i;
		  }

		  // Returnera summa rader
		return	bong->h1index * bong->b1index * bong->h2index *
				bong->b2index * bong->h3index *	bong->b3index;
		}

	// Spel med 4 matcher
	else if (ant==4)
	{
		if (Read(hChild))					// Kopiara bitmap
		  for (int i=0; i<MAXRES; i++)
		  {
			// Match 1 - Mål för hemmalaget  60
			if (pb[ PIXVAL(xoffs+XH1M4,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH1M4,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->h1list[ bong->h1index ++ ]  = i;

			// Match 1 - Mål för bortalaget
			if (pb[ PIXVAL(xoffs+XH1M4+XWD,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH1M4+XWD,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->b1list[ bong->b1index ++ ]  = i;

			// Match 2 - Mål för hemmalaget
			if (pb[ PIXVAL(xoffs+XH2M4,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH2M4,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->h2list[ bong->h2index ++ ]  = i;

			// Match 2 - Mål för bortalaget
			if (pb[ PIXVAL(xoffs+XH2M4+XWD,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH2M4+XWD,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->b2list[ bong->b2index ++ ]  = i;

			// Match 3 - Mål för hemmalaget
			if (pb[ PIXVAL(xoffs+XH3M4,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH3M4,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->h3list[ bong->h3index ++ ]  = i;

			// Match 3 - Mål för bortalaget
			if (pb[ PIXVAL(xoffs+XH3M4+XWD,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH3M4+XWD,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->b3list[ bong->b3index ++ ]  = i;

			// Match 4 - Mål för hemmalaget
			if (pb[ PIXVAL(xoffs+XH4M4,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH4M4,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->h4list[ bong->h4index ++ ]  = i;

			// Match 4 - Mål för bortalaget
			if (pb[ PIXVAL(xoffs+XH4M4+XWD,yoffs+YTOP+int (16.3*i)) ]!=255  || pb[ PIXVAL(xoffs+XH4M4+XWD,yoffs+YTOP+int(16.3*i))+1 ]!=255)
				bong->b4list[ bong->b4index ++ ]  = i;
		  }

		  // Returnera summa rader
		return	bong->h1index * bong->b1index * bong->h2index *	bong->b2index * 
				bong->h3index *	bong->b3index * bong->h4index *	bong->b4index;
		}

}
int CSvSpScrn::LasResUnibet(HWND hChild, TBONG *bong, int ant,  XPOSTYPE *pXPos) 
// Läs ikryssade match-resultat (ant=antal matcher). Returnerar antal rader
{	
	CFile file;
	int ypos;

	// Nollställ bong
	bong->spelad = false;
	bong->insats = 0;

	bong->h1index = 0;
	bong->b1index = 0;
	bong->h2index = 0;
	bong->b2index = 0;
	bong->h3index = 0;
	bong->b3index = 0;
	bong->h4index = 0;  // 0-0 i "fjärde" match för kompabilitet
	bong->b4index = 0;

	// Spel med 3 matcher
	if (ant==3)
	{
		bong->h4index = 1;  // 0-0 i "fjärde" match för kompabilitet
		bong->b4index = 1;
		bong->h4list[0] = 0;
		bong->b4list[0] = 0;
		if (Read(hChild))					// Kopiara bitmap
		{
		  ypos = GetUnibetYpos2(hChild, 288);
	
		  for (int i=0; i<MAXRES; i++)
		  {
			// Match 1 - Mål för hemmalaget  60
			if (GetPixel(pXPos->xh1, ypos + UB_YTOP + i*UB_ROWDIFF) != 0xffffff)
				bong->h1list[ bong->h1index ++ ]  = i;

			// Match 1 - Mål för bortalaget
			if (GetPixel(pXPos->xb1, ypos + UB_YTOP + i*UB_ROWDIFF) != 0xffffff)			
				bong->b1list[ bong->b1index ++ ]  = i;

			// Match 2 - Mål för hemmalaget
			if (GetPixel(pXPos->xh2, ypos + UB_YTOP + i*UB_ROWDIFF) != 0xffffff)
				bong->h2list[ bong->h2index ++ ]  = i;

			// Match 2 - Mål för bortalaget
			if (GetPixel(pXPos->xb2, ypos + UB_YTOP + i*UB_ROWDIFF) != 0xffffff)			
				bong->b2list[ bong->b2index ++ ]  = i;

			// Match 3 - Mål för hemmalaget
			if (GetPixel(pXPos->xh3, ypos + UB_YTOP + i*UB_ROWDIFF) != 0xffffff)
				bong->h3list[ bong->h3index ++ ]  = i;

			// Match 3 - Mål för bortalaget
			if (GetPixel(pXPos->xb3, ypos + UB_YTOP + i*UB_ROWDIFF) != 0xffffff)
				bong->b3list[ bong->b3index ++ ]  = i;
		  }

		}
	}
	// Spel med 2 matcher
	else if (ant==2)
	{
		bong->h4index = 1;  
		bong->b4index = 1;
		bong->h4list[0] = 0;
		bong->b4list[0] = 0;
		bong->h3index = 1;  
		bong->b3index = 1;
		bong->h3list[0] = 0;
		bong->b3list[0] = 0;
		if (Read(hChild))					// Kopiara bitmap
		{
		  ypos = GetUnibetYpos2(hChild, 288);
	
		  for (int i=0; i<MAXRES; i++)
		  {
			// Match 1 - Mål för hemmalaget  60
			if (GetPixel(pXPos->xh1, ypos + UB_YTOP + i*UB_ROWDIFF) != 0xffffff)
				bong->h1list[ bong->h1index ++ ]  = i;

			// Match 1 - Mål för bortalaget
			if (GetPixel(pXPos->xb1, ypos + UB_YTOP + i*UB_ROWDIFF) != 0xffffff)			
				bong->b1list[ bong->b1index ++ ]  = i;

			// Match 2 - Mål för hemmalaget
			if (GetPixel(pXPos->xh2, ypos + UB_YTOP + i*UB_ROWDIFF) != 0xffffff)
				bong->h2list[ bong->h2index ++ ]  = i;

			// Match 2 - Mål för bortalaget
			if (GetPixel(pXPos->xb2, ypos + UB_YTOP + i*UB_ROWDIFF) != 0xffffff)			
				bong->b2list[ bong->b2index ++ ]  = i;
		  }

		}
	}

	// Returnera summa rader
	return	bong->h1index * bong->b1index * bong->h2index *
			bong->b2index * bong->h3index *	bong->b3index;
}


// True om betala-ruta visas i fönstret
bool CSvSpScrn::BetalaRuta()	
{
	if (Read(HittaSpelFonster(1000)))
	{
		int h, l;
		l = pb[ PIXVAL(280, 220) ];
		h = pb[ PIXVAL(280, 220)+1 ];
		if (l!=255  ||  h!=255)
				return true;
		}
	return false;
}
// True ifall odds för "Mitt vad" ar lästs in
bool CSvSpScrn::OddsInlast(HWND hChild, int xoffs, int yoffs)	
{
	if (Read(hChild))
		for (int i= 370 ; i<470; i++)
		{
			int h, l;
			l = pb[ PIXVAL(xoffs+i, yoffs+i-100) ];	//4 XPP, 1 98
			h = pb[ PIXVAL(xoffs+i, yoffs+i-100)+1 ];	// 4
			if (l!=255  ||  h!=255)
				return true;
		}
	return false;
}

bool CSvSpScrn::OddsInlastUnibet(int ypos)
{
	for (int i= 600 ; i<640; i++)
		if (GetPixel(i,ypos) != 0xffffff)
			return true;

	return false;
}

int CSvSpScrn::GetUnibetYpos(HWND hChild)
{
	int ypos=0;
	if (Read(hChild))					// Kopiara bitmap
	{
		// Hitta Y-koordinat för mörkgrön underkant i Unibet-fönster
		for (int i=50; i<250; i++)
		{
			int *hh=(int *) &pb[ PIXVAL(300, i) ];
			// Color found --> Save pos
			if (*hh == 3966468)
				ypos=i;
			else if (ypos > 0)
				break;
		}
	}
	return ypos;
}
int CSvSpScrn::GetUnibetYpos2(HWND hChild, int AntalMatcher)
{
	int ypos=0;
	if (Read(hChild))					// Kopiara bitmap
	{
		// Hitta Y-koordinat för mörkgrön underkant i Unibet-fönster
		for (int i=50; i<550; i++)
		{
			int *h1;
			if (AntalMatcher==3)
				h1=(int *) &pb[ PIXVAL(UB_XH1M3, i) ];
			else
				h1=(int *) &pb[ PIXVAL(UB_XH1M2, i) ];
			// Color found --> Save pos
			if (*h1 == 16761035 )
				ypos=i;
			else if (ypos > 0)
				break;
		}
	}
	return ypos;
}
// Returnerar 32-bitars pixelvärde
int CSvSpScrn::GetPixel(int xpos, int ypos)
{
	int *p, val=0;
	p = (int *) &pb[ PIXVAL(xpos, ypos) ];
	val = *p;
	return val;
}

// Returnerar X koordinater
int CSvSpScrn::GetXposUnibet(HWND hChild, XPOSTYPE *pXpos, int ant)
{
	int Ypos, Xpos=250;
	int H1a=0, H1b=0, H2a=0, H2b=0, H3a=0, H3b=0;
	int B1a=0, B1b=0, B2a=0, B2b=0, B3a=0, B3b=0;
	int pix;
	// Hämta yposition
	Ypos = GetUnibetYpos2(hChild, 288)+ UB_YTOP ;

	// Scan through white area
	while ((pix=GetPixel(Xpos, Ypos)) == 0xffffff)
		if (Xpos++ > 1000)
			return false;

//----------------------------------
	// XPos för H1a;
	while ((pix=GetPixel(Xpos, Ypos)) != 0xffffff)
		if (Xpos++ > 1000)
			return false;
	H1a=Xpos;

	// XPos för H1b;
	while ((pix=GetPixel(Xpos, Ypos)) == 0xffffff)
		if (Xpos++ > 1000)
			return false;
	H1b=Xpos-1;
	// XPos för B1a;
	while ((pix=GetPixel(Xpos, Ypos)) != 0xffffff)
		if (Xpos++ > 1000)
			return false;
	B1a=Xpos-1;

	// XPos för B1b;
	while ((pix=GetPixel(Xpos, Ypos)) == 0xffffff)
		if (Xpos++ > 1000)
			return false;
	B1b=Xpos-1;

//----------------------------------
	// XPos för H2a;
	if (ant==2)
	{
		// Scan to white area
		while ((pix=GetPixel(Xpos, Ypos)) != 0xffffff)
			if (Xpos++ > 1000)
				return false;
		// Scan through white area
		while ((pix=GetPixel(Xpos, Ypos)) == 0xffffff)
			if (Xpos++ > 1000)
				return false;
	}
	else
		Xpos = Xpos + 50;  // No white space in some cases!!

	while ((pix=GetPixel(Xpos, Ypos)) != 0xffffff)
		if (Xpos++ > 1000)
			return false;
	H2a=Xpos;
	
	// XPos för H2b;
	while ((pix=GetPixel(Xpos, Ypos)) == 0xffffff)
		if (Xpos++ > 1000)
			return false;
	H2b=Xpos-1;
	// XPos för B2a;
	while ((pix=GetPixel(Xpos, Ypos)) != 0xffffff)
		if (Xpos++ > 1000)
			return false;
	B2a=Xpos-1;

	// XPos för B1b;
	while ((pix=GetPixel(Xpos, Ypos)) == 0xffffff)
		if (Xpos++ > 1000)
			return false;
	B2b=Xpos-1;
//----------------------------------
	if (ant==3)
	{
		// XPos för H3a;
		Xpos = Xpos + 50;
		while ((pix=GetPixel(Xpos, Ypos)) != 0xffffff)
			if (Xpos++ > 1000)
				return false;
		H3a=Xpos;
		
		// XPos för H3b;
		while ((pix=GetPixel(Xpos, Ypos)) == 0xffffff)
			if (Xpos++ > 1000)
				return false;
		H3b=Xpos-1;

		// XPos för B3a;
		while ((pix=GetPixel(Xpos, Ypos)) != 0xffffff)
			if (Xpos++ > 1000)
				return false;
		B3a=Xpos-1;

		// XPos för B3b;
		while ((pix=GetPixel(Xpos, Ypos)) == 0xffffff)
			if (Xpos++ > 1000)
				return false;
		B3b=Xpos-1;
	}
//----------------------------------

	pXpos->xh1 = (H1a+H1b)/2;
	pXpos->xb1 = (B1a+B1b)/2;
	pXpos->xh2 = (H2a+H2b)/2;
	pXpos->xb2 = (B2a+B2b)/2;
	pXpos->xh3 = (H3a+H3b)/2;
	pXpos->xb3 = (B3a+B3b)/2;
	return true;
}