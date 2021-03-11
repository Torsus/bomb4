// OddsLas.cpp : implementation file
//

#include <stdio.h>
#include "stdafx.h"
#include "bomb.h"
#include "OddsLas.h"
#include "bombDlg.h"
#include <chrono>
#include <WinInet.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COddsLas dialog


COddsLas::COddsLas(CWnd* pParent /*=NULL*/)
	: CDialog(COddsLas::IDD, pParent)
{
	//{{AFX_DATA_INIT(COddsLas)
	m_AntalInlastaOdds = 0;
	m_upprepa = FALSE;
	m_MissadeSidor = 0;
	m_maxsida1 = 0;
	m_maxsida10 = 0;
	m_maxsida2 = 0;
	m_maxsida3 = 0;
	m_maxsida4 = 0;
	m_maxsida5 = 0;
	m_maxsida6 = 0;
	m_maxsida7 = 0;
	m_maxsida8 = 0;
	m_maxsida9 = 0;
	m_minsida1 = 0;
	m_minsida10 = 0;
	m_minsida2 = 0;
	m_minsida3 = 0;
	m_minsida4 = 0;
	m_minsida5 = 0;
	m_minsida6 = 0;
	m_minsida7 = 0;
	m_minsida8 = 0;
	m_minsida9 = 0;
	m_MissadeSidor2 = 0;
	m_MissadeSidor10 = 0;
	m_MissadeSidor3 = 0;
	m_MissadeSidor4 = 0;
	m_MissadeSidor5 = 0;
	m_MissadeSidor6 = 0;
	m_MissadeSidor7 = 0;
	m_MissadeSidor8 = 0;
	m_MissadeSidor9 = 0;
	m_Instanser = 0;
	m_InlastaOdds1 = 0;
	m_InlastaOdds2 = 0;
	m_InlastaOdds3 = 0;
	m_InlastaOdds4 = 0;
	m_InlastaOdds5 = 0;
	m_InlastaOdds6 = 0;
	m_InlastaOdds7 = 0;
	m_InlastaOdds8 = 0;
	m_InlastaOdds9 = 0;
	m_InlastaOdds10 = 0;
	//}}AFX_DATA_INIT
}


void COddsLas::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COddsLas)
	DDX_Control(pDX, IDC_PROGRESS9, m_progress9);
	DDX_Control(pDX, IDC_PROGRESS8, m_progress8);
	DDX_Control(pDX, IDC_PROGRESS7, m_progress7);
	DDX_Control(pDX, IDC_PROGRESS6, m_progress6);
	DDX_Control(pDX, IDC_PROGRESS5, m_progress5);
	DDX_Control(pDX, IDC_PROGRESS4, m_progress4);
	DDX_Control(pDX, IDC_PROGRESS3, m_progress3);
	DDX_Control(pDX, IDC_PROGRESS10, m_progress10);
	DDX_Control(pDX, IDC_PROGRESS2, m_progress2);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Text(pDX, IDC_EDIT1, m_AntalInlastaOdds);
	DDX_Check(pDX, IDC_CHECK_UPPREPA, m_upprepa);
	DDX_Text(pDX, IDC_MISSADESIDOR, m_MissadeSidor);
	DDX_Text(pDX, IDC_MAXSIDA1, m_maxsida1);
	DDX_Text(pDX, IDC_MAXSIDA10, m_maxsida10);
	DDX_Text(pDX, IDC_MAXSIDA2, m_maxsida2);
	DDX_Text(pDX, IDC_MAXSIDA3, m_maxsida3);
	DDX_Text(pDX, IDC_MAXSIDA4, m_maxsida4);
	DDX_Text(pDX, IDC_MAXSIDA5, m_maxsida5);
	DDX_Text(pDX, IDC_MAXSIDA6, m_maxsida6);
	DDX_Text(pDX, IDC_MAXSIDA7, m_maxsida7);
	DDX_Text(pDX, IDC_MAXSIDA8, m_maxsida8);
	DDX_Text(pDX, IDC_MAXSIDA9, m_maxsida9);
	DDX_Text(pDX, IDC_STARTSIDA1, m_minsida1);
	DDX_Text(pDX, IDC_STARTSIDA10, m_minsida10);
	DDX_Text(pDX, IDC_STARTSIDA2, m_minsida2);
	DDX_Text(pDX, IDC_STARTSIDA3, m_minsida3);
	DDX_Text(pDX, IDC_STARTSIDA4, m_minsida4);
	DDX_Text(pDX, IDC_STARTSIDA5, m_minsida5);
	DDX_Text(pDX, IDC_STARTSIDA6, m_minsida6);
	DDX_Text(pDX, IDC_STARTSIDA7, m_minsida7);
	DDX_Text(pDX, IDC_STARTSIDA8, m_minsida8);
	DDX_Text(pDX, IDC_STARTSIDA9, m_minsida9);
	DDX_Text(pDX, IDC_MISSADESIDOR2, m_MissadeSidor2);
	DDX_Text(pDX, IDC_MISSADESIDOR10, m_MissadeSidor10);
	DDX_Text(pDX, IDC_MISSADESIDOR3, m_MissadeSidor3);
	DDX_Text(pDX, IDC_MISSADESIDOR4, m_MissadeSidor4);
	DDX_Text(pDX, IDC_MISSADESIDOR5, m_MissadeSidor5);
	DDX_Text(pDX, IDC_MISSADESIDOR6, m_MissadeSidor6);
	DDX_Text(pDX, IDC_MISSADESIDOR7, m_MissadeSidor7);
	DDX_Text(pDX, IDC_MISSADESIDOR8, m_MissadeSidor8);
	DDX_Text(pDX, IDC_MISSADESIDOR9, m_MissadeSidor9);
	DDX_Text(pDX, IDC_EDIT2, m_Instanser);
	//DDX_Text(pDX, IDC_EDIT39, m_omsattning);
	DDX_Text(pDX, IDC_INLASTAODDS1, m_InlastaOdds1);
	DDX_Text(pDX, IDC_INLASTAODDS2, m_InlastaOdds2);
	DDX_Text(pDX, IDC_INLASTAODDS3, m_InlastaOdds3);
	DDX_Text(pDX, IDC_INLASTAODDS4, m_InlastaOdds4);
	DDX_Text(pDX, IDC_INLASTAODDS5, m_InlastaOdds5);
	DDX_Text(pDX, IDC_INLASTAODDS6, m_InlastaOdds6);
	DDX_Text(pDX, IDC_INLASTAODDS7, m_InlastaOdds7);
	DDX_Text(pDX, IDC_INLASTAODDS8, m_InlastaOdds8);
	DDX_Text(pDX, IDC_INLASTAODDS9, m_InlastaOdds9);
	DDX_Text(pDX, IDC_INLASTAODDS10, m_InlastaOdds10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COddsLas, CDialog)
	//{{AFX_MSG_MAP(COddsLas)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP

	ON_MESSAGE(WM_ODDSREAD, OnOddsRead)
	ON_MESSAGE(WM_ODDSFINISHED, OnOddsFinished)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COddsLas message handlers
// Söksträngar för scanf-funktioner
// OBS! Målen läses in som strängar eftersom F=10 förekommer 
// "width" skiljer sig mellan hockey och fotboll

#define SCANMALSTR		  "    <td class=\"mbr\" width=\"%d%%\" align=\"center\">%c - %c"
#define SCANODDSSTR		  "    <td class=\"mbr\" width=\"50%%\" align=\"right\">"


bool ScanSvenskaOdds(char *s1, char *s2, char *s3, char *so)
{
	char ch1, cb1, ch2, cb2, ch3='0', cb3='0'; // Tecken för antal mål
	int width, h1,b1,h2,b2,h3,b3,h4,b4,todds=0, iodds,dodds;
	float odds;
	bool ret=false;

	if ((sscanf(s1,SCANMALSTR,&width,&ch1,&cb1) == 3) && (sscanf(s2,SCANMALSTR,&width,&ch2,&cb2)==3)  &&
		((Odds->m_speltyp==1 || Odds->m_speltyp==2)          || (sscanf(s3,SCANMALSTR,&width,&ch3,&cb3)==3)) &&  // Endast fotboll
		((sscanf(so,SCANODDSSTR "%d,%d",&iodds,&dodds) == 2) || 
		 (sscanf(so,SCANODDSSTR "%d %d,%d",&todds,&iodds,&dodds) == 3)))

	{
		h1 = (ch1=='F') ? 10 : ch1-'0';
		b1 = (cb1=='F') ? 10 : cb1-'0';
		h2 = (ch2=='F') ? 10 : ch2-'0';
		b2 = (cb2=='F') ? 10 : cb2-'0';
		h3 = (ch3=='F') ? 10 : ch3-'0';
		b3 = (cb3=='F') ? 10 : cb3-'0';

		odds = (float)todds*1000.0 + (float)iodds + (float)dodds/10.0;
		ret = true;

		// Uppdatera antal inlästa odds
		if (!Odds->last[h1][b1][h2][b2][h3][b3][h4][b4])
			Odds->NumOdds ++;
		Odds->last[h1][b1][h2][b2][h3][b3][h4][b4] = true;


		// Beräkna nominellt odds
		if (Odds->KB[h1][b1][h2][b2][h3][b3][h4][b4]!=NULL && Odds->KB[h1][b1][h2][b2][h3][b3][h4][b4]->NOdds > 0)
		{
			Odds->KB[h1][b1][h2][b2][h3][b3][h4][b4]->kvot = odds/Odds->KB[h1][b1][h2][b2][h3][b3][h4][b4]->NOdds;
			Odds->KB[h1][b1][h2][b2][h3][b3][h4][b4]->EjSpelad = false;
		}
	}
	return ret;
}

bool LasSvenskaOddsSida(int franp)
{
	char  buf[400], s1[400], s2[200], s3[200], so[200]; //, h1[100],b1[100];
	int  width;
	char h1,b1;
	bool traff=false;			// Tilldelan true om odds läses in 
	CStdioFile *pFile;
	CInternetSession m_Session;

				    //http://www.svenskaspel.se/pl.aspx?PageID=2544&round=2514&FranPos=0&mest=True
	sprintf(buf, "http://www.svenskaspel.se/pl.aspx?PageID=2544&round=%d&FranPos=%d&mest=True", Odds->m_matchid, franp); 
	pFile = m_Session.OpenURL(buf,1,INTERNET_FLAG_DONT_CACHE|INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_ASCII);

	while (pFile->ReadString( s1, sizeof(s1) )) 

		// Matchad förstasträng --> Läs in resterande
		if (sscanf(s1,SCANMALSTR,&width,&h1,&b1) == 3) {

			pFile->ReadString(s2, sizeof(s2));		// HTML-sträng match 2
			// Fotboll eller Hocky med 3 matcher/perioder -->
			if (Odds->m_speltyp == 0 || Odds->m_speltyp == 8 || Odds->m_speltyp == 9) 
				pFile->ReadString(s3, sizeof(s3));	// HTML-sträng match 3

			pFile->ReadString(so, sizeof(so));		// HTML-sträng odds
		
			// Skanna strängar och tilldela odds
			if (ScanSvenskaOdds(s1, s2,s3, so))
				traff = true;

			// Nollställ strängar
			s1[0]='\0'; s2[0]='\0'; s2[0]='\0'; so[0]='\0'; 
		}

	pFile->Close();
	m_Session.Close();
	return traff;

}

UINT LasSvenskaOdds( LPVOID param )
{
	int MissadSida[1000];
	int franp;
	Odds->MissadeSidor = 0;;

	// Läs i samtliga odds
	for (franp=Odds->m_minsida; franp<Odds->m_maxsida; franp +=100)
	{

		// Oddsinläsningfönstret stängt (genom CANCEL) --> Avsluta
		if (!::IsWindowEnabled((HWND)param))
			return 0;

		// Läs odds-sida och markera eventuella missade sidor
		if (!LasSvenskaOddsSida(franp) && Odds->MissadeSidor < 1000)
			MissadSida[ Odds->MissadeSidor++ ] = franp;

		// Skicka message till dialogprogram för uppdatering av progress bar
		::PostMessage((HWND)param, WM_ODDSREAD,franp/100, 0);//(franp+100 >= Odds->m_maxsida));
	}	

	// Ta bort eventuella tomma sidor på slutet
	franp -=100;
	while (Odds->MissadeSidor>0 && MissadSida[ Odds->MissadeSidor-1 ] == franp)
	{
			Odds->MissadeSidor --;
			franp -=100;
	}

	// Läs in missade sidor på nytt
	int AntalSidor = Odds->MissadeSidor;
	for (int i=0; i<AntalSidor; i++)
	{
		// Oddsinläsningfönstret stängt (genom CANCEL) --> Avsluta
		if (!::IsWindowEnabled((HWND)param))
			return 0;

		if (LasSvenskaOddsSida( MissadSida[i]))
			Odds->MissadeSidor--;

		// Skicka message till dialogprogram för uppdatering av progress bar
		::PostMessage((HWND)param, WM_ODDSREAD,MissadSida[i]/100, 0);//(franp+100 >= Odds->m_maxsida));
	}
	
	
	// Skicka message till dialogprogram då inläsning är klar
	::PostMessage((HWND)param, WM_ODDSFINISHED,0,0);
	return 0;
}
void COddsLas::Svenskinlasning()
{
	int AntalOdds, range;		

	if (Odds->m_OspeladeForvalt)
	   NollaOdds();

	AntalOdds = Odds->m_maxsida - Odds->m_minsida + 1;
	range = AntalOdds / m_Instanser;	
	
	// Avrunda uppåt till närmsta hundratal
	if ((range % 100) != 0)
		range = ((range/100) + 1) * 100;

	for (int i=0; i<10; i++)
	{
		if (i<m_Instanser)
		{
			*field[i].minsida = Odds->m_minsida + i*range;
			*field[i].maxsida = *field[i].minsida + range - 100;
		} 
		else {
			*field[i].minsida = 0;
			*field[i].maxsida = 0;
		}
	}
	UpdateData(FALSE);

	Odds->MissadeSidor = 0;
	m_progress.SetRange32(  *field[0].minsida,  *field[0].maxsida);
	m_progress2.SetRange32( *field[1].minsida,  *field[1].maxsida);
	m_progress3.SetRange32( *field[2].minsida,  *field[2].maxsida);
	m_progress4.SetRange32( *field[3].minsida,  *field[3].maxsida);
	m_progress5.SetRange32( *field[4].minsida,  *field[4].maxsida);
	m_progress6.SetRange32( *field[5].minsida,  *field[5].maxsida);
	m_progress7.SetRange32( *field[6].minsida,  *field[6].maxsida);
	m_progress8.SetRange32( *field[7].minsida,  *field[7].maxsida);
	m_progress9.SetRange32( *field[8].minsida,  *field[8].maxsida);
	m_progress10.SetRange32(*field[9].minsida,  *field[9].maxsida);

	// Starta trådinläsning
	HWND hwnd = GetSafeHwnd();
//	Thread = AfxBeginThread(LasSvenskaOdds,hwnd);

	char OddsServStr[64], CmdStr[128];
	sprintf(OddsServStr,"Oddsinläsning ID=%d", Odds->m_matchid);
	
	hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof( MEMFILETYPE), OddsServStr);
	pMap = (MEMFILETYPE *) MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);

	// Startup OddsServer Process
	for (int i=0; i<m_Instanser; i++)
	{
		pMap->I[i].num			= 0;
		pMap->I[i].AntalOdds	= 0;
		pMap->I[i].MissadeSidor = 0;

		STARTUPINFO stInfo;
		PROCESS_INFORMATION prInfo;
		ZeroMemory( &stInfo, sizeof(stInfo) );
		stInfo.cb = sizeof(stInfo);
		stInfo.dwFlags=STARTF_USESHOWWINDOW;
		stInfo.wShowWindow=SW_MINIMIZE;

		sprintf(CmdStr, "OddsServer.exe %d %d %d %d %d", 
			Odds->m_matchid, Odds->m_speltyp, i, *field[i].minsida,  *field[i].maxsida);
	
		// Starta upp process
		// Om OddsServer inte finns i samma katalog 
		if (!CreateProcess(NULL, (LPSTR)(LPCSTR) CmdStr, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, 
						NULL, NULL, &stInfo, &prInfo))
		{
			//	------> Försök i debug-katalogen		
			sprintf(CmdStr, "../OddsServer/Debug/OddsServer.exe %d %d %d %d %d", 
						Odds->m_matchid, Odds->m_speltyp, i, *field[i].minsida,  *field[i].maxsida);

			CreateProcess(NULL, (LPSTR)(LPCSTR) CmdStr, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, 
						NULL, NULL, &stInfo, &prInfo);

		}
	}

}
void COddsLas::SetOdds(int h1, int b1, int h2, int b2, int h3, int b3,int h4,int b4, float oddsval)
{
	// Uppdatera antal inlästa odds
	if (!Odds->last[h1][b1][h2][b2][h3][b3][h4][b4])
		Odds->NumOdds ++;
	Odds->last[h1][b1][h2][b2][h3][b3][h4][b4] = true;


	// Beräkna nominellt odds
	if (Odds->KB[h1][b1][h2][b2][h3][b3][h4][b4]!=NULL && Odds->KB[h1][b1][h2][b2][h3][b3][h4][b4]->NOdds > 0)
	{
		Odds->KB[h1][b1][h2][b2][h3][b3][h4][b4]->kvot = oddsval/Odds->KB[h1][b1][h2][b2][h3][b3][h4][b4]->NOdds;
		Odds->KB[h1][b1][h2][b2][h3][b3][h4][b4]->EjSpelad = false;
	}
}

