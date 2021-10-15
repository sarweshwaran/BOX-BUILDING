#include<bits/stdc++.h>

using namespace std;


char row1[8]={'.',' ','.',' ','.',' ','.','\0'};
char row2[8]={'.',' ','.',' ','.',' ','.','\0'}; 
char row3[8]={'.',' ','.',' ','.',' ','.','\0'};

char init_row1[8]={' ',' ',' ',' ',' ',' ',' ','\0'};
char init_row2[8]={' ',' ',' ',' ',' ',' ',' ','\0'};

int change(int r,int p,int player);
int check(int r,int p,int player);

int player1=0,player2=0;



//to print welcome note

void welcome()
{
	cout<<"\t\t****************************\n\t\t\tBOX BUILDING\n\t\t****************************";
	cout<<"\n\nWELCOME TO BOX BUILDING...\n\nTHIS GAME NEEDS TWO PLAYERS. \nBOTH OF YOU NEED TO TRY TO CREATE AS MANY BOX YOU CAN BY JOINING THE GIVEN DOTS.\nFOR EVERY BOX YOU CREATE YOU'LL GET AN EXTRA 1 MOVE";
	cout<<"\n\nUSE ROW NUMBER AND PLACE HOLDER NUMBER TO CHOOSE YOUR DESIRE POSITION TO CREATE A LINE\n\nTHE ROW  NUMBERS ARE ASSIGNED AS FOLLOW..\n\n. . . .\t-->row no. 1\n       \t-->row no. 2\n. . . .\t-->row no. 3\n       \t-->row no. 4\n. . . .\t-->row no. 5\n\nUSE 0 TO RESELECT ROW NUMBER\nPLACE HOLDER NUMBERS ARE SHOWN ONCE YOU SELECT THE ROW NUMBER\n\nOK!! ALL SET LET'S GET INTO THE GAME";
	cout<<"\n\nPRESS ANY KEY TO BEGIN THE GAME...";
	cin.get();
}


//to display the board

void display()
{
	system("cls");
	cout<<"\t\t****************************\n\t\t\tBOX BUILDING\n\t\t****************************";
	cout<<"\n\n";
	cout<<"\t\t\t    BOARD\n\n";
	cout<<"\t\t\t   "<<row1<<endl;
	cout<<"\t\t\t   "<<init_row1<<endl;
	cout<<"\t\t\t   "<<row2<<endl;
	cout<<"\t\t\t   "<<init_row2<<endl;
	cout<<"\t\t\t   "<<row3<<endl;
	cout<<"\n\n\t\t\tBOXES OCCUPIED\n\n\t\tPLAYER 1 = "<<player1<<"\tPLAYER 2 = "<<player2<<endl;

}


//function that carry on the entire game

void game()
{
	bool gameover=false;
	int player=1,round=1;
	int r,p;
	while(!gameover)
	{
		display();
		cout<<"\nPLAYER -->"<<player;
		lable:
		do{
		
		cout<<"\nENTER THE ROW NUMBER : ";
		cin>>r;
		
		}while(!(r<6&&r>0));
		if(r%2==1)
		{
			cout<<"\n.1.3.5.\nENTER THE PLACE NUMBER :";
			cin>>p;
			if(p==0)
			{
				goto lable;
			}
		}
		else
		{
			cout<<"\n1 3 5 7\nENTER THE PLACE NUMBER :";
			cin>>p;
			if(p==0)
			{
				goto lable;
			}
		}
		
		
		if(!change(r,p,player))
		{
			player=player==1?2:1;
		}
		
		round++;
		if(round>17)
		{
			gameover=true;
		}
	}
	
}


//to where all the box are completed

