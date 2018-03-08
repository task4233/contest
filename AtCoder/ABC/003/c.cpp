// ------------------------------------
// Date:2018/ 2/14
// Problem:ABC 003 AtCoderプログラミング講座 c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

// -----------------------------------------------
// N:講座動画の数 / K:高橋君が見れる動画の数
// R:講座動画のレート
void solve(const int N,const int K,const vector<double> R)
{
    double hisRate;
    hisRate = 0.0;
    
    /*
    REP(i,N) {
        cout << R.at(i) << "/";
    }
    cout << endl;
    */
     
    FOR(rNum,N-K,N) {
        hisRate = (hisRate+R.at(rNum))/2.0;
    }
    printf("%.7lf\n", hisRate);
    
}

// ********** 出力は%.7lfで行うこと! **********
// -----------------------------------------------

int main()
{
    int N,K;
    cin >> N >> K;
    vector<double> R(N,0);
    REP(i,N) {
        cin >> R.at(i);
    }
    sort(R.begin(),R.end());
    solve(N,K,R);
    return 0;
}