// Inläsning av en sida --> Uppdatera progress-bar och antal inlästa odds
LONG COddsLas::OnOddsRead(WPARAM wParam, LPARAM lParam)
{
	int sida = (int) wParam;	// Inläst sida
	int ins  = (int) lParam;	// Instans	

	UpdateData(true);						// Fånga ev. ikryssning
	
	m_AntalInlastaOdds = Odds->NumOdds;
	m_MissadeSidor = Odds->MissadeSidor;

	// Spel i sverige --> Läs data från server
	if (/*Odds->m_speltyp <= 2  || Odds->m_speltyp == 8 || Odds->m_speltyp ==9 ||*/ Odds->m_speltyp ==10)
	{
		pMap->Upprepa = m_upprepa;	

		for (int j=0; j<pMap->I[ins].num; j++)
			SetOdds(pMap->I[ins].L[j].h1, pMap->I[ins].L[j].b1, pMap->I[ins].L[j].h2, pMap->I[ins].L[j].b2, 
					pMap->I[ins].L[j].h3, pMap->I[ins].L[j].b3,pMap->I[ins].L[j].h4, pMap->I[ins].L[j].b4, pMap->I[ins].L[j].odds);
		pMap->I[ins].num = 0;
	
		for (int i=0; i<m_Instanser; i++)
		{
			*field[i].MissadeSidor = pMap->I[i].MissadeSidor;
			*field[i].AntalOdds = pMap->I[i].AntalOdds;
		}
	}
	// Uppdatera fält
	if (ins == 0)
		m_progress.SetPos(sida + 1);
	else if (ins == 1)
		m_progress2.SetPos(sida + 1);
	else if (ins == 2)
		m_progress3.SetPos(sida + 1);
	else if (ins == 3)
		m_progress4.SetPos(sida + 1);
	else if (ins == 4)
		m_progress5.SetPos(sida + 1);
	else if (ins == 5)
		m_progress6.SetPos(sida + 1);
	else if (ins == 6)
		m_progress7.SetPos(sida + 1);
	else if (ins == 7)
		m_progress8.SetPos(sida + 1);
	else if (ins == 8)
		m_progress9.SetPos(sida + 1);
	else if (ins == 9)
		m_progress10.SetPos(sida + 1);

	UpdateData(false);					

	return 0;
}

// Inläsning klar --> Ny inläsning eller avsluta
LONG COddsLas::OnOddsFinished(WPARAM wParam, LPARAM lParam)
{
	UpdateData(true);
	Odds->m_OspeladeForvalt  = false;

	// Upprepa-ruta ikryssad  -->  Ny inläsning
	if (m_upprepa)
		if (Odds->m_speltyp <= 2  || Odds->m_speltyp == 8 || Odds->m_speltyp == 9)
			; //Svenskinlasning();
	
		else
			Norskinlasning();


	else if (/*Odds->m_speltyp <= 2  || Odds->m_speltyp == 8 || Odds->m_speltyp == 9 ||*/ Odds->m_speltyp ==10)
	{
		// Kolla om alla instanser är klara
		if (!pMap->Upprepa)
		{
			bool avsluta = true;
			for (int i=0; i<m_Instanser; i++)
				avsluta = avsluta && !pMap->I[i].Activ;
			// Ingen instans aktiv --> Avsluta
			if (avsluta)
				EndDialog(0);
		}
	}
	else			// --> Spel i norge
		EndDialog(0);

	return 0;
}

//void COddsLas::Finskinlasning(int startsida,int slutsida)
//{
//	CStdioFile *pFile;
//	CString sUrl;
//	char  sUrlOrg[300];
//	CInternetSession m_Session;
//	char str[64]; 
//	char bgcolor[10],cmatchid1,cmatchid2,cmatchid3,fpc1,fpc2,fpc3,fpc4,fpc5;
//	int h1,h2,h3,b1,b2,b3,iodds,iodds2,iodds3,dodds,franp,varv,antalInlastaodds;
//	float odds,fodds,f1,f2;
//	bool hittatodds;
//	m_progress.SetRange( 0, 100 );
//	m_progress.SetPos(0);
//	sprintf(sUrlOrg , "http://www.veikkaus.fi/odds/www/GetSysOdds?i=%d&H0=1&H1=1&H2=1&H3=1&H4=1&H5=1&H6=1&H7=1&H8=1&H9=1&V0=1&V1=1&V2=1&V3=1&V4=1&V5=1&V6=1&V7=1&V8=1&V9=1&I0=1&I1=1&I2=1&I3=1&I4=1&I5=1&I6=1&I7=1&I8=1&I9=1&W0=1&W1=1&W2=1&W3=1&W4=1&W5=1&W6=1&W7=1&W8=1&W9=1&J0=1&X0=1",
//		   Odds->m_matchid);
//	if(Odds->mh1*Odds->mb1*Odds->mh2*Odds->mb2 <= 5000)
//	{
//		sprintf(sUrlOrg , "http://www.veikkaus.fi/odds/www/GetSysOdds?i=%d&H0=1&H1=1&H2=1&H3=1",
//		   Odds->m_matchid);
//		sUrl = sUrlOrg;
//		if(Odds->mh1 > 3)
//			sUrl.Insert(500,"&H4=1");
//		if(Odds->mh1 > 4)
//			sUrl.Insert(500,"&H5=1");
//		if(Odds->mh1 > 5)
//			sUrl.Insert(500,"&H6=1");
//		if(Odds->mh1 > 6)
//			sUrl.Insert(500,"&H7=1");
//		if(Odds->mh1 > 7)
//			sUrl.Insert(500,"&H8=1");
//		if(Odds->mh1 > 8)
//			sUrl.Insert(500,"&H9=1");
//		///////////////////////////////
//		sUrl.Insert(500,"&V0=1&V1=1&V2=1&V3=1");
//		if(Odds->mb1 > 3)
//			sUrl.Insert(500,"&V4=1");
//		if(Odds->mb1 > 4)
//			sUrl.Insert(500,"&V5=1");
//		if(Odds->mb1 > 5)
//			sUrl.Insert(500,"&V6=1");
//		if(Odds->mb1 > 6)
//			sUrl.Insert(500,"&V7=1");
//		if(Odds->mb1 > 7)
//			sUrl.Insert(500,"&V8=1");
//		if(Odds->mb1 > 8)
//			sUrl.Insert(500,"&V9=1");
//		///////////////////////////////
//		sUrl.Insert(500,"&I0=1&I1=1&I2=1&I3=1");
//		if(Odds->mh2 > 3)
//			sUrl.Insert(500,"&I4=1");
//		if(Odds->mh2 > 4)
//			sUrl.Insert(500,"&I5=1");
//		if(Odds->mh2 > 5)
//			sUrl.Insert(500,"&I6=1");
//		if(Odds->mh2 > 6)
//			sUrl.Insert(500,"&I7=1");
//		if(Odds->mh2 > 7)
//			sUrl.Insert(500,"&I8=1");
//		if(Odds->mh2 > 8)
//			sUrl.Insert(500,"&I9=1");
//		///////////////////////////////
//		sUrl.Insert(500,"&W0=1&W1=1&W2=1&W3=1");
//		if(Odds->mb2 > 3)
//			sUrl.Insert(500,"&W4=1");
//		if(Odds->mb2 > 4)
//			sUrl.Insert(500,"&W5=1");
//		if(Odds->mb2 > 5)
//			sUrl.Insert(500,"&W6=1");
//		if(Odds->mb2 > 6)
//			sUrl.Insert(500,"&W7=1");
//		if(Odds->mb2 > 7)
//			sUrl.Insert(500,"&W8=1");
//		if(Odds->mb2 > 8)
//			sUrl.Insert(500,"&W9=1");
//		sUrl.Insert(500,"&J0=1");
//	}
//
//	 Finsk fotboll eller hockey med 3 matcher -->
//	if(Odds->m_speltyp == 3)
//	{
//		 if(Odds->m_speltyp == 0)
//		{
//			int ytterloop,innerloop,maxinner,totalavarv;
//			totalavarv = 0;
//			for(ytterloop = 0; ytterloop <9;ytterloop++)
//			{
//				 Replace J0=1 
//				if(Odds->mh1*Odds->mb1*Odds->mh2*Odds->mb2 <= 5000)
//				{
//					sUrl.SetAt(sUrl.GetLength()-3,ytterloop+48);
//				}
//				else
//				{
//					sUrl = sUrlOrg;
//					 sprintf(str, "J0=%c", ytterloop+48);
//					 sUrl.Replace("J0=1", str);
//					sUrl.SetAt(249,ytterloop+48);
//				}
//				if(ytterloop == 0)
//					maxinner = 8;
//				else if(ytterloop == 1)
//					maxinner = 7;
//				else if(ytterloop ==2)
//					maxinner = 7;
//				else if(ytterloop ==3)
//					maxinner = 7;
//				else if(ytterloop ==4)
//					maxinner = 5;
//				else if(ytterloop ==5)
//					maxinner = 4;
//				else if(ytterloop ==6)
//					maxinner = 3;
//				else if(ytterloop == 7)
//					maxinner = 3;
//				else if(ytterloop == 8)
//					maxinner = 0;
//				for(innerloop = 0;innerloop <=maxinner;innerloop++)
//				{
//					int inlasta;
//					inlasta = 0;
//					if(Odds->mh1*Odds->mb1*Odds->mh2*Odds->mb2 <= 5000)
//					{
//						CString sUrltmp;
//						sUrltmp = sUrl;
//						sUrltmp.Insert(500,"&X0=1");
//						sUrltmp.SetAt(sUrltmp.GetLength()-3,innerloop+48);
//						if(innerloop<maxinner)
//						{
//							sUrltmp.Insert(500,"&X0=1");
//							innerloop++;
//							sUrltmp.SetAt(sUrltmp.GetLength()-3,innerloop+48);
//						}
//						pFile = m_Session.OpenURL(sUrltmp, INTERNET_FLAG_TRANSFER_ASCII);
//					}
//					else
//					{
//						sUrl.SetAt(254,innerloop+48);
//						pFile = m_Session.OpenURL(sUrl, INTERNET_FLAG_TRANSFER_ASCII);
//					}
//					if (pFile==NULL)
//						return;
//					pFile->ReadString( buf, 399 );
//					do
//					{
//						
//						if(sscanf(buf,"%d - %d     %d - %d     %d - %d  	 %f,%f",&h1,&b1,&h2,&b2,&h3,&b3,&f1,&f2)>7)
//						{
//							odds = f1 + (f2/100);
//							inlasta++;
//							if (Odds->KB[h1][b1][h2][b2][h3][b3] != NULL)
//							{	
//								if(Odds->KB[h1][b1][h2][b2][h3][b3][0][0]->NOdds > 0)
//								{
//									Odds->KB[h1][b1][h2][b2][h3][b3][0][0]->kvot = odds/Odds->KB[h1][b1][h2][b2][h3][b3][0][0]->NOdds;
//								}
//							}
//						m_progress.SetPos(inlasta/10000);
//						}
//						else if(sscanf(buf,"%d - %d     %d - %d     %d - %d  	 %f",&h1,&b1,&h2,&b2,&h3,&b3,&odds)>5)
//						{
//							inlasta++;
//
//
//
//							if (Odds->KB[h1][b1][h2][b2][h3][b3][0][0] != NULL)
//							{	
//								Odds->KB[h1][b1][h2][b2][h3][b3][0][0]->EjSpelad = true;
//								Odds->KB[h1][b1][h2][b2][h3][b3][0][0]->kvot=0.0;
//
//				
//							}
//
//						}
//						
//					}
//					while(	pFile->ReadString( buf, 399 ));
//					totalavarv++;
//					if(Odds->mh1*Odds->mb1*Odds->mh2*Odds->mb2 <= 5000)
//						m_progress.SetPos(((totalavarv*100)/51)*2);
//					else
//					m_progress.SetPos((totalavarv*100)/51);
//					Invalidate(true);
//					
//				}
//				
//			}
//		}
//		m_Session.Close();
//		EndDialog(5);
//		return;
//	}
//
//	 Finsk hockey med 2 matcher -->
//	else if (Odds->m_speltyp == 4)
//	{
//        MessageBox("startar sökning av sidan...");
//        sprintf(sUrlOrg,"http://www.veikkaus.fi/odds/www/GetSysOdds?i=%d&H0=1&H1=1&H2=1&H3=1&H4=1&H5=1&H6=1&H7=1&H8=1&H9=1&V0=1&V1=1&V2=1&V3=1&V4=1&V5=1&V6=1&V7=1&V8=1&V9=1&I0=1&I1=1&I2=1&I3=1&I4=1&I5=1&I6=1&I7=1&I8=1&I9=1&W0=1&W1=1&W2=1&W3=1&W4=1&W5=1&W6=1&W7=1&W8=1&W9=1",
//				   Odds->m_matchid);		
//		
//		pFile = m_Session.OpenURL(sUrlOrg);
//		MessageBox("Sidan hittad!");
//        if (pFile==NULL)
//				return;
//		pFile->ReadString( buf, 399 );
//		do
//		{
//						
//			if(sscanf(buf,"%d - %d     %d - %d     	 %f,%f",&h1,&b1,&h2,&b2,&f1,&f2)>5)
//			{
//				odds = f1 + (f2/100);
//							
//
//
//
//				if (Odds->KB[h1][b1][h2][b2][0][0] != NULL)
//				{	
//					if(Odds->KB[h1][b1][h2][b2][0][0]->NOdds > 0)
//					{
//							Odds->KB[h1][b1][h2][b2][0][0]->kvot = odds/Odds->KB[h1][b1][h2][b2][0][0]->NOdds;
//					}
//				}
//						
//			}
//			else if(sscanf(buf,"%d - %d     %d - %d    	 %f",&h1,&b1,&h2,&b2,&odds)>3)
//			{
//						
//
//				if (Odds->KB[h1][b1][h2][b2][0][0] != NULL)
//				{	
//					Odds->KB[h1][b1][h2][b2][0][0]->EjSpelad = true;
//					Odds->KB[h1][b1][h2][b2][0][0]->kvot=0.0;
//				
//				}
//			}
//						
//					}
//					while(	pFile->ReadString( buf, 399 ));
//					MessageBox("Oddsinläsning klar!");
//		EndDialog(5);
//		return;
//	}
//
//	
//	
//	while(franp<=slutsida);
//	
//	Odds->antalInlastaodds = antalInlastaodds;
//	int antaluppfangadeodds;
//	antaluppfangadeodds = 0;
//	if(Odds->m_speltyp == 0)
//	{
//		for(int a1=0;a1<=10;a1++)
//			for(int a2=0;a2<=10;a2++)
//				for(int a3=0;a3<=10;a3++)
//					for(int a4=0;a4<=10;a4++)
//						for(int a5=0;a5<=10;a5++)
//							for(int a6=0;a6<=10;a6++)
//							{
//								if(Odds->KB[a1][a2][a3][a4][a5][a6]!=NULL)
//								{
//									if(Odds->KB[a1][a2][a3][a4][a5][a6]->kvot > 0.0005)
//										antaluppfangadeodds++;
//								}
//							}
//	}
//		MessageBox("klar!");
//	Odds->antaluppfangadeodds = antaluppfangadeodds;
//	Odds->antalmissadeinlastaodds = antalInlastaodds - antaluppfangadeodds;
//	m_Session.Close();
//		EndDialog(5);
//}

int charreturn(int a) // definition { if(d1 > d2) return d1; // returvärde else return d2; // returvärde }
{
	if (a == 0)
		return '1';
	else if (a == 1)
		return '2';
	else if (a == 2)
		return '3';
	else if (a == 3)
		return '4';
	else if (a == 4)
		return '5';
	else if (a == 5)
		return '6';
	else if (a == 6)
		return '7';
	else if (a == 7)
		return '8';
	else if (a == 8)
		return '9';
	else if (a == 9)
		return 'A';
	
}

