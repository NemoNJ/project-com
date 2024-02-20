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
#include <windows.h>

using namespace std;

class Unit{
       int hpmax; 
        string type;		
		int hp;
		int atk;
		int def;  
        int super_atk;
        bool changeturn;
    public:
    void createchar(string); //เรื่มต้นค่า status
    void newturn(); //เปลี่ยนตา
    void showstatus();
	int attack(Unit &,string);
    int superattack(Unit &,string);
	int beAttacked(int,string);
    int beSuperAttacked(int,string);
	int heal();	
	void guard();
	bool isDead();
    void buy_item(int);
    void inputsaveprogress(int);
    void outputsaveprogress(int);
    int usegrenade(string);
    void level_up();
    int HeroATK();
    int HeroDEF();
    int HeroHP();
    int medkit;
    int grenade;
    int level = 1;
    bool havegun;
    bool haverifle;
};

void Unit::createchar(string type){ //กำหนดค่า status เริ่มต้น
	if(type == "Soilder"){
		hpmax = 100;
		atk = 5;
		def = 5;
	}else if(type == "BOSS01"){
		hpmax = 80;
		atk = 5;
		def = 0;
	}else if(type == "BOSS02"){
		hpmax = 150;
		atk = 10;
		def = 10;
    }else if(type == "BOSS03"){
		hpmax = 500;
		atk = 20;
		def = 20;
    }else if(type == "BOSS04"){
		hpmax = 900;
		atk = 30;
		def = 50;
    }
	hp = hpmax;
    changeturn = false;
    havegun = false;
    haverifle = false;
}
void Unit::newturn(){
	changeturn = false;
}
bool Unit::isDead(){
if(hp > 0) return false;
else return true;
}
int Unit::heal(){//ใช้ medkit
if(medkit > 0){
  int healing;
     healing = (25+rand()%16);
    if(healing+hp >= hpmax){
        healing = hpmax-hp ;
        hp = hpmax ;
        return healing ;
    }
     hp += healing;
     return healing;
     medkit -= 1; //เอากล่องที่ใช้แล้วออก
    }
}
int Unit::beAttacked(int oppatk, string type){//ต้องสุ่ม damage ทุกครั้งที่ attack
    if (type == "Soilder") {
        oppatk += (rand() % 16);
        hp = hp - (oppatk - def);
        return oppatk - def;
    } else if (type == "BOSS01") {
        oppatk += (rand() % 6);
        hp = hp - (oppatk - def);
        return oppatk - def;
    } else if (type == "BOSS02") {
        oppatk += (rand() % 11);
        hp = hp - (oppatk - def);
        return oppatk - def;
    } else if (type == "BOSS03") {
        oppatk += (rand() % 21);
        hp = hp - (oppatk - def);
        return oppatk - def;
    } else if (type == "BOSS04") {
        oppatk += (rand() % 51);
        hp = hp - (oppatk - def);
        return oppatk - def;
    }
    return 0; // Default case
}
int Unit::attack(Unit &type,string name){
	return type.beAttacked(atk,name);
}
int Unit::beSuperAttacked(int oppatk, string type) {//ต้องสุ่ม damage ทุกครั้งที่ attack
    int super_oppatk = 3 * oppatk;
    if (type == "BOSS01") {
        super_oppatk += (rand() % 6);
        hp = hp - (super_oppatk - def);
        return super_oppatk - def;
    } else if (type == "BOSS02") {
        super_oppatk += (rand() % 11);
        hp = hp - (super_oppatk - def);
        return super_oppatk - def;
    } else if (type == "BOSS03") {
        super_oppatk += (rand() % 21);
        hp = hp - (super_oppatk - def);
        return super_oppatk - def;
    } else if (type == "BOSS04") {
        super_oppatk += (rand() % 51);
        hp = hp - (super_oppatk - def);
        return super_oppatk - def;
    }
    return 0; // Default case
}
int Unit::superattack(Unit &type,string name){
	return type.beSuperAttacked(atk,name);
}
int Unit::usegrenade(string name){
   return this->beAttacked(120,name);
   grenade -= 1;// ใช้ระเบิดแล้ว
}
void Unit::showstatus(){
	if(type == "Soilder"){
		cout << "---------------------------------------\n"; 
		cout << type << "\n"; 
		cout << "HP: " << hp << "/" << hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def;		
		cout << "\n---------------------------------------\n";
	}	
	else if(type == "BOSS"){
		cout << "\t\t\t\t---------------------------------------\n"; 
		cout << "\t\t\t\t" << type << "\n"; 
		cout << "\t\t\t\tHP: " << hp << "\t\tATK: "<< atk << "\t\tDEF: "<< def;
		cout << "\n\t\t\t\t---------------------------------------\n";
	}
}

