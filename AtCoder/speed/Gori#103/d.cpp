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

int c[10][10];
int a[202][202];

signed main() {
  INIT;
	VAR(int, H, W);
	REP(hi, 10) {
		REP(wi, 10) {
			cin >> c[hi][wi];
		}
	}

	REP(h, 10) {
		REP(i, 10) {
			REP(j, 10) {
				c[i][j] = min(c[i][j], c[i][h] + c[h][j]);
			}
		}
	}

	int ans = 0;
	REP(hi, H) {
		REP(wi, W) {
			cin >> a[hi][wi];
			if (a[hi][wi] < 0 || a[hi][wi] == 1) continue;
			ans += c[a[hi][wi]][1];
		}
	}
	OUT(ans)BR;

  
  return 0;
}
