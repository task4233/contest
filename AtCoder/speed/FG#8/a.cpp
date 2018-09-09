#include <bits/stdc++.h>

using namespace std;

int main()
{
  int X, t;
  cin >> X >> t;
  int ans = max(0, X - t);
  cout << ans << endl;
  return 0;
}