UINT LasUnibetOddsm2 ( LPVOID param )
{
	 int max_mh1, max_mb1, max_mh2, max_mb2, max_mh3,antalvarv;	
	 int MinMalGrp,MaxMalGrp;
	 char  sUrlOrgexpekt[300];
	 CInternetSession m_Session;
	//CStdioFile *pFile;


	 using namespace std::chrono;
	 milliseconds ms = duration_cast<milliseconds>(
		 high_resolution_clock::now().time_since_epoch());




	 CBombDlg BombDlg;
		MinMalGrp = BombDlg.m_MinMalGrp;
		MaxMalGrp = BombDlg.m_MaxMalGrp;
		antalvarv=0;
		max_mh1 = 4;
		max_mb1 = 4;
		max_mh2 = 6;
		max_mb2 = 6;
		max_mh3 = 6;
	


		HINTERNET hSession = InternetOpen("Mozilla/5.0 (Windows NT 6.3; WOW64; rv:37.0) Gecko/20100101 Firefox/37.0",
			INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
		static TCHAR hdrs [] =
			_T("Content-Type: application/json\r\n");

		sprintf(sUrlOrgexpekt, "/pia/api/v1/dynamic/coupon/%d/odds.json?lang=sv&rand = %llu", Odds->m_matchid, ms);
		static TCHAR frmdata [] =
			_T("{\"odds\":{\"combinationPattern\":\"12__\",\"@type\":\"calc\"}}");
		static LPCSTR accept[63] = { "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8", NULL };

		HINTERNET hConnect = InternetConnect(hSession, _T("poolbetting.api.kambi.com"),
			INTERNET_DEFAULT_HTTPS_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 1);
		HINTERNET hRequest = HttpOpenRequest(hConnect, "POST",
			_T(sUrlOrgexpekt), NULL, NULL, accept, INTERNET_FLAG_SECURE | INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_RELOAD | INTERNET_FLAG_PRAGMA_NOCACHE, 1);


		

		 for (int mh2 = 0; mh2<11; mh2++)
		 {
		
	
			 if (mh2 == 9)
				 frmdata[31] = 'A';
			 else if (mh2 == 10)
				 frmdata[31] = 'B';
			 else
				frmdata[31] = charreturn(mh2);
			// sUrlOrgexpekt[89+mh2] = '1';
			 for (int mb2 = 0; mb2<11; mb2++)
			 {
				 if (mb2 == 9)
					 frmdata[32] = 'A';
				 else if (mb2 == 10)
					 frmdata[32] = 'B';
				 else
				 frmdata[32] = charreturn(mb2);
				

				 BOOL resulting = HttpSendRequest(hRequest, hdrs, strlen(hdrs), frmdata, strlen(frmdata));
				 bool resulting2;
				 DWORD dwBytesAvailable;
				 char* responseText2 = NULL;
				 responseText2 = new char[15000];
				 DWORD lpdwNumberOfBytesRead = 0;
				 DWORD lasterror;
				 do
				 {

					 if (!InternetQueryDataAvailable(hRequest, &dwBytesAvailable, 0, 0)) break;

					 resulting2 = InternetReadFile(hRequest, (LPVOID) responseText2, 15000, &lpdwNumberOfBytesRead);

					 lasterror = GetLastError();


				 } while (resulting2 == 0);


				 //analysera innehållet



				 char buf1[100], buf2[100];


		char str[250];	
		int h1=-1, b1=-1, h2=-1, b2=-1, h3=-1, b3=-1,	h, b, oint,sret;
		
		
		

		int H1, B1, H2, B2, H3, B3, H4, B4, ickespelad;
		float ofloat, ofloat2, tempoddsodds;
		float Bel1, Bel2, Bel3, BelL, Bel, BelH;
		int antal_odds, status, lasindex;
		antal_odds = 0;
		status = 0;
		lasindex = 0;
		float odds;
		odds = 0;
		do
		{
			if (responseText2[lasindex] == 'r' && status == 0)
			{
				status = 1;
			}
			else if (responseText2[lasindex] == 'e' && status == 1)
			{
				status = 2;
			}
			else if (responseText2[lasindex] == 's'  && status == 2)
			{
				status = 3;
			}
			else if (responseText2[lasindex] == 'u' && status == 3)
			{
				status = 4;
			}
			else if (responseText2[lasindex] == 'l' && status == 4)
			{
				status = 5;
			}
			else if (responseText2[lasindex] == 't' && status == 5)
			{
				status = 6;
			}
			else if (responseText2[lasindex] == 'o' && status == 6)
			{
				status = 7;
			}
			else if (responseText2[lasindex] == 'd' && status == 7)
			{
				status = 8;
			}
			else if (responseText2[lasindex] == 'd' && status == 8)
			{
				status = 9;
			}
			else if (responseText2[lasindex] == 's' && status == 9)
			{
				status = 10;
			}
			else if (responseText2[lasindex] == '-' && status == 10)
			{
				status = 12;
				odds = 0;
			}
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 10))
			{
				odds = 10 * odds + (responseText2[lasindex] - 48);

			}
			else if (responseText2[lasindex] == '.' && status == 10)
			{
				status = 11;
			}
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 11))
			{
				float de;
				de = (responseText2[lasindex] - 48);
				de = de / 10;
				odds = odds + de;
				status = 12;
			}
			else if (responseText2[lasindex] == 'e' && (status == 12 || status == 10))
			{
				status = 13;
			}
			else if (responseText2[lasindex] == '$' && (status == 13 || status == 10))
			{
				status = 14;
			}
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 14))
			{
				H1 = (responseText2[lasindex] - 48);
				status = 15;
			}
			//////Lägg in för tvåsiffrigt här
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 15))
			{
				int tmp;
				tmp = (responseText2[lasindex] - 48);
				H1 = H1 * 10;
				H1 = H1 + tmp;
				status = 15;
			}
			else if (responseText2[lasindex] == '-' && status == 15)
			{
				status = 16;
			}
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 16))
			{
				B1 = (responseText2[lasindex] - 48);
				status = 17;
			}
			//////Lägg in för tvåsiffrigt här
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 17))
			{
				int tmp;
				tmp = (responseText2[lasindex] - 48);
				B1 = B1 * 10;
				B1 = B1 + tmp;
				status = 17;
			}
			else if (responseText2[lasindex] == '@' && status == 17)
			{
				status = 18;
			}
			else if (responseText2[lasindex] == '$' && status == 18)
			{
				status = 185;
			}
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 185))
			{
				H2 = (responseText2[lasindex] - 48);
				status = 19;
			}
			//////Lägg in för tvåsiffrigt här
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 19))
			{
				int tmp;
				tmp = (responseText2[lasindex] - 48);
				H2 = H2 * 10;
				H2 = H2 + tmp;
				status = 19;
			}
			else if (responseText2[lasindex] == '-' && status == 19)
			{
				status = 20;
			}
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 20))
			{
				B2 = (responseText2[lasindex] - 48);
				status = 21;
			}
			/////Tvåsiffrigt
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 21))
			{
				int tmp;
				tmp = (responseText2[lasindex] - 48);
				B2 = B2 * 10;
				B2 = B2 + tmp;
				status = 25;
			}
			else if (status == 21 && (responseText2[lasindex] == '}'))
				status = 25;
			/*else if (responseText2[lasindex] == '$' && status == 21)
			{
				status = 22;
			}
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 22))
			{
				H3 = (responseText2[lasindex] - 48);
				status = 23;
			}
			else if (responseText2[lasindex] == '-' && status == 23)
			{
				status = 24;
			}
			else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 24))
			{
				B3 = (responseText2[lasindex] - 48);

				status = 25;
			}*/
			else if (status == 25)
			{
				/*if (H1 == 0 && B1 == 1 && H2 == 0 && B2 == 1)
				{
					int a;
					a = 0;
				}*/
				if (odds > 0)
				{
					if (Odds->KB[H1][B1][H2][B2][0][0][0][0] != NULL)
					{
						Odds->KB[H1][B1][H2][B2][0][0][0][0]->kvot = *(Odds->KvotJust) * odds / Odds->KB[H1][B1][H2][B2][0][0][0][0]->NOdds;
						Odds->KB[H1][B1][H2][B2][0][0][0][0]->EjSpelad = false;
					}


					// Räkna upp antal inlästa odds
					if (!Odds->last[H1][B1][H2][B2][0][0][0][0])
						Odds->NumOdds++;
					Odds->last[H1][B1][H2][B2][0][0][0][0] = true;
				}
				else
				{


					if (Odds->KB[H1][B1][H2][B2][0][0][0][0] != NULL)
						Odds->KB[H1][B1][H2][B2][0][0][0][0]->EjSpelad = true;

					//// Räkna upp antal inlästa odds
					if (!Odds->last[H1][B1][H2][B2][0][0][0][0])
						Odds->NumOdds++;
					Odds->last[H1][B1][H2][B2][0][0][0][0] = true;
				}
				antal_odds++;
				status = 6;
				odds = 0;
			}
			lasindex++;

		} while (/*antal_odds < 144*/ lasindex < 14000);






//////////////////////////////////////////////////////////
		//while ( pFile->ReadString( buf1, 99 ) )
		//{
		//
		//	if (sscanf(buf1,"\t\t\t\t<td class=\"mt_OddsResult\" align=\"center\">%d-%d", &h, &b)==2)
		//	{
		//		if (h1==-1)	
		//		{
		//			h1=h;
		//			b1=b;
		//		}
		//		else if (h2==-1)
		//		{
		//			h2=h;
		//			b2=b;
		//		}
		//	//	else 
		//	//	{
		//	//		h3=h;
		//	//		b3=b;
		//	//	}
		//	}

		//	if (h2 != -1 && sscanf(buf1,"%d,%f", &oint, &ofloat)==2)
		//	{
		//		tempoddsodds = oint*1000.0 + ofloat;
		//		if (Odds->KB[h1][b1][h2][b2][0][0][0][0] != NULL)
		//		{
		//			Odds->KB[h1][b1][h2][b2][0][0][0][0]->kvot = *(Odds->KvotJust) * tempoddsodds/Odds->KB[h1][b1][h2][b2][0][0][0][0]->NOdds;
		//			Odds->KB[h1][b1][h2][b2][0][0][0][0]->EjSpelad = false;
		//		}
		//		// Räkna upp antal inlästa odds
		//		if (!Odds->last[h1][b1][h2][b2][0][0][0][0])
		//			Odds->NumOdds ++;
		//		Odds->last[h1][b1][h2][b2][0][0][0][0] = true;
		//		h1=-1; b1=-1; h2=-1; b2=-1; h3=-1; b3=-1;
		//	}

		//	if (h2 != -1 && sscanf(buf1,"%f", &ofloat)==1)
		//	{
		//		tempoddsodds = ofloat;
		//		if (Odds->KB[h1][b1][h2][b2][0][0][0][0] != NULL)
		//		{
		//			Odds->KB[h1][b1][h2][b2][0][0][0][0]->kvot = *(Odds->KvotJust) * tempoddsodds/Odds->KB[h1][b1][h2][b2][0][0][0][0]->NOdds;
		//			Odds->KB[h1][b1][h2][b2][0][0][0][0]->EjSpelad = false;
		//		}
		//		// Räkna upp antal inlästa odds
		//		if (!Odds->last[h1][b1][h2][b2][0][0][0][0])
		//			Odds->NumOdds ++;
		//		Odds->last[h1][b1][h2][b2][0][0][0][0] = true;
		//		h1=-1; b1=-1; h2=-1; b2=-1; h3=-1; b3=-1;
		//	}

		//	if (h2 != -1 && strstr(buf1,"-&nbsp;") != NULL)
		//	{
		//		if (Odds->KB[h1][b1][h2][b2][0][0][0][0] != NULL)
		//			Odds->KB[h1][b1][h2][b2][0][0][0][0]->EjSpelad = true;

		//		// Räkna upp antal inlästa odds
		//		if (!Odds->last[h1][b1][h2][b2][0][0][0][0])
		//			Odds->NumOdds ++;
		//		Odds->last[h1][b1][h2][b2][0][0][0][0] = true;
		//		h1=-1; b1=-1; h2=-1; b2=-1; h3=-1; b3=-1;
		//	}
		//	strcpy(buf2, buf1);
		//		//slut analysera innehållet
		//	 }

		/////////////////////////////////////////////////////////
		}
			 antalvarv++;
		::PostMessage((HWND)param, WM_ODDSREAD,antalvarv/10,0);
	}
	::PostMessage((HWND)param, WM_ODDSFINISHED,0,0);
	return 0;
}

void scanna_oddsen(char responseText2[])
{
	//analysera innehållet
	char buf1[100], buf2[100];


	char str[250];
	int h1 = -1, b1 = -1, h2 = -1, b2 = -1, h3 = -1, b3 = -1, h, b, oint, sret;
	int H1, B1, H2, B2, H3, B3, H4, B4, ickespelad;
	float ofloat, ofloat2, tempoddsodds;
	float Bel1, Bel2, Bel3, BelL, Bel, BelH;
	int antal_odds, status, lasindex;
	antal_odds = 0;
	status = 0;
	lasindex = 0;
	float odds;
	odds = 0;
	do
	{
		if (responseText2[lasindex] == 'r' && status == 0)
		{
			status = 1;
		}
		else if (responseText2[lasindex] == 'e' && status == 1)
		{
			status = 2;
		}
		else if (responseText2[lasindex] == 's'  && status == 2)
		{
			status = 3;
		}
		else if (responseText2[lasindex] == 'u' && status == 3)
		{
			status = 4;
		}
		else if (responseText2[lasindex] == 'l' && status == 4)
		{
			status = 5;
		}
		else if (responseText2[lasindex] == 't' && status == 5)
		{
			status = 6;
		}
		else if (responseText2[lasindex] == 'o' && status == 6)
		{
			status = 7;
		}
		else if (responseText2[lasindex] == 'd' && status == 7)
		{
			status = 8;
		}
		else if (responseText2[lasindex] == 'd' && status == 8)
		{
			status = 9;
		}
		else if (responseText2[lasindex] == 's' && status == 9)
		{
			status = 10;
		}
		else if (responseText2[lasindex] == '-' && status == 10)
		{
			status = 12;
			odds = 0;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 10))
		{
			odds = 10 * odds + (responseText2[lasindex] - 48);

		}
		else if (responseText2[lasindex] == '.' && status == 10)
		{
			status = 11;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 11))
		{
			float de;
			de = (responseText2[lasindex] - 48);
			de = de / 10;
			odds = odds + de;
			status = 12;
		}
		else if (responseText2[lasindex] == 'e' && (status == 12 || status == 10))
		{
			status = 13;
		}
		else if (responseText2[lasindex] == '$' && (status == 13 || status == 10))
		{
			status = 14;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 14))
		{
			H1 = (responseText2[lasindex] - 48);
			status = 15;
		}
		else if (responseText2[lasindex] == '-' && status == 15)
		{
			status = 16;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 16))
		{
			B1 = (responseText2[lasindex] - 48);
			status = 17;
		}
		else if (responseText2[lasindex] == '$' && status == 17)
		{
			status = 18;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 18))
		{
			H2 = (responseText2[lasindex] - 48);
			status = 19;
		}
		else if (responseText2[lasindex] == '-' && status == 19)
		{
			status = 20;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 20))
		{
			B2 = (responseText2[lasindex] - 48);
			status = 21;
		}
		else if (responseText2[lasindex] == '$' && status == 21)
		{
			status = 22;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 22))
		{
			H3 = (responseText2[lasindex] - 48);
			status = 23;
		}
		else if (responseText2[lasindex] == '-' && status == 23)
		{
			status = 24;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 24))
		{
			B3 = (responseText2[lasindex] - 48);

			status = 25;
		}
		else if (status == 25)
		{
			if (odds > 0)
			{
				if (Odds->KB[H1][B1][H2][B2][H3][B3][0][0] != NULL)
				{
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->kvot = *(Odds->KvotJust) * odds / Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->NOdds;
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = false;
				}
				/*else
				{
				Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;
				}*/
				// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][0][0] = true;
			}
			else
			{
				if (Odds->KB[H1][B1][H2][B2][H3][B3][0][0] != NULL)
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;

				//// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][0][0] = true;
			}
			antal_odds++;
			status = 6;
			odds = 0;
		}
		lasindex++;

	} while (/*antal_odds < 144*/ lasindex < 14000);
}
void scanna_oddsen_sverige(char responseText2[])
{
	//analysera innehållet
	char buf1[100], buf2[100];


	char str[250];
	int h1 = -1, b1 = -1, h2 = -1, b2 = -1, h3 = -1, b3 = -1, h, b, oint, sret;
	int H1, B1, H2, B2, H3, B3, H4, B4, ickespelad;
	float ofloat, ofloat2, tempoddsodds;
	float Bel1, Bel2, Bel3, BelL, Bel, BelH;
	int antal_odds, status, lasindex;
	antal_odds = 0;
	status = 0;
	lasindex = 0;
	float odds,odds2;
	odds = 0;
	do
	{
		if (responseText2[lasindex] == 'l' && status == 0)
		{
			status = 1;
		}
		else if (responseText2[lasindex] == 'i' && status == 1)
		{
			status = 2;
		}
		else if (responseText2[lasindex] == 's' && status == 2)
		{
			status = 3;
		}
		else if (responseText2[lasindex] == 't' && status == 3)
		{
			status = 4;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 4))
		{
			status = 5;
			H1 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == '-' && status == 5)
		{
			status = 6;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 6))
		{
			status = 7;
			B1 = (responseText2[lasindex] - 48);
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 7))
		{
			status = 8;
			H2 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == '-' && status == 8)
		{
			status = 9;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 9))
		{
			status = 10;
			B2 = (responseText2[lasindex] - 48);
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 10))
		{
			status = 11;
			H3 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == '-' && status == 11)
		{
			status = 12;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 12))
		{
			status = 13;
			B3 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == 'o' && status == 13)
		{
			status = 14;
		}

		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 14))
		{
			int temp;
			temp = responseText2[lasindex] - 48;
			odds = 10 * odds + temp;
		}
		else if (responseText2[lasindex] == ',' && status == 14)
		{
			status = 15;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 15))
		{

			float de;
			de = (responseText2[lasindex] - 48);
			de = de / 10;
			odds = odds + de;
			status = 16;
			
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 16))
		{
			float decc;
			decc = (responseText2[lasindex] - 48);
			decc = decc / 100;
			status = 17;
			odds = odds + decc;
		}
		else if (responseText2[lasindex] == 'c' && status > 16)
		{
			int dummy;
			dummy = 1;
			odds2 = odds;
			int hjalpodds;
			if (Odds->KB[H1][B1][H2][B2][H3][B3][0][0] != NULL) {
				hjalpodds = Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->NOdds;
			}
			else {
				hjalpodds = Odds->m_maxnomodds;
			}
		//	if (odds >(Odds->m_omsattning*0.35) && Odds->m_en_krona_ospelad) {
			if (odds >(Odds->m_minodds) && Odds->m_en_krona_ospelad && hjalpodds < Odds->m_maxnomodds) {
				
				odds = 0;
			}
			if (odds > 0 && Odds->m_en_krona_ospelad==false)
			{
				if (Odds->KB[H1][B1][H2][B2][H3][B3][0][0] != NULL)
				{
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->kvot = *(Odds->KvotJust) * odds / Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->NOdds;
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = false;
				}
				/*else
				{
				Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;
				}*/
				// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][0][0] = true;
			}
			//else if(Odds->m_en_krona_ospelad == false)
			else if(odds2 > Odds->m_minodds && hjalpodds < Odds->m_maxnomodds)
			{
				if (Odds->KB[H1][B1][H2][B2][H3][B3][0][0] != NULL)
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;

				//// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][0][0] = true;
			}
			else {
				if (Odds->KB[H1][B1][H2][B2][H3][B3][0][0] != NULL)
				{
				//	Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->kvot = *(Odds->KvotJust) * odds / Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->NOdds;
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->kvot = 0.5;
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = false;
				}
				/*else
				{
				Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;
				}*/
				// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][0][0] = true;
			}


			odds = 0;
			status = 4;
		}
		else if (responseText2[lasindex] == 'n' && status > 15)
		{
			status = 33;
		}
		lasindex++;
	} while (status < 33);
}


