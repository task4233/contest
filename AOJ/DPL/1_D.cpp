// ------------------------------------
// Date:2018/ 3/ 2
// Problem:AOJ DPL Longest Increasing Subsequence 1_D.cpp
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

int N;
int a[101010];
// dp[見ているところ]
int dp[101010];

int main()
{
  memset(a, 0, sizeof(a));
  memset(dp, 0, sizeof(dp));
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d", &a[i]);
  }
  
  int res = 0;
  REP(i, N) {
    dp[i] = 1;
    REP(j, i) {
      if (a[j] < a[i]) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
    res = max(res, dp[i]);
  }
  printf("%d\n", res);
  /*
  REP(i, N) {
    printf("dp[%d] -> %d\n", i, dp[i]);
  }
   */
  return 0;
}

