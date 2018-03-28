// ------------------------------------
// Date:2018/ 3/17
// Problem:ARC 067 FactorsOfFactorial c.cpp
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

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int MOD = 1e9 + 7;
static const int MAX_N = 1010;

bool prime[MAX_N];

void init()
{
  FOR(i, 2, MAX_N) {
    for (int j = 0; i * (j + 2) < MAX_N; ++j) {
      prime[i * (j + 2)] = true;
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(prime, false, sizeof(prime));
  CIN(N);
  init();
  ll ans = 1ll;
  FOR(i, 2, MAX_N) {
    if (prime[i]) continue;
    ll cnt = 0;
    FOR(j, 2, N + 1) {
      ll tmp = j;
      while(tmp % i == 0) {
	cnt++;
	tmp /= i;
      }
    }
    ans = (ans % MOD) * ((cnt + 1) % MOD);
    ans %= MOD;
    // debug(i);
    // debug(ans);
  }

  cout << ans << endl;

  return 0;
}

