
void urect();
void vrect();
void crect();
void drect();

void rect(int colorFrame)
{
 int i;
 char ch[7]={'1','2','3','4','5','6','7'};
 textcolor(colorFrame);
 urect();
 for(i=0;i<=4;i++)
 {
  vrect();
  vrect();
  crect();
 }
 vrect();
 vrect();
 drect();
 printf("\n");
  for(i=0;i<=6;i++)
  {
   cprintf("    %c   ",ch[i]);
  }
}

void urect()
{
 int i,j;
  printf("\n\n\n\n");
  for(i=3;i<=59;i++)
  {
    if(i==3)
    cprintf("%c",218);
    else
    if(i==59)
    cprintf("%c",191);
    else
    if(i%8==3)
    cprintf("%c",194);
    else
    cprintf("%c",196);
  }
}

void vrect()
{
  int i,j;
  printf("\n");
  for(i=3;i<=59;i++)
  {
   if(i%8==3)
   cprintf("%c",179);
   else
   cprintf(" ");
  }
}

void crect()
{
 int i,j;
  printf("\n");
  for(i=3;i<=59;i++)
  {
   if(i==3)
   cprintf("%c",195);
   else
   if(i==59)
   cprintf("%c",180);
   else
   if(i%8==3)
   cprintf("%c",197);
   else
   cprintf("%c",196);
  }
}

void drect()
{
 int i,j;
  printf("\n");
  for(i=3;i<=59;i++)
  {
    if(i==3)
    cprintf("%c",192);
    else
    if(i==59)
    cprintf("%c",217);
    else
    if(i%8==3)
    cprintf("%c",193);
    else
    cprintf("%c",196);
  }
}