
/* the names of the text styles supported */
char *fname[] = { "CONNECT 4",
		  "CONNECT 4",
		  "CONNECT 4",
		  "CONNECT 4",
		  "CONNECT 4"
		};

void conpr()
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int style;
   int size = 1;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }


   settextjustify(CENTER_TEXT, CENTER_TEXT);

   /* loop through the available text styles */
      style=3;
      cleardevice();

	 size = 8;
      //	 printf("%d\n%d",midx,midy);
      /* select the text style */
      settextstyle(style, HORIZ_DIR, size);

      /* output a message */
      outtextxy(300, 200, fname[style]);

   /* clean up */

}

