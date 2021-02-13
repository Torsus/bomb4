// Odds.cpp: implementation of the COdds class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "Odds.h"
#include <cmath>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COdds::COdds()
{
	Init();
}

COdds::~COdds()
{

}
TKombination *COdds::KBs(int h1, int b1, int h2, int b2, int h3, int b3, int h4, int b4)
{
	return KB[h1][b1][h2][b2][h3][b3][h4][b4];
}
TKombination **COdds::pKBs(int h1, int b1, int h2, int b2, int h3, int b3, int h4, int b4)
{
	return &KB[h1][b1][h2][b2][h3][b3][h4][b4];
}

void COdds::Init()
{
	for (int i=0; i<MAXRES; i++)
	  for (int j=0; j<MAXRES; j++)
		for (int k=0; k<MAXRES; k++)
		  for (int l=0; l<MAXRES; l++)
			for (int m=0; m<MAXRES; m++)
			  for (int n=0; n<MAXRES; n++)
				  for(int o=0;o<MAXRES4;o++)
					  for(int p=0;p<MAXRES4;p++)
			  {
				*pKBs(i,j,k,l,m,n,o,p) = NULL;

				// KB[i][j][k][l][m][n][o][p] = NULL;
				last[i][j][k][l][m][n][o][p] = false;
			  }

	for (int i=0;   i<sizeof( KL )/sizeof( KL[0] );    i++)
	{
		
		KL[i].insats = 0;
		KL[i].kvot = 0.0;
		KL[i].NOdds = 0;
		KL[i].spelad = false;		// Av oss
		KL[i].EjSpelad = false;	// Av någon annan
		KL[i].LastBfv = false;
		KL[i].spelat = 0;
	}
	Num = 0;
	NumOdds = 0;
	SpelPos = 0;
	m_speltyp = 0;
	m_utvardering = 0;
}
void COdds::NollaOdds()
{
   NumOdds = 0;	// Nollställ antal inlästa odds
   for(int t1 = 0;t1<MAXRES;t1++)
	 for(int t2 = 0;t2<MAXRES;t2++)
		for(int t3 = 0;t3<MAXRES;t3++)
    		for(int t4 = 0;t4<MAXRES;t4++)
				for(int t5 = 0;t5<MAXRES;t5++)
					for(int t6 = 0;t6<MAXRES;t6++)
						for(int t7 = 0;t7<MAXRES4;t7++)
							for(int t8 = 0;t8<MAXRES4;t8++)
					{
						if (KB[t1][t2][t3][t4][t5][t6][t7][t8] != NULL)
						{
							KB[t1][t2][t3][t4][t5][t6][t7][t8]->EjSpelad = true;
							KB[t1][t2][t3][t4][t5][t6][t7][t8]->kvot=0.0;
							last[t1][t2][t3][t4][t5][t6][t7][t8] = false;
							
						}
			
					}
}

	// Allocera minner för KB-array
void COdds::AlloceraKB(int H1max, int B1max, int H2max, int B2max, int H3max, int B3max, int H4max, int B4max)
{
	H1maxmal = H1max;
	B1maxmal = B1max;
	H2maxmal = H2max;
	B2maxmal = B2max;
	H3maxmal = H3max;
	B3maxmal = B3max;
	H4maxmal = H4max;
	B4maxmal = B4max;
}
void COdds::NyttOdds(int h1, int b1, int h2, int b2, int h3, int b3,int h4, int b4, float nomodds)
{
	KL[Num].NOdds = nomodds;
	KL[Num].h1 = (char) h1;
	KL[Num].b1 = (char) b1;
	KL[Num].h2 = (char) h2;
	KL[Num].b2 = (char) b2;
	KL[Num].h3 = (char) h3;
	KL[Num].b3 = (char) b3;
	KL[Num].h4 = (char) h4;
	KL[Num].b4 = (char) b4;

	*pKBs(h1,b1,h2,b2,h3,b3,h4,b4) =  &KL[ Num++ ];
	
	// KB[h1][b1][h2][b2][h3][b3][h4][b4] =  &KL[ Num++ ];
}

int CompareFinskKomb( const void *k1, const void *k2 )
{
	if (((TKombination *) k1)->optins < ((TKombination *)k2)->optins)
		return -1;
	else if (((TKombination *) k1)->optins > ((TKombination *)k2)->optins)
		return 1;
	else
		return 0;
}

int CompareKomb( const void *k1, const void *k2 )
{
    
   /* Compare all of both strings: */
	if (((TKombination *) k1)->insats < ((TKombination *)k2)->insats)
		return 1;
	else if (((TKombination *)k1)->insats > ((TKombination *)k2)->insats)
		return -1;
	else  // Samma insatskategori --> jämför förväntad vinst
	{

		if (((TKombination *) k1)->insats == 0) 
			return 0;
		else if (((TKombination *) k1)->fv < ((TKombination *) k2)->fv)
			return -1; // UUU 1;
		else if (((TKombination *) k1)->fv > ((TKombination *) k2)->fv)
			return 1; // UUU -1;
		else
			return 0;
	}
}

#define FORVVINST(OMS,I,O,K) (((I) * (*AterBet) * (OMS) / (((*AterBet)  * (OMS) / ((O) * (K))) + (I)))  /  (O)    -   (I))

void COdds::BerIns1()
{
	float Ins;
	// Nollställ spellista

	for (int i=0; i<Num; i++)
	{
		Ins = 0.0;


		if (KL[i].NOdds <= *MaxNomOdds && 
				// Spelad --> Kolla kvotetn
			(( !KL[i].EjSpelad && KL[i].kvot>=*MinKvot)
				// Ospelad --> Kolla mot omsättning
			|| (KL[i].EjSpelad && KL[i].NOdds < *Oms * (*AterBet) / (*MinKvot) * (0.5 /(*MinIns))))
				// Ospelad OCH Odds för ospelade aktiv --> Kolla mot fast odds
			|| (KL[i].EjSpelad && (*OddsOspelActive) && KL[i].NOdds < (*OddsOspelade)) )
		{
			if (KL[i].EjSpelad) // Insatser för ospelade 
			{
				// Finsk insats 
				if (2<m_speltyp && m_speltyp<6)
					Ins =  0.2;

				// Unibet 
				else if (m_speltyp==12 || m_speltyp==13 || m_speltyp==14)
					Ins =  0.1;

				else //resp. Svensk/Norsk insats  på ej spelade
					Ins =  1.0;

				KL[i].kvot = *Oms * (*AterBet) * 0.5  /  KL[i].NOdds;
			}
			else
				Ins = (*AterBet) * 0.5 * (*Oms)/(KL[i].NOdds*KL[i].kvot)*(sqrt(KL[i].kvot)-1);
		}
		else
			Ins = 0.0;

		KL[i].optins = Ins;

		if (Ins < *MinIns)
		{

			KL[i].optins = 0.0;
			KL[i].insats = 0;
		
		}
		// Spel i finland
		else if (2<m_speltyp && m_speltyp<6)  //(m_speltyp > 2 && m_speltyp!=8)
		{
			KL[i].insats = 0.2;
		}
		else {
			if (Ins >= 1.5)
				KL[i].insats = Ins;
			else
				KL[i].insats = 1;
	}
		// KL[i].fv = FORVVINST(*Oms, KL[i].insats, KL[i].NOdds, KL[i].kvot);
		KL[i].fv = FORVVINST(*Oms, KL[i].optins, KL[i].NOdds, KL[i].kvot);

		KL[i].LastBfv = false;		// Nollställ märke för skökning efter förv. vinst
		KL[i].spelat = 0;			// Tilldela 0 till spelat belopp
		KL[i].spelad = false;

	}

	// Sortera efter insatser

	if (2 < m_speltyp && m_speltyp < 6)		// finland
		qsort( (void *)KL, (size_t)Num, sizeof( TKombination ), CompareFinskKomb );

	else					// sverige
		qsort( (void *)KL, (size_t)Num, sizeof( TKombination ), CompareKomb );

	SpanKB();
}

float COdds::NyForvVinst(int ins, TKombination *K)
{
	if (! K->spelad  && ins > K->optins)
		return FORVVINST(*Oms, K->optins, K->NOdds, K->kvot);	
	else
		return FORVVINST(*Oms, (ins + K->spelat), K->NOdds, K->kvot) - FORVVINST(*Oms, K->spelat, K->NOdds, K->kvot);	
}

