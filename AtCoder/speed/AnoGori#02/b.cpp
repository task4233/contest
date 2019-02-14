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

int gcd(int a, int b){
	return (a%b==0?b:gcd(b, a%b));
}

signed main() {
  INIT;
	VAR(int, n, m);
	VAR(string, s, t);

	int gc = gcd(n,m);
	int len = n * m / gcd(n, m);
	// string ans = string(len, 'A');
	//debug(len);
	// m * n / gc
	// si * m * gc == ti * n * gc?
	map<int, int > mp;
	REP(si, n){
		mp[si*len/n] = s[si];
	}
	REP(ti, m) {
		if (!mp[ti*len/m] == 0 && mp[ti*len/m] != t[ti]) {
			//debug(mp[ti*len/m]);
			OUT(-1)BR;
			return 0;
		}
	}
	// REP(si, n) {
	// 	ans[si*len/n] = s[si];
	// }

	// REP(ti, m) {
	// 	if (ans[ti*len/m] != 'A' && ans[ti * len/m] != t[ti]) {
	// 		//debug(ans[2*len/m]);
	// 		//debug(t[ti]);
	// 		OUT(-1)BR;
	// 		return 0;
	// 	}
	// 	ans[ti*len/m] = t[ti];
	// }
	
	OUT(len)BR;
	
  return 0;
}
