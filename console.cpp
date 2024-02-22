#include<iostream>
#include<windows.h>
#include <conio.h>

using namespace std;

int main(){
  char click = getch();
  printf("%c\n",click);
  if(click == '1') system("main");
  else if(click == '2') system("3Card");
  else if(click == '3') system("quizGame");
}
