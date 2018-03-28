// ------------------------------------
// Date:2018/ 3/13
// Problem:back and forth a.cpp
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

  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  int h = tx - sx;
  int w = ty - sy;

  REP(i, h) {
    cout << "R";
  }
  REP(i, w) {
    cout << "U";
  }
  REP(i, h) {
    cout << "L";
  }
  REP(i, w) {
    cout << "D";
  }
  cout << "D";
  REP(i, h + 1) {
    cout << "R";
  }
  REP(i, w + 1) {
    cout << "U";
  }
  cout << "LU";
  REP(i, h + 1) {
    cout << "L";
  }
  REP(i, w + 1) {
    cout << "D";
  }
  cout << "R" << endl;
  return 0;
}

