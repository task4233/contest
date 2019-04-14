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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 1;

ll fact[MAX_N];

ll power(ll x, ll n) {
  ll res = 1ll;
  while (n > 0) {
    if (n & 1) {
      (res *= x) %= MOD;
    }
    (x *= x) %= MOD;
    n >>= 1;
  }
  return res % MOD;
}

ll inverse(ll n) {
  return power(n, MOD - 2);
}

ll nCr(ll n, ll r) {
  return ((fact[n] * inverse(fact[n - r])) % MOD * inverse(fact[r])) % MOD;
}


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(H, W, A, B);

  fact[0] = 1ll;
  FOR(i, 1, MAX_N) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  
  ll ans = 0ll;
  REP(hi, H - A) {
    ans += nCr(B + hi - 1, hi) * nCr(W - B + H - hi - 2, H - hi - 1);
    debug(W + H - B - hi - 2);
    debug(W - B - 1);
    debug(ans);
    cout << endl;
    ans %= MOD;
  }

  cout << ans << endl;
  

  return 0;
}

