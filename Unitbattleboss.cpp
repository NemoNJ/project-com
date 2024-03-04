#include <iostream>
#include <iomanip>
#include <cstdlib> // Include for using rand()
#include <ctime>   // Include for using time()
#include <string>
#include <windows.h>
using namespace std;

int PistolPrice = 150;
int ArmourPrice = 300;
int MedkitPrice = 100;
int AKPrice = 1000;
int grenadePrice = 200;
int grenadeDamage = 120;
int medkitHeal = 25+rand()%16;
class Player;
class Boss; // Forward declaration

class Player
{
public:
    Player(string name);
    string getname();
    void setname(string);
    void buyPistol();
    void buyArmour();
    void buyMedkit();
    void buyAK();
    void showshop();
    void buyGrenade();
    void GobuyPhase();
    void GetEnter();
    void attack(Boss &);
    void PlayerbeAttacked(int);
    void useGrenade(Boss &);
    void useMedkit();
    bool CheckDead();
    void addmoney(int);
    void playerWin(int);
    void playerLose();

    string name;
    int hpmax;
    int hp;
    int atk;
    int def;
    int super_atk;
    bool changeturn;
    int money;
    int grenade;
    int level;
    bool armor;
    bool isPistol;
    bool isAK;
    bool buyphase;
    bool isDead;
    int medkit = 0;
    bool isarmour  = false ; 
};
class Boss
{
public:
    Boss(string Name, int Hpmax, int Attack, int Def, int money);
    bool bossisDead();
    bool bossnewturn();
    void bossbeAttacked(int);
    int bossattack(Player &);
    void attack(Player &);
    int money;
    string name;
    int hpmax;
    int hp;
    int atk;
    int def;
    int super_atk;
    bool changeturn;
    bool isDead;
    bool CheckDead();
};

Player::Player(string name)
{
    this->name = name;
    money = 100;
    hpmax = 120;
    hp = 100;
    // hp = 10;
    atk = 5;
    def = rand() % 3 + 1;
    armor = false;
    isPistol = false;
    isAK = false;
    medkit = 0;
    grenade = 0;
    level = 1;
    changeturn = false;
    buyphase = false;
    isDead = false;
    cout << setw(62) << "Hello Player " << name << endl;

}
string Player::getname()
{
    return name;
}

void Player::setname(string Name)
{
    name = Name;
}
void Player::playerWin(int levelStage)
{
if(levelStage == 1){
/* ลงภาพ*/
    }
  if(levelStage == 2){
/* ลงภาพ*/
    }
     if(levelStage == 3){
/* ลงภาพ*/
    }
   if(levelStage == 4){
/* ลงภาพ*/
    }
};
void Player::playerLose()
{
/* ลงภาพ*/
};

void Player::showshop()
{
/* ลงภาพ*/
}



void Player::buyPistol()
{
    if (isPistol)
    {
        cout << setw(62) << "You already have it" << endl;
    }
    else if (money < PistolPrice)
    {
        cout << setw(62) << "You need more " << PistolPrice - money << " $\n";
    }
    else
    {
        money -= PistolPrice;
        isPistol = true;
        atk = 15 + rand()%11;
        cout << setw(62) << "Success Buy Pistol" << endl;
    }
}

void Player::buyArmour()
{
    if(!isarmour){
    if (money >= ArmourPrice)
    {
        money -= ArmourPrice;
        def += 10;
        isarmour = true ;
        cout << setw(62) << "Success Buy Armour" << endl;
    }
    else
    {
        cout << setw(62) << "You need more : " << ArmourPrice - money << " $\n";
    }}else{
        cout <<"You already have it\n" ;
    }
}

void Player::buyMedkit()
{
    if (money >= MedkitPrice)
    {
        money -= MedkitPrice;
        ++medkit ;
        cout << setw(62) << "Success Buy Medkit" << endl;
    }
    else
    {
        cout << setw(62) << "You need more : " << MedkitPrice - money << " $\n";
    }
}

void Player::buyAK()
{
    if (isAK)
    {
        cout << setw(62) << "You already have it" << endl;
    }
    else if (money < AKPrice)
    {
        cout << setw(62) << "You need more " << AKPrice - money << " $\n";
    }
    else
    {
        money -= AKPrice;
        isAK = true;
        atk = 55 + rand()%21;
        cout << setw(62) << "Success Buy AK" << endl;
    }
}

void Player::buyGrenade()
{
    if (grenade >= 2)
    {
        cout << "You Can Have Only 2 grenade" << endl;
    }
    else if (money >= grenadePrice)
    {
        money -= grenadePrice;
        grenade++;
        cout << setw(62) << "Success Buy Grenade" << endl;
    }
    else
    {
        cout << setw(62) << "You need more : " << grenadePrice - money << " $\n";
    }
}

void Player::GobuyPhase()
{
    buyphase = true;
    while (buyphase == true)
    {
        showshop();
        cout << setw(62) << "you choose : ";
        string choice;
        cin >> choice;
        if (choice == "T" || choice == "t")
        {
            buyphase = false;
            cin.ignore();
            GetEnter();
        }
        else if (choice == "1")
        {
            buyPistol();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "2")
        {
            buyArmour();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "3")
        {
            buyMedkit();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "4")
        {
            buyAK();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "5")
        {
            buyGrenade();
            cin.ignore();
            GetEnter();
        }
        else
        {
            cout << "Wrong input" << endl;
            cin.ignore();
            GetEnter();
        }
    }
}

void Player::GetEnter()
{
    cout << setw(62) << "Press Enter To go next";
    cin.get();
    system("cls"); // Assuming you are using Windows. Change to "clear" for Linux.
}

void Player::addmoney(int money)
{

    this->money += money;
}

Boss::Boss(string Name, int Hpmax, int Attack, int Def, int Money)
{
    this->name = Name;
    this->hpmax = Hpmax;
    this->hp = Hpmax;
    this->atk = Attack;
    this->def = Def;
    isDead = false;
    money = Money;
}

void Player::attack(Boss &Boss)
{
    int x = rand() % 100 + 1;
    if (x <= 10)
        Boss.bossbeAttacked(atk * 2);
    else
        Boss.bossbeAttacked(atk);
}

void Boss::bossbeAttacked(int damage)
{
    if (def > damage)
    {
        damage = 0;
    }
    else
    {
        hp -= (damage - def);
    }
    if (hp <= 0)
    {
        isDead = true;
    }
}

void Boss::attack(Player &Player1)
{
    Player1.PlayerbeAttacked(atk);
}

void Player::PlayerbeAttacked(int damage)
{
    if (def > damage)
    {
        damage = 0;
    }
    else
    {
        hp -= (damage - def);
    }
    if (hp <= 0)
    {
        isDead = true;
    }
}

void Player::useGrenade(Boss &Boss)
{
    if (grenade > 0)
    {
        Boss.bossbeAttacked(grenadeDamage);
        grenade--;
    }
    else
    {
        cout << "You Don't have Grenade\n";
    }
}

void Player::useMedkit()
{
    if (medkit > 0)
    {
        if (medkitHeal + hp >= hpmax)
        {
            hp = hpmax;
            medkit -= 1;
        }
        else
        {
            hp += medkitHeal;
            medkit -= 1;
        }
    }
    else
    {
        cout << "You Don't Have Medkits\n";
    }
}

bool Player::CheckDead()
{
    if (hp <= 0)
        isDead = true;
    return isDead;
}

bool Boss::CheckDead()
{
    if (hp <= 0)
        isDead = true;
    return isDead;
}
