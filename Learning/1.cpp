// ------------------------------------
// Date:2018/ 3/14
// Problem:fourier samp _ 1.cpp
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

int f[3] = {1, 1, 1};
int g[3] = {1, -1, -1};
int h[3] = {1, 1, -1};

int F[3];

int main()
{
  REP(i, 3) {
    cin >> F[i];
  }

  int a, b, c;
  bool ok = false;
  REP(ai, F[0]) {
    REP(bi, F[0]) {
      a = ai;
      b = bi;
      c = (F[0] - f[0] * a - g[0] * b) / h[0];

      if (c < 0) continue;
      if (F[0] == f[0] * a + g[0] * b + h[0] * c and
	  F[1] == f[1] * a + g[1] * b + h[1] * c and
	  F[2] == f[2] * a + g[2] * b + h[2] * c)
	ok = true;
    }
    if (ok) break;
  }

  printf("a = %d, b = %d, c = %d\n", a, b, c);
  
  return 0;
}

