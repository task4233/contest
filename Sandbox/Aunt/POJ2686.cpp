// ------------------------------------
// Date:2018/ 3/ 3
// Problem:POJ TravelingByStagecoach / POJ2686.cpp
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

int main()
{
  // N:移動できる回数 / M:全体の都市の数
  // s:始点 / g:終点 / t:乗車券に記載されている頭数
  int N, M;
  int s, g;
  int t[10];
  
  // line[from][to]
  int line[30][30];
  
  // 残っている乗車券の集合をS,現在いる都市をfromとする
  double dp[1 << 8][30];
  
  REP(i, 1 << N) {
    fill(dp[i], dp[i] + M, INF);
  }
  dp[(1 << N) - 1][0] = 0;
  
  double res = INF;
  REP(S, (1 << N)) {
    res = 
    REP(from, N) {
      
      REP(to, N) {
        if (not(S >> to & 1)) {
          dp[S][from] = min(dp[S & ~(1 << to)][from],
                            dp[S][from] + (double)line[from][to] / t[from]);
        }
      }
    }
  }
  
  return 0;
}

