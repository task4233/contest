// ------------------------------------
// Date:2018/ 3/ 3
// Problem:AOJ DPL Knapsack Problem with Limitations 1_G.cpp
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

int main()
{
  // dp[num][weight]{最大の価値, 追加した個数}
  pair< int, int > dp[101][1010];
  
  int N, W;
  scanf("%d %d", &N, &W);
  int v[1010];
  int w[1010];
  int m[10101];
  REP(i, N) {
    scanf("%d %d %d", &v[i], &w[i], &m[i]);
  }
  memset(dp, 0, sizeof(dp));
  
  // O(NmW) ≒ O(10^(2+4+3)) = O(10^9)
  REP(num, N) {
    REP(weight, W + 1) {
      if (weight < w[num]) {
        // 入らん
        dp[num + 1][weight] = dp[num][weight];
      } else {
        // 入る
        if (dp[num][weight].second < m[num]) {
          dp[num][weight].first = dp[num][weight - w[num]].first + v[num];
          dp[num][weight].second++;
        } else {
          dp[num + 1][weight].first = max(dp[num][weight].first,
                                          dp[num][weight - w[num]].first) + v[num];
        }
      }
    }
  }
  
  printf("%d\n", dp[N][W].first);
  
  REP(num, N) {
    REP(weight, W + 1) {
      printf("dp[%03d][%03d] = {%d, %d}\n", num, weight, dp[num][weight].first, dp[num][weight].second);
    }
  }
  
  return 0;
}

