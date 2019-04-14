#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

int main()
{
  int64 a, b, x;
  cin >> a >> b >> x;
  if (a == 0) {
    cout << b / x + 1 <<  endl;
    return 0;
  }
  int64 ans = (b) / x - (a - 1) / x;
  cout << ans << endl;
  return 0;
}
