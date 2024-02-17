#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character {
public:
    int health;
    int defense;

    Character() {
        health = 100;
        defense = 0;
    }
};

int randomCardValue(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(0));

    Character player;
    Character bot;

    int attackCards[20];
    int defenseCards[20];
    int healCards[10];
    int playerCards[5];
    int botCards[5];
    int playerChoice;
    int botChoice = rand() % 5 + 1;

    //สุ่มค่าไพ่
    for (int i = 0; i < 20; ++i) {
        attackCards[i] = randomCardValue(20, 50);
        defenseCards[i] = randomCardValue(10, 30);
    }
    for (int i = 0; i < 10; ++i) {
        healCards[i] = randomCardValue(5, 30);
    }

    //ไพ่ผู้เล่น (แสดงผล)
    cout << "Your cards:" << endl;
    for (int i = 0; i < 5; ++i) {
        playerCards[i] = randomCardValue(1, 3);
        cout << "Card " << i + 1 << ": " << playerCards[i] << endl;
    }   cout << "1. ATK card   2. DEF card   3. HEAL card" << endl;

    //ไพ่บอท (ไม่แสดงผล)
    for (int i = 0; i < 5; ++i) {
        botCards[i] = randomCardValue(1, 3);
    }

    for (int round = 1; round <= 3; ++round) {
        cout << "\nRound " << round << endl;
        
        cout << "Your turn - Choose a card to play (1-5): ";
        cin >> playerChoice;

        // ตรวจสอบว่าผู้เล่นเลือกไพ่โจมตีหรือป้องกันหรือรักษา
        if (playerCards[playerChoice - 1] == 1) { // ไพ่โจมตี
            // ลดเลือดของบอท
            bot.health -= attackCards[rand() % 20];
            cout << "Player attacked Bot!" << endl;
        } else if (playerCards[playerChoice - 1] == 2) { // ไพ่ป้องกัน
            // เพิ่มพลังป้องกันของผู้เล่น
            player.defense += defenseCards[rand() % 20];
            cout << "Player defended!" << endl;
        } else if (playerCards[playerChoice - 1] == 3) { // ไพ่รักษา
            // เพิ่มเลือดของผู้เล่น
            player.health += healCards[rand() % 10];
            cout << "Player healed!" << endl;
        }

        // ตรวจสอบว่าบอทเลือกไพ่โจมตีหรือป้องกันหรือรักษา
        if (botCards[botChoice - 1] == 1) {
            // ลดเลือดของผู้เล่น
            player.health -= attackCards[rand() % 20];
            cout << "Bot attacked Player!" << endl;
        } else if (botCards[botChoice - 1] == 2) {
            // เพิ่มพลังป้องกันของบอท
            bot.defense += defenseCards[rand() % 20];
            cout << "Bot defended!" << endl;
        } else if (botCards[botChoice - 1] == 3) {
            // เพิ่มเลือดของบอท
            bot.health += healCards[rand() % 10];
            cout << "Bot healed!" << endl;
        }

        // ลบไพ่ที่เล่นออกจากมือของผู้เล่นและบอท
        playerCards[playerChoice - 1] = 0;
        botCards[botChoice - 1] = 0;

        // สุ่มไพ่ใหม่เพื่อแทนที่ไพ่ที่เล่นแล้ว
        int newPlayerCard = randomCardValue(1, 3);
        int newBotCard = randomCardValue(1, 3);
        for (int i = 0; i < 5; ++i) {
            if (playerCards[i] == 0) {
                playerCards[i] = newPlayerCard;
                break;
            }
        }
        for (int i = 0; i < 5; ++i) {
            if (botCards[i] == 0) {
                botCards[i] = newBotCard;
                break;
            }
        }

        cout << "Your new card: " << newPlayerCard << endl;
        cout << "Your HP: " << player.health << "  Bot's HP: " << bot.health << endl;
    }

    return 0;
}
 