void scanna_oddsen_sverige_is(char responseText3[])
{
	//analysera innehållet
	char buf1[100], buf2[100];


	char str[250];
	int h1 = -1, b1 = -1, h2 = -1, b2 = -1, h3 = -1, b3 = -1, h, b, oint, sret;
	int H1, B1, H2, B2, H3, B3, H4, B4, ickespelad;
	float ofloat, ofloat2, tempoddsodds;
	float Bel1, Bel2, Bel3, BelL, Bel, BelH;
	int antal_odds, status, lasindex;
	antal_odds = 0;
	status = 0;
	lasindex = 0;
	float odds,odds2;
	odds = 0;
	do
	{
		if (responseText3[lasindex] == 'l' && status == 0)
		{
			status = 1;
		}
		else if (responseText3[lasindex] == 'i' && status == 1)
		{
			status = 2;
		}
		else if (responseText3[lasindex] == 's' && status == 2)
		{
			status = 3;
		}
		else if (responseText3[lasindex] == 't' && status == 3)
		{
			status = 4;
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 4))
		{
			status = 5;
			H1 = (responseText3[lasindex] - 48);
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 5))
		{
			int tmpH;
			status = 5;
			tmpH = (responseText3[lasindex] - 48);
			H1 = H1 * 10;
			H1 = H1 + tmpH;
		}
		else if (responseText3[lasindex] == '-' && status == 5)
		{
			status = 6;
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 6))
		{
			status = 7;
			B1 = (responseText3[lasindex] - 48);
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 7))
		{
			int tmpB;
			tmpB = (responseText3[lasindex] - 48);
			B1 = B1 * 10;
			B1 = B1 + tmpB;
			status = 7;
		}
		else if ((responseText3[lasindex] < '0' && status == 7))
		{
			char t;
			t = responseText3[lasindex];
			status = 8;
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 8))
		{
			status = 9;
			H2 = (responseText3[lasindex] - 48);
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 9))
		{
			int tmpH2;
			tmpH2 = (responseText3[lasindex] - 48);
			H2 = H2 * 10;
			H2 = H2 + tmpH2;
			status = 9;

		}
		
		else if (responseText3[lasindex] == '-' && status == 9)
		{
			status = 10;
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 10))
		{
			status = 13;
			B2 = (responseText3[lasindex] - 48);
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 13))
		{
			status = 13;
			int tmpB2;
			tmpB2 = (responseText3[lasindex] - 48);
			B2 = B2 * 10;
			B2 = B2 + tmpB2;
		}


		/*else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 10))
		{
			status = 11;
			H3 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == '-' && status == 11)
		{
			status = 12;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 12))
		{
			status = 13;
			B3 = (responseText2[lasindex] - 48);
		}*/
		else if (responseText3[lasindex] == 'o' && status == 13)
		{
			status = 14;
		}

		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 14))
		{
			int temp;
			temp = responseText3[lasindex] - 48;
			odds = 10 * odds + temp;
		}
		else if (responseText3[lasindex] == ',' && status == 14)
		{
			status = 15;
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 15))
		{

			float de;
			de = (responseText3[lasindex] - 48);
			de = de / 10;
			odds = odds + de;
			status = 16;

		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 16))
		{
			float decc;
			decc = (responseText3[lasindex] - 48);
			decc = decc / 100;
			status = 17;
			odds = odds + decc;
		}
		else if (responseText3[lasindex] == 'c' && status > 16)
		{
			int dummy;
			dummy = 1;
			odds2 = odds;
			int hjalpodds;
			if (Odds->KB[H1][B1][H2][B2][0][0][0][0] != NULL) {
				hjalpodds = Odds->KB[H1][B1][H2][B2][0][0][0][0]->NOdds;
			}
			else {
				hjalpodds = Odds->m_maxnomodds;
			}
			if (odds >(Odds->m_minodds) && Odds->m_en_krona_ospelad && hjalpodds < Odds->m_maxnomodds) {

				odds = 0;
			}
			//if (odds > 0)
			if (odds > 0 && Odds->m_en_krona_ospelad == false)
			{
				if (Odds->KB[H1][B1][H2][B2][0][0][0][0] != NULL)
				{
					Odds->KB[H1][B1][H2][B2][0][0][0][0]->kvot = *(Odds->KvotJust) * odds / Odds->KB[H1][B1][H2][B2][0][0][0][0]->NOdds;
					Odds->KB[H1][B1][H2][B2][0][0][0][0]->EjSpelad = false;
				}
				/*else
				{
				Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;
				}*/
				// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][0][0][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][0][0][0][0] = true;
			}
			else if (odds2 > Odds->m_minodds && hjalpodds < Odds->m_maxnomodds)
			{
				if (Odds->KB[H1][B1][H2][B2][0][0][0][0] != NULL)
					Odds->KB[H1][B1][H2][B2][0][0][0][0]->EjSpelad = true;

				//// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][0][0][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][0][0][0][0] = true;
			}
			else {
				if (Odds->KB[H1][B1][H2][B2][0][0][0][0] != NULL)
				{
					//	Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->kvot = *(Odds->KvotJust) * odds / Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->NOdds;
					Odds->KB[H1][B1][H2][B2][0][0][0][0]->kvot = 0.5;
					Odds->KB[H1][B1][H2][B2][0][0][0][0]->EjSpelad = false;
				}
				/*else
				{
				Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;
				}*/
				// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][0][0][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][0][0][0][0] = true;
			}

			odds = 0;
			status = 4;
		}
		else if (responseText3[lasindex] == 'n' && status > 15)
		{
			status = 33;
		}
		lasindex++;
	} while (status < 33);
}


void scanna_oddsen_sverige_is_tre(char responseText3[])
{
	//analysera innehållet
	char buf1[100], buf2[100];


	char str[250];
	int h1 = -1, b1 = -1, h2 = -1, b2 = -1, h3 = -1, b3 = -1, h, b, oint, sret;
	int H1, B1, H2, B2, H3, B3, H4, B4, ickespelad;
	float ofloat, ofloat2, tempoddsodds;
	float Bel1, Bel2, Bel3, BelL, Bel, BelH;
	int antal_odds, status, lasindex;
	antal_odds = 0;
	status = 0;
	lasindex = 0;
	float odds,odds2;
	odds = 0;
	do
	{
		if (responseText3[lasindex] == 'l' && status == 0)
		{
			status = 1;
		}
		else if (responseText3[lasindex] == 'i' && status == 1)
		{
			status = 2;
		}
		else if (responseText3[lasindex] == 's' && status == 2)
		{
			status = 3;
		}
		else if (responseText3[lasindex] == 't' && status == 3)
		{
			status = 4;
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 4))
		{
			status = 5;
			H1 = (responseText3[lasindex] - 48);
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 5))
		{
			int tmpH;
			status = 5;
			tmpH = (responseText3[lasindex] - 48);
			H1 = H1 * 10;
			H1 = H1 + tmpH;
		}
		else if (responseText3[lasindex] == '-' && status == 5)
		{
			status = 6;
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 6))
		{
			status = 7;
			B1 = (responseText3[lasindex] - 48);
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 7))
		{
			int tmpB;
			tmpB = (responseText3[lasindex] - 48);
			B1 = B1 * 10;
			B1 = B1 + tmpB;
			status = 7;
		}
		else if ((responseText3[lasindex] < '0' && status == 7))
		{
			char t;
			t = responseText3[lasindex];
			status = 8;
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 8))
		{
			status = 9;
			H2 = (responseText3[lasindex] - 48);
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 9))
		{
			int tmpH2;
			tmpH2 = (responseText3[lasindex] - 48);
			H2 = H2 * 10;
			H2 = H2 + tmpH2;
			status = 9;

		}

		else if (responseText3[lasindex] == '-' && status == 9)
		{
			status = 10;
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 10))
		{
			status = 13;
			B2 = (responseText3[lasindex] - 48);
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 13))
		{
			status = 13;
			int tmpB2;
			tmpB2 = (responseText3[lasindex] - 48);
			B2 = B2 * 10;
			B2 = B2 + tmpB2;
		}
		else if ((responseText3[lasindex] < '0' && status == 13))
		{
			char t;
			t = responseText3[lasindex];
			status = 14;
		}

		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 14))
		{
			status = 15;
			H3 = (responseText3[lasindex] - 48);
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 15))
		{
			int tmpH2;
			tmpH2 = (responseText3[lasindex] - 48);
			H3 = H3 * 10;
			H3 = H3 + tmpH2;
			status = 15;

		}

		else if ((responseText3[lasindex] < '0' && status == 15))
		{
			char t;
			t = responseText3[lasindex];
			status = 17;
		}

		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 17))
		{
			status = 18;
			B3 = (responseText3[lasindex] - 48);
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 18))
		{
			status = 18;
			int tmpB2;
			tmpB2 = (responseText3[lasindex] - 48);
			B3 = B3 * 10;
			B3 = B3 + tmpB2;
		}


		/*else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 10))
		{
		status = 11;
		H3 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == '-' && status == 11)
		{
		status = 12;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 12))
		{
		status = 13;
		B3 = (responseText2[lasindex] - 48);
		}*/
		else if (responseText3[lasindex] == 'o' && status == 18)
		{
			status = 19;
		}

		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 19))
		{
			int temp;
			temp = responseText3[lasindex] - 48;
			odds = 10 * odds + temp;
		}
		else if (responseText3[lasindex] == ',' && status == 19)
		{
			status = 20;
		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 20))
		{

			float de;
			de = (responseText3[lasindex] - 48);
			de = de / 10;
			odds = odds + de;
			status = 21;

		}
		else if ((responseText3[lasindex] >= '0' && (responseText3[lasindex] <= '9') && status == 21))
		{
			float decc;
			decc = (responseText3[lasindex] - 48);
			decc = decc / 100;
			status = 22;
			odds = odds + decc;
		}
		else if (responseText3[lasindex] == 'c' && status > 21)
		{
			int dummy;
			dummy = 1;
			odds2 = odds;
			int hjalpodds;
			if (Odds->KB[H1][B1][H2][B2][H3][B3][0][0] != NULL) {
				hjalpodds = Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->NOdds;
			}
			else {
				hjalpodds = Odds->m_maxnomodds;
			}
			if (odds >(Odds->m_minodds) && Odds->m_en_krona_ospelad && hjalpodds < Odds->m_maxnomodds) {

				odds = 0;
			}
		//	if (odds > 0)
			if (odds > 0 && Odds->m_en_krona_ospelad == false)
			{
				if (Odds->KB[H1][B1][H2][B2][H3][B3][0][0] != NULL)
				{
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->kvot = *(Odds->KvotJust) * odds / Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->NOdds;
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = false;
				}
				/*else
				{
				Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;
				}*/
				// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][0][0] = true;
			}
			else if (odds2 > Odds->m_minodds && hjalpodds < Odds->m_maxnomodds)
			{
				if (Odds->KB[H1][B1][H2][B2][H3][B3][0][0] != NULL)
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;

				//// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][0][0] = true;
			}

			else {
				if (Odds->KB[H1][B1][H2][B2][H3][B3][0][0] != NULL)
				{
					//	Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->kvot = *(Odds->KvotJust) * odds / Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->NOdds;
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->kvot = 0.5;
					Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = false;
				}
				/*else
				{
				Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;
				}*/
				// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][0][0])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][0][0] = true;
			}

			odds = 0;
			status = 4;
		}
		else if (responseText3[lasindex] == 'n' && status > 15)
		{
			status = 33;
		}
		lasindex++;
	} while (status < 33);
}

UINT LasDenyaSvenskaOddsen_is_tre(LPVOID param)
{

	char  sUrlOrg[300];
	int antalvarv;
	CInternetSession m_Session;
	CStdioFile *pFile, Logfile;
	int antal_odds;
	float odds;
	int status;
	char buffer[17000];
	antalvarv = 0;
	antal_odds = 0;
	int mal1, mal2, mal3, mal4, mal5, mal6, mal7, mal8, mal9, mal10, mal11, mal12, mal13, mal14, mal15, mal16, mal17, mal18, mal19;
	mal1 = 0;
	mal2 = 1;
	mal3 = 2;
	mal4 = 3;
	mal5 = 4;
	mal6 = 0;
	mal7 = 1;
	mal8 = 2;
	mal9 = 3;
	mal10 = 4;
	mal11 = 0;
	mal12 = 1;
	mal13 = 2;
	mal14 = 3;
	mal15 = 4;
	mal16 = 0;
	mal17 = 1;
	sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d&away1=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d&home2=%d&away2=%d&home3=0&away3=0", Odds->m_matchid, mal1, mal2, mal3, mal4, mal5, mal6, mal7, mal8, mal9, mal10, mal11, mal12, mal13, mal14, mal15, mal16, mal17);
	
			
				for(int mh2 = 0;mh2<6;mh2++)
				{
					int mh2b = (2 * mh2) + 1;
					for (int mb2 = 0;mb2 < 11;mb2++)
					{
						
							for (int mh3 = 0;mh3 < 11; mh3++)
							{
								
								for (int mb3 = 0;mb3 < 11;mb3++)
								{
									
									//	sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d&away1=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d&home2=%d&away2=%d&home3=%d&away3=%d", Odds->m_matchid, 0, 1, 2, 3, 4, 5,6,7,8,9,10, 0, 1,2,3,4,5,6,7,8,9,10, mh2, mb2, mh3,mb3);
									if (mh2 < 5) {
										int mh2double = 2 * mh2;
										sprintf(sUrlOrg, "https://api.www.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d&away1=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d&home2=%d,%d&away2=%d&home3=%d&away3=%d", Odds->m_matchid, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, mh2double,mh2b, mb2, mh3, mb3);
									}
									else if (mh2 == 5) {
										int mh2double = 2 * mh2;
										sprintf(sUrlOrg, "https://api.www.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d&away1=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d&home2=%d&away2=%d&home3=%d&away3=%d", Odds->m_matchid, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, mh2double, mb2, mh3, mb3);
									}
										//	sprintf(sUrlOrg, "https://api.www.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=10889&home1=0,1,2,3,4,5,6,7,8,9&away1=0,1,2,3,4&home2=0,1,2,3,4&away2=0&home3=0&away3=0");
										::Sleep(5);
										pFile = m_Session.OpenURL(sUrlOrg, 1, INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_TRANSFER_ASCII);
										pFile->ReadString(buffer, 16099);
										status = 0;
										//	do
										//	{
										scanna_oddsen_sverige_is_tre(buffer);
										antalvarv++;
										//	antal_odds += 250;
										//	Odds->NumOdds += 250;
										//	} while (antalvarv < 4000);

										//	::PostMessage((HWND)param, WM_ODDSREAD, antalvarv / 10, 0);
											pFile->Close();
									}
								//pFile->Close();
								}
								/////////////////////////////////////////////////////////////////////////
								::PostMessage((HWND)param, WM_ODDSREAD, antalvarv / 500, 0);

							}
						}
						



	::PostMessage((HWND)param, WM_ODDSFINISHED, 0, 0);
	return 0;
}


