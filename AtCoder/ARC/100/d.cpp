#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
static const int64 LINF = 1LL << 30;
#define debug(x) cerr << #x << ":" << x<< endl

int main()
{
  int N;
  cin >> N;
  vector< int64 > a(N);
  vector< int64 > sm(N + 1, 0LL);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    sm[i] = a[i];
  }
  for (int i = 0; i < N; ++i) {
    sm[i + 1] += sm[i];
    // cout << sm[i] << endl;
    debug(sm[i + 1]);
  }

  int64 ans = LINF;
  for (int i = 1; i < N; ++i) {
    int64 tmp1 = LINF;
    int div1 = 0;
    int ub = 0;
    for (int lb = 0; lb < i; ++lb) {
      while (ub < i && abs(sm[ub] - (sm[N] - sm[ub + 1])) < tmp1) {
	ub++;
      }
      if (abs(sm[ub] - (sm[N] - sm[ub + 1])) < tmp1) {
	div1 = ub;
      }
      if (ub <= lb) ub = lb + 1;
    }

    int64 tmp2 = LINF;
    int div2 = i;
    ub = i;
    for (int lb = i; lb < N; ++lb) {
      while (ub < N && abs(sm[ub] - (sm[N] - sm[ub + 1])) < tmp2) {
	ub++;
      }
      if (abs(sm[ub] - (sm[N] - sm[ub + 1])) < tmp2) {
	div2 = ub;
      }
      if (ub <= lb) ub = lb + 1;
    }

    int64 sm1 = sm[div1];
    int64 sm2 = sm[i] - sm[div1 + 1];
    int64 sm3 = sm[div2];
    int64 sm4 = sm[N] - sm[div2 + 1];
    debug(i);
    debug(div1);
    debug(div2);
    debug(sm1);
    debug(sm2);
    debug(sm3);
    debug(sm4);
    
    
    int64 tmp = max(max(sm1, sm2), max(sm3, sm4)) - min(min(sm1, sm2), min(sm3, sm4));
    cout << tmp << endl;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  
  return 0;
}