bool COdds::Save( const char *name )
{
	// Spara omgång till fil
	char buf[250];
	CStdioFile f;
	if (f.Open( name, CFile::modeCreate | CFile::modeWrite, 0 ))
	{
		// Spara matchodds
		sprintf(buf, "MatchOdds %d %d %d %d %d %d %d %d %d %d %d %d\n", 
						*MatchOdds[0][0], *MatchOdds[1][0], *MatchOdds[2][0],
						*MatchOdds[0][1], *MatchOdds[1][1], *MatchOdds[2][1],
						*MatchOdds[0][2], *MatchOdds[1][2], *MatchOdds[2][2],
						*MatchOdds[0][3], *MatchOdds[1][3], *MatchOdds[2][3]);
		f.WriteString(buf);

		// Spara omsättning
		sprintf(buf, "Oms %d\n", *Oms); 
		f.WriteString(buf);
		// Spara minkvot
		sprintf(buf, "MinKvot %f\n", *MinKvot); 
		f.WriteString(buf);
		// Spara mininsats
		sprintf(buf, "MinIns %f\n", *MinIns); 
		f.WriteString(buf);
		// Spara max. nominellt odds
		sprintf(buf, "MaxNomOdds %d\n", *MaxNomOdds); 
		f.WriteString(buf);
		for (int i=0; i<Num; i++)
		{
			TKombination *K;
			K = &KL[i];
			if (K->kvot > 0.0)
			{
				sprintf(buf, "%d-%d %d-%d %d-%d %d-%d\t%12.2f\t%12.6f\t%d\t%6.2f\t%d\n", K->h1, K->b1, K->h2, K->b2, K->h3, 
					         K->b3, K->h4, K->b4, K->NOdds,  K->kvot, (K->EjSpelad) ? 1 : 0, K->optins, K->spelat);
				f.WriteString(buf);
			}
		}
		f.Close();
		return true;
	} else
		return false;
}
bool COdds::SparaSomDagfil()
{
	char name[100];
	CTime theTime = CTime::GetCurrentTime();
	sprintf(name, "Bomb%02d%02d.txt", theTime.GetMonth(), theTime.GetDay());
	return Save( name );
}
bool COdds::Read( bool ReadHead, const char *name )
{
	char buf[250];
	int H1,B1,H2,B2,H3,B3,H4,B4, ejspelad, ins, intodds;
	float odds, kvot;

	if (m_OspeladeForvalt)
	{
		NollaOdds();
		m_OspeladeForvalt = false;
	}
	// Läs spelomgångsfil
	CStdioFile f;
	if (f.Open( name, CFile::modeRead, 0 ))
	{
		if (ReadHead)
		{
			// nollställ
			Init();
			// Läs MatchOdds 
			f.ReadString(buf, 249);
			sscanf(buf, "MatchOdds %d %d %d %d %d %d %d %d %d %d %d %d\n", 
						MatchOdds[0][0], MatchOdds[1][0],MatchOdds[2][0],
						MatchOdds[0][1], MatchOdds[1][1],MatchOdds[2][1],
						MatchOdds[0][2], MatchOdds[1][2],MatchOdds[2][2],
						MatchOdds[0][3], MatchOdds[1][3],MatchOdds[2][3]);


			// Läs omsättning
			f.ReadString(buf, 249);
			sscanf(buf, "Oms %d\n", Oms); 
			// Läs minkvot
			f.ReadString(buf, 249);
			sscanf(buf, "MinKvot %f\n", MinKvot); 
			// Läs mininsats
			f.ReadString(buf, 249);
			sscanf(buf, "MinIns %f\n", MinIns); 
			// Läs max. nominellt odds
			f.ReadString(buf, 249);
			sscanf(buf, "MaxNomOdds %d\n", MaxNomOdds); 
		}		
		
		while (f.ReadString(buf, 249) )
		{
			// Init
			H3 = 0;
			B3 = 0;
			H4 = 0;
			B4 = 0;
			// Enligt gammal modell
			if (sscanf(buf,"%d-%d %d-%d %d-%d %d-%d %f %f %d %d", &H1,&B1,&H2,&B2,&H3,&B3,&H4,&B4,&odds,&kvot,&ejspelad,&ins)==12)
			{
				// Ny kombination --> Skapa ny post i listan KL
				//  if (KB[H1][B1][H2][B2][H3][B3][H4][B4] ==  NULL )
				if (KBs(H1,B1,H2,B2,H3,B3,H4,B4) ==  NULL )
				{
					KL[Num].h1 = (char) H1;
					KL[Num].b1 = (char) B1;
					KL[Num].h2 = (char) H2;
					KL[Num].b2 = (char) B2;
					KL[Num].h3 = (char) H3;
					KL[Num].b3 = (char) B3;
					KL[Num].h4 = (char) H4;
					KL[Num].b4 = (char) B4;
					KL[Num].kvot  = kvot;
					KL[Num].NOdds = odds;
					KL[Num].EjSpelad = (ejspelad==1);
				//	KL[Num].insats = ins;  //TBR
					KL[Num].fv = KL[Num].insats * (KL[Num].kvot - 1.0);
					// KB[H1][B1][H2][B2][H3][B3] = &KL[ Num ];
					Num++;
				}
				// kombination finns redan --> Modifiera
				else if (kvot > 0.0)
				{
					TKombination *K;
					// K = KB[H1][B1][H2][B2][H3][B3][H4][B4];
					K = KBs(H1,B1,H2,B2,H3,B3,H4,B4);

					K->kvot  = kvot;
					K->NOdds = odds;
					K->EjSpelad = (ejspelad==1);
					K->insats = ins;  //TBR
					K->fv = KL[Num].insats * (KL[Num].kvot - 1.0);

				}
				// Markera odds som inläst
				if (kvot > 0.0 && !last[H1][B1][H2][B2][H3][B3][H3][B3])
					NumOdds ++;
				last[H1][B1][H2][B2][H3][B3][H3][B3] = true;

			}
			// Oddsfil hämtad från Svenska spel -->
			// Ex: 141624900;4,2,0,0,2,2,0,2
			else if (sscanf(buf,"%d;%d,%d,%d,%d,%d,%d,%d,%d,%d",&intodds, &H1,&B1,&H2,&B2,&H3,&B3,&H4,&B4)>4)
			{
					if (MAXRESOK(H1,B1,H2,B2,H3,B3,H4,B4) && KBs(H1,B1,H2,B2,H3,B3,H4,B4) != NULL)
					{
						if(KBs(H1,B1,H2,B2,H3,B3,H4,B4)->NOdds > 0)
						{
							float fodds = intodds/100.0; 
							KBs(H1,B1,H2,B2,H3,B3,H4,B4)->kvot = (*KvotJust) * fodds / KBs(H1,B1,H2,B2,H3,B3,H4,B4)->NOdds;
							KBs(H1,B1,H2,B2,H3,B3,H4,B4)->EjSpelad = false;					
						}
						else  // Ej med i tabell
							KBs(H1,B1,H2,B2,H3,B3,H4,B4)->kvot= 0.0;

						// Uppdatera antal inlästa odds
						if (!last[H1][B1][H2][B2][H3][B3][H4][B4])
							NumOdds ++;
						last[H1][B1][H2][B2][H3][B3][H4][B4] = true;

					}

			}
		}
		f.Close();
		SpanKB();

		return true;
	}
	return false;
}
// Skapar KB  / pekare till lista
void COdds::SpanKB()
{
	for (int i=0; i<MAXRES; i++)
	  for (int j=0; j<MAXRES; j++)
		for (int k=0; k<MAXRES; k++)
		  for (int l=0; l<MAXRES; l++)
			for (int m=0; m<MAXRES; m++)
			  for (int n=0; n<MAXRES; n++)
				  for(int o=0;o<MAXRES4; o++)
					  for(int p=0;p<MAXRES4; p++)
				
				*pKBs(i,j,k,l,m,n,o,p) = NULL;
				// KB[i][j][k][l][m][n][o][p] = NULL;

	for (int i=0; i<Num; i++)
	{
		if (KL[i].h1==2 && KL[i].b1==1 && KL[i].h2==1 && KL[i].b2==3 &&
			KL[i].h3==1 && KL[i].b3==1 && KL[i].h4==1 && KL[i].b4==0)

				int kk=0;

		*pKBs( KL[i].h1, KL[i].b1, KL[i].h2 ,KL[i].b2, KL[i].h3, KL[i].b3, KL[i].h4, KL[i].b4 ) = &KL[i];

		//KB[ KL[i].h1 ][ KL[i].b1 ][ KL[i].h2 ][ KL[i].b2 ][ KL[i].h3 ][ KL[i].b3 ][ KL[i].h4 ][ KL[i].b4 ] = &KL[i];
	}
	int kk=0;
}
void COdds::MarkeraSpelad(TBONG *B)
{
	for (int i=0; i<B->h1index; i++)
	  for (int j=0; j<B->b1index; j++)
		for (int k=0; k<B->h2index; k++)
		  for (int l=0; l<B->b2index; l++)
			for (int m=0; m<B->h3index; m++)
			  for (int n=0; n<B->b3index; n++)
				  for(int o=0; o<B->h4index; o++)
					  for(int p=0; p<B->b4index; p++)
			  {
					TKombination *K = KB	[ B->h1list[i] ] [ B->b1list[j] ] [ B->h2list[k] ]	
											[ B->b2list[l] ] [ B->h3list[m] ] [ B->b3list[n] ]
											[ B->h4list[o] ] [ B->b4list[p] ];
					K->spelat += B->insats;
					K->spelad =  true;

			  }
}
// Returnerar antal resultat med avvikande insats, eller som redan har spelats (då "spelade" er satt)
int COdds::AntalKomplement(TBONG *B, bool spelade)
{
	int ant = 0;
	for (int i=0; i<B->h1index; i++)
	  for (int j=0; j<B->b1index; j++)
		for (int k=0; k<B->h2index; k++)
		  for (int l=0; l<B->b2index; l++)
			for (int m=0; m<B->h3index; m++)
			  for (int n=0; n<B->b3index; n++)
				  for(int o=0; o<B->h4index; o++)
					  for(int p=0;p<B->b4index; p++)
			  {
					TKombination *K = KB	[ B->h1list[i] ] [ B->b1list[j] ] [ B->h2list[k] ]	
											[ B->b2list[l] ] [ B->h3list[m] ] [ B->b3list[n] ]
											[ B->h4list[o] ] [ B->b4list[p] ];
					//if  ((K->spelad && spelade) || K->insats != B->insats)
					if ((K->spelad && spelade) || K->insats == 0) // Test only
						ant++;
			  }
	return ant;
}
float COdds::BongForvVinst(int ins, TBONG *B)
{
	TKombination *K;
	float fvsum = 0.0;

	for (int i=0; i<B->h1index; i++)
	  for (int j=0; j<B->b1index; j++)
		for (int k=0; k<B->h2index; k++)
		  for (int l=0; l<B->b2index; l++)
			for (int m=0; m<B->h3index; m++)
			  for (int n=0; n<B->b3index; n++)
				  for(int o=0; o<B->h4index; o++)
					  for(int p=0; p<B->b4index; p++)
			  {
				K = KB	[ B->h1list[i] ] [ B->b1list[j] ] [ B->h2list[k] ]	
						[ B->b2list[l] ] [ B->h3list[m] ] [ B->b3list[n] ]
						[ B->h4list[o] ] [ B->b4list[p] ];
				float fv = NyForvVinst(ins, K );
				fvsum += fv;
			  }
	return fvsum;
}
void COdds::SkrivBong(CStdioFile *f, TBONG *B, int num)  // num = ordningsnummer
{
	char buf[250];
	int ant =  B->h1index*B->b1index*B->h2index*B->b2index*B->h3index*B->b3index;

	if (2<m_speltyp && m_speltyp<6 || m_speltyp==12 || m_speltyp==13 || m_speltyp==14)  // Finland och Unibet
		sprintf(buf, "B%04d O: %2dx%3.1f\t", num, ant, B->insats);
	else				// Sverige 
		sprintf(buf, "B%04d O: %2dx%2d\t", num, ant, (int) B->insats);
	f->WriteString(buf);

	// f->WriteString(buf);
	for(int b = 0;b<B->h1index;b++)
	{
		if(b==0)
			sprintf(buf, (B->h1list[b]==10) ? "F" :"%d", B->h1list[b]);
		else
			sprintf(buf,(B->h1list[b]==10) ? ",F" :",%d",B->h1list[b]);
		f->WriteString(buf);
	}
	for (int b=B->h1index; b<5; b++)
		f->WriteString("  ");

	sprintf(buf,"- ");
	f->WriteString(buf);
	for(int b = 0;b<B->b1index;b++)
	{
		if(b==0)
			sprintf(buf, (B->b1list[b]==10) ? "F" :"%d",B->b1list[b]);
		else
		sprintf(buf, (B->b1list[b]==10) ? ",F" : ",%d",B->b1list[b]);
		f->WriteString(buf);
	}
	for (int b=B->b1index; b<5; b++)
		f->WriteString("  ");
	sprintf(buf,"\t");
	f->WriteString(buf);
	for(int b = 0;b<B->h2index;b++)
	{
		if(b==0)
			sprintf(buf,(B->h2list[b]==10) ? "F" : "%d",B->h2list[b]);
		else
			sprintf(buf, (B->h2list[b]==10) ? ",F" : ",%d",B->h2list[b]);
		f->WriteString(buf);
	}
	for (int b=B->h2index; b<5; b++)
		f->WriteString("  ");
	sprintf(buf,"- ");
	f->WriteString(buf);
	for(int b = 0;b<B->b2index;b++)
	{
		if(b==0)
			sprintf(buf, (B->b2list[b]==10) ? "F" : "%d",B->b2list[b]);
		else
			sprintf(buf, (B->b2list[b]==10) ? ",F" : ",%d",B->b2list[b]);
		f->WriteString(buf);
	}
	for (int b=B->b2index; b<5; b++)
		f->WriteString("  ");
	sprintf(buf,"\t");
	f->WriteString(buf);
	for(int b = 0;b<B->h3index;b++)
	{
		if(b==0)
			sprintf(buf,"%d",B->h3list[b]);
		else
			sprintf(buf,",%d",B->h3list[b]);
		f->WriteString(buf);
	}
	for (int b=B->h3index; b<5; b++)
		f->WriteString("  ");
	sprintf(buf,"- ");
	f->WriteString(buf);
	for(int b = 0;b<B->b3index;b++)
	{
		if(b==0)
			sprintf(buf,"%d",B->b3list[b]);
		else
			sprintf(buf,",%d",B->b3list[b]);
			f->WriteString(buf);
	}
	int AntKomp = AntalKomplement(B, false);
	if (AntKomp > 0)	// Skriv ut antal komplement
	{
		sprintf(buf, "\t#%d", AntKomp);
		f->WriteString(buf);
	}
	f->WriteString("\n");

}
// Skapa spelfil
bool COdds::SkapaSpel()
{
	if (m_speltyp < 3 || m_speltyp==8  || m_speltyp==9 || m_speltyp==10 || m_speltyp==11)
		return SkapaSvenskSpelFil();
	else if (m_speltyp < 6)
	    return SkapaFinskSpelFil();
	else if (m_speltyp==12 || m_speltyp==13)
	    return SkapaUnibetSpelFil();
	else if (m_speltyp==14)
	    return SkapaUnibetSpelFil2();
	else 
	    return SkapaNorskSpelFil();
}

