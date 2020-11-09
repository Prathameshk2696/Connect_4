#include"allinclude.cpp";
#define MAX_VALUE=32766;
#define MIN_VALUE=-32766

int wp=1;//which player for time control
int graph=0;
int first=0;
int stint=0;//static vars initialisation for play again
int pumpOldX=1,pumpSet=0,pDir=1;
int gDis[7][1];
int frameColor=15;
int *playerCP;
int *pumpCP;
int pumpC[2]={6,1};
int seizerX=0;
int tab=0;
char tabarray[]={'p','q','r','c','o','k','n'};
void initFields();
int coloredField=0;
int subcoloredfield=0;
int ischanged=0;
char returnedbyrules;
int checkers[4]={219,176,177,178};
int keyreleased=0;

void main()
{
 char chm;
 clrscr();
 if(graph==0)
 {
  graph=1;
  conpr();
  sleep(2);
  closegraph();
 }
 if(sa[6].colorV==1)
 {
  drawTheme(40,7,sa[4].colorV,sa[5].colorV,sa[3].colorV,checkers[sa[7].colorV]);
 }
 if(first==0)
 {
  if(ischanged==0)
  {
   initFields();
   ischanged=1;
  }
  receiveColor(sa[4].colorV,sa[5].colorV,checkers[sa[7].colorV]);
  _setcursortype(_NOCURSOR);
  textbackground(BLACK);
  if(coloredField==0)
  textcolor(12);
  else
  textcolor(WHITE);
  gotoxy(13,sa[0].y);
  cprintf(sa[0].name);
  if(coloredField==1)
  textcolor(12);
  else
  textcolor(WHITE);
  gotoxy(13,sa[1].y);
  cprintf(sa[1].name);
  if(coloredField==2)
  textcolor(12);
  else
  textcolor(WHITE);
  gotoxy(13,sa[2].y);
  cprintf(sa[2].name);
  if(coloredField==3)
  textcolor(12);
  else
  textcolor(WHITE);
  gotoxy(13,sa[3].y);
  cprintf(sa[3].name);
  textcolor(sa[3].colorV);
  cprintf(" %c%c",219,219);
  textcolor(WHITE);
  if(coloredField==4)
  textcolor(12);
  else
  textcolor(WHITE);
  gotoxy(13,sa[4].y);
  cprintf(sa[4].name);
  textcolor(sa[4].colorV);
  cprintf(" %c%c",checkers[sa[7].colorV],checkers[sa[7].colorV]);
  textcolor(WHITE);
  if(coloredField==5)
  textcolor(12);
  else
  textcolor(WHITE);
  gotoxy(13,sa[5].y);
  cprintf(sa[5].name);
  textcolor(sa[5].colorV);
  cprintf(" %c%c",checkers[sa[7].colorV],checkers[sa[7].colorV]);
  textcolor(WHITE);
  if(coloredField==6)
  textcolor(12);
  gotoxy(13,sa[6].y);
  cprintf(sa[6].name);
  textcolor(WHITE);
  if(sa[6].colorV==0)
  cprintf(" OFF");
  else
  if(sa[6].colorV==1)
  cprintf(" ON ");

  if(coloredField==7)
  textcolor(12);
  else
  textcolor(WHITE);
  gotoxy(13,sa[7].y);
  cprintf(sa[7].name);
  textcolor(WHITE);
  cprintf(" %c%c",checkers[sa[7].colorV],checkers[sa[7].colorV]);
  textcolor(WHITE);

  if(coloredField==8)
  textcolor(12);
  gotoxy(13,sa[8].y);
  cprintf(sa[8].name);
  textcolor(WHITE);
  if(sa[8].colorV==0)
  cprintf(" Keyboard");
  else
  if(sa[8].colorV==1)
  cprintf(" Mouse   ");

  if(coloredField==9)
  textcolor(12);
  gotoxy(13,sa[9].y);
  cprintf(sa[9].name);
  textcolor(WHITE);
  if(sa[9].colorV==0)
  cprintf(" OFF");
  else
  if(sa[9].colorV==1)
  cprintf(" ON ");

   if(coloredField==10&&subcoloredfield==0)
   textcolor(12);
   else
   textcolor(WHITE);
   gotoxy(13,sm[0].y);
   cprintf(sm[0].name);

   if(coloredField==10&&subcoloredfield==1)
   textcolor(12);
   else
   textcolor(WHITE);
   if(sm[0].mins<10)
   cprintf(" 0%d",sm[0].mins);
   else
   cprintf(" %d",sm[0].mins);
   textcolor(WHITE);
   cprintf(":");

   if(coloredField==10&&subcoloredfield==2)
   textcolor(12);
   else
   textcolor(WHITE);
   if(sm[0].secs<10)
   cprintf("0%d",sm[0].secs);
   else
   cprintf("%d",sm[0].secs);
   textcolor(WHITE);
   cprintf(":");

   if(coloredField==10&&subcoloredfield==3)
   textcolor(12);
   else
   textcolor(WHITE);
   if(sm[0].millis<10)
   cprintf("00%d",sm[0].millis);
   else
   if(sm[0].millis<100)
   cprintf("0%d",sm[0].millis);
   else
   cprintf("%d",sm[0].millis);
   textcolor(WHITE);

  if(coloredField==11)
  textcolor(12);
  gotoxy(35,sa[10].y);
  cprintf(sa[10].name);
  textcolor(WHITE);
  if(sa[10].colorV==0)
  cprintf(" Human vs Human   ");
  else
  if(sa[10].colorV==1)
  cprintf(" Human vs Computer");
  else
  if(sa[10].colorV==2)
  cprintf(" Computer vs Human");

  if(coloredField==12)
  textcolor(12);
  gotoxy(35,sa[11].y);
  cprintf(sa[11].name);
  textcolor(WHITE);
  if(sa[11].colorV==0)
  cprintf(" Traditional");
  else
  if(sa[11].colorV==1)
  cprintf(" Pop Out    ");

 }

 if(first==0)
 {
  fflush(stdin);
  chm=getch();
 }
 else
 chm='p';

 textcolor(WHITE);
 if(chm=='p'||(chm==13&&coloredField==0))
 {
  nochangesm[0]=sm[0];

  start();
 }
 if(chm=='q'||(chm==13&&coloredField==1))
 {
  exit(0);
 }
 else
 if(chm=='r'||(chm==13&&coloredField==2))
 {
  returnedbyrules=rules();
  if(returnedbyrules=='p')
  {
   nochangesm[0]=sm[0];
   coloredField=0;
   start();
  }
  else
  main();
 }
 else
 if(chm==72)
 {
  if(subcoloredfield==0)
  {
  coloredField--;
  if(coloredField<0)
  coloredField=12;
  }
  else
  {
   if(subcoloredfield==1&&sa[9].colorV==1)
   {
    sm[0].mins--;
    sm[1].mins--;
    if(sm[0].mins<1)
    {
     sm[0].mins=sm[1].mins=1;
    }
   }
   if(subcoloredfield==2&&sa[9].colorV==1)
   {
    sm[0].secs--;
    sm[1].secs--;
    if(sm[0].secs<0)
    {
     sm[0].secs=sm[1].secs=59;
    }
   }
   if(subcoloredfield==3&&sa[9].colorV==1)
   {
    sm[0].millis=sm[0].millis-10;
    sm[1].millis=sm[1].millis-10;
    if(sm[0].millis<0)
    {
     sm[0].millis=sm[1].millis=990;
    }
   }
  }
  main();
 }
 else
 if(chm==80)
 {
  if(subcoloredfield==0)
  {
   coloredField++;
   if(coloredField>12)
   coloredField=0;
  }
  else
  {
   if(subcoloredfield==1&&sa[9].colorV==1)
   {
    sm[0].mins++;
    sm[1].mins++;
   }
   if(subcoloredfield==2&&sa[9].colorV==1)
   {
    sm[0].secs++;
    sm[1].secs++;
    if(sm[0].secs>59)
    {
     sm[0].secs=sm[1].secs=0;
    }
   }
   if(subcoloredfield==3&&sa[9].colorV==1)
   {
    sm[0].millis=sm[0].millis+10;
    sm[1].millis=sm[1].millis+10;
    if(sm[0].millis>990)
    {
     sm[0].millis=sm[1].millis=0;
    }
   }
  }
  main();
 }
 else
 if(chm==75)
 {
  if(coloredField==12)
  {
   sa[11].colorV--;
   if(sa[11].colorV<0)
   sa[11].colorV=1;
  }
  else
  if(coloredField==11)
  {
   sa[10].colorV--;
   if(sa[10].colorV<0)
   sa[10].colorV=2;
  }
  else
  if(coloredField==10)
  {
   subcoloredfield--;
   if(subcoloredfield<0)
   subcoloredfield=3;
  }
  else
  if(coloredField==9)
  {
   sa[9].colorV=(sa[9].colorV+1)%2;
  }
  else
  if(coloredField==8)
  {
   sa[8].colorV=(sa[8].colorV+1)%2;
  }
  else
  if(coloredField==7)
  {
   sa[7].colorV=sa[7].colorV--;
   if(sa[7].colorV<0)
   sa[7].colorV=3;
  }
  else
  if(coloredField==6)
  {
   sa[6].colorV=(sa[6].colorV+1)%2;
  }
  else
  if(coloredField==3||coloredField==4||coloredField==5)
  {
   sa[coloredField].colorV--;
   if(coloredField==4)
   {
    if(sa[coloredField].colorV==sa[coloredField+1].colorV)
    sa[coloredField].colorV--;
   }
   else
   if(coloredField==5)
   {
    if(sa[coloredField].colorV==sa[coloredField-1].colorV)
    sa[coloredField].colorV--;
   }
   if(sa[coloredField].colorV==0)
   sa[coloredField].colorV=15;
  }
  main();
 }
 else
 if(chm==77)
 {
  if(coloredField==12)
  {
   sa[11].colorV++;
   if(sa[11].colorV>1)
   sa[11].colorV=0;
  }
  else
  if(coloredField==11)
  {
   sa[10].colorV++;
   if(sa[10].colorV>2)
   sa[10].colorV=0;
  }
  else
  if(coloredField==10)
  {
   subcoloredfield++;
   if(subcoloredfield>3)
   subcoloredfield=0;
  }
  if(coloredField==9)
  {
   sa[9].colorV=(sa[9].colorV+1)%2;
  }
  if(coloredField==8)
  {
   sa[8].colorV=(sa[8].colorV+1)%2;
  }
  if(coloredField==7)
  {
   sa[7].colorV=sa[7].colorV++;
   if(sa[7].colorV>3)
   {
    sa[7].colorV=0;
   }
  }
  else
  if(coloredField==6)
  {
   sa[6].colorV=(sa[6].colorV+1)%2;
  }
  else
  if(coloredField==3||coloredField==4||coloredField==5)
  {
   sa[coloredField].colorV++;
   if(coloredField==4)
   {
    if(sa[coloredField].colorV==sa[coloredField+1].colorV)
    sa[coloredField].colorV++;
   }
   else
   if(coloredField==5)
   {
    if(sa[coloredField].colorV==sa[coloredField-1].colorV)
    sa[coloredField].colorV++;
   }
   if(sa[coloredField].colorV==16)
   sa[coloredField].colorV=1;
  }
  main();
 }
 else
 main();
}

