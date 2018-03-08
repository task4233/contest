// ------------------------------------
// Date:2018/ 2/14
// Problem:ABC 003 AtCoder社の給料 a.cpp
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
    int N,sum;
    cin >> N;
    sum = 0;
    FOR(i,1,N+1) {
        sum += i * 10000;
    }
    cout << sum/N << endl;
    return 0;
}

