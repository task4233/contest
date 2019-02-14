#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
#include <cfloat>
#include <set>
#include <map>

// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 3e5 + 1;

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


signed main() {
  INIT;
	VAR(int, n);

	if (n==1) {
		OUT(2)BR;
		return 0;
	}
	if (n==2) {
		OUT(3)BR;
		return 0;
	}
	
	vector< int > m(1000000, 2e5);

	for (int i=2; i*i<=1e12; ++i) {
		int res = LINF;
		for (int j=1; j*j<=i; ++j) {
			if (i%j!=0) continue;
			int tmp = j + i/j;
			if (j == 1) ++tmp;
			res = min(res, tmp);
		}
		m[i] = res;
	}

	int t = 2;
	while (n > (1<<t)) ++t;
	int ans1 = 2LL * sqrt(1<<t);
	debug(ans1);
	int ans = LINF;
	for (int i=333332; i>=n; --i) {
		ans = min(ans, m[i]);
		/*
		if (m[i] < ans) {
		debug(i);
		 debug(m[i]);
			ans = min(ans, m[i]);
			}
		*/
		// if (m[i] == 0) {OUT(i)SP;OUT(m[i])BR;}
	}
	OUT(ans)BR;
  
  return 0;
}
