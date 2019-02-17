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

// dp[i][j] := sをi文字目まで見て, tをj文字目まで見た時の最長部分列
// 遷移
// dp[i+1][j+1] = dp[i][j] + 1 if s[i] == t[j];
// dp[i+1][j+1] = dp[i+1][j]   if dp[i+1][j] < dp[i][j+1]
// dp[i+1][j+1] = dp[i][j+1]   otherwise

// 復元路は後ろから前に辿る
// そもそも一致した部分は上で述べた遷移の一番上の繊維なので, そこの遷移を復元したい
// そこで, そこの遷移まで復元してやればよい
// while (i+j>0) {
//   // 斜めの時はvector<char> ans;にpush_back;
//   // 横の場合は--j;
//   // 縦の場合は--i;
// }

int dp[3030][3030];
// 0:斜め, 1:横, 2:縦
int memo[3030][3030];

signed main() {
  INIT;
	VAR(string, s, t);
	int n=s.size(), m=t.size();

	REP(i, n){
		REP(j, m) {
			if (s[i]==t[j]) {
				// 斜め
				dp[i+1][j+1] = dp[i][j] + 1;
				memo[i+1][j+1] = 0;
			} else if (dp[i+1][j]>dp[i][j+1]){
				// 横からの遷移の方がいい時
				// 0 0
				// 1 ?
				// のような時
				// 横
				dp[i+1][j+1] = dp[i+1][j];
				memo[i+1][j+1] = 1;
			} else {
				// 0 1
				// 0 ?
				// のような時
				dp[i+1][j+1] = dp[i][j+1];
			  memo[i+1][j+1] = 2;
			}
		}
	}

	/*
	REP(i,n+1){
		REP(j,m+1) {
			cerr << dp[i][j] << " ";
		}
		cerr << endl;
	}
	

	// これでdp[n][m]が最大長
	debug(dp[n][m]);
	*/
	int rest = dp[n][m], i=n, j=m;
	vector<char> ans;
	while(rest>0){
		switch(memo[i][j]) {
		case 0:
			// 斜め
			--i; --j;
			--rest;
			ans.push_back(s[i]);
			break;
		case 1:
			// 横
			--j;
			break;
		default:
			// 縦
			--i;
			break;
		}
	}
	reverse(ALL(ans));
	EACH(ai, ans){
		OUT(ai);
	}
	BR;
	
  return 0;
}
