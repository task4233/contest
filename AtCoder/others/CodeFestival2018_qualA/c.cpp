#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int, int>;
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
#define BR cout<<"\n";
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

// dp[n][番目]
int dp[55][33];
int n, k;

int solve(vector< int > cnt, int j, int mk) {
	if (j + 1 == cnt.size() - 1) return mk;
	int res = 0;
	FOR(i, j + 1, cnt.size()) {
		res += min(cnt[i], mk);
	}
	return nCr(res, k) % MOD;
}

int pi(vector< int > cnt) {
	int ans = 0;
	REP(i, cnt.size()) {
		if (ans == 0) ans = (cnt[i] + 1);
		else (ans *= (cnt[i] + 1)) %= MOD;
	}
	return ans - 1;
}

int loop(vector< int > cnt, int num, int left, bool ok) {
	if (num + 1 == cnt.size() - 1) {
		return left + (ok ? 1 : 0);
	}
	int res = 0;
	FOR(i, num + 1, n) {
		FOR(j, 1, cnt[i] + 1) {
			int mk = left - j;
			if (mk == 0) {
				(res += loop(cnt, i, cnt[i] - j, true)) %= MOD;
				break;
			} else {
				int tmp = cnt[i];
				cnt[i] = 0;
				(res += loop(cnt, i, mk, false)) %= MOD;
				cnt[i] = tmp;
			}
			debug(res);
		}
		debug(res);
	}
	if (ok) res++;
	debug(res);
	return res % MOD;
}

signed main() {
  INIT;
	fact[0] = ifact[0] = 1;
	FOR(i, 1, MAX_N) {
		fact[i] = (fact[i - 1] * i) % MOD;
		ifact[i] = inv(fact[i]);
	}
	
	cin >> n >> k;
	VEC(int, a, n);
	vector< int > cnt(n, 0);
	bool hasZero = false;
	int sm = 0;
	REP(i, n) {
		hasZero |= (a[i] == 0);
		while (a[i] > 0) {
			cnt[i]++;
			a[i] /= 2;
		}
		sm += cnt[i];
		debug(cnt[i]);
	}
	sort(ALL(cnt));
	bool reached = (sm >= k);

	if (hasZero) {
		OUT(solve(cnt, 0, k))BR;
		return 0;
	}
	if (!reached) {
		OUT(pi(cnt))BR;
		return 0;
	}
	
	int ans = loop(cnt, k, -1, false) % MOD;
	OUT(ans)BR;
	
  return 0;
}
