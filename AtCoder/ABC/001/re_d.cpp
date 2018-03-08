// ------------------------------------
// Date:2018/ 2/11
// Problem:ABC 001 : d.cpp
//
// ------------------------------------

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)
#define S(ri) rainingData.at(ri)[0]
#define E(ri) rainingData.at(ri)[1]

// ----------------------------------------------

void solve(const int N,vector<array<int,2>> rainingData)
{
    vector<int> timeTable(289, 0);
    bool isPositive;
    isPositive = false;
    
    REP(ri,N) {
        timeTable.at((S(ri)/100)*12 + (S(ri)%100)/5)++;
        timeTable.at((E(ri)/100)*12 + ((E(ri)%100)/5) + (E(ri)%5==0?0:1))--;
    }
    
    REP(ti,289) {
        if (ti>0) timeTable.at(ti) += timeTable.at(ti-1);
        //cout << ti << ":" << timeTable.at(ti) << endl;
    }
        
    REP(ti,289) {
        if (timeTable.at(ti)>0) {
            if (!isPositive) {
            isPositive = true;
            printf("%04d-", (ti/12)*100 + (ti%12)*5);
            }
        } else {
            if (isPositive) printf("%04d\n", (ti/12)*100 + (ti%12)*5);
            isPositive = false;
        }
    }
}

// ----------------------------------------------

int main()
{
    int N;
    vector<array<int,2>> rainingData;
    array<int,2> elem;
    cin >> N;
    REP(i,N) {
        scanf("%4d-%4d",&elem[0],&elem[1]);
        rainingData.emplace_back(elem);
    }
    solve(N,rainingData);
    return 0;
}
