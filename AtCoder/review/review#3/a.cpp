#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int MOD = 1e9 + 7;

struct Eratosthenes {
  vector< bool > prime;
  Eratosthenes(int _size) {
    init(_size);
  }

  void init(int n) {
    prime.resize(n + 1);
    for(int i = 0; i < prime.size(); ++i) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i = 2; i < sqrt(n); i++) {
      if (prime[i]) {
        for (int j = 0; i * (j + 2) < n; j++) {
	  prime[i * (j + 2)] = false;
	}
      }
    }
  }
};

int main()
{
  int N;
  cin >> N;

  Eratosthenes e(N + 1);
  
  int64 ans = 1ll;
  for (int i = 2; i <= N; ++i) {
    if (!e.prime[i]) continue;
    int64 sm = 1ll;
    
    for (int j = 2; j <= N; ++j) {
      int64 tmp = j;
      while (tmp % i == 0) {
	sm++;
	tmp /= i;
      }
    }
    (ans *= sm) %= MOD;
  }

  cout << ans << endl;
  
  return 0;
}
