// ------------------------------------
// Date:2018/ 2/25
// Problem:AOJ DPL KnapsackProblem 1_a.cpp
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
#define debug(x) cerr << #x << ":" << x << endl

using ll = long long;

#define MOD 1000000007

// dp[num][weight]
int dp[111][11111];

int main()
{
  int N;
  int W;
  cin >> N >> W;
  // v:value, w:weight
  int v[111];
  int w[111];
  memset(dp,0,sizeof(dp));
  memset(v,0,sizeof(v));
  memset(w,0,sizeof(w));
  REP(i,N) {
    cin >> v[i] >> w[i];
  }
  REP(num,N+1) {
    REP(weight,W+1) {
      if (weight-w[num] >= 0) {
        // max(中に入れる or 中に入れない)
        dp[num+1][weight] = max(dp[num][weight],
                                dp[num+1][weight-w[num]]+v[num]);
      } else {
        // これ以上入らないのでスルー
        dp[num+1][weight] = dp[num][weight];
      }
    }
  }
  cout << dp[N][W] << endl;
  return 0;
}

