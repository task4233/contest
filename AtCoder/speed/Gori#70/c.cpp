#include <iostream>
#include <vector>

using namespace std;

typedef long long int64;

int main()
{
  int N;
  cin >> N;
  vector< int > T(N);
  vector< int > A(N);
  for (int i = 0; i < N; ++i) {
    cin >> T[i] >> A[i];
  }

  int64 t = 1ll;
  int64 a = 1ll;
  // cout << t << " " <<  a << endl;
  for (int i = 0; i < N; ++i) {
    int64 tmp = max((t + T[i] - 1) / T[i],
		    (a + A[i] - 1) / A[i]);

    a = tmp * A[i];
    t = tmp * T[i];
  }

  int64 ans = t + a;
  cout << ans << endl;
  
  return 0;
}
