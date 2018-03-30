#ifndef _kratos_h
# define _kratos_h
typedef unsigned long long U64;
# define NAME "vice 1.0"
# define BRD_SQ_NUM 120
# define MAXGAMEMOVES 2048
# include "stdlib.h"
# define Assert(n)\
if(!n){\
	printf("%s Failed ",#n);\
	printf("On %s",__DATE__);\
		printf("At %s",__TIME__);\
		printf("%s In file",__FILE__);\
		printf("At line %d\n",__LINE__);\
		exit(1);}


enum {EMPTY,wP,wN,wB,wR,wQ,wK,bP,bN,bB,bR,bQ,bK};
enum {FILE_A,FILE_B,FILE_C,FILE_D,FILE_E,FILE_F,FILE_G,FILE_H,FILE_NONE};
enum {RANK_1,RANK_2,RANK_3,RANK_4,RANK_5,RANK_6,RANK_7,RANK_8,RANK_NONE};

enum { WHITE,BLACK,BOTH };



enum { A1=21, B1,C1,D1,E1,F1,G1,H1,
 A2=31, B2,C2,D2,E2,F2,G2,H2,
A3=41, B3,C3,D3,E3,F3,G3,H3,
A4=51, B4,C4,D4,E4,F4,G4,H4,
A5=61, B5,C5,D5,E5,F5,G5,H5,
A6=71, B6,C6,D6,E6,F6,G6,H6,
A7=81, B7,C7,D7,E7,F7,G7,H7,
A8=91, B8,C8,D8,E8,F8,G8,H8,NO_SQ
};
enum
{
WKCA=1,WQCA=2,BKCA=4,BQCA=8
};

enum{
	FALSE,TRUE
};
typedef struct 
{
	int move;
	int castlePerm;
	int enPas;
	int fiftyMove;
     U64 posKey;	

} S_UNDO;
typedef struct 
{
	int pieces[BRD_SQ_NUM];
	U64 pawns[3];
	int KingSq[2];
	int side;
	int enPas;
	int fiftyMove;
	int ply;
	int hisPly;
	int pceNum[13];
	int bigPce[3];
	int majPce[3];
	int minPce[3];
    S_UNDO history[2048];
    int pList[13][10];

} S_BOARD;

extern void Initsq120Tosq64();
extern int sq120Tosq64[BRD_SQ_NUM];
extern int sq64Tosq120[64];
# define FR2SQ(f,r) ((21) + (r) ) +((r)*10)
#endif 
