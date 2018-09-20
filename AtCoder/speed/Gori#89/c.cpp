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

void init() {
	fact[0] = fact[1] = 1;
	REP(i, MAX_N) {
		(fact[i + 1] = fact[i] * (i + 1)) %= MOD;
		//debug(fact[i + 1]);
	}
}

signed main() {
  INIT;
	VAR(int, n, m);

	if (abs(n - m) > 1) {
		OUT(0)BR;
		return 0;
	}

	init();

	int ans;
	if (abs(n - m) == 1) {
		(ans = fact[max(n, m)] * fact[min(n, m)]) %= MOD;
	}

	if (n == m) {
		ans = (2 * fact[n] % MOD * fact[m]) % MOD;
		//debug(fact[n]);
	}
	OUT(ans)BR;
  
  return 0;
}
