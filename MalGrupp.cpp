// MalGrupp1.cpp: implementation of the CMalGrupp class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MalGrupp.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction7
//////////////////////////////////////////////////////////////////////

CMalGrupp::CMalGrupp()
{
	for (int i=0; i<26; i++)
		for (int j=0; j<10; j++)
			for (int k=0; k<2; k++)
				for (int l=0; l<10; l++)
					grupp[i][j][k][l] = false;
	
	// Initiera
	InsertGrp(110,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"2,4-3",		"7,8-0,1",
					"5-0,1,2",		"6-0,1,2",		"",				"",				"");

	InsertGrp(115,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"1-4",
					"5-0,1,2,3",	"6-0,1,2",		"7,8-0,1",		"",				"");

	InsertGrp(120,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"1,2,4-4,5",
					"5-0,1,2,3",	"7,8-0,1",		"6-0,1,2",		"",				"");
																										
	InsertGrp(125,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"1,2-4,5",
					"5-0,1,2,3",	"6,7-1,2",		"6,7,8-0",		"",				"");
																										
	InsertGrp(130,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"5-0,1,2,3",	"6,7-1,2",		"6,7,8-0",		"0,1,2-5",		"");
																										
	InsertGrp(135,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",
					"0,4-5",		"5-0,1,2,3,4",	"6,7-1,2",		"6,7,8-0",			"");
																										
	InsertGrp(140,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,2,4-5",		"5-1,2,3,4",	"6,7-1,2,3",	"5,6,7,8-0",	"");

	InsertGrp(145,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,2,4-5",		"5-1,2,3,4",	"6,7-1,2,3",	"5,6,7,8-0",	"");

	InsertGrp(150,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,4,5-4",
					"0,2-5",		"5-0,1,2,3",	"6-0,1,2,3",	"7-0,1,2,3",	"8-0");

	InsertGrp(155,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,2,3-5",		"5-0,1,2,3,4",	"6-0,1,2",		"7,8-0,1,2",		"");

	InsertGrp(160,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,2,3-5",		"5-0,1,2,3",	"6-0,1,2,3",	"7-0,1,2",		"");

	InsertGrp(165,	"0,1,2,3,4,8-0","0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",
					"0,1,2,3-5",	"2-6",			"5-0,1,2,3",	"6-0,1,2,3",	"7-0,1,2");

	InsertGrp(170,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2-5,6",	"7-1",			"6-0,1,2",		"5-0,1,2,4",	"");

	InsertGrp(175,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2,3-5",	"5,6,7-1,2",	"5,6,7,8-0",	"2-6",			"5-4");

	InsertGrp(180,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",		
					"0,1,2,3-5",	"1-6",			"5-0,1,2,3,4",	"6,7-0,1,2",	"");

	InsertGrp(185,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2,3-5",	"5-0,1,2,3,4",	"6,7-0,1,2",	"0,1,2-6",		"");

	InsertGrp(190,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2,3-5",	"0,1,2,3-6",	"5-0,1,2,3,4",	"6,7-0,1,2",	"");

	InsertGrp(195,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4,5-4",	
					"0,1,2,3-5",	"1,2,3-6",		"5,6-1,2",		"5,6,7-0",		"");

	InsertGrp(200,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2-6",		"5,6-0,1,2",	"0,1,2,3,4-5",	"",				"");

	InsertGrp(205,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2-5,6",	"5,6,7-1",		"5,6-2,3",		"5,6-0",		"4-5");

	InsertGrp(210,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2-5,6",	"5,6-2,3",		"5,6-0,1",		"",				"");

	InsertGrp(215,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2-5,6",	"5,6-2,3",		"5,6-0,1",		"",				"");

	InsertGrp(220,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2,3,4-5",	"5,6-0,1,2",	"0,2-6",		"",				"");

	InsertGrp(225,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2,3-5",	"0,2,3,4-6",	"5,6-0,1,2",	"",				"");

	InsertGrp(230,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2,3-5",	"5-0,1,2,3",	"0,2,4-6",		"6-0,1,2,4",	"");

	InsertGrp(235,	"0,1,2,3,4-0",	"0,1,2,3,4-1",	"0,1,2,3,4-2",	"0,1,2,3,4-3",	"0,1,2,3,4-4",	
					"0,1,2,3-5",	"5-0,1,2,3",	"0,2,4-6",		"6-0,1,2,4",	"");

}

CMalGrupp::~CMalGrupp()
{

}

int CMalGrupp::GetMalGrp(int Hodds)
{
	switch (Hodds) {
		case 110: return 0;
		case 115: return 1;
		case 120: return 2;
		case 125: return 3;
		case 130: return 4;
		case 135: return 5;
		case 140: return 6;
		case 145: return 7;
		case 150: return 8;
		case 155: return 9;
		case 160: return 10;
		case 165: return 11;
		case 170: return 12;
		case 175: return 13;
		case 180: return 14;
		case 185: return 15;
		case 190: return 16;
		case 195: return 17;
		case 200: return 18;
		case 205: return 19;
		case 210: return 20;
		case 215: return 21;
		case 220: return 22;
		case 225: return 23;
		case 230: return 24;
		case 235: return 25;
		case 240: return 23;
		case 245: return 22;
		case 250: return 21;
		case 255: return 20;
		case 260: return 19;
		case 265: return 18;
		case 275: return 17;
		case 280: return 16;
		case 290: return 15;
		case 300: return 14;
		case 315: return 13;
		case 325: return 12;
		case 335: return 11;
		case 360: return 10;
		case 380: return 9;
		case 400: return 8;
		case 435: return 7;
		case 460: return 6;
		case 485: return 5;
		case 515: return 4;
		case 550: return 3;
		case 600: return 2;
		case 680: return 1;
		case 770: return 0;

	}

	
	int ret = (Hodds <= 235) ? (Hodds-110)/5 : ((470-Hodds)-110)/5;;  
	if (ret>25)
		return 0;

	return ret;  
}

void CMalGrupp::InsertGrp(int H1odds, char *G0, char *G1, char *G2, char *G3, char *G4, 
									  char *G5, char *G6, char *G7, char *G8, char *G9)
{
	int	grp = GetMalGrp( H1odds);
	Insert(grp, 0, G0);
	Insert(grp, 1, G1);
	Insert(grp, 2, G2);
	Insert(grp, 3, G3);
	Insert(grp, 4, G4);
	Insert(grp, 5, G5);
	Insert(grp, 6, G6);
	Insert(grp, 7, G7);
	Insert(grp, 8, G8);
	Insert(grp, 9, G9);
}

void CMalGrupp::Insert(int OddsGrp, int MalGrp, char *S)
{
	char *p;
	p=S;
	while (*p != '-'  && *p !='\0')
	{
		if (*p >= '0' && *p <= '9')
			grupp[ OddsGrp ][ MalGrp ][ 0 ][ *p - '0' ] = true;
		p ++;
	}
	if (*p !='\0')
		p ++;
	while (*p != '-'  && *p !='\0')
	{
		if (*p >= '0' && *p <= '9')
			grupp[ OddsGrp ][ MalGrp ][ 1 ][ *p - '0' ] = true;
		p ++;
	}
}


int CMalGrupp::GetBong(int M1mg, int M2mg, int M3mg, int H1odds, int H2odds, int H3odds, TBONG *bong)
{
	// Oddsgrupp, Målgrupp, Hemma/Borta, Antal Mål
	bong->spelad = false;
	bong->insats = 0;

	bong->h1index = 0;
	bong->b1index = 0;
	bong->h2index = 0;
	bong->b2index = 0;
	bong->h3index = 0;
	bong->b3index = 0;
	bong->h4index = 0;
	bong->b4index = 0;

	for (int i=0; i<10; i++)
	{
		// Match 1 - Mål för hemmalaget
		if (((H1odds <= 235) && grupp[ GetMalGrp(H1odds) ][ M1mg ][ 0 ][ i ])
		  || ((H1odds > 235) && grupp[ GetMalGrp(H1odds) ][ M1mg ][ 1 ][ i ]))
			bong->h1list[ bong->h1index ++ ]  = i;

		// Match 1 - Mål för bortalaget
		if (((H1odds <= 235) && grupp[ GetMalGrp(H1odds) ][ M1mg ][ 1 ][ i ])
		  || ((H1odds > 235) && grupp[ GetMalGrp(H1odds) ][ M1mg ][ 0 ][ i ]))
			bong->b1list[ bong->b1index ++ ]  = i;

		// Match 2 - Mål för hemmalaget
		if (((H2odds <= 235) && grupp[ GetMalGrp(H2odds) ][ M2mg ][ 0 ][ i ])
		  || ((H2odds > 235) && grupp[ GetMalGrp(H2odds) ][ M2mg ][ 1 ][ i ]))
			bong->h2list[ bong->h2index ++ ]  = i;

		// Match 2 - Mål för bortalaget
		if (((H2odds <= 235) && grupp[ GetMalGrp(H2odds) ][ M2mg ][ 1 ][ i ])
		  || ((H2odds > 235) && grupp[ GetMalGrp(H2odds) ][ M2mg ][ 0 ][ i ]))
			bong->b2list[ bong->b2index ++ ]  = i;

		// Match 3 - Mål för hemmalaget
		if (((H3odds <= 235) && grupp[ GetMalGrp(H3odds) ][ M3mg ][ 0 ][ i ])
		  || ((H3odds > 235) && grupp[ GetMalGrp(H3odds) ][ M3mg ][ 1 ][ i ]))
			bong->h3list[ bong->h3index ++ ]  = i;

		// Match 3 - Mål för bortalaget
		if (((H3odds <= 235) && grupp[ GetMalGrp(H3odds) ][ M3mg ][ 1 ][ i ])
		  || ((H3odds > 235) && grupp[ GetMalGrp(H3odds) ][ M3mg ][ 0 ][ i ]))
			bong->b3list[ bong->b3index ++ ]  = i;
	}	

	// Returnera summa rader
	return	bong->h1index * bong->b1index * bong->h2index *
			bong->b2index * bong->h3index *	bong->b3index;

}

/* / Special
// Bong med 3 matcher i hocky/Bandy
int CMalGrupp::GetBongHockey3(int m1, int m2, int h3, int b3, TBONG *bong)
{
	// Oddsgrupp, Målgrupp, Hemma/Borta, Antal Mål
	bong->spelad = false;
	bong->insats = 0;

	bong->h1index = 0;
	bong->b1index = 0;
	bong->h2index = 0;
	bong->b2index = 0;
	bong->h3index = 0;
	bong->b3index = 0;
	bong->h4index = 1;
	bong->b4index = 1;

	// 0 <= m1 < 6
	if (m1==0 || m1==1 || m1==2) {
		bong->h1list[0] = 1;
		bong->h1list[1] = 2;
		bong->h1list[2] = 3;
		bong->h1list[3] = 4;
		bong->h1list[4] = 5;
		bong->h1index = 5;
	} else {
		bong->h1list[0] = 6;
		bong->h1list[1] = 7;
		bong->h1list[2] = 8;
		bong->h1list[3] = 9;
		bong->h1list[4] = 10;
		bong->h1index = 5;
	}
	if (m1==0 || m1==3) {
		bong->b1list[0] = 0;
		bong->b1list[1] = 1;
		bong->b1list[2] = 2;
		bong->b1index = 3;
	} else if (m1==1 || m1==4) {
		bong->b1list[0] = 3;
		bong->b1list[1] = 4;
		bong->b1list[2] = 5;
		bong->b1index = 3;
	
	} else {
		bong->b1list[0] = 6;
		bong->b1list[1] = 7;
		bong->b1list[2] = 8;
		bong->b1index = 3;
	}

	bong->h2list[0] = h3;
	bong->h2index = 1;
	bong->b2list[0] = b3;
	bong->b2index = 1;

	// 0 <= m2 < 4
	if (m2==0 || m2==1 ) {
		bong->h3list[0] = 1;
		bong->h3list[1] = 2;
		bong->h3list[2] = 3;
		bong->h3list[3] = 4;
		bong->h3list[4] = 5;
		bong->h3index = 5;
	} else {
		bong->h3list[0] = 6;
		bong->h3list[1] = 7;
		bong->h3list[2] = 8;
		bong->h3list[3] = 9;
		bong->h3list[4] = 10;
		bong->h3index = 5;
	}

	if (m2==0 || m2==2 ) {
		bong->b3list[0] = 0;
		bong->b3list[1] = 1;
		bong->b3list[2] = 2;
		bong->b3list[3] = 3;
		bong->b3list[4] = 4;
		bong->b3index = 5;
	} else {
		bong->b3list[0] = 5;
		bong->b3list[1] = 6;
		bong->b3list[2] = 7;
		bong->b3list[3] = 8;
		bong->b3list[4] = 9;
		bong->b3index = 5;
	}

	bong->h4list[0] =0;
	bong->h4index = 1;
	bong->b4list[0] = 0;
	bong->b4index = 1;
	// Returnera summa rader
	return	bong->h1index * bong->b1index * bong->h2index *
			bong->b2index * bong->h3index *	bong->b3index;
}
*/
// Bong med 3 matcher i hocky/Bandy
int CMalGrupp::GetBongHockey3(int m1, int m2, int h3, int b3, TBONG *bong)
{
	// Oddsgrupp, Målgrupp, Hemma/Borta, Antal Mål
	bong->spelad = false;
	bong->insats = 0;

	bong->h1index = 0;
	bong->b1index = 0;
	bong->h2index = 0;
	bong->b2index = 0;
	bong->h3index = 0;
	bong->b3index = 0;
	bong->h4index = 1;
	bong->b4index = 1;

	// 0 <= m1 < 4
	if (m1==0 || m1==1) {
		bong->h1list[0] = 0;
		bong->h1list[1] = 1;
		bong->h1list[2] = 2;
		bong->h1list[3] = 3;
		bong->h1list[4] = 4;
		bong->h1index = 5;
	} else {
		bong->h1list[0] = 5;
		bong->h1list[1] = 6;
		bong->h1list[2] = 7;
		bong->h1list[3] = 8;
		bong->h1list[4] = 9;
		bong->h1index = 5;
	}
	if (m1==0 || m1==2) {
		bong->b1list[0] = 0;
		bong->b1list[1] = 1;
		bong->b1list[2] = 2;
		bong->b1list[3] = 3;
		bong->b1list[4] = 4;
		bong->b1index = 5;
	} else {
		bong->b1list[0] = 5;
		bong->b1list[1] = 6;
		bong->b1list[2] = 7;
		bong->b1list[3] = 8;
		bong->b1list[4] = 9;
		bong->b1index = 5;
	}
		
	// 0 <= m2 < 6
	if (m2==0 || m2==1 || m2==2) {
		bong->h2list[0] = 0;
		bong->h2list[1] = 1;
		bong->h2list[2] = 2;
		bong->h2list[3] = 3;
		bong->h2list[4] = 4;
		bong->h2index = 5;
	} else {
		bong->h2list[0] = 5;
		bong->h2list[1] = 6;
		bong->h2list[2] = 7;
		bong->h2list[3] = 8;
		bong->h2list[4] = 9;
		bong->h2index = 5;
	}
	if (m2==0 || m2==3) {
		bong->b2list[0] = 0;
		bong->b2list[1] = 1;
		bong->b2list[2] = 2;
		bong->b2index = 3;
	} else if (m2==1 || m2==4) {
		bong->b2list[0] = 3;
		bong->b2list[1] = 4;
		bong->b2list[2] = 5;
		bong->b2index = 3;
	} else if (m2==2 || m2==5) {
		bong->b2list[0] = 6;
		bong->b2list[1] = 7;
		bong->b2list[2] = 8;
		bong->b2index = 3;
	}
	bong->h3list[0] = h3;
	bong->h3index = 1;
	bong->b3list[0] = b3;
	bong->b3index = 1;

	bong->h4list[0] =0;
	bong->h4index = 1;
	bong->b4list[0] = 0;
	bong->b4index = 1;
	// Returnera summa rader
	return	bong->h1index * bong->b1index * bong->h2index *
			bong->b2index * bong->h3index *	bong->b3index;
}
// Gruppera m=0 to 5 motsvarar 01-23-45-67-89-10
int CMalGrupp::SetGrupp2(int m, int *list)
{
	int index = 2;

	if (m==0)
	{
		list[0]=0;
		list[1]=1;
	} else if (m==1)
	{
		list[0]=2;
		list[1]=3;
	} else if (m==2)
	{
		list[0]=4;
		list[1]=5;
	} else if (m==3)
	{
		list[0]=6;
		list[1]=7;
	} else if (m==4)
	{
		list[0]=8;
		list[1]=9;
	} else if (m==5)
	{
		list[0]=10;
		index = 1;
	} 

	return index;
}
// Gruppera m=0 to 3 motsvarar 012-345-678-9,10
int CMalGrupp::SetGrupp3(int m, int *list)
{
	int index = 3;

	if (m==0)
	{
		list[0]=0;
		list[1]=1;
		list[2]=2;
	} else if (m==1)
	{
		list[0]=3;
		list[1]=4;
		list[2]=5;
	} else if (m==2)
	{
		list[0]=6;
		list[1]=7;
		list[2]=8;
	} else if (m==3)
	{
		list[0]=9;
		list[1]=10;
		index = 2;
	} 

	return index;
}

// Gruppera m=0 to 3 motsvarar 0123-4567-89,10
int CMalGrupp::SetGrupp4(int m, int *list)
{
	int index = 4;

	if (m==0)
	{
		list[0]=0;
		list[1]=1;
		list[2]=2;
		list[3]=3;
	} else if (m==1)
	{
		list[0]=4;
		list[1]=5;
		list[2]=6;
		list[3]=7;
	} else if (m==2)
	{
		list[0]=8;
		list[1]=9;
		list[2]=10;
		index = 3;
	}

	return index;
}

// Fotboll med 4 matcher
int CMalGrupp::GetBongFotboll4(int mh1, int mb1, int mh2, int mb2, int mh3, int mb3, int mh4, int mb4, TBONG *bong)
{
	// Oddsgrupp, Målgrupp, Hemma/Borta, Antal Mål
	bong->spelad = false;
	bong->insats = 0;

	bong->h1index = 3;
	bong->b1index = 2;
	bong->h2index = 2;
	bong->b2index = 2;
	bong->h3index = 2;
	bong->b3index = 2;
	bong->h4index = 2;
	bong->b4index = 2;

	if (mh1==0) {
		bong->h1list[0] = 0;
		bong->h1list[1] = 1;
		bong->h1list[2] = 2;
		} else {
		bong->h1list[0] = 3;
		bong->h1list[1] = 4;
		bong->h1list[2] = 5;
	}

	SetGrupp2(mb1, bong->b1list);
	SetGrupp2(mh2, bong->h2list);
	SetGrupp2(mb2, bong->b2list);
	SetGrupp2(mh3, bong->h3list);
	SetGrupp2(mb3, bong->b3list);
	SetGrupp2(mh4, bong->h4list);
	SetGrupp2(mb4, bong->b4list);

	// Returnera summa rader
	return	bong->h1index * bong->b1index * bong->h2index *	bong->b2index * 
			bong->h3index *	bong->b3index * bong->h4index *	bong->b4index;
}

// Hocky med 3matcher 4x4 x 3x2 x 2x2
int CMalGrupp::GetBongHocky3A(int mh1, int mb1, int mh2, int mb2, int mh3, int mb3,  TBONG *bong)
{
	// Oddsgrupp, Målgrupp, Hemma/Borta, Antal Mål
	bong->spelad = false;
	bong->insats = 0;

	bong->h1index = SetGrupp4(mh1, bong->h1list);
	bong->b1index = SetGrupp4(mb1, bong->b1list);
	bong->h2index = SetGrupp3(mh2, bong->h2list);
	bong->b2index = SetGrupp2(mb2, bong->b2list);
	bong->h3index = SetGrupp2(mh3, bong->h3list);
	bong->b3index = SetGrupp2(mb3, bong->b3list);
	
	bong->h4list[0] = 0;
	bong->h4index = 1;
	bong->b4list[0] = 0;
	bong->b4index = 1;

	// Returnera summa rader
	return	bong->h1index * bong->b1index * bong->h2index *	bong->b2index * 
			bong->h3index *	bong->b3index * bong->h4index *	bong->b4index;
}

// Fotboll med 3 matcher på Unibet 3x3 x 2x2 x 2x2
int CMalGrupp::GetBongUnibet3(int mh1, int mb1, int mh2, int mb2, int mh3, int mb3,  TBONG *bong)
{
	// Oddsgrupp, Målgrupp, Hemma/Borta, Antal Mål
	bong->spelad = false;
	bong->insats = 0;

	bong->h1index = SetGrupp3(mh1, bong->h1list);
	bong->b1index = SetGrupp3(mb1, bong->b1list);
	bong->h2index = SetGrupp2(mh2, bong->h2list);
	bong->b2index = SetGrupp2(mb2, bong->b2list);
	bong->h3index = SetGrupp2(mh3, bong->h3list);
	bong->b3index = SetGrupp2(mb3, bong->b3list);
	
	bong->h4list[0] = 0;
	bong->h4index = 1;
	bong->b4list[0] = 0;
	bong->b4index = 1;

	// Returnera summa rader
	return	bong->h1index * bong->b1index * bong->h2index *	bong->b2index * 
			bong->h3index *	bong->b3index * bong->h4index *	bong->b4index;
}