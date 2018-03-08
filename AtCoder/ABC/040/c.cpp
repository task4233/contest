// ------------------------------------
// Date:2018/ 2/25
// Problem:ABC 040 柱柱柱柱柱 c.cpp
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

int dp[1010101];

int main()
{
  int N;
  int ans = 0;
  cin >> N;
  vector<int> A(N);
  REP(i,N) cin >> A[i];
  memset(dp,-1,sizeof(dp));
  dp[0] = 0;
  dp[1] = abs(A[1] - A[0]);
  REP(i,N+1) {
    // 1つ進むときと2つ進む時の最大値をとる
    if (i > 1) dp[i] = min(dp[i-1] + abs(A[i] - A[i-1]),
                           dp[i-2] + abs(A[i] - A[i-2]));
  }
  cout << dp[N-1] << endl;
  return 0;
}

