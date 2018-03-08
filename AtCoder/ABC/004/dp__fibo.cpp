// ------------------------------------
// Date:2018/ 2/16
// Problem:zenka siki dp dp__fibo.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int dp[100000000];

int dp_fibo(int n)
{
  dp[0] = 0;
  dp[1] = 1;
  FOR(i,2,n+1) dp[i] = dp[i-1] + dp[i-2];
  return dp[n];
}

int main()
{
  int n;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  cout << dp_fibo(n) << endl;
  return 0;
}
