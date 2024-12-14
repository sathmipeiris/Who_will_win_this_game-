/*
NAME    : .........................................H.S.V. PEIRIS
INDEX NO: .........................................21/ENG/035
ASSIGNMENT TYPE:...................................MINIPROJECT
*/
#include"GAMEHEADER.h"
using namespace std;
void clearScreen();
void fileoperation();

void TEAM::newplayer(PLAYERS** FIRST, string a, int agee, bool bowler, bool batter) {
    PLAYERS* newnode = new PLAYERS;
    newnode->NEXTPLAYER = nullptr;
    newnode->PLAYERNAME = a;
    newnode->age = agee;
    newnode->BATTING = batter;
    newnode->BOWLER = bowler;
    newnode->BOTH = bowler * batter;
    PLAYERS* PTR = *FIRST;

    if (PTR == NULL) {
        *FIRST = newnode;
        return;
    }

    else {
        while (PTR->NEXTPLAYER != nullptr)
        {
            PTR = PTR->NEXTPLAYER;
        }
        PTR->NEXTPLAYER = newnode;
    }




}

void TEAM::ballerlist(BOWLER** FIRST, string a, int agee, bool bowler) {
    BOWLER* newn = new BOWLER;
    newn->NEXTBOWLER = nullptr;
    newn->setbowlername(a);
    newn->age = agee;

    BOWLER* PTR = *FIRST;
    if (PTR == NULL) {
        *FIRST = newn;
        return;
    }
    else {
        while (PTR->NEXTBOWLER != nullptr)
        {
            PTR = PTR->NEXTBOWLER;
        }
        PTR->NEXTBOWLER = newn;
    }





}

void TEAM::Cprintplayer(PLAYERS* FIRST, TEAM* T1) {
    PLAYERS* ptr = FIRST;
    cout << endl << endl;
    cout << "--------------------------------------------------MATCH  SUMMARY --------------------------------------------------              ";
    cout << T1->TEAMNAME << "                 " << T1->T0TALSCORE << "/" << T1->WICKETS << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------              ";

    cout << endl << endl;
    cout << "BATTERS" << setw(80 - 7) << "RUNS" << setw(10) << "BALLS" << setw(10) << "4's" << setw(10) << "6's" << setw(10) << "SR" << endl;
    while (ptr != nullptr) {

        int length = ptr->PLAYERNAME.size();
        cout << ptr->PLAYERNAME << setw(80 - length) << ptr->RUNS << setw(10) << ptr->balls << setw(10) << ptr->f4s << setw(10) << ptr->s6s << setw(10) << ptr->SR << endl;

        ptr = ptr->NEXTPLAYER;
    }
}

void TEAM::Cprintballer(BOWLER* FIRST) {
    BOWLER* ptr = FIRST;
    int length = ptr->NAME.size();
    int c = 0;
    cout << "--------------------------------------------------------------------------------------------------------------------              ";
    cout << endl << endl;
    cout << "BALLERS" << setw(80 - 7) << "OVERS" << setw(10) << "RUNS" << setw(10) << "WKTS" << setw(10) << "ECO" << endl;
    while (ptr != nullptr && c <= 4) {

        int length = ptr->NAME.size();
        cout << ptr->NAME << setw(80 - length) << ptr->BALLEROVER << setw(10) << ptr->RUNSBY << setw(10) << ptr->WICKETSTAKEN << setw(10) << ptr->RUNSBY / 4 << endl;

        ptr = ptr->NEXTBOWLER;
        c++;

    }
}


int GAME::randomnumgenerator() {



    int p = 1 + (rand() % 100);
    return p;
}



