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
	VAR(int, n, k);
	VEC(int, x, n);
	
	vector<int> bit(40, 0);
	REP(i, n){
		REP(bi, 40){
			if ((x[i] >> bi) & 1) ++bit[bi];
		}
	}
	
	vector<int> ans(41, 1);
	REP(bi, 41) {
		if (n%2 == 0) {
			if (bit[bi] == n/2) {
				ans[bi] = 0;
				continue;
			}
		}
		if (bit[bi] > n/2) ans[bi] = 0;
		//OUT(bit[bi]);
	}
	//BR;

	/*
	REP(i, n){
		OUT(ans[i]);
	}
	BR;
	*/

	vector< PAIR > dd;
	REP(i,40){
		dd.push_back({bit[i], i});
	}
	
	int X = 0;
	int Y = 0, mx;
	REP(i, 41) {
		if (ans[i] == 1) {
			if (X + (1 << i) > k) {
				Y = X + (1 << i);
				mx = i;
				break;
			}
			X += (1 << i);
		}
	}
	// debug(X);
	// debug(Y);

	int diff = Y - k;
	//debug(diff);
	//debug(mx);
	RREP(i, mx) {
		REP(j, i+1)
		if (ans[j] == 1 && (1 << j) >= diff) {
			Y -= (1 << j);
			//debug(j);
			break;
		}
		if (Y <= k) break;
		Y -= (1 << i);
		diff -= (1 << i);
		if (Y <= k) break;
	}

	if (Y > k) Y = -1;
	
	int res = 0;
	int res_y = 0;
	REP(i, n) {
		res += (x[i] xor X);
		res_y += (x[i] xor Y);
	}
	
	if (Y < 0) {OUT(res)BR;}
	else {OUT(max(res, res_y))BR;}
	
  return 0;
}
