// ------------------------------------
// Date:2018/ 3/10
// Problem:ABC 072 Together c.cpp
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
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  map< int, int > m;
  REP(i, N) {
    int a;
    cin >> a;
    if (a > 0) m[a - 1]++;
    m[a]++;
    m[a + 1]++;
  }

  int ans = 0;
  REP(mi, m.size()) {
    ans = max(ans, m[mi]);
  }
  cout << ans << endl;
  return 0;
}

