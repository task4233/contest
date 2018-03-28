// ------------------------------------
// Date:2018/ 3/13
// Problem:rgb cards . c.cpp
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

  int r, g, b;
  cin >> r >> g >> b;

  bool ok = false;
  if ((g * 10 + b) % 4 == 0)  {
    ok = true;
  } 

  cout << (ok ? "YES" : "NO") << endl;
  
  return 0;
}