void playerWin(){
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(color , 2);	
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                       |       |       ____                       |             |    _    ___      _                                                   |\n");
printf("|                                        |     |      |      |    |         |      |             |    |    |  |     |                                                   |\n");
printf("|                                         |   |      |        |   |         |       |     |     |     |    |   |    |                                                   |\n");
printf("|                                           |       |          |  |         |        |   | |   |      |    |    |   |                                                   |\n");
printf("|                                           |        |        |   |         |         | |   | |       |    |     |  |                                                   |\n");
printf("|                                           |         | ____ |     |_______|           |     |        |    |      |_|                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                  ***************************************************************************************                                              |\n");
printf("|                                  *                   YOU GET MONEY : ____ $   Press [ T ] To Continue                  *                                              |\n");
printf("|                                  ***************************************************************************************                                              |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                       ---------                                                                                       |\n");
printf("|                                                                        -.....-                                                                                        |\n");
printf("|                                                                         .....                                                                                         |\n");
printf("|                                                                      ...      ...                                                                                     |\n");
printf("|                                                                     ...          ..                                                                                   |\n");
printf("|                                                                    ...    |        ..                                                                                 |\n");
printf("|                                                                  ...    :|:         ..                                                                                |\n");
printf("|                                                                 ...     : |  :       ..                                                                               |\n");
printf("|                                                                ...     :  |   :       ...                                                                             |\n");
printf("|                                                              ...        : |             ..                                                                            |\n");
printf("|                                                              ..          :|             ..                                                                            |\n");
printf("|                                                              ..           |:            ..                                                                            |\n");
printf("|                                                              ...          |  :         ..                                                                             |\n");
printf("|                                                               ...     :   |   :       ...                                                                             |\n");
printf("|                                                                ...     :  |  :       ...                                                                              |\n");
printf("|                                                                  .....   :|:       ....                                                                               |\n");
printf("|                                                                     ...   |      ....                                                                                 |\n");
printf("|                                                                       ............                                                                                    |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n") ; 
SetConsoleTextAttribute(color , 15);
};


