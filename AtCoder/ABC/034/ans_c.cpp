// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ABC 034 経路 c.cpp
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
static const int MAX_SIZE = 201010;

int fact[MAX_SIZE];

int mul(ll a, ll b)
{
  return ((a % MOD) * (b % MOD)) % MOD;
}

int power(int x, int n)
{
  int res = 1;
  while(n > 0) {
    if (n & 1) {
      res = mul(res, x);
    }
    x = mul(x, x);
    n >>= 1;
  }
  return res % MOD;
}

int inverse(int n)
{
  return power(n, MOD - 2);
}

void init(int n)
{
  fact[0] = 1;
  FOR(i, 1, n) {
    fact[i] = mul(fact[i - 1], i);
  }
}

int nCr(int n, int r)
{
  return mul(mul(fact[n], inverse(fact[n - r])),  inverse(fact[r]));
}

int main()
{
  memset(fact, 0, sizeof(fact));
  init(MAX_SIZE);
  int W, H;
  cin >> W >> H;
  cout << nCr((W + H - 2), W - 1) << endl;
  return 0;
}
