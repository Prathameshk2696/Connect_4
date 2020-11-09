

char rules()
{
  void rulescall();
  clrscr();
  textcolor(WHITE);
  rulescall();
  return getch();
}

void rulescall()
{
 gotoxy(5,5);
 textcolor(RED);
 cprintf("1 ");
 textcolor(WHITE);
 cprintf("Winner is the first player to get 4 checkers in a row");
 gotoxy(7,6);
 cprintf("either horizontally or vertically or diagonally");
 gotoxy(5,8);
 textcolor(RED);
 cprintf("2 ");
 textcolor(WHITE);
 cprintf("Press column number at the bottom of the frame");
 gotoxy(7,9);
 cprintf("in which you want to insert your checker");
 gotoxy(5,11);
 textcolor(RED);
 cprintf("3 ");
 textcolor(WHITE);
 cprintf("There can't be empty space below checker");
 textcolor(GREEN);
 gotoxy(5,13);
 cprintf("Press p to play");
 gotoxy(5,14);
 cprintf("Press any other key to go back");
}