UINT LasDenyaSvenskaOddsen(LPVOID param)
{

	char  sUrlOrg[300];
	int antalvarv;
	CInternetSession m_Session;
	CStdioFile *pFile, Logfile;
	int antal_odds;
	float odds;
	int status;
	char buffer[17000];
	antalvarv = 0;
	antal_odds = 0;
	int mal1, mal2, mal3, mal4, mal5, mal6, mal7, mal8, mal9, mal10, mal11, mal12, mal13,mal14,mal15,mal16,mal17,mal18,mal19;
	mal1 = 0;
	mal2 = 1;
	mal3 = 2;
	mal4 = 3;
	mal5 = 4;
	mal6 = 0;
	mal7 = 1;
	mal8 = 2;
	mal9 = 3;
	mal10 = 4;
	mal11 = 0;
	mal12 = 1;
	mal13 = 2;
	mal14 = 3;
	mal15 = 4;
	mal16 = 0;
	mal17 = 1;
	sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=%d,%d,%d,%d,%d&away1=%d,%d,%d,%d,%d&home2=%d,%d,%d,%d,%d&away2=%d,%d&home3=0&away3=0", Odds->m_matchid,mal1,mal2,mal3,mal4,mal5,mal6,mal7,mal8,mal9,mal10,mal11,mal12,mal13,mal14,mal15,mal16,mal17);
	for (int mh1 = 0;mh1 < 2;mh1++)
	{
		if (mh1 == 1)
		{
			mal1 = 5;
			mal2 = 6;
			mal3 = 7;
			mal4 = 8;
			mal5 = 9;
			mal6 = 0;
			mal7 = 1;
			mal8 = 2;
			mal9 = 3;
			mal10 = 4;
			mal11 = 0;
			mal12 = 1;
			mal13 = 2;
			mal14 = 3;
			mal15 = 4;
			mal16 = 0;
			mal17 = 1;
		}
			for (int mb1 = 0; mb1 < 2; mb1++)
			{
				if (mb1 == 1)
				{
					mal6 = 5;
					mal7 = 6;
					mal8 = 7;
					mal9 = 8;
					mal10 = 9;

					mal11 = 0;
					mal12 = 1;
					mal13 = 2;
					mal14 = 3;
					mal15 = 4;
					mal16 = 0;
					mal17 = 0;
				}
				if (!(mh1 == 1 && mb1 == 1))
				{
					for (int mh2 = 0; mh2 < 2;mh2++)
					{
						if (mh2 == 1)
						{
							mal11 = 5;
							mal12 = 6;
							mal13 = 7;
							mal14 = 8;
							mal15 = 9;
							mal16 = 0;
							mal17 = 0;
						}
						
							for (int mb2 = 0;mb2 < 5;mb2++)
							{
								if (!(mh2 == 1 && mb2 > 2))
								{
								mal16 = mb2 * 2;
								mal17 = mal16 + 1;
								for (int mh3 = 0;mh3 < 10; mh3++)
								{
									mal18 = mh3;
									for (int mb3 = 0;mb3 < 10;mb3++)
									{
										if (!(mh3 > 4 && mb3 > 4))
										{
											mal19 = mb3;
											sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=%d,%d,%d,%d,%d&away1=%d,%d,%d,%d,%d&home2=%d,%d,%d,%d,%d&away2=%d,%d&home3=%d&away3=%d", Odds->m_matchid, mal1, mal2, mal3, mal4, mal5, mal6, mal7, mal8, mal9, mal10, mal11, mal12, mal13, mal14, mal15, mal16, mal17, mal18, mal19);
											//	sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=10889&home1=0,1,2,3,4,5,6,7,8,9&away1=0,1,2,3,4&home2=0,1,2,3,4&away2=0&home3=0&away3=0");
											::Sleep(5);
											pFile = m_Session.OpenURL(sUrlOrg, 1, INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_TRANSFER_ASCII);
											pFile->ReadString(buffer, 16099);
											status = 0;
											//	do
											//	{
											scanna_oddsen_sverige(buffer);
											antalvarv++;
											//	antal_odds += 250;
											//	Odds->NumOdds += 250;
										//	} while (antalvarv < 4000);

										//	::PostMessage((HWND)param, WM_ODDSREAD, antalvarv / 10, 0);
										//	pFile->Close();
										}
										pFile->Close();
									}
									/////////////////////////////////////////////////////////////////////////
									::PostMessage((HWND)param, WM_ODDSREAD, antalvarv / 500, 0);

								}
								//pFile->Close();
							}
							////
						}
					}
				}
				//////////////////////////////////////////////////////////////////////////
				//	::PostMessage((HWND)param, WM_ODDSREAD, mb1, 0);
			}
		
		
	}
	::PostMessage((HWND)param, WM_ODDSFINISHED, 0, 0);
	return 0;
	}



	UINT LasDenyaSvenskaOddsen_bandy2m(LPVOID param)
	{

		char  sUrlOrg[300];
		int antalvarv;
		CInternetSession m_Session;
		CStdioFile *pFile, Logfile;
		int antal_odds;
		float odds;
		int status;
		char buffer[17000];
		antalvarv = 0;
		antal_odds = 0;
		int mal1, mal2, mal3, mal4, mal5, mal6, mal7, mal8, mal9, mal10, mal11, mal12, mal13, mal14, mal15, mal16, mal17, mal18, mal19;
		mal1 = 0;
		mal2 = 1;
		sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=0,1,2,3,4,5,6,7,8,9,10%d&away1=0,1,2,3,4,5,6,7,8,9,10&home2=%d&away2=%d", Odds->m_matchid, mal1, mal2);
		for (int mh2 = 0; mh2 < 11; mh2++)
		{
			mal1 = mh2;
			for (int mb2 = 0; mb2 < 11; mb2++)
			{

				mal2 = mb2;






				sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=0,1,2,3,4,5,6,7,8,9,10&away1=0,1,2,3,4,5,6,7,8,9,10&home2=%d&away2=%d", Odds->m_matchid, mal1, mal2);
				//	sprintf(sUrlOrg, "https://api.www.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=10889&home1=0,1,2,3,4,5,6,7,8,9&away1=0,1,2,3,4&home2=0,1,2,3,4&away2=0&home3=0&away3=0");
				::Sleep(5);
				pFile = m_Session.OpenURL(sUrlOrg, 1, INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_TRANSFER_ASCII);
				pFile->ReadString(buffer, 16099);
				status = 0;

				scanna_oddsen_sverige_is(buffer);
				antalvarv++;



				/////////////////////////////////////////////////////////////////////////
				::PostMessage((HWND)param, WM_ODDSREAD, antalvarv / 500, 0);



				////



				//////////////////////////////////////////////////////////////////////////
				//	::PostMessage((HWND)param, WM_ODDSREAD, mb1, 0);
			}


		}
		::PostMessage((HWND)param, WM_ODDSFINISHED, 0, 0);
		return 0;
	}



	UINT LasDenyaSvenskaOddsen_is(LPVOID param)
	{

		char  sUrlOrg[300];
		int antalvarv;
		CInternetSession m_Session;
		CStdioFile *pFile, Logfile;
		int antal_odds;
		float odds;
		int status;
		char buffer[17000];
		antalvarv = 0;
		antal_odds = 0;
		int mal1, mal2, mal3, mal4, mal5, mal6, mal7, mal8, mal9, mal10, mal11, mal12, mal13, mal14, mal15, mal16, mal17, mal18, mal19;
		mal1 = 0;
		mal2 = 1;
		sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=0,1,2,3,4,5,6,7,8,9,10%d&away1=0,1,2,3,4,5,6,7,8,9,10&home2=%d&away2=%d", Odds->m_matchid, mal1, mal2);
		for (int mh2 = 0;mh2 < 11;mh2++)
		{
			mal1 = mh2;
			for (int mb2 = 0; mb2 < 11; mb2++)
			{
				
				mal2 = mb2;
			

						
							
										
										
											sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=0,1,2,3,4,5,6,7,8,9,10&away1=0,1,2,3,4,5,6,7,8,9,10&home2=%d&away2=%d", Odds->m_matchid, mal1, mal2);
											//	sprintf(sUrlOrg, "https://api.www.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=10889&home1=0,1,2,3,4,5,6,7,8,9&away1=0,1,2,3,4&home2=0,1,2,3,4&away2=0&home3=0&away3=0");
											::Sleep(5);
											pFile = m_Session.OpenURL(sUrlOrg, 1, INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_TRANSFER_ASCII);
											pFile->ReadString(buffer, 16099);
											status = 0;
											
											scanna_oddsen_sverige_is(buffer);
											antalvarv++;
											
										
									
									/////////////////////////////////////////////////////////////////////////
									::PostMessage((HWND)param, WM_ODDSREAD, antalvarv / 500, 0);

								
							
							////
						
					
				
				//////////////////////////////////////////////////////////////////////////
				//	::PostMessage((HWND)param, WM_ODDSREAD, mb1, 0);
			}


		}
		::PostMessage((HWND)param, WM_ODDSFINISHED, 0, 0);
		return 0;
	}






