// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 006 トリボナッチ数列 b.cpp
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

#define MOD 10007

int dp[10000000];
int N;

int dfs(int n) {
  if (n == 0) return 0;
  if (n == 1) return 0;
  if (n == 2) return 1;
  if (dp[n] != 0) return dp[n];
  return dp[n] = (dfs(n-1) + dfs(n-2) + dfs(n-3))%MOD;
}

int main()
{
  cin >> N;
  memset(dp,0,sizeof(dp));
  cout << dfs(N-1) << endl;
  return 0;
}

