#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 202020;

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

signed main() {
  INIT;
	VAR(int, n, x);
	vector< int > a(MAX_N);
	vector< int > sm(MAX_N, 0);
	FOR(i, 1, n + 1) {
		cin >> a[i];
	}
	FOR(i, 1, n + 1) {
		sm[i] = a[i] + sm[i - 1];
	}
	
	int ans = LINF;
  FOR(k, 1, n + 1) {
		int tmp = k * x;
		REP(i, (n - 1) / k + 1) {
			int q = n - i * k;
			int p = max(0LL, q - k);
			int c = (i == 0 ? 5 : 2 * (i + 1));
			tmp += c * (sm[q] - sm[p]);
			if (tmp < 0) break;
		}
		if (tmp > 0) ans = min(ans, tmp);
	}
	ans += n * x;
	OUT(ans)BR;
  return 0;
}
