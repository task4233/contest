#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

int main()
{
  int64 N, x;
  cin >> N >> x;
  vector< int64 > a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    // debug(a[i]);
  }

  int64 ans = 1e18 + 1ll;
  vector< int64 > memo(a);
  
  for (int64 i = 0ll; i < N; ++i) {
    int64 sm = x * i;
    
    for (int64 j = 0ll; j < N; ++j) {
      // debug(j);
      // debug(a[j]);
      // debug(a[(N + j - i) % N]);
      memo[j] = min(memo[j], a[(N + j - i) % N]);
      sm += memo[j];
    }

    ans = min(ans, sm);
    // cout << ans << endl << endl;
  }

  cout << ans << endl;
  
  return 0;
}
