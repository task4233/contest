#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  B -= A;
  A -= A;

  for (int i = 0; i < N; ++i) {
    int64 small1 = C * i;
    int64 large1 = D * i;
    int64 small2 = C * (N - i - 1);
    int64 large2 = D * (N - i - 1);

    if (small1 - large2 <= B && B <= large1 - small2) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
