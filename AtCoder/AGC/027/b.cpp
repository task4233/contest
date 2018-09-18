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

int a[MAX_N];
int memo[MAX_N];

signed main() {
  INIT;

	VAR(int, n, x);
	REP(i, n) {
		cin >> a[i + 1];
	}
	a[0] = 0;

	int ans = 0, cnt = 0;
	REP(i, n) {
		if (cnt == 0) {
			ans += a[i + 1];
			cnt++;
		}
		int get = (2 * cnt + 3) * a[i] + (cnt + 1) * (cnt + 1) * a[i + 1] + 2 * x + memo[i];
		int non = 5 * a[i] + (cnt + 1) * (cnt + 1) * a[i + 1] + 3 * x;

		debug(i);
		debug(get);
		debug(non);
		debug(ans);
		
		if (get > non) {
			ans += non;
			cnt = 0;
			continue;
		}

		if (i == n - 1) {
			ans += min(get, non);
		} else {
			ans += (memo[i] = (cnt + 1) * (cnt + 1) * (a[i] - a[i + 1]) + x);
			cnt++;
		}
		debug(ans);
		cout << endl;
	}
	OUT(ans)BR;
  
  return 0;
}
