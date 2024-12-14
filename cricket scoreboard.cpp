/*
NAME    : .........................................H.S.V. PEIRIS
INDEX NO: .........................................21/ENG/035
ASSIGNMENT TYPE:...................................MINIPROJECT
*/

#include <iostream> //header files
#include<fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <Windows.h>
#include<chrono>
#include<random>
#include<thread>
#include"GAMEHEADER.h"
using namespace std; //standard namespace

int main()
{
    srand(time(0)); 
    PLAYERS* team1player = nullptr;
    PLAYERS* team2player = nullptr;
    BOWLER* bowler1 = nullptr; BOWLER* bowler2 = nullptr;
    GAME cricket = {};

    TEAM team1 = {};
    TEAM team2 = {};
    team1.TEAMNAME = "SRI LANKA";
    team2.TEAMNAME = "INDIA";
   
    {
        ifstream inputFile;
        inputFile.open("x.txt", ios::in);

        if (inputFile.is_open()) {
            string data;
            int age;
            bool bow;
            bool bat;
            char comma1;
            char comma2;
            int c = 0;
            

            while (getline(inputFile >> std::ws, data, ',') >> age >> comma1 >> bow >> comma2 >> bat) {

                c++;
                
                if (c <= 11) {
                    team1.newplayer(&team1player, data, age, bow, bat);
                    if (bow == 1) {
                        team1.ballerlist(&bowler1, data, age, bow);
                    }
                }
                else {
                team2.newplayer(&team2player, data, age, bow, bat);
                if (bow == 1) {
                    team2.ballerlist(&bowler2, data, age, bow);
                }
                }
            }
        }
        else {
        }
        inputFile.close();
    }
    int tss = team1.toss(&cricket,&team1, &team2);
    cout << "Lets us start the game................." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    system("cls");
    if (tss==1)
    {
        
        team1.batting(team1player, 0, bowler2, 0, &cricket, &team1, &team2,0);
        system("cls");
        
        team2.batting(team2player, 0, bowler1, 0, &cricket, &team2, &team1,1);
        
        system("cls");
        team1.teamsummary(&team1);
        team2.teamsummary(&team2);   
   }
    else
    {
        team2.batting(team2player, 0, bowler1, 0, &cricket, &team2, &team1,0);
        system("cls");
        team1.batting(team1player, 0, bowler2, 0, &cricket, &team1, &team2,1);
        system("cls");
        team2.teamsummary(&team2);
        team1.teamsummary(&team1);        
    }

    team1.winner(&team2, &team1);
    team1.Cprintplayer(team1player, &team1);team2.Cprintballer(bowler2);
    team2.Cprintplayer(team2player, &team2); team1.Cprintballer(bowler1);
    //create input file stream object  
    return 0;  
}