void playerLose(){
	// you die

printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                    ____                                                                               |\n");
printf("|                                         |       |       ____                      |    |      _      _______                                                          |\n");
printf("|                                          |     |      |      |    |         |     |     |     |      |                                                                |\n");
printf("|                                           |   |      |        |   |         |     |      |    |      |                                                                |\n");
printf("|                                             |       |          |  |         |     |      |    |      |_____                                                           |\n");
printf("|                                             |        |        |   |         |     |     |     |      |                                                                |\n");
printf("|                                             |         | ____ |     |_______|      |____|      |      |______                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                  ***************************************************************************************                                              |\n");
printf("|                                  *                          Press [ L ] To Load Your Save                              *                                              |\n");
printf("|                                  ***************************************************************************************                                              |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                 ..*.*.*.*.*.*.*.*.*..                                                                                 |\n");
printf("|                                                               **                     **                                                                               |\n");
printf("|                                                              *                         *                                                                              |\n");
printf("|                                                            *                             *                                                                            |\n");
printf("|                                                           *          *          *         *                                                                           |\n");
printf("|                                                          *         * x *      * x *        *                                                                          |\n");
printf("|                                                          *         *   *      *   *        *                                                                          |\n");
printf("|                                                          *..         *          *        ..*                                                                          |\n");
printf("|                                                           *..                           ..*                                                                           |\n");
printf("|                                                             *..                       ..*                                                                             |\n");
printf("|                                                               *..                   ..*                                                                               |\n");
printf("|                                                                  *..              ..*                                                                                 |\n");
printf("|                                                                   *   .   .   .   *                                                                                   |\n");
printf("|                                                                   *   .   .   .   *                                                                                   |\n");
printf("|                                                                   *   .   .   .   *                                                                                   |\n");
printf("|                                                                    ***************                                                                                    |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	
};

void getmoney(string type,int money){//ชนิดของ boss และ update money
    if(type == "BOSS01"){
          money += 300; 
    }
    else if(type == "BOSS02"){
           money += 700;
    }
    else if(type == "BOSS03"){
           money += 1000;
    }
    else if(type == "BOSS04"){
           money += 1500;
    }
};

void Unit::buy_item(int money){
    while(true){
    char click = getch();
    printf("%c\n",click);
    if(click == '1'){//pistol
        if(money > 0){
          atk += (15+rand()%21);
          money -= 150;
          havegun = true;
        }
        else{
            cout << "You can't afford it\n";
        }
    }
    if(click == '2'){//armor
       if(money > 300){
          def += 10;
          money -= 300;
       }
       else{
            cout << "You can't afford it\n";
        }
    }
    if(click == '3'){//med kit
       if(money > 50){
          medkit += 1;
          money -= 100;
       }
       else{
            cout << "You can't afford it\n";
        }
    }
    if(click == '4'){//rifle
       if(money > 1000){
          atk += (50+rand()%51);
          money -= 1000;
          haverifle = true;
       }
       else{
            cout << "You can't afford it\n";
        }
    }
    if(click == '5'){//grenade
       if(money > 200){
          grenade += 1;
          money -= 200;
       }
       else{
            cout << "You can't afford it\n";
        }
    }
    if(click == 'e'){//exit shop
           break;
    }
    }
 }
void Unit::inputsaveprogress(int money){
        ofstream dest;
        dest.open("status.txt");
        string myhp = to_string(hp);
        string myatk = to_string(atk);
        string mydef = to_string(def);
        string mygrenade = to_string(grenade);
        string mymedkit = to_string(medkit);
        string mymoney = to_string(money);
        dest << myhp;
        dest << myatk;
        dest << mydef;
        dest << mygrenade;
        dest << mymedkit;
        dest << mymoney;
        dest.close();
}
void Unit::outputsaveprogress(int money){
        ifstream source;
        source.open("status.txt");
        string textline;
        getline(source,textline);
        hp = atoi(textline.c_str());
        getline(source,textline);
        atk = atoi(textline.c_str());
        getline(source,textline);
        def = atoi(textline.c_str());
        getline(source,textline);
        grenade = atoi(textline.c_str());
        getline(source,textline);
        medkit = atoi(textline.c_str());
        getline(source,textline);
        money = atoi(textline.c_str());
        source.close();
}
void Unit::level_up(){//เพิ่ม level เมื่อผ่านด่าน
    level += 1;
}
void button(char &player_action,char &BOSS_action){
    char click = getch();
    printf("%c\n",click);
    if(click == 'a'){ 
        player_action = 'a';
        BOSS_action = 'a';
        }
    else if(click == 'q'){
        player_action = 'q';
        BOSS_action = 'a';
    } 
    else if(click == 'g'){ 
        player_action = 'g';
        BOSS_action = 'a';
    }
    else if(click == 't'){
        player_action = 't';
            }
    else if(click == 's') player_action = 's';
    else if(click == 'l') player_action = 'l';
    else if(click == 'e') player_action = 'e';
};
int Unit::HeroATK(){
   int heroatk = atk;
   return  heroatk;
}
int Unit::HeroDEF(){
    int herodef = def;
   return  herodef;
}
int Unit::HeroHP(){
    int herohp = hp;
   return  herohp;
}
//วาด position ที่จะเกิด
void drawScene(Unit soilder101,Unit boss,string heroname){
    char heroes[50];
    sscanf (heroname.c_str(),"%s",heroes);
   if (soilder101.level == 1 && soilder101.havegun == false) {
          int heroatk = soilder101.HeroATK();
          int herodef = soilder101.HeroDEF();
          int herohp = soilder101.HeroHP();
          int bossatk = boss.HeroATK();
          int bossdef = boss.HeroDEF();
          int bosshp = boss.HeroHP();
//battle sence1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 1     |\n");
printf("|                         %s                                                                            The Stick Man LV 1                                              |\n",heroes);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       ------        ATK: %d                                      |\n",heroatk,bossatk);
printf("|                      /--------|      /|      HP:  %d                                                #     / -  - |       HP:  %d                                      |\n",herohp,bosshp);
printf("|                      |/   I I |      ||      DEF: %d                                                #     | o  o |       DEF: %d                                      |\n",herodef,bossdef);
printf("|                      ||    -  /      ||                                                             #     |  -   |                                                    |\n");
printf("|                        '------'      +++                                                            #     '-----'                                                     |\n");
printf("|                       /  ------------[]                                                             []----        |                                                   |\n");
printf("|                      /  |      |----/                                                               []------      |                                                   |\n");
printf("|                      |  |      |                                                                    #     |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack [G] USE_Grenade [Q] USE_MedKit [S] Save_game [L] Load_game [E] Exit                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

   }
   if (soilder101.level == 2 && soilder101.havegun == false) {
      int heroatk = soilder101.HeroATK();
          int herodef = soilder101.HeroDEF();
          int herohp = soilder101.HeroHP();
          int bossatk = boss.HeroATK();
          int bossdef = boss.HeroDEF();
          int bosshp = boss.HeroHP();
//battle sence 2-1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 2     |\n");
printf("|                         %s                                                                           The 9mm  LV 10                                                   |\n",heroes);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",heroatk,bossatk);
printf("|                      /--------|      /|      HP:  %d                                                    ---------|       HP:  %d                                      |\n",herohp,bosshp);
printf("|                      |/   I I |      ||      DEF: %d                                                      | =  = |       DEF: %d                                      |\n",herodef,bossdef);
printf("|                      ||    -  /      ||                                                                   |  -   |                                                    |\n");
printf("|                        '------'      +++                                                         '====     '-----'                                                    |\n");
printf("|                       /  ------------[]                                                             '[]----       |                                                   |\n");
printf("|                      /  |      |----/                                                                 ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack [G] USE_Grenade [Q] USE_MedKit [S] Save_game [L] Load_game [E] Exit                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
   }
   if (soilder101.level == 2 && soilder101.havegun == true) {
      int heroatk = soilder101.HeroATK();
          int herodef = soilder101.HeroDEF();
          int herohp = soilder101.HeroHP();
          int bossatk = boss.HeroATK();
          int bossdef = boss.HeroDEF();
          int bosshp = boss.HeroHP();
//battle sence2-2
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 2     |\n");
printf("|                         %s                                                                              The 9mm  LV 10                                                |\n",heroes);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",heroatk,bossatk);
printf("|                      /--------|              HP:  %d                                                    ---------|       HP:  %d                                      |\n",herohp,bosshp);
printf("|                      |/   I I |              DEF: %d                                                      | =  = |       DEF: %d                                      |\n",herodef,bossdef);
printf("|                      ||    -  /                                                                           |  -   |                                                    |\n");
printf("|                        '------'       ===='                                                      '====     '-----'                                                    |\n");
printf("|                       /  ------------[]'                                                            '[]----       |                                                   |\n");
printf("|                      /  |      |----/                                                                 ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack [G] USE_Grenade [Q] USE_MedKit [S] Save_game [L] Load_game [E] Exit                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

   }
   if (soilder101.level == 3 && soilder101.haverifle == false) {
      int heroatk = soilder101.HeroATK();
          int herodef = soilder101.HeroDEF();
          int herohp = soilder101.HeroHP();
          int bossatk = boss.HeroATK();
          int bossdef = boss.HeroDEF();
          int bosshp = boss.HeroHP();
//battle sence 3-1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 3     |\n");
printf("|                         %s                                                                             Toxic Timmy LV 25                                              |\n",heroes);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",heroatk,bossatk);
printf("|                      /--------|              HP:  %d                                                    ---------|       HP:  %d                                      |\n",herohp,bosshp);
printf("|                      |/   I I |              DEF: %d                                                      |[]-[] |       DEF: %d                                      |\n",herodef,bossdef);
printf("|                      ||    -  /                                                                           |  -   |                                                    |\n");
printf("|                        '------'       ===='                                                  -'=======q    '-----'                                                    |\n");
printf("|                       /  ------------[]'                                                       ||   '[]==---      |                                                   |\n");
printf("|                      /  |      |----/                                                           --    ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack [G] USE_Grenade [Q] USE_MedKit [S] Save_game [L] Load_game [E] Exit                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
   }
   if (soilder101.level == 3 && soilder101.haverifle == true) {
      int heroatk = soilder101.HeroATK();
          int herodef = soilder101.HeroDEF();
          int herohp = soilder101.HeroHP();
          int bossatk = boss.HeroATK();
          int bossdef = boss.HeroDEF();
          int bosshp = boss.HeroHP();
//battle sence 3-2
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 3     |\n");
printf("|                         %s                                                                             Toxic Timmy LV25                                               |\n",heroes);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",heroatk,bossatk);
printf("|                      /--------|              HP:  %d                                                    ---------|       HP:  %d                                      |\n",herohp,bosshp);
printf("|                      |/   I I |              DEF: %d                                                      |[]-[] |       DEF: %d                                      |\n",herodef,bossdef);
printf("|                      ||    -  /                                                                           |  -   |                                                    |\n");
printf("|                        '------'-----_==============='                                       -'=======q    '-----'                                                     |\n");
printf("|                       /  --------___/ |[]'-||---/                                              ||   '[]==---      |                                                   |\n");
printf("|                      /  |      ||____/     |_|                                                  --    ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack [G] USE_Grenade [Q] USE_MedKit [S] Save_game [L] Load_game [E] Exit                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
   }
   if (soilder101.level == 4 && soilder101.haverifle == false) {
      int heroatk = soilder101.HeroATK();
          int herodef = soilder101.HeroDEF();
          int herohp = soilder101.HeroHP();
          int bossatk = boss.HeroATK();
          int bossdef = boss.HeroDEF();
          int bosshp = boss.HeroHP();
//battle sence 4-1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 4     |\n");
printf("|                         %s                                                                            Just_a_teen LV50                                                |\n",heroes);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------      ATK: %d                                       |\n",heroatk,bossatk);
printf("|                      /--------|              HP:  %d                                                    __|-------|__   HP:  %d                                       |\n",herohp,bosshp);
printf("|                      |/   I I |              DEF: %d                                                      | U  U |      DEF: %d                                       |\n",herodef,bossdef);
printf("|                      ||    -  /                                                                   |_:     |   ^  |                                                    |\n");
printf("|                        '------'       ===='                                                '==-'======'    '-----'                                                    |\n");
printf("|                       /  ------------[]'                                                       [|   '[]==-/  |_| ||                                                   |\n");
printf("|                      /  |      |----/                                                           [|    ------     ||                                                   |\n");
printf("|                      |  |      |                                                                 [|       |      ||                                                   |\n");
printf("|                      |==|      |                                                                          |[][][]||                                                   |\n");
printf("|                      |==|      |                                                                          | | | |||                                                   |\n");
printf("|                      '=====[]=='                                                                          ===[]====                                                   |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack [G] USE_Grenade [Q] USE_MedKit [S] Save_game [L] Load_game [E] Exit                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
   }

   if (soilder101.level == 4 && soilder101.haverifle == true) {
      int heroatk = soilder101.HeroATK();
          int herodef = soilder101.HeroDEF();
          int herohp = soilder101.HeroHP();
          int bossatk = boss.HeroATK();
          int bossdef = boss.HeroDEF();
          int bosshp = boss.HeroHP();
//battle sence4-2

printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 4     |\n");
printf("|                         %s                                                                            Just_a_teen LV50                                                |\n",heroes);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------      ATK: %d                                       |\n",heroatk,bossatk);
printf("|                      /--------|              HP:  %d                                                    __|-------|__   HP:  %d                                       |\n",herohp,bosshp);
printf("|                      |/   I I |              DEF: %d                                                      | U  U |      DEF: %d                                       |\n",herodef,bossdef);
printf("|                      ||    -  /                                                                   |_:     |   ^  |                                                    |\n");
printf("|                         '------'-----_==============='                                     '==-'======'    '-----'                                                    |\n");
printf("|                       /  --------___/ |[]'-||---/                                              [|   '[]==-/  |_| ||                                                   |\n");
printf("|                      /  |      ||____/     |_|                                                  [|    ------     ||                                                   |\n");
printf("|                      |  |      |                                                                 [|       |      ||                                                   |\n");
printf("|                      |==|      |                                                                          |[][][]||                                                   |\n");
printf("|                      |==|      |                                                                          | | | |||                                                   |\n");
printf("|                      '=====[]=='                                                                          ===[]====                                                   |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack [G] USE_Grenade [Q] USE_MedKit [S] Save_game [L] Load_game [E] Exit                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
   }
};

void getname(string &hero_name){
    string name;
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             [ MAP ]                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )                                                               |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
printf("|                                                       /                                                                                                               |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ( Stage 2 )                                                                                                        |\n");
printf("|                                     /                                                                                                                                 |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ( Stage 1 )                                                                                                                         |\n");
printf("|                          [ You Are Here ]                                                                                                                             |\n");
printf("|       ENTER YOUR NAME : "); cin >> name; cin.ignore();printf("                                                                                                        |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
 hero_name = name;
};

void showmap(Unit soilder101){
    if (soilder101.level == 1){
       //map in game stage 1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             [ MAP ]                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )                                                               |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
printf("|                                                       /                                                                                                               |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ( Stage 2 )                                                                                                        |\n");
printf("|                                     /                                                                                                                                 |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ( Stage 1 )                                                                                                                         |\n");
printf("|                          [ You Are Here ]                                                                                                                             |\n");
printf("|       PRESS [T] To continue                                                                                                                                           |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (soilder101.level == 2){
//map in game stage 2
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             [ MAP ]                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )                                                               |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
printf("|                                                       /                                                                                                               |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ( Stage 2 )                                                                                                        |\n");
printf("|                                     /            [ You Are Here ]                                                                                                     |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ( Stage 1 complete)                                                                                                                 |\n");
printf("|                                                                                                                                                                       |\n");
printf("|       PRESS [T] To continue                                                                                                                                           |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (soilder101.level == 3){
//map in game stage 3

printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             [ MAP ]                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )                                                               |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
printf("|                                                       /               [ You Are Here ]                                                                                |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ( Stage 2 complete )                                                                                               |\n");
printf("|                                     /                                                                                                                                 |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ( Stage 1 complete)                                                                                                                 |\n");
printf("|                                                                                                                                                                       |\n");
printf("|       PRESS [T] To continue                                                                                                                                           |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (soilder101.level == 4){
    //map in game stage 4
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             [ MAP ]                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )    [ You Are Here ]                                           |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 complete )                                                                           |\n");
printf("|                                                       /                                                                                                               |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ( Stage 2 complete )                                                                                               |\n");
printf("|                                     /                                                                                                                                 |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ( Stage 1 complete)                                                                                                                 |\n");
printf("|                                                                                                                                                                       |\n");
printf("|       PRESS [T] To continue                                                                                                                                           |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
};
void showshop(int money){
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
printf("|             PRICE : 1000  $                                          PRICE : 200  $ ( 1 used )                                                                        |\n");
printf("|             ATK   : 50 - 100 damage                                  ATK   : 120 damage                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|     YOUR MONEY : %d              PRESS [T] To continue                                                                                                                |\n",money);
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
};
