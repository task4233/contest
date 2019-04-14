#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

int main()
{
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 0; i < S.size() - 1; ++i) {
    if (S[i + 1] != S[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
