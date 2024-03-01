#include "3Card.cpp"
using namespace std;


struct Stat{
    int Hpoint;
    int Defpoint;
    int ATK;
    int DEF;
    int HEAL;
};

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
string UsedDetect(int &, Stat &);

// PlayerCards[] , attackCards[] , deffenseCards[] , healCards[] , PlayerChoice, Stat Py, string CardType[], Paction;
string CheckCondition(string [], int [], int [], int [], int , Stat &, string [], int &);

int DMGConfig(Stat &, Stat &, int &);
int HealConfig(Stat &, int &);

string usedCard(string card[], int arr){
    return card[arr] = " used           ";
}

//BotCards[] , Stat Bt , attackCards[] , deffenseCards[] , healCards[] , BotChoice , CardType[] , Baction;
string BotDoing(string [], Stat &,int [], int [], int [], int, string [], int &);
// Type of CardType(0,1,2) , Stat Bt , (atk,def,heal) Cards , Baction;
string BotAction(int , Stat &, int[], int &);

void CoutHpDef(Stat &P, Stat &B, int &Php, int &Bhp){
            cout << "                 Player's Health point: " << Php;
            if(B.ATK > 0) cout << " - (" << abs(abs(B.ATK - P.DEF) - P.HEAL) << ") ";
            else if(P.HEAL > 0) cout << " + (" << abs(abs(B.ATK - P.DEF) - P.HEAL) << ") ";
            cout << setw(107) << "Bot's Health point: " << Bhp;
            if(P.ATK > 0) cout << " - (" << abs(abs(P.ATK - B.DEF) - B.HEAL) << ") " << endl;
            else if(B.HEAL > 0) cout << " + (" << abs(abs(P.ATK - B.DEF) - B.HEAL) << ") " << endl;
            else cout << endl;
            cout << "                 Player's deffense point: " << P.DEF << "  ";
            cout << setw(107) << "Bot's deffense point: " << B.DEF << endl;
        
}
void CoutGameOver(int, int, int , bool &);

void Coutframe(int a, int b, int sw){
    for(int i = 0; i < sw; i++) cout << " ";
    for(int i = 0; i < b; i++) cout << " . ";
    for(int i = 0; i < a; i++) cout << "===";
    for(int i = 0; i < b; i++) cout << " . ";
    cout << endl;
}

