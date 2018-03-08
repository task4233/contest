// ------------------------------------
// Date:2018/ 3/ 2
// Problem:AOJ DPL 0-1 Knapsack Problem 1_b.cpp
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

//static const int MOD = 1000000007;

// dp[今見てる品物の個数+1][まだ詰め込める量]
int dp[101][10101];

// v:value / w:weight
int v[1010];
int w[1010];

// N:品物の個数 / W:ナップサックの容量
int N, W;

int main()
{
  // 初期化
  memset(dp, 0, sizeof(dp));
  memset(v, 0, sizeof(v));
  memset(w, 0, sizeof(w));
  scanf("%d %d", &N, &W);
  REP(i, N) {
    scanf("%d %d", &v[i], &w[i]);
  }
  
  REP(num, N) {
    REP(weight, W+1) {
      if (weight < w[num]) {
        // 見ている品物の重さが、まだ詰め込める量より多いとき
        dp[num + 1][weight] = dp[num][weight];
      } else {
        // 詰め込むことが可能な状態で、max(詰め込まない or 詰め込む
        dp[num + 1][weight] = max(dp[num][weight],
                                  dp[num][weight - w[num]] + v[num]);
      }
    }
  }
  
  int ans = dp[N][W];
  printf("%d\n", ans);
  
  return 0;
}
