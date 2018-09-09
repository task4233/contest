#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main()
{
  int N, K;
  cin >> N >> K;
  vector< int64 > x(N);
  vector< int64 > y(N);
  for (int i = 0; i < N; ++i) {
    cin >> x[i] >> y[i];
  }

  vector< int64 > sorted_x(x);
  vector< int64 > sorted_y(y);
  sort(sorted_x.begin(), sorted_x.end());
  sort(sorted_y.begin(), sorted_y.end());

  int64 ans = (sorted_y.back() - sorted_y[0]) * (sorted_x.back() - sorted_x[0]);

  // cout << ans << endl;
  
  for (int hi = 0; hi < N; ++hi) {
    for (int wi = 0; wi < N; ++wi) {
      for (int hj = hi; hj < N; ++hj) {
	for (int wj = wi; wj < N; ++wj) {

	  int sm = 0;
	  for (int i = 0; i < N; ++i) {
	    if (sorted_y[hi] <= y[i] && y[i] <= sorted_y[hj] &&
		sorted_x[wi] <= x[i] && x[i] <= sorted_x[wj]) {
	      sm++;
	    }
	  }

	  if (sm >= K) {
	    ans = min(ans, (sorted_y[hj] - sorted_y[hi]) * (sorted_x[wj] - sorted_x[wi]));
	  }
	  
	}
      }
    }
  }

  cout << ans << endl;

  
  
  return 0;
}