//======================================================================------ Start Program ------===================================================================//
int main(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(color , 15);
    cout << endl; 
    cout << "                ------------------------------------============== * * * * |   Welcome to the game   | * * * * ==============------------------------------------" << endl;
    cout << endl;
    cout << "                This game is played by using cards from all 50 cards that were shuffled to your hand for 5 cards." << endl;
    cout << "                If you have played all of your cards,  don't worry, cards will shuffle to your hand again." << endl; 
    cout << "                All most forgot,  you have to play against Bot and both of you have 100 hp.  Hope you enjoy!!" << endl;

    cout << "-----Press Enter to continue------" ;
    cin.get();
    cout << endl;
    cout << "There are 3 type of cards. As follows: " << endl;
    cout << endl;
    CoutATK();
    CoutShield();
    CoutHeal();
    ClearTerminal(33);
    TerminalDefault();

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
    int round = 0;
    Frame("-");
    // pre stat (hp, def, atk, heal)
    Stat PreP = {100, 0, 0,0,0};
    Stat PreB = {100, 0, 0,0,0};
    //cout standard hp, def
    CoutHpDef(PreP, PreB, PlayerHP, BotHP);
    int TotalDMG_P = 0, TotalHEAL_P = 0, Blocked_P = 0;
    int TotalDMG_B = 0, TotalHEAL_B = 0, Blocked_B = 0;
//======================================================================------ Start Game ------===================================================================//
    do{

        Stat Py = {PlayerHP, 0, 0,0,0};
        Stat Bt = {BotHP, 0, 0,0,0};
        
        int Paction = 0, Baction = 0;
        cout << "\nRound " << round + 1 << endl;
        
        cout << "Your turn - Choose a card to play (1-5): ";
        cin >> playerChoice;
        int PyC = playerChoice - 1;
        cout << endl;
        ClearTerminal(33);
        round++;
        //CardType = " Fury Strike ", " Damage Absolver", " Healing"};
         // 1 = strike card , 2 = deffense card , 3 = heal card;
        switch (PyC)
        {
        case 0:// 1
            cout << "   your action:";
            cout << CheckCondition(AllCardPlayer, attackCards, defenseCards, healCards, playerChoice, Py, CardType, Paction);
            usedCard(AllCardPlayer, PyC);
            break;
        
        case 1:// 2
            cout << "   your action:";
            cout << CheckCondition(AllCardPlayer, attackCards, defenseCards, healCards, playerChoice, Py, CardType, Paction);
            usedCard(AllCardPlayer, PyC);
            break;

        case 2:// 3
            cout << "   your action:";
            cout << CheckCondition(AllCardPlayer, attackCards, defenseCards, healCards, playerChoice, Py, CardType, Paction);
            usedCard(AllCardPlayer, PyC);
            break;
        
        case 3:// 4
            cout << "   your action:";
            cout << CheckCondition(AllCardPlayer, attackCards, defenseCards, healCards, playerChoice, Py, CardType, Paction);
            usedCard(AllCardPlayer, PyC);
            break;

        case 4: // 5 
            cout << "   your action:";
            cout << CheckCondition(AllCardPlayer, attackCards, defenseCards, healCards, playerChoice, Py, CardType, Paction);
            usedCard(AllCardPlayer, PyC);
            break;
        }
        TotalDMG_P += Py.ATK;
        
        TotalHEAL_P += Py.HEAL;

        //random bot choice of action;
        int BotChoice = rand()%7 + 1;
        cout << setw(110) << "Bot's action:";
        cout << BotDoing(AllCardBot, Bt, attackCards, defenseCards, healCards, BotChoice, CardType, Baction) << endl;
        TotalDMG_B += Bt.ATK;
        TotalHEAL_B += Bt.HEAL;

        if(Py.ATK > 0 && Bt.DEF > 0) Blocked_B += abs(Bt.DEF - Py.ATK);
        if(Bt.ATK > 0 && Py.DEF > 0) Blocked_P += abs(Py.DEF - Bt.ATK);

        TerminalSeclection(Paction, Baction);

        Coutframe(8, 6, 0);
        if(ReturnUsedcard(AllCardPlayer)) ShuffleCards(AllCardPlayer, CardType);
        cout << "                  Player's cards(5 of 50):" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "                  Card " << i + 1 << ": " << AllCardPlayer[i] << endl;
            }
        Coutframe(8, 6, 0);
        // Bt atk - Def Py == PlayerHp;
        DMGConfig(Bt, Py, PlayerHP);
        DMGConfig(Py, Bt, BotHP);
        if (BotHP < 0) BotHP = 0;
        if (PlayerHP < 0) PlayerHP = 0;
        HealConfig(Bt, BotHP);
        HealConfig(Py, PlayerHP);
        Frame("-");
        CoutHpDef(Py, Bt, PlayerHP, BotHP);
        
        int Playerhealth = PlayerHP;
        int Bothealth = BotHP;
        CoutGameOver(Playerhealth, Bothealth, round, GameOver);
    }
    while(!GameOver);
    cout << "                             your total damage: " << TotalDMG_P;
    cout << setw(86) << "Bot total damage: " << TotalDMG_B << endl;
    cout << "                             your total heal: " << TotalHEAL_P;
    cout << setw(86) << "Bot total heal: " << TotalHEAL_B << endl;
    cout << "                             damage Blocked: " << Blocked_P;
    cout << setw(87) << "damage blocked: " << Blocked_B << endl;
    cout << endl;
}
//=============================================================------ End program ------============================================================================//

string UsedDetect(int &act, Stat &Pyaction){
    act = 0;
    Pyaction.ATK = 0;
    Pyaction.HEAL = 0;
    Pyaction.DEF = 0;
    return " Absolutely nothing...";
}


