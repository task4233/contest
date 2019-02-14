#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
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
#define zero(n) cout<<setfill('0')<<right<<setw(n)
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

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

void init_fact() {
  fact[0] = ifact[0] = 1;
	for (int i=1; i<MAX_N; ++i) {
		(fact[i] = fact[i - 1] * i) %= MOD;
		ifact[i] = inv(fact[i]);
	}
}

int dp[MAX_N];

signed main() {
  INIT;
	VAR(int, n);
	VEC(int, a, n);

	if (n == 1) {
		OUT(0)BR;
		return 0;
	}

	auto check = [=](int mid, int exponent, int cnt) {
		return (power(mid, exponent-1) >= cnt); 
	};

	fill_n(dp, MAX_N, INF);
	REP(i, n) {
		*lower_bound(dp, dp+MAX_N, a[i]) = a[i];
	}
	int cnt = lower_bound(dp, dp+MAX_N, INF) - dp, ans = 2;

	int ng = 0, ok = MAX_N;
	while (ok - ng > 1) {
		int mid = (ng + ok) >> 1;
		if (check(mid, a.back(), cnt)) ok = mid;
		else ng = mid;
		//debug(mid);
	}

	// debug(ok)BR;
	ans = max(ans, ok);
	
	OUT(ans)BR;
	
  return 0;
}