void start()
{
 void showpump();
 void showarrows();
 clrscr();
  rect(sa[3].colorV);
  if(sa[8].colorV==0)
  {
   showpump();
  }
  else
  {
   showarrows();
  }

 if(sa[10].colorV==0)
 {
  if(sa[9].colorV==0)
  {
   gotoxy(70,5);
   textcolor(sa[4].colorV);
   cprintf("Player 1");
  }
  else
  {
   gotoxy(70,5);
   textcolor(sa[4].colorV);
   cprintf("Player 1");
   gotoxy(70,7);
   textcolor(sa[5].colorV);
   cprintf("Player 2");
  }
 }
 else
 {
  if(sa[9].colorV==0)
  {
   gotoxy(70,5);
   textcolor(sa[4].colorV);
   cprintf("Human   ");
  }
  else
  if(sa[10].colorV==1)
  {
   gotoxy(70,5);
   textcolor(sa[4].colorV);
   cprintf("Human   ");
   gotoxy(70,7);
   textcolor(sa[5].colorV);
   cprintf("Computer");
  }
  else
  {
   gotoxy(70,5);
   textcolor(sa[4].colorV);
   cprintf("Computer");
   gotoxy(70,7);
   textcolor(sa[5].colorV);
   cprintf("Human   ");
  }
 }
 play();
 getch();
}
int filled=0;
void play()
{
  void twoplayerplay();
  void oneplayerplay();
  if(sa[10].colorV==0)
  twoplayerplay();
  else
  oneplayerplay();
}

