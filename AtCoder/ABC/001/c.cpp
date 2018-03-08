// ------------------------------------
// Date:2018/ 2/10
// Problem:. . . a.cpp
//
// ------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

// ------------------------------------------
// ベターなコード
// ------------------------------------------
void solve(int Deg, int Dis)
{
    string Dir[16]
    = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    int directionNum, windPowNum;
    int tmp;
    int windPowWidth[12] = {3, 13, 18, 21, 25, 28, 31, 33, 36, 37, 40, 42};
    
    // 風向きの処理
    directionNum = ((Deg*10+1125)/2250)%16;
    // 風速の処理
    REP(i,12) windPowWidth[i] *= 6;
    referenceVal = 15;

    if (Dis - referenceVal<0) {
        cout << "C 0" << endl;
    } else {
        for (windPowNum=0; windPowNum<12; ++windPowNum, referenceVal+=windPowWidth[windPowNum]) {
            if (Dis-referenceVal<0) break;
            //cout << windPowNum << ":" << Dis << "-" << tmp << endl;
        }
        cout << Dir[directionNum] << " " << windPowNum << endl;
    }
}

// ------------------------------------------
// ミスが出やすいコード
// ------------------------------------------

/*
// g:Digree, s:V/m
void solve(double g,double s)
{
    string Dir;
    int W;
    double mS;
 
    if (g < 3487.5 && g >= 3262.5) Dir = "NNW";
    else if (g >= 3037.5)         Dir = "NW";
    else if (g >= 2812.5)         Dir = "WNW";
    else if (g >= 2587.5)         Dir = "W";
    else if (g >= 2362.5)         Dir = "WSW";
    else if (g >= 2137.5)         Dir = "SW";
    else if (g >= 1912.5)         Dir = "SSW";
    else if (g >= 1687.5)         Dir = "S";
    else if (g >= 1462.5)         Dir = "SSE";
    else if (g >= 1237.5)         Dir = "SE";
    else if (g >= 1012.5)         Dir = "ESE";
    else if (g >= 787.5)          Dir = "E";
    else if (g >= 562.5)          Dir = "ENE";
    else if (g >= 337.5)          Dir = "NE";
    else if (g >= 112.5)          Dir = "NNE";
    else                          Dir = "N";
    
    mS = s/60.0;
    if (mS < 0.25) W = 0;
    else if (mS < 1.55)  W = 1;
    else if (mS < 3.35)  W = 2;
    else if (mS < 5.45)  W = 3;
    else if (mS < 7.95)  W = 4;
    else if (mS < 10.75) W = 5;
    else if (mS < 13.85) W = 6;
    else if (mS < 17.15) W = 7;
    else if (mS < 20.75) W = 8;
    else if (mS < 24.45) W = 9;
    else if (mS < 28.45) W = 10;
    else if (mS < 32.65) W = 11;
    else                 W = 12;
    
    if (W==0) Dir = "C";
     
    cout << Dir << " " << W << endl;
}
// ----------------------------------------------
 */

int main()
{
    //double Deg, Dis;
    int Deg, Dis;
    cin >> Deg >> Dis;
    solve(Deg, Dis);
    return 0;
}

