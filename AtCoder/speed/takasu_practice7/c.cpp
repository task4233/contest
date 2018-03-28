// ------------------------------------
// Date:2018/ 3/17
// Problem:H S I c.cpp
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

ll power(int x, int n)
{
  ll res = 1ll;
  while (n > 0) {
    if (n & 1) {
      res = x * res;
    }
    x *= x;
    n >>= 1;
  }
  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  ll tmp = 1900 * M + (N - M) * 100;
  ll tmp2 = power(2, M);
  //debug(tmp2);
  
  ll ans = tmp * tmp2;
  cout << ans << endl;
  
  return 0;
}

