// Odds.h: interface for the COdds class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODDS_H__770A2E44_BC27_10D5_90D9_0002E30B7832__INCLUDED_)
#define AFX_ODDS_H__770A2E44_BC27_10D5_90D9_0002E30B7832__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "defs.h"
// #include <list>

typedef struct
{
	// Tidigare medlemar

	// Nya medlemar
	small h1,b1,h2,b2,h3,b3,h4,b4;
	float  optins;	// Ber�knad opt. insats
	float  insats;	// Insats (kategori)
	float   spelat;	// Spelat (accumulerat belopp)			
	float kvot;
	float NOdds;	// Nominellt odds
	bool  spelad;	// Av oss
	bool  EjSpelad;	// Av n�gon annan
	bool  LastBfv;	// Igenoml�st vid s�kning efter vid s�kning efter b�sta vinst
	float fv;		// F�rv�ntad vinst med ber�knad insats

} TKombination;


class COdds  
{
public:
	// Gamla medlemmar
	int m_speltyp;
	int antalmissadeinlastaodds;
	int antalInlastaodds;
	int antaluppfangadeodds;
	int antalnoteradeodds;
	int m_matchid;
	int m_minsida, m_maxsida;
	int m_Instanser;
	int m_utvardering;
	int mh1,mb1,mh2,mb2,mh3,mb3,mh4,mb4;
	int m_omsattning;
	int m_maxnomodds, m_minodds;
	bool m_en_krona_ospelad;
	bool m_OspeladeForvalt;
	bool m_UpprepaForvalt;
	bool last[MAXRES][MAXRES][MAXRES][MAXRES][MAXRES][MAXRES][MAXRES4][MAXRES4];
	// Nya medl.
	TKombination	KL[3* 2000000];
	// list <TKombination> KL;
	int	H1maxmal, B1maxmal, H2maxmal, B2maxmal, H3maxmal, B3maxmal, H4maxmal, B4maxmal;

	TKombination	*KB[MAXRES][MAXRES][MAXRES][MAXRES][MAXRES][MAXRES][MAXRES4][MAXRES4];
	int				Num;		// Antal element i KL
	int				NumOdds;	// Antal kombinationer i KL som inneh�ller inl�sta odds
	int				SpelPos;	// Position f�r senast spelad kombination
	int				MissadeSidor;	// Antal missade sidor under en inl�sning	
	// Tillkommande
	UINT  *MatchOdds[3][3];
	float *MinKvot;
	float *MinIns;
	UINT  *Oms;
	UINT  *MaxNomOdds;
	float *AterBet;
	int *OddsOspelActive;
	UINT *OddsOspelade;
	float *KvotJust;

	COdds();
	virtual ~COdds();
	void Init();					// Nollst�ll
	void NollaOdds();

	void NyttOdds(int h1, int b1, int h2, int b2, int h3, int b3,int h4,int b4, float nomodds);

	TKombination	*KBs(int h1, int b1, int h2, int b2, int h3, int b3,int h4, int b4);
	TKombination	**pKBs(int h1, int b1, int h2, int b2, int h3, int b3,int h4, int b4);

	// Allocera minner f�r KB-array
	void AlloceraKB(int H1max, int B1max, int H2max, int B2max, int H3max, int B3max, int H4max, int B4max);
	
	bool Save( const char *name );	// Spara fil
	bool Read( bool ReadHead, const char *name );	// �ppna fil Om par 1 �r false, l�ses endast odds (import)
	bool SparaSomDagfil();			// Sparar till fil med dagens datum: "bombmmdd.txt" - mm=m�nad, dd=dag
	bool SkapaSpel();				// Skapa fil med spelbara bonger
	bool SkapaSvenskSpelFil();
	bool KomplSvenskBong(int kryss, TBONG *B1, TBONG *B2);
	bool SkapaFinskSpelFil();
	bool SkapaNorskSpelFil();
	bool SkapaUnibetSpelFil();
	bool SkapaUnibetSpelFil2(); // Fotboll 2 matcher
	bool KomplFinskBong(int kryss, TBONG *B1, TBONG *B2);
	bool KomplNorskBong(int kryss, TBONG *B1, TBONG *B2);
	bool KomplUnibetBong(int kryss, TBONG *B1, TBONG *B2);
	

	void BerIns1();					// Ber�kna insatser f�r alla kombinationer
	float NyForvVinst(int ins, TKombination *K); // Ber�knar "ny" f�rv�ntad vinst med h�nsyn till tidigare spelad insats
	float BongForvVinst(int ins, TBONG *B);		// Ber�knar samma fast f�r en hel bong

	void SpanKB();					// Skapar KB-struktur (pekare till lista)
	void MarkeraSpelad(TBONG *B);	// Ett-st�ller "spelad"-flagga f�r alla kombinationer
	int AntalKomplement(TBONG *B, bool spelade);	// Returnerar antal resultat med avvikande insats (ant. kompletterade rader)
	void SkrivBong(CStdioFile *f, TBONG *B, int num);	// Skriver en bong p� en rad i spelfilen

	TKombination	*NastaKomb(float ins, int *pos);

	void SkapaBong( TBONG *B, TKombination *K, float ins);	
													// F�rs�ker skapa en bong utifr�n kombination K
													// Om AnnaIns �r satt testas �ven andra insatser

	bool Komp10ins(TBONG *B);						// Kompletterar bong d�r insatsen �r 10 eller mer
	// Kompletterar bong d�r insatsen �r 5
	bool KompIns(TBONG *B, int MinTraff, bool AnnanIns, float minbfv);
	bool Komp3ins(TBONG *B, bool AnnanIns);			// Kompletterar bong d�r insatsen �r 3
	bool Komp1ins(TBONG *B,  int MinRes, bool AnnanIns);	// Kompletterar bong d�r insatsen �r 1
	bool EttKomp(TBONG *B);
	bool KomplBong(int kr, int ins, TBONG *B1, TBONG *B2);	// F�rs�ker skapa kompletterad bong
															// kr:  Kryss H1/0 = pos, Ordning V->H U->N
															// ins:	Alternativ insats
															// B1:	In-bong
															// B2:	Kompletterad bong
	bool ArBastaBong(TBONG *B, TBONG *Bcp, int MinRad, int *MinAntKomp, float *bfv);
	bool EgnaRader(int bombnr);
};


#endif // !defined(AFX_ODDS_H__770A2E44_BC27_10D5_90D9_0002E30B7832__INCLUDED_)
