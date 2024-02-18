#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "3Card.cpp"
using namespace std;

int randomCardValue(int min, int max) {
    return min + rand() % (max - min + 1);
}
int ArryRand(int min, int max) {
    return min + rand()%max;
}
void ShuffleCards(string Deck[] , string Type[]){
        for(int i = 0; i < 5; i++){
            Deck[i] = Type[ArryRand(0, 3)];
        }
}
bool ReturnUsedcard(string arry[]){
    string usedCheck = " used           ";
    int boolsum = 0;
        for(int i = 0; i < 5; i++){
            if (arry[i] == usedCheck) boolsum += 1;
        }
    if(boolsum == 5) return 1;
    else return 0;
}

string CheckCondition(string [], int , int [], int , int &, string [], int &);
int DMGConfig(int , int , int &);
int HpConfig(int , int &);

string usedCard(string card[], int arr){
    return card[arr] = " used           ";
}
string BotDoing(string [], int &, int &, int &, int [], int [], int [], int, int &);
string BotAction(int , int &, int[], int &);

void CoutHpDef(int hp1, int hp2, int def1, int def2, int DMG1, int HEAL1 , int DMG2, int HEAL2){
            cout << "                 Player's Health point: " << hp1;
            if(DMG2 > 0) cout << " - (" << abs(abs(DMG2 - def1) - HEAL1) << ") ";
            else if(HEAL1 > 0) cout << " + (" << abs(abs(DMG2 - def1) - HEAL1) << ") ";
            cout << setw(107) << "Bot's Health point: " << hp2;
            if(DMG1 > 0) cout << " - (" << abs(abs(DMG1 - def2) - HEAL2) << ") " << endl;
            else if(HEAL2 > 0) cout << " + (" << abs(abs(DMG1 - def2) - HEAL2) << ") " << endl;
            else cout << endl;
            cout << "                 Player's deffense point: " << def1 << "  ";
            cout << setw(107) << "Bot's deffense point: " << def2 << endl;
        
}

void Coutframe(int a, int b, int sw){
    for(int i = 0; i < sw; i++) cout << " ";
    for(int i = 0; i < b; i++) cout << " . ";
    for(int i = 0; i < a; i++) cout << "===";
    for(int i = 0; i < b; i++) cout << " . ";
    cout << endl;
}


