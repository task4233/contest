#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

const int INF = 1e9 + 1;
const int MAX_N = 1e5 + 10;
const int MAX_LEN = 21;

ll N;
ll d[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  vector< ll > a(N);
  REP(i, N) {
    cin >> a[i];
    if (i > 0) d[i] = d[i - 1];
    d[i] += a[i];
  }

  /*
  REP(i, N) {
    REP(j, MAX_LEN) 
      cout << d[i][j];
    cout << endl;
  }
  */

  ll ub = 0ll;
  ll ans = 0ll;
  ll tmp = 0ll;
  REP(lb, N) {
    debug(lb);
    ub = max((ll)lb + 1ll, ub);
    while(ub < N) {
      if (d[ub] != (tmp xor a[ub])) break;

      tmp = tmp xor a[ub];
      ans += ub - lb;
      debug(ans);
      debug(ub);
      ub++;
    }
    tmp = tmp xor a[lb];
  }


  if (zflag) ans = N * (N + 1ll) / 2ll;
  cout << ans << endl;
  

  return 0;
}
