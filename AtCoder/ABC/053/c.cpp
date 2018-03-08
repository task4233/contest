// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 053 X:YetAnotherDieGame c.cpp
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
  ll x;
  cin >> x;
  cout << (x / 11) * 2 + ((x % 11 ) > 6 ? 2 : (x % 11) > 0 ? 1 : 0) << endl;
  return 0;
}

