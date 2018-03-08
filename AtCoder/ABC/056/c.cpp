// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 056 GoHome c.cpp
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

int dx[3] = {-1, 0, 1};

int X;

int main()
{
  cin >> X;
  FOR (n, 1, 1e9) {
    if ((n + 1) * n >= 2 * X) {
      cout << n << endl;
      return 0;
    }
  }
  return 0;
}

