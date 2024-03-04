#include<iostream>
#include<windows.h>
#include <conio.h>

using namespace std;

int main(){
  
/* ลงภาพ*/

  char click = getch();
  printf("%c\n",click);
  if(click == '1')
  {
  system("cls");
  system("Battle-Boss_game_01");
  } 
  else if(click == '2'){
    system("cls");
    system("3Card_game_02");
  }
  else if(click == '3'){
   system("cls");
  system("Quiz_game_03");
  }
  else {
    cout << "Invalid input";
    cout << "Please input again";
    system("cls");
    main();
  }
}
