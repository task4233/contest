#include <bits/stdc++.h>
// statics
using namespace std;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int_fast64_t LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1e5 + 1;

// init/input
#define int int_fast64_t
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
	VAR(int, r, b, x, y);

	auto check = [=](int mid) {
		int left_r = r - mid;
		int left_b = b - mid;
	  return left_r >= 0 && left_b >= 0 && (left_r / (x - 1) + left_b / (y - 1) >= mid);
	};
	
	int ok = 0, ng = LINF;
	while (ng - ok > 1) {
		int mid = (ok + ng) / 2;
		if (check(mid)) ok = mid;
		else ng = mid;
	}
	OUT(ok)BR;
  return 0;
}