bool COdds::SkapaSvenskSpelFil()
{
	char buf[250];

	CStdioFile f;

	BerIns1();	// Beräkna insatser och sortra

	if (f.Open( "spelfil.txt", CFile::modeWrite | CFile::modeCreate   , 0 ))
	{
		TBONG Bong;
		int	AntalKomb = 0;
		int	AntalBonger = 0;
		float TotIns02 = 0;
		float TotIns10 = 0;
		float TotIns1;

		SpelPos = 0;

		
		while (SpelPos < Num)
		{
			float ins;
			TBONG BK1; // Kompletterande bonger

            ins = KL[SpelPos].optins - KL[SpelPos].spelat;
			
			// ins = 0.2 * floor( ins * 5.0 + 0.5);

			   ins = floor( (ins * 10.0 + 5.0)/10.0);

			if (ins >= 1.0)
			{
				SkapaBong(&Bong, &KL[SpelPos], ins);
/* GB 2008-02.09
				for (int k1=0; k1<60; k1++)
				// for (int k1=59; k1>0; k1--)
				{
					if (KomplSvenskBong(k1, &Bong, &BK1))	
						memcpy(&Bong, &BK1, sizeof( TBONG ));
				}
*/
				// Markera alla kombinationer som spelade
				MarkeraSpelad(&Bong);
				SkrivBong(&f, &Bong, AntalBonger);
				AntalBonger ++;
				AntalKomb += ANTALRES(Bong);
				TotIns02 += ANTALRES(Bong) * Bong.insats;
			}
			SpelPos++;
			
		}

	// Skriv ut ej spelade kombinationer
		int AntalMissade = 0;
		int AntalSpelbara = 0;
		for (int i=0; i<Num; i++)
			if (KL[i].insats>0)
			{
				AntalSpelbara ++;
				if (!KL[i].spelad)
				{
					sprintf(buf, "%2d-%2d\t%2d-%2d\t%2d-%2d\t%.2f\t%2.1f\n", 
						KL[i].h1, KL[i].b1, KL[i].h2, KL[i].b2, KL[i].h3, KL[i].b3, KL[i].kvot, KL[i].optins);
					f.WriteString(buf);
					AntalMissade ++;
				}
			}

		
		sprintf(buf,"Totalt antal spelad rader %d. Missade %d av %d.\n", AntalKomb, AntalMissade, AntalSpelbara);
		f.WriteString(buf);
		sprintf(buf,"Insatser -\t enkronorsrader: %.1f kr\t1 övriga %.1f E\t Totalt: %.1f kr\n", TotIns02, TotIns10, TotIns02+TotIns10);
		f.WriteString(buf);
		sprintf(buf,"Antal bonger: %d\n", AntalBonger);
		f.WriteString(buf);
		f.Close();

		return true;
	}
	return false;


}
// kryss  0-60 anger position för det "nya" krysset enligt
//	H1	B1	H2	B2	H3	B3
//	H1	B1	H2	B2	H3	B3
//	0	1	2	3	4	5	
//	0	1	2	3	4	5	
//	6	7	8	9	10	11
//	.	.	.	.	.	.
//	60	61	62	63	64	65
bool COdds::KomplSvenskBong(int kryss, TBONG *B1, TBONG *B2)
{
	int	*idx=NULL, *l=NULL; // Index / lista

	// Kopera bong
	memcpy(B2, B1, sizeof( TBONG ));
	if (kryss==-1) return true;
	// Välj lista
	switch (kryss % 6) {
		case 0: idx = &B2->h1index; l = B2->h1list; break;
		case 1: idx = &B2->b1index; l = B2->b1list; break;
		case 2: idx = &B2->h2index; l = B2->h2list; break;
		case 3: idx = &B2->b2index; l = B2->b2list; break;
		case 4: idx = &B2->h3index; l = B2->h3list; break;
		case 5: idx = &B2->b3index; l = B2->b3list; break;
	}
	// Redan kryssad --> Avsluta
	for (int i = 0; i < *idx; i++)
			if ((kryss/6) == l[i])
				return false; 

	// Komplettera bong med kryss
	l[ *idx ]  = (kryss / 6);
	*idx = (*idx) + 1;

	// Test ifall bongen är giltig
	for (int i = 0; i<B2->h1index; i++)
	  for (int j = 0; j < B2->b1index; j++)
		for (int k = 0; k < B2->h2index; k++)
		  for (int l = 0; l < B2->b2index; l++)
			for (int m = 0; m < B2->h3index; m++)
			  for (int n = 0; n < B2->b3index; n++)
			  {
					if (!MAXRESOK(B2->h1list[i], B2->b1list[j], B2->h2list[k], B2->b2list[l], B2->h3list[m],
								  B2->b3list[n], 0, 0))
								
								  return false;
						
					TKombination *K = KB	[ B2->h1list[i] ] [ B2->b1list[j] ] [ B2->h2list[k] ]	
											[ B2->b2list[l] ] [ B2->h3list[m] ]	[ B2->b3list[n] ] [0][0];

					if (K == NULL)
						return false;

					else if (K->optins - K->spelat < B1->insats - 0.5) 
							return false;
			  }
	return true;
}


