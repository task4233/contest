#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector< int > x(n), y(n);
	for(int i=0;i<n;++i) cin >> x[i] >> y[i];

	// n, m: 1e5
	// dpかと思ったが, 間に合わない
	// 答えるのは可能性がある箱の個数なので, 発想の転換が必要?
	// n=1e5なので, nlognゲーなきがする.
	// 移す前は1のとき0に,
	// 移す後は1になる.
	// dp[i][j] := i番目(偶奇)の

	vector< int > state(n, false);
	state[0] = true;
	
	
  return 0;
}
