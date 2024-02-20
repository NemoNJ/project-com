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
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
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

