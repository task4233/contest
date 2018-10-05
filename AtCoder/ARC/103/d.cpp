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
	vector< int > x(n), y(n), sm(n, 0);
	REP(i, n) {
		cin >> x[i] >> y[i];
		sm[i] = abs(x[i]) + abs(y[i]);
	}

	bool ok = true;
	REP(i, n - 1) {
		ok &= sm[i] % 2 == sm[i + 1] % 2;
	}

	if (!ok) {
		OUT(-1)BR;
		return 0;
	}


	int m = 20 + sm[0] % 2;
	OUT(m)BR;
	REP(i, m) {
		OUT(1);
		if (i < m - 1) SP;
	}
	BR;
	REP(i, n) {
		int t = 0;
		if (x[i] > 0) {
			OUT(string(x[i], 'R'));
		} else {
			OUT(string(-x[i], 'L'));
		}
		t += abs(x[i]);

		if (y[i] > 0) {
			OUT(string(y[i], 'U'));
		} else {
			OUT(string(-y[i], 'D'));
		}
		t += abs(y[i]);

		REP(i, m - t) {
			if (i & 1) {
				OUT('U');
			} else {
				OUT('D');
			}
		}
		BR;
	}
 	
  
  return 0;
}
