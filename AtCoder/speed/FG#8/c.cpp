#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector< int > a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int ans = 0;
  int sm = 0;
  int cnt = 0;
  for (int i = a[i]; i <= a.back(); ++i) {
    cnt = upper_bound(a.begin(), a.end(), i + 1) - a.begin();
    cnt -= lower_bound(a.begin(), a.end(), i - 1) - a.begin();

    if (cnt > sm) {
      sm = cnt;
      ans = i;
    }
    cnt = 0;
  }
  cout << sm << endl;
  //cout << ans << endl;
  
  return 0;
}
