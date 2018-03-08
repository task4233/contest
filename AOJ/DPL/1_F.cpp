// ------------------------------------
// Date:2018/ 3/ 3
// Problem:AOJ DPL fd 1_F.cpp
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

typedef long long ll;

static const int MOD = 1000000007;

// dp[num][weight]
//int dp[101][1010101010]; // 10^(2*9) Byte
int main()
{
  int N, W;
  // dp[num][value]
  int dp[101][10101];
  int v[101];
  int w[101];
  scanf("%d %d", &N, &W);
  REP(n, N + 1) {
    REP(v, 100*N + 1) {
      dp[n][v] = 1e9 + 1;
    }
  }
  memset(v, 11, sizeof(v));
  memset(v, 11, sizeof(w));
  REP(num, N) {
    scanf("%d %d", &v[num], &w[num]);
  }
  
  dp[0][0] = 0;
  REP(num, N) {
    REP(value, 100*N + 1) {
      if (value < v[num]) {
        dp[num + 1][value] = dp[num][value];
      } else {
        dp[num + 1][value] = min(dp[num][value],
                                 dp[num][value - v[num]] + w[num]);
      }
    }
  }
  
  int ans = 0;
  REP(value, 100*N + 1) {
    //printf("dp[N][%d] = %d\n", value, dp[N][value]);
    if (dp[N][value] <= W) {
      ans = max(ans, value);
    }
  }
  printf("%d\n", ans);
  return 0;
}

