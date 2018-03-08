// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 046 AtCoDeerAndElectionReport c.cpp
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

#define MOD 1000000007

// 最小値
ll dp[1050];

int main()
{
  int N;
  cin >> N;
  vector<int> T(N),A(N);
  REP(i,N) cin >> T[i] >> A[i];
  dp[0] = 1;
  REP(i,N+1) {
    if (i>=1) dp[i] = max((T[i]/T[i-1])+(T[i]%T[i-1]==0?0:1),(A[i]/A[i-1])+(A[i]%A[i-1]==0?0:1))*dp[i-1];
  }
  REP(i,N+1) {
    cout << i << "->" << dp[i] << endl;
  }
  cout << dp[N-1] << endl;
  return 0;
}