UINT LasUnibetOdds(LPVOID param)
{
	int max_mh1, max_mb1, max_mh2, max_mb2, max_mh3;
	int MinMalGrp, MaxMalGrp, antalvarv;
	char  sUrlOrgexpekt[300];
	CInternetSession m_Session;
	//	CStdioFile *pFile;
	CBombDlg BombDlg;
	MinMalGrp = BombDlg.m_MinMalGrp;
	MaxMalGrp = BombDlg.m_MaxMalGrp;
	antalvarv = 0;
	max_mh1 = 4;
	max_mb1 = 4;
	max_mh2 = 6;
	max_mb2 = 6;
	max_mh3 = 6;

	time_t  timev;
	time(&timev);
	using namespace std::chrono;
	milliseconds ms = duration_cast<milliseconds>(
		high_resolution_clock::now().time_since_epoch());

	


		/* TH nytt 2015-04-14***/
	HINTERNET hSession = InternetOpen("Mozilla/5.0 (Windows NT 6.3; WOW64; rv:37.0) Gecko/20100101 Firefox/37.0",
	INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	static TCHAR hdrs[] =
		_T("Content-Type: application/json\r\n");
	
		sprintf(sUrlOrgexpekt, "/pia/api/v1/dynamic/coupon/%d/odds.json?lang=sv&rand = %llu", Odds->m_matchid, ms);
		static TCHAR frmdata [] =
			_T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111111000001111110000011110000000100000000001000000000010000000000\"}}");
		static LPCSTR accept[63] = { "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8", NULL };

		HINTERNET hConnect = InternetConnect(hSession, _T("poolbetting.api.kambi.com"),
			INTERNET_DEFAULT_HTTPS_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 1);
		HINTERNET hRequest = HttpOpenRequest(hConnect, "POST",
			_T(sUrlOrgexpekt), NULL, NULL, accept, INTERNET_FLAG_SECURE | INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_RELOAD | INTERNET_FLAG_PRAGMA_NOCACHE, 1);

	    for (int mh2 = 0; mh2<2; mh2++)
		{
			if(mh2 == 1)
			{
				

				frmdata[96] = '0';
				frmdata[97] = '0';
				frmdata[98] = '0';
				frmdata[99] = '0';

				frmdata[100] = '1';
				frmdata[101] = '1';
				frmdata[102] = '1';
				frmdata[103] = '1';
				frmdata[113] = '0';
			
			}
	      for (int mb2 = 0; mb2<7; mb2++)
		  {
			  frmdata[124] = '0';
			   if(mb2 > 0)
			   {
				
				frmdata[106 + mb2] = '0';
			   }
			 frmdata[107 + mb2] = '1';
		      for (int mh3 = 0; mh3<7; mh3++)
			  {
				  frmdata[135] = '0';
				  if(mh3 > 0)
				  {
					
					frmdata[117 + mh3] = '0';
				  }
				  frmdata[118 + mh3] = '1';
				  for (int mb3 = 0; mb3 < 7; mb3++)
				  {
					  if (!(mh3 > 4 && mb3 > 4))
					  {
						  if (mb3 > 0)
							  frmdata[128 + mb3] = '0';
						  frmdata[129 + mb3] = '1';

						  BOOL resulting = HttpSendRequest(hRequest, hdrs, strlen(hdrs), frmdata, strlen(frmdata));
						  bool resulting2;
						  DWORD dwBytesAvailable;
						  char* responseText2 = NULL;
						  responseText2 = new char[17000];
						  DWORD lpdwNumberOfBytesRead = 0;
						  DWORD lasterror;
						  do
						  {

							  if (!InternetQueryDataAvailable(hRequest, &dwBytesAvailable, 0, 0)) break;

							  resulting2 = InternetReadFile(hRequest, (LPVOID)responseText2, 17000, &lpdwNumberOfBytesRead);

							  lasterror = GetLastError();


						  } while (resulting2 == 0);


						  //analysera innehållet
						  scanna_oddsen(responseText2);

					  }
				  }
				   ////////////////////////////////////////////
				   antalvarv++;
				::PostMessage((HWND)param, WM_ODDSREAD,antalvarv/20,0);

			  }
		  }
		}

		//Nu ska vi behandla odds med fler mål.....////
	///////////sprintf(sUrlOrgexpekt,"http://www.expekt.com/supertotoProxy/ownodds.htm?coupon=%d&combp=000000100001110000000011110000000111100000001110000000010000000000&filter=000000000&lang=sv", Odds->m_matchid);
		static TCHAR frmdata2[]  =
			_T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"000000100001110000000011110000000111100000001110000000010000000000\"}}");
		
	//	static LPCSTR accept[63] = { "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8", NULL };
		for (int ytterloop = 0; ytterloop < 3; ytterloop++)
		{
			if (ytterloop > 0)
			{
				frmdata2[79 + ytterloop] = '0';
				frmdata2[80 + ytterloop] = '1';
				frmdata2[132] = '0';
				frmdata2[129] = '1';
				// _T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111000000001000000000011110000000111100000000000000100011100000000\"}}");
			}
			for (int mb3 = 0; mb3 < 4; mb3++)
			{
				if (mb3 > 0)
				{




					frmdata2[128 + mb3] = '0';
					frmdata2[129 + mb3] = '1';
				}


				BOOL resulting = HttpSendRequest(hRequest, hdrs, strlen(hdrs), frmdata2, strlen(frmdata2));
				bool resulting2;
				DWORD dwBytesAvailable;
				char* responseText2 = NULL;
				responseText2 = new char[15000];
				DWORD lpdwNumberOfBytesRead = 0;
				DWORD lasterror;
				do
				{

					if (!InternetQueryDataAvailable(hRequest, &dwBytesAvailable, 0, 0)) break;

					resulting2 = InternetReadFile(hRequest, (LPVOID) responseText2, 15000, &lpdwNumberOfBytesRead);

					lasterror = GetLastError();


				} while (resulting2 == 0);
				//analysera innehållet
				scanna_oddsen(responseText2);
				antalvarv++;
			}
		}
		 //Odds med 8 mål i H2

		/////// sprintf(sUrlOrgexpekt,"http://www.expekt.com/supertotoProxy/ownodds.htm?coupon=%d&combp=000000010001110000000011110000000111100000001110000000010000000000&filter=000000000&lang=sv", Odds->m_matchid);
		 static TCHAR frmdata3 [] =
			 _T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111100000001111000000000000000100111000000001110000000010000000000\"}}");
		 for (int mb3 = 0; mb3<4; mb3++)
		{
			 if (mb3 > 0)
				 //		sUrlOrgexpekt[121+mb3] = '0';
				 //	sUrlOrgexpekt[122+mb3] = '1';
			 {
				 frmdata3[128 + mb3] = '0';
				 frmdata3[129 + mb3] = '1';
			 }
			//	pFile = m_Session.OpenURL( sUrlOrgexpekt,1,INTERNET_FLAG_DONT_CACHE|INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_ASCII);
				BOOL resulting = HttpSendRequest(hRequest, hdrs, strlen(hdrs), frmdata3, strlen(frmdata3));
				bool resulting3;
				DWORD dwBytesAvailable;
				char* responseText3 = NULL;
				responseText3 = new char[15000];
				DWORD lpdwNumberOfBytesRead = 0;
				DWORD lasterror;
				do
				{

					if (!InternetQueryDataAvailable(hRequest, &dwBytesAvailable, 0, 0)) break;

					resulting3 = InternetReadFile(hRequest, (LPVOID) responseText3, 15000, &lpdwNumberOfBytesRead);

					lasterror = GetLastError();


				} while (resulting3 == 0);
				//analysera innehållet
				scanna_oddsen(responseText3);
				 antalvarv++;
		 }


		 //slut 7 mål i H1

		 //6-8 mål i match 3 för hemmalaget
		 static TCHAR frmdata4 [] =
			 _T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111000000001000000000011110000000111100000000000001000011100000000\"}}");
		 for(int ytterloopen = 0; ytterloopen < 3; ytterloopen++)
		 {
			 
			 if (ytterloopen > 0)
			 {
				 frmdata4[123+ytterloopen] = '0';
				 frmdata4[124+ytterloopen] = '1';
				 frmdata4[88] = '0';
				 frmdata4[85] = '1';
					// _T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111000000001000000000011110000000111100000000000000100011100000000\"}}");
			 }
			 for (int mb3 = 0; mb3 < 4; mb3++)
			 {
				 if (mb3 > 0)

				 {
					 frmdata4[84 + mb3] = '0';
					 frmdata4[85 + mb3] = '1';
				 }
				 //	pFile = m_Session.OpenURL( sUrlOrgexpekt,1,INTERNET_FLAG_DONT_CACHE|INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_ASCII);
				 BOOL resulting = HttpSendRequest(hRequest, hdrs, strlen(hdrs), frmdata4, strlen(frmdata4));
				 bool resulting4;
				 DWORD dwBytesAvailable;
				 char* responseText4 = NULL;
				 responseText4 = new char[15000];
				 DWORD lpdwNumberOfBytesRead = 0;
				 DWORD lasterror;
				 do
				 {

					 if (!InternetQueryDataAvailable(hRequest, &dwBytesAvailable, 0, 0)) break;

					 resulting4 = InternetReadFile(hRequest, (LPVOID) responseText4, 15000, &lpdwNumberOfBytesRead);

					 lasterror = GetLastError();


				 } while (resulting4 == 0);
				 //analysera innehållet
				 scanna_oddsen(responseText4);
				 antalvarv++;
			 }
		 }
		 //slut 6-7 mål för hemmalaget


		 //6-8 mål i match 1 för bortalaget
		 static TCHAR frmdata5 [] =
			 _T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111000000000000001000011110000000111100000001110000000010000000000\"}}");
		 for (int ytterloop4 = 0; ytterloop4 < 3; ytterloop4++)
		 {

			 if (ytterloop4 > 0)
			 {
				 frmdata5[90 + ytterloop4] = '0';
				 frmdata5[91 + ytterloop4] = '1';
				 frmdata5[132] = '0';
				 frmdata5[129] = '1';
				 // _T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111000000001000000000011110000000111100000000000000100011100000000\"}}");
			 }
			 for (int mb3 = 0; mb3 < 4; mb3++)
			 {
				 if (mb3 > 0)

				 {
					 frmdata5[128 + mb3] = '0';
					 frmdata5[129 + mb3] = '1';
				 }
				 //	pFile = m_Session.OpenURL( sUrlOrgexpekt,1,INTERNET_FLAG_DONT_CACHE|INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_ASCII);
				 BOOL resulting = HttpSendRequest(hRequest, hdrs, strlen(hdrs), frmdata5, strlen(frmdata5));
				 bool resulting5;
				 DWORD dwBytesAvailable;
				 char* responseText5 = NULL;
				 responseText5 = new char[15000];
				 DWORD lpdwNumberOfBytesRead = 0;
				 DWORD lasterror;
				 do
				 {

					 if (!InternetQueryDataAvailable(hRequest, &dwBytesAvailable, 0, 0)) break;

					 resulting5 = InternetReadFile(hRequest, (LPVOID) responseText5, 15000, &lpdwNumberOfBytesRead);

					 lasterror = GetLastError();


				 } while (resulting5 == 0);
				 //analysera innehållet
				 scanna_oddsen(responseText5);
				 antalvarv++;
			 }
		 }



		 //6-8 mål i match 2 för bortalaget
		 static TCHAR frmdata6 [] =
			 _T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111100000001111000000011100000000000000100001110000000010000000000\"}}");
		 for (int ytterloop5 = 0; ytterloop5 < 3; ytterloop5++)
		 {

			 if (ytterloop5 > 0)
			 {
				 frmdata6[112 + ytterloop5] = '0';
				 frmdata6[113 + ytterloop5] = '1';
				 frmdata6[132] = '0';
				 frmdata6[129] = '1';
				 // _T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111000000001000000000011110000000111100000000000000100011100000000\"}}");
			 }
			 for (int mb3 = 0; mb3 < 4; mb3++)
			 {
				 if (mb3 > 0)

				 {
					 frmdata6[128 + mb3] = '0';
					 frmdata6[129 + mb3] = '1';
				 }
				 //	pFile = m_Session.OpenURL( sUrlOrgexpekt,1,INTERNET_FLAG_DONT_CACHE|INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_ASCII);
				 BOOL resulting = HttpSendRequest(hRequest, hdrs, strlen(hdrs), frmdata6, strlen(frmdata6));
				 bool resulting6;
				 DWORD dwBytesAvailable;
				 char* responseText6 = NULL;
				 responseText6 = new char[15000];
				 DWORD lpdwNumberOfBytesRead = 0;
				 DWORD lasterror;
				 do
				 {

					 if (!InternetQueryDataAvailable(hRequest, &dwBytesAvailable, 0, 0)) break;

					 resulting6 = InternetReadFile(hRequest, (LPVOID) responseText6, 15000, &lpdwNumberOfBytesRead);

					 lasterror = GetLastError();


				 } while (resulting6 == 0);
				 //analysera innehållet
				 scanna_oddsen(responseText6);
				 antalvarv++;
			 }
		 }



		 //6-8 mål i match 3 för bortalaget
		 static TCHAR frmdata7 [] =
			 _T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111000000001000000000011110000000111100000001110000000000000010000\"}}");
		 for (int ytterloop6 = 0; ytterloop6 < 3; ytterloop6++)
		 {

			 if (ytterloop6 > 0)
			 {
				 frmdata7[134 + ytterloop6] = '0';
				 frmdata7[135 + ytterloop6] = '1';
				 frmdata7[88] = '0';
				 frmdata7[85] = '1';
				 // _T("{\"odds\":{\"@type\":\"bet\",\"reducedPattern\":\"000000000\",\"combinationPattern\":\"111000000001000000000011110000000111100000000000000100011100000000\"}}");
			 }
			 for (int mb3 = 0; mb3 < 4; mb3++)
			 {
				 if (mb3 > 0)

				 {
					 frmdata7[84 + mb3] = '0';
					 frmdata7[85 + mb3] = '1';
				 }
				 //	pFile = m_Session.OpenURL( sUrlOrgexpekt,1,INTERNET_FLAG_DONT_CACHE|INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_ASCII);
				 BOOL resulting = HttpSendRequest(hRequest, hdrs, strlen(hdrs), frmdata7, strlen(frmdata7));
				 bool resulting7;
				 DWORD dwBytesAvailable;
				 char* responseText7 = NULL;
				 responseText7 = new char[15000];
				 DWORD lpdwNumberOfBytesRead = 0;
				 DWORD lasterror;
				 do
				 {

					 if (!InternetQueryDataAvailable(hRequest, &dwBytesAvailable, 0, 0)) break;

					 resulting7 = InternetReadFile(hRequest, (LPVOID) responseText7, 15000, &lpdwNumberOfBytesRead);

					 lasterror = GetLastError();


				 } while (resulting7 == 0);
				 //analysera innehållet
				 scanna_oddsen(responseText7);
				 antalvarv++;
			 }
		 }






	::PostMessage((HWND)param, WM_ODDSFINISHED,0,0);
	return 0;
}

