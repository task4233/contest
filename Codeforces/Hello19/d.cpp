#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
#include <cfloat>
#include <set>
#include <map>

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

map< int, int >  dp[10101];

signed main() {
  INIT;
	VAR(int, n, k);
	
	auto get_divisors = [&](int v) {
		vector< int > res;
		if (v == 1) {
			res.push_back(1);
			return res;
		}
		for (int i=1; i*i<=v; ++i) {
			if (v%i!=0) continue;
			res.push_back(i);
			if (i!=1 && i*i != v) res.push_back(v/i);
		}
		res.push_back(v);
		return res;
	};
	vector< int > div = get_divisors(n);


	REP(i, div.size()) {
		// OUT(div[i])SP;
		dp[1][div[i]]++;
	}

	
	REP(ki, k) {
		REP(di, div.size()) {
			vector< int > di_div = get_divisors(div[di]);
			REP(dj, di_div.size()) {
				debug(div.size());
				debug(di_div.size());
				(dp[ki + 1][di_div[dj]] += dp[ki][di] * (div.size() / di_div.size())) %= MOD;
			}
		}
	}

	int ans = 0;
	EACH(di, dp[k]) {
		(ans += (di.first % MOD) * (di.second % MOD)) %= MOD;
		debug(di.first);
		debug(di.second);
		debug(ans);
	}
	debug(ans);
	
	(ans *= inv(power(div.size(), k))) %= MOD;
	OUT(ans)BR;
 
  return 0;
}
