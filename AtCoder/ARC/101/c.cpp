#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

int main()
{
  int N, K;
  cin >> N >> K;
  vector< int64 > x(N);
  bool zero_flag = false;
  for (int i = 0; i < N; ++i) {
    cin >> x[i];
    if (x[i] == 0) {
      zero_flag = true;
      K--;
    }
  }

  if (!zero_flag) {
    x.push_back(0);
    N++;
  }
  
  int64 ans = 1e18 + 1ll;
  
  sort(x.begin(), x.end());

  int zero = 0;
  for (int i = 0; i < N; ++i) {
    if (x[i] == 0) {
      zero = i;
    }
  }
  
  for (int i = 0; i < N; ++i) {
    if (i + K < N && i + K >= zero && i <= zero) {
      int64 tmp = abs(x[i + K] - x[i]);
      if (abs(i - zero) < K) tmp += abs(x[i] - x[zero]);
      ans = min(ans, tmp);
      // debug(i);
      // debug(abs(x[i + K] - x[i]));
      // debug(tmp);
    }
    if (i - K >= 0 && i - K <= zero && i >= zero) {
      int64 tmp = abs(x[i - K] - x[i]);
      if (abs(i - zero) < K) tmp += abs(x[i] - x[zero]);
      ans = min(ans, tmp);
      // debug(i);
      // debug(abs(x[i - K] - x[i]));
      // debug(tmp);
    }
  }

  cout << ans << endl;
  
  return 0;
}