TKombination *COdds::NastaKomb(float ins, int *pos)
{
	for (int i=	*pos; i<Num; i++)
	{
		// if ((KL[i].insats == ins || (ins==10 && KL[i].insats > 10))  // org
		if (!KL[i].LastBfv && KL[i].insats == ins && 
								(!KL[i].spelad
							||  (ins==5 && KL[i].optins - KL[i].spelat >= 5.0)
							) 
			)
		{
			*pos = i+1;
			return &KL[i];	
		}
		if (ins == 5  &&  KL[i].optins >= 5.0)
			int jj = 0;
	}
	return NULL;		// NULL vid ingen träff
}

bool COdds::KomplBong(int kr, int ins, TBONG *B1, TBONG *B2)
{
	int	*idx=NULL, *l=NULL; // Index / lista

	// Kopera bong
	memcpy(B2, B1, sizeof( TBONG ));
	if (kr==-1) return true;
	switch (kr % 6) {
		case 0: idx = &B2->h1index; l = B2->h1list; break;
		case 1: idx = &B2->b1index; l = B2->b1list; break;
		case 2: idx = &B2->h2index; l = B2->h2list; break;
		case 3: idx = &B2->b2index; l = B2->b2list; break;
		case 4: idx = &B2->h3index; l = B2->h3list; break;
		case 5: idx = &B2->b3index; l = B2->b3list; break;
	}
	for (int i = 0; i < *idx; i++)
			if ((kr/6) == l[i])
				return false; // Redan kryssad --> Avsluta

	// Komplettera bong med kryss
	l[ *idx ]  = (kr / 6);
	*idx = (*idx) + 1;
	// Test ifall bongen är giltig
	for (int i = (kr==0)?kr/6:0; i<B2->h1index; i++)
 	  for (int j = (kr==1)?kr/6:0; j<B2->b1index; j++)
		for (int k = (kr==2)?kr/6:0; k<B2->h2index; k++)
		  for (int l = (kr==3)?kr/6:0; l<B2->b2index; l++)
			for (int m = (kr==4)?kr/6:0; m<B2->h3index; m++)
			  for (int n = (kr==5)?kr/6:0; n<B2->b3index; n++)
			  {
						
					TKombination *K = KB	[ B2->h1list[i] ] [ B2->b1list[j] ] [ B2->h2list[k] ]	
											[ B2->b2list[l] ] [ B2->h3list[m] ]	[ B2->b3list[n] ] [0][0];
					if (K == NULL)
						return false;
					else if (ins == -1)
						;
					// else if (K->spelad || (K->insats != B1->insats && (K->insats != ins || ins == 0)))
					//else if (K->spelad || (K->insats == 0)) // Test only 1
					else if ((K->insats == 0) || (K->optins- K->spelat< 0)) // Test only 2
						return false;
			  }
	return true;
}

void COdds::SkapaBong( TBONG *B, TKombination *K, float ins)	
{
	B->h1index = 1;			B->b1index = 1;			B->h2index = 1;
	B->b2index = 1;			B->h3index = 1;			B->b3index = 1;
	B->h4index = 1;			B->b4index = 1;

	B->h1list[0] = K->h1;	B->b1list[0] = K->b1;	B->h2list[0] = K->h2;
	B->b2list[0] = K->b2;	B->h3list[0] = K->h3;	B->b3list[0] = K->b3;
	B->h4list[0] = K->h4;	B->b4list[0] = K->b4;

	B->insats = ins;

}


