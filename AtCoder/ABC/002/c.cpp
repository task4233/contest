// -------------------------------------
// Date:2018/ 2/12
// Problem:ABC 002 直訴 c.cpp
//
// ------------------------------------

#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

#define FEACH(i,a) for(auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define X(di) data.at(di).x
#define Y(di) data.at(di).y

// ----------------------------------------------
struct Pos {
    int x;
    int y;
};

void solve(vector<Pos> data)
{
    //REP(di,3) cout << X(di) << ":" << Y(di) << endl;
    // dataのキーPos.xをラムダ式で昇順ソート
    sort(data.begin(),
         data.end(),
         [](const Pos& current,const Pos& next) {
             return current.x < next.x;
         });
    // X(0).xおよびY(0).yの座標が0になるように全ての点を平行移動
    RREP(di,3) {
        X(di) -= X(0);
        Y(di) -= Y(0);
    }
    printf("%.3f\n", fabs((double)(X(1)*Y(2)-X(2)*Y(1))/2.0));
}
// ----------------------------------------------

int main()
{
    Pos pos;
    vector<Pos> data;
    REP(i,3){
        cin >> pos.x >> pos.y;
        data.emplace_back(pos);
    }
    solve(data);
    return 0;
}

