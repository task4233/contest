#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'g') {
      cnt++;
    } else {
      if (cnt < 1) {
	ans--;
      } else {
	cnt--;
      }
    }
  }
  ans += cnt / 2;

  cout << ans << endl;
  return 0;
}
