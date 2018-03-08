// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 046 AtCoDeerAndPaintCans a.cpp
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

using ll = long long;

#define MOD 1000000007

int main()
{
  int a,b,c,ans;
  cin >> a >> b >> c;
  if (a == b && b == c) {
    ans = 1;
  } else if (a != b && b != c && a!=c) {
    ans = 3;
  } else {
    ans = 2;
  }
  cout << ans << endl;
  return 0;
}

