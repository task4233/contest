#include <iostream>

using namespace std;

typedef long long int64;

int main()
{
  int N, K;
  cin >> N >> K;

  int64 ans = K;
  for (int i = 0; i < N - 1; ++i)
    ans *= K - 1;

  cout << ans << endl;
  
}