UINT LasNorskaOdds( LPVOID param )
//void COddsLas::Norskinlasning()
{
	CStdioFile *pFile, Logfile;

	char  sUrlOrg[300];
	CInternetSession m_Session;
	float odds;
	char buffer[1100];

     // MessageBox("startar sökning av sidan...");
     //   sprintf(sUrlOrg,"http://www.norsk-tipping.no/wco?event=GETGAMEINFODETAIL&game_id=11&DrawID=257&segmentno=01&frameID=2&eventCount=3");
	 
 // sprintf(sUrlOrg,"https://www.norsk-tipping.no/gar/wco?event=getResultDetails&DrawID=1234&game_id=11&eventCount=3&segmentNo=01&");
 //   sprintf(sUrlOrg,"https://www.norsk-tipping.no/gar/wco?event=GETGAMEINFODETAIL&game_id=11&DrawID=3307&segmentNo=02&target=1&eventCount=3");	    
	sprintf(sUrlOrg,"https://www.norsk-tipping.no/api-oddsbomben/getOddsSummary.json?drawID=12948&segmentID=03&segmentSize=600");
/* int temposida,temposida2;
		temposida = Odds->m_matchid;
		temposida = ((Odds->m_matchid/100)*100);

		temposida2 = Odds->m_matchid - temposida;
		sUrlOrg[66] = (temposida/100)+48;

		temposida = ((temposida2/10)*10);
		sUrlOrg[67] = (temposida/10)+48;
		
		temposida = temposida2 - ((temposida2/10)*10);
		sUrlOrg[68] = (temposida+48);
		*/
	  /*  sprintf( &sUrlOrg[67+12],"%d", Odds->m_matchid); 
		sUrlOrg[71+12] = '&';*/

		sprintf( &sUrlOrg[71],"%d",Odds->m_matchid);
		sUrlOrg[76] = '&';
		int loopindex;
		loopindex = 1;
		
		for(int ytterloopen=loopindex;ytterloopen<=Odds->m_maxsida;ytterloopen++)
		{
			 
		if(ytterloopen<10)
		{
		//	sUrlOrg[105+1+1-12]=(ytterloopen+48);
			sUrlOrg[88]=(ytterloopen+48);
		}
		else
		{
			int th;
			th = ytterloopen - ((ytterloopen/10)*10);
		//	sUrlOrg[104+1+1-12]=((ytterloopen)/10)+48;
		//	sUrlOrg[105+1+1-12] = th+48;
			sUrlOrg[87]=((ytterloopen)/10)+48;
			sUrlOrg[88] = th+48;
		}
		// Tommy Hagberg avkommenterat nedan 2014-09-15
	//	pFile = m_Session.OpenURL(sUrlOrg/*,1,INTERNET_FLAG_DONT_CACHE|INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_ASCII*/);
		// GB changed 04411024
		::Sleep(300);
		pFile = m_Session.OpenURL(sUrlOrg,1,INTERNET_FLAG_DONT_CACHE|INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_ASCII);
//	pFile = m_Session.OpenURL(sUrlOrg,1,INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_PASSIVE);
	
		FILE *str;
	//	CStdioFile *pFile;
		long antal_simu,antal_utfall;
		char list[170];	// GB changed for mem.check  2008-10-11
	//	char list[17000000];
	//	char scantext[15];
		int aa,bb,cc,dd,ee,ff,index;

		//pFile = fopen_s( &str, "permu.txt", "r+" );
	
		char filnamn[12];
		sprintf(filnamn,"test%d.txt",ytterloopen);
	//	URLDownloadToFile( NULL,"https://www.norsk-tipping.no/api-oddsbomben/getOddsSummary.json?drawID=4755&segmentID=1","test1.txt", 0, NULL );
		
	//	URLDownloadToFile( NULL,"https://www.norsk-tipping.no/api-oddsbomben/getOddsSummary.json?drawID=4755&segmentID=2","test2.txt", 0, NULL );
		//Tommy Hagberg kommenterat bort fyra rader 2014-09-15
	//	HRESULT resultat;
     //   do 
     //      resultat=URLDownloadToFile( NULL,sUrlOrg,filnamn, 0, NULL );
     //   while(resultat!=S_OK);






	//	URLDownloadToFile( NULL,sUrlOrg,filnamn, 0, NULL );
//		URLDownloadToFile( NULL,sUrlOrg,"test.txt", 0, NULL );
//		fopen_s( &str, "permu.txt", "r+" );
		//Tommy Hagberg kommenterat bort nedanstående 2014-09-15
	//	str = fopen( filnamn, "r+" );
	//	fread( buffer, sizeof( char ), 1099, str);
	




		//////////////
		//GB 091013 , Dump file
		//int ret = Logfile.Open( "OddsLogg.txt", CFile::modeCreate| CFile::modeWrite | CFile::typeText );
		//while (pFile->ReadString( buffer, 1099 ))
			//Logfile.WriteString( buffer);
		//Logfile.Close();
		//pFile->Close();
		//ret = Logfile.Open( "OddsLogg.txt", CFile::modeRead | CFile::typeText );

		//pFile = &Logfile;
		// End GB change


		// Oddsinläsningfönstret stängt (genom CANCEL) --> Avsluta
		if (!::IsWindowEnabled((HWND)param))
			return 0;
		
		int nypos;
		//  Uppdatera progress-baren i dialogfönstret
		// ::PostMessage((HWND)param, WM_ODDSREAD,ytterloopen,0);

        if (pFile==NULL)
		//if(str==NULL)
				return 0;
		int status;
		status = 0;
		int funnaodds;
		funnaodds = 0;
		int bufferindex;
		bufferindex = 0;
		odds = 0;
		int slut;
		slut = 1;
		
		int tempodds[6][601];
		float tempoddsodds[601];

		for(int gg = 0;gg<=5;gg++)
		{
			for(int hh = 0;hh<=600;hh++)
				tempodds[gg][hh] = 0;
		}
		for(int yy = 0;yy<=600;yy++)
			tempoddsodds[yy] = 0.0;

		int ti1,ti2;
		ti1=0;ti2=1;
		// CStdioFile LoggFile("test.html", CFile::modeCreate | CFile::modeWrite);
		
	//	for(int bbb=0;bbb<10;bbb++)
			pFile->ReadString( buffer, 1099 );
		//fread( buffer, sizeof( char ), 1099, str);
			 //   for(int ccc=0;ccc<100;ccc++)
			//	{
			//		pFile->ReadString( buffer, 999 );
			//		LoggFile.WriteString(buffer);
			//	}
			//	pFile->ReadString( buffer, 199999 );
			//	LoggFile.WriteString(buffer);
			//	LoggFile.Close();
		status = 0;
		do
		{

		/*	 	if(buffer[bufferindex] == 'n' && status ==0)
				status = 1;
			else if(buffer[bufferindex] =='e' && status == 1)
				status = 2;
			else if(buffer[bufferindex] !='e' && status == 1)
				status = 0;
			else if(buffer[bufferindex] =='w' && status == 2)
				status = 3;
			else if(buffer[bufferindex] == ' ' && status == 3)
				status = 4;*/
			if(buffer[bufferindex] == 's' && status == 0)
				status = 5;
			else if(buffer[bufferindex] == 'c' && status == 5)
				status = 6;
			else if(buffer[bufferindex] == 'o' && status == 6)
				status = 7;
			else if(buffer[bufferindex] == 'r' && status == 7)
				status = 8;
			else if(buffer[bufferindex] == 'e' && status == 8)
				status = 9;/**TH nytt*/
			else if(buffer[bufferindex] == 'T' && status == 9)
				status = 10;
			else if(buffer[bufferindex] == 'a' && status == 10)
				status = 11;
			else if(buffer[bufferindex] == 'b' && status == 11)
				status = 12;
			else if(buffer[bufferindex] == 'l' && status == 12)
				status = 13;
			else if(buffer[bufferindex] == 'e' && status == 13)
				status = 14;
			else if(buffer[bufferindex] == '[' && status == 14)
				status = 15;
			else if(buffer[bufferindex] == '[' && status == 15)
				status = 16;
			else if(buffer[bufferindex] == '[' && status == 16)
				status = 28;
//			else if(buffer[bufferindex] == '0' && status == 15)
//				status = 16;
			else if(buffer[bufferindex] == ']' && status == 16)
				status = 28;//nytt TH 20061108
			else if(buffer[bufferindex] == 'y' && status == 17)
				status = 18;
			else if(buffer[bufferindex] == 'n' && status == 18)
				status = 19;
			else if(buffer[bufferindex] == 'e' && status == 19)
				status = 20;
			else if(buffer[bufferindex] == 'w' && status == 20)
				status = 21;
			else if(buffer[bufferindex] == ' ' && status == 21)
				status = 22;
			else if(buffer[bufferindex] == 'A' && status == 22)
				status = 23;
			else if(buffer[bufferindex] == 'r' && status == 23)
				status = 24;
			else if(buffer[bufferindex] == 'r' && status == 24)
				status = 25;
			else if(buffer[bufferindex] == 'a' && status == 25)
				status = 26;
			else if(buffer[bufferindex] == 'y' && status == 26)
				status = 27;
			else if(buffer[bufferindex] == ']' && status == 27)/*th nytt*/
				status = 28;
			else if(buffer[bufferindex] >= '0' && buffer[bufferindex]<= '9' && status == 28)
				odds = 10*odds + (buffer[bufferindex]-48);
			else if(buffer[bufferindex] == ',' && status == 28)
			{
				tempodds[ti1][ti2] = odds;
				ti2++;
				odds = 0;
			}
			else if(buffer[bufferindex] == ']' && status == 28)/*TH nytt*/
			{
				tempodds[ti1][ti2] = odds;
				ti2++;
				odds = 0;
				status = 29;
			}
			else if(buffer[bufferindex] == '[' && status == 29)/*TH nytt*/
			{
				status = 30;
				ti1++;
				ti2 = 1;
				odds = 0;
			}
			else if(buffer[bufferindex] >= '0' && buffer[bufferindex]<= '9' && status == 30)
				odds = 10*odds + (buffer[bufferindex]-48);
			else if(buffer[bufferindex] == ',' && status == 30)
			{
				tempodds[ti1][ti2] = odds;
				ti2++;
				odds = 0;
			}
			else if(buffer[bufferindex] == ']' && status == 30)/*th nytt*/
			{
				tempodds[ti1][ti2] = odds;
				status = 31;
				ti1++;
				ti2 = 1;
				odds = 0;
			}
			else if(buffer[bufferindex] == '[' && status == 31)/*th nytt*/
				status = 33;
			else if(buffer[bufferindex] == ']' && status == 32)/*TH nytt* ScoreTable 1 ska nu läsas*/
				status = 33;

			else if(buffer[bufferindex] >= '0' && buffer[bufferindex]<= '9' && status == 33)
				odds = 10*odds + (buffer[bufferindex]-48);
			else if(buffer[bufferindex] == ',' && status == 33)
			{
				tempodds[ti1][ti2] = odds;
				ti2++;
				odds = 0;
			}
			else if(buffer[bufferindex] == ']' && status == 33)/*th nytt*/
			{
				tempodds[ti1][ti2] = odds;
				status = 34;
			}
			else if(buffer[bufferindex] == '[' && status == 34)/*th nytt*/
			{
				status = 35;
				ti1++;
				ti2 = 1;
				odds = 0;
			}
			else if(buffer[bufferindex] >= '0' && buffer[bufferindex]<= '9' && status == 35)
				odds = 10*odds + (buffer[bufferindex]-48);
			else if(buffer[bufferindex] == ',' && status == 35)
			{
				tempodds[ti1][ti2] = odds;
				ti2++;
				odds = 0;
			}
			else if(buffer[bufferindex] == ']' && status == 35)/*th nytt*/
			{
				tempodds[ti1][ti2] = odds;
				status = 36;
				ti1++;
				ti2 = 1;
				odds = 0;
			}
			else if(buffer[bufferindex] == '[' && (status == 36 && Odds->m_speltyp==7))
				status = 42;
			else if(buffer[bufferindex] == '[' && status == 36)/*th nytt*/
				status = 38;
			else if(buffer[bufferindex] == '=' && status == 37)/*th nytt ScoreTable 3 ska nu läsas*/
				status = 38;

			else if(buffer[bufferindex] >= '0' && buffer[bufferindex]<= '9' && status == 38)
				odds = 10*odds + (buffer[bufferindex]-48);
			else if(buffer[bufferindex] == ',' && status == 38)
			{
				tempodds[ti1][ti2] = odds;
				ti2++;
				odds = 0;
			}
			else if(buffer[bufferindex] == ']' && status == 38)/*th nytt*/
			{
				tempodds[ti1][ti2] = odds;
				status = 39;
			}
			else if(buffer[bufferindex] == '[' && status == 39)/*th nytt*/
			{
				status = 40;
				ti1++;
				ti2 = 1;
				odds = 0;
			}
			else if(buffer[bufferindex] >= '0' && buffer[bufferindex]<= '9' && status == 40)
				odds = 10*odds + (buffer[bufferindex]-48);
			else if(buffer[bufferindex] == ',' && status == 40)
			{
				tempodds[ti1][ti2] = odds;
				ti2++;
				odds = 0;
			}
			else if(buffer[bufferindex] == ']' && status == 40)/*th nytt*/
			{
				tempodds[ti1][ti2] = odds;
				status = 41;
				ti1++;
				ti2 = 1;
				odds = 0;
			}
			else if(buffer[bufferindex] == ':' && status == 41)/*th nytt*/
				status = 42;
			else if(buffer[bufferindex] >= '0' && buffer[bufferindex]<= '9' && status == 42)
				odds = 10*odds + (buffer[bufferindex]-48);
			else if(buffer[bufferindex] == '.' && status == 42)
			{
				tempoddsodds[ti2] = odds;
				status = 43;
			}
			else if(buffer[bufferindex] >= '0' && buffer[bufferindex]<= '9' && status == 43)
			{
				tempoddsodds[ti2] += 0.1*(buffer[bufferindex]-48);
				odds = 0;
				status = 44;
			}
			else if(buffer[bufferindex] >= '0' && buffer[bufferindex]<= '9' && status == 44)
			{
				tempoddsodds[ti2] += 0.01*(buffer[bufferindex]-48);
				odds = 0;
			}
			else if(buffer[bufferindex] == ',' && (status ==44))
			{
				status = 42;
				ti2++;
			}
			else if(buffer[bufferindex] == ']' && status == 44)
				status = 45;
			//	else
				//	status = 0;

		    bufferindex++;
			if(bufferindex == 1099)
			{
				bufferindex = 0;
				pFile->ReadString( buffer, 1099 );
				//Tommy hagberg avkommenterat ovan, kommenterat nedan 2014-09-15
			//	fread( buffer, sizeof( char ), 1099, str);
				int jj=0;
			}
			
						
		}
		while(status<45);

		int jj=0;
		

		for(int xxx=1;xxx<=600;xxx++)
		{
			int h1,b1,h2,b2,h3,b3;

			//**Tommy start 2003-10-10**//
			if(Odds->m_speltyp==6)
			{
				h1=tempodds[0][xxx];
				b1=tempodds[1][xxx];
				h2=tempodds[2][xxx];
				b2=tempodds[3][xxx];
				h3=tempodds[4][xxx];
				b3=tempodds[5][xxx];

				if(h1==0 && b1 == 0 && h2 ==0 && b2 ==0 && h3 ==0 && b3 ==0)
				{
					int a;
					a = 1;
				}

				//***Tommy slut 2003-10-10**//
				if ((tempodds[0][xxx] < 11) && (tempodds[1][xxx] < 11) && (tempodds[2][xxx] < 11) && (tempodds[3][xxx] < 11) &&
					(tempodds[4][xxx] < 11) && (tempodds[5][xxx] < 11) &&
					Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][tempodds[4][xxx]][tempodds[5][xxx]][0][0] != NULL)
				{	

					if(Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][tempodds[4][xxx]][tempodds[5][xxx]][0][0]->NOdds > 0 /* && (Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][tempodds[4][xxx]][tempodds[5][xxx]][0][0]->EjSpelad = false)*/)
					{
						Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][tempodds[4][xxx]][tempodds[5][xxx]][0][0]->kvot = *(Odds->KvotJust) * 
									tempoddsodds[xxx]/Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][tempodds[4][xxx]][tempodds[5][xxx]][0][0]->NOdds;
						Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][tempodds[4][xxx]][tempodds[5][xxx]][0][0]->EjSpelad = false;

						// Räkna upp antal inlästa odds
						if (!Odds->last[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][tempodds[4][xxx]][tempodds[5][xxx]][0][0])
							Odds->NumOdds ++;
						Odds->last[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][tempodds[4][xxx]][tempodds[5][xxx]][0][0] = true;
						
						

					}
				}
				//***Tommy Start 2003-10-10**//
			}
			else if(Odds->m_speltyp==7)
			{
				//**Tommy Slut 2003-10-10**//
				if ((tempodds[0][xxx] < 11) && (tempodds[1][xxx] < 11) && (tempodds[2][xxx] < 11) && (tempodds[3][xxx] < 11) &&
				     Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][0][0][0][0] != NULL)
				{ 
					if(Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][0][0][0][0]->NOdds > 0)
					{
						Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][0][0][0][0]->kvot = *(Odds->KvotJust) * tempoddsodds[xxx]/Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][0][0][0][0]->NOdds;
						Odds->KB[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][0][0][0][0]->EjSpelad = false;
						// Räkna upp antal inlästa odds
						if (!Odds->last[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][0][0][0][0])
							Odds->NumOdds ++;
						Odds->last[tempodds[0][xxx]][tempodds[1][xxx]][tempodds[2][xxx]][tempodds[3][xxx]][0][0][0][0] = true;
					}
				}
				//**Tommy Start 2003-10-10**//
			}
			//**Tommy Slut 2003-10-10**//
		}
		/*	segmentindex.Open( "segmentindex.txt", CFile::modeWrite    , 0 );
		sprintf(buf, "%d\n",DrawIDNo);
		segmentindex.WriteString(buf);
		sprintf(buf, "%d",ytterloopen);
		segmentindex.WriteString(buf);
		segmentindex.Close();
		char tbuffer1[10],tbuffer2[4],tbuffer3[4],tbuffer4[4],tbuffer5[4],tbuffer6[4];
		hemma1.SeekToEnd();
	
		for(int tt = 1; tt<601;tt++)
		{
			sprintf(tbuffer1,"%d\n",tempodds[0][tt]);
			hemma1.WriteString(tbuffer1);
			sprintf(tbuffer1,"%d\n",tempodds[1][tt]);
			hemma1.WriteString(tbuffer1);
			sprintf(tbuffer1,"%d\n",tempodds[2][tt]);
			hemma1.WriteString(tbuffer1);
			sprintf(tbuffer1,"%d\n",tempodds[3][tt]);
			hemma1.WriteString(tbuffer1);
			sprintf(tbuffer1,"%d\n",tempodds[4][tt]);
			hemma1.WriteString(tbuffer1);
			sprintf(tbuffer1,"%d\n",tempodds[5][tt]);
			hemma1.WriteString(tbuffer1);
			sprintf(tbuffer1,"%f\n",tempoddsodds[tt]);
			hemma1.WriteString(tbuffer1);
		
		}*/
		pFile->Close();
		//fclose(str);

		//  Uppdatera progress-baren i dialogfönstret
		::PostMessage((HWND)param, WM_ODDSREAD,ytterloopen,0);
		}
	//	Odds->Save("test.txt");
	// hemma1.Close();
	::PostMessage((HWND)param, WM_ODDSFINISHED,0,0);
	return 0;
}



void COddsLas::NollaOdds()
{
   Odds->NumOdds = 0;	// Nollställ antal inlästa odds
   for(int t1 = 0;t1<MAXRES;t1++)
	 for(int t2 = 0;t2<MAXRES;t2++)
		for(int t3 = 0;t3<MAXRES;t3++)
    		for(int t4 = 0;t4<MAXRES;t4++)
				for(int t5 = 0;t5<MAXRES;t5++)
					for(int t6 = 0;t6<MAXRES;t6++)
						for(int t7 = 0;t7<MAXRES4;t7++)
							for(int t8 = 0;t8<MAXRES4;t8++)
					{
						if (Odds->KB[t1][t2][t3][t4][t5][t6][t7][t8] != NULL)
						{
							Odds->KB[t1][t2][t3][t4][t5][t6][t7][t8]->EjSpelad = true;
							Odds->KB[t1][t2][t3][t4][t5][t6][t7][t8]->kvot=0.0;
							Odds->last[t1][t2][t3][t4][t5][t6][t7][t8] = false;
							
						}
			
					}
}


void scanna_oddsen_sverige_fyra(char responseText2[])
{
	//analysera innehållet
	char buf1[100], buf2[100];


	char str[250];
	int h1 = -1, b1 = -1, h2 = -1, b2 = -1, h3 = -1, b3 = -1, h, b, oint, sret;
	int H1, B1, H2, B2, H3, B3, H4, B4, ickespelad;
	float ofloat, ofloat2, tempoddsodds;
	float Bel1, Bel2, Bel3, BelL, Bel, BelH;
	int antal_odds, status, lasindex;
	antal_odds = 0;
	status = 0;
	lasindex = 0;
	float odds,odds2;
	odds = 0;
	do
	{
		if (responseText2[lasindex] == 'l' && status == 0)
		{
			status = 1;
		}
		else if (responseText2[lasindex] == 'i' && status == 1)
		{
			status = 2;
		}
		else if (responseText2[lasindex] == 's' && status == 2)
		{
			status = 3;
		}
		else if (responseText2[lasindex] == 't' && status == 3)
		{
			status = 4;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 4))
		{
			status = 5;
			H1 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == '-' && status == 5)
		{
			status = 6;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 6))
		{
			status = 7;
			B1 = (responseText2[lasindex] - 48);
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 7))
		{
			status = 8;
			H2 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == '-' && status == 8)
		{
			status = 9;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 9))
		{
			status = 10;
			B2 = (responseText2[lasindex] - 48);
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 10))
		{
			status = 11;
			H3 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == '-' && status == 11)
		{
			status = 12;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 12))
		{
			status = 13;
			B3 = (responseText2[lasindex] - 48);
		}
		////Nytt fyra matcher
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 13))
		{
			status = 14;
			H4 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == '-' && status == 14)
		{
			status = 15;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 15))
		{
			status = 16;
			B4 = (responseText2[lasindex] - 48);
		}
		else if (responseText2[lasindex] == 'o' && status == 16)
		{
			status = 17;
		}

		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 17))
		{
			int temp;
			temp = responseText2[lasindex] - 48;
			odds = 10 * odds + temp;
		}
		else if (responseText2[lasindex] == ',' && status == 17)
		{
			status = 18;
		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 18))
		{

			float de;
			de = (responseText2[lasindex] - 48);
			de = de / 10;
			odds = odds + de;
			status = 19;

		}
		else if ((responseText2[lasindex] >= '0' && (responseText2[lasindex] <= '9') && status == 19))
		{
			float decc;
			decc = (responseText2[lasindex] - 48);
			decc = decc / 100;
			status = 20;
			odds = odds + decc;
		}
		else if (responseText2[lasindex] == 'c' && status > 19)
		{
			int dummy;
			/*if (H1 == 0 && B1 == 0 && H2 == 0 && B2 == 0 && H3 == 2 && B3 == 0 && H4 == 1 && B4 == 1)
			{
				int koll;
				koll = 1;
			}*/
			dummy = 1;
			odds2 = odds;
			int hjalpodds;
			if (Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4] != NULL) {
				hjalpodds = Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4]->NOdds;
			}
			else {
				hjalpodds = Odds->m_maxnomodds;
			}
			if (odds > (Odds->m_minodds) && Odds->m_en_krona_ospelad && hjalpodds < Odds->m_maxnomodds) {
				odds = 0;
			}
		//	if (odds > 0)
			if (odds > 0 && Odds->m_en_krona_ospelad == false)
			{
				if (Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4] != NULL)
				{
					Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4]->kvot = *(Odds->KvotJust) * odds / Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4]->NOdds;
					Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4]->EjSpelad = false;
				}
				/*else
				{
				Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;
				}*/
				// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][H4][B4])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][H4][B4] = true;
			}
			else if (odds2 > Odds->m_minodds && hjalpodds < Odds->m_maxnomodds)
			{
				if (Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4] != NULL)
					Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4]->EjSpelad = true;

				//// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][H4][B4])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][H4][B4] = true;
			}
			else {
				if (Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4] != NULL)
				{
					//	Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->kvot = *(Odds->KvotJust) * odds / Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->NOdds;
					Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4]->kvot = 0.5;
					Odds->KB[H1][B1][H2][B2][H3][B3][H4][B4]->EjSpelad = false;
				}
				/*else
				{
				Odds->KB[H1][B1][H2][B2][H3][B3][0][0]->EjSpelad = true;
				}*/
				// Räkna upp antal inlästa odds
				if (!Odds->last[H1][B1][H2][B2][H3][B3][H4][B4])
					Odds->NumOdds++;
				Odds->last[H1][B1][H2][B2][H3][B3][H4][B4] = true;
			}



			odds = 0;
			status = 4;
		}
		else if (responseText2[lasindex] == 'n' && status > 15)
		{
			status = 33;
		}
		lasindex++;
	} while (status < 33);
}

