#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int randomCardValue(int min, int max) {
    return min + rand() % (max - min + 1);
}
int ArryRand(int min, int max) {
    return min + rand()%max;
}

string CheckCondition(string [], int , int [], int , int &, string []);
int DMGConfig(int , int , int &);
int HpConfig(int , int &);

string usedCard(string card[], int arr){
    return card[arr] = "used";
}
    
int main(){
    srand(time(0));
    int PlayerHP = 100;
    int BotHP = 100; 
    bool GameOver = false;

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
    string BC   [5];
    string CardType[] = {" Fury Strike", " Damage Absolver", " Healing"};
    for(int i = 0; i < 5; i++){
        AllCardPlayer[i] = (CardType[ArryRand(0, 3)]);
        BC  [i] = (CardType[ArryRand(0, 3)]);
    }
    for(int i = 0; i < 8; i++) cout << "---";
    cout << endl;
    cout << "Cards in your hand (5 of 50):" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Card " << i + 1 << ": " << AllCardPlayer[i] << endl;
    }
    for(int i = 0; i < 8; i++) cout << "---";
    cout << endl;
    int playerChoice;    
    int i = 0;
    do{
        int Atk = 0, heal = 0, shield = 0;
        cout << "\nRound " << i + 1 << endl;
        cout << "Your turn - Choose a card to play (1-5): ";
        cin >> playerChoice;
        i++;
        //CardType = " Fury Strike ", " Damage Absolver", " Healing"};
         // 1 = strike card , 2 = deffense card , 3 = heal card;
        if (playerChoice == 1){
            if (AllCardPlayer[playerChoice - 1] == " Fury Strike"){
                cout << CheckCondition(AllCardPlayer, 1, attackCards, playerChoice, Atk, CardType) << endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == " Damage Absolver"){
                cout << CheckCondition(AllCardPlayer, 2, defenseCards, playerChoice, shield, CardType) << endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == " Healing"){
                cout << CheckCondition(AllCardPlayer, 3, healCards, playerChoice, heal, CardType) << endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            }
        else if (playerChoice == 2){
            if (AllCardPlayer[playerChoice - 1] == " Fury Strike"){
                cout << CheckCondition(AllCardPlayer, 1, attackCards, playerChoice, Atk, CardType) << endl;
                usedCard(AllCardPlayer, playerChoice - 1);
            }
            if (AllCardPlayer[playerChoice - 1] == " Damage Absolver"){
                cout << CheckCondition(AllCardPlayer, 2, defenseCards, playerChoice, shield, CardType) << endl;
                usedCard(AllCardPlayer, playerChoice - 1);
            }
            if (AllCardPlayer[playerChoice - 1] == " Healing"){
                cout << CheckCondition(AllCardPlayer, 3, healCards, playerChoice, heal, CardType)<< endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            }
        else if (playerChoice == 3){
            if (AllCardPlayer[playerChoice - 1] == " Fury Strike"){
                cout << CheckCondition(AllCardPlayer, 1, attackCards, playerChoice, Atk, CardType)<< endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == " Damage Absolver"){
                cout << CheckCondition(AllCardPlayer, 2, defenseCards, playerChoice, shield, CardType)<< endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == " Healing"){
                cout << CheckCondition(AllCardPlayer, 3, healCards, playerChoice, heal, CardType)<< endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }       
            }
        else if (playerChoice == 4){
            if (AllCardPlayer[playerChoice - 1] == " Fury Strike"){
                cout << CheckCondition(AllCardPlayer, 1, attackCards, playerChoice, Atk, CardType)<< endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }   
            if (AllCardPlayer[playerChoice - 1] == " Damage Absolver"){
                cout << CheckCondition(AllCardPlayer, 2, defenseCards, playerChoice, shield, CardType)<< endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == " Healing"){
                cout << CheckCondition(AllCardPlayer, 3, healCards, playerChoice, heal, CardType)<< endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }           
            }
        else if (playerChoice == 5){
            if (AllCardPlayer[playerChoice - 1] == " Fury Strike"){
                cout << CheckCondition(AllCardPlayer, 1, attackCards, playerChoice, Atk, CardType)<< endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == " Damage Absolver"){
                cout << CheckCondition(AllCardPlayer, 2, defenseCards, playerChoice, shield, CardType)<< endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            if (AllCardPlayer[playerChoice - 1] == " Healing"){
                cout << CheckCondition(AllCardPlayer, 3, healCards, playerChoice, heal, CardType)<< endl;
                usedCard(AllCardPlayer, playerChoice - 1);
                }
            }
        else cout << "------Try Again------" << endl;

        for(int i = 0; i < 8; i++) cout << "---";
        cout << endl;
        cout << "Your cards left:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "Card " << i + 1 << ": " << AllCardPlayer[i] << endl;
            }
        for(int i = 0; i < 8; i++) cout << "---";
        cout << endl;

        DMGConfig(Atk, shield, PlayerHP);
        DMGConfig(Atk, shield, BotHP);

        if (BotHP < 0) BotHP = 0;
        if (PlayerHP < 0) PlayerHP = 0;
        HpConfig(heal, BotHP);
        HpConfig(heal, PlayerHP);
        cout << "Bot's HP: " << BotHP << endl;
        cout << "Player's HP: " << PlayerHP << endl;
        if (BotHP <= 0) {
            cout << "You won!" << endl;
            GameOver = true;
            }
        else if (PlayerHP <= 0) {
            cout << "You lost!" << endl;
            GameOver = true;    
            }
        }
    while(!GameOver); 
}

string CheckCondition(string C[], int Type, int card[], int N, int &action, string CType[]){
    // 1 = strike card , 2 = deffense card , 3 = heal card;
    for(int i = 0; i < 5; i++){
        if (C[i] == CType[Type - 1]){
            if(Type == 1){ //strike
                action = card[rand() % 20];
                return "     Fury Strike!!!";
            }
            if(Type == 2){// deffense
                action = card[rand() % 20];
                return "     Shield up";
            }
            if(Type == 3){// Healing
                action = card[rand() % 10];
                return "     heal~~";
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
    Hp -= Dmg - Def;
    return Hp;
}

string BotAction(string BC[], int BType, int Bcard[], int B, int &Baction, string BCType[]){
    if()
    
    int botChoice = rand()%5 +1;
    for(int i = 0; i < 5; i++){
        if (BC[i] == BCType[BType - 1]){
            if(BType == 1){ //strike
                Baction = Bcard[rand() % 20];
                return "     Fierce Attack!!! (O.O)";
            }
            if(BType == 2){// deffense
                Baction = Bcard[rand() % 20];
                return "     Guard Up!!";
            }
            if(BType == 3){// Healing
                Baction = Bcard[rand() % 10];
                return "     Healing~~ (^-^)";
            }
        }
    }
    if (botChoice == 1){
            if (BC[botChoice - 1] == " Fury Strike"){
                cout << CheckCondition(BC, 1, attackCards, playerChoice, Atk, CardType) << endl;
                usedCard(BC, botChoice - 1);
                }
            if (BC[botChoice - 1] == " Damage Absolver"){
                cout << CheckCondition(BC, 2, defenseCards, playerChoice, shield, CardType) << endl;
                usedCard(BC, botChoice - 1);
                }
            if (BC[botChoice - 1] == " Healing"){
                cout << CheckCondition(BC   , 3, healCards, playerChoice, heal, CardType) << endl;
                usedCard(BC , botChoice - 1);
                }
            }
        else if (botChoice == 2){
            if (BC  [botChoice - 1] == " Fury Strike"){
                cout << CheckCondition(BC   , 1, attackCards, playerChoice, Atk, CardType) << endl;
                usedCard(BC , botChoice - 1);
            }
            if (AllCardPAllCardBotlayer[botChoice - 1] == " Damage Absolver"){
                cout << CheckCondition(BC   , 2, defenseCards, playerChoice, shield, CardType) << endl;
                usedCard(BC , botChoice - 1);
            }
            if (BC  [botChoice - 1] == " Healing"){
                cout << CheckCondition(BC   , 3, healCards, playerChoice, heal, CardType)<< endl;
                usedCard(BC , botChoice - 1);
                }
            }
        else if (botChoice == 3){
            if (BC  [botChoice - 1] == " Fury Strike"){
                cout << CheckCondition(BC   , 1, attackCards, playerChoice, Atk, CardType)<< endl;
                usedCard(BC , botChoice - 1);
                }
            if (BC  [botChoice - 1] == " Damage Absolver"){
                cout << CheckCondition(BC   , 2, defenseCards, playerChoice, shield, CardType)<< endl;
                usedCard(BC , botChoice - 1);
                }
            if (BC  [botChoice - 1] == " Healing"){
                cout << CheckCondition(BC   , 3, healCards, playerChoice, heal, CardType)<< endl;
                usedCard(BC , botChoice - 1);
                }       
            }
        else if (botChoice == 4){
            if (AllCardPlayer[botChoice - 1] == " Fury Strike"){
                cout << CheckCondition(BC   , 1, attackCards, playerChoice, Atk, CardType)<< endl;
                usedCard(BC , botChoice - 1);
                }   
            if (AllCardPlayer[botChoice - 1] == " Damage Absolver"){
                cout << CheckCondition(BC   , 2, defenseCards, playerChoice, shield, CardType)<< endl;
                usedCard(BC , botChoice - 1);
                }
            if (AllCardPlayer[botChoice - 1] == " Healing"){
                cout << CheckCondition(BC   , 3, healCards, playerChoice, heal, CardType)<< endl;
                usedCard(BC , botChoice - 1);
                }           
            }
        else if (botChoice == 5){
            if (AllCardPlayer[botChoice - 1] == " Fury Strike"){
                cout << CheckCondition(BC   , 1, attackCards, playerChoice, Atk, CardType)<< endl;
                usedCard(BC , botChoice - 1);
                }
            if (AllCardPlayer[botChoice - 1] == " Damage Absolver"){
                cout << CheckCondition(BC   , 2, defenseCards, playerChoice, shield, CardType)<< endl;
                usedCard(BC , botChoice - 1);
                }
            if (AllCardPlayer[botChoice - 1] == " Healing"){
                cout << CheckCondition(BC   , 3, healCards, playerChoice, heal, CardType)<< endl;
                usedCard(BC , botChoice - 1);
                }
            }
    
}