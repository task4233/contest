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

signed main() {
  INIT;
	VAR(int, n, m);
	vector< PAIR > d(m); 
	REP(i, m) {
		VAR(int, p, y);
		d[i] = make_pair(p, y);
	}
	vector< PAIR > cp_d;

	sort(ALL(cp_d), [] (PAIR x, PAIR y) {
			if (x.first == y.first) return x.second < y.second;
			return x.first < y.first;
		});

	REP(i, m) {
		OUT(string((6 - to_string(d[i].first).size()), '0'));
		OUT(d[i].first);
		
		int ok = (upper_bound(ALL(d), d[i]) - d.begin()) + 1;
		// int ng = upper_bound(ALL(d), d[i]) - d.begin();

		/*
		auto check = [&](int mid) {
			return d[i].second >= cp_d[mid].second;
		};
		
		while (ng - ok > 1) {
			int mid = (ng + ok) / 2;
			if (check(mid)) ok = mid;
			else ng = mid;
		}
		*/

		OUT(string((6 - to_string(ok).size()), '0'));
		OUT(ok)BR;
		
	}
	
  return 0;
}
