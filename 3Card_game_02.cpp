#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <windows.h>

using namespace std;

void Frame(string Frame){
    int width = 170;
    for (int i = 0; i < width; i++) cout << Frame;
    cout << endl;
}
void Terminal(){
    int tall = 29;
    for(int i = 0; i < tall; i++) Frame(" ");
}

void ClearTerminal(int j){
    for(int i = 0; i < j; i++) cout << endl;
}
void CoutATK(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 12);	
    printf ("   ______________\n");
    printf ("  |              |\n");
    printf ("  |      /\\      |      Card name: Fury Strike\n");
    printf ("  |     |  |     |      Random damage from 20 - 50 point\n");
    printf ("  |   __|__|__   |      then strike to an enemy.\n");
    printf ("  |  |__|__|__|  |\n");
    printf ("  |     |__|     |\n");
    printf ("  |______________|\n");
    SetConsoleTextAttribute(color , 15);
    printf ("---Enter to continue---");
    cin.get();

}

void CoutShield(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 9);	
    printf ("   ______________\n");
    printf ("  |  __________  |\n");
    printf ("  | |  ______  | |      Card name: Damage Absolver\n");
    printf ("  | | |      | | |      can reduce damage from enemy\n");
    printf ("  | | |      | | |      in range 10 - 30 point.\n");
    printf ("  |  \\ \\ __ / /  |\n");
    printf ("  |   \\______/   |\n");
    printf ("  |______________|\n");
    SetConsoleTextAttribute(color , 15);
    printf ("---Enter to continue---");
    cin.get();
}

void CoutHeal(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 10);	
    printf ("   ______________\n");
    printf ("  |              |\n");
    printf ("  |      __      |      Card name: Healing\n");
    printf ("  |   __|  |__   |      can restore some Hp\n");
    printf ("  |  |__    __|  |      from 5 - 30 point\n");
    printf ("  |     |__|     |\n");
    printf ("  |              |\n");
    printf ("  |______________|\n");
    SetConsoleTextAttribute(color , 15);
    printf ("---Enter to continue---");
    cin.get();
}

