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
string hero_name;
void condition(){

     printf("Press button A to ATTACK\n");
 
     printf("Press button Q to USE MEDKIT\n");

     printf("Press button G to USE GRENADE\n");

     printf("Press button S to SAVE GAME\n");

     printf("Press button L to BLOAD GAME\n");

     printf("Press button E to EXIT GAME\n");

}
void terminal(){
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                            ____________________________________________                                                               |\n");
printf("|                                                           [                                            ]                                                              |\n");
printf("|                            *******************************[      WELCOME TO BATTLE BOSS GAME 03        ]*********************************                             |\n");
printf("|                            *                              [____________________________________________]                                *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                          [1] PLAY GAME                                                     *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                          [2] HOW TO PLAY                                                   *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                          [E] EXIT                                                          *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                              ....                                                          *                             |\n");
printf("|                            *                                            .'    '.                                                        *                             |\n");
printf("|                            *                                           .   ......  ___       _                                          *                             |\n");
printf("|                            *                                           . .' I_I_;./___|_____/-|____                                     *                             |\n");
printf("|                            *                                         .'     |     ____.--;;;;;;;'                                       *                             |\n");
printf("|                            *                                        .  ...  |____/||  [ ]'''                                            *                             |\n");
printf("|                            *                                        :     ...   ...'   [_]                                              *                             |\n");
printf("|                            *                                       .    .     :                                                         *                             |\n");
printf("|                            *                                       . :  . :  : .                                                        *                             |\n");
printf("|                            *                                       : : .  :  : :                                                        *                             |\n");
printf("|                            *                                       :...........:                                                        *                             |\n");
printf("|                            *                                       :           :                                                        *                             |\n");
printf("|                            **************************************************************************************************************                             |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

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
//storade
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                         [  SHOP  ]                                                                                    |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                 _______________==                                      ___     ___                                      _______________                               |\n");
printf("|                q|[[[[ [__]   ___|                                      [ ]_____[ ]]                                    /______________/|                              |\n");
printf("|                /_____________/_ |                                     |    VEST   ||                                   |      _      | |                              |\n");
printf("|                |    [|_]'                                             |           ||                                   |   __| |__   | |                              |\n");
printf("|                | ## |                                                 |___ ___ ___||                                   |  |__   __|  | |                              |\n");
printf("|                | ## |                                                 |[__][__][__]|                                   |     |_|     | |                              |\n");
printf("|                |_##_|                                                 |   |   |   ||                                   |  first aid  | |                              |\n");
printf("|                                                                       |___|___|___|/                                   |_____________|/                               |\n");
printf("|             Pistol Press[1]                                           Armor1 Press[2]                                  Medkit  Press[3]                               |\n");
printf("|             PRICE : 150  $                                            PRICE : 300  $                                   PRICE : 100  $                                 |\n");
printf("|             ATK   : 15 - 35 damage                                    DEF   : +10 def                                  HEAL  :  25 - 40 hp                            |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                            __                                                                                         |\n");
printf("|                                  __:                                     /=||=-o                                                                                      |\n");
printf("|                         /**********|======.._____    ==                 / [  ]                                                                                        |\n");
printf("|                --------/  '/-----/ |=[][] !!-----|___/|                / [    ]                                                                                       |\n");
printf("|               |        __  |_]--|--|=======-----------|               | [______]                                                                                      |\n");
printf("|               |      _/  |_|     |  |                                    [    ]                                                                                       |\n");
printf("|               |_____/    ==       |__|                                    [__]                                                                                        |\n");
printf("|             Rifile  Press[4]                                         Grenade  Press[5]                                                                                |\n");
printf("|             PRICE : 1000  $                                          PRICE : 150  $ ( 1 used )                                                                        |\n");
printf("|             ATK   : 50 - 100 damage                                  ATK   : 200 damage                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|     YOUR MONEY : %d              PRESS [T] To continue                                                                                                                |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
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
    getname(hero_name);//รับชื่อ
    srand(time(0));

   //ซื้อของเมื่อเข้ารอบ 2
   int i = 1;
   while(i < 4){ //ต้องเจอ monster ตัวถัดไป
    showmap(soilder101);//show stage
    if(i > 1){//รอบ 2 ให้ซื้อของ
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
		drawScene(soilder101,boss,hero_name);		
        //player
        button(player_action,BOSS_action);
        if(player_action == 'a') p = soilder101.attack(boss,"Soilder"); 
        
        // level 2 ขึ้นไปใช้ระเบิดกับกล่องพยาบาลได้
        // หมดแล้วหมดเลย
        if(player_action == 'q'){
            if(i > 1 && soilder101.medkit > 0) p = soilder101.heal();
            else if(i > 1 && soilder101.medkit < 0) cout << "Emtry";
            else cout << "Your level is too low";
        } 
        if(player_action == 'g'){
            if(i > 1 && soilder101.grenade > 0) p = soilder101.usegrenade(boss_id);
            else if(i > 1 && soilder101.grenade < 0) cout << "Emtry";
            else cout << "Your level is too low";
        }
        
        if(player_action == 's') soilder101.inputsaveprogress(money);
        if(player_action == 'l') soilder101.outputsaveprogress(money);
        if(player_action == 'e') break;
        //mons
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
        
		if(soilder101.isDead()){
			drawScene(soilder101,boss,hero_name);
			playerLose();
			break; 
		}
		
		if(boss.isDead()){
			drawScene(soilder101,boss,hero_name);//อาจแก้เป็นฉากตาย
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
