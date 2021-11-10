// ------------------------------------
// Date:2018/ 3/ 3
// Problem:bit DP 巡回セールスマン問題 3_4_1.cpp
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
static const int INF = 1e9 + 1;

static const int MAX_N = 15;

int N;
// 辺
int line[MAX_N][MAX_N];

// メモ化テーブル
int dp[1 << MAX_N][MAX_N];

int rec(int S, int from)
{
  if (dp[S][from] != 0) {
    return dp[S][from];
  }
  if (S == (1 << N) - 1 && from == 0) {
    // Nビットシフトしたのちに1を引くことで、全てのビットを1にする
    // かつ頂点from == 0の時
    // -> 全ての頂点を通り、頂点0に戻って来た
    return dp[S][from] = 0;
  }
  
  int res = INF;
  REP(to, N) {
    if (not(S >> to & 1)) {
      // toはまだ訪れていない場所
      // toを始点とした時のパスの重みの最小値を返す
      res = min(res,
                rec(S | 1 << to, to) + line[from][to]);
    }
  }
  return dp[S][from] = res;
}

void solve()
{
  memset(dp, -1, sizeof(dp));
  printf("%d\n", rec(0, 0));
}

int main()
{
  
  return 0;
}

