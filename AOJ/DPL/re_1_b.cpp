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

// dp[num][weight]
int dp[101][10101];

// v:value / w:weight
int v[1010];
int w[1010];

// N:品物の個数 / W:ナップサックの容量
int N, W;

int solve(int num, int weight)
{
  if (dp[num][weight] != 0) {
    // チェックしたことのあるやつ
    return dp[num][weight];
  }
  int ret;
  if (num == N) {
    // 全てチェック済み
    ret = 0;
  } else if (weight < w[num]) {
    // これ以上はいらん
    ret = solve(num + 1, weight);
  } else {
    // max(入れない or 入れる)
    ret = max(solve(num + 1, weight),
              solve(num + 1, weight - w[num]) + v[num]);
  }
  return dp[num][weight] = ret;
}

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
  
  int ans = solve(0, W);
  printf("%d\n", ans);
  
  return 0;
}
