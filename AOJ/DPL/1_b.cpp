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

int main()
{
  // N:品物の個数 / W:容量
  int N, W;
  scanf("%d %d", &N, &W);
  // v:value / w:weight
  vector< int > v(N + 1, 0);
  vector< int > w(N + 1, 0);
  memset(dp, 0, sizeof(dp));
  REP(ni, N) {
    scanf("%d %d", &v[ni], &w[ni]);
  }
  
  REP(num, N + 1) {
    REP(weight, W + 1) {
      if (weight < w[num]) {
        // これ以上はいらないのでスルー
        dp[num + 1][weight] = dp[num][weight];
      } else {
        // 何も入れない　or 入れる
        dp[num + 1][weight] = max(dp[num][weight],
                                  dp[num + 1][weight - w[num]] + v[num]);
      }
    }
  }
  printf("%d\n", dp[N][W]);
  return 0;
}
