#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main()
{
  int N;
  cin >> N;
  vector< int64 > a(N);
  map< int64, int64 > mp;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    mp[a[i]]++;
  }

  int64 ans = 0ll;
  for (auto&& mi : mp) {
    if (mi.second < mi.first) {
      ans += mi.second;
    } else {
      ans += mi.second - mi.first;
    }
	
    // ans += min(mi.second, abs(mi.second - mi.first));
  }

  cout << ans << endl;
 
  return 0;
}
