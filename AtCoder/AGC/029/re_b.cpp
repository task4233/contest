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
// #define int int64
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


signed main() {
  INIT;
	int n; scanf("%d", &n);
	map< int, int > mp;
	vector< int > a;
	REP(i, n) {
		int j; scanf("%d", &j);
		a.push_back(j);
		mp[j]++;
	}

	sort(ALL(a));
	a.erase(unique(ALL(a)), a.end());

	int ans = 0;
	RREP(i, a.size()) {
		RREP(j, 31) {
			if (mp[a[i]] == 0) break;
			int target = (1 << j) - a[i];
			auto target_itr = &mp[target];
			auto a_itr = &mp[a[i]];
			if (target == a[i]) {
				int tmp = *target_itr / 2;
				*target_itr -= tmp * 2;
				ans += tmp;
			} else {
				int tmp1 = *target_itr, tmp2 = *a_itr;
				*target_itr -= min(tmp1, tmp2);
				*a_itr -= min(tmp1, tmp2);
				ans += min(tmp1, tmp2);
			}
		}
	}

	OUT(ans)BR;
  
  return 0;
}
