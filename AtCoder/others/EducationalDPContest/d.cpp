#include <bits/stdc++.h>
using namespace std;

int64_t dp[101][101010];

int main() {
	int64_t n, W;
	cin >> n >> W;
	vector< int64_t > w(n), v(n);
	for (int i=0; i<n; ++i) cin >> w[i] >> v[i];

	for (int ni=0; ni<n; ++ni) {
		for (int wi=0; wi<=W; ++wi) {
			dp[ni+1][wi] = max(dp[ni][wi], dp[ni+1][wi]);
			if (wi+w[ni] > W) continue;
			dp[ni+1][wi+w[ni]] = max(dp[ni+1][wi+w[ni]], dp[ni][wi] + v[ni]);
		}
	}

	int64_t ans = 0;
	for (int i=0; i<=W; ++i) {
		ans = max(ans, dp[n][i]);
		
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
