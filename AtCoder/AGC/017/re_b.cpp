#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, A, B, C, D, dist;
  cin >> N >> A >> B >> C >> D;

  dist = B - A;
  
  int64 l_a, r_a, l_b, r_b;
  for (int i = 0; i < N; ++i) {
    l_a = C * i;
    r_b = D * i;
    l_b = C * (N - i - 1);
    r_a = D * (N - i - 1);

    if (l_a - r_a <= dist && dist <= r_b - l_b) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  
  return 0;
}
