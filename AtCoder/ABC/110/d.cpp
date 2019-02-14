#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 3e5 + 1;

// init/input
#define int int64
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...) type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T &t) {cin>>t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<endl;
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

struct Eratosthenes {
  vector< bool > prime;
  Eratosthenes(int _size) {
    init(_size);
  }

  void init(int n) {
    prime.resize(n + 1);
    for(int i = 0; i < prime.size(); ++i) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i = 2; i < sqrt(n); i++) {
      if (prime[i]) {
        for (int j = 0; i * (j + 2) < n; j++) {
					prime[i * (j + 2)] = false;
				}
      }
    }
  }
};

int fact[MAX_N];
int ifact[MAX_N];
 
int power(int x, int n) {
	int res = 1LL;
	while (n > 0) {
		if (n & 1) (res *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	return res % MOD;
}
 
int inv(int x) {
	return power(x, MOD - 2);
}
 
int nCr(int n, int r) {
	if (n < 0 || r < 0 || r > n) return 0;
	if (r > n / 2) r = n - r;
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}


signed main() {
  INIT;
	VAR(int, n, m);
	Eratosthenes e(MAX_N);

	fact[0] = ifact[0] = 1;
	FOR(i, 1, MAX_N) {
		fact[i] = (fact[i - 1] * i) % MOD;
		ifact[i] = inv(fact[i]);
	}

	map< int, int > mp;
  for (int i=2; i*i <= n; ++i) {
		if (!e.prime[i]) continue;
		while (m > 0 && m % i == 0) {
			mp[i]++;
			m /= i;
		}
	}
	
	if (m > 1) mp[m]++;
	
	int ans = 1LL;
	EACH(mi, mp) {
		// debug(mi.first);
		// debug(mi.second);
		int tmp = nCr(n-1+mi.second, n-1);
		ans = (ans * tmp) % MOD;
	}
	OUT(ans)BR;
	
  return 0;
}
