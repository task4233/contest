#include <bits/stdc++.h>
using namespace std;

int dp[101010];

int main() {
	int n, k;
	cin >> n >> k;
	vector< int > h(n);
	for (int i=0; i<n; ++i) cin >> h[i];

	fill_n(dp, 101010, 1e9+1);
	dp[0] = 0;
	for (int i=0; i<n; ++i) {
		for (int ki=1; ki<=k; ++ki) {
			if (i+ki < n) dp[i+ki] = min(dp[i+ki], dp[i] + abs(h[i+ki] - h[i]));
		}
	}

	int ans = dp[n-1];
	cout << ans << endl;
	
  return 0;
}
