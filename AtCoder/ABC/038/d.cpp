// ------------------------------------
// Date:2018/ 3/ 3
// Problem:ABC 038 プレゼント d.cpp
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

static const int INF = 1000000007;

int dp[101010];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int N;
  scanf("%d", &N);
  // tmp{fin, start}
  vector< pair< int, int > >tmp(N);
  REP(i, N) {
    scanf("%d %d", &tmp[i].first, &tmp[i].second);
    // ソートする時にhの大きい順にしたいので、-1倍してあげる
  }
  sort(ALL(tmp));
  fill_n(dp, N, INF);
  
  int res = 0;
  REP(i, N) {
    dp[i] = 1;
    REP(j, i) {
      if (tmp[j].first < tmp[i].first and
          tmp[j].second < tmp[i].second) {
        dp[i] = max(dp[i],
                    dp[j] + 1);
      }
    }
    res = max(dp[i], res);
  }
  printf("%d\n", res);
  return 0;
}

