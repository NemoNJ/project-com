#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    int health = 100;
    int defense = 0;
};

// Function to generate random card values
int randomCardValue(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to distribute cards to players
void distributeCards(vector<int> &deck, vector<int> &hand, int numCards) {
    random_shuffle(deck.begin(), deck.end());
    for (int i = 0; i < numCards; ++i) {
        hand.push_back(deck.back());
        deck.pop_back();
    }
}

// Function to play a round
void playRound(vector<int> &deck, vector<int> &playerHand, vector<int> &botHand, Player &player, Player &bot) {
    cout << "\nPlayer's turn:" << endl;
    cout << "Player's hand: ";
    for (int card : playerHand) {
        cout << card << " ";
    }
    cout << endl;

    cout << "Bot's hand: ";
    for (int card : botHand) {
        cout << card << " ";
    }
    cout << endl;

    // Player's turn
    for (int i = 0; i < 2; ++i) {
        cout << "Choose a card to play (1-" << playerHand.size() << "): ";
        int choice;
        cin >> choice;
        int playerCard = playerHand[choice - 1];
        playerHand.erase(playerHand.begin() + choice - 1);

        cout << "Player plays card with value: " << playerCard << endl;

        if (playerCard >= 10 && playerCard <= 30) {
            player.defense += playerCard;
        } else {
            bot.health -= playerCard;
        }
    }

    // Bot's turn
    for (int i = 0; i < 2; ++i) {
        int botChoice = rand() % botHand.size();
        int botCard = botHand[botChoice];
        botHand.erase(botHand.begin() + botChoice);

        cout << "Bot plays card with value: " << botCard << endl;

        if (botCard >= 10 && botCard <= 30) {
            bot.defense += botCard;
        } else {
            player.health -= botCard;
        }
    }

    // Replace played cards with new random cards
    distributeCards(deck, playerHand, 2);
    distributeCards(deck, botHand, 2);
}

int main() {
    srand(time(0));

    // Initialize deck
    vector<int> deck;
    for (int i = 0; i < 20; ++i) {
        deck.push_back(randomCardValue(20, 50)); // Attack cards
        deck.push_back(randomCardValue(10, 30)); // Defense cards
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(randomCardValue(5, 30)); // Heal cards
    }

    // Initialize player's and bot's hand
    vector<int> playerHand;
    vector<int> botHand;
    distributeCards(deck, playerHand, 5); // Distribute 5 cards to player
    distributeCards(deck, botHand, 5);    // Distribute 5 cards to bot

    // Initialize player's and bot's attributes
    Player player;
    Player bot;

    // Main game loop
    while (true) {
        cout << "\nPlayer's Health: " << player.health << endl;
        cout << "Bot's Health: " << bot.health << endl;

        if (player.health <= 0) {
            cout << "Bot wins!" << endl;
            break;
        } else if (bot.health <= 0) {
            cout << "Player wins!" << endl;
            break;
        }

        playRound(deck, playerHand, botHand, player, bot);
    }

    return 0;
}