string CheckCondition(string C[],int Atk[], int Def[], int Heal[], int PyC, Stat &action, string CType[], int &act){
    // 1 = strike card , 2 = deffense card , 3 = heal card;
    //PyC == PlayerChoice;
    if(C[PyC - 1] == " used           ") return UsedDetect(act, action);
    if(C[PyC - 1] == CType[0]){
        //strike
            action.ATK = Atk[rand()%21];
            act = 1;
            return "  Fury Strike!!";
        }
    if(C[PyC - 1] == CType[1]){
        // deffense
            action.DEF = Def[rand()%21];
            act = 2;
            return "  Shield up";
            
        }
        if(C[PyC - 1] == CType[2]){
        // Healing
            action.HEAL = Heal[rand()%11];
            act = 3;
            return "  heal~~";
            
    }
}
int HealConfig(Stat &Hl, int &Hp){
    Hp += Hl.HEAL;
    if(Hp > 100) Hp = 100;
    return Hp;
}

int DMGConfig(Stat &Act1, Stat &Act2, int &Hp2){
    if( Act1.ATK > 0) Hp2 -= abs(Act1.ATK - Act2.DEF);
    return Hp2;
}
// BC == AllCardBot , BCType == CardType for bot;
//Botdoing == BotChoice, CType[] == CardType[];
string BotDoing(string BC[], Stat &Bot, int Atk_B[], int Def_B[], int Heal_B[], int BotDoing, string CType[] , int &Bact){

    if (BC[BotDoing - 1] == CType[0]){
        return BotAction(1, Bot, Atk_B, Bact);
        }
    if (BC[BotDoing - 1] == CType[1]){
        return BotAction(2, Bot, Def_B, Bact);
        }
    if (BC[BotDoing - 1] == CType[2]){
    return BotAction(3, Bot, Heal_B, Bact);
    }
    if (BotDoing == 6) return BotAction(1, Bot, Atk_B, Bact);
    if (BotDoing == 7) return BotAction(1, Bot, Atk_B, Bact);
           
}
//type = 1,2,3 , actype == atk/def/heal , Cardrand == atk/def/heal card 1-20
string BotAction( int type, Stat &botActType, int Cardrand[], int &Bact){
    if (type == 1){//Attack
        botActType.ATK = Cardrand[rand() % 21];
        Bact = 1;
        return "  Fierce Attack!!! (O.O)";
        }
    if (type == 2){// deffense
        botActType.DEF = Cardrand[rand() % 21];
        Bact = 2;
        return "  Guard Up!!";
        }
    if (type == 3){// Healing
        botActType.HEAL = Cardrand[rand() % 11];
        Bact = 3;
        return "  Healing~~ (^-^)";
        }
}

void CoutGameOver(int PHP, int BHP, int r, bool &GameCheck){
    if(PHP <= 0 && BHP > 0){
        ClearTerminal(32);
        Coutframe(15, 10, 30);
        cout << endl << setw(86) << "You lost!!" << endl;
        cout << setw(85) << "at round " << r + 1 << endl;
        cout << endl;
        Coutframe(15, 10, 30);
        ClearTerminal(10);
        GameCheck = 1;
    }
    if(PHP > 0 && BHP <= 0){
        ClearTerminal(32);
        Coutframe(15, 10, 30);
        cout << endl << setw(86) << "You won!!" << endl;
        cout << setw(85) << "at round " << r + 1 << endl;
        cout << endl;
        Coutframe(15, 10, 30);
        ClearTerminal(10);
        GameCheck = 1;
        }
    else if(PHP == 0 && BHP == 0){
        ClearTerminal(32);
        Coutframe(15, 10, 30);
        cout << endl << setw(86) << " Draw!!!" << endl;
        cout << setw(85) << "at round " << r + 1 << endl;
        cout << endl;
        Coutframe(15, 10, 30);
        ClearTerminal(10);
        GameCheck = 1;
        }
}