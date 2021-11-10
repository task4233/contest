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

void solve()
{
  // テーブルを十分大きな値で初期化
  REP(S, 1 << N) {
    fill(dp[S], dp[S] + n, INF);
  }
  dp[(1 << N) - 1][0] = 0;
  
  // 漸化式に従って順に計算
  RREP(S, (1 << N)) {
    REP(from, N) {
      REP(to, N) {
        if (not(S >> to & 1)) {
          // toはまだ訪れていない場所である
          // toを視点とした時のパスの重みの最小値を返す
          dp[S][from] = min(dp[S][from],
                            dp[S | 1 << to][to] + line[from][to]);
        }
      }
    }
  }
  
  printf("%d\n", dp[0][0]);
}

int main()
{
  solve();
  return 0;
}

