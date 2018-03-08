// ------------------------------------
// Date:2018/ 2/22
// Problem:ABC 044 TakAndCards c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()

using ll = long long;

//  dp[i][j][sum] i枚のカードからj枚選んだ時の合計(sum)をメモ
ll dp[51][51][2601] = {0ll};

int main()
{
  int N,A,n;
  cin >> N >> A;
  vector<int> x(N);
  REP(i,N) cin >> x[i];
  
  dp[0][0][0] = 1;
  REP(i,N){
    REP(j,i+1) {
      REP(sum,2601) {
        // x[i]を選んだ時
        dp[i+1][j+1][sum+x[i]] += dp[i][j][sum];
        // x[i]を選ばなかった時
        dp[i+1][j][sum] += dp[i][j][sum];
      }
    }
  }
  
  ll res = 0ll;
  REP(i,N+1) {
    if (i >= 1) res += dp[N][i][i*A];
  }
  cout << res << endl;
  return 0;
}

