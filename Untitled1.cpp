#include "clui.h" 
#include <iostream>
#include <ctime>
using namespace std;
char sum[5][5],num[5][5];
int temp=0,theta=0,punk=0,rose=0;
open_function()
{
	if(sum[temp][theta]!='F')
	{
		sum[temp][theta]=num[temp][theta];
		if(sum[temp][theta]=='*')
		rose++;
}
	else
	{
			cursor_to_pos(20,20);
					change_color_rgb(255,0,0);
					cout<<"error you cant open a flaged block";
					reset_color;
					delay(2000);
	}
}
void insert()
{
	while(true)
	{
		if(rose == 19)
		{
			clear_screen();
			int rana=10;
			cursor_to_pos(rana,50);
			cout<<"_______________";
				for(int i=0;i<5;i++)
				{
					rana++;
					cursor_to_pos(rana,50);
					for(int j=0;j<5;j++)
					{
						cout<<'|';
						if(num[i][j]=='B')
						{
							change_color_rgb(255,0,0);
							cout<<num[i][j];
							reset_color();
						}
						else
						cout<<num[i][j];
						cout<<'|';
		   			 }
		
				}
				cursor_to_pos(25,25);
				change_color_rgb(255,0,0);
				cout<<"YOU WON";
				reset_color;
				delay(3000);
				quit();
			
		}
		clear_screen();
		int mana=10;
		cursor_to_pos(mana,50);
		cout<<"_______________";
			for(int i=0;i<5;i++)
			{
				mana++;
				cursor_to_pos(mana,50);
				for(int j=0;j<5;j++)
				{
					cout<<'|';
					if( i==temp && j==theta)
					{
						change_color_rgb(61,59,196);
						cout<<sum[i][j];
						reset_color();
					}
			
					else
					cout<<sum[i][j];
					cout<<'|';
		   		}
			}
		cursor_to_pos(mana+1,50);
		cout<<"---------------";
		cursor_to_pos(20,4);
		change_color_rgb(115,140,41);
		cout<<"**guide**"<<endl<<"press w to go up"<<endl;
		cout<<"press s to go down"<<endl;
		cout<<"press d to go to right"<<endl;
		cout<<"press a to go to left"<<endl;
		cout<<"press f to put flag"<<endl;
		cout<<"press e to open the block"<<endl;
		cout<<"press esc to exit";
		reset_color();
		
		char hong=getch();
		if(hong=='e' || hong =='E')
		{
			if(num[temp][theta]=='B')
			{
				clear_screen();
				int rana=10;
				cursor_to_pos(rana,50);
				cout<<"_______________";
				for(int i=0;i<5;i++)
				{
					rana++;
					cursor_to_pos(rana,50);
					for(int j=0;j<5;j++)
					{
						cout<<'|';
						if(num[i][j]=='B')
						{
							change_color_rgb(255,0,0);
							cout<<num[i][j];
							reset_color();
						}
						else
						cout<<num[i][j];
						cout<<'|';
		    		}
		    		cursor_to_pos(rana+1,50);
					cout<<"---------------";
		
				}
			cursor_to_pos(20,20);
			change_color_rgb(255,0,0);
			cout<<"YOU LOST";
			delay(2000);
			cursor_to_pos(25,25);
			cout<<"paly again (p) or any key to exit game";
			reset_color;
			char kong=getch();
			if(kong=='p' || kong=='P')			
			return;
			else
			quit();
			}
			else
			open_function();
		}
		if(hong=='w' || hong=='W')
		{
			if(temp==0)
			temp=4;
			else
			temp--;
			continue;
		}
		if(hong=='s' || hong=='S')
		{
			if(temp==4)
			temp=0;
			else
			temp++;
			continue;
		}
		if(hong=='d' || hong=='D')
		{
			if(theta==4)
			theta=0;
			else
			theta++;
			continue;
		}
		if(hong=='a' || hong=='A')
		{
			if(theta==0)
			theta=4;
			else
			theta--;
			continue;
		}
		if(hong=='f' || hong=='F')
		{
				if(sum[temp][theta]=='F')
				{
					punk--;
					sum[temp][theta]='*';
					continue;
				}
				if(punk>5)
				{
					cursor_to_pos(20,20);
					change_color_rgb(255,0,0);
					cout<<"max flags are 6!!";
					reset_color;
					delay(2000);
					continue;
				}
				if(sum[temp][theta]=='*')
				{
					sum[temp][theta]='F';
					punk++;
					continue;
				}
		
				else
				{
					cursor_to_pos(20,20);
					change_color_rgb(255,0,0);
					cout<<"error you cant put flag on an opened block";
					reset_color;
					delay(2000);
					continue;
				}		
		}
		if(hong==27)
			quit();
		
	
		}	
}
void bomb_generator()
{
	srand(time(NULL));
	for(int i=0;i<6;i++)
	{
		int temp=rand()%5;
		int lum=rand()%5;
		if(num[temp][lum]!='B')
			num[temp][lum]='B';
		else
			i--;
	}
	for(int i=0;i<5;i++)
    {
    	for(int j=0;j<5;j++)
    	{
    		if(num[i][j]!='B')
    			num[i][j]='0';
		}
	}
	return;
}
void table_generator()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(num[i][j]=='B')
			{
				if((i-1)>=0 && (j-1)>=0 && num[i-1][j-1]!='B')
					num[i-1][j-1]++;
				if((j-1)>=0 && num[i][j-1]!='B')
					num[i][j-1]++;
				if((i+1)<5 && (j-1)>=0 && num[i+1][j-1]!='B')
					num[i+1][j-1]++;
				if(i+1<5 && num[i+1][j]!='B')
					num[i+1][j]++;
				if((i+1)<5 && (j+1)<5 && num[i+1][j+1]!='B')
					num[i+1][j+1]++;
				if((j+1)<5 && num[i][j+1]!='B')
					num[i][j+1]++;
				if((i-1)>=0 && (j+1)<5 && num[i-1][j+1]!='B')
					num[i-1][j+1]++;
				if((i-1)>=0 && num[i-1][j]!='B')
					num[i-1][j]++;
			}
		}
	}
	
}
int main()
{

	init_clui();
    bomb_generator();
    table_generator();
    change_color_rgb(199,80,82);
    cursor_to_pos(10,45);
    cout<<"WELCOME TO MINESWEEPER GAME!!";
    delay(5000);
    cursor_to_pos(13,45);
    change_color_rgb(60,196,59);
	cout<<"press any key to continue";
	reset_color();
	char trash=getch();
	while(true)
	{
		for (int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				sum[i][j]='*';
				num[i][j]='0';
			}
		}
		bomb_generator();
    	table_generator();
    	temp=theta=punk=rose=0;
		insert();
	
}
}
