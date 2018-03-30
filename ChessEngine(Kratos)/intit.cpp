# include <bits/stdc++.h>
# include "kratos.h"
using namespace std;
void Initsq120Tosq64()
{
	int index = 0 ;

	 int file =FILE_A;
	 int rank = RANK_1;
	 int sq =A1;
	 int sq64=0;
	 for(index = 0 ; index < 65 ;index++)
	 {
	 	sq64Tosq120[index]=120;

	 }
	 for(rank = RANK_1 ;rank <=RANK_8 ;rank++)
	 {
	 	for(file =FILE_A ;file<=FILE_H ; file++)
	 	{
	 		sq =FR2SQ(file,rank);
	 		sq64Tosq120[sq64]=sq;
	 		sq120Tosq64[sq]=sq64;
	 		sq64++;
	 	}
	 }
}
