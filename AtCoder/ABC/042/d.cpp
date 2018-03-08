// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 042 IrohaAndAGrid d.cpp
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

int H,W,A,B;
int dp[100000][100000];

int main()
{
  cin >> H >> W >> A >> B;
  memset(dp,0,sizeof(dp));
  dp[0][0] = 1;
  REP(hi,H+1) {
    REP(wi,W+1) {
      if (hi > H-A-1 && wi < B) continue;
      // 右に行く
      // 条件追加　範囲指定
      if (wi < W) dp[hi][wi+1] += dp[hi][wi]%MOD;
      // 下に行く
      if (hi < H) dp[hi+1][wi] += dp[hi][wi]%MOD;
      //cout << "dp[" << hi << "][" << wi << "]=" << dp[hi][wi] << endl;
    }
  }
  cout << dp[H-1][W-1] << endl;
  return 0;
}

