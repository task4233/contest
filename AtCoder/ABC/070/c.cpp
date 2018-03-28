// ------------------------------------
// Date:2018/ 3/10
// Problem:ABC 070 MultipleClocks c.cpp
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

ll lcm(ll x, ll y)
{
  ll r0, r1, a0, a1, b0, b1, q0, q1, tmp;
  r0 = x; r1 = y;
  a0 = 1; a1 = 0;
  b0 = 0; b1 = 1;

  while(r1 > 0) {
    q1 = r0 / r1;

    // a2 = a0 - q1 * a1
    tmp = a1;
    // a1 := a2
    a1 = a0 - q1 * a1;
    a0 = tmp;

    // b2 = b0 - q1 * b1
    tmp = b1;
    // b1 := b2
    b1 = b0 - q1 * b1;
    b0 = tmp;

    // r2 = r0 - q1 * r1
    tmp = r1;
    // r1 := r2
    r1 = r0 - q1 * r1;
    r0 = tmp;
  }
  return (x / r0) * y;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  // 1 <= T[i] <= 10e18
  vector< ll > T(N);
  REP(i, N) {
    cin >> T[i];
  }

  ll ans = T[0];
  FOR(i, 1, N) {
    ans = lcm(ans, T[i]);
  }

  cout << ans << endl;
  return 0;
}

