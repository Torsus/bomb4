// Definition file
#ifndef __DEFS__
#define __DEFS__

#define MAXRES  11
#define MAXRES4 10

// Offset i X-led i Windows Vista
#define VISTA_XOFFS 3
#define VISTA_YOFFS 10
//#define VXOFFS(m) ((m) ? VISTA_XOFFS : 0)
#define VXOFFS(m) ((m) ? m_VistaXoffs : 0)
//#define VYOFFS(m) ((m) ? VISTA_YOFFS : 0)
#define VYOFFS(m) ((m) ? m_VistaYoffs : 0)

// Check mot övre gräns
#define MAXRESOK(h1,b1,h2,b2,h3,b3,h4,b4) (h1<MAXRES && b1<MAXRES && h2<MAXRES && b2<MAXRES && h3<MAXRES && b3<MAXRES && h4<MAXRES4 && b4<MAXRES4)

// Positioner för kryssning av bonger och pixelavkänning på Svenska Spel
#define YTOP	233
#define XWD    27

#define XH1M2  127
#define XH2M2  207

#define XH1M3  87
#define XH2M3  166
#define XH3M3  247

#define XH1M4  47   //48
#define XH2M4  127  // 128
#define XH3M4  207  // 208
#define XH4M4  287  //288

// Positioner för kryssning av bonger och pixelavkänning på Unibet
#define UB_YTOP	    8	
#define UB_XWD     30
#define UB_XWDM2   40
#define UB_ROWDIFF 16

#define UB_XH1M2  317
#define UB_XH2M2  462

#define UB_XOFFS  0									//     GB 101016
#define UB_XH1M3  289						// ((m_WV) ? 284 : 293)
#define UB_XH2M3  386						// ((m_WV) ? (382-2) : 376)
#define UB_XH3M3  484						// ((m_WV) ? (480-4) : 459)

#define UB_XH1M4  0
#define UB_XH2M4  0
#define UB_XH3M4  0
#define UB_XH4M4  0
// Struct för X positioner
typedef struct {
	int xh1, xb1, xh2, xb2, xh3, xb3;
} XPOSTYPE;


extern 	HWND HittaSpelFonster(int timeout);

typedef struct {
		 bool spelad;
		 float  insats;
		 int h1list[MAXRES];
		 int h1index;
		 int b1list[MAXRES];
		 int b1index;
		 int h2list[MAXRES];
		 int h2index;
		 int b2list[MAXRES];
		 int b2index;
		 int h3list[MAXRES];
		 int h3index;
		 int b3list[MAXRES];
		 int b3index;
		 int h4list[MAXRES4];
		 int h4index;
		 int b4list[MAXRES4];
		 int b4index;
	}TBONG;

#define ANTALRES(Bong)	(Bong).h1index*(Bong).b1index*(Bong).h2index*(Bong).b2index*(Bong).h3index*(Bong).b3index

#define TRE(m)	(m==0 || m==8 || m==9 || m==10 || m==12)
#define UNIBETSPEL(m) (m==12 || m==13 || m==14)

// Antal matcher
#define ANTALMATCHER(m) ((m==0 || m==3 || m==5 || m==6 || m==8 || m==9 || m==10  || m==12) ? 3 : ((m==11) ? 4 : 2))
// Klickposition beroende på antal matcher.
#define KLXPOS(m,POS2M, POS3M, POS4M) ((m==0 || m==3 || m==5 || m==6 || m==8 || m==9 || m==10) ? POS3M : ((m==11) ? POS4M : POS2M))
// Komplettera ovanstående med UNIBET nedan
// Dessa meddelanden skickas från oddsserver till dialogen när en odds-sida lästs in, och 
// när inläsningen är färdig.

const int WM_ODDSREAD		= WM_USER+100;
const int WM_ODDSFINISHED	= WM_USER+101;


// Struct för gemensam data som används i kommunikation mellan Bomb.exe och OddsServer.exe
typedef struct {
	int h1, b1, h2, b2, h3, b3,h4,b4;  // Antal mål för hemma resp. bortalag
	float odds;
} TINLASTODDS;

// Struct för en oddsinläsnings-instans
typedef struct {
	bool	Activ;
	int		MissadeSidor;	// Antal missade sidor
	int		AntalOdds;		// Totalt antal odds
	int		num;			// Antal inlästa odds
	TINLASTODDS L[100];		// Lista med odds
	} INSTYPE;

typedef struct {
	bool Upprepa;		// Upprepande inläsning
	INSTYPE I[10];		// Lista instanser
	} MEMFILETYPE;


#endif