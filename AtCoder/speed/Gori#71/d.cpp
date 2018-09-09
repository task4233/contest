#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

int main()
{
  int N, T;
  cin >> N >> T;
  vector< int64 > a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  
  map< int64, int > mp;
  int64 l = a[0];
  for (int i = 0; i < N; ++i) {
    if (a[i + 1] > a[i]) {
      l = min(l, a[i + 1]);
    } else {
      mp[a[i] - l]++;
      l = a[i + 1];
    }
  }

  int64 mx = 0, ans = 0;
  for (auto m : mp) {
    if (m.first > mx) {
      ans = m.second;
      mx = m.first;
    }
  }

  cout << ans << endl;
  return 0;
}
