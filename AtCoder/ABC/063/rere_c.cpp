// ------------------------------------
// Date:2018/ 2/28
// Problem:ABC 063 Bugged c.cpp
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
const int MAX_N = 101;
const int MAX_SUM = 10101;

bool dp[MAX_N][MAX_SUM];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int N;
  cin >> N;
  vector< int > s(N);
  REP(i, N) cin >> s[i];
  memset(dp, false, sizeof(dp));

  dp[0][0] = true;
  REP(i, N) {
    REP(j, MAX_SUM + 1) {
      dp[i + 1][j] |= dp[i][j];
      if (j >= s[i]) dp[i + 1][j] |= dp[i][j - s[i]];
    }
  }


  int ans = 0;
  RREP(i, MAX_SUM) {
    if (i % 10 == 0) continue;
    if (dp[N][i]) {
      ans = i;
      break;
    }
  }
    
  cout << ans << endl;
  return 0;
}

