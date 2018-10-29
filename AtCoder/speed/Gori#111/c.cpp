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

int a[2][101];

signed main() {
  INIT;
	VAR(int, n);
	REP(i, 2) {
		REP(j, n) {
			cin >> a[i][j];
		}
	}

	vector< int > sm1(n + 1, 0);
	REP(i, n) {
		sm1[i] = a[0][i];
		if (i > 0) sm1[i] += sm1[i - 1];
	}

	vector< int > sm2(n + 1, 0);
	RREP(i, n) {
		sm2[i] = a[1][i];
		if (i > 0) sm2[i] += sm2[i + 1];
	}
	sm2[0] += sm2[1];

	int ans = 0;
	REP(i, n) {
		debug(sm1[i]);
		debug(sm2[i]);
		ans = max(ans, sm1[i] + sm2[i]);
	}
	OUT(ans)BR;
	
  
  return 0;
}
