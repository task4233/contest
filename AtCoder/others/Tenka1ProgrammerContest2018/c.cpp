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
	VAR(int, n);
	VEC(int, a, n);
  sort(ALL(a));

	PAIR p = make_pair(a[0], a.back());
	deque< int > dq;
	FOR(i, 1, n - 1) {
		dq.push_back(a[i]);
	}

	int ans = abs(a.back() - a[0]);
	while (!dq.empty()) {
		int f = dq.front(), l = dq.back();
		int one = abs(p.first - l), two = abs(p.second - f);
		//	debug(f);
		// debug(l);
		if (one > two) {
			p.first = l;
			dq.pop_back();
			ans += one;
		} else {
			p.second = f;
			dq.pop_front();
			ans += two;
		}
		f = p.first; l = p.second;
		p = make_pair(min(f, l), max(f, l));
		//debug(f);
		//debug(l);
		//debug(ans);
	}

	OUT(ans)BR;
  return 0;
}