void TerminalDefault(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 1);
    printf ("                   __     ______________                                                                                    ___      ________             \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |\\/|   /______________\\                                                                                   |||     /        \\         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |  |     |  __  __  |                                                                                     | |    |  /\\  /\\  |         \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |  |\\__  |  \\/__\\/  |                                                                                    _|_|_   |   ____   |        \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |______|  \\________/                                                                                    |_____|   \\________/      _   \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                     |______/  _\\/_  \\________                                                                              |_|_____/        \\_____|_| \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           |  /    \\  |    _|_|_                                                                                   |          |          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           |  \\____/  |   |_ _ _|                                                                                  |          |          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                            \\________/      | |                                                                                     \\________/          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                             ||    ||       | |                                                                                      ||    ||             \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                             ||    ||       \\ /                                                                                    __||    ||__          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           /_\\|    |/_\\                                                                                           |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}


void TerminalHH(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 11);
    printf ("                   __     ______________                                                                                    ___      ________             \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |\\/|   /______________\\                                                                                   |||     /        \\         \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |  |     |  __  __  |                   ______________                          ______________            | |    |  /\\  /\\  |         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |  |\\__  |  \\/__\\/  |                  |              |                        |              |          _|_|_   |   ____   |        \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |______|  \\________/                   |      __      |                        |      __      |         |_____|   \\________/      _   \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                     |______/  _\\/_  \\________           |   __|  |__   |                        |   __|  |__   |           |_|_____/        \\_____|_| \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           |  /    \\  |    _|_|_         |  |__    __|  |                        |  |__    __|  |                  |          |          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           |  \\____/  |   |_ _ _|        |     |__|     |                        |     |__|     |                  |          |          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                            \\________/      | |          |              |                        |              |                   \\________/          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                             ||    ||       | |          |______________|                        |______________|                    ||    ||             \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                             ||    ||       \\ /                                                                                    __||    ||__          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           /_\\|    |/_\\                                                                                           |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}


void TerminalHA(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 1);
    printf ("                   __     ______________                                                                                    ___      ________             \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |\\/|   /______________\\                                                                                   |||     /        \\         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |  |     |  __  __  |                   ______________                          ______________            | |    |  /\\  /\\  |         \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |  |\\__  |  \\/__\\/  |                  |              |                        |              |          _|_|_   |   ____   |        \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |______|  \\________/                   |      __      |                        |      /\\      |         |_____|   \\________/      _  \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                     |______/  _\\/_  \\________           |   __|  |__   |                        |     |  |     |           |_|_____/        \\_____|_| \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           |  /    \\  |    _|_|_         |  |__    __|  |                        |   __|__|__   |                  |          |          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           |  \\____/  |   |_ _ _|        |     |__|     |                        |  |__|__|__|  |                  |          |          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                            \\________/      | |          |              |                        |     |__|     |                   \\________/          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                             ||    ||       | |          |______________|                        |______________|                    ||    ||             \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                             ||    ||       \\ /                                                                                    __||    ||__          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           /_\\|    |/_\\                                                                                           |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}

void TerminalHS(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 11);
    printf ("                   __     ______________                                                                                    ___      ________             \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |\\/|   /______________\\                                                                                   |||     /        \\         \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |  |     |  __  __  |                   ______________                          ______________            | |    |  /\\  /\\  |         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |  |\\__  |  \\/__\\/  |                  |              |                        |  __________  |          _|_|_   |   ____   |        \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |______|  \\________/                   |      __      |                        | |  ______  | |         |_____|   \\________/      _   \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                     |______/  _\\/_  \\________           |   __|  |__   |                        | | |      | | |           |_|_____/        \\_____|_| \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           |  /    \\  |    _|_|_         |  |__    __|  |                        | | |      | | |                  |          |          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           |  \\____/  |   |_ _ _|        |     |__|     |                        |  \\ \\ __ / /  |                  |          |        \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                            \\________/      | |          |              |                        |   \\______/   |                   \\________/         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                             ||    ||       | |          |______________|                        |______________|                    ||    ||             \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                             ||    ||       \\ /                                                                                    __||    ||__          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           /_\\|    |/_\\                                                                                           |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}



void TerminalAH(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 1);
    printf ("                   __     ______________                                                                                    ___      ________             \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |\\/|   /______________\\                                                                                   |||     /        \\         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |  |     |  __  __  |                   ______________                          ______________            | |    |  /\\  /\\  |         \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |  |\\__  |  \\/__\\/  |                  |              |                        |              |          _|_|_   |   ____   |        \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |______|  \\________/                   |      /\\      |                        |      __      |         |_____|   \\________/      _  \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                     |______/  _\\/_  \\________           |     |  |     |                        |   __|  |__   |           |_|_____/        \\_____|_| \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           |  /    \\  |    _|_|_         |   __|__|__   |                        |  |__    __|  |                  |          |          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           |  \\____/  |   |_ _ _|        |  |__|__|__|  |                        |     |__|     |                  |          |          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                            \\________/      | |          |     |__|     |                        |              |                   \\________/          \n");
    SetConsoleTextAttribute(color , 11);      
    printf ("                             ||    ||       | |          |______________|                        |______________|                    ||    ||             \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                             ||    ||       \\ /                                                                                    __||    ||__          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           /_\\|    |/_\\                                                                                           |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}

void TerminalAA(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 11);
    printf ("                   __     ______________                                                                                   ___      ________              \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |\\/|   /______________\\                                                                                  |||     /        \\          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |  |     |  __  __  |                   ______________                          ______________           | |    |  /\\  /\\  |          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |  |\\__  |  \\/__\\/  |                  |              |                        |              |         _|_|_   |   ____   |         \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |______|  \\________/                   |      /\\      |                        |      /\\      |        |_____|   \\________/      _  \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                     |______/  _\\/_  \\________           |     |  |     |                        |     |  |     |          |_|_____/        \\_____|_|  \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           |  /    \\  |    _|_|_         |   __|__|__   |                        |   __|__|__   |                 |          |           \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           |  \\____/  |   |_ _ _|        |  |__|__|__|  |                        |  |__|__|__|  |                 |          |           \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                            \\________/      | |          |     |__|     |                        |     |__|     |                  \\________/           \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                             ||    ||       | |          |______________|                        |______________|                   ||    ||              \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                             ||    ||       \\ /                                                                                   __||    ||__           \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           /_\\|    |/_\\                                                                                          |___|    |___|         \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}

void TerminalAS(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 1);
    printf ("                   __     ______________                                                                                   ___      ________              \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |\\/|   /______________\\                                                                                  |||     /        \\          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |  |     |  __  __  |                   ______________                          ______________           | |    |  /\\  /\\  |          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |  |\\__  |  \\/__\\/  |                  |              |                        |  __________  |         _|_|_   |   ____   |         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |______|  \\________/                   |      /\\      |                        | |  ______  | |        |_____|   \\________/      _   \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                     |______/  _\\/_  \\________           |     |  |     |                        | | |      | | |          |_|_____/        \\_____|_|  \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           |  /    \\  |    _|_|_         |   __|__|__   |                        | | |      | | |                 |          |           \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           |  \\____/  |   |_ _ _|        |  |__|__|__|  |                        |  \\ \\ __ / /  |                 |          |         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                            \\________/      | |          |     |__|     |                        |   \\______/   |                  \\________/          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                             ||    ||       | |          |______________|                        |______________|                   ||    ||              \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                             ||    ||       \\ /                                                                                   __||    ||__           \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           /_\\|    |/_\\                                                                                          |___|    |___|         \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}

void TerminalSH(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 11);
    printf ("                   __     ______________                                                                                   ___      ________             \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |\\/|   /______________\\                                                                                  |||     /        \\         \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |  |     |  __  __  |                   ______________                          ______________           | |    |  /\\  /\\  |         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |  |\\__  |  \\/__\\/  |                  |  __________  |                        |              |         _|_|_   |   ____   |        \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |______|  \\________/                   | |  ______  | |                        |      __      |        |_____|   \\________/      _   \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                     |______/  _\\/_  \\________           | | |      | | |                        |   __|  |__   |          |_|_____/        \\_____|_| \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           |  /    \\  |    _|_|_         | | |      | | |                        |  |__    __|  |                 |          |          \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           |  \\____/  |   |_ _ _|        |  \\ \\ __ / /  |                        |     |__|     |                 |          |        \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                            \\________/      | |          |   \\______/   |                        |              |                  \\________/         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                             ||    ||       | |          |______________|                        |______________|                   ||    ||             \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                             ||    ||       \\ /                                                                                   __||    ||__          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           /_\\|    |/_\\                                                                                          |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}

void TerminalSA(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 1);
    printf ("                   __     ______________                                                                                   ___      ________             \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |\\/|   /______________\\                                                                                  |||     /        \\         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |  |     |  __  __  |                   ______________                          ______________           | |    |  /\\  /\\  |         \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |  |\\__  |  \\/__\\/  |                  |  __________  |                        |              |         _|_|_   |   ____   |        \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |______|  \\________/                   | |  ______  | |                        |      /\\      |        |_____|   \\________/      _  \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                     |______/  _\\/_  \\________           | | |      | | |                        |     |  |     |          |_|_____/        \\_____|_| \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           |  /    \\  |    _|_|_         | | |      | | |                        |   __|__|__   |                 |          |          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           |  \\____/  |   |_ _ _|        |  \\ \\ __ / /  |                        |  |__|__|__|  |                 |          |        \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                            \\________/      | |          |   \\______/   |                        |     |__|     |                  \\________/         \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                             ||    ||       | |          |______________|                        |______________|                   ||    ||             \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                             ||    ||       \\ /                                                                                   __||    ||__          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           /_\\|    |/_\\                                                                                          |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}

void TerminalSS(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 11);
    printf ("                   __     ______________                                                                                   ___      ________             \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |\\/|   /______________\\                                                                                  |||     /        \\         \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |  |     |  __  __  |                   ______________                          ______________           | |    |  /\\  /\\  |         \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                  |  |\\__  |  \\/__\\/  |                  |  __________  |                        |  __________  |         _|_|_   |   ____   |        \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                  |______|  \\________/                   | |  ______  | |                        | |  ______  | |        |_____|   \\________/      _   \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                     |______/  _\\/_  \\________           | | |      | | |                        | | |      | | |          |_|_____/        \\_____|_| \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                           |  /    \\  |    _|_|_         | | |      | | |                        | | |      | | |                 |          |          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           |  \\____/  |   |_ _ _|        |  \\ \\ __ / /  |                        |  \\ \\ __ / /  |                 |          |      \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                            \\________/      | |          |   \\______/   |                        |   \\______/   |                  \\________/        \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                             ||    ||       | |          |______________|                        |______________|                   ||    ||             \n");
    SetConsoleTextAttribute(color , 1);
    printf ("                             ||    ||       \\ /                                                                                   __||    ||__          \n");
    SetConsoleTextAttribute(color , 11);
    printf ("                           /_\\|    |/_\\                                                                                          |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}

// add used card action: 
//  Nothing , Atk
void TerminalNA(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 12);
    printf ("                   __     ______________                                                                                    ___      ________             \n");
    printf ("                  |\\/|   /______________\\                                                                                   |||     /        \\         \n");
    printf ("                  |  |     |  __  __  |                                                           ______________            | |    |  /\\  /\\  |         \n");
    printf ("                  |  |\\__  |    O__O  |                                                          |              |          _|_|_   |   ____   |          \n");
    printf ("                  |______|  \\________/                                                           |      /\\      |         |_____|   \\________/      _  \n");
    printf ("                     |______/  _\\/_  \\________                                                   |     |  |     |           |_|_____/        \\_____|_| \n");
    printf ("                           |  /    \\  |    _|_|_                                                 |   __|__|__   |                  |          |          \n");
    printf ("                           |  \\____/  |   |_ _ _|                                                |  |__|__|__|  |                  |          |          \n");
    printf ("                            \\________/      | |                                                  |     |__|     |                   \\________/          \n");
    printf ("                             ||    ||       | |                                                  |______________|                    ||    ||             \n");
    printf ("                             ||    ||       \\ /                                                                                    __||    ||__          \n");
    printf ("                           /_\\|    |/_\\                                                                                           |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}

// Nothing , Shield
void TerminalNS(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 12);
    printf ("                   __     ______________                                                                                    ___      ________             \n");
    printf ("                  |\\/|   /______________\\                                                                                   |||     /        \\         \n");
    printf ("                  |  |     |  __  __  |                                                           ______________            | |    |  /\\  /\\  |         \n");
    printf ("                  |  |\\__  |    O__O  |                                                          |  __________  |          _|_|_   |   ____   |          \n");
    printf ("                  |______|  \\________/                                                           | |  ______  | |         |_____|   \\________/      _   \n");
    printf ("                     |______/  _\\/_  \\________                                                   | | |      | | |           |_|_____/        \\_____|_| \n");
    printf ("                           |  /    \\  |    _|_|_                                                 | | |      | | |                  |          |          \n");
    printf ("                           |  \\____/  |   |_ _ _|                                                |  \\ \\ __ / /  |                  |          |        \n");
    printf ("                            \\________/      | |                                                  |   \\______/   |                   \\________/         \n");
    printf ("                             ||    ||       | |                                                  |______________|                    ||    ||             \n");
    printf ("                             ||    ||       \\ /                                                                                    __||    ||__          \n");
    printf ("                           /_\\|    |/_\\                                                                                           |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}

// Nothing , Heal
void TerminalNH(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 12);
    printf ("                   __     ______________                                                                                    ___      ________             \n");
    printf ("                  |\\/|   /______________\\                                                                                   |||     /        \\         \n");
    printf ("                  |  |     |  __  __  |                                                           ______________            | |    |  /\\  /\\  |         \n");
    printf ("                  |  |\\__  |    O__O  |                                                          |              |          _|_|_   |   ____   |          \n");
    printf ("                  |______|  \\________/                                                           |      __      |         |_____|   \\________/      _   \n");
    printf ("                     |______/  _\\/_  \\________                                                   |   __|  |__   |           |_|_____/        \\_____|_| \n");
    printf ("                           |  /    \\  |    _|_|_                                                 |  |__    __|  |                  |          |          \n");
    printf ("                           |  \\____/  |   |_ _ _|                                                |     |__|     |                  |          |          \n");
    printf ("                            \\________/      | |                                                  |              |                   \\________/          \n");
    printf ("                             ||    ||       | |                                                  |______________|                    ||    ||             \n");
    printf ("                             ||    ||       \\ /                                                                                    __||    ||__          \n");
    printf ("                           /_\\|    |/_\\                                                                                           |___|    |___|        \n");
    SetConsoleTextAttribute(color , 15);
    cout << endl;
}

void TerminalSeclection(int Pact, int Bact){
    // atk
    if(Pact == 1 && Bact == 1) TerminalAA();
    if(Pact == 1 && Bact == 2) TerminalAS();
    if(Pact == 1 && Bact == 3) TerminalAH();

    //def
    if(Pact == 2 && Bact == 1) TerminalSA();
    if(Pact == 2 && Bact == 2) TerminalSS();
    if(Pact == 2 && Bact == 3) TerminalSH();

    //heal
    if(Pact == 3 && Bact == 1) TerminalHA();
    if(Pact == 3 && Bact == 2) TerminalHS();
    if(Pact == 3 && Bact == 3) TerminalHH();

    //used
    if(Pact == 0 && Bact == 1) TerminalNA();
    if(Pact == 0 && Bact == 2) TerminalNS();
    if(Pact == 0 && Bact == 3) TerminalNH();

}
int main2(){
}