char returnbutton()
{
  int ic;

  ic=msex/64;  //msex/8 is gotoxy coordinates..so diving again by 8
  //gotoxy(50,20);
  //printf("%d",ic);
  return ch[ic];
}

int childrenrootscores[7]={-3,-3,-3,-3,-3,-3,-3};
//int nm[7]={0,0,0,0,0,0,0};

int hashumanwon()
{
  int value;
  value=hocomp(g,2);
  if(value==8)
  return 1;
  value=vocomp(g,2);
  if(value==8)
  return 1;
  value=duocomp(g,2);
  if(value==8)
  return 1;
  value=ddocomp(g,2);
  if(value==8)
  return 1;

  return 0;
}

int hascomputerwon()
{
  int value;
  value=hocomp(g,1);
  if(value==4)
  return 1;
  value=vocomp(g,1);
  if(value==4)
  return 1;
  value=duocomp(g,1);
  if(value==4)
  return 1;
  value=ddocomp(g,1);
  if(value==4)
  return 1;

  return 0;
}

int gameOver()
{
  if(hascomputerwon()==1)
  return 1;
  if(hashumanwon()==1)
  return -1;
  else
  if(filled==42)   //draw
  return 0;
  else
  return -2;
}

int returnbestmove()
{
   int max=-1000;
   int bestindex=-1;
   for(int rbm=0;rbm<=6;rbm++)
   {
    if(childrenrootscores[rbm]>max)
    {
     max=childrenrootscores[rbm];
     bestindex=rbm;
    }
   }
   return bestindex;
}

int returnMax(int poi[7])
{
  int max=-100;
  for(int po=0;po<=6;po++)
  {
   if(poi[po]>max)
   {
    max=poi[po];
   }
  }
  return max;
}

int returnMin(int poi[7])
{
  int min=100;
  for(int po=0;po<=6;po++)
  {
   if(poi[po]<min)
   {
    min=poi[po];
   }
  }
  return min;
}

int callminimax(int depth,int player)
{
 int minimax(int,int);
 thinkframe();
 for(int crsc=0;crsc<=6;crsc++)
 {
  childrenrootscores[crsc]=-3;
 }
 minimax(depth,player);
 gotoxy(60,17);
 printf("                    ");
 gotoxy(60,17);
 for(int cv=0;cv<=6;cv++)
 {
  textcolor(WHITE);
  cprintf("%d,",cnt[cv]);
 }

 gotoxy(60,18);
 printf("                    ");
 gotoxy(60,18);
 for(int cu=0;cu<=6;cu++)
 {
  textcolor(WHITE);
  cprintf("%d,",childrenrootscores[cu]);
 }
 return returnbestmove();
}

int minimax(int depth,int player)
{
  if(hashumanwon()==1)
  {
   return -1;
  }
  else
  if(hascomputerwon()==1)
  {
   return 1;
  }

  if(depth==7)
  return 0;

  int points[7];

  for(int i=0;i<=6;i++)
  {
    if(cnt[i]<6)
    {
     if(player==1)
     {
       g[i][cnt[i]]=1;
       cnt[i]++;
       if(depth<7)
       points[i]=minimax(depth+1,2);

       if(depth==0)
       {
	 if(i==0)
	 removethinknext();
	 printthinknext();
	 childrenrootscores[i]=points[i];
	 if(points[i]==2)
	 {
	  gotoxy(70,13);
	  printf("happening");
	 }
       }
     }
     else
     if(player==2)
     {
      g[i][cnt[i]]=2;
      cnt[i]++;
      if(depth<7)
      points[i]=minimax(depth+1,1);
     }
     cnt[i]--;
     g[i][cnt[i]]=0;
   } //end of nm[i] if block
  } //end of for

  return player==1?returnMax(points):returnMin(points);
}

