#include <bits/stdc++.h>
using namespace std;

string s;
int x, y;
int main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> s >> x >> y;
  bitset< 2 * 8000 > dpx, dpy;
  int cnt = 0, first = 0, N = s.size();
  while (s[first++] == 'F');
  dpx[8000 + --first] = dpy[8000] = 1;

  bool isX = true;
  for (int i = first; i < N; ++i) {
    if (s[i] == 'F') cnt++;
    if (s[i] == 'T' || i == N - 1) {
      if (isX) dpx = (dpx << cnt) | (dpx >> cnt);
      else     dpy = (dpy >> cnt) | (dpy << cnt);
      isX = !isX;
      cnt = 0;
    }
  }

  cout << (dpx[x + 8000] && dpy[y + 8000] ? "Yes" : "No") << endl;
  return 0;
}
