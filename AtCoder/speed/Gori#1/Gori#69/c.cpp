#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main()
{
  string S;
  cin >> S;
  int N = S.size();
  
  int64 ans = 0ll, tmp;
  int last = 0;
  for (int bit = 0; bit < (1 << (N - 1)); ++bit) {
    last = 0;
    for (int i = 0; i < N - 1; ++i) {
      if ((bit >> i) & 1) {
        ans += (int64)stoll(S.substr(last, i - last + 1).c_str());
	last = i + 1;
      }
    }
    ans += (int64)stoll(S.substr(last, N - last).c_str());
  }

  cout << ans << endl;
  return 0;
}
