#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int64 INF = 1LL << 40 - 1;
constexpr int64 LINF = 1LL << 60 + 1;
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

int power(int x, int n) {
	int res = 1LL;
	while (n > 0) {
		if (n & 1) (res *= x);
		(x *= x);
		n >>= 1;
	}
	return res;
}

signed main() {
  INIT;
	VAR(int, n);
	VEC(int, a, n);
	a.push_back(LINF);
	sort(ALL(a));

	vector< int > par;
	REP(i, 32) {
		debug(power(2, i));
		par.push_back(power(2, i));
	}

	int ans = 0;
	RREP(i, n) {
		RREP(j, par.size()) {
			int target = par[j];
			target -= a[i];
			auto it = lower_bound(ALL(a), target);
			int pos = (it - a.begin());
			if (pos < i && a[pos] == target) {
				// debug(a[i]);
				// debug(a[pos]);
				ans++;
				a[pos] = a[pos + 1] - INF;
				a[i] = LINF;
				break;
			}
		}
	}

	OUT(ans)BR;
  
  return 0;
}
