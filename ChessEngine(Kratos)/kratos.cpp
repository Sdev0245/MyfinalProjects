# include <stdio.h>
# include "kratos.h"
using namespace std;
int main()
{
	Initsq120Tosq64();
	
	for(int index =0 ;index < BRD_SQ_NUM ;index++)
{

	if(index%10 == 0 ) printf("\n");;
	printf("%5d",sq64Tosq120[index]);
}
	return 0;
}
