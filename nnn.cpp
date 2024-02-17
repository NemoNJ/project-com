#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// การสร้างคลาสสำหรับตัวละคร
class Character {
    string name;
	string type;		
	int hp;
	int hpmax;
	int atk;
	int def;
	bool guard_on;	
public:
    int health;
    int defense;
    void createplayer(string );
    void randomCardValue(int , int );
    void Chars();
    void attackCards();
    void defenseCards();
    void healCards();

};
void Character::createplayer(string p){ 
	if(p == "Player"){
		type = "player";
		cout << "Please input your name: ";
		getline(cin,name);
	}else if(p == "AI"){
		type = "AI";
		name = "ROBOT";
		
	}
}

void Character::Chars() {
        health = 100;
        defense = 0;
}

void Character::randomCardValue(int min, int max) {
    return min + rand() % (max - min + 1);
}

void Character::attackCards(){
    srand(time(0));
    for (int i = 0; i < 20; ++i) {
    attackCards[i] = randomCardValue(20, 50);
    }
}

void Characters::defenseCards(){
    srand(time(0));
    for (int i = 0; i < 20; ++i) {
    defenseCards[i] = randomCardValue(10, 30);
    }
}

void Character::healCards(){
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        healCards[i] = randomCardValue(5, 30);
    }
}

int main() {
    cout << "Player's cards:" << endl;
    for (int i = 0; i < 5; ++i) {
        playerCards[i] = randomCardValue(1, 3);
        cout << "Card " << i + 1 << ": " << playerCards[i] << endl;
    }
    
    for (int round = 1; round <= 3; ++round) {
        cout << "\nRound " << round << endl;
        // ผู้เล่นลงไพ่
        int playerChoice;
        cout << "Player's turn - Choose a card to play (1-5): ";
        cin >> playerChoice;
        // บอทลงไพ่ (สุ่มเลือก)
        int botChoice = rand() % 5 + 1;

        // คำนวณผลลัพธ์จากการลงไพ่และสุ่มไพ่ใหม่
        // สามารถเขียนโค้ดส่วนนี้ต่อไปเพื่อคำนวณตามเงื่อนไขของเกมไพ่ได้
        cout << "Player chose card " << playerChoice << " - Bot chose card " << botChoice << endl;
        // คำนวณผลลัพธ์และสุ่มไพ่ใหม่ต่อไป...

    }
    return 0;
}