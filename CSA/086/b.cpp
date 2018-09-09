#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

static const int MAX_N = 5 + 1;
static const int MAX_C = 1e5 + 1;

int64 dp[MAX_C][MAX_N];

int main()
{
  int N, C, S;
  cin >> N >> C >> S;
  vector< int > a(N);
  vector< int > b(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i] >> b[i];
  }

  int ans = C;
  for (int i = 0; i <= C; ++i) {
    for (int bit = 0; bit < (1 << N); ++bit) {
      // debug(bit);
      int sm = 0;
      int tmp = S * i;
      for (int j = 0; j < N; ++j) {
	if ((bit >> j) & 1) {
	  sm += a[j];
	}
      }
      if (S * (i - 1) - sm < 0) {
	tmp = 0;
	break;
      }
      tmp -= sm;
      for (int j = 0; j < N; ++j) {
	if ((bit >> j) & 1) {
	  tmp += b[j] * (S * i - a[j]);
	}
	if (bit == 6) {
	  debug(i);
	  debug(bit);
	  debug(tmp);
	}
	if (tmp >= C) {
	  ans = min(ans, i);
	  cout << ans << endl;
	return 0;
      }
      }
    }
  }
  
  

  return 0;
}

