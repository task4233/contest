// ------------------------------------
// Date:2018/ 3/11
// Problem:ABC 090 . c.cpp
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
const int MAX_N = 1e9 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, M;
  cin >> N >> M;

  ll ans;
  if (N >= 2 and M >= 2) {
    ans = (N - 2) * (M - 2);
  } else {
    if (N < 2 and M < 2) {
      ans = 1;
    } else if (N >= 2 and M < 2) {
      ans = N - 2;
    } else {
      ans = M - 2;
    }
  }

  cout << ans << endl;
  return 0;
}

