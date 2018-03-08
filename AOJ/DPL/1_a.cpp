// ------------------------------------
// Date:2018/ 2/25
// Problem:AOJ DPL Coin Changing Problem 1_a.cpp
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

int N;
int M;
int dp[50505];
int c[20];


int main()
{
  scanf("%d %d", &N, &M);
  memset(dp, 50000, sizeof(dp));
  REP(mi, M) {
    scanf("%d", &c[mi]);
  }
  sort(c, c + M);
  
  dp[0] = 0;
  REP(ni, N) {
    REP(mi, M) {
      // 多すぎる時
      if (ni + c[mi] > N) break;
      // 硬貨を選ばない時と選ぶ時
      dp[ni + c[mi]] = min(dp[ni] + 1,
                         dp[ni + c[mi]]);
    }
  }
  printf("%d\n", dp[N]);
  return 0;
}

