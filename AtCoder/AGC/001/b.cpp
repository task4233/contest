// ------------------------------------
// Date:2018/ 3/28
// Problem:Mysterious Light / b.cpp
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
const int MAX_N = 1e5 + 1;

ll solve(ll n, ll x)
{
  // debug(n);
  // debug(x);
  ll tmp = n - x;
  if (tmp == 0) return 2 * n;
  
  ll res = 0;
  if (x > n) {
    if (x % n == 0) {
      res += x * 2 * + solve(x, tmp);
    } else {
      res += tmp * 2 * (n / x);
      res += x + solve(x, n % x);
    }
  }
  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LCIN(N, X);
  
  ll ans = solve(N, X);

  cout << ans << endl;
  
  return 0;
}

