// ------------------------------------
// Date:2018/ 2/15
// Problem:ABC 004 マーブル d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define debug(x) cerr << #x << ": " << x << '\n';
#define MOD 1000000007

int R,G,B;
//  dp[lookAt][leftSum]
int dp[1000][1000];

// 移動距離を返す
inline int cost(int lookAt,int leftSum)
{
  if (leftSum >= G+B) return abs(400-lookAt);
  else if (leftSum >= B) return abs(500-lookAt);
  else return abs(600-lookAt);
}

int main()
{
  cin >> R >> G >> B;
  
  REP(lookAt,1000) REP(leftSum, 1000) dp[lookAt][leftSum] = 1e9;
  REP(lookAt,1000) dp[lookAt][R+G+B] = 0;
  FOR(lookAt,1,1000) {
    REP(leftSum,R+G+B) {
      // 移動させないときと、移動させたときのうち少ない方をdpに記憶する。
      dp[lookAt][leftSum] = min(dp[lookAt-1][leftSum],
                                dp[lookAt-1][leftSum+1] + cost(lookAt,leftSum)
                                );
    }
  }
  
  int res = 1000000000;
  REP(lookAt,1000) {
    res = min(res, dp[lookAt][0]);
  }
  cout << res << endl;
  
  return 0;
}

