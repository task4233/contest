#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

int main()
{
  int N, T;
  cin >> N >> T;
  vector< int64 > a(N);
  vector< int64 > mn(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    if (i > 0) mn[i] = min(a[i], mn[i - 1]);
    else mn[i] = a[i];
  }

  map< int64, int > mp;
  for (int i = 0; i < N; ++i) {
    mp[a[i] - mn[i]]++;
  }

  int ans = 0;
  for (auto &&m : mp) ans = m.second;
  cout << ans << endl;
  
  return 0;
}
