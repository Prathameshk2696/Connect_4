

int lux=20,luy=5;
int themearr[6][7]={{1,2,2,2,1},{0,2,1,1},{0,1,2,2},{0,1}};
int color[2];
int frameC;
int checkernum;

void drawTheme(int x,int y,int c1,int c2,int framecolor,int checkern)
{
  clrscr();
  lux=x;
  luy=y;
  frameC=framecolor;
  checkernum=checkern;
  color[0]=c1;
  color[1]=c2;
  void urects();
  void vrects();
  void crects();
  void drects();
  void drawCheckers();
  textcolor(frameC);
  urects();
 for(int i=0;i<=4;i++)
 {
  vrects();
  crects();
 }
 vrects();
 drects();
 drawCheckers();
}

void urects()
{
 int i,j;
  gotoxy(lux,luy);
  for(i=3;i<=38;i++) //31
  {
    if(i==3)
    cprintf("%c",218);
    else
    if(i==38)
    cprintf("%c",191);
    else
    if(i%5==3)
    cprintf("%c",194);
    else
    cprintf("%c",196);
  }
}

void vrects()
{
  int i,j;
  luy++;
  gotoxy(lux,luy);
  for(i=3;i<=38;i++)
  {
   if(i%5==3)
   cprintf("%c",179);
   else
   cprintf(" ");
  }
}

void crects()
{
 int i,j;
  luy++;
  gotoxy(lux,luy);
  for(i=3;i<=38;i++)
  {
   if(i==3)
   cprintf("%c",195);
   else
   if(i==38)
   cprintf("%c",180);
   else
   if(i%5==3)
   cprintf("%c",197);
   else
   cprintf("%c",196);
  }
}

void drects()
{
 int i,j;
  luy++;
  gotoxy(lux,luy);
  for(i=3;i<=38;i++)
  {
    if(i==3)
    cprintf("%c",192);
    else
    if(i==38)
    cprintf("%c",217);
    else
    if(i%5==3)
    cprintf("%c",193);
    else
    cprintf("%c",196);
  }
}

void drawCheckers()
{
  for(int i=0;i<=5;i++)
  {
   for(int j=0;j<=6;j++)
   {
    gotoxy(42+j*5,18-i*2);
    if(themearr[i][j]==1)
    textcolor(color[0]);
    if(themearr[i][j]==2)
    textcolor(color[1]);
    if(themearr[i][j]==1||themearr[i][j]==2)
    cprintf("%c%c",checkernum,checkernum);
   }
  }
}
