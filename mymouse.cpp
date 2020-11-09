
union REGS i,o;
int msex=0,msey=0;
int mseb=0;
//static int waszero=1;
//static int firstmouseclick=0;
int prevx;


void showmouse()
{
 i.x.ax=1;
 int86(0x33,&i,&o);
}

void movemouse()
{
 i.x.ax=3;
 //gotoxy(60,19);
 //printf("%d",o.x.bx);
 //prevx=o.x.bx;
 int86(0x33,&i,&o);
 //printf(" %d",o.x.bx);
 /*if(prevx!=o.x.bx&&firstmouseclick==0)
 {
  o.x.bx=0;
 }
 else
 if(prevx==o.x.bx&&firstmouseclick==0)
 {
  firstmouseclick=1;  //interrpur working well
 }                 */
 mseb=o.x.bx;
 msex=o.x.cx;
 msey=o.x.dx;
}

void setmouse()
{
i.x.ax=4;
i.x.bx=0;
i.x.cx=msex;
i.x.dx=msey;
int86(0x33,&i,&o);
}

void deletemouse()
{
 int count=0;
 while(count<=5)
 {
  movemouse();
  count++;
  delay(10);
 }
}

void hidemouse()
{
 i.x.ax=2;
 int86(0x33,&i,&o);
}

int mousepressed()
{
 i.x.ax=5;
 i.x.bx=0;
 int86(0x33,&i,&o);
 mseb=o.x.bx;
 return mseb;
}