void TEAM::batting(PLAYERS* FIRST, int batp, BOWLER* BALL1, int ballp, GAME* G, TEAM* T, TEAM* T2,bool target) {

    PLAYERS* PTR = FIRST;
    PLAYERS* score = FIRST;
    BOWLER* BALLER1 = BALL1;

    int oneballscore = 0;
    TEAM* T12 = T;
    int cricketercount = 1;
    int ballcount = 1;
    int targetvalue = 0;
    while (cricketercount <= 11 && T->CURROVERS <= 20) {
       

        int oneballscore = 0;
        batp = G->randomnumgenerator();
        ballp = G->randomnumgenerator();


        if (0 <= ballp && ballp <= 5) {
            oneballscore++;
            //cout << "1" << endl;
            PTR->balls = PTR->balls + 1;
            BALLER1->NOBALL++;
            PTR->playerscore++;
            T->TOTCURRBALLS++;
            PTR->RUNS++;BALLER1->RUNSBY++;

            PTR->SR = (float(PTR->RUNS) / PTR->balls) * 100;

        }
        if (6 <= ballp && ballp <= 15) {
            oneballscore++;
            PTR->playerscore++;
            PTR->balls++;
            BALLER1->WIDEBALL++;
            T->TOTCURRBALLS++;
            PTR->RUNS++;BALLER1->RUNSBY++;
            PTR->SR = (float(PTR->RUNS) / PTR->balls) * 100;
            //cout << "2" << endl;

        }

        if (0 <= batp && batp <= 10) {

            // cout << "3" << endl;
            PTR->s6s++;
            oneballscore += 6;
            PTR->playerscore += 6;
            PTR->RUNS += 6;BALLER1->RUNSBY += 6;
            PTR->balls++;
            PTR->overballs++;
            PTR->SR = (float(PTR->RUNS) / PTR->balls) * 100;

        }
        else if (11 <= batp && batp <= 20) {
            PTR->f4s++;
            oneballscore += 4;
            PTR->RUNS += 4;BALLER1->RUNSBY += 4;
            PTR->playerscore += 4;
            PTR->balls++;
            PTR->overballs++;
            PTR->SR = (float(PTR->RUNS) / PTR->balls) * 100;
            // cout << "4" << endl;

        }
          else if (21 <= batp && batp <= 40) {
            PTR->RUNS++;BALLER1->RUNSBY++;
            oneballscore += 1;
            PTR->playerscore += 1;
            PTR->balls++;
            PTR->overballs++;
            PTR->SR = (float(PTR->RUNS) / PTR->balls) * 100;
            // cout << "5" << endl;


        }
         
       
        else if (41 <= batp && batp <= 89) {
            PTR->RUNS += 2;BALLER1->RUNSBY += 2;
            oneballscore += 2;
            PTR->playerscore += 2;
            PTR->balls++;
            PTR->overballs++;
            PTR->SR = (float(PTR->RUNS) / PTR->balls) * 100;
            //cout << "6" << endl;



        }
        else if (90 <= batp && batp <= 100  ) {
            //  cout << "7" << endl;
            if ((PTR->NEXTPLAYER != nullptr)) {
                PTR->balls++;
                PTR->overballs++;

                PTR->SR = (float(PTR->RUNS) / PTR->balls) * 100;
                if (PTR != NULL)
                    PTR = PTR->NEXTPLAYER;
                system("cls");


                cricketercount++;
                T->WICKETS++;

                BALLER1->WICKETSTAKEN++;
            }
            if((PTR->NEXTPLAYER == nullptr)) {
                return ;

            }
        }


        T->T0TALSCORE += oneballscore;

        //cout << T->T0TALSCORE;
        //ballcount++;
       // cout << T->CURRBALLS;
        T->CURRBALLS++;
         


        

        if (T->CURRBALLS % 6 == 0) {

            T->CURROVERS++;
            BALLER1->BALLEROVER++;
        }

        // cout << T->CURROVERS << endl;
        if ((T->CURRBALLS % 24 == 0) && (T->CURRBALLS != 0) && (BALLER1->NEXTBOWLER != nullptr)) {
            //cout << "1" << endl;
            BALLER1 = BALLER1->NEXTBOWLER;

        }

        cout << endl;
        // cout << ballp << " " << batp;
        // cout << endl;

      // T->Cprintplayer(FIRST);
      // T->Cprintballer(BALL1);

        cout << "------------------------------------------------ CRICKET LIVE SCOREBOARD -----------------------------------------------              ";
        cout << endl << endl;
        cout << "BATTING : " << T->TEAMNAME << endl;
        cout << " CURRENT SCORE: " << T->T0TALSCORE << "/" << T->WICKETS << setw(80) << PTR->PLAYERNAME << "   " << PTR->RUNS << "/" << "Over :" << T->CURROVERS << endl;
        if (target == 1) {
            cout << " TARGET SCORE: " << T2->T0TALSCORE - T->T0TALSCORE << endl;
        }
        cout << endl << endl;
        cout << "BALLNG : " << T2->TEAMNAME << setw(80) << BALLER1->NAME << endl;
        cout << T2->T0TALSCORE << "/" << T2->WICKETS << endl;
        cout << "------------------------------------------------*************************-----------------------------------------------              ";

        if (target == 1 && (T->T0TALSCORE >= T2->T0TALSCORE)) {
            
            return;

        }

        this_thread::sleep_for(chrono::milliseconds(500));

        clearScreen();


    }
}

void clearScreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

bool TEAM::toss(GAME* G, TEAM* T1, TEAM* T2) {

    cout << "***********************************  20 OVER CRICKET MATCH B/W " << T1->TEAMNAME << " AND " << T2->TEAMNAME << "  ***********************************" << endl << endl;;

    cout << setw(80) << "Tossing the coin..........." << endl << setw(65) << T1->TEAMNAME << " VS " << T2->TEAMNAME << endl << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(500));

    int toss = G->randomnumgenerator();
    if (toss >= 50) {

        cout << T1->TEAMNAME << " won the toss!!!!!!!!!!!!!!!" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));

        return true;
    }
    else {

        cout << T2->TEAMNAME << " won the toss!!!!!!!!!!!!!" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));

        return false;
    }


}

void TEAM::teamsummary(TEAM* T1) {
    cout << T1->TEAMNAME << "  MATCH SUMMARY  " << T1->T0TALSCORE << "/" << T1->WICKETS << endl << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));


}

void TEAM::winner(TEAM* T1, TEAM* T2) {
    system("cls");
    if ((T1->T0TALSCORE < T2->T0TALSCORE)||( T1->T0TALSCORE == T2->T0TALSCORE)&&(T2->WICKETS<T1->WICKETS)) {
        cout << T2->TEAMNAME << " Won by " << T2->T0TALSCORE - T1->T0TALSCORE << " RUNS ";
        if ((T1->T0TALSCORE == T2->T0TALSCORE) && (T2->WICKETS < T1->WICKETS)) {
            cout << T1->WICKETS - T2->WICKETS << " wickets" << endl;
        }
        cout << endl;

    }
    if((T2->T0TALSCORE < T1->T0TALSCORE) || (T2->T0TALSCORE == T1->T0TALSCORE) && (T1->WICKETS < T2->WICKETS)){
        cout << T1->TEAMNAME << " Won by " << T1->T0TALSCORE - T2->T0TALSCORE << " RUNS " << endl;
        if ((T2->T0TALSCORE == T1->T0TALSCORE) && (T1->WICKETS < T2->WICKETS)) {
            cout << T2->WICKETS - T1->WICKETS << " wickets" << endl;
        }
        cout << endl;
    }
}


