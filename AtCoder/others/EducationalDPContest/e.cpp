#include <bits/stdc++.h>
using namespace std;

// dp[ni][vi]
int64_t dp[101][101010];

int main() {
	int64_t n, W;
	cin >> n >> W;
	vector< int64_t > w(n), v(n);
	for (int i=0; i<n; ++i) cin >> w[i] >> v[i];
	fill_n(dp[0], 101010, 1e9+1);
	dp[0][0] = 0;
	
	for (int ni=0; ni<n; ++ni) {
		for (int vi=0; vi<101010; ++vi) {
			dp[ni+1][vi] = dp[ni][vi];
			if (vi-v[ni] < 0) continue;
			dp[ni+1][vi] = min(dp[ni+1][vi], dp[ni][vi-v[ni]] + w[ni]);
		}
	}

	int64_t ans = 0;
	for (int64_t i=0; i<101010; ++i) {
		if (dp[n][i] > W) continue;
		ans = max(ans, i);
	}
	cout << ans << endl;
	/*
	for (int i=0; i<=n; ++i) {
		for (int wi=0; wi<=W; ++wi){
			cout << dp[i][wi] << " ";
		}
		cout << endl;
	}
	*/
  return 0;
}
