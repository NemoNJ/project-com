#include <windows.h>

#define BLACK          0
#define DARKBLUE       1
#define DARKGREEN      2
#define AQUA           3
#define DARKRED        4
#define DARKVOILET     5
#define DARKYELLOW     6
#define GRAY           7
#define DARKGRAY       8
#define BLUE           9
#define GREEN          10
#define CYAN           11
#define RED            12
#define VIOLET         13
#define YELLOW         14
#define WHITE          15

#define textcolor(txt,back) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back*16+txt)
#define resetcolor() SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)