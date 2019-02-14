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
	VAR(int, n, c);
	vector< int > x(n), v(n);
	REP(i, n) {
		cin >> x[i] >> v[i];
	}
	
	auto solve = [=]() {
		vector< int > sm(n + 1, 0), rev(n, 0), rev_sm(n + 1, 0), rev_ans(n + 1, 0);
		
		int res = 0;
		// 累積和
		sm[0] = v[0];
		REP(i, n) {
			sm[i] = sm[i - 1] + v[i];
		}

		// 逆回りの時の累積和
		rev_sm[n - 1] = v[n - 1];
		RREP(i, n - 2) {
			rev_sm[i] = rev_sm[i + 1] + v[i];
		}
		
		// 逆回りの時の、i番目のsushiまでの距離
		REP(i, n) {
			rev[i] = c - x[i];
		}

		// 逆回りの時の最適解
		rev_ans[n - 1] = rev_sm[n - 1] - rev[n - 1];
		RREP(i, n - 2) {
			rev_ans[i] = rev_sm[i] - rev[i];
			rev_ans[i] = max(rev_ans[i], rev_ans[i + 1]);
		}

		// 右端固定
		REP(i, n) {
			int tmp_sm = sm[i] - x[i];
			res = max(res, tmp_sm);
			tmp_sm -= x[i];

			// 最後まで行ったら取れない
			if (i < n - 1) tmp_sm += rev_sm[i + 1]; 
			res = max(res, tmp_sm);
		}

		return res;
	};
	
	int ans = solve();

	reverse(ALL(v));
	REP(i, n) x[i] = c - x[i];
	reverse(ALL(x));

	ans = max(ans, solve());
	OUT(ans)BR;
  
  return 0;
}
