#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef long double double32;

int main()
{
  double32 Q, H, S, D;
  int64 N;
  cin >> Q >> H >> S >> D >> N;

  double32 mq = Q * 4.0;
  double32 mh = H * 2.0;
  double32 ms = S * 1.0;
  double32 md = D / 2.0;

  double32 m = min(mq, min(mh, ms));
  
  int64 ans;
  if (N % 2 == 1) {
    if (m <= md) ans = N * m;
    else ans = (int64)(N / 2) * md * 2 + m;
  } else {
    if (m <= md) ans = N * m;
    else ans = N * md;
  }

  cout << ans << endl;
  
  return 0;
}
