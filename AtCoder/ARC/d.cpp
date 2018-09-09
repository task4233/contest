#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
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
#define FOUT(n, dist) cout <<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<"\n";
#define debug(x) cerr << #x << ":" << (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

int power(int x, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) (res *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	return res % MOD;
}

signed main() {
  INIT;
	VAR(int, n, m);
	set< int > sx;
	set< int > sy;
	int min_x = 1e9, max_x = -1e9;
	int min_y = 1e9, max_x = -1e9;
	REP(i, n) {
		VAR(int, x);
		sx.insert(x);
		min_x = min(min_x, x);
		max_x = max(max_x, x);
	}
	REP(i, m) {
		VAR(int, y);
		sy.insert(y);
		min_y = min(min_y, y);
		max_y = max(max_y, y);
	}
	int W = sx.size() - 2;
	int H = sy.size() - 2;
	int ans = (max_x - min_x) * (max_y - min_y);
	ans %= MOD;
	(ans *= power(2, W)) %= MOD;
	(ans *= power(2, H)) %= MOD;
	OUT(ans)BR;
}