void oneplayerplay()
{
  int Xreturned;
  void openDown();
  void disappear();
  void showarrows();
  //int count=0;
  int corrchar=0; //correct character for sound
  char c;
  //static int pc=0;
  //static int p=0;
  int y;
  int randomnumber;
  //static int tc=0;

  if(filled==0&&sa[10].colorV==2)
     {
      randomize();
      randomnumber=random(7);
      printf("%d",randomnumber);
      //assigning c a character based on random number generated
      for(int rnc=0;rnc<=6;rnc++)
      {
       if(randomnumber==rnc)
       {
	c=ch[rnc];
	cnt[rnc]++;
	filled++;
	//gotoxy(70,16);
	//printf("count %d",cnt[rnc]);
	g[rnc][(cnt[rnc]-1)]=2;
	y=yv[cnt[rnc]-1];
	appear(4+8*rnc,y);
	rnc=6;
       }
      }
     } //end of if block

  printf("%d",gameOver());

  while(gameOver()==-2&&filled<42)
  {
    //	printf("\ninside while");

      corrchar=0;
      while(corrchar==0)
      {
       c=getch();
       for(int i=0;i<=6;i++)
       {
	if(c=='q'||c=='p'||c=='m')
	{
	 corrchar=1;
	 break;
	}
	if(c==ch[i])
	{
         if(cnt[i]>=6)
         corrchar=0; //if inserted checker is 7th or above
         else
         corrchar=1;
         if(corrchar==0)
         {
          sound(800);
          delay(100);
          nosound();
         }
        }
       } //end of for

      }  //end of corrchar while

      if(c=='p')
      {
       openDown();
       disappear();
       first=1;
       stint=1;
       initiate();
       sm[0]=sm[1]=nochangesm[0];
       main();
      }
      else
      if(c=='q')
      {
       exit(0);
      }
      else
      if(c=='m')
      {
       first=0;
       stint=1;
       initiate();
       sm[0]=sm[1]=nochangesm[0];
       main();
      }

   /* for(int i=0;i<=6;i++)
    {
     if(c==ch[i])
     {
      //nm[i]++;
      if(cnt[i]>=6)
      corrchar=0; //if inserted checker is 7th or above
      else
      corrchar=1;
     }
    }

   if(corrchar==0)
   {
     sound(800);
     delay(100);
     nosound();
   }

  corrchar=0; */

   if((c=='1'&&cnt[0]<=6)||(c=='2'&&cnt[1]<=6)||(c=='3'&&cnt[2]<=6)||(c=='4'&&cnt[3]<=6)||(c=='5'&&cnt[4]<=6)||(c=='6'&&cnt[5]<=6)||(c=='7'&&cnt[6]<=6))
   {

      gotoxy(70,5);
      if(sa[10].colorV==1)  //human vs computer
      {
       textcolor(sa[4].colorV);
       cprintf("Human   ");
      }
      else
      if(sa[10].colorV==2)
      {
       textcolor(sa[5].colorV);
       cprintf("Human   ");
      }

    for(int i=0;i<=6;i++)
    {
     if(c==ch[i])
     {
       filled++;
       cnt[i]++;
       //gotoxy(70,16);
       //printf("count %d",cnt[i]);
       g[i][(cnt[i]-1)]=2;
       y=yv[cnt[i]-1];
       appear(4+8*i,y);
       i=6;
     }
    }
  }  //end of if block
  if(gameOver()==-2)
  {
   textcolor(RED);
   gotoxy(62,16);
   cprintf("COMPUTER THINKING");
   textcolor(WHITE);
   Xreturned=callminimax(0,1);
   gotoxy(65,15);
   printf("                 ");
   textcolor(WHITE);
   gotoxy(70,18);
   cprintf("Xmini %d",Xreturned);
   cnt[Xreturned]++;
   filled++;
   //gotoxy(70,17);
   //cprintf("count %d",cnt[Xreturned]);
   g[Xreturned][(cnt[Xreturned]-1)]=1;
   y=yv[cnt[Xreturned]-1];
   appear(4+8*Xreturned,y);
   removethinknext();
   gotoxy(60,17);
   printf("                    ");
   gotoxy(60,17);
   for(int cv=0;cv<=6;cv++)
   {
    textcolor(WHITE);
    cprintf("%d,",cnt[cv]);
   }
   gotoxy(60,18);
   printf("                    ");
   gotoxy(60,18);
   for(int cu=0;cu<=6;cu++)
   {
    textcolor(WHITE);
    cprintf("%d,",childrenrootscores[cu]);
   }
  }
  else
  {
   printf("human wins");
  }
 }  //end of while
} //end of function


