#include <bits/stdc++.h>
using namespace std;
typedef long long int64;


int main()
{
  int N;
  cin >> N;
  vector< int64 > a(N);
  vector< int64 > sm(N + 2);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    sm[i] = a[i];
  }

  for (int i = 0; i < N; ++i) {
    sm[i + 1] += sm[i];
  }

  sort(sm.begin(), sm.end());

  int64 ans = 0ll;
  int64 tmp = 1ll;
  for (int i = 1; i <= N; ++i) {
    if (sm[i] != sm[i - 1]) {      
      ans += tmp * (tmp - 1) / 2;
      tmp = 0ll;
    }
    tmp++;
  }
  if (tmp > 0) {
    ans += tmp * (tmp - 1) / 2;
  }
  
  cout << ans << endl;
  
  return 0;
}