bool COdds::SkapaFinskSpelFil()
{
	char buf[250];

	CStdioFile f;

	BerIns1();	// Beräkna insatser och sortra

	if (f.Open( "spelfil.txt", CFile::modeWrite | CFile::modeCreate   , 0 ))
	{
		TKombination *K;
		TBONG Bong;
		int	AntalKomb = 0;
		int	AntalBonger = 0;
		float TotIns02 = 0;
		float TotIns10 = 0;
		float TotIns1;

		SpelPos = 0;

		
		while (SpelPos < Num)
		{
			float ins, ins1;
			TBONG BK1; // Kompletterande bonger

            ins1 = KL[SpelPos].optins - KL[SpelPos].spelat;
			
			// ins = 0.2 * floor( ins * 5.0 + 0.5);

			ins = 0.1 * floor( ins1 * 10.0 + 0.5);
			
			if (0.0<ins && ins<=0.2)
				ins = 0.2;

			if (ins >= 0.2)
			{
				SkapaBong(&Bong, &KL[SpelPos], ins);
				for (int k1=0; k1<60; k1++)
				{
					if (KomplFinskBong(k1, &Bong, &BK1))	
						memcpy(&Bong, &BK1, sizeof( TBONG ));
				}

				// Markera alla kombinationer som spelade
				MarkeraSpelad(&Bong);
				SkrivBong(&f, &Bong, AntalBonger);
				AntalBonger ++;
				AntalKomb += ANTALRES(Bong);
				TotIns02 += ANTALRES(Bong) * Bong.insats;
			}
			SpelPos++;
			
		}

	// Skriv ut ej spelade kombinationer
		int AntalMissade = 0;
		int AntalSpelbara = 0;
		for (int i=0; i<Num; i++)
			if (KL[i].insats>0)
			{
				AntalSpelbara ++;
				if (!KL[i].spelad)
				{
					sprintf(buf, "%2d-%2d\t%2d-%2d\t%2d-%2d\t%.2f\t%2.1f\n", 
						KL[i].h1, KL[i].b1, KL[i].h2, KL[i].b2, KL[i].h3, KL[i].b3, KL[i].kvot, KL[i].optins);
					f.WriteString(buf);
					AntalMissade ++;
				}
			}

		
		sprintf(buf,"Totalt antal spelad rader %d. Missade %d av %d.\n", AntalKomb, AntalMissade, AntalSpelbara);
		f.WriteString(buf);
		sprintf(buf,"Insatser -\t 0.2 Euros-rader: %.1f E\t1 Euros-rader %.1f E\t Totalt: %.1f E.\n", TotIns02, TotIns10, TotIns02+TotIns10);
		f.WriteString(buf);
		sprintf(buf,"Antal bonger: %d\n", AntalBonger);
		f.WriteString(buf);
		f.Close();

		return true;
	}
	return false;

}
bool COdds::KomplFinskBong(int kryss, TBONG *B1, TBONG *B2)
{
	int	*idx=NULL, *l=NULL; // Index / lista

	// Kopera bong
	memcpy(B2, B1, sizeof( TBONG ));
	if (kryss==-1) return true;
	switch (kryss % 6) {
		case 0: idx = &B2->h1index; l = B2->h1list; break;
		case 1: idx = &B2->b1index; l = B2->b1list; break;
		case 2: idx = &B2->h2index; l = B2->h2list; break;
		case 3: idx = &B2->b2index; l = B2->b2list; break;
		case 4: idx = &B2->h3index; l = B2->h3list; break;
		case 5: idx = &B2->b3index; l = B2->b3list; break;
	}
	for (int i = 0; i < *idx; i++)
			if ((kryss/6) == l[i])
				return false; // Redan kryssad --> Avsluta

	// Komplettera bong med kryss
	l[ *idx ]  = (kryss / 6);
	*idx = (*idx) + 1;

	// Test ifall bongen är giltig
	for (int i = 0; i<B2->h1index; i++)

 	  for (int j = 0; j<B2->b1index; j++)

		for (int k = 0; k<B2->h2index; k++)

		  for (int l = 0; l<B2->b2index; l++)

			for (int m = 0; m<B2->h3index; m++)

			  for (int n = 0; n<B2->b3index; n++)
			  {
						
					TKombination *K = KB	[ B2->h1list[i] ] [ B2->b1list[j] ] [ B2->h2list[k] ]	
											[ B2->b2list[l] ] [ B2->h3list[m] ]	[ B2->b3list[n] ] [0][0];

					if (K == NULL)
						return false;

					// else if (K->optins - K->spelat < B1->insats - 0.1) 

					else 
					{
						
						float rest = K->optins - K->spelat - B1->insats;

						if (((0.15<K->optins) && (rest<0.2)) || (rest < -0.15))    // 0.2 eller mer kvar
							
						return false;
					}
			  }
	return true;
}

