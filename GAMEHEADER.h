/*
NAME    : .........................................H.S.V. PEIRIS
INDEX NO: .........................................21/ENG/035
ASSIGNMENT TYPE:...................................MINIPROJECT
*/

#include <iostream>//header files
#include<fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <Windows.h>
#include<chrono>
#include<random>
#include<thread>
using namespace std; //standard namespace

//player==batter class
class PLAYERS {
public:
    string PLAYERNAME = "";
    int age = 0;
    int playerscore = 1;
    bool BOWLER = 0;
    bool BATTING = 0;
    bool BOTH = 0;
    int RUNS = 0;
    int f4s = 0;
    int s6s = 0;
    int overballs = 0;
    int balls = 0;
    float SR = 0;
    PLAYERS* NEXTPLAYER = {};

};
class UMPIRE {
private:
    string UMPIRENAME =" ";
    int UMPIREAGE = 0;
    int DESCISIONMAKINGABILITY = 0;
public:
    void JUDGEMENT(){}
};

class GAME {
private:

public:
   
    int GAMEOVERS = 20;
    int GAMEWICKETS = 10;
    int GAMEBALLS = GAMEOVERS * 6;
    int randomnumgenerator();
};

//bowler class
class BOWLER : PLAYERS {
public:
    string NAME = "";
    int NOBALL = 0;
    int WIDEBALL = 0;
    int BALL = 0;
    int WICKETSTAKEN = 0;
    int age = 0;
    int RUNSBY = 0;
    int BALLEROVER =0;

    BOWLER* NEXTBOWLER = {};
    void setbowlername(string n) {
        NAME = n;
    }
    string getbowlername() {
        return NAME;
    }

};

//team class
class TEAM {
public:

    string TEAMNAME = {};
    int T0TALSCORE = 0;
    int WICKETS = 0;
    int CURROVERS = 0;
    int CURRBALLS = 0;
    int TOTCURRBALLS = 0;

    void newplayer(PLAYERS** FIRST, string a, int agee, bool bowler, bool batter);
    void ballerlist(BOWLER** FIRST, string a, int agee, bool bowler);
    void Cprintplayer(PLAYERS* FIRST, TEAM* T1);
    void batting(PLAYERS* FIRST, int batp, BOWLER* BALL1, int ballp, GAME* G, TEAM* T, TEAM* T2, bool target);
    void Cprintballer(BOWLER* FIRST);
    bool toss(GAME* G, TEAM* T1, TEAM* T2);
    void teamsummary(TEAM* T1);
    void winner(TEAM* T1, TEAM* T2);

};