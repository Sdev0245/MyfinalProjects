### 2048 game
![](https://i.stack.imgur.com/wxgDV.png)

Hi everyone  i have the passion of creating the games.So this is the third game which is full of the logic i have created .The main logic or  the main thing is that in this game you need to move the blocks without pressing the enter.so for this i have used one function as given below.
```
void kbhit()
{
  system("stty raw");
  cin>>ct;
  system("stty cooked");
}```

where you donot need to press enter after pressing the 'w','s','a','d'.The major logic of the game is the only one function
````
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

						}
						```
            This above show how should the blocks be moved after you press the respective keys.Just analyse the above function you will know how to create the game.
