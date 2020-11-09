#include<conio.h>
#define BL       if(cnt==4) \
                 textcolor(col[0]+128); \
                 if(cnt==8)    \
                 textcolor(col[1]+128);

int xc[7]={4,12,20,28,36,44,52};
int yc[6]={21,18,15,12,9,6};
int blcnt=0; //blink count
int pl12=0;
int col[2];
int checker;
int firstfind=0;
int isfirstfind=0;
int playerturn=0;

void receiveColor(int c1,int c2,int checkernumber)
{
  checker=checkernumber;
  col[0]=c1;
  col[1]=c2;
  //printf("%d %d",col[0],col[1]);
}

void receiveplayerturn(int playerturn1)
{
  playerturn=playerturn1;
}

void hcomp(int g[7][6],int *cor)
{
 extern int pl12;
 extern int blcnt;
 int cnt=0,i,j;
 blcnt=0;
  pl12=0;
 textcolor(WHITE);
  for(i=0;i<=5;i++)
  {
   for(j=0;j<=3;j++)
   {
    cnt=0;
   // for(k=0;k<=3;k++)
    //{
      if((g[j][i]==g[j+1][i])&&(g[j+1][i]==g[j+2][i])&&(g[j+2][i]==g[j+3][i]))
      {
	cnt=(4*g[j][i]);
	if(cnt==4||cnt==8)
	{
                if(isfirstfind==0)
                {
                 firstfind=cnt;
                }
                isfirstfind++;
                if(cnt==firstfind)
                {
                 BL
                 for(blcnt=0;blcnt<=3;blcnt++)
                 {
                  gotoxy(xc[j+blcnt],yc[i]);
                  cprintf("   ");
                  gotoxy(xc[j+blcnt],yc[i]);
                  cprintf("%c%c%c",checker,checker,checker);
                  gotoxy(xc[j+blcnt],yc[i]+1);
                  cprintf("   ");
                  gotoxy(xc[j+blcnt],yc[i]+1);
                  cprintf("%c%c%c",checker,checker,checker);
                 }
		 textcolor(14);
		 gotoxy(65,9);
		if(cnt==4)
		cprintf("Player 1 wins");
		else
		cprintf("Player 2 wins");
                pl12=1;
		*cor=1;
         }
       }
     // }
    }
   }
  }
 }

void vcomp(int g[7][6],int *cor)
{
 int cnt=0,i,j;
   for(i=0;i<=5;i++)
   {
    for(j=0;j<=2;j++)
    {
     cnt=0;
    // for(k=0;k<=3;k++)
     //{
       if((g[i][j]==g[i][j+1])&&(g[i][j+1]==g[i][j+2])&&(g[i][j+2]==g[i][j+3]))
       {
	cnt=(4*g[i][j]);
	if(cnt==4||cnt==8)
	{
               if(isfirstfind==0)
                {
                 firstfind=cnt;
                }
                 isfirstfind++;
                 if(cnt==firstfind)
                 {
                 BL
                 for(blcnt=0;blcnt<=3;blcnt++)
		 {
                  gotoxy(xc[i],yc[j+blcnt]);
                  cprintf("%c%c%c",checker,checker,checker);
                  gotoxy(xc[i],yc[j+blcnt]+1);
                  cprintf("%c%c%c",checker,checker,checker);
                 }
        	textcolor(14);
                if(pl12!=1)
                {
                 pl12=1;
        	gotoxy(65,9);
        	if(cnt==4)
        	cprintf("Player 1 wins");
        	else
        	cprintf("Player 2 wins");
                }
        	*(cor+1)=1;
          }
	}
      }
    }
  // }
  }
 }

 void ducomp(int g[7][6],int *cor)
{
 int cnt=0,i,j;
   for(i=0;i<=3;i++)
   {
    for(j=0;j<=2;j++)
    {
     cnt=0;
    // for(k=0;k<=3;k++)
    // {
       if((g[i][j]==g[i+1][j+1])&&(g[i+1][j+1]==g[i+2][j+2])&&(g[i+2][j+2]==g[i+3][j+3]))
       {
	cnt=(4*g[i][j]);
	if(cnt==4||cnt==8)
	{
          BL
          for(blcnt=0;blcnt<=3;blcnt++)
          {
           gotoxy(xc[i+blcnt],yc[j+blcnt]);
           cprintf("%c%c%c",checker,checker,checker);
           gotoxy(xc[i+blcnt],yc[j+blcnt]+1);
           cprintf("%c%c%c",checker,checker,checker);
          }
	  textcolor(14);
          if(pl12!=1)
          {
           pl12=1;
	  gotoxy(65,9);
	  if(cnt==4)
	  cprintf("Player 1 wins");
	  else
	  cprintf("Player 2 wins");
          }
	  *(cor+2)=1;
	}
      }
   // }
   }
  }
 }

  void ddcomp(int g[7][6],int *cor)
{
 int cnt=0,i,j;
   for(i=0;i<=3;i++)
   {
    for(j=3;j<=5;j++)
    {
     cnt=0;
   //  for(k=0;k<=3;k++)
   //  {
       if((g[i][j]==g[i+1][j-1])&&(g[i+1][j-1]==g[i+2][j-2])&&(g[i+2][j-2]==g[i+3][j-3]))
       {
	cnt=(4*g[i][j]);
	if(cnt==4||cnt==8)
	{
        BL
        for(blcnt=0;blcnt<=3;blcnt++)
         {
          gotoxy(xc[i+blcnt],yc[j-blcnt]);
          cprintf("%c%c%c",checker,checker,checker);
          gotoxy(xc[i+blcnt],yc[j-blcnt]+1);
          cprintf("%c%c%c",checker,checker,checker);
         }
         textcolor(14);
         if(pl12!=1)
         {
         pl12=1;
	gotoxy(65,9);
	if(cnt==4)
	cprintf("Player 1 wins");
	else
	cprintf("Player 2 wins");
        }
	*(cor+3)=1;

	}
      }
   // }
   }
  }
 }