int change(int r,int p, int player)
{
	bool u=false,d=false,l=false;
	switch(r)
	{
		case 1:
			if(row1[p]=='-'||!(p==1||p==3||p==5))
			{
				do{
					cout<<"INVALID PLACE NUMBER ENTER AGAIN\n\n.1.3.5.\nENTER THE PLACE NUMBER : ";
					cin>>p;
					
				}while(row1[p]=='-'||!(p==1||p==3||p==5));
			}
			row1[p]='-';
			if(r-1>0)
			{
				u=check(r-1,p+1,player);
			}
			if(r+1<5)
			{
				d=check(r+1,p+1,player);
			}
			if(u || d)
			{
				return true;
			}
			break;
			
			
			
		case 2:
			if(init_row1[p]=='|'||!(p==1||p==3||p==5||p==7||p==9))
			{
				do{
					cout<<"INVALID PLACE NUMBER ENTER AGAIN\n\n1 3 5 7\nENTER THE PLACE NUMBER : ";
					cin>>p;
					
				}while(init_row1[p]=='|'||!(p==1||p==3||p==5||p==7||p==9));
			}
			init_row1[p-1]='|';
			if(p-1>0)
			{
				l=check(r,p-1,player);
			}
			if(p+1<10)
			{
				r=check(r,p+1,player);
			}
			if(r || l)
			{
				return true;
			}
			break;
			
			
			
		case 3:
			if(row2[p]=='-'||!(p==1||p==3||p==5))
			{
				do{
					cout<<"INVALID PLACE NUMBER ENTER AGAIN\n\n.1.3.5.\nENTER THE PLACE NUMBER : ";
					cin>>p;
					
				}while(row2[p]=='-'||!(p==1||p==3||p==5));
			}
			row2[p]='-';
			if(r-1>0)
			{
				u=check(r-1,p+1,player);
				
			}
			if(r+1<5)
			{
				d=check(r+1,p+1,player);
			}
			if(u || d)
			{
				return true;
			}
			break;
			
			
			
		case 4:
			if(init_row2[p]=='|'||!(p==1||p==3||p==5||p==7||p==9))
			{
				do{
					cout<<"INVALID PLACE NUMBER ENTER AGAIN\n\n1 3 5 7\nENTER THE PLACE NUMBER : ";
					cin>>p;
					
				}while(init_row2[p]=='|'||!(p==1||p==3||p==5||p==7||p==9));
			}
			init_row2[p-1]='|';
			if(p-1>0)
			{
				l=check(r,p-1,player);
			}
			if(p+1<8)
			{
				r=check(r,p+1,player);
			}
			if(r || l)
			{
				return true;
			}
			break;
			
			
			
			
			
		case 5:
			if(row3[p]=='-'||!(p==1||p==3||p==5))
			{
				do{
					cout<<"INVALID PLACE NUMBER ENTER AGAIN\n\n.1.3.5.\nENTER THE PLACE NUMBER : ";
					cin>>p;
					
				}while(row3[p]=='-'||!(p==1||p==3||p==5));
			}
			row3[p]='-';
			if(r-1>0)
			{
				u=check(r-1,p+1,player);
			}
			if(r+1<5)
			{
				d=check(r+1,p+1,player);
			}
			if(u || d)
			{
				return true;
			}
			break;
	}
	return false;
}


int check(int r, int p, int player)
{
	char in=player==1?'A':'B';
	
	
	switch(r)
	{
		case 2:
			if(init_row1[p-2]=='|' && init_row1[p]=='|')
			{
				
				if(row1[p-1]=='-' && row2[p-1]=='-')
				{
					init_row1[p-1]=in;
					if(player==1)
					{
						player1++;
					}
					else
					{
						player2++;
					}
					return true;
				}
			}
			break;
			
			
		case 4:
			if(init_row2[p-2]=='|' && init_row2[p]=='|')
			{
				
				if(row2[p-1]=='-' && row3[p-1]=='-')
				{
					init_row2[p-1]=in;
					if(player==1)
					{
						player1++;
					}
					else
					{
						player2++;
					}
					return true;
				}
			}
			break;
		
	}
	return false;

	
}

int main()
{
	welcome();
	game();
	if(player1>player2)
	{
		system("cls");
		cout<<"\t\t\t******************************";
		cout<<"\n\n\n\t\t\t\t******BINGO******\n\n\t\t\t    PLAYER 1 YOU THE MATCH..";
		cout<<"\n\n\n\t\t\t******************************\n\n\n";
	}
	else if(player1==player2)
	{
		system("cls");
		cout<<"\t\t\t******************************";
		cout<<"\n\n\n\t\t\t\t**GREAT MATCH**\n\n\t\t\t  BUT THE MATCH IS DRAW..";
		cout<<"\n\n\n\t\t\t******************************\n\n\n";
	}
	else
	{
		system("cls");
		cout<<"\t\t\t******************************";
		cout<<"\n\n\n\t\t\t\t******BINGO******\n\n\t\t\t  PLAYER 1 YOU THE MATCH..";
		cout<<"\n\n\n\t\t\t******************************\n\n\n";
	}
}