bool kollanomodds4matcher(int mh1, int mb1, int mh2, int mb2, int mh3, int mb3, int mh4, int mb4) {
	int loop1start, loop1slut, loop2start, loop2slut,loop3start,loop3slut,loop4start,loop4slut;
	bool ska_lasas = false;
	if (mh1 == 0) {
		loop1start = 0;
		loop1slut = 4;
	}
	else {
		loop1start = 5;
		loop1slut = 9;
	}
	if (mb1 == 0) {
		loop2start = 0;
		loop2slut = 4;
	}
	else {
		loop2start = 5;
		loop2slut = 9;
	}
	if (mh2 == 0) {
		loop3start = 0;
		loop3slut = 4;
	}
	else {
		loop3start = 5;
		loop3slut = 9;
	}
	loop4start = 2 * mb2;
	loop4slut = loop4start + 1;
	for (int a = loop1start; a <= loop1slut; a++) {
		for (int b = loop2start; b <= loop2slut; b++) {
			for (int c = loop3start; c <= loop3slut; c++) {
				for (int d = loop4start; d <= loop4slut; d++) {
					float hjalpodds;
					if (Odds->KB[a][b][c][d][mh3][mb3][mh4][mb4] != NULL) {
					//	try {
							hjalpodds = Odds->KB[a][b][c][d][mh3][mb3][mh4][mb4]->NOdds;
					//	}
					//	catch (...) {
					//		int a;
					//		a = 1;
					//	}
					}
					else {
					//	hjalpodds = Odds->m_maxnomodds;
						hjalpodds = Odds->m_minnomodds;
					}
				//	if (hjalpodds < Odds->m_maxnomodds){
					if (hjalpodds < Odds->m_minnomodds){
						ska_lasas = true;
					}
				}
			}
		}
	}
	return ska_lasas;
}

UINT LasDenyaSvenska_fyra(LPVOID param)
{

	char  sUrlOrg[300];
	int antalvarv;
	CInternetSession m_Session;
	CStdioFile *pFile, Logfile;
	int antal_odds;
	float odds;
	int status;
	bool filoppen;
	char buffer[17000];
	antalvarv = 0;
	antal_odds = 0;
	int mal1, mal2, mal3, mal4, mal5, mal6, mal7, mal8, mal9, mal10, mal11, mal12, mal13, mal14, mal15, mal16, mal17, mal18, mal19, mal20, mal21;
	mal1 = 0;
	mal2 = 1;
	mal3 = 2;
	mal4 = 3;
	mal5 = 4;
	mal6 = 0;
	mal7 = 1;
	mal8 = 2;
	mal9 = 3;
	mal10 = 4;
	mal11 = 0;
	mal12 = 1;
	mal13 = 2;
	mal14 = 3;
	mal15 = 4;
	mal16 = 0;
	mal17 = 0;
	mal18 = 0;
	mal19 = 0;
	mal20 = 0;
	mal21 = 0;
	sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/score/bet_oddslist?product=7&drawnum=%d&home1=0,1,2,3,4,5,6,7,8,9&away1=%d,%d,%d,%d,%d&home2=%d,%d,%d,%d,%d&away2=0&home3=0&away3=0", Odds->m_matchid, mal1, mal2, mal3, mal4, mal5, mal6, mal7, mal8, mal9, mal10, mal11, mal12, mal13);
	for (int mh1 = 0; mh1 < 2; mh1++)
	{
		if (mh1 == 1)
		{
			mal1 = 5;
			mal2 = 6;
			mal3 = 7;
			mal4 = 8;
			mal5 = 9;

			mal6 = 0;
			mal7 = 1;
			mal8 = 2;
			mal9 = 3;
			mal10 = 4;

			mal11 = 0;
			mal12 = 1;
			mal13 = 2;
			mal14 = 3;
			mal15 = 4;

			mal16 = 0;
			mal17 = 0;
			mal18 = 0;
			mal19 = 0;
			mal20 = 0;
			mal21 = 0;



		}
		for (int mb1 = 0; mb1 < 2;mb1++)
		{
			if (mb1 == 1)
			{
				mal6 = 5;
				mal7 = 6;
				mal8 = 7;
				mal9 = 8;
				mal10 = 9;

				mal11 = 0;
				mal12 = 1;
				mal13 = 2;
				mal14 = 3;
				mal15 = 4;
				mal16 = 0;
				mal17 = 0;
				mal18 = 0;
				mal19 = 0;
				mal20 = 0;
				mal21 = 0;
			}
			for (int mh2 = 0;mh2 < 2;mh2++)
			{
				if (mh2 == 1)
				{
					mal11 = 5;
					mal12 = 6;
					mal13 = 7;
					mal14 = 8;
					mal15 = 9;
					mal16 = 0;
					mal17 = 0;
					mal18 = 0;
					mal19 = 0;
					mal20 = 0;
					mal21 = 0;
				}
				for (int mb2 = 0;mb2 < 5;mb2++)
				{
					mal16 = mb2 * 2;
					mal17 = mal16 + 1;
					mal18 = 0;
					mal19 = 0;
					mal20 = 0;
					mal21 = 0;
					for (int mh3 = 0;mh3 < 10;mh3++)
					{
						mal18 = mh3;
						/*if (mh3 == 2)
						{
							int k;
							k = 1;
						}*/
						for (int mb3 = 0;mb3 < 10;mb3++)
						{
							if (!(mh3 > 4 && mb3 > 4))
							{
								mal19 = mb3;
								for (int mh4 = 0; mh4 < 10;mh4++)
								{
									mal20 = mh4;
									for (int mb4 = 0; mb4 < 10;mb4++)
									{
										if (!(mh4 > 4 && mb4 > 4))
										{
											mal21 = mb4;
											/*if (mh3 == 2 && mb3 == 0 && mh4 == 1 && mb4 == 1)
											{
												int koll;
												koll = 1;
											}*/
											if(antalvarv == 8191)
											{
												int apa;
												apa = 1;
											}
											filoppen = false;
											if (kollanomodds4matcher(mh1, mb1, mh2, mb2, mh3, mb3, mh4, mb4)) {
												filoppen = true;
												sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/1/score/bet_oddslist?product=7&drawnum=%d&home1=%d,%d,%d,%d,%d&away1=%d,%d,%d,%d,%d&home2=%d,%d,%d,%d,%d&away2=%d,%d&home3=%d&away3=%d&home4=%d&away4=%d", Odds->m_matchid, mal1, mal2, mal3, mal4, mal5, mal6, mal7, mal8, mal9, mal10, mal11, mal12, mal13, mal14, mal15, mal16, mal17, mal18, mal19, mal20, mal21);
												// https://api.spela.svenskaspel.se/draw/1/score/bet_oddslist?product=7&drawnum=13105&home1=0,1&away1=0,1,2&home2=0,1&away2=0,1&home3=10&away3=9,
												//	sprintf(sUrlOrg, "https://api.spela.svenskaspel.se/draw/1/score/bet_oddslist?product=7&drawnum=10889&home1=0,1,2,3,4,5,6,7,8,9&away1=0,1,2,3,4&home2=0,1,2,3,4&away2=0&home3=0&away3=0");
												::Sleep(1);
												pFile = m_Session.OpenURL(sUrlOrg, 1, INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_TRANSFER_ASCII);
												pFile->ReadString(buffer, 16099);
												status = 0;
												scanna_oddsen_sverige_fyra(buffer);
												antalvarv++;
											}
											else {
												antalvarv++;
												Odds->NumOdds += 250;
											}
										}
										if (filoppen == true)
										pFile->Close();
									}
									
								}
								////////////////////////
								
							}
							
						}
						::PostMessage((HWND)param, WM_ODDSREAD, antalvarv / 50000, 0);
						
					}
					

				}
			}
		}
		//	::PostMessage((HWND)param, WM_ODDSREAD, mb1, 0);
	}
	::PostMessage((HWND)param, WM_ODDSFINISHED, 0, 0);
	return 0;
}


void COddsLas::LasnyaSvenskaOdds_fyra()
{
	if (Odds->m_OspeladeForvalt)
		NollaOdds();

	m_progress.SetRange(0, Odds->m_maxsida);
	// Starta trådinläsning
	HWND hwnd = GetSafeHwnd();
	Thread = AfxBeginThread(LasDenyaSvenska_fyra, hwnd);
}






void COddsLas::LasnyaSvenskaOdds()
{
	if (Odds->m_OspeladeForvalt)
		NollaOdds();

	m_progress.SetRange(0, Odds->m_maxsida);
	// Starta trådinläsning
	HWND hwnd = GetSafeHwnd();
	Thread = AfxBeginThread(LasDenyaSvenskaOddsen, hwnd);
}

void COddsLas::LasnyaSvenskaOdds_bandy2m()
{
	if (Odds->m_OspeladeForvalt)
		NollaOdds();

	m_progress.SetRange(0, Odds->m_maxsida);
	// Starta trådinläsning
	HWND hwnd = GetSafeHwnd();
	Thread = AfxBeginThread(LasDenyaSvenskaOddsen_bandy2m, hwnd);
}


void COddsLas::LasnyaSvenskaOdds_is()
{
	if (Odds->m_OspeladeForvalt)
		NollaOdds();

	m_progress.SetRange(0, Odds->m_maxsida);
	// Starta trådinläsning
	HWND hwnd = GetSafeHwnd();
	Thread = AfxBeginThread(LasDenyaSvenskaOddsen_is, hwnd);
}

void COddsLas::LasnyaSvenskaOdds_is_tre()
{
	if (Odds->m_OspeladeForvalt)
		NollaOdds();

	m_progress.SetRange(0, Odds->m_maxsida);
	// Starta trådinläsning
	HWND hwnd = GetSafeHwnd();
	Thread = AfxBeginThread(LasDenyaSvenskaOddsen_is_tre, hwnd);
}

void COddsLas::UnibetInlasning()
{
	if (Odds->m_OspeladeForvalt)
	   NollaOdds();

	m_progress.SetRange( 0, Odds->m_maxsida);
	// Starta trådinläsning
	HWND hwnd = GetSafeHwnd();
	Thread = AfxBeginThread(LasUnibetOdds,hwnd);
	//EndDialog(5);

}

void COddsLas::UnibetInlasningm2()
{
	if (Odds->m_OspeladeForvalt)
	   NollaOdds();

	m_progress.SetRange( 0, Odds->m_maxsida);
	// Starta trådinläsning
	HWND hwnd = GetSafeHwnd();
	Thread = AfxBeginThread(LasUnibetOddsm2,hwnd);
	//EndDialog(5);

}

void COddsLas::Norskinlasning()
{
	if (Odds->m_OspeladeForvalt)
	   NollaOdds();

	m_progress.SetRange( 0, Odds->m_maxsida);
	// Starta trådinläsning
	HWND hwnd = GetSafeHwnd();
	Thread = AfxBeginThread(LasNorskaOdds,hwnd);
	//EndDialog(5);

}
BOOL COddsLas::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// Ändra rubriktext på fönster så att Odds-servrarna kan hitta det
	// (det skall vara möjligt att köra två bomb-program paralellt
	char str[64];
	sprintf(str,"Oddsinläsning ID=%d", Odds->m_matchid);
	SetWindowText(str);


	Thread = NULL;
	m_AntalInlastaOdds = Odds->NumOdds;
	m_MissadeSidor = Odds->MissadeSidor;
	m_upprepa = Odds->m_UpprepaForvalt;
	m_Instanser = Odds->m_Instanser;

	field[0].minsida = &m_minsida1;		field[0].maxsida = &m_maxsida1;		field[0].MissadeSidor = &m_MissadeSidor;
	field[1].minsida = &m_minsida2;		field[1].maxsida = &m_maxsida2;		field[1].MissadeSidor = &m_MissadeSidor2;
	field[2].minsida = &m_minsida3;		field[2].maxsida = &m_maxsida3;		field[2].MissadeSidor = &m_MissadeSidor3;
	field[3].minsida = &m_minsida4;		field[3].maxsida = &m_maxsida4;		field[3].MissadeSidor = &m_MissadeSidor4;
	field[4].minsida = &m_minsida5;		field[4].maxsida = &m_maxsida5;		field[4].MissadeSidor = &m_MissadeSidor5;
	field[5].minsida = &m_minsida6;		field[5].maxsida = &m_maxsida6;		field[5].MissadeSidor = &m_MissadeSidor6;
	field[6].minsida = &m_minsida7;		field[6].maxsida = &m_maxsida7;		field[6].MissadeSidor = &m_MissadeSidor7;
	field[7].minsida = &m_minsida8;		field[7].maxsida = &m_maxsida8;		field[7].MissadeSidor = &m_MissadeSidor8;
	field[8].minsida = &m_minsida9;		field[8].maxsida = &m_maxsida9;		field[8].MissadeSidor = &m_MissadeSidor9;
	field[9].minsida = &m_minsida10;	field[9].maxsida = &m_maxsida10;	field[9].MissadeSidor = &m_MissadeSidor10;

	field[0].AntalOdds = &m_InlastaOdds1;
	field[1].AntalOdds = &m_InlastaOdds2;
	field[2].AntalOdds = &m_InlastaOdds3;
	field[3].AntalOdds = &m_InlastaOdds4;
	field[4].AntalOdds = &m_InlastaOdds5;
	field[5].AntalOdds = &m_InlastaOdds6;
	field[6].AntalOdds = &m_InlastaOdds7;
	field[7].AntalOdds = &m_InlastaOdds8;
	field[8].AntalOdds = &m_InlastaOdds9;
	field[9].AntalOdds = &m_InlastaOdds10;

	UpdateData(false);
	ShowWindow(SW_SHOW);
	RedrawWindow();
	if (Odds->m_speltyp <= 2 || Odds->m_speltyp == 8 || Odds->m_speltyp == 9 || Odds->m_speltyp == 10)
		//Svenskinlasning();
		if (Odds->m_speltyp == 1)
			LasnyaSvenskaOdds_is();
		else if (Odds->m_speltyp == 2)
			LasnyaSvenskaOdds_bandy2m();
		else if(Odds->m_speltyp==8 || Odds->m_speltyp ==9)
			LasnyaSvenskaOdds_is_tre();
		else
		LasnyaSvenskaOdds();
	else if (Odds->m_speltyp == 11)
		LasnyaSvenskaOdds_fyra();
	else if (Odds->m_speltyp == 12)
		UnibetInlasning();
	else if (Odds->m_speltyp == 13 || Odds->m_speltyp == 14)
		UnibetInlasningm2();
	else if  (Odds->m_speltyp >= 6)
		Norskinlasning();

	else
		; //Finskinlasning(0,0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COddsLas::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
	int treadexit = ::TerminateThread(Thread, 0);
}


void COddsLas::OnOK() 
{
	// Don't finnish on <Return>
}

void COddsLas::OnButton1() 
{
	// Create MapFile for odds reading
	TCHAR str1[100], str2[100];
	::GetClassName( GetSafeHwnd(), str1, 100);
	::GetWindowText( GetSafeHwnd(), str2, 100);
	MessageBox(str1, str2);	

	char OddsServStr[64];
	sprintf(OddsServStr,"Oddsinläsning ID=%d", Odds->m_matchid);
	
	hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof( MEMFILETYPE), OddsServStr);
	pMap = (MEMFILETYPE *) MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	pMap->I[0].num = 0;

	// Startup OddsServer Process
	/* STARTUPINFO stInfo;
	PROCESS_INFORMATION prInfo;
	BOOL bResult;
	ZeroMemory( &stInfo, sizeof(stInfo) );
	stInfo.cb = sizeof(stInfo);
	stInfo.dwFlags=STARTF_USESHOWWINDOW;
	stInfo.wShowWindow=SW_MINIMIZE;

	bResult = CreateProcess(NULL,
                         (LPSTR)(LPCSTR)"../OddsServer/Debug/OddsServer.exe",
                         NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &stInfo, &prInfo);
	BOOL res=bResult;
	*/

}
