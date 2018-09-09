#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
const int MOD = 1e9 + 7;

int64 dp[4];

int main()
{
  string s;
  cin >> s;

  dp[3] = 1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'A') {
      (dp[0] += dp[3]) %= MOD;
    } else if (s[i] == 'B') {
      (dp[1] += dp[0]) %= MOD;
    } else if (s[i] == 'C') {
      (dp[2] += dp[1]) %= MOD;
    } else {
      (dp[2] = dp[2] * 3 + dp[1]) %= MOD;
      (dp[1] = dp[1] * 3 + dp[0]) %= MOD;
      (dp[0] = dp[0] * 3 + dp[3]) %= MOD;
      (dp[3] = dp[3] * 3) %= MOD;
    }
  }

  int64 ans = dp[2];
  cout << ans << endl;
  
  return 0;
}
