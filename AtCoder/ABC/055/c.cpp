// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 055 SccPuzzle c.cpp
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

int main()
{
  // S1個とc2個で、Sがなくなるまで作る
  // C4個で可能な限り作る
  // N:S / M:c
  ll N, M;
  cin >> N >> M;
  ll ans = 0;
  if (M - N*2 >= 0) {
    ans = N;
    M -= N * 2;
    ans += M/4;
  } else {
    ans = M / 2;
  }
  cout << ans << endl;
  return 0;
}

