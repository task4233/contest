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

// [0, L]の座標間
// 整数で始まり, 整数で終わる
// 整数座標の点でのみ侵攻方向を変えられる
// i-0.5の座標を通る荼毘に, i番目の耳に石を1個入れる
// e.g.)
// 0.5 => 1番目の耳に
// 3.5 => 4番目の耳に
// 座標+0.5に石を1こ入れる

// りんご
// 耳を1つ選び, 石を1個入れる
// 石が1個以上入っている耳を選び, 取り出す
// 初期操作を自由に選べる時, 絶対値の差を最小化必要な操作回数の最小値を求めよ


signed main() {
  INIT;
	VAR(int, l);
	vector< int > a(l);
	vector< int > state(l);
	// 0: 0, 1:奇数, 2:偶数
	REP(i,l){
		cin >> a[i];
		if (a[i] == 0) state[i] = 0;
		else if (a[i] % 2 == 1)  state[i] = 1;
		else state[i] = 2;
		debug(state[i]);
	}

	vector< int > sm_odd(l+1, 0), sm_even(l+1, 0), lr_cnt(l+1, 0), lr_zero(l+1,0);
	REP(i, l) {
		if (i>0 && state[i] == state[i-1]) {
			lr_cnt[i] = lr_cnt[i-1] + 1;
		} else lr_cnt[i] = 1;

		if (i>0) lr_zero[i] = lr_zero[i-1];
		
		if (state[i] == 0) {
			lr_zero[i]++;
		} else {
			sm_odd[i] += (i>0?sm_odd[i-1]:0) + (state[i]==1?1:0);
			sm_even[i] += (i>0?sm_even[i-1]:0) + (state[i]==2?1:0);
		}
	}

	vector< int > rl_cnt(l+1, 0);
	RREP(i, l) {
		if (i+1<l && state[i+1] == state[i]) rl_cnt[i] = rl_cnt[i+1] + 1;
		else rl_cnt[i] = 1;
	}
	vector< int > rl_zero(lr_zero);
	int mx = rl_zero.back();
	REP(i, l) {
		rl_zero[i] = abs(rl_zero[i] - mx);
	}
	reverse(ALL(rl_zero));

	int ans = INF;
	FOR(i, 1, l) {
		int tmp = 0;
		if (state[i] == 0) continue;
		if (i>0 && state[i-1] == 0) continue;
		if (i>0 && state[i] == state[i-1]) {
			continue;
		}

		// 左と右で違ったら
		// 左は全てstate[i-1]
		tmp += (state[i-1]==1?sm_even[i-1]:sm_odd[i-1]);
		// ゼロの分
		// int l_z =  ((lower_bound(ALL(lr_zero), lr_zero[i-1])) - lr_zero.begin()) - 1;
		// tmp -= (state[i-1]==1?sm_even[l_z]:sm_odd[l_z]);
		debug(i);
		debug(tmp);
		
		// 右は全てstate[i]
	  tmp += (state[i]==1?sm_even[i]-sm_even[i-1]:sm_odd[i]-sm_odd[i-1]);
		// ゼロの分
		// int r_z =  l - (((lower_bound(ALL(rl_zero), rl_zero[l-i-1])) - rl_zero.begin()) - 1) - 1;
		// tmp -= (state[i]==1?sm_even[r_z]:sm_odd[r_z]);
		debug(tmp);
		ans = min(ans, tmp);
	}
	OUT(ans)BR;
  
  return 0;
}
