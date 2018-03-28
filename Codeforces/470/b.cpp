// ------------------------------------
// Date:2018/ 3/11
// Problem:Codeforces . . b.cpp
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

// static const int MOD = 1000000007;
static const int MAX_N = 1010101;

bool prime[MAX_N];

int x2;

bool flag = false;
// (x0, x1)
bool solve(int x0, int x1, int cnt)
{
  debug(x0 + 1);
  debug(x1 + 1);
  debug(cnt);
  if (cnt == 1) {
    FOR (i, (x0 < 4 ? 4: x0), x1) {
      if (!prime[i + 1]) {
	cout << i + 1 << endl;
	flag = true;
	return true;
      }
    }
  }
  FOR(i, x0, x1) {
    if (prime[i + 1]) continue;
    FOR(j, 2, i) {
      if (prime[j + 1]) {
	if (solve(j, i, cnt + 1)) {
	  return true;
	}
      }
    }
  }
}

void init()
{
  memset(prime, true, sizeof(prime));
  FOR(i, 2, sqrt(MAX_N)) {
    for(int j = 0; i * (j + 2) < MAX_N; ++j) {
      prime[i * (j + 2)] = false;
    }
  }
  prime[0] = prime[1] = false;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  init();

  cin >> x2;
  FOR(i, 3, x2) {
    if (!prime[i + 1]) continue;
    if (solve(i, x2 - 1, 0)) {
      if (flag) break;
    }
  }
  return 0;
}

