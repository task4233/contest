#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 10007;
constexpr int MAX_N = 1e6 + 1;

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
#define BR cout<<endl;
#define zero(n) cout<<setfill('0')<<right<<setw(n)
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

int memo[MAX_N];

int f(int n) {
	if (n < 3) return 0;
	if (n == 3) return 1;
	if (memo[n] > -1) return memo[n];
	return memo[n] = (f(n - 1) + f(n - 2) + f(n - 3)) % MOD;
}

signed main() {
  INIT;
	fill_n(memo, MAX_N, -1);
	VAR(int, n);
	OUT(f(n))BR;
  
  return 0;
}
