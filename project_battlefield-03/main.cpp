#include "game03.h"
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include <cmath>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;
void condition(){

     printf("Press button A to ATTACK\n");
 
     printf("Press button Q to USE MEDKIT\n");

     printf("Press button G to USE GRENADE\n");

     printf("Press button S to SAVE GAME\n");

     printf("Press button L to BLOAD GAME\n");

     printf("Press button E to EXIT GAME\n");

}
void terminal(){
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

}
string choose_mon(int count){ //เลือก mons ที่จะบวก
    string boss;
    if(count == 1) boss = "BOSS01";
    else if(count == 2) boss = "BOSS02";
    else if(count == 3) boss = "BOSS03";
    else if(count == 4) boss = "BOSS04";
    return boss;
}
char atkboss(char BOSS_action){//เช็ค monster action
   int ranAtkboss = rand()%10;
        if(ranAtkboss <= 8) BOSS_action == 'a';
        if(ranAtkboss > 8) BOSS_action == 'b';
    return BOSS_action;
}

void showshop(){
//Pistol
printf("          _______________==\n");
printf("         q|[[[[ [__]   ___|\n");
printf("         /_____________/_ |\n");
printf("        |    [|_]'\n");
printf("        | ## |\n");
printf("        | ## |\n");
printf("        |_##_|\n");
printf("\n\n");
printf("        Pistol Press[1] \n");
printf("        PRICE : 150  $ \n");
printf("        ATK   : 15 - 35 damage  \n");
printf("\n");
//Armor1
printf("    ___     ___\n");
printf("    [ ]_____[ ]]\n");
printf("   |    VEST   ||\n");
printf("   |           ||\n");
printf("   |___ ___ ___||\n");
printf("   |[__][__][__]|\n");
printf("   |   |   |   ||\n");
printf("   |___|___|___|/\n");
printf("\n\n");
printf("        Armor1 Press[2] \n");
printf("        PRICE : 300  $ \n");
printf("        DEF   : 10 def \n");
printf("\n");

//medkit

printf("  _______________\n");
printf(" /______________/|\n");
printf(" |      _      | |\n");
printf(" |   __| |__   | |\n");
printf(" |  |__   __|  | |\n");
printf(" |     |_|     | |\n");
printf(" |  first aid  | |\n");
printf(" |_____________|/\n");
printf("\n\n");
printf("        Medkit  Press[3] \n");
printf("        PRICE : 100  $ ( 1 used ) \n");
printf("        HEAL  :  25 - 40 hp  \n");
printf("\n");

//Rifile
printf("                    __:\n");
printf("          /**********|======.._____    ==\n");
printf(" --------/  '/-----/ |=[][] !!-----|___/|\n");
printf("|        __  |_]--|--|=======-----------|\n");
printf("|      _/  |_|     |  |\n");
printf("|_____/    ==       |__|\n");
printf("\n\n");
printf("        Rifile  Press[4] \n");
printf("        PRICE : 1000  $ \n");
printf("        ATK   : 50 - 100 damage  \n");
printf("\n");

//granade
printf("      __\n");
printf("    /=||=-o\n");
printf("   / [  ]\n");
printf("  / [    ]\n");
printf(" | [______]\n");
printf("   [      ]\n");
printf("    [    ]\n");
printf("     [__]\n");
printf("\n\n");
printf("        Grenade  Press[5] \n");
printf("        PRICE : 150  $ ( 1 used ) \n");
printf("        ATK   : 200 damage  \n");
printf("\n");

  
printf(" \n");

}
void starterbotton(int money,char player_action){
     char click = getch();
     printf("%c\n",click);
     if(click == '1') money = 0;
     else if(click == '2') condition();
     else if(click == 'e') player_action = 'e';
}

int main(){
    Unit soilder101,boss;
    int turn_count = 1;
    int money;
    char player_action = '\0',BOSS_action = '\0'; //กำหนดค่าเริ่มต้น monster action
    
    terminal();
    starterbotton(money,player_action);
    srand(time(0));

   //ซื้อของเมื่อเข้ารอบ 2
   int i = 1;
   while(i < 4){ //ต้องเจอ monster ตัวถัดไป
    if(i == 2){
       soilder101.buy_item(money);
       showshop();
   }
    string boss_id = choose_mon(turn_count);
	soilder101.createchar("Soilder");
	boss.createchar(boss_id);
	int p = 0, m = 0;//กำหนดค่าเริ่มต้น
	while(true){
		boss.newturn();	
		soilder101.newturn();			
		drawScene(soilder101,boss);		
        //player
        button(player_action);
        if(player_action == 'a'){
        p = soilder101.attack(boss,"Soilder"); 
        //boss action start เมื่อ player ตี
		if(i > 0){
        if(i == 4){
              BOSS_action = atkboss(BOSS_action);
        }
        else{
              BOSS_action = 'a';
        }
        }
        if(BOSS_action == 'a') m = boss.attack(soilder101,boss_id); 
        if(BOSS_action == 'b') m = boss.superattack(soilder101,boss_id);
        }
        //ใช้กล่องพยาบาล
        if(player_action == 'q'){ 
            p = soilder101.heal(); 
            //boss action start เมื่อ player ตี
		if(i > 0){
        if(i == 4){
              BOSS_action = atkboss(BOSS_action);
        }
        else{
              BOSS_action = 'a';
        }
        }
        if(BOSS_action == 'a') m = boss.attack(soilder101,boss_id); 
        if(BOSS_action == 'b') m = boss.superattack(soilder101,boss_id);
        }
        }
        //ใช้ระเบิด
        if(player_action == 'g'){
             p = soilder101.usegrenade("Soilder");
             //boss action start เมื่อ player ตี
		if(i > 0){
        if(i == 4){
              BOSS_action = atkboss(BOSS_action);
        }
        else{
              BOSS_action = 'a';
        }
        }
        if(BOSS_action == 'a') m = boss.attack(soilder101,boss_id); 
        if(BOSS_action == 'b') m = boss.superattack(soilder101,boss_id);
        }
             }
        if(player_action == 's') soilder101.inputsaveprogress(money);
        if(player_action == 'l') soilder101.outputsaveprogress(money);
        if(player_action == 'e') break;
        
		if(soilder101.isDead()){
			drawScene(soilder101,boss);
			playerLose();
			break; 
		}
		if(boss.isDead()){
			drawScene(soilder101,boss);//อาจแก้เป็นฉากตาย
            soilder101.level_up();
			playerWin();
            getmoney(boss_id,money);
        }
    }
    i++;
    turn_count++;
	}
	return 0;
}
