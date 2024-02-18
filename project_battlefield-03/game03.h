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

class Unit{
       int hpmax; 
       int level = 1;
        string type;		
		int hp;
		int atk;
		int def;  
        int medkit;
        int grenade;
        int super_atk;
        bool changeturn;
        bool havegun;
        bool haverifle;
    public:
    void createchar(string); //เรื่มต้นค่า status
    void newturn(); //เปลี่ยนตา
    void showstatus();
	int attack(Unit &);
	int beAttacked(int);
	int heal();	
	void guard();
	bool isDead();
    void buy_item(int);
    int beSuperAttacked(int);
    int superattack(Unit &);
    void inputsaveprogress(int);
    void outputsaveprogress(int);
    int usegrenade();
    void drawScene();
    void level_up();
    void drawcase1();
    void drawcase2();
    void drawcase3();
    void drawcase4();
    void drawcase5();
    void drawcase6();
};


void Unit::createchar(string type){ //กำหนดค่า status เริ่มต้น
	if(type == "Soilder"){
		hpmax = 100;
		atk = 5+(rand()%16);
		def = 5;
	}else if(type == "BOSS01"){
		hpmax = 80;
		atk = 5+(rand()%16);
		def = 0;
	}else if(type == "BOSS02"){
		hpmax = 150;
		atk = 10+(rand()%11);
		def = 10;
    }else if(type == "BOSS03"){
		hpmax = 300;
		atk = 20+(rand()%21);
		def = 20;
    }else if(type == "BOSS04"){
		hpmax = 500;
		atk = 30+(rand()%51);
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
int Unit::beAttacked(int oppatk){
   hp = hp - oppatk - def;
   return oppatk - def;
}
int Unit::attack(Unit &type){
	return type.beAttacked(atk);
}
int Unit::beSuperAttacked(int oppatk){
   int super_oppatk =  3*oppatk;
   hp = hp - super_oppatk - def;
   return super_oppatk - def;
}
int Unit::superattack(Unit &type){
	return type.beSuperAttacked(atk);
}
int Unit::usegrenade(){
   return this->beAttacked(200);
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
	cout << "*******************************************************\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*                   YOU WIN!!!                        *\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};


void playerLose(){
	cout << "*******************************************************\n";
	cout << "*                                                     *\n";
	cout << "*                   YOU LOSE!!!                       *\n";
	cout << "*                                                     *\n";
	cout << "*******************************************************\n";
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
            cout << "You can't afford it";
        }
    }
    if(click == '2'){//armor
       if(money > 300){
          def += 10;
          money -= 300;
       }
       else{
            cout << "You can't afford it";
        }
    }
    if(click == '3'){//med kit
       if(money > 50){
          medkit += 1;
          money -= 100;
       }
       else{
            cout << "You can't afford it";
        }
    }
    if(click == '4'){//rifle
       if(money > 1000){
          atk += (50+rand()%51);
          money -= 1000;
          haverifle = true;
       }
       else{
            cout << "You can't afford it";
        }
    }
    if(click == '5'){//grenade
       if(money > 150){
          grenade += 1;
          money -= 150;
       }
       else{
            cout << "You can't afford it";
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
//วาด position ที่จะเกิด
void Unit::drawScene() {
   if (level == 1 && havegun == false) {
      drawcase1();
   }
   if (level == 2 && havegun == false) {
      drawcase2();
   }
   if (level == 2 && havegun == true) {
      drawcase3();
   }
   if (level == 3 && haverifle == false) {
      drawcase4();
   }
   if (level == 3 && haverifle == true) {
      drawcase5();
   }
   if (level == 4 && haverifle == true) {
      drawcase6();
   }
}
void Unit::drawcase1(){
//battle sence1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 1     |\n");
printf("|                         NAME                                                                         The Stick Man LV1                                                |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: 00                                                       ------        ATK: 00                                      |\n");
printf("|                      /--------|      /|      HP:  00                                                #     / -  - |       HP:  00                                      |\n");
printf("|                      |/   I I |      ||      DEF: 00                                                #     | o  o |       DEF: 00                                      |\n");
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
printf("|                                                     ATK [1]             DEF [2]          ITEM [3]                                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
void Unit::drawcase2(){
//battle sence1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 1     |\n");
printf("|                         NAME                                                                         The Stick Man LV1                                                |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: 00                                                       ------        ATK: 00                                      |\n");
printf("|                      /--------|      /|      HP:  00                                                #     / -  - |       HP:  00                                      |\n");
printf("|                      |/   I I |      ||      DEF: 00                                                #     | o  o |       DEF: 00                                      |\n");
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
printf("|                                                     ATK [1]             DEF [2]          ITEM [3]                                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void Unit::drawcase3(){
//battle sence1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 1     |\n");
printf("|                         NAME                                                                         The Stick Man LV1                                                |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: 00                                                       ------        ATK: 00                                      |\n");
printf("|                      /--------|      /|      HP:  00                                                #     / -  - |       HP:  00                                      |\n");
printf("|                      |/   I I |      ||      DEF: 00                                                #     | o  o |       DEF: 00                                      |\n");
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
printf("|                                                     ATK [1]             DEF [2]          ITEM [3]                                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
void Unit::drawcase4(){
//battle sence1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 1     |\n");
printf("|                         NAME                                                                         The Stick Man LV1                                                |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: 00                                                       ------        ATK: 00                                      |\n");
printf("|                      /--------|      /|      HP:  00                                                #     / -  - |       HP:  00                                      |\n");
printf("|                      |/   I I |      ||      DEF: 00                                                #     | o  o |       DEF: 00                                      |\n");
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
printf("|                                                     ATK [1]             DEF [2]          ITEM [3]                                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
void Unit::drawcase5(){
//battle sence1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 1     |\n");
printf("|                         NAME                                                                         The Stick Man LV1                                                |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: 00                                                       ------        ATK: 00                                      |\n");
printf("|                      /--------|      /|      HP:  00                                                #     / -  - |       HP:  00                                      |\n");
printf("|                      |/   I I |      ||      DEF: 00                                                #     | o  o |       DEF: 00                                      |\n");
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
printf("|                                                     ATK [1]             DEF [2]          ITEM [3]                                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
void Unit::drawcase6(){
//battle sence1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 1     |\n");
printf("|                         NAME                                                                         The Stick Man LV1                                                |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: 00                                                       ------        ATK: 00                                      |\n");
printf("|                      /--------|      /|      HP:  00                                                #     / -  - |       HP:  00                                      |\n");
printf("|                      |/   I I |      ||      DEF: 00                                                #     | o  o |       DEF: 00                                      |\n");
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
printf("|                                                     ATK [1]             DEF [2]          ITEM [3]                                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
