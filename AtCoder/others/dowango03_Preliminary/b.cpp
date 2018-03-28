// ------------------------------------
// Date:2018/ 3/ 8
// Problem:dowango03 preliminary ニコニコレベル b.cpp
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

// dp[num][2 or 5] = ニコニコレベル
int dp[101010][2];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(dp, 0, sizeof(dp));
  dp[0][0] = 0;
  dp[0][1] = -1;
  
  string T;
  cin >> T;

  int ans = 0;
  REP(i, T.size()) {
    switch(T[i]) {
    case '2':
      dp[i + 1][0] = 0;
      dp[i + 1][1] = dp[i][0] + 1;
      break;
    case '5':
      dp[i + 1][0] = dp[i][1] + 1;
      dp[i + 1][1] = -1;
      break;
    case '?':
      dp[i + 1][0] = dp[i][1] + 1;
      dp[i + 1][1] = dp[i][0] + 1;
      break;
    default:
      dp[i + 1][0] = 0;
      dp[i + 1][1] = -1;
    }
    ans = max(ans, max(dp[i + 1][0], dp[i + 1][1]));
  }
  cout << ans / 2 * 2 << endl;

  /*
  REP(i, T.size()) {
    debug(dp[i][0]);
    debug(dp[i][1]);
  }
  */
  
  return 0;
}
