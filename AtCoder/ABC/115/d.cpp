#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
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

int memo[55];
int p_memo[55];

int f(int n) {
	if (n == 0) return memo[0] = 1;
	return memo[n] = f(n - 1) * 2 + 3;
}

int fill_p(int n) {
	if (n == 0) return p_memo[0] = 1;
	return p_memo[n] = fill_p(n - 1) * 2 + 1;
}

int solve(int x, int n) {
	if (x == 0) return 0;
	if (n == 0) return 1;
	/*
	debug(x);
	debug(n);
	debug(memo[n]);
	debug(p_memo[n]);BR;
	*/
	int res = 0;
	x--;
	if (x >= memo[n - 1]) {
		res += p_memo[n - 1];
		x -= memo[n - 1];
	} else {
		return res += solve(x, n - 1);
	}
	if (x == 0) return res;
	
 	res++;
	x--;
	if (x >= memo[n - 1]) {
		res += p_memo[n - 1];
		x -= memo[n - 1];
	} else {
		return res += solve(x, n - 1);
	}
	x--;
	return res;
}


signed main() {
  INIT;
	VAR(int, n, x);
	f(n);
	fill_p(n);
	
	/*int ans;
	if (x >= memo[n] / 2) {
		ans = p_memo[n] - solve(memo[n] - x, n);
	} else {
		ans = solve(x, n);
	}
	*/
	int ans = solve(x, n);
	OUT(ans)BR;

	
	//debug(p_memo[n]);
  
  return 0;
}
