#include "library.h"

using namespace std;

class Unit{
       int hpmax; 
        string type;		
		int hp;
		int atk;
		int def;  
        int medkit;
        int grenade;
        bool changeturn;
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
};


void Unit::createchar(string type){ 
	if(type == "Soilder"){
		hpmax = 100;
		atk = 5+(rand()%16);
		def = 5;
	}else if(type == "Monster01"){
		hpmax = 80;
		atk = 5+(rand()%16);
		def = 0;
	}else if(type == "Monster02"){
		hpmax = 150;
		atk = 10+(rand()%11);
		def = 10;
    }else if(type == "Monster03"){
		hpmax = 300;
		atk = 20+(rand()%21);
		def = 20;
    }else if(type == "Monster04"){
		hpmax = 500;
		atk = 30+(rand()%51);
		def = 50;
    }
	hp = hpmax;
    changeturn = false;
}
void Unit::newturn(){
	changeturn = false;
}
bool Unit::isDead(){
if(hp > 0) return false;
else return true;
}
int Unit::heal(){
int healing;
     healing = (rand()%21 + 10);
    if(healing+hp >= hpmax){
        healing = hpmax-hp ;
        hp = hpmax ;
        return healing ;
    }
     hp += healing;
     return healing;
}
int Unit::beAttacked(int oppatk){
   hp = hp - oppatk - def;
   return oppatk - def;
}
int Unit::attack(Unit &type){
	return type.beAttacked(atk);
}


void Unit::showstatus(){
	if(type == "Hero"){
		cout << "---------------------------------------\n"; 
		cout << type << "\n"; 
		cout << "HP: " << hp << "/" << hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def;		
		cout << "\n---------------------------------------\n";
	}	
	else if(type == "Monster"){
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

void getmoney(string type,int money){//ชนิดของ mons และ update money
    if(type == "Monster01"){
          money += 300; 
    }
    else if(type == "Monster02"){
           money += 700;
    }
    else if(type == "Monster03"){
           money += 1000;
    }
    else if(type == "Monster04"){
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
        }
        else{
            cout << "You can't afford it";
        }
    }
    if(click == '2'){//armor
       if(money > 300){
          def += 50;
          money -= 300;
       }
       else{
            cout << "You can't afford it";
        }
    }
    if(click == '3'){//med kit
       if(money > 50){
          medkit += 1;
          money -= 50;
       }
       else{
            cout << "You can't afford it";
        }
    }
    if(click == '4'){//rifle
       if(money > 1000){
          atk += (50+rand()%51);
          money -= 1000;
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
