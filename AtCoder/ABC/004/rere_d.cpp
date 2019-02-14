#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1e5 + 1;

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
#define zero(n) cout<<setfill('0')<<right<<setw(n)
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

int pow(int a, int b) {
	int res = 1LL;
	while (n > 0) {
	  if (n & 1) (res *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	return res % MOD;
}

signed main() {
  INIT;
	VAR(int, n);
	vector< int > a(n), d(MAX_N, 0);
	int mx = 0;
	REP(i, n) {
		cin >> a[i];
		d[--a[i]]++;
		mx = max(mx, a[i]);
	}

	bool ok = a[0] == 0 && d[0] == 1;
	FOR(i, 1, mx + 1) {
		ok &= d[i] > 0;
	}
	if (!ok) {
		OUT(0)BR;
		return 0;
	}

	int ans = 1;
	REP(i, mx) {
		(ans *= (power(2, d[i] + d[i + 1] - 1) + MOD - power(2, d[i + 1])) % MOD ) %= MOD;
	}
	OUT(ans)BR;
  
  return 0;
}
