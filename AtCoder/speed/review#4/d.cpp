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

// dp[i] := i本使った時の最大の桁数を求めたい
// 遷移
// dp[i] = max(dp[i-cost[j]] + 1, dp[i])

// その後, dpテーブルを復元する
// 最後のdpから復元し, 成立するものを選んで前に遷移すれば良い

int cost[9]={2,5,5,4,5,6,3,7,6};
int dp[101010];
int memo[101010];

signed main() {
  INIT;
	VAR(int,n,m);
  VEC(int,a,m);
	sort(ALL(a));
	reverse(ALL(a));

	// dpテーブルの生成
	for(int i=0;dp[i]<=n;++i) {
		REP(j,a.size()){
			if (i-cost[a[j]-1]>=0){
				if (dp[i-cost[a[j]-1]] + 1 > dp[i]){
					dp[i] = max(dp[i], dp[i-cost[a[j]-1]] + 1);
					memo[i] = i-cost[a[j]-1];
				}
			}
		}
		if(dp[i]>n) break;
	}

	vector<int>ans;
	// 復元
	while(n!=0){
		REP(j,a.size()){
			if(dp[n]==1){
				// 最後の遷移はちょうど0になるようにする
				if(n-cost[a[j]-1]==0 && dp[n] == dp[n-cost[a[j]-1]] + 1){
					ans.push_back(a[j]);
					// debug(a[j]);
					n = 0;
					break;
				}
			} else {
				if(n-cost[a[j]-1]>=0 && dp[n] == dp[n-cost[a[j]-1]] + 1){
					ans.push_back(a[j]);
					n=memo[n];
					//debug(a[j]);
					break;
				}
			}
		}
		//debug(n);
	}
	EACH(ai,ans){
		OUT(ai);
	}
	
  return 0;
}
