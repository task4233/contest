// ------------------------------------
// Date:2018/ 3/ 3
// Problem:区間スケジューリング問題 / / 2_2_2.cpp
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

static const int MAX_N = 100000;

int N, S[MAX_N], T[MAX_N];

// itv{finish, start}
pair< int, int > itv[MAX_N];

void solve()
{
  REP(i, N) {
    itv[i].first = T[i];
    itv[i].second = S[i];
  }
  // 終了時間の早い順にソート
  sort(itv, itv + N);
  
  int ans = 0;
  int last = 0;
  // lastは最後に選んだ仕事の終了時間
  REP(i, N) {
    if (last < itv[i].second) {
      ++ans;
      last = itv[i].first;
    }
  }
  printf("%d\n", ans);
}

int main()
{
  solve();
  return 0;
}

