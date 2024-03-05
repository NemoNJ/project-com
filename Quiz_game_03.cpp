#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int one() {
    SetConsoleTextAttribute(color , 13);
    cout << "                                           " << endl;
    cout << "************************************  Started Relaxing Quiz Game 1 ************************************" << endl;
    cout << "                                           " << endl;
    int score = 0;
    srand(time(0));
    switch (1) {
        case 1: {
            SetConsoleTextAttribute(color , 14);
            int a = rand() % 1000;
            int b = rand() % 1000;
            int sum = a + b;
            cout << "1.) What is " << a << " + " << b << " ?" << endl;
            int a1;
            cout << "             "<< endl;
            cout << "Your Answer :";
            cin >> a1;
            if (a1 == sum) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< sum << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 2: {
            SetConsoleTextAttribute(color , 14);
            cout << "2.) How to wash dishes without getting your hands wet?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q2[] = {" Wash and dry your hands."," Wash and dry in the sun.", " Wash without water.", " Use someone else to wash."};
            for (int i=0; i < sizeof(q2)/sizeof(q2[0]); i++) {
                cout << i+1 << ". " << q2[i] << endl;
            }
            int a2;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a2;
            if (a2 == 4) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q2[3] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 3: {
            SetConsoleTextAttribute(color , 14);
            cout << "3.) In a race, if you are in third place ,and you passed the third; what position are you in?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q3[] = {"First ","Second ","Third ","Fourth "};
            for (int i=0; i < sizeof(q3)/sizeof(q3[0]); i++) {
                cout << i+1 << ". " << q3[i] << endl;
            }
            int a3;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a3;
            SetConsoleTextAttribute(color , 13);
            if (a3 == 2) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q3[1] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 4: {
            SetConsoleTextAttribute(color , 14);
            cout << "4.)3 brothers rode a buffalo backhome. The older sit at the head and the middle sit on the back. The younger sit behind. Do you know where a buffalo is the heaviest??" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q4[] = {"Head ", "Middle ", "Behind", "Don't know"};
            for (int i=0; i < sizeof(q4)/sizeof(q4[0]); i++) {
                cout << i+1 << ". " << q4[i] << endl;
            }
            int a4;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a4;
            SetConsoleTextAttribute(color , 13);
            if (a4 == 4) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q4[3] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 5: {
            SetConsoleTextAttribute(color , 14);
            cout << "5.) Have 200 people standing in this line. Who were Isaan people?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q5[] = {"1 ", "9 ", "101 ","200 "};
            for (int i=0; i < sizeof(q5)/sizeof(q5[0]); i++) {
                cout << i+1 << ". " << q5[i] << endl;
            }
            int a5;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a5;
            if (a5 == 3) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q5[2] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 6: {
            SetConsoleTextAttribute(color , 14);
            cout << "6.) Have 100 people standing on a cliff and Who people will fall off a cliff and die?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q6[] = {"1 ", "9 ", "19 ","100 "};
            for (int i=0; i < sizeof(q6)/sizeof(q6[0]); i++) {
                cout << i+1 << ". " << q6[i] << endl;
            }
            int a6;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a6;
            if (a6 == 2) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q6[1] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 7: {
            SetConsoleTextAttribute(color , 14);
            cout << "7.) What do you call a person who has only one right leg?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q7[] = {"Normal person ", "Disabled person ", "Crazy people ","Weird people "};
            for (int i=0; i < sizeof(q7)/sizeof(q7[0]); i++) {
                cout << i+1 << ". " << q7[i] << endl;
            }
            int a7;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a7;
            if (a7 == 1) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q7[0] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 8: {
            SetConsoleTextAttribute(color , 14);
            cout << "8.) Prime Minister's phone number What number does it start with?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q8[] = {"0 ", "1 ", "2 ","3 "};
            for (int i=0; i < sizeof(q8)/sizeof(q8[0]); i++) {
                cout << i+1 << ". " << q8[i] << endl;
            }
            int a8;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a8;
            if (a8 == 1) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q8[0] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        }
    SetConsoleTextAttribute(color , 3);
    cout << "                                                           \n" << endl;
    SetConsoleTextAttribute(color , 12);
    cout << "\t\t\tYour scored [ " << score << " ] points out of 8 points" << endl;
    cout << "                                                           \n" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    return 0;
}

int two() {
    SetConsoleTextAttribute(color , 13);
    cout << "                                           " << endl;
    cout << "************************************  Started Relaxing Quiz Game 2  ************************************" << endl;
    cout << "                                           " << endl;
    int score = 0;
    srand(time(0));
    switch (1) {
        case 1: {
            SetConsoleTextAttribute(color , 14);
            cout << "1.) What is the most commonly spoken language in the world?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q1[] = {" English"," Spanish", " Mandarin Chinese", " Hindi"};
            for (int i=0; i < sizeof(q1)/sizeof(q1[0]); i++) {
                cout << i+1 << ". " << q1[i] << endl;
            }
            int a1;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a1;
            if (a1 == 3) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q1[2] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 2: {
            SetConsoleTextAttribute(color , 14);
            cout << "2.) Which planet is known as the Red Planet?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q2[] = {" Earth"," Mars", " Jupiter", " Venus"};
            for (int i=0; i < sizeof(q2)/sizeof(q2[0]); i++) {
                cout << i+1 << ". " << q2[i] << endl;
            }
            int a2;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a2;
            if (a2 == 2) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q2[1] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 3: {
            SetConsoleTextAttribute(color , 14);
            cout << "3.) What is the capital city of France?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q3[] = {" Madrid "," Rome "," Berlin "," Paris "};
            for (int i=0; i < sizeof(q3)/sizeof(q3[0]); i++) {
                cout << i+1 << ". " << q3[i] << endl;
            }
            int a3;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a3;
            SetConsoleTextAttribute(color , 13);
            if (a3 == 4) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q3[3] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 4: {
            SetConsoleTextAttribute(color , 14);
            cout << "4.)Who painted the Mona Lisa?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q4[] = {" Vincent van Gogh ", " Pablo Picasso ", " Leonardo da Vinci ", "Don't know"};
            for (int i=0; i < sizeof(q4)/sizeof(q4[0]); i++) {
                cout << i+1 << ". " << q4[i] << endl;
            }
            int a4;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a4;
            SetConsoleTextAttribute(color , 13);
            if (a4 == 3) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q4[2] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 5: {
            SetConsoleTextAttribute(color , 14);
            cout << "5.) What is the chemical symbol for water?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q5[] = {" H2O ", " CO2 ", " O2 "," NaCl "};
            for (int i=0; i < sizeof(q5)/sizeof(q5[0]); i++) {
                cout << i+1 << ". " << q5[i] << endl;
            }
            int a5;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a5;
            if (a5 == 1) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q5[0] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 6: {
            SetConsoleTextAttribute(color , 14);
            cout << "6.) Which animal is known as the King of the Jungle?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q6[] = {" Lion ", "  Elephant ", " Tiger "," Gorilla "};
            for (int i=0; i < sizeof(q6)/sizeof(q6[0]); i++) {
                cout << i+1 << ". " << q6[i] << endl;
            }
            int a6;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a6;
            if (a6 == 1) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q6[0] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 7: {
            SetConsoleTextAttribute(color , 14);
            cout << "7.) What is the longest river in the world?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q7[] = {" Nile ", " Amazon ", " Mississippi "," Yangtze "};
            for (int i=0; i < sizeof(q7)/sizeof(q7[0]); i++) {
                cout << i+1 << ". " << q7[i] << endl;
            }
            int a7;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a7;
            if (a7 == 1) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q7[0] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 8: {
            SetConsoleTextAttribute(color , 14);
            cout << "8.) Who wrote Romeo and Juliet?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q8[] = {" William Shakespeare ", " Charles Dickens ", " Jane Austen "," Mark Twain "};
            for (int i=0; i < sizeof(q8)/sizeof(q8[0]); i++) {
                cout << i+1 << ". " << q8[i] << endl;
            }
            int a8;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a8;
            if (a8 == 1) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q8[0] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
            case 9: {
            SetConsoleTextAttribute(color , 14);
            cout << "9.) What is the currency of Japan?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q9[] = {" Euro ", " Yen ", " Dollar "," Yuan "};
            for (int i=0; i < sizeof(q9)/sizeof(q9[0]); i++) {
                cout << i+1 << ". " << q9[i] << endl;
            }
            int a9;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a9;
            if (a9 == 2) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q9[1] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
            case 10: {
            SetConsoleTextAttribute(color , 14);
            cout << "10.) Which ocean is the largest by surface area?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q10[] = {"  Southern Ocean ", " Indian Ocean ", " Atlantic Ocean "," Pacific Ocean "};
            for (int i=0; i < sizeof(q10)/sizeof(q10[0]); i++) {
                cout << i+1 << ". " << q10[i] << endl;
            }
            int a10;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a10;
            if (a10 == 4) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q10[3] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        }
    SetConsoleTextAttribute(color , 3);
    cout << "                                                           \n" << endl;
    SetConsoleTextAttribute(color , 12);
    cout << "\t\t\tYour scored [ " << score << " ] points out of 10 points" << endl;
    cout << "                                                           \n" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    return 0;
}

int three() 
{
    SetConsoleTextAttribute(color , 13);
    cout << "                                           " << endl;
    cout << "************************************  Started Relaxing Quiz Game 3  ************************************" << endl;
    cout << "                                           " << endl;
    int score = 0;
    srand(time(0));
    switch (1) {
        case 1: {
            SetConsoleTextAttribute(color , 14);
            cout << "1.) What is the force that pulls objects toward the center of the Earth called??" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q1[] = {" Gravity "," Magnetism ", " Friction ", "  Buoyancy "};
            for (int i=0; i < sizeof(q1)/sizeof(q1[0]); i++) {
                cout << i+1 << ". " << q1[i] << endl;
            }
            int a1;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a1;
            if (a1 == 1) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q1[0] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 2: {
            SetConsoleTextAttribute(color , 14);
            cout << "2.) What is the process by which plants make their own food using sunlight called?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q2[] = {" Respiration "," Photosynthesis ", " Fermentation ", " Digestion "};
            for (int i=0; i < sizeof(q2)/sizeof(q2[0]); i++) {
                cout << i+1 << ". " << q2[i] << endl;
            }
            int a2;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a2;
            if (a2 == 2) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q2[1] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 3: {
            SetConsoleTextAttribute(color , 14);
            cout << "3.) What is the smallest unit of matter called?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q3[] = {" Atom "," Molecule "," Cell "," Electron "};
            for (int i=0; i < sizeof(q3)/sizeof(q3[0]); i++) {
                cout << i+1 << ". " << q3[i] << endl;
            }
            int a3;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a3;
            SetConsoleTextAttribute(color , 13);
            if (a3 == 1) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q3[0] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 4: {
            SetConsoleTextAttribute(color , 14);
            cout << "4.) Which gas do plants absorb during photosynthesis?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q4[] = {" Oxygen ", " Carbon Dioxide ", " Nitrogen ", " Hydrogen "};
            for (int i=0; i < sizeof(q4)/sizeof(q4[0]); i++) {
                cout << i+1 << ". " << q4[i] << endl;
            }
            int a4;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a4;
            SetConsoleTextAttribute(color , 13);
            if (a4 == 2) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q4[1] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 5: {
            SetConsoleTextAttribute(color , 14);
            cout << "5.) What is the unit of measurement for electrical resistance?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q5[] = {" Watt ", " Volt ", " Ohm "," Ampere "};
            for (int i=0; i < sizeof(q5)/sizeof(q5[0]); i++) {
                cout << i+1 << ". " << q5[i] << endl;
            }
            int a5;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a5;
            if (a5 == 3) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q5[2] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 6: {
            SetConsoleTextAttribute(color , 14);
            cout << "6.) In mechanical engineering, what law states that for every action, there is an equal and opposite reaction?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q6[] = {" Newton's First Law ", " Newton's Second Law ", " Newton's Third Law "," Boyle's Law "};
            for (int i=0; i < sizeof(q6)/sizeof(q6[0]); i++) {
                cout << i+1 << ". " << q6[i] << endl;
            }
            int a6;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a6;
            if (a6 == 3) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                cout << "             "<< endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q6[2] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 7: {
            SetConsoleTextAttribute(color , 14);
            cout << "7.) When was the Faculty of Engineering established at Chiang Mai University?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q7[] = {" 1950 ", " 1964 ", " 1973 "," 1982 "};
            for (int i=0; i < sizeof(q7)/sizeof(q7[0]); i++) {
                cout << i+1 << ". " << q7[i] << endl;
            }
            int a7;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a7;
            if (a7 == 2) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q7[1] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        case 8: {
            SetConsoleTextAttribute(color , 14);
            cout << "8.) Which engineering program is most popular at the Faculty of Engineering, Chiang Mai University?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q8[] = {" Electrical Engineering ", " Civil Engineering ", " Computer Engineering "," Mechanical Engineering "};
            for (int i=0; i < sizeof(q8)/sizeof(q8[0]); i++) {
                cout << i+1 << ". " << q8[i] << endl;
            }
            int a8;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a8;
            if (a8 == 2) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q8[1] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
            case 9: {
            SetConsoleTextAttribute(color , 14);
            cout << "9.) Which faculty is the most prestigious at Chiang Mai University?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q9[] = {" Science ", " Economics", " Medicine "," Engineering "};
            for (int i=0; i < sizeof(q9)/sizeof(q9[0]); i++) {
                cout << i+1 << ". " << q9[i] << endl;
            }
            int a9;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a9;
            if (a9 == 3) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q9[2] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
            case 10: {
            SetConsoleTextAttribute(color , 14);
            cout << "10.) How many faculties does Chiang Mai University have?" << endl;
            SetConsoleTextAttribute(color , 9);
            cout << "                                           " << endl;
            string q10[] = {"  16 faculties ", " 17 faculties ", " 19 faculties "," 20 faculties "};
            for (int i=0; i < sizeof(q10)/sizeof(q10[0]); i++) {
                cout << i+1 << ". " << q10[i] << endl;
            }
            int a10;
            cout << "             "<< endl;
            SetConsoleTextAttribute(color , 14);
            cout << "Your Answer :";
            cin >> a10;
            if (a10 == 2) {
                score++;
                SetConsoleTextAttribute(color , 10);
                cout << "- Correct!" << endl;
            }
            else {
                SetConsoleTextAttribute(color , 12);
                cout << "- Wrong!" << endl;
                SetConsoleTextAttribute(color , 10);
                cout << "Correct! is "<< q10[1] << endl;
            }
            cout << endl;
            SetConsoleTextAttribute(color , 11);
            cout << "-----------------------------------------------------------------------------------------------" << endl;
        }
        }
    SetConsoleTextAttribute(color , 3);
    cout << "                                                           \n" << endl;
    SetConsoleTextAttribute(color , 12);
    cout << "\t\t\tYour scored [ " << score << " ] points out of 10 points" << endl;
    cout << "                                                           \n" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    return 0;
}

int out(){
    SetConsoleTextAttribute(color , 3);
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "                                                           \n" << endl;
    SetConsoleTextAttribute(color , 12);
    cout << "\t\t\tOut Quiz Game To Console Press[1]" << endl;
    cout << "                                                           \n" << endl;
    SetConsoleTextAttribute(color , 12);
    cout << "\t\t\tOut Quiz Game Press[2]" << endl;
    cout << "                                                           \n" << endl;
    SetConsoleTextAttribute(color , 12);
    cout << "\t\t\tRandom Play Again Quiz Game Press[3]" << endl;
    cout << "                                                           \n" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    char clicks = getch();
    printf("%c\n",clicks);
    if(clicks == '1')
  {
    system("cls");
  } 
  else if(clicks == '2')
  {
    system("cls");
    system("Console");

  } 
  else if(clicks == '3')
  {
    srand(time(0));
    int s = rand() % 3 + 1;
    system("cls");
    if(s == 1){
        one();
    }
    if(s == 2){
        two();
    }
    if(s == 3){
        three();
    }

  } 
  else {
    cout << "Invalid input";
    cout << "Please input again";
    out();
    return 0;
}
}
int main(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
SetConsoleTextAttribute(color , 2);	//Add Color
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
SetConsoleTextAttribute(color , 10);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                           **********************************************************************************                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                          ");SetConsoleTextAttribute(color , 9);printf("Press[1] to enter Quiz Game 1");SetConsoleTextAttribute(color , 10);printf("                         *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                          ");SetConsoleTextAttribute(color , 9);printf("Press[2] to enter Quiz Game 2");SetConsoleTextAttribute(color , 10);printf("                         *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                          ");SetConsoleTextAttribute(color , 9);printf("Press[3] to enter Quiz Game 3");SetConsoleTextAttribute(color , 10);printf("                         *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           **********************************************************************************                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
SetConsoleTextAttribute(color , 2);
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
SetConsoleTextAttribute(color , 15);
    char click = getch();
    printf("%c\n",click);
    if(click == '1')
  {
    one();
    out();
  } 
    else if(click == '2'){
    two();
    out();
  }
    else if(click == '3'){
    three();
    out();
  }
    else {
    cout << "Invalid input";
    cout << "Please input again";
    system("cls");
    main();
  }
}