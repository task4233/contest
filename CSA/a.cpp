#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int N, P, T;
  cin >> N >> P >> T;
  P--;

  int tmp = 0;
  for (int i = 0; i < T; ++i) {
    switch(i % 9) {
    case 4:
    case 6:
    case 7:
    case 8:
      tmp++;
      break;
    case 5:
      tmp--;
      break;
    default:
      break;
    }
  }

  int ans = -1;
  if (P >= tmp) {
    ans = P - tmp + 1;
  }
  cout << ans << endl;
  
  return 0;
}
