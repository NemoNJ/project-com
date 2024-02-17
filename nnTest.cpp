#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct health{
    int HP = 100;
    int DEF = 0;
};

int randomCardValue(int min, int max) {
    return min + rand() % (max - min + 1);
}
int ArryRand(int min, int max) {
    return min + rand()%max;
}

string CheckCondition(vector<string>, int , int [], int , health, string []);

void usedCard(vector<string> card, int arr){
    card.at(arr) = "used";
}
    
int main(){
    srand(time(0));

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

    vector<string> AllCardType;
    string CardType[] = {" Fury Strike ", " Damage Absolver", " Healing"};
    for(int i = 0; i < 5; i++){
        AllCardType.push_back(CardType[ArryRand(0, 3)]);
    }
    int playerCards[5];
    for(int i = 0; i < 8; i++) cout << "---";
    cout << endl;
    cout << "Cards in your hand (5 of 50):" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Card " << i + 1 << ": " << AllCardType[i] << endl;
    }
    for(int i = 0; i < 8; i++) cout << "---";
    cout << endl;
    health Player; 
    health Bot;
    int playerChoice;    
    int i = 0;
    do{
        cout << "\nRound " << i + 1 << endl;
        cout << "Your turn - Choose a card to play (1-5): ";
        cin >> playerChoice;
        i++;
        switch (playerChoice)
        {//CardType = " Fury Strike ", " Damage Absolver", " Healing"};
         // 1 = strike card , 2 = deffense card , 3 = heal card;
        if (playerChoice == 1){
            if (CardType[0] == " Fury Strike ")
            cout << CheckCondition(AllCardType, 1, attackCards, playerChoice, Bot, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            if (CardType[0] == " Damage Absolver ")
            cout << CheckCondition(AllCardType, 2, defenseCards, playerChoice, Player, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            if (CardType[0] == " Healing ")
            cout << CheckCondition(AllCardType, 3, healCards, playerChoice, Player, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            }
        if (playerChoice == 2){
            if (CardType[1] == " Fury Strike ")
            cout << CheckCondition(AllCardType, 1, attackCards, playerChoice, Bot, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            if (CardType[1] == " Damage Absolver ")
            cout << CheckCondition(AllCardType, 2, defenseCards, playerChoice, Player, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            if (CardType[1] == " Healing ")
            cout << CheckCondition(AllCardType, 3, healCards, playerChoice, Player, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            }
        if (playerChoice == 3){
            if (CardType[2] == " Fury Strike ")
            cout << CheckCondition(AllCardType, 1, attackCards, playerChoice, Bot, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            if (CardType[2] == " Damage Absolver ")
            cout << CheckCondition(AllCardType, 2, defenseCards, playerChoice, Player, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            if (CardType[2] == " Healing ")
            cout << CheckCondition(AllCardType, 3, healCards, playerChoice, Player, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            }
        if (playerChoice == 4){
            if (CardType[3] == " Fury Strike ")
            cout << CheckCondition(AllCardType, 1, attackCards, playerChoice, Bot, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            if (CardType[3] == " Damage Absolver ")
            cout << CheckCondition(AllCardType, 2, defenseCards, playerChoice, Player, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            if (CardType[3] == " Healing ")
            cout << CheckCondition(AllCardType, 3, healCards, playerChoice, Player, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            }
        if (playerChoice == 5){
            if (CardType[4] == " Fury Strike ")
            cout << CheckCondition(AllCardType, 1, attackCards, playerChoice, Bot, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            if (CardType[4] == " Damage Absolver ")
            cout << CheckCondition(AllCardType, 2, defenseCards, playerChoice, Player, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            if (CardType[4] == " Healing ")
            cout << CheckCondition(AllCardType, 3, healCards, playerChoice, Player, CardType) << endl;
            usedCard(AllCardType, playerChoice - 1);
            }
        }
    for(int i = 0; i < 8; i++) cout << "---";
        cout << endl;
    cout << "Your cards left:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Card " << i + 1 << ": " << AllCardType[i] << endl;
        }
    for(int i = 0; i < 8; i++) cout << "---";
        cout << endl;
    }
    while(Bot.HP > 0); 
    
    return 0;
}

string CheckCondition(vector<string> C, int Type, int card[], int N, health PB, string CType[]){
    // 1 = strike card , 2 = deffense card , 3 = heal card;
    string response;
        if (find (C.begin(), C.end(), CType[Type - 1]) != C.end()){
            switch (Type)
            {
            case 1: //strike
                PB.HP -= card[rand() % 20];
                response = "Fury Strike!!!";
                return response;
                break;
            case 2: // deffense
                PB.DEF += card[rand() % 20];
                response = "Shield up";
                return response;
                break;
            case 3: // Healing
                PB.HP += card[rand() % 10];
                response = "heal~~";
                return response;
                break;
            }
        return "";
    }
}