#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int MAX_N = 101;
const int MAX_W = MAX_N * 3;

int64 dp[MAX_N][MAX_W];

int main()
{
  int N, W;
  cin >> N >> W;
  vector< int64 > w(N);
  vector< int64 > v(N);
  vector< int64 > diff(N);
  for (int i = 0; i < N; ++i) {
    cin >> w[i] >> v[i];
    diff[i] = w[i] - w[0];
  }

  int64 sm = 0ll;
  for (int i = 0; i < N; ++i) {
    for (int j = i; j >= 0; --j) {
      for (int64 k = sm; k >= 0; --k) {
	dp[j + 1][k + diff[i]] = max(dp[j + 1][k + diff[i]],
				     dp[j][k] + v[i]);
      }
    }
    sm += diff[i];
  }

  int64 ans = 0ll;
  
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j < MAX_W; ++j) {
      sm = w[0] * i + j;
      if (sm > W) {
	continue;
      }

      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << endl;
  
  return 0;
}
