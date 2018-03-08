// ------------------------------------
// Date:2018/ 2/ 3
// Problem:AtCoder Petrozavodsk Contest a.cpp
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

int main()
{
    long long X,Y;
    cin >> X >> Y;
    if (X>=Y && X%Y==0) {
        cout << -1 << endl;
    } else {
        cout << X << endl;
    }
    return 0;
}

