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
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

int power(int x, int n) {
	int res = 1LL;
	while (n > 0) {
		if (n & 1) (res *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	return res % MOD;
}

int dp[575][7][7][2];
// 0: a
// 1: c
// 2: g
// 3: t

 
signed main() {
  INIT;
	VAR(int,n);

	//dp[3][2][1][1] = 1;
	//dp[3][1][2][1] = 1;
	//dp[3][0][1][1] = 1;

	REP(i,4){
		REP(j,4){
			//if(i==2 && j==1) {dp[3][i][j][0] = 3;continue;}
			//if(i==1 && j==2) {dp[3][i][j][0] = 3;continue;}
			//if(i==0 && j==1) {dp[3][i][j][0] = 3;continue;}
			dp[0][i][j][0] += 1;
		}
	}
	
	
	REP(i,n){
		REP(j,4){
			REP(k,4){
				dp[i+1][j][k][1] += dp[i][j][k][1] * 4;
				REP(l,4){ // next
					if (j==0 && k==2) {
						if(l==1) dp[i+1][k][l][1] += dp[i][j][k][0];
						else dp[i+1][k][l][0] += dp[i][j][k][0];
					}
					else if (j==0 && k==1) {
						if (l==2) dp[i+1][k][l][1] += dp[i][j][k][0];
						else dp[i+1][k][l][0] += dp[i][j][k][0];
					}
					else if (j==2 && k==0) {
						if (l==1) dp[i+1][k][l][1] += dp[i][j][k][0];
						else dp[i+1][k][l][0] += dp[i][j][k][0];
					}
					else {
						dp[i+1][j][k][0] += dp[i][j][k][0];
					}
				}
			}
		}	
	}

	int ans = 0;
	int _ans = power(4,n);
	REP(i,4){
		REP(j,4){
			ans += dp[n][i][j][0];
		}
	}
	debug(_ans);
	OUT(ans)BR;
  
  return 0;
}
