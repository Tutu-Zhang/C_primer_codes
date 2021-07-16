#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<time.h>
#include<conio.h>
#include<windows.h>

void xy(int x,int y)
{
	COORD posi = {x,y};
	HANDLE h;
	
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h,posi);
}

char map[51][101];

int main() 
{
		int inpx,inpy;
		
		printf("Please input the size of the map,both input should be less than 51 and larger than 10:\n");
		scanf("%d%d",&inpx,&inpy);
		
		if(inpx<20)
			inpx = 20;
		if(inpy<20)
			inpy = 20;
	
		xy(20,20);
		printf("Press any key to start");
	
		char ch = getch();
		int mark=0;
		
		system("cls");
	
	for(int i = 0;i<=inpy&&i<51;i++)
		for(int j = 0;j<=inpx*2&&j<101;j++)
		{
			if((i == 0)||(i==inpy)||j==0||j==inpx*2||i==100||j==200)
				printf("#"),map[j][i] = '#';
			else
			{
					printf(" ");
					map[j][i] = ' ';
			}
			
			if(j == inpx*2||j== 200)
				printf("\n");
		}

		 int posx = 2,posy = 2;

		xy(posx,posy);



		while(ch!='q')
		{
			Sleep(100);
			
			if(kbhit())
			{
				ch = getch();
			if(ch == 'a')
					{
						xy(posx,posy);
						printf(" ");
						posx-=2;
						mark = 1;
						if(map[posx][posy] == ' ')
						{
							xy(posx,posy);
							printf("0");
							xy(51,0);
						}
						else
							posx+=2;
					}
				if(ch == 'd')
				{
					xy(posx,posy);
						printf(" ");
					posx+=2;
					mark = 3;
					if(map[posx][posy] == ' ')
						{
							xy(posx,posy);
							printf("0");
							xy(51,0);
						}
						else
							posx-=2;
				}
				if(ch == 's')
				{
					xy(posx,posy);
						printf(" ");
					posy++;
					mark = 4;
					if(map[posx][posy] == ' ')
						{
							xy(posx,posy);
							printf("0");
							xy(51,0);
						}
						else
							posy--;
				}
				if(ch == 'w')
				{
					xy(posx,posy);
						printf(" ");
					posy--;
					mark = 2;
					if(map[posx][posy] == ' ')
						{
							xy(posx,posy);
							printf("0");
							xy(51,0);
						}
						else
							posy++;
				}
			}
			else
			{
				if(mark == 1)
					{
						xy(posx,posy);
						printf(" ");
						posx-=2;
						if(map[posx][posy] == ' ')
						{
							xy(posx,posy);
							printf("*");
							xy(51,0);
						}
						else
							posx+=2;
					}
				if(mark == 3)
				{
					xy(posx,posy);
						printf(" ");
					posx+=2;
					if(map[posx][posy] == ' ')
						{
							xy(posx,posy);
							printf("*");
							xy(51,0);
						}
						else
							posx-=2;
				}
				if(mark == 4)
				{
					xy(posx,posy);
						printf(" ");
					posy++;
					if(map[posx][posy] == ' ')
						{
							xy(posx,posy);
							printf("*");
							xy(51,0);
						}
						else
							posy--;
				}
				if(mark == 2)
				{
					xy(posx,posy);
						printf(" ");
					posy--;
					if(map[posx][posy] == ' ')
						{
							xy(posx,posy);
							printf("*");
							xy(51,0);
						}
						else
							posy++;
				}
			}
		}
}