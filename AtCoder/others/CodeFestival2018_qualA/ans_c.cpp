#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int, int>;
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
#define BR cout<<"\n";
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

// dp[i][j][0] := i個までみて、今までの数をj回割って、0にしていない(割り切っていない)
// dp[i][j][1] := i個までみて、今までの数をj回割って、0にしている(割り切ってしまってループに遷移している)
int dp[55][60 * 55][2];

signed main() {
  INIT;
  VAR(int, n, k);
	VEC(int, a, n);
	REP(i, n) {
		int cnt = 0;
		while (a[i] > 0) {
			a[i] /= 2;
			cnt++;
		}
		a[i] = cnt + 1; // 0になるまでに割れる回数を先に計算しておく
	}

	dp[0][0][0] = 1;
	REP(i, n) { // i個目まで見ている
		REP(j, 60 * 55) { // 全体でj回割っている
			REP(num, a[i]) { // i個目の数を0になるまで割り切る
				if (num + j < 60 * 55) { // 最大値を超えない場合は両方を遷移させる
					(dp[i + 1][num + j][0] += dp[i][j][0]) %= MOD;
					(dp[i + 1][num + j][1] += dp[i][j][1]) %= MOD;
				 }
			}

			if (a[i] + j < 60 * 55) { // i個目の数を0になるまで割った時の和が最大値を超えてしまった時は全てループに遷移する
				(dp[i + 1][a[i] + j][1] += dp[i][j][0]) %= MOD;
				(dp[i + 1][a[i] + j][1] += dp[i][j][1]) %= MOD;
			}
		}
	}

	int ans = 0;
	if (k < 60 * 55) { // kが最大値に届いていないときは、全てが0にならないことがある
		(ans += dp[n][k][0]) %= MOD;
	}
	REP(i, min((int64)60 * 55, k)) {
		(ans += dp[n][i][1]) %= MOD;
	}
	OUT(ans)BR;
	
  return 0;
}