bool COdds::EgnaRader(int bombnr)
{
	char buf[250], name[100];
	int		fileidx = 1,		// Fil-index file11, fil2 osv
			row = 20000;		// Dummy init for new opening of new file
	bool	FirstFile = true;
	
	CStdioFile f;
	CStdioFile g;
	CStdioFile g2;
	CStdioFile g3;
	CStdioFile g4;
	CStdioFile g5;

  	  for (int i=0; i<MAXRES; i++)
		for (int j=0; j<MAXRES; j++)
		  for (int k=0; k<MAXRES; k++)
			for( int l=0;l<MAXRES;l++)
			  for(int m=0;m<MAXRES;m++)
				for(int n=0;n<MAXRES;n++)
					for(int o=0;o<MAXRES4;o++)
						for(int p=0;p<MAXRES4;p++)

			if (KBs(i,j,k,l,m,n,o,p) !=NULL)			
			{
				int ins,ins2;
				//Tommy nytt 20121223
				if(m_speltyp ==12 || m_speltyp ==13 || m_speltyp ==14)
				{
					ins = floor((KBs(i,j,k,l,m,n,o,p)->spelat*100.0 + 5.0) / 10.0);
					ins2 = ins;
				}
				else 
					//Tommy slut 20121223
					ins = floor((KBs(i,j,k,l,m,n,o,p)->spelat*10.0 + 5.0) / 10.0);
				
				for (int nRad=0; nRad<ins ; nRad++)
				{
					//  Open new file
					if (row >= 20000)
					{	
						if (!FirstFile)
						{
							f.Flush();
							f.Close();
						}
						FirstFile = false;

						//Filnamn
						CTime theTime = CTime::GetCurrentTime();
						sprintf(name, "Egnarader nr %d fil %d Datum %d-%02d-%02d.txt", bombnr, fileidx++,
							theTime.GetYear(), theTime.GetMonth(), theTime.GetDay());

						f.Open( name, CFile::modeWrite | CFile::modeCreate   , 0 );
		
						// Skriv flihuvud
						//Tommy nytt 20121223
						if(m_speltyp == 12 || m_speltyp == 13 || m_speltyp == 14)
						{
							g.Open( "systemfil_1.txt", CFile::modeWrite | CFile::modeCreate   , 0 );
							g2.Open( "systemfil_2.txt", CFile::modeWrite | CFile::modeCreate   , 0 );
							g3.Open( "systemfil_4.txt", CFile::modeWrite | CFile::modeCreate   , 0 );
							g4.Open( "systemfil_8.txt", CFile::modeWrite | CFile::modeCreate   , 0 );
							g5.Open( "systemfil_16.txt", CFile::modeWrite | CFile::modeCreate   , 0 );
						}
						if(m_speltyp != 12 && m_speltyp !=13 && m_speltyp !=14){
							sprintf(buf,"Bomben,Bombennummer=%d,Insats=1 \n", bombnr);
						f.WriteString(buf);}
						//Tommy slut 20121223
						row = 0;
					}
						
					
					char    h1 = (i==10) ? 'F' : '0'+i,
							b1 = (j==10) ? 'F' : '0'+j,
							h2 = (k==10) ? 'F' : '0'+k,
							b2 = (l==10) ? 'F' : '0'+l,
							h3 = (m==10) ? 'F' : '0'+m,
							b3 = (n==10) ? 'F' : '0'+n,
							h4 = (m==10) ? 'F' : '0'+o,
							b4 = (n==10) ? 'F' : '0'+p;

					// Fotboll eller hockey/bandy med 3 matcher eller hockey med 3 perioder  -->
					if (m_speltyp == 0 || m_speltyp == 8 || m_speltyp == 9 || m_speltyp == 10)  
						sprintf(buf,"E,%c-%c,%c-%c,%c-%c\n", h1, b1, h2, b2, h3, b3);

					// Fotboll eller hockey/bandy med 3 matcher eller hockey med 3 perioder  -->
					else if (m_speltyp == 11)  
						sprintf(buf,"E,%c-%c,%c-%c,%c-%c,%c-%c\n", h1, b1, h2, b2, h3, b3, h4, b4);
					//Fotboll Unibet 3 matcher
					else if (m_speltyp == 12)
					{
						sprintf(buf,"%c,%c,%c,%c,%c,%c\n", h1, b1, h2, b2, h3, b3);
						if(ins2 >0)
						{
							char buf2[250];
							if(ins2>15)
							{
								sprintf(buf2,"%c,%c,%c,%c,%c,%c\n", h1, b1, h2, b2, h3, b3);
								g5.WriteString(buf2);
								ins2-=16;
							}
							if(ins2>7)
							{
								sprintf(buf2,"%c,%c,%c,%c,%c,%c\n", h1, b1, h2, b2, h3, b3);
								g4.WriteString(buf2);
								ins2-=8;
							}
							if(ins2>3)
							{
								sprintf(buf2,"%c,%c,%c,%c,%c,%c\n", h1, b1, h2, b2, h3, b3);
								g3.WriteString(buf2);
								ins2-=4;
							}
							if(ins2>1)
							{
								sprintf(buf2,"%c,%c,%c,%c,%c,%c\n", h1, b1, h2, b2, h3, b3);
								g2.WriteString(buf2);
								ins2-=2;
							}
							if(ins2>0)
							{
								sprintf(buf2,"%c,%c,%c,%c,%c,%c\n", h1, b1, h2, b2, h3, b3);
								g.WriteString(buf2);
								ins2-=1;
							}
						}
					}
					else if (m_speltyp == 13 || m_speltyp == 14)
					{
						sprintf(buf,"%c,%c,%c,%c\n", h1, b1, h2, b2);
						if(ins2 >0)
						{
							char buf2[250];
							if(ins2>15)
							{
								sprintf(buf2,"%c,%c,%c,%c\n", h1, b1, h2, b2);
								g5.WriteString(buf2);
								ins2-=16;
							}
							if(ins2>7)
							{
								sprintf(buf2,"%c,%c,%c,%c\n", h1, b1, h2, b2);
								g4.WriteString(buf2);
								ins2-=8;
							}
							if(ins2>3)
							{
								sprintf(buf2,"%c,%c,%c,%c\n", h1, b1, h2, b2);
								g3.WriteString(buf2);
								ins2-=4;
							}
							if(ins2>1)
							{
								sprintf(buf2,"%c,%c,%c,%c\n", h1, b1, h2, b2);
								g2.WriteString(buf2);
								ins2-=2;
							}
							if(ins2>0)
							{
								sprintf(buf2,"%c,%c,%c,%c\n", h1, b1, h2, b2);
								g.WriteString(buf2);
								ins2-=1;
							}
						}
					}
					else   // Ishockey/Bandy/Fotboll med två matcher -->
						sprintf(buf,"E,%c-%c,%c-%c\n", h1, b1, h2, b2);

					f.WriteString(buf);
					row ++;
				}
				//KB[i][j][k][l][m][n]->spelat = ins;
			}
	  f.Close();
	  return true;

}
bool COdds::SkapaNorskSpelFil()
{
	char buf[250];

	CStdioFile f;

	BerIns1();	// Beräkna insatser och sortra

	if (f.Open( "spelfil.txt", CFile::modeWrite | CFile::modeCreate   , 0 ))
	{
		TBONG Bong;
		int	AntalKomb = 0;
		int	AntalBonger = 0;
		float TotIns02 = 0;
		float TotIns10 = 0;


		for (int pass=0; pass<18&& AntalBonger<90000; pass++) 		
		{
		SpelPos = 0;

		while (SpelPos < Num && AntalBonger<90000)
		{
			float ins;

            ins = KL[SpelPos].optins - KL[SpelPos].spelat;
			
			ins = floor( (ins * 10.0 + 5.0)/10.0);

			if (ins >= 1.0)
			{
				bool kompletterad  = false;
				SkapaBong(&Bong, &KL[SpelPos], ins);

				switch (pass) {
				case 0 : 
					kompletterad  = Komp1ins(&Bong, 30, false);
					break;

				case 1 : 
					kompletterad  = Komp1ins(&Bong, 20, false);
					break;

				case 2 : 
					kompletterad  = Komp1ins(&Bong, 16, false);
					break;

				case 3 : 
					kompletterad  = Komp1ins(&Bong, 10, false);
					break;

				case 4 : 
					kompletterad  = Komp1ins(&Bong, 8, false);
					break;

				case 5 : 
					if (ins > 9)
						kompletterad  = Komp1ins(&Bong, 2, false);
					break;

				case 6 :
					if (ins > 4)
						kompletterad  = Komp1ins(&Bong, 4, false);
					break;

				case 7 : 
					if (ins > 2)
						kompletterad  = Komp1ins(&Bong, 6, false);
					break;

				case 8 : 
					if (ins > 9)
						kompletterad  = Komp1ins(&Bong, 1, false);
					break;

				case 9 : 
					if (ins > 5)
						kompletterad  = Komp1ins(&Bong, 1, false);
					break;

				case 10: 
					if (ins > 2)
						kompletterad  = Komp1ins(&Bong, 2, false);
					break;

				case 11: 
					if (ins > 5)
						kompletterad  = Komp1ins(&Bong, 1, false);
					break;

				case 12: 
					kompletterad  = Komp1ins(&Bong, 4, false);
					break;

				case 13: 
					if (ins > 2)
						kompletterad  = Komp1ins(&Bong, 1, false);
					break;

				case 14: 
					kompletterad  = Komp1ins(&Bong, 4, false);
					break;

				case 15: 
					kompletterad  = Komp1ins(&Bong, 3, false);
					break;

				case 16: 
					kompletterad  = Komp1ins(&Bong, 2, false);
					break;

				case 17: 
					kompletterad  = Komp1ins(&Bong, 1, false);
					break;
				}

				if (kompletterad)
				{
					// Markera alla kombinationer som spelade
					MarkeraSpelad(&Bong);
					SkrivBong(&f, &Bong, AntalBonger);
					AntalBonger ++;
					AntalKomb += ANTALRES(Bong);
					TotIns02 += ANTALRES(Bong) * Bong.insats;
				}
			}
			SpelPos++;
			
		}
		}
	// Skriv ut ej spelade kombinationer
		int AntalMissade = 0;
		int AntalSpelbara = 0;
		for (int i=0; i<Num; i++)
			if (KL[i].insats>0)
			{
				AntalSpelbara ++;
				if (!KL[i].spelad)
				{
					sprintf(buf, "%2d-%2d\t%2d-%2d\t%2d-%2d\t%.2f\t%2.1f\n", 
						KL[i].h1, KL[i].b1, KL[i].h2, KL[i].b2, KL[i].h3, KL[i].b3, KL[i].kvot, KL[i].optins);
					f.WriteString(buf);
					AntalMissade ++;
				}
			}

		
		sprintf(buf,"Totalt antal spelad rader %d. Missade %d av %d.\n", AntalKomb, AntalMissade, AntalSpelbara);
		f.WriteString(buf);
		sprintf(buf,"Insatser -\t enkronorsrader: %.1f kr\t1 övriga %.1f E\t Totalt: %.1f kr\n", TotIns02, TotIns10, TotIns02+TotIns10);
		f.WriteString(buf);
		sprintf(buf,"Antal bonger: %d\n", AntalBonger);
		f.WriteString(buf);

		// Beräkna färväntat vinst
		float forvv = 0.0;
		for (int i=0; i<MAXRES; i++)
			for (int j=0; j<MAXRES; j++)
				for (int k=0; k<MAXRES; k++)
					for( int l=0;l<MAXRES;l++)
						for(int m=0;m<MAXRES;m++)
							for(int n=0;n<MAXRES;n++)
								for(int o=0;o<MAXRES4;o++)
									for(int p=0;p<MAXRES4;p++)
								if ((KBs(i,j,k,l,m,n,o,p) !=NULL) && (KBs(i,j,k,l,m,n,o,p)->spelat >0))
		
							forvv += FORVVINST(*Oms, KBs(i,j,k,l,m,n,o,p)->spelat, 
									KBs(i,j,k,l,m,n,o,p)->NOdds, KBs(i,j,k,l,m,n,o,p)->kvot);
									


		sprintf(buf,"Förväntad vinst = %.2f\n", forvv);
		f.WriteString(buf);

		f.Close();

		return true;
	}
	return false;


}
// kryss  0-60 anger position för det "nya" krysset enligt
//	H1	B1	H2	B2	H3	B3
//	0	1	2	3	4	5	
//	6	7	8	9	10	11
//	.	.	.	.	.	.
//	60	61	62	63	64	65
bool COdds::KomplNorskBong(int kryss, TBONG *B1, TBONG *B2)
{
	int	*idx=NULL, *l=NULL; // Index / lista

	// Kopera bong
	memcpy(B2, B1, sizeof( TBONG ));
	if (kryss==-1) return true;
	// Välj lista
	switch (kryss % 6) {
		case 0: idx = &B2->h1index; l = B2->h1list; break;
		case 1: idx = &B2->b1index; l = B2->b1list; break;
		case 2: idx = &B2->h2index; l = B2->h2list; break;
		case 3: idx = &B2->b2index; l = B2->b2list; break;
		case 4: idx = &B2->h3index; l = B2->h3list; break;
		case 5: idx = &B2->b3index; l = B2->b3list; break;
	}
	// Redan kryssad --> Avsluta
	for (int i = 0; i < *idx; i++)
			if ((kryss/6) == l[i])
				return false; 

	// Komplettera bong med kryss
	l[ *idx ]  = (kryss / 6);
	*idx = (*idx) + 1;

	// Test ifall bongen är giltig
	for (int i = 0; i<B2->h1index; i++)

	  for (int j = 0; j < B2->b1index; j++)

		for (int k = 0; k < B2->h2index; k++)

		  for (int l = 0; l < B2->b2index; l++)

			for (int m = 0; m < B2->h3index; m++)

			  for (int n = 0; n < B2->b3index; n++)
			  {
						
					TKombination *K = KB	[ B2->h1list[i] ] [ B2->b1list[j] ] [ B2->h2list[k] ]	
					[ B2->b2list[l] ] [ B2->h3list[m] ]	[ B2->b3list[n] ] [0][0];

					if (K == NULL)
						return false;

					else if (K->optins - K->spelat < B1->insats - 0.5) 
							return false;
			  }
	return true;
}


