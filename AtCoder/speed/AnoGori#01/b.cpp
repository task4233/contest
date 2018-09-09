#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 nCr[575][575];

int64 f(int64 n, int64 r)
{
  if (r == 0 || n == r) return 1;
  if (nCr[n][r] >= 0) return nCr[n][r];
  return nCr[n][r] = f(n - 1, r - 1) + f(n - 1, r);
}

int main()
{
  memset(nCr, -1, sizeof(nCr));;
  int N, P;
  cin >> N >> P;
 
  vector< int > a(N);
  int o = 0;
  int e = 0;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      e++;
    } else {
      o++;
    }
  }
  
  int64 ans = 0ll;
  for (int i = 0; i <= o; ++i) {
    if (i % 2 == P) {
      ans += f(o, i);
    }
  }
  ans <<= e;
  
  cout << ans << endl;
  
  return 0;
}
