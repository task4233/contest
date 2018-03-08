// ------------------------------------
// Date:2018/ 2/15
// Problem:ABC 004 回転 b.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int main()
{
    char table[4][4];
    REP(xi,4) {
        REP(yi,4) {
            cin >> table[xi][yi];
        }
    }
    RREP(xi,4) {
        RREP(yi,4) {
            cout << table[xi][yi];
            if (yi != 0) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

