#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

int main()
{
  int lw = 0, uw, lh = 0, uh, N;
  cin >> uw >> uh >> N;
  for (int i = 0; i < N; ++i) {
    int x, y, a;
    cin >> x >> y >> a;
    switch (a) {
    case 1:
      lw = max(lw, x);
      break;
    case 2:
      uw = min(uw, x);
      break;
    case 3:
      lh = max(lh, y);
      break;
    case 4:
      uh = min(uh, y);
      break;
    }
  }

  int H = uh - lh;
  int W = uw - lw;
  int ans = H * W;
  if (H < 0 || W < 0) ans = 0;
  cout << ans << endl;
  return 0;
}
