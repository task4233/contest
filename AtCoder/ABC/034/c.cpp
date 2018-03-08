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

int fact[201010];
int inverse[201010];

ll power(int a, int b)
{
  
  ll res = 1;
  
  while(b > 0) {
    if ((b & 1) == 1) {
      res = (res % MOD) * (a % MOD);
    }
    a = ((a % MOD) * (a % MOD));
    b >>= 1;
  }
  return res % MOD;
}

ll nCr(int n, int r)
{
  return ((fact[n] % MOD) * (inverse[fact[r]] % MOD) * (inverse[fact[n - r]] % MOD)) % MOD;
}

void init()
{
  fact[0] = 1;
  inverse[0] = 1;
  FOR(i, 1, 201010) {
    fact[i] = ((fact[i - 1] % MOD) * i) % MOD;
  }
  inverse[200001] = power(fact[200000], MOD - 2);
  RREP(i, 200000) {
    inverse[i] = (inverse[i + 1] * (i + 1)) % MOD;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int W, H;
  cin >> W >> H;
  init();

  REP(i, 10) {
    cout << fact[i] << endl;
    cout << inverse[i] << endl;
    cout << power(2, i) << endl;
    cout << nCr(10, i) << endl << endl;
  }
  cout << nCr(H + W - 2, H - 1) << endl;
  
  return 0;
}

