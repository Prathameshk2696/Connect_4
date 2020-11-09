
struct Arrows
 {
  char arrowchar;
  int colorV;
  int x;
 };

 struct Arrows aroarr[10];

 void initarrow()
 {
  for(int acn=0;acn<=9;acn++)
   {
    if(acn<=6) //arrows
    {
     aroarr[acn].arrowchar=219;
     aroarr[acn].colorV=15;
     aroarr[acn].x=(acn*8)+5;
    }
    else
    if(acn==7)
    {
     aroarr[acn].arrowchar='m';
     aroarr[acn].colorV=7;
     aroarr[acn].x=11;
    }
    else
    if(acn==8)
    {
     aroarr[acn].arrowchar='q';
     aroarr[acn].colorV=7;
     aroarr[acn].x=15;
    }
    else
    if(acn==9)
    {
     aroarr[acn].arrowchar='p';
     aroarr[acn].colorV=7;
     aroarr[acn].x=19;
    }
   }
  }