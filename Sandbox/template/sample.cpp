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

struct nCr {
  const int MOD = 1e9 + 7;
  vector< int > fact;
  nCr(int _n) {
    init(_n);
  }

  init(int n) {
    fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i < n; i++)
      fact[i] = (fact[i - 1] % MOD) * i % MOD;
  }

  int power(int x, int n) {
    int res = 1;
    while(n > 0) {
      if (n & 1) res = (res % MOD) * (x % MOD) % MOD;
      x = (x % MOD) * (x % MOD) % MOD;
      n >>= 1;
    }
    return res % MOD;
  }

  int inverse(int n) {
    return power(n, MOD - 2);
  }

  int MODnCr(int n, int r) {
    return (fact[n] % MOD) * (inverse(fact[n - r]) % MOD) * (inverse(fact[r]) % MOD) % MOD;
  }
};


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(W, H);
  nCr n(W + H);
  cout << n.MODnCr(W + H - 2, H - 1) << endl;

  return 0;
}


