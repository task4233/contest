// ------------------------------------
// Date:2018/ 3/ 5
// Problem:ABC 083 WideFlip d.cpp
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

// dp[0:raw, 1:invert][見ている桁]
int dp[2][101010];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string inputStr;
  cin >> inputStr;
  REP(i, 2) {
    fill_n(dp[i], 101010, 1);
  }
  
  int rawAns = 1e9 + 1;
  int invertAns = 1e9 + 1;
  REP(i, inputStr.size()) {
    if (inputStr[i] == '0') {
      // raw
      dp[0][i + 1] = dp[0][i] + 1;

      // invert
      if (dp[1][i] == 0) continue;
      invertAns = min(dp[1][i], invertAns);
      
    } else {
      // invert
      dp[1][i + 1] = dp[1][i] + 1;
      
      // raw
      if (dp[0][i] == 0) continue;
      rawAns = min(dp[0][i], rawAns);
    }
  }
  if (dp[0][inputStr.size() - 1] != 0) rawAns = max(dp[0][inputStr.size() - 1], rawAns);
  if (dp[1][inputStr.size() - 1] != 0) invertAns = max(dp[1][inputStr.size() - 1], invertAns);

  /*
  REP(i, 2) {
    REP(j, inputStr.size()) {
      printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
    }
  }
  */
  
  int ans = max(rawAns, invertAns);
  cout << ans << endl;
  return 0;
}

