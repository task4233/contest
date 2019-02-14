#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	vector< int > h(n);
	for(int i=0;i<n;++i) cin >> h[i];

	vector< int > dp(n, 1e9+1);
	dp[0] = 0;
	for (int i=0;i<n;++i){
		for (int j=0;j<k;++j){
			if (i-j>=0) dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
		}
	}

	cout << dp[n-1] << endl;

	for (int i=0;i<n+1;++i)cerr << dp[i] << endl;
	
  return 0;
}
