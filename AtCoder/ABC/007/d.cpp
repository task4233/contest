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

// 4と9を含む数字が区間[A,B]にいくつあるかを求めよ
// 1 \leq A,B \leq 10^18
// ある数Xまでの数字で4と9を含むものがいくつあるかを求めたい
// それで, solve(B)-solve(A)をすればおk
// 桁に含まれているか否かで桁DPすれば良さそう
// dp[i][j][k] := i桁目までみて, 与えられた数字X以下で(k?ある:ない)時で, かつ{4,9}が含まれていることが確定して(j?いる:いない)時の数え上げ数
// 遷移
// まず, jの未確定/確定は桁の数字と与えられた数字Xの桁の数字を比較することで判断できる
// jについて作る数字のi桁目をpとすると, d桁目において
// j:1->1(確定->確定)
// なんでもおk
// X[i] > pのとき
// j:0->1(未確定->確定)
// x[i] == pのとき
// j:0->0(未確定->未確定)
// X[i] < pのとき
// 考えない(与えられた上限を超えているため)
// 次に, kの確定/未確定の遷移は, p \in {4,9}か否かで確定する
// 上の議論を持ち越すと
// X[i] > pの時
// if p=={4,9}
// この時, いかなる数字が来ても, 確定状態になる
// dp[i+1][1][1] += dp[i][j][k]
// else
// dp[i+1][1][k] += dp[i][j][k]
// X[i] == pの時
// if p=={4,9}
// この時, 未確定状態ではあるが, kは確定状態になる
// dp[i+1][0][1] += dp[i][0][k]
// else
// dp[i+1][0][k] += dp[i][0][k];
// X[i] < pの時
// 前のjが確定状態の時は遷移できるが, 未確定の場合は遷移できない
// if p=={4,9}
// dp[i+1][1][1] += dp[i][1][k];
// else
// dp[i+1][1][k] += dp[i][1][k]

int dp[20][2][2];

int solve(string x){
	// debug(x);
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	int n = x.size();
	REP(i,n){
		REP(p, 10){
			//debug((x[i]>p+48 ? "more":"less"));
			if(x[i] > p+48){
				if(p==4 || p==9){
					// j:->確定
					REP(j,2){
						REP(k,2){
							dp[i+1][1][1] += dp[i][j][k];
						}
					}
				} else {
					REP(j,2){
						REP(k,2){
							dp[i+1][1][k] += dp[i][j][k];
						}
					}
				}
			} else if (x[i] == p+48){
				if(p==4 || p==9){
					// j:未確定->未確定
					// j:確定->確定
					REP(j,2){
						REP(k,2){
							dp[i+1][j][1] += dp[i][j][k];
						}
					}
					
				} else {
					REP(j,2){
						REP(k,2){
							dp[i+1][j][k] += dp[i][j][k];
						}
					}
				}
			} else {
				// j:確定->確定
				if(p==4||p==9){
					REP(k,2){
						dp[i+1][1][1] += dp[i][1][k];
					}
				} else {
					REP(k,2){
						dp[i+1][1][k] += dp[i][1][k];
					}
				}
			}
		}
	}

	/*
	REP(i,n+1){
		debug(i);
		REP(j,2){
			REP(k,2){
				cerr << dp[i][j][k] << " ";
			}
			cerr << endl;
		}
		cerr << endl << endl;
	}
	debug(dp[n][1][1]);
	*/
	int res = dp[n][1][1] + dp[n][0][1];
	return res;
}

signed main() {
  INIT;
	VAR(int, a, b);
	
	int ans_a = solve(to_string(a-1));
	int ans_b = solve(to_string(b));
	int ans = ans_b - ans_a;
	OUT(ans)BR;
  
  return 0;
}
