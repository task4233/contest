#include <bits/stdc++.h>
using namespace std;

// dp[i][j] := j: 0:a, 1:b, 2:c
int dp[101010][3];

int main() {
	int n;
	cin >> n;
	vector< vector< int > > d(n, vector< int >(3, 0));
	for (int i=0; i<n; ++i) {
		cin >> d[i][0] >> d[i][1] >> d[i][2];
	}

	for (int ni=0; ni<n; ++ni) {
		for (int ji=0; ji<3; ++ji) {
			for (int jj=1; jj<3; ++jj) {
				dp[ni+1][ji] = max(dp[ni+1][ji], dp[ni][(ji+jj)%3] + d[ni][ji]);
			}
		}
	}

	int ans = 0;
	for (int i=0; i<3; ++i) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
	
  return 0;
}
