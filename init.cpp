
 void appear(int,int);
 void play(),leave();
 void comp();
 int cnt[7]={0,0,0,0,0,0,0};
 int yv[6]={21,18,15,12,9,6};
 char ch[7]={'1','2','3','4','5','6','7'};
 int g[7][6];
 int cor[4]={0,0,0,0};



 struct Fields
 {
  char name[20];
  int colorV;
  int y;
 };

 struct Mytime
 {
   int mins,secs,millis;
   int cmins,csecs,cmillis; // their colors
   char name[10];
   int y;
 };

 struct Fields sa[12];//struct array
 struct Mytime sm[2];
 struct Mytime nochangesm[2];

 void start();

 void initFields()
 {
  initarrow();
  sm[0].mins=sm[1].mins=5;
  sm[0].secs=sm[1].secs=0;
  sm[0].millis=sm[1].millis=0;
  sm[0].cmins=sm[1].cmins=15;
  sm[0].csecs=sm[1].csecs=15;
  sm[0].cmillis=sm[1].cmillis=15;
  strcpy(sm[0].name,"Set Time");
  strcpy(sm[1].name,"Set Time");
  sm[0].y=sm[1].y=23;
  strcpy(sa[0].name,"Press p to play");
  sa[0].y=3;
  strcpy(sa[1].name,"Press q to quit");
  sa[1].y=5;
  strcpy(sa[2].name,"Press r for rules");
  sa[2].y=7;
  strcpy(sa[3].name,"Frame");
  sa[3].colorV=15;
  sa[3].y=9;
  strcpy(sa[4].name,"Player 1");
  sa[4].colorV=2;
  sa[4].y=11;
  strcpy(sa[5].name,"Player 2");
  sa[5].colorV=4;
  sa[5].y=13;
  strcpy(sa[6].name,"Preview");
  sa[6].colorV=0;
  sa[6].y=15;
  strcpy(sa[7].name,"Checker");
  sa[7].colorV=0;
  sa[7].y=17;
  strcpy(sa[8].name,"Input Mode");
  sa[8].colorV=0;
  sa[8].y=19;
  strcpy(sa[9].name,"Timer");
  sa[9].colorV=0;
  sa[9].y=21;
  strcpy(sa[10].name,"No of Players");
  sa[10].colorV=0;
  sa[10].y=21;
  strcpy(sa[11].name,"Variation");
  sa[11].colorV=0;
  sa[11].y=23;
 }

void initiate()
{
  int i,j;
  extern int cnt[7];
  extern int g[7][6];
  extern int cor[4];
  for(i=0;i<=6;i++)
  cnt[i]=0;
  for(i=0;i<=3;i++)
  cor[i]=0;
  for(i=0;i<=6;i++)
  for(j=0;j<=5;j++)
  g[i][j]=0;
}