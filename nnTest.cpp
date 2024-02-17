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
    cout << "Cards in your hand (5 of 50):" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Card " << i + 1 << ": " << CardType[ArryRand(0, 3)] << endl;
        for(int i = 0; i < 8; i++) cout << "---";
        cout << endl;
    }
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
        case 1:
            cout << CheckCondition(AllCardType, 1, attackCards, playerChoice, Bot, CardType) << endl;
            break;
        case 2:
            cout << CheckCondition(AllCardType, 2, defenseCards, playerChoice, Player, CardType) << endl;
            break;
        case 3:
            cout << CheckCondition(AllCardType, 3, healCards, playerChoice, Player, CardType) << endl;
            break;
        }
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
                C.at(N-1) = "used";
                response = "Fury Strike!!!";
                return response;
                break;
            case 2: // deffense
                PB.DEF += card[rand() % 20];
                C.at(N-1) = "used";
                response = "Shield up";
                return response;
                break;
            case 3: // Healing
                PB.HP += card[rand() % 10];
                C.at(N-1) = "used";
                response = "heal~~";
                return response;
                break;
            }
        return "";
    }
}