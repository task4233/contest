#include <bits/stdc++.h>
using namespace std;



int main() {
	int n; cin >> n;
	vector< int > h(n);
	for(int i=0;i<n;++i) cin >> h[i];

	vector< int > dp(n+1, 1e9+1);

	dp[0] = 0;
	for(int i=0;i<n;++i){
		if (i>0) dp[i] = min(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
		if (i>1) dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
	}
	cout << dp[n-1] << endl;
	
  return 0;
}