// Kompletterar bong där insatsen är 1				
bool COdds::Komp1ins(TBONG *B, int MinRes, bool AnnanIns)					
{
	TBONG BK, BK1, BK2, BK3; // Kompletterade bonger

	
	// for (int k1=0; k1<60; k1++)
	for (int k1=59; k1>=0; k1--)
	{
		if (m_speltyp!=12 && m_speltyp!=13 && m_speltyp!=14 && KomplNorskBong(k1, B, &BK))	
			memcpy(B, &BK, sizeof( TBONG ));

		else if ((m_speltyp==12 || m_speltyp==13 || m_speltyp==14) && KomplUnibetBong(k1, B, &BK))	
			memcpy(B, &BK, sizeof( TBONG ));
	}

	if (ANTALRES(*B)  >=  MinRes)
		return true;

	// return false;
	
	if (AnnanIns)
	{
		// Endast två rader -> Går inte att komplettera
		if (ANTALRES( *B ) < 3)
			return false;

		int		MinAntKomp = 100;		// Antal komplement med annan insats (initieras med dummy-värde)
		float	bfv = 0.0;				// Bästa förväntade vinst

		memcpy(&BK1, B, sizeof( TBONG )); // Kopiera bong
		
		// Testa att komplettera med ett kryss
		for (int k1=0; k1<60; k1++)
			if (KomplBong(k1, -1, &BK1, &BK2) && ArBastaBong(&BK2, B, 2, &MinAntKomp, &bfv))
				if (bfv>10.0)
					return true;

		// Testa att komplettera med två kryss
		for (int k1=0; k1<59; k1++)
			if (KomplBong(k1, -1, &BK1, &BK2))	
				for (int k2=k1+1; k2<60; k2++)
					if (KomplBong(k2, -1, &BK2, &BK3) && ArBastaBong(&BK3, B, 2, &MinAntKomp, &bfv))
						if (bfv>10.0)
								return true;
		
		// Testa att komplettera med tre kryss
		/* for (k1=0; k1<58; k1++)

			if (KomplBong(k1, -1, &BK1, &BK2))	
				for (int k2=k1+1; k2<59; k2++)
				
					if (KomplBong(k2, -1, &BK2, &BK3))	
						for (int k3=k2+1; k3<60; k3++)
					
							if (KomplBong(k3, -1, &BK3, &BK4) && ArBastaBong(&BK4, B, 2, &MinAntKomp, &bfv))
									if (bfv>10.0)
										return true;

		*/
		if (bfv>8.0)
			return true;
	}
	// Returnera false vid ingen träff
	return false;

}
bool COdds::ArBastaBong(TBONG *B, TBONG *Bcp, int MinRad, int *MinAntKomp, float *bfv)
{
	int		AntKomp		= AntalKomplement( B, true );
	float	fv			= BongForvVinst(B->insats, B );

	if (ANTALRES( *B) >= MinRad && AntKomp < *MinAntKomp  && fv > *bfv )
	{
		*MinAntKomp = AntKomp;
		*bfv = fv;
		memcpy(Bcp, B, sizeof( TBONG )); // Kopiera bong
		return true;
	}
	else
		return false;
}

