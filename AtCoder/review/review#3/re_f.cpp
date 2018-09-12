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

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LCIN(N, x);
  vector< ll > a(N);
  REP(i, N) {
    cin >> a[i];
    debug(a[i]);
  }

  ll ans = LINF;
  vector< ll > b(a);
  REP(i, N) {
    ll tmp = x * (ll)i;
    
    REP(j, N) {
      debug(j);
      debug(b[j]);
      debug(a[((ll)(j - i) + N) % N]);
      b[j] = min(b[j], a[((ll)(j - i) + N) % N]);
    }
    REP(j, N) {
      tmp += b[j];
      // debug(b[j]);
    }

    ans = min(ans, tmp);
    cout << ans << endl;
  }

  cout << ans << endl;

  return 0;
}
