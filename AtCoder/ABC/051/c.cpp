// ------------------------------------
// Date:2018/ 2/26
// Problem:ABC 051 BackAndForth c.cpp
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

#define MOD 1000000007

int main()
{
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  int mx,my;
  string output = "";
  mx = tx - sx;
  my = ty - sy;
  REP(h,2) {
    if (h == 1) {
      output += "D";
    }
    REP(i,mx+h) {
      output += "R";
    }
    REP(i,my+h) {
      output += "U";
    }
    if (h == 1) {
      output += "LU";
    }
    REP(i,mx+h) {
      output += "L";
    }
    REP(i,my+h) {
      output += "D";
    }
    if (h == 1) {
      output += "R";
    }
  }
  cout << output << endl;
  return 0;
}


