#include <bits/stdc++.h>

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

// あるブロックに書き込まれる整数は, そのブロックの左下, 真下, 右下のブロックの中央値である
// 一番上のブロックがxの時, 存在するN段目の並びを求めよ(1, ..., 2N-1とする)
//   x
// i x j (i<=x, x<=j)
// xが(1)or(2N-1)の時は無理
// 2の時は?
//     2
//   2 2 4
// 1 3 2 4 5

// 4, 4
//       4
//     3 4 5
//   2 3 4 5 6
// 1 2 3 4 5 6 7

// 一般化すると,
// 同じ数字が2個並べば良い
// x-1, x, x+1, x-2とすれば良いらしい
// ただし, x=2の時は+-を逆にすれば良い
// x+1, x, x-1, x+2

signed main() {
  INIT;
	VAR(int, n, x);

	if (n==2){
		if (x==2) {
			OUT("Yes")BR;
			OUT(1)BR;
			OUT(2)BR;
			OUT(3)BR;
		} else {
			OUT("No")BR;
		}
		return 0;
	}
	
	if (x==1 || x==2*n-1){
	  OUT("No")BR;
		return 0;
	}
	OUT("Yes")BR;
	vector<int> ans(2*n-1);
	int cnt = 1;
  if (x==2){
		ans[n-2] = x+1;
		ans[n-1] = x;
		ans[n] = x-1;
		ans[n+1] = x+2;
		REP(i,2*n-1){
			if (n-2 <= i && i<= n+1) continue;
			while (x-1 <= cnt && cnt <= x+2) ++cnt;
			ans[i] = cnt++;
		}
		EACH(ai,ans) {
			OUT(ai)BR;
		}
		return 0;
	}
	ans[n-2] = x-1;
	ans[n-1] = x;
	ans[n] = x+1;
	ans[n+1] = x-2;
	REP(i,2*n-1){
		if (n-2 <= i && i<= n+1) continue;
		while (x-2 <= cnt && cnt <= x+1) ++cnt;
		ans[i] = cnt++;
	}
	EACH(ai,ans) {
		OUT(ai)BR;
	}
	
  
  return 0;
}