void twoplayerplay()
{
  void openDown();
  void disappear();
  int btnpressed=0;
  void showarrows();
  int allowmouse=0;
  int mousetimer=0;
  void timeends(int);
  int count=0;
  int corrchar=0; //correct character for sound
  char c;
  static int pc=0;
  static int p=0;
  int y;
  static int isfirst=0;//to start timer after player 1 plays
  static int tc=0;
  static int nm[7];//no more than 6 presses of each key

  if(sa[8].colorV==0)
  {
   textcolor(BLUE);
   gotoxy(65,11);
   cprintf("Exit q");
   gotoxy(65,12);
   cprintf("Main menu m");
   gotoxy(65,13);
   cprintf("Play again p");
  }

  if(sa[8].colorV==1&&sa[9].colorV==1)
  {
    showmouse();
    mousetimer=1;
    allowmouse=0;
  }

  if(sa[8].colorV==1&&sa[9].colorV==0)
  {
   showmouse();
   allowmouse=1;
   mousetimer=0;
  }

  if(stint==1)
  {
   mseb=0;
   stint=2;
   isfirst=0;
   pc=0;
   p=0;
   tc=0;
   for(int i=0;i<=6;i++)
   nm[i]=0;
   receiveColor(sa[4].colorV,sa[5].colorV,checkers[sa[7].colorV]);
  }

  if(sa[9].colorV==1&&sa[8].colorV==0) //keyboard inout with timer
  {
    wp=p%2;
    while(!kbhit())
    {
     if(isfirst==0)
     {
      for(int i=0;i<=1;i++)
       {
        gotoxy(60,5+i*2);
        if(sm[i].secs<10&&sm[i].millis==0)
        printf("%d:0%d:00%d",sm[i].mins,sm[i].secs,sm[i].millis);
        else
        if(sm[i].secs>=10&&sm[i].millis==0)
        printf("%d:%d:00%d",sm[i].mins,sm[i].secs,sm[i].millis);
        else
        if(sm[i].secs<10&&sm[i].millis<100)
        printf("%d:0%d:0%d",sm[i].mins,sm[i].secs,sm[i].millis);
        else
        if(sm[i].secs>=10&&sm[i].millis<100)
        printf("%d:%d:0%d",sm[i].mins,sm[i].secs,sm[i].millis);
        else
        if(sm[i].secs<10&&sm[i].millis>=100)
        printf("%d:0%d:%d",sm[i].mins,sm[i].secs,sm[i].millis);
        else
        printf("%d:%d:%d",sm[i].mins,sm[i].secs,sm[i].millis);
       }
      }//end of isfirst block
     else
     {
      if(sm[wp].millis==0&&sm[wp].secs==0)
      {
      sm[wp].mins=sm[wp].mins-1;
      sm[wp].secs=59;
      sm[wp].millis=990;
     }
     else
     if(sm[wp].millis==0&&sm[wp].secs>0)
     {
      sm[wp].secs=sm[wp].secs-1;
      sm[wp].millis=990;
     }
     else
     if(sm[wp].millis>0)
     {
      sm[wp].millis=sm[wp].millis-10;
     }
     if(sm[wp].mins==0&&sm[wp].secs==0&&sm[wp].millis==0)
     {
      count=2;
      break;
     }
      for(int i=0;i<=1;i++)
      {
       gotoxy(60,5+i*2);
       if(sm[i].secs<10&&sm[i].millis==0)
       printf("%d:0%d:00%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       if(sm[i].secs>=10&&sm[i].millis==0)
       printf("%d:%d:00%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       if(sm[i].secs<10&&sm[i].millis<100)
       printf("%d:0%d:0%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       if(sm[i].secs>=10&&sm[i].millis<100)
       printf("%d:%d:0%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       if(sm[i].secs<10&&sm[i].millis>=100)
       printf("%d:0%d:%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       printf("%d:%d:%d",sm[i].mins,sm[i].secs,sm[i].millis);
       }
      delay(10);
      }
     }
     if(count==2)
     {
      timeends(wp);
     }
   }

   else
   if(sa[9].colorV==1&&sa[8].colorV==1) //timer with mouse input
   {
     wp=p%2;
     setmouse();
     showmouse();
     while(mousetimer==1)
     {
       showmouse();
       showarrows();
       //showmouse();
       movemouse();
       //gotoxy(60,20);
       //cprintf("%d,%d",msex/8+1,msey/8+1);
      for(int z=0;z<=9;z++)
      {
       if(z<=6)
       {
         if(aroarr[z].x==(msex/8+1)&&(msey/8+1)==3)
         {
          aroarr[z].colorV=4;
          if(mseb==1)
          {
           while(mseb==1)
           {
             movemouse();
	   }
           aroarr[z].colorV=2;
           mousetimer=0;
          }
         }
         else
         {
          aroarr[z].colorV=15;
         }
        }
           else
         if(z==7||z==8||z==9)
         {
          if((z==9&&(msex/8+1)>=65&&(msex/8+1)<=73&&(msey/8+1)>=aroarr[z].x&&(msey/8+1)<=aroarr[z].x+2)||(msex/8+1)>=65&&(msex/8+1)<=70&&(msey/8+1)>=aroarr[z].x&&(msey/8+1)<=aroarr[z].x+2)
          {
            aroarr[z].colorV=2;
            if(mseb==1)
            {
              btnpressed=z;
              while(mseb==1)
              {
               movemouse();
	      }
              //printf("inside mseb");
              aroarr[z].colorV=2;
              //firstmouseclick=1;
              mousetimer=0;
            }
            else
            {
 	     btnpressed=0;
            }
            //printf("within mseb %d %d",btnpressed,z);
          }
          else
          {
           aroarr[z].colorV=7;
          }
        }
      }
      if(isfirst==0)
      {
       for(int i=0;i<=1;i++)
       {
        gotoxy(60,5+i*2);
        if(sm[i].secs<10&&sm[i].millis==0)
        printf("%d:0%d:00%d",sm[i].mins,sm[i].secs,sm[i].millis);
        else
        if(sm[i].secs>=10&&sm[i].millis==0)
        printf("%d:%d:00%d",sm[i].mins,sm[i].secs,sm[i].millis);
        else
        if(sm[i].secs<10&&sm[i].millis<100)
        printf("%d:0%d:0%d",sm[i].mins,sm[i].secs,sm[i].millis);
        else
        if(sm[i].secs>=10&&sm[i].millis<100)
        printf("%d:%d:0%d",sm[i].mins,sm[i].secs,sm[i].millis);
        else
        if(sm[i].secs<10&&sm[i].millis>=100)
        printf("%d:0%d:%d",sm[i].mins,sm[i].secs,sm[i].millis);
        else
        printf("%d:%d:%d",sm[i].mins,sm[i].secs,sm[i].millis);
       }
      }//end of isfirst block
     else
     {
      if(sm[wp].millis==0&&sm[wp].secs==0)
      {
      sm[wp].mins=sm[wp].mins-1;
      sm[wp].secs=59;
      sm[wp].millis=990;
      }
      else
      if(sm[wp].millis==0&&sm[wp].secs>0)
      {
       sm[wp].secs=sm[wp].secs-1;
       sm[wp].millis=990;
      }
      else
      if(sm[wp].millis>0)
      {
       sm[wp].millis=sm[wp].millis-10;
      }
      if(sm[wp].mins==0&&sm[wp].secs==0&&sm[wp].millis==0)
      {
       count=2;
      }
      for(int i=0;i<=1;i++)
      {
       gotoxy(60,5+i*2);
       if(sm[i].mins==0&&sm[i].secs==0&&sm[i].millis==0)
       printf("%d:0%d:00%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       if(sm[i].secs<10&&sm[i].millis==0)
       printf("%d:0%d:00%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       if(sm[i].secs>=10&&sm[i].millis==0)
       printf("%d:%d:00%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       if(sm[i].secs<10&&sm[i].millis<100)
       printf("%d:0%d:0%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       if(sm[i].secs>=10&&sm[i].millis<100)
       printf("%d:%d:0%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       if(sm[i].secs<10&&sm[i].millis>=100)
       printf("%d:0%d:%d",sm[i].mins,sm[i].secs,sm[i].millis);
       else
       printf("%d:%d:%d",sm[i].mins,sm[i].secs,sm[i].millis);
     }
       if(count==2)
       break;//when time ends
      delay(10);
      }
     }
     if(count==2)
     {
      timeends(wp);
     }
   }//end of timer with mouse input

   if(sa[8].colorV==0) //keyboard input
   {
    fflush(stdin);
    c=getch();
    //c=getch();
   }
   else
   if(sa[8].colorV==1)  //mouse input
   {
    if(mousetimer==0) //timer is off
    {
     setmouse();
     showmouse();
     while(allowmouse==1)
     {
       delay(50);
       showarrows();
       movemouse();
       for(int z=0;z<=9;z++)
        {
         if(z<=6)
         {
          if(aroarr[z].x==(msex/8+1)&&(msey/8+1)==3)
          {
           aroarr[z].colorV=4;
           if(mseb==1)
           {
             //printf("within mseb");
             //firstmouseclick=1;
             while(mseb==1)
             {
               movemouse();

	     }
             aroarr[z].colorV=2;
             allowmouse=0;
           }
          }
          else
          {
           aroarr[z].colorV=15;
          }
         }
         else
         if(z==7||z==8||z==9)
         {
          if((z==9&&(msex/8+1)>=65&&(msex/8+1)<=73&&(msey/8+1)>=aroarr[z].x&&(msey/8+1)<=aroarr[z].x+2)||(msex/8+1)>=65&&(msex/8+1)<=70&&(msey/8+1)>=aroarr[z].x&&(msey/8+1)<=aroarr[z].x+2)
          {
            aroarr[z].colorV=2;
            if(mseb==1)
            {
              btnpressed=z;
              while(mseb==1)
              {
               movemouse();
	      }
              aroarr[z].colorV=2;
              //firstmouseclick=1;
              allowmouse=0;
            }
            else
            {
 	     btnpressed=0;
            }
            //printf("within mseb %d %d",btnpressed,z);
          }
          else
          {
           aroarr[z].colorV=7;
          }
        }
       } //end of for
       //gotoxy(60,20);
       //cprintf(" %d,%d,%d",mseb,msex/8+1,msey/8+1);
     }//end of while
     //printf("outwhile");
    }
    if(btnpressed!=7&&btnpressed!=8&&btnpressed!=9)
    c=returnbutton();
    //printf(" %c %d",c,btnpressed);
    if(btnpressed==7)
    {
      deletemouse();
      c='m';
    }
    else
    if(btnpressed==8)
    {
     deletemouse();
     c='q';
    }
    else
    if(btnpressed==9)
    {
     c='p';
    }
    btnpressed=0;
   }

   if(c=='p')
   {
     openDown();
     disappear();
     first=1;
     stint=1;
     initiate();
     sm[0]=sm[1]=nochangesm[0];
     main();
   }
   else
   if(c=='q')
   {
    if(sa[8].colorV==1)
    deletemouse();
    exit(0);
   }
   else
   if(c=='m')
   {
    hidemouse();
    delay(10);
    clrscr();
    delay(10);
    first=0;
    stint=1;
    initiate();
    sm[0]=sm[1]=nochangesm[0];
    main();
   }
   //gotoxy(60,23);
   //printf("i m here");
  for(int i=0;i<=6;i++)
  {
    if(c==ch[i])
    {
     nm[i]++;
     if(nm[i]>=7)
     corrchar=0;
     else
     corrchar=1;
    }
  }
  if(corrchar!=0&&isfirst==0)
  {
   isfirst=1;
  }
  if(corrchar==0)
  {
    sound(800);
    delay(100);
    nosound();
  }
  corrchar=0;
  if(pc<=41)
  {
   if((c=='1'&&nm[0]<=6)||(c=='2'&&nm[1]<=6)||(c=='3'&&nm[2]<=6)||(c=='4'&&nm[3]<=6)||(c=='5'&&nm[4]<=6)||(c=='6'&&nm[5]<=6)||(c=='7'&&nm[6]<=6))
   {
      p=p+1;
      pc=pc+1; //play counter 42
     if(sa[9].colorV==0)
     {
      gotoxy(70,5);
      if(p%2==1)
      {
       textcolor(sa[5].colorV);
       cprintf("Player 2");
       }
      else
      {
       textcolor(sa[4].colorV);
       cprintf("Player 1");
      }
     }
     else
     {
      gotoxy(70,5);
      textcolor(sa[4].colorV);
      cprintf("Player 1");
      gotoxy(70,7);
      textcolor(sa[5].colorV);
      cprintf("Player 2");
     }
    for(int i=0;i<=6;i++)
    {
     if(c==ch[i])
     {
       cnt[i]++;
       if(p%2==1)
      g[i][(cnt[i]-1)]=1;
      else
      g[i][(cnt[i]-1)]=2;
      y=yv[cnt[i]-1];
      appear(4+8*i,y);
      i=6;
     }
    }
    tc=tc+1;
    hcomp(g,cor);
    vcomp(g,cor);
    ducomp(g,cor);
    ddcomp(g,cor);
    if(cor[0]==1||cor[1]==1||cor[2]==1||cor[3]==1)
    {
      leave();
    }
    else
   if(pc!=42)
    play();
    else
    {
      textcolor(14+128);
      gotoxy(60,7);
      cprintf("No one wins");
      leave();
     }
  }
  else
  if(pc!=42)
  play();
 }

}

void clear(int pumpOldX)
{
  gotoxy(pumpOldX,1);
  printf(" ");
  gotoxy(pumpOldX,2);
  printf(" ");
  if(pDir==1)
  {
   gotoxy(pumpOldX-2,3);
   printf(" ");
   gotoxy(pumpOldX-2,4);
   printf(" ");
  }
  else
  if(pDir==0)
  {
   gotoxy(pumpOldX+2,3);         -
   printf(" ");
   gotoxy(pumpOldX+2,4);
   printf(" ");
  }
}

void showpump()
{
   pumpOldX=5;
   gotoxy(5,1);
   textcolor(pumpC[1]);
   cprintf("%c",194);
   gotoxy(5,2);
   textcolor(pumpC[1]);
   cprintf("%c",179);
   for(int i=0;i<=1;i++)
   {
    gotoxy(1,1);
    gotoxy(3,i+3);
    textcolor(pumpC[0]);
    cprintf("%c%c%c%c%c",219,219,219,219,219);
   }
}

void movepump(int x)
{
  if(pumpOldX<x)
  pDir=1;
  else
  pDir=0;
  while(pumpSet==0)
  {
   //gotoxy(60,10);
   //printf("%d %d",pumpOldX,x);
   clear(pumpOldX);
   if(pumpOldX<x)
    {
     pDir=1;
     pumpOldX++;
    }
    if(pumpOldX>x)
    {
     pumpOldX--;
    }
    gotoxy(pumpOldX,1);
   textcolor(pumpC[1]);
   cprintf("%c",194);
   gotoxy(pumpOldX,2);
   textcolor(pumpC[1]);
   cprintf("%c",179);
   for(int i=0;i<=1;i++)
   {
    gotoxy(1,1);
    gotoxy(pumpOldX-2,i+3);
    textcolor(pumpC[0]);
    cprintf("%c%c%c%c%c",219,219,219,219,219);
   }
   delay(5);
  if(pumpOldX==x)
    {
      gotoxy(pumpOldX,1);
      printf(" ");
      gotoxy(pumpOldX,2);
      printf("%c",194);
      pumpSet=1;
      delay(100);
    }
   }
}

void showarrows()
{
  for(int arocnt=0;arocnt<=6;arocnt++)
  {
   gotoxy(aroarr[arocnt].x,3);
   textcolor(aroarr[arocnt].colorV);
   cprintf("%c",aroarr[arocnt].arrowchar);
  }
  for(int btncnt=7;btncnt<=9;btncnt++)
  {
    for(int btncounts=0;btncounts<=2;btncounts++)
    {
      if(btncnt==7)
      gotoxy(65,btncounts+11);
      else
      if(btncnt==8)
      gotoxy(65,btncounts+15);
      else
      if(btncnt==9)
      gotoxy(65,btncounts+19);
      textcolor(aroarr[btncnt].colorV);
      if(btncnt==7||btncnt==8)
      cprintf("%c%c%c%c%c%c",219,219,219,219,219,219);
      if(btncnt==9)
      cprintf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);
    }
    if(btncnt==7)
    gotoxy(66,12);
    else
    if(btncnt==8)
    gotoxy(66,16);
    if(btncnt==9)
    gotoxy(66,20);
    textbackground(aroarr[btncnt].colorV);
    textcolor(RED);
    if(btncnt==7)
    cprintf("Menu");
    else
    if(btncnt==8)
    cprintf("Quit");
    else
    cprintf("Restart");
    textbackground(BLACK);
  }
}

void openDown()
{
   //delay(50);
   //gotoxy(1,23);
   for(int i=23;i<=24;i++)
   {
    gotoxy(1,i);
    printf("                                                        ");
    gotoxy(1,i+1);
    printf("________________________________________________________");
    delay(200);
   }
   gotoxy(1,25);
   printf("                                                        ");
}

void disappear()
{
 void showDisappeared();

  for(int total=5;total>=0;total--)
  {
    for(int a=0;a<=6;a++)
    {
     gDis[a][0]=g[a][0];
    }
   for(int i=0;i<=4;i++)
   {
     for(int j=0;j<=6;j++)
     {
        g[j][i]=g[j][i+1];
     }
   }
   for(int n=0;n<=6;n++)
   {
    g[n][total]=0;
   }
   showDisappeared();
   delay(100);
  }
}

void showDisappeared()
{
  for(int x=0;x<=6;x++)
  {
    if(gDis[x][0]==0)
     {
      gotoxy(x*8+4,24);
      cprintf("   ");
      gotoxy(x*8+4,25);
      cprintf("   ");
     }
     else
     {
      if(gDis[x][0]==1)
      textcolor(sa[4].colorV);
      else
      if(gDis[x][0]==2)
      textcolor(sa[5].colorV);
      gotoxy(x*8+4,24);
      cprintf("%c%c%c",checkers[sa[7].colorV],checkers[sa[7].colorV],checkers[sa[7].colorV]);
      gotoxy(x*8+4,25);
      cprintf("%c%c%c",checkers[sa[7].colorV],checkers[sa[7].colorV],checkers[sa[7].colorV]);
     }
  }
  for(int i=0;i<=5;i++)
  {
   for(int j=0;j<=6;j++)
   {
     if(g[j][i]==0)
     {
      gotoxy(j*8+4,(5-i)*3+6);
      cprintf("   ");
      gotoxy(j*8+4,(5-i)*3+7);
      cprintf("   ");
     }
     else
     {
      if(g[j][i]==1)
      textcolor(sa[4].colorV);
      else
      if(g[j][i]==2)
      textcolor(sa[5].colorV);
      gotoxy(j*8+4,(5-i)*3+6);
      cprintf("%c%c%c",checkers[sa[7].colorV],checkers[sa[7].colorV],checkers[sa[7].colorV]);
      gotoxy(j*8+4,(5-i)*3+7);
      cprintf("%c%c%c",checkers[sa[7].colorV],checkers[sa[7].colorV],checkers[sa[7].colorV]);
     }
    }
  }
}

void appear(int x,int y)
{
  static int p=0;
  static int cn;
  if(sa[8].colorV==0)
  {
   pumpSet=0;
   movepump(x+1);
  }
  gotoxy(70,20);
  if(stint==2)
  {
   stint=0;
   p=0;
   cn=0;
  }
  cn=(y-3)/3;
  p++;
 if(p%2==1)
  {
   textcolor(sa[4].colorV);
  }
  else
  {
   textcolor(sa[5].colorV);
  }

 for(int i=1;i<=cn;i++)
   {
    gotoxy(x,i*3+3);
    cprintf("%c%c%c",checkers[sa[7].colorV],checkers[sa[7].colorV],checkers[sa[7].colorV]);
    gotoxy(x,i*3+4);
    cprintf("%c%c%c",checkers[sa[7].colorV],checkers[sa[7].colorV],checkers[sa[7].colorV]);
    delay(40);
    if(i<cn)
    {
     gotoxy(x,i*3+3);
     cprintf("   ");
     gotoxy(x,i*3+4);
     cprintf("   ");
    }
   }
   if(sa[8].colorV==0)
   {
    gotoxy(pumpOldX,1);
    printf("%c",194);
    gotoxy(pumpOldX,2);
    printf("%c",179);
   }
}

void timeends(int wp)
{
 gotoxy(65,9);
 if(wp==0)
 wp=2;
 textcolor(14+BLINK);
 cprintf("Player %d wins",wp);
 leave();
}

void leave()
 {
  void disappear();
  void openDown();
  char c;
  first=1;
  int almouse,bpressed;
  /*textcolor(WHITE);
  gotoxy(1,1);
  for(int w=0;w<=3;w++)
  {
   cprintf("                                                             ");
   printf("\n");
  }
  gotoxy(2,2);
  cprintf("Press p to play again");
  gotoxy(30,2);
  cprintf("Press q to quit");
  gotoxy(2,3);
  cprintf("Press m to go to main menu");
  //gotoxy(70,5);
  //printf("         ");

   textcolor(BLUE);
   gotoxy(65,13);
   cprintf("Play again p"); */
   fflush(stdin);
   if(sa[8].colorV==0)
   {
    c=getch();
   }
   else
   if(sa[8].colorV==1)
   {
    almouse=1;
    while(almouse==1)
    {
       delay(10);
       showarrows();
       showmouse();
       movemouse();
       for(int z=0;z<=9;z++)
        {
          if(z<=6)
          {
            aroarr[z].colorV=15;
          }
          else
          if((z==9&&(msex/8+1)>=65&&(msex/8+1)<=73&&(msey/8+1)>=aroarr[z].x&&(msey/8+1)<=aroarr[z].x+2)||(msex/8+1)>=65&&(msex/8+1)<=70&&(msey/8+1)>=aroarr[z].x&&(msey/8+1)<=aroarr[z].x+2)
          {
            aroarr[z].colorV=2;
            if(mseb==1)
            {
              bpressed=z;

              aroarr[z].colorV=2;
              //firstmouseclick=1;
              almouse=0;
            }
            else
            {
 	     bpressed=0;
            }
            //printf("within mseb %d %d",btnpressed,z);
          }
          else
          {
           aroarr[z].colorV=7;
          }
         }
       } //end of for
   }

   if(bpressed==7)
    {
      deletemouse();
      c='m';
    }
    else
    if(bpressed==8)
    {
     deletemouse();
     c='q';
    }
    else
    if(bpressed==9)
    {
     c='p';
    }
    bpressed=0;

   if(c=='p')
   {
    openDown();
    disappear();
    first=1;
    stint=1;
    initiate();
    sm[0]=sm[1]=nochangesm[0];
    main();
   }
   else
   if(c=='m')
   {
    clrscr();
    first=0;
    stint=1;
    initiate();
    sm[0]=sm[1]=nochangesm[0];
     main();
   }
   else
   if(c=='q')
   {
    fflush(stdin);
    clrscr();
    exit(0);
   }
   else
   leave();
}


