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
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

signed main() {
  int n;
	scanf("%d", &n);
	vector< PAIR > d(n);
	REP(i, n) {
		scanf("%d-%d", &d[i].first, &d[i].second);
		d[i].first = d[i].first / 5 * 5;
		d[i].second = ((d[i].second + 4) / 5) * 5;
	}
	sort(ALL(d));

	vector< PAIR > ans;
	int lb = d[0].first, ub = d[0].second;
	REP(i, d.size()) {
		if (ub < d[i].first) {
			ans.push_back({lb, ub});
			lb = d[i].first;
			ub = d[i].second;
		} else {
			// lb = d[i].first;
			ub = max(ub, d[i].second);
		}
	}
	ans.push_back({lb, ub});
	REP(i, ans.size()) {
		// wtf
		// printf("%d-%d", ans[i].first, ans[i].second);
		cout << setfill('0') << right << setw(4) << ans[i].first << "-" << ans[i].second << endl;
	}

	
  
  return 0;
}
