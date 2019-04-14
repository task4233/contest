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

// dp[見ているところ][ok/ng]
int dp[MAX_N][2][MAX_N];

int solve(string N, int k = 0, bool tight = true, int sum = 0) {

	if (k == N.size()) return sum == D;
	
	// 今見ている桁の数
	int x = N[k] - '0';

	// tightがtrueならxまでしか遷移しないようにする
	int r = (tight ? x : 9);

	int &res = dp[k][tight][sum];
	if (~res) return res;
	res = 0;

	// rまで遷移. 未満ではない
	for (int i=0; i<=r; ++i) {
		if (i == 4 || i == 9) continue;
		res += rec(k + 1, tight && i == r, sum + i);
		res %= MOD;
	}

	return res;
}

signed main() {
  INIT;
	VAR(string, a, b);
	memser(dp, -1, sizeof(dp));

	int ans = solve(b, , , ) - solve(a - '1' + '0', , ,);
	OUT(ans)BR;
  return 0;
}

// 10 -> 4, 9
// 100 -> (4, 9) /5 + (40, 90) /5- (44, 49, 94, 99)/25
