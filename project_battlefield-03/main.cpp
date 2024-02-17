#include "library.h"
#include "game03.h"
#include "color.h"

using namespace std;

void condition(){
    textcolor(RED,RED);
     printf("Press button A to ATTACK\n");
     resetcolor();
    textcolor(GREEN,GREEN);
     printf("Press button Q to USE MEDKIT\n");
     resetcolor();
     resetcolor();
      textcolor(YELLOW ,YELLOW);
     printf("Press button G to USE GRENADE\n");
     resetcolor();
     textcolor( BLUE,BLUE);
     printf("Press button S to SAVE GAME\n");
     resetcolor();
     textcolor(VIOLET,VIOLET );
     printf("Press button L to BLOAD GAME\n");
     resetcolor();
     textcolor(WHITE,WHITE);
     printf("Press button E to EXIT GAME\n");
     resetcolor();
}


void terminal(){

    textcolor(DARKRED,DARKRED);
    printf( "---------------------------------------------------------------------------------------------------\n");
    printf("|                                                                                                   |\n");
    printf("|                                                                                                   |\n");
    printf("|                                    WELCOME TO BATTLE BOSS GAME 03                                 |\n"); 
    printf("|                                                                                                   |\n");
    printf("|                                          [1] PLAY GAME                                            |\n");
    printf("|                                                                                                   |\n");
    printf("|                                          [2] HOW TO PLAY                                          |\n");
    printf("|                                                                                                   |\n");
    printf("|                                          [E] EXIT                                                 |\n");
    printf("|                                                                                                   |\n");
    printf("|                                                                                                   |\n");
    printf( "---------------------------------------------------------------------------------------------------");
    resetcolor();

}

string chooose_mon(int count){ //เลือก mons ที่จะบวก
    string mons;
    if(count == 1) mons = "Monster01";
    else if(count == 2) mons = "Monster02";
    else if(count == 3) mons = "Monster03";
    else if(count == 4) mons = "Monster04";
    return mons;
}



char atkboss(char monster_action){//เช็ค monster action
   int ranAtkboss = rand()%10;
        if(ranAtkboss <= 8) monster_action == 'a';
        if(ranAtkboss > 8) monster_action == 'b';
    return monster_action;
}
