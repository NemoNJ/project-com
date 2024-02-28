#include <iostream>
#include <string>
#include "Player.cpp"
using namespace std;
class Boss
{
public:
    Boss(string Name, int Hpmax, int Attack, int Def);

    string name;
    int hpmax;
    int hp;
    int atk;
    int def;
    int super_atk;
    bool changeturn;
    bool bossisDead();
    bool bossnewturn();
};

Boss::Boss(string Name, int Hpmax, int Attack, int Def)
{
    this->name = Name;
    this->hpmax = Hpmax;
    this->atk = Attack;
    this->def = Def;
    // cout << setw(62) << " Boss " << name << " Has created" << endl;
}
bool Boss::bossisDead(){
    if(hp > 0) return false;
    else return true;
}