bool COdds::SkapaUnibetSpelFil()
{
	char buf[250];

	CStdioFile f;

	BerIns1();	// Beräkna insatser och sortra

	if (f.Open( "spelfil.txt", CFile::modeWrite | CFile::modeCreate   , 0 ))
	{
		TBONG Bong;
		int	AntalKomb = 0;
		int	AntalBonger = 0;
		float TotIns02 = 0;
		float TotIns10 = 0;


		for (int pass=0; pass<18&& AntalBonger<90000; pass++) 		
		{
		SpelPos = 0;

		while (SpelPos < Num && AntalBonger<90000)
		{
			float ins;

            //ins = KL[SpelPos].optins - KL[SpelPos].spelat;
			// GB change 091013
			ins = 0.0;
			if (KL[SpelPos].optins - KL[SpelPos].spelat  >  0.05)
				ins = 0.1;
			// End GB change

			ins = floor( (ins*100.0 + 5.0)/10.0) / 10.0;

			if (ins >= 0.1)
			{
				bool kompletterad  = false;
				SkapaBong(&Bong, &KL[SpelPos], ins);

				switch (pass) {
				case 0 : 
					kompletterad  = Komp1ins(&Bong, 100, false);
					break;

				case 1 : 
					kompletterad  = Komp1ins(&Bong, 72, false);
					break;

				case 2 : 
					kompletterad  = Komp1ins(&Bong, 48, false);
					break;

				case 3 : 
					kompletterad  = Komp1ins(&Bong, 42, false);
					break;

				case 4 : 
					kompletterad  = Komp1ins(&Bong, 32, false);
					break;

				case 5 : 
						kompletterad  = Komp1ins(&Bong, 24, false);
					break;

				case 6 :
						kompletterad  = Komp1ins(&Bong, 18, false);
					break;

				case 7 : 
						kompletterad  = Komp1ins(&Bong, 12, false);
					break;

				case 8 : 
						kompletterad  = Komp1ins(&Bong, 10, false);
					break;

				case 9 : 
						kompletterad  = Komp1ins(&Bong, 8, false);
					break;

				case 10: 
						kompletterad  = Komp1ins(&Bong, 4, false);
					break;

				case 11: 
						kompletterad  = Komp1ins(&Bong, 3, false);
					break;

				case 12: 
						kompletterad  = Komp1ins(&Bong, 2, false);
					break;

				case 13: 
						kompletterad  = Komp1ins(&Bong, 1, false);
					break;

				case 14: 
						kompletterad  = Komp1ins(&Bong, 4, false);
					break;

				case 15: 
						kompletterad  = Komp1ins(&Bong, 3, false);
					break;

				case 16: 
						kompletterad  = Komp1ins(&Bong, 2, false);
					break;

				case 17: 
						kompletterad  = Komp1ins(&Bong, 1, false);
					break;
				}

				if (kompletterad)
				{
					// Markera alla kombinationer som spelade
					MarkeraSpelad(&Bong);
					SkrivBong(&f, &Bong, AntalBonger);
					AntalBonger ++;
					AntalKomb += ANTALRES(Bong);
					TotIns02 += ANTALRES(Bong) * Bong.insats;
				}
			}
			SpelPos++;
			
		}
		}
	// Skriv ut ej spelade kombinationer
		int AntalMissade = 0;
		int AntalSpelbara = 0;
		for (int i=0; i<Num; i++)
			if (KL[i].insats>0)
			{
				AntalSpelbara ++;
				if (!KL[i].spelad)
				{
					sprintf(buf, "%2d-%2d\t%2d-%2d\t%2d-%2d\t%.2f\t%2.1f\n", 
						KL[i].h1, KL[i].b1, KL[i].h2, KL[i].b2, KL[i].h3, KL[i].b3, KL[i].kvot, KL[i].optins);
					f.WriteString(buf);
					AntalMissade ++;
				}
			}

		
		sprintf(buf,"Totalt antal spelad rader %d. Missade %d av %d.\n", AntalKomb, AntalMissade, AntalSpelbara);
		f.WriteString(buf);
		sprintf(buf,"Insatser -\t enkronorsrader: %.1f kr\t1 övriga %.1f E\t Totalt: %.1f kr\n", TotIns02, TotIns10, TotIns02+TotIns10);
		f.WriteString(buf);
		sprintf(buf,"Antal bonger: %d\n", AntalBonger);
		f.WriteString(buf);

		// Beräkna färväntat vinst
		float forvv = 0.0;
		for (int i=0; i<MAXRES; i++)
			for (int j=0; j<MAXRES; j++)
				for (int k=0; k<MAXRES; k++)
					for( int l=0;l<MAXRES;l++)
						for(int m=0;m<MAXRES;m++)
							for(int n=0;n<MAXRES;n++)
								for(int o=0;o<MAXRES4;o++)
									for(int p=0;p<MAXRES4;p++)
								if ((KBs(i,j,k,l,m,n,o,p) !=NULL) && (KBs(i,j,k,l,m,n,o,p)->spelat >0))
		
							forvv += FORVVINST(*Oms, KBs(i,j,k,l,m,n,o,p)->spelat, 
									KBs(i,j,k,l,m,n,o,p)->NOdds, KBs(i,j,k,l,m,n,o,p)->kvot);
									


		sprintf(buf,"Förväntad vinst = %.2f\n", forvv);
		f.WriteString(buf);

		f.Close();

		return true;
	}
	return false;


}
bool COdds::SkapaUnibetSpelFil2()
{
	char buf[250];

	CStdioFile f;

	BerIns1();	// Beräkna insatser och sortra

	if (f.Open( "spelfil.txt", CFile::modeWrite | CFile::modeCreate   , 0 ))
	{
		TBONG Bong;
		int	AntalKomb = 0;
		int	AntalBonger = 0;
		float TotIns02 = 0;
		float TotIns10 = 0;


		for (int pass=0; pass<18&& AntalBonger<90000; pass++) 		
		{
		SpelPos = 0;

		while (SpelPos < Num && AntalBonger<90000)
		{
			float ins;

            //ins = KL[SpelPos].optins - KL[SpelPos].spelat;
			// GB change 091013
			ins = 0.0;
			if (KL[SpelPos].optins - KL[SpelPos].spelat  >=  1.0)
				ins = 1.0;
			else if (pass > 5 && KL[SpelPos].optins - KL[SpelPos].spelat  >  0.05)
				ins = 0.1;
			// End GB change

			ins = floor( (ins*100.0 + 5.0)/10.0) / 10.0;

			if (ins >= 0.1)
			{
				bool kompletterad  = false;
				SkapaBong(&Bong, &KL[SpelPos], ins);

				switch (pass) {
				case 0 : 
					kompletterad  = Komp1ins(&Bong, 10, false);
					break;

				case 1 : 
					kompletterad  = Komp1ins(&Bong, 6, false);
					break;

				case 2 : 
					kompletterad  = Komp1ins(&Bong, 5, false);
					break;

				case 3 : 
					kompletterad  = Komp1ins(&Bong, 4, false);
					break;

				case 4 : 
					kompletterad  = Komp1ins(&Bong, 3, false);
					break;

				case 5 : 
						kompletterad  = Komp1ins(&Bong, 2, false);
					break;

				case 6 :
						kompletterad  = Komp1ins(&Bong, 100, false);
					break;

				case 7 : 
						kompletterad  = Komp1ins(&Bong, 72, false);
					break;

				case 8 : 
						kompletterad  = Komp1ins(&Bong, 64, false);
					break;

				case 9 : 
						kompletterad  = Komp1ins(&Bong, 48, false);
					break;

				case 10: 
						kompletterad  = Komp1ins(&Bong, 32, false);
					break;

				case 11: 
						kompletterad  = Komp1ins(&Bong, 24, false);
					break;

				case 12: 
						kompletterad  = Komp1ins(&Bong, 16, false);
					break;

				case 13: 
						kompletterad  = Komp1ins(&Bong, 8, false);
					break;

				case 14: 
						kompletterad  = Komp1ins(&Bong, 4, false);
					break;

				case 15: 
						kompletterad  = Komp1ins(&Bong, 3, false);
					break;

				case 16: 
						kompletterad  = Komp1ins(&Bong, 2, false);
					break;

				case 17: 
						kompletterad  = Komp1ins(&Bong, 1, false);
					break;
				}

				if (kompletterad)
				{
					// Markera alla kombinationer som spelade
					MarkeraSpelad(&Bong);
					SkrivBong(&f, &Bong, AntalBonger);
					AntalBonger ++;
					AntalKomb += ANTALRES(Bong);
					TotIns02 += ANTALRES(Bong) * Bong.insats;
				}
			}
			SpelPos++;
			
		}
		}
	// Skriv ut ej spelade kombinationer
		int AntalMissade = 0;
		int AntalSpelbara = 0;
		for (int i=0; i<Num; i++)
			if (KL[i].insats>0)
			{
				AntalSpelbara ++;
				if (!KL[i].spelad)
				{
					sprintf(buf, "%2d-%2d\t%2d-%2d\t%2d-%2d\t%.2f\t%2.1f\n", 
						KL[i].h1, KL[i].b1, KL[i].h2, KL[i].b2, KL[i].h3, KL[i].b3, KL[i].kvot, KL[i].optins);
					f.WriteString(buf);
					AntalMissade ++;
				}
			}

		
		sprintf(buf,"Totalt antal spelad rader %d. Missade %d av %d.\n", AntalKomb, AntalMissade, AntalSpelbara);
		f.WriteString(buf);
		sprintf(buf,"Insatser -\t enkronorsrader: %.1f kr\t1 övriga %.1f E\t Totalt: %.1f kr\n", TotIns02, TotIns10, TotIns02+TotIns10);
		f.WriteString(buf);
		sprintf(buf,"Antal bonger: %d\n", AntalBonger);
		f.WriteString(buf);

		// Beräkna färväntat vinst
		float forvv = 0.0;
		for (int i=0; i<MAXRES; i++)
			for (int j=0; j<MAXRES; j++)
				for (int k=0; k<MAXRES; k++)
					for( int l=0;l<MAXRES;l++)
						for(int m=0;m<MAXRES;m++)
							for(int n=0;n<MAXRES;n++)
								for(int o=0;o<MAXRES4;o++)
									for(int p=0;p<MAXRES4;p++)
								if ((KBs(i,j,k,l,m,n,o,p) !=NULL) && (KBs(i,j,k,l,m,n,o,p)->spelat >0))
		
							forvv += FORVVINST(*Oms, KBs(i,j,k,l,m,n,o,p)->spelat, 
									KBs(i,j,k,l,m,n,o,p)->NOdds, KBs(i,j,k,l,m,n,o,p)->kvot);
									


		sprintf(buf,"Förväntad vinst = %.2f\n", forvv);
		f.WriteString(buf);

		f.Close();

		return true;
	}
	return false;


}
// kryss  0-60 anger position för det "nya" krysset enligt
//	H1	B1	H2	B2	H3	B3
//	0	1	2	3	4	5	
//	6	7	8	9	10	11
//	.	.	.	.	.	.
//	60	61	62	63	64	65
bool COdds::KomplUnibetBong(int kryss, TBONG *B1, TBONG *B2)
{
	int	*idx=NULL, *l=NULL; // Index / lista

	// Kopera bong
	memcpy(B2, B1, sizeof( TBONG ));
	if (kryss==-1) return true;
	// Välj lista
	switch (kryss % 6) {
		case 0: idx = &B2->h1index; l = B2->h1list; break;
		case 1: idx = &B2->b1index; l = B2->b1list; break;
		case 2: idx = &B2->h2index; l = B2->h2list; break;
		case 3: idx = &B2->b2index; l = B2->b2list; break;
		case 4: idx = &B2->h3index; l = B2->h3list; break;
		case 5: idx = &B2->b3index; l = B2->b3list; break;
	}
	// Redan kryssad --> Avsluta
	for (int i = 0; i < *idx; i++)
			if ((kryss/6) == l[i])
				return false; 

	// Komplettera bong med kryss
	l[ *idx ]  = (kryss / 6);
	*idx = (*idx) + 1;

	// Test ifall bongen är giltig
	for (int i = 0; i<B2->h1index; i++)

	  for (int j = 0; j < B2->b1index; j++)

		for (int k = 0; k < B2->h2index; k++)

		  for (int l = 0; l < B2->b2index; l++)

			for (int m = 0; m < B2->h3index; m++)

			  for (int n = 0; n < B2->b3index; n++)
			  {
						
					TKombination *K = KB	[ B2->h1list[i] ] [ B2->b1list[j] ] [ B2->h2list[k] ]	
					[ B2->b2list[l] ] [ B2->h3list[m] ]	[ B2->b3list[n] ] [0][0];

					if (K == NULL)
						return false;

					else if (K->optins - K->spelat < B1->insats - 0.05) 
							return false;
			  }
	return true;
}
