#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int N, C, S;
  cin >> N >> C >> S;
  vector< int > a(N);
  vector< int > b(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i] >> b[i];
  }

  vector< int > p(N);
  iota(p.begin(), p.end(), 0);

  int64 ans = (C + S - 1) / S;

  for (int bit = 1; bit < (1 << N); ++bit) {
    vector< int > buy;
    // bit-all search
    for (int i = 0; i < N; ++i) {
      if ((bit >> i) & 1) buy.push_back(i);
    }
    
    do {
      int64 cur = 0, tmp = 0, delta = S;
      
      for (int j = 0; j < (int)buy.size(); ++j) {
	// v representing the number of cookies
	int64 v = max(0ll, ((a[buy[j]] - cur) + delta - 1) / delta);
	tmp += v;
	cur += v * delta - a[buy[j]];
	delta += b[buy[j]];
      }

      // DON'T FORGET
      int64 v = max(0ll, ((C - cur) + delta - 1) / delta);
      tmp += v;

      ans = min(ans, tmp);
    } while (next_permutation(buy.begin(), buy.end()));
  }

  cout << ans << endl;
  
  return 0;
}
