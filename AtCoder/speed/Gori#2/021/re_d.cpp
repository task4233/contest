#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;
#define int int64

// 解法
// 制約からbitDPであることに気づく
// dp[i][j] := i番目のうさぎまで見たときに,
//             状態がj(0:unreached, 1:reached)だったときの通り数
// その後, 遷移を考える
// i番目のうさぎが遷移できるのは,
// - i=xiのとき, 状態jのyiビット目が立っていないとき(yi番目のうさぎは到達していてはならない)
// - i=yiのとき ,状態jのxiビット目が立っているとき(xi番目のうさぎは到達していなければならない)

// よって, 計算量はO(n*2^n*n*m)=O(n^2*2^n*m)

int dp[20][(1<<20)];
vector< int > e[20];

signed main() {
	int n,m; cin >> n >> m;
	for(int mi=0;mi<m;++mi){
		int x,y;
		cin >> x >> y;
		--x; --y;
		e[x].push_back(y);
	}

	dp[0][0] = 1;
	for(int ni=0;ni<n;++ni){
		for(int state=0;state<(1<<n);++state){
			// i番目のうさぎへの遷移が可能かを確認
			for(int i=0;i<n;++i){
				if(state & (1<<i)) continue;

				bool can_move = true;
				for (auto &&ti: e[i]) {
					can_move &= !(state & (1<<ti));
				}
				
				if (!can_move) continue;
				dp[ni+1][state | (1<<i)] += dp[ni][state];
			}
		}
	}

	int ans = dp[n][(1<<n)-1];
	cout << ans << endl;
  return 0;
}
