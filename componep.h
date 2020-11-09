int hocomp(int g[7][6],int playerturn)
{
  int i,j,cnt;
  for(i=0;i<=5;i++)
  {
   for(j=0;j<=3;j++)
   {
    cnt=0;
      if((g[j][i]==playerturn)&&(g[j][i]==g[j+1][i])&&(g[j+1][i]==g[j+2][i])&&(g[j+2][i]==g[j+3][i]))
      {
	cnt=4*playerturn;
        return cnt;
      }
    }
   }
   return 0;
 }

int vocomp(int g[7][6],int playerturn)
{
 int cnt=0,i,j;
   for(i=0;i<=5;i++)
   {
    for(j=0;j<=2;j++)
    {
     cnt=0;
       if((g[i][j]==playerturn)&&(g[i][j]==g[i][j+1])&&(g[i][j+1]==g[i][j+2])&&(g[i][j+2]==g[i][j+3]))
       {
	cnt=4*playerturn;
        return cnt;
       }
    }
   }
   return 0;
 }

int duocomp(int g[7][6],int playerturn)
{
 int cnt=0,i,j;
   for(i=0;i<=3;i++)
   {
    for(j=0;j<=2;j++)
    {
     cnt=0;
       if((g[i][j]==playerturn)&&(g[i][j]==g[i+1][j+1])&&(g[i+1][j+1]==g[i+2][j+2])&&(g[i+2][j+2]==g[i+3][j+3]))
       {
	 cnt=4*playerturn;
         return cnt;
       }
    }
   }
   return 0;
 }

int ddocomp(int g[7][6],int playerturn)
{
 int cnt=0,i,j;
   for(i=0;i<=3;i++)
   {
    for(j=3;j<=5;j++)
    {
     cnt=0;
      if((g[i][j]==playerturn)&&(g[i][j]==g[i+1][j-1])&&(g[i+1][j-1]==g[i+2][j-2])&&(g[i+2][j-2]==g[i+3][j-3]))
      {
	cnt=4*playerturn;
        return cnt;
      }
    }
   }
   return 0;
 }

