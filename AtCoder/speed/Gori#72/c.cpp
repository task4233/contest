#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

int main()
{
  int64 N, x;
  cin >> N >> x;
  vector< int64 > a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  int64 ans = 0LL;
  for (int i = 0; i < N - 1; ++i) {
    if (a[i] + a[i + 1] > x) {
      ans += a[i] + a[i + 1] - x;
      if (a[i] > x) {
	a[i + 1] = 0;
      } else {
	a[i + 1] = x - a[i];
      }
    }
  }

  cout << ans << endl;

  /*
  for(auto &ai : a)
    debug(ai);
  */
  return 0;
}