int main(){
    srand(time(0));
    int PlayerHP = 100;
    int BotHP = 100; 

    int attackCards[20];
    int defenseCards[20];
    for (int i = 0; i < 20; ++i) {
        attackCards[i] = randomCardValue(20, 50);
        defenseCards[i] = randomCardValue(10, 30);
    }
    int healCards[10];
    for (int i = 0; i < 10; ++i) {
        healCards[i] = randomCardValue(5, 30);
    }

    string AllCardPlayer[5];
    string AllCardBot[5];
    string CardType[] = {"| Fury Strike     |", "| Damage Absolver |", "| Healing         |"};
    ShuffleCards(AllCardPlayer, CardType);
    ShuffleCards(AllCardBot, CardType);

    Coutframe(8, 6, 0);
    cout << "                  Player's cards(5 of 50):" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "                  Card " << i + 1 << ": " << AllCardPlayer[i] << endl;
    }
    Coutframe(8, 6, 0);
    int playerChoice;    
    int i = 0, d = 0;
    Frame("-");
    CoutHpDef(PlayerHP, BotHP, d, d, 0, 0, 0, 0);    
    do{
        int Atk = 0, heal = 0, shield = 0;
        int BAtk = 0, Bheal = 0, Bshield = 0;
        int Paction = 0, Baction = 0;
        cout << "\nRound " << i + 1 << endl;
        
        cout << "Your turn - Choose a card to play (1-5): ";
        cin >> playerChoice;
        cout << endl;
        ClearTerminal(33);
        i++;
        //CardType = " Fury Strike ", " Damage Absolver", " Healing"};
         // 1 = strike card , 2 = deffense card , 3 = heal card;
        if (playerChoice == 1){
            cout << "   your action:";
            if (AllCardPlayer[playerChoice - 1] == "| Fury Strike     |"){
                cout << CheckCondition(AllCardPlayer, 1, attackCards, playerChoice, Atk, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == "| Damage Absolver |"){
                cout << CheckCondition(AllCardPlayer, 2, defenseCards, playerChoice, shield, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == "| Healing         |"){
                cout << CheckCondition(AllCardPlayer, 3, healCards, playerChoice, heal, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            }
        else if (playerChoice == 2){
            cout << "   your action:";
            if (AllCardPlayer[playerChoice - 1] == "| Fury Strike     |"){
                cout << CheckCondition(AllCardPlayer, 1, attackCards, playerChoice, Atk, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
            }
            if (AllCardPlayer[playerChoice - 1] == "| Damage Absolver |"){
                cout << CheckCondition(AllCardPlayer, 2, defenseCards, playerChoice, shield, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
            }
            if (AllCardPlayer[playerChoice - 1] == "| Healing         |"){
                cout << CheckCondition(AllCardPlayer, 3, healCards, playerChoice, heal, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            }
        else if (playerChoice == 3){
            cout << "   your action:";
            if (AllCardPlayer[playerChoice - 1] == "| Fury Strike     |"){
                cout << CheckCondition(AllCardPlayer, 1, attackCards, playerChoice, Atk, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == "| Damage Absolver |"){
                cout << CheckCondition(AllCardPlayer, 2, defenseCards, playerChoice, shield, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == "| Healing         |"){
                cout << CheckCondition(AllCardPlayer, 3, healCards, playerChoice, heal, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }       
            }
        else if (playerChoice == 4){
            cout << "   your action:";
            if (AllCardPlayer[playerChoice - 1] == "| Fury Strike     |"){
                cout << CheckCondition(AllCardPlayer, 1, attackCards, playerChoice, Atk, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }   
            if (AllCardPlayer[playerChoice - 1] == "| Damage Absolver |"){
                cout << CheckCondition(AllCardPlayer, 2, defenseCards, playerChoice, shield, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == "| Healing         |"){
                cout << CheckCondition(AllCardPlayer, 3, healCards, playerChoice, heal, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }           
            }
        else if (playerChoice == 5){
            cout << "   your action:";
            if (AllCardPlayer[playerChoice - 1] == "| Fury Strike     |"){
                cout << CheckCondition(AllCardPlayer, 1, attackCards, playerChoice, Atk, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == "| Damage Absolver |"){
                cout << CheckCondition(AllCardPlayer, 2, defenseCards, playerChoice, shield, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == "| Healing         |"){
                cout << CheckCondition(AllCardPlayer, 3, healCards, playerChoice, heal, CardType, Paction);
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            }
        else cout << "------Nothing happened------" << endl;
        
        //random bot choice of action;
        int BotChoice = rand()%7 + 1;
        cout << setw(110) << "Bot's action:";
        cout << BotDoing(AllCardBot, BAtk, Bshield, Bheal, attackCards, defenseCards, healCards, BotChoice, Baction) << endl;
        TerminalSeclection(Paction, Baction);

        Coutframe(8, 6, 0);
        if(ReturnUsedcard(AllCardPlayer)) ShuffleCards(AllCardPlayer, CardType);
        cout << "                  Player's cards(5 of 50):" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "                  Card " << i + 1 << ": " << AllCardPlayer[i] << endl;
            }
        Coutframe(8, 6, 0);
        DMGConfig(BAtk, shield, PlayerHP);
        DMGConfig(Atk, Bshield, BotHP);
        if (BotHP < 0) BotHP = 0;
        if (PlayerHP < 0) PlayerHP = 0;
        HpConfig(Bheal, BotHP);
        HpConfig(heal, PlayerHP);
        Frame("-");
        CoutHpDef(PlayerHP, BotHP, shield, Bshield, Atk, heal, BAtk, Bheal);
        if (BotHP <= 0) {
            cout << endl;
            Coutframe(15, 10, 30);
            cout << endl << setw(86) << "You won!" << endl;
            cout << endl;
            Coutframe(15, 10, 30);
            GameOver = true;
            }
        else if (PlayerHP <= 0) {
            cout << endl;
            Coutframe(15, 10, 30);
            cout << endl << setw(86) << "You lost!" << endl;
            cout << endl;
            Coutframe(15, 10, 30);
            GameOver = true;    
            }
        
    }
    while(!GameOver); 
}

string CheckCondition(string C[], int Type, int card[], int N, int &action, string CType[], int &act){
    // 1 = strike card , 2 = deffense card , 3 = heal card;
    for(int i = 0; i < 5; i++){
        if (C[i] == CType[Type - 1]){
            if(Type == 1){ //strike
                action = card[rand() % 20];
                act = 1;
                return "  Fury Strike!!";
            }
            if(Type == 2){// deffense
                action = card[rand() % 20];
                act = 2;
                return "  Shield up";
            }
            if(Type == 3){// Healing
                action = card[rand() % 10];
                act = 3;
                return "  heal~~";
            }
        }
    }
}
int HpConfig(int hl, int &Hp){
    Hp += hl;
    if(Hp > 100) Hp = 100;
    return Hp;
}

int DMGConfig(int Dmg, int Def, int &Hp){
    if( Dmg > 0) Hp -= abs(Dmg - Def);
    return Hp;
}
// BC == AllCardBot , BCType == CardType for bot;
string BotDoing(string BC[], int &ATK, int &DEF, int &HEAL, int ATKcard[], int DEFcard[], int HEALcard[], int BotDoing, int &Bact){
    
    if (BotDoing == 1){
            if (BC[BotDoing - 1] == "| Fury Strike     |"){
                return BotAction(1, ATK, ATKcard, Bact);
                }
            if (BC[BotDoing - 1] == "| Damage Absolver |"){
                return BotAction(2, DEF, DEFcard, Bact);
                }
            if (BC[BotDoing - 1] == "| Healing         |"){
                return BotAction(3, HEAL, HEALcard, Bact);
                }
            }
        else if (BotDoing == 2){
            if (BC[BotDoing - 1] == "| Fury Strike     |"){
                return BotAction(1, ATK, ATKcard, Bact);
                }
            if (BC[BotDoing - 1] == "| Damage Absolver |"){
                return BotAction(2, DEF, DEFcard, Bact);
                }
            if (BC[BotDoing - 1] == "| Healing         |"){
                return BotAction(3, HEAL, HEALcard, Bact);
                }
            }
        else if (BotDoing == 3){
            if (BC[BotDoing - 1] == "| Fury Strike     |"){
                return BotAction(1, ATK, ATKcard, Bact);
                }
            if (BC[BotDoing - 1] == "| Damage Absolver |"){
                return BotAction(2, DEF, DEFcard, Bact);
                }
            if (BC[BotDoing - 1] == "| Healing         |"){
                return BotAction(3, HEAL, HEALcard, Bact);
                }      
            }
        else if (BotDoing == 4){
            if (BC[BotDoing - 1] == "| Fury Strike     |"){
                return BotAction(1, ATK, ATKcard, Bact);
                }
            if (BC[BotDoing - 1] == "| Damage Absolver |"){
                return BotAction(2, DEF, DEFcard, Bact);
                }
            if (BC[BotDoing - 1] == "| Healing         |"){
                return BotAction(3, HEAL, HEALcard, Bact);
                }          
            }
        else if (BotDoing == 5){
            if (BC[BotDoing - 1] == "| Fury Strike     |"){
                return BotAction(1, ATK, ATKcard, Bact);
                }
            if (BC[BotDoing - 1] == "| Damage Absolver |"){
                return BotAction(2, DEF, DEFcard, Bact);
                }
            if (BC[BotDoing - 1] == "| Healing         |"){
                return BotAction(3, HEAL, HEALcard, Bact);
                }
            }
        else if (BotDoing == 6) return BotAction(1, ATK, ATKcard, Bact);
        else if (BotDoing == 7) return BotAction(1, ATK, ATKcard, Bact);
           
}
//type = 1,2,3 , actype == atk/def/heal , Cardrand == atk/def/heal card 1-20
string BotAction( int type, int &ActType, int Cardrand[], int &Bact){
    if (type == 1){//Attack
        ActType = Cardrand[rand() % 20];
        Bact = 1;
        return "  Fierce Attack!!! (O.O)";
        }
    if (type == 2){// deffense
        ActType = Cardrand[rand() % 20];
        Bact = 2;
        return "  Guard Up!!";
        }
    if (type == 3){// Healing
        ActType = Cardrand[rand() % 10];
        Bact = 3;
        return "  Healing~~ (^-^)";
        }
}