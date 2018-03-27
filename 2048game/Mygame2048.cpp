
# include <bits/stdc++.h>
# include <unistd.h>
# include "Mygame2048.hpp"
using namespace std;

int main()
{
  display a;
  
  srand(time(NULL));

  a.start_grid();
  
    while(1)
    {
      a.display_grid();
      a.kbhit();
      a.logic(&a);

    }
    
return 0;
}
