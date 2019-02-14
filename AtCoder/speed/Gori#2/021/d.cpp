#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;
#define int int64
// n!
// xi < yi
// 片方が決まればもう片方も決まる
// 2 1
// 2 3
// 連続している場合, 確定する
// 1 2
// 2 3

// n: 16
// m: 120

// bitDP?
// mはソートしておき, 左辺値よりも右辺値の方が小さい時はそれを認めない
// dp[i][j] := iという状態で(01), j番目まで見たときの数え上げ
// O(2^n*m*n)

constexpr int MAX_N = 16;
constexpr int MAX_M = 16 * 15 / 2;

signed main() {
	int n,m;
	cin >> n >> m;

	vector< int > fr[MAX_N], to[MAX_N];
	for (int i=0;i<m;++i){
		int x, y;
		cin >> x >> y;
		--x; --y;
		fr[x].push_back(y);
		to[y].push_back(x);
	}

	vector< vector< int > > dp(n+1, vector< int >(1<<(n+1), 0));
	dp[0][0] = 1;
	for (int i=0;i<n;++i){
		for (int state=0;state<(1<<n);++state){
			for (int fi=0;fi<n;++fi){
				if (state & (1<<fi)) continue;
				// cerr << i << endl;

				// まだfiに到達していないzenntei
				// fiに対してto[fi]はまだ到達していない
				// fiに対してfr[fi]は既に到達している
				bool can_move = true;
				for (auto &&ti: to[fi]){
					if ((state & (1<<ti)) != 0) can_move = false;
				}
				for (auto &&fj: fr[fi]){
					if ((state & (1<<fj)) == 0) can_move = false;
				}
				if (!can_move) continue;
				dp[i+1][state | (1<<fi)] += dp[i][state];
			}
		}
	}

	int ans = dp[n][(1<<n)-1];
	cout << ans << endl;

	for (int i=0;i<n;++i){
		for (int j=0;j<(1<<n);++j){
			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	
  return 0;
}
