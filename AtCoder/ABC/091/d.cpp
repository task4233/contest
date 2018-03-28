// ------------------------------------
// Date:2018/ 3/17
// Problem:_ _ _ d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

static const int MOD = 1e9 + 7;
static const int MAX_N = 1;

int main()
{
  int N;
  scanf("%d", &N);
  vector< int > a(N);
  REP(i, N) scanf("%d", &a[i]);
  vector< int > b(N);
  REP(i, N) scanf("%d", &b[i]);


  ll ans = 0;
  REP(bit, 29) {
    ll T = 1 << bit; 
    // [0, 29)の区間の各ビットを調査

    vector< int > aModT(N);
    REP(i, N) {
      // mod 2*Tを求める
      aModT[i] = a[i] % (T * 2);
    }

    vector< int > bModT(N);
    REP(i, N) {
      // mod 2*Tを求める
      bModT[i] = b[i] % (T * 2);
    }

    sort(ALL(bModT));

    ll cnt = 0;
    REP(ai, N) {
      // aModT[ai]として固定
      int a = aModT[ai];
      int tmp1 = lower_bound(ALL(bModT), T - a) - bModT.begin();
      int tmp2 = lower_bound(ALL(bModT), 2 * T - a) - bModT.begin();
      int tmp3 = lower_bound(ALL(bModT), 3 * T - a) - bModT.begin();

      // cnt += [3*T, 4*T) + [T, 2*T)
      cnt += N - tmp3 + tmp2 - tmp1;
      // debug(tmp1);
      // debug(tmp2);
      // debug(tmp3);

    }
    // xorは奇数の時に1
    if (cnt % 2 == 1) {
      ans += T;
      // cout << "ok" << endl;
    }
  }

  printf("%d\n", ans);
  return 0;
}

