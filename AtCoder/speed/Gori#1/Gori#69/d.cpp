#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

map< pair< int, int >, int64 > mp; 

int main()
{
  int64 H, W, N;
  cin >> H >> W >> N;
  vector< int64 > a(N);
  vector< int64 > b(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    for (int64 hi = -1; hi <= 1; ++hi) {
      for (int64 wi = -1; wi <= 1; ++wi) {
	if (0 < a[i] + hi && a[i] + hi < H - 1 &&
	    0 < b[i] + wi && b[i] + wi < W - 1) {
	  mp[make_pair(a[i] + hi, b[i] + wi)]++;
	}
      }
    }
  }

  vector< int64 > ans(10, 0ll);
  ans[0] = (H - 2) * (W - 2);
  
  for (auto&& mi : mp) {
    if (0 <= mi.second && mi.second <= 9) {
      ans[mi.second]++;
      ans[0]--;
    }
  }

  for (int i = 0; i <= 9; ++i) {
    cout << ans[i] << endl;
  }
  
  return 0;
}
