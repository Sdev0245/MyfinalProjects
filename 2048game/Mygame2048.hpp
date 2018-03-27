#ifndef _Mygame2048_hpp
# define _Mygame2048_hpp
# include <iostream>
using namespace std;
class display;
int genrand(int x);
class AI
{
	public:
  int krt;
  int fin;
  char ct;
  int max=2048;
  int win=0;
  int add=0;
  int s=0;
  int grid[4][4]={0};
  int backup_b[4][4]={0}; 
  void logic(display*);
  void kbhit();
  void start_grid();
  void update_grid();
  void fill_space();
  void fill_intial();
  void findmax();
  void backup_grid();  
  int full();
  int temp1();

};

class display : public AI
{
 
  
public:
  void display_grid();
  void start_grid();
};


void AI::kbhit()
{
  system("stty raw");
  cin>>ct;
  system("stty cooked");
}


void AI::logic(display *dev)
{
  
  switch(ct)
  {
  	case 'x':
  	exit(0);
      case 'w':
      case 'a':
      case 's':
      case 'd':
		 dev->backup_grid();
		 dev->fill_space();
		 dev->update_grid();
		 dev->fill_space();
		 dev->findmax();
		 dev->display_grid();
		  usleep(10000);

		  if(dev->full()&&fin)
		  {
		      krt=-1;
		      break;
		  }
		  else if(dev->temp1())
		  {
		     dev->fill_intial();
		      break;
		  }
		  else
		  {
		      krt=0;	
		      break;
		  }

      
		  
  }
}
void display::start_grid()
{
  int i,j;
  
  add=0;
  s=0;
  max=0;
  
	for(i=0;i<4;i++)	
		for(j=0;j<4;j++)
			grid[i][j]=0;

	i=genrand(4);
	j=genrand(4);

		grid[i][j]=2;

	i=genrand(4);
	j=genrand(4);

		grid[i][j]=2;
}

void display::display_grid()
{
	system("clear");
	cout<<"Created By Deven Sharma @NITH"<<" ";
		
			cout<<"\t\t\t\t"<<"press x to exit"<<endl;
			
		cout<<"\t\t\t\t\t\ts::"<<s<<" \n\n\n\n";
				
				for(int i=0;i<4;i++)
				{
				cout<<"\t\t     |";

					for(int j=0;j<4;j++)
					{
						if(grid[i][j])
							printf("%3d  |",grid[i][j]);
						else
							printf("%3c  |",' ');
					} 

				cout<<endl<<endl;
				}

		
}

int genrand(int x)
{
    int i;
    i=rand()%x;

return i;
}

void AI::backup_grid()
{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				backup_b[i][j]=grid[i][j];
}

		
void AI::fill_space()
{

	switch(ct)
	{
		case 'w':
					for(int i=0;i<4;i++)
						for(int j=0;j<4;j++)
						{
							if(!grid[j][i])
							{
								for(int k=j+1;k<4;k++)
									if(grid[k][i])
									{
										grid[j][i]=grid[k][i];
										grid[k][i]=0;
										break;
									}
							}

						}break;

		case 's':
					for(int i=0;i<4;i++)
						for(int j=3;j>=0;j--)
						{
							if(!grid[j][i])
							{
								for(int k=j-1;k>=0;k--)
									if(grid[k][i])
									{
										grid[j][i]=grid[k][i];
										grid[k][i]=0;
										break;
									}
							}

						}break;
		case 'a':
					for(int i=0;i<4;i++)
						for(int j=0;j<4;j++)
						{
							if(!grid[i][j])
							{
								for(int k=j+1;k<4;k++)
									if(grid[i][k])
									{
										grid[i][j]=grid[i][k];
										grid[i][k]=0;
										break;
									}
							}

						}break;


		case 'd':
					for(int i=0;i<4;i++)
						for(int j=3;j>=0;j--)
						{
							if(!grid[i][j])
							{
								for(int k=j-1;k>=0;k--)
									if(grid[i][k])
									{
										grid[i][j]=grid[i][k];
										grid[i][k]=0;
										break;
									}
							}

						}break; 

	}
}


void AI::update_grid()
{
	add=0;
	fin=1;

	switch(ct)
	{
		case 'w':
					for(int i=0;i<4;i++)
						for(int j=0;j<3;j++)
						{
							if(grid[j][i]&&grid[j][i]==grid[j+1][i])
							{
								fin=0;
								grid[j][i]+=grid[j+1][i];
								grid[j+1][i]=0;
								add+=(((log2(grid[j][i]))-1)*grid[j][i]);
								s+=(((log2(grid[j][i]))-1)*grid[j][i]);
								
							}
						}break;

		case 's':
					for(int i=0;i<4;i++)
						for(int j=3;j>0;j--)
						{
							if(grid[j][i]&&grid[j][i]==grid[j-1][i])
							{
								fin=0;
								grid[j][i]+=grid[j-1][i];
								grid[j-1][i]=0;
								add+=(((log2(grid[j][i]))-1)*grid[j][i]);
								s+=(((log2(grid[j][i]))-1)*grid[j][i]);
							}
						}break;

		case 'a':
					for(int i=0;i<4;i++)
						for(int j=0;j<3;j++)
						{
							if(grid[i][j]&&grid[i][j]==grid[i][j+1])
							{
								fin=0;
								grid[i][j]+=grid[i][j+1];
								grid[i][j+1]=0;
								add+=((log2(grid[i][j]))-1)*grid[i][j];
								s+=((log2(grid[i][j]))-1)*grid[i][j];
							}
						}break;

		case 'd':
					for(int i=0;i<4;i++)
						for(int j=3;j>0;j--)
						{
							if(grid[i][j]&&grid[i][j]==grid[i][j-1])
							{
								fin=0;
								grid[i][j]+=grid[i][j-1];
								grid[i][j-1]=0;
								add+=((log2(grid[i][j]))-1)*grid[i][j];
								s+=(((log2(grid[i][j]))-1)*grid[i][j]);
							}
						}break;


	}
	
	

}


void AI::fill_intial()
{
		int i,j,k;
		
		do
		{
		    i=genrand(4);
		    j=genrand(4);
		    k=genrand(10);

		}while(grid[i][j]);
				
		
			
		if(k<2)
		    grid[i][j]=2;

		else
		    grid[i][j]=4;
	

}
		
		
void AI::findmax()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(grid[i][j]>max)
				max=grid[i][j];
}

int AI::full()
{
	int k=1;

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(!grid[i][j])
				k=0;
				
		}
return k;
}

int AI::temp1()
{
	int k=0;

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(backup_b[i][j]!=grid[i][j])
			{	
				k=1;
				break;
			}
return k;
}
# endif