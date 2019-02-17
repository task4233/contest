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

// W*Hの全てのマスに金塊が置かれている
// N個の金塊回収マシンを用いて集められる金塊の最大値を求めたい
// 金塊を回収できる条件は,
// x/y+1 \leq i \leq p-1
// p-1   \leq i \leq x/y-1
// の全てのマスに金塊が存在すること
//
// なるべく重複しない様に取りたい
// 1 \leq W,H \leq 10^6
// 1 \leq N \leq 30

// 東西南北で取れる金塊の個数をメモする
// O(N * 4 * max(W,H))
// NONONONONONONO
// 20なんだから2^20で, next_permutationでは?
// 20 * 2^20で10^7くらい??
// 間に合うじゃあないですか！
// 大きい方から考えると, 取れる分と分割後の領域はわかる
// 分割後の領域をメモする方法がわからない

// 解説みる
// 領域分割してからdpらしい
// ここからdpだと気付けなかった...
// それでも1e6の時は無理では...?
// dp[i][j][k][l] := 左上が(i,j), 右下が(k,l)の長方形領域が残った時の最適解
// 遷移
// 分割前は分割後の最適解から求められる
// 例えば, (p,q)で分割した時, 
// dp[i][j][k][l] = dp[i][p-1][k][q-1] + dp[i][p-1][q+1][l]
//                  dp[p+1][j][k][q-1] + dp[p+1][j][q+1][l]
// の様になる
// それぞれの値の埋め方は, 
// このDPテーブルを埋めるには, O(N*H^2*W^2)かかる
// ダメだ...
// 満点解法は座圧を使うらしい
// 座圧ってこういう風に使うのか...
// 連続する区間は, 座圧すると嬉しくなる
// 座圧の方法は, mapで前からやれば上手くいくらしい

int n,w,h;
vector< int > x,y;
map< tuple< int, int, int, int >, int > memo;

// 再帰用の関数
int solve(int hi,int hj,int wi,int wj){
	auto tmp_frame = make_tuple(hi,hj,wi,wj);
	if(memo.count(tmp_frame)) return memo[tmp_frame];

	int res = 0;
	// n個の回収機について, 全て作動させた時の最適解を求める
	REP(i,n){
		int yi=y[i], xi=x[i];
		// 領域に入っている時に, それを最適解として選択する
		if(!(hi<=yi&&yi<=hj && wi<=xi&&xi<=wj)) continue;

		// (hj-hi+1) + (wj-wi+1) - 1 = hj-hi+wj-wi+1
		res = max(res, hj-hi+wj-wi+1 +
							solve(hi,yi-1,wi,xi-1) + solve(hi,yi-1,xi+1,wj) +
							solve(yi+1,hj,wi,xi-1) + solve(yi+1,hj,xi+1,wj));
	}

	return memo[tmp_frame] = res;
}

signed main() {
  INIT;
	cin>>w>>h>>n;
	x.resize(n),y.resize(n);
	REP(i,n) cin>>x[i]>>y[i];

	// 区間は問題に従い, 閉区間とする
	// [hi,hj], [wi,wj]
	int ans = solve(1,h,1,w);
	OUT(ans)BR;
	
  return 0;
}
