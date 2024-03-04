#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "Unitbattleboss.cpp"
#include <windows.h>

using namespace std;
char *Heroname;
string Hero;
void GameStart();

void GetEnter();
// void CreateBoss();
void AskPlayerName();
void ShowHowToplay();
void ShowMap();
string toUpperStr(string);
void FightBoss(Player &, Boss &);
void ShowFightPhase();
Boss Dummy1("Dummy1", rand() % 5 + 30, rand() % 4 + 10, rand() % 2 + 1, 200);
Boss Dummy2("Dummy2", rand() % 5 + 100, rand() % 8 + 12, rand() % 2 + 3, 400);
Boss Dummy3("Dummy3", rand() % 6 + 130, rand() % 10 + 17, rand() % 3 + 10, 1200);
Boss Dummy4("Dummy4", rand() % 10 + 450, rand() % 12 + 22, rand() % 10 + 32,2000);
string name;

int levelStage = 1;
Player Player1("");

int main()
{
    srand(time(0));

    GameStart();

    if (Player1.getname() == "")
        AskPlayerName();
    cout << setw(62) << "Hi Player : " << Hero << endl;
    Player1.setname(name);
    GetEnter();
    ShowHowToplay();
    while(levelStage < 5){
    Player1.GobuyPhase();
    // Modify to read file to save current in future
    ShowMap();
    GetEnter();
    system("cls");
    if (levelStage == 1)
        FightBoss(Player1, Dummy1);
    else if (levelStage == 2)
        FightBoss(Player1, Dummy2);
    else if (levelStage == 2)
        FightBoss(Player1, Dummy2);
    else if (levelStage == 3)
        FightBoss(Player1, Dummy3);
    else if (levelStage == 4)
        FightBoss(Player1, Dummy4);
   if (Player1.isDead)
    {
        Player1.hp = Player1.hpmax;
        if (levelStage == 1) Dummy1.hp = Dummy1.hpmax;
        if (levelStage == 2) Dummy2.hp = Dummy2.hpmax;
        if (levelStage == 3) Dummy3.hp = Dummy3.hpmax;
        if (levelStage == 4) Dummy4.hp = Dummy4.hpmax;
        main();
    }
    }
}

string toUpperStr(string x)
{
    string y = x;
    for (unsigned i = 0; i < x.size(); i++)
        y[i] = toupper(x[i]);
    return y;
}
void AskPlayerName()
{
    cout << setw(62) << "Enter Your Name : ";
    getline(cin,Hero);
    const char* Heroname = Hero.c_str();
    
    name = Hero;
    system("cls");//clear terminal
}
void GameStart()
{
/* ลงภาพ*/
}

//อธิบายการเล่นคร่าวๆ
void tutorial(){

/* ลงภาพ*/

}


void GetEnter()
{
    cout << setw(70) << "Press Enter To go next";
    cin.get();
    system("cls");
}

void ShowHowToplay()
{
    tutorial();
   //อธิบายการเล่น
    GetEnter();
}
void ShowMap()
{
    if (levelStage == 1)
    {
        // map in game stage 1
/* ลงภาพ*/
    }
    if (levelStage == 2)
    {
        // map in game stage 2
/* ลงภาพ*/
    }
   if (levelStage == 3)
    {
        // map in game stage 3
/* ลงภาพ*/
    }
    if (levelStage == 4)
    {
        // map in game stage 4
/* ลงภาพ*/
    }
}
void buttonaction(string &action){
    char click = getch();
    printf("%c\n",click);
    if(click == 'a'){ 
        action = 'A';
        }
    else if(click == 'q'){
        action = 'Q';
    } 
    else if(click == 'g'){ 
        action = 'G';
    }
    else if(click == 'e') action = 'E';
    else action = 't';
}
void FightBoss(Player &Player1, Boss &Boss)
{
    string action;
    bool FightPhase = true;
    Player1.hp = Player1.hpmax;
    while (FightPhase)
    {
        ShowFightPhase();
        //cin >> action;
        //action = toUpperStr(action);
        buttonaction(action);
        if (action == "A")
        {
            Player1.attack(Boss);
            system("cls");
        }
        else if (action == "G")
        {
            Player1.useGrenade(Boss);
            if (Player1.grenade == 0)
                continue;
        }
        else if (action == "Q")
        {
            Player1.useMedkit();
            if (Player1.medkit == 0)
                continue;//ไม่ให้ถูกโจมตี
        }
        else if (action == "E")
        {
            cout << "exiting....";
            main();
        }
        else
        {
            cout << "Wrong input" << endl;
            cin.ignore();
            GetEnter();
            continue; // Continue the loop instead of recursive call
        }

        if (Boss.CheckDead())
        {
            FightPhase = false;
            Player1.playerWin(levelStage);
            levelStage++;
            Player1.addmoney(Boss.money);

            cin.ignore();
            GetEnter();
        }
        Boss.attack(Player1);

        if (Player1.CheckDead())
        {
            FightPhase = false;
            Player1.playerLose();
            cin.ignore();
            GetEnter();
        }
    }
}


void ShowFightPhase(){

    if (levelStage == 1 && !Player1.isAK && !Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy1.hp < 0) Dummy1.hp = 0;
/* ลงภาพ*/
    }
    else if (levelStage == 1 && !Player1.isAK && Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy1.hp < 0) Dummy1.hp = 0;
/* ลงภาพ*/
    }
    else if (levelStage == 1 && Player1.isAK)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy1.hp < 0) Dummy1.hp = 0;
   /* ลงภาพ*/
    }
    else if (levelStage == 2 && !Player1.isAK && !Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy2.hp < 0) Dummy2.hp = 0;
/* ลงภาพ*/
    }
     else if (levelStage == 2 && !Player1.isAK && Player1.isPistol)
    {
         if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy2.hp < 0) Dummy2.hp = 0;
/* ลงภาพ*/
}
     else if (levelStage == 2 && Player1.isAK )
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy2.hp < 0) Dummy2.hp = 0;
    //เติม case stage 2 player มี AK
/* ลงภาพ*/
}
     else if (levelStage == 3 && !Player1.isAK && !Player1.isPistol)
    {
         if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy3.hp < 0) Dummy3.hp = 0;
   //เติม case stage 3 player ถือ มีด
/* ลงภาพ*/
}
else if (levelStage == 3 && !Player1.isAK && Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy3.hp < 0) Dummy3.hp = 0;
/* ลงภาพ*/
}


else if (levelStage == 3 && Player1.isAK)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy3.hp < 0) Dummy3.hp = 0;
/* ลงภาพ*/
}
else if (levelStage == 4 && !Player1.isAK && !Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy4.hp < 0) Dummy4.hp = 0;
    //เติม case stage 4 player ถือ มีด
/* ลงภาพ*/
}
else if (levelStage == 4 && !Player1.isAK && Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy4.hp < 0) Dummy4.hp = 0;
/* ลงภาพ*/
}
else if (levelStage == 4 && Player1.isAK)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy4.hp < 0) Dummy4.hp = 0;
/* ลงภาพ*/
}

}
