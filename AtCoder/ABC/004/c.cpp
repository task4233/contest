// ------------------------------------
// Date:2018/ 2/15
// Problem:ABC 004 入れ替え c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

#define debug(x) cerr << #x << ": " << x << '\n';

int main()
{
    int N,newN;
    vector<int> output(6);
    cin >> N;
    REP(i,6) output.at(i) = i+1;
    newN = N%30;
    
    REP(oi,newN) {
        swap(output.at(oi%5),output.at(oi%5+1));
    }
    
    REP(oi,6) cout << output.at(oi);
    cout << endl;
    return 0;
}

