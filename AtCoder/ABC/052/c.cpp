// ------------------------------------
// Date:2018/ 2/28
// Problem:ABC 053 FactorsOfFactorial c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

static const int MOD = 1000000007;

int N;
bool prime[1000];

int main()
{
  cin >> N;
  memset(prime, true, sizeof(prime));
  // エラトステネス
  FOR(i, 2, sqrt(N)) {
    if (prime[i]) {
      for (int j = 0; i * (j + 2) < N; ++j) {
        prime[i * (j + 2)] = false;
      }
    }
  }
  int cnt = 1;
  FOR(i, 1, N) {
    if (prime[i]) {
      if (N % i == 0) {
        ++cnt;
        cnt %= MOD;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}

