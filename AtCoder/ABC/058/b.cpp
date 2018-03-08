// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 058 ∵∴∵ b.cpp
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
  string O, E;
  string ans = "";
  cin >> O >> E;
  int o,e;
  o = O.length();
  e = E.length();
  REP(i, e) {
    ans += O[i];
    ans += E[i];
  }
  if (o > e) ans += O[o-1];
  cout << ans << endl;
  return 0;
}

