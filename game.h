#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Army{
       int hpmax; 
        string name;		
		int hp;
		int atk;
		int def;  
        int heal;
        int skillatk;
    public:
    void status();
};
void statusstarter(){
Army Tank = {"Tank",300,50+(rand()%11),50,0};
Army Soilder[3] ;
Soilder[0] = {"Soilder1",100,25+(rand()%11),10,0,50+rand()%151};
Soilder[1] = {"Soilder2",100,25+(rand()%11),10,0,50+rand()%151};
Soilder[2] = {"Soilder3",100,25+(rand()%11),10,0,50+rand()%151};
Soilder[3] = {"Soilder4",100,25+(rand()%11),10,0,50+rand()%151};
Army Artillery = {"Artillery",60,20+(rand()%81),5,0};
Army Commander = {"Commander",200,20+(rand()%11),0,50};
}