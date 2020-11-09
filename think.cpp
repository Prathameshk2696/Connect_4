
void thinkframe()
{
 gotoxy(63,12);
 printf("%c",218);
 printf("%c%c%c%c%c%c%c",196,196,196,196,196,196,196);
 printf("%c",191);
 gotoxy(63,13);
 printf("%c",179);
 gotoxy(71,13);
 printf("%c",179);
 gotoxy(63,14);
 printf("%c",192);
 printf("%c%c%c%c%c%c%c",196,196,196,196,196,196,196);
 printf("%c",217);
}

int xp=64;

void printthinknext()
{
   gotoxy(xp,13);
   textcolor(RED);
   cprintf("%c",219);
   xp++;
}

void removethinknext()
{
  xp=64;
  gotoxy(64,13);
  printf("       ");
}

