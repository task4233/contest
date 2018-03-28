// ------------------------------------
// Date:2018/ 3/11
// Problem:ABC 090 . d.cpp
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

bool state[101010];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  /*
  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }
  */

  ll ans = 0ll;
  FOR(bi, K + 1, N + 1) {
    ll tmp = (N + 1) / bi;
    ans += tmp * (bi - min(K, bi));
    ans += max(0, ((N + 1) % bi) - K);
    if (K == 0) {
      // グループを形成できない中途半端なものを求めるときに、+1(0の分)を引く必要がある
      ans--;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}

