#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 2020;

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
#define debug(x) cerr << #x << ":" << (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

int sm[MAX_N][MAX_N];

int getSum(int x1, int y1, int x2, int y2) {
	// return sum(x1 <= x <= x2, y1 <= y <= y2)
	if (x1 > x2 || y1 > y2) return 0;
	// 鳩の巣原理
	return sm[x2][y2] - sm[x1 - 1][y2] - sm[x2][y1 - 1] + sm[x1 - 1][y1 - 1];
}

signed main() {
  INIT;

	VAR(int, n, k);
	vector< int > x(n), y(n), c(n);
	REP(i, n) {
	  cin >> x[i] >> y[i];
		VAR(char, t);
		(x[i] += (t == 'B' ? k : 0)) %= 2 * k;
		(y[i] += (t == 'B' ? k : 0)) %= 2 * k;
	}

	REP(i, n) {
		sm[x[i]][y[i]]++;
	}

	REP(hi, MAX_N) {
		REP(wi, MAX_N) {
			if (hi == 0 && wi == 0) continue;
			if (hi == 0) {
				sm[hi][wi] += sm[hi][wi - 1];
			} else if (wi == 0) {
				sm[hi][wi] += sm[hi - 1][wi];
			} else {
				sm[hi][wi] += sm[hi - 1][wi];
				sm[hi][wi] += sm[hi][wi - 1];
				sm[hi][wi] -= sm[hi - 1][wi - 1];
			}
		}
	}
	
	
	int ans = 0;
	REP(hi, k) {
		REP(wi, k) {
			// W: (x, y) = ([0, hi) || [hi + k, 2 * k), [0, wi) || [wi + k, 2 * k))
			int cnt = 0;
			cnt += getSum(wi, hi, wi + k - 1, hi + k - 1);
			cnt += getSum(wi + k, hi + k, 2 * k, 2 * k);
			cnt += getSum(1, 1, wi - 1, hi - 1);
			cnt += getSum(wi + k, 1, 2 * k, hi - 1);
			cnt += getSum(1, hi + k, wi - 1, 2 * k);
			ans = max(ans, max(cnt, n - cnt));
		}
	}
	OUT(ans)BR;
  
  return 0;
}
