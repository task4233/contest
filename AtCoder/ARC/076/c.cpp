// ------------------------------------
// Date:2018/ 3/20
// Problem:ARC 076 Reconciled? c.cpp
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
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") <<　endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int MOD = 1e9 + 7;
static const int MAX_N = 1e5 + 1;

ll fact[MAX_N];

void init()
{
  fact[0] = 1;
  FOR(i, 1, MAX_N) {
    fact[i] = fact[i - 1] % MOD * i % MOD;
    fact[i] = (fact[i] % MOD + MOD) % MOD;
    // debug(fact[i]);
  }
}

ll power(ll x, ll n)
{
  ll res = 1;
  while(n > 0) {
    if (n & 1) {
      res = (res % MOD) * (x % MOD) % MOD;
    }
    x = (x % MOD) * (x % MOD) % MOD;
    n >>= 1;
    // debug(res);
  }
  return res % MOD;
}

ll inverse(ll n)
{
  return power(n, MOD - 2) % MOD;
}

ll nCr(ll n, ll r)
{
  // debug((fact[n] % MOD));
  // debug(inverse(fact[n - r]));
  // debug(inverse(fact[r]));
  return (fact[n] % MOD) * inverse(fact[n - r])  * inverse(fact[r]) % MOD;
}

int main()
{
  LCIN(N, M);
  init();
  ll ans = 0ll;
  if (abs(N - M) < 2) {
    ans = power(fact[min(M, N)], 2);
    if (N == M) {
      ans = ans % MOD * 2 % MOD;
    } else {
      ans = (ans % MOD) * (max(M, N) % MOD) % MOD;
    }
    ans = (ans % MOD + MOD) % MOD;
  }
  cout << ans << endl;

  return 0;
}

