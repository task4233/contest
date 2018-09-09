#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector< int > p(N);
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if (p[i] == i + 1) {
      ans++;
      if (i == N - 1) {
	swap(p[i], p[i - 1]);
      } else if (p[i + 1] == i + 1) {
	swap(p[i], p[i - 1]);
      } else {
	swap(p[i], p[i + 1]);
      }
    }
  }
  cout << ans << endl;

  
  return 0;
}
