// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 057 DigitsInMultiplication c.cpp
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

int f(ll n)
{
  if (n < 10) return 1;
  return f(n/10) + 1;
}

int main()
{
  ll N;
  int ans = (1 << 9), tmp;
  cin >> N;
  for(ll i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      tmp = max(f(i), f(N/i));
      if (tmp < ans) ans = tmp;
    }
  }
  cout << ans << endl;
  return 0;
}

