#include <bits/stdc++.h>
using namespace std;

int dp[101010];

int main() {
	int n;
	cin >> n;
	vector< int > h(n);
	for (int i=0; i<n; ++i) cin >> h[i];

	fill_n(dp, 101010, 1e9+1);
	dp[0] = 0;
	for (int i=0; i<n; ++i) {
		if (i+1 < n) dp[i+1] = min(dp[i+1], dp[i] + abs(h[i+1] - h[i]));
		if (i+2 < n) dp[i+2] = min(dp[i+2], dp[i] + abs(h[i+2] - h[i])); 
	}

	int ans = dp[n-1];
	cout << ans << endl;
	
  return 0;
}
