#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1010;

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

int dp[MAX_N][MAX_N];

signed main() {
  INIT;
	VAR(int, n, m);
	VEC(int, a, n);
	VEC(int, b, m);
	int sm = 0;
	REP(i, n) sm += a[i];
	REP(i, m) sm += b[i];

	RREP(i, n) {
		RREP(j, m) {
			if ((i + j) % 2 == 0) {
				// 後手
				dp[i][j] = max(dp[i + 1][j] + a[i],
															 dp[i][j + 1] + b[j]);
			} else {
				// 先手
				dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	OUT(max(dp[0][0], sm))BR;
  
  return 0;
}
