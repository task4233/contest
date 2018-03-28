// ------------------------------------
// Date:2018/ 3/11
// Problem:codeforces . . a.cpp
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

string field[500];

int R, C;

bool search(int ri, int ci)
{
   switch(field[ri][ci]) {
    case 'W':
      return false;
    case '.':
      field[ri][ci] = 'D';
      break;
    }
   return true;
}

bool sets(int ri, int ci)
{
  // up
  if (ri > 0) {
    if (!search(ri - 1, ci)) return false;
  }
  // left
  if (ci > 0) {
    if (!search(ri, ci - 1)) return false;
  }
  // down
  if (ri < R - 1) {
    if (!search(ri + 1, ci)) return false;
  }
  // right
  if (ci < C - 1) {
    if (!search(ri, ci + 1)) return false;
  }
  return true;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> R >> C;
  REP(ri, R) {
    cin >> field[ri];
  }

  bool ok = true;
  REP(ri, R) {
    REP(ci, C) {
      if (field[ri][ci] == 'S') {
	if (!sets(ri, ci)) ok = false;
      }
    }
  }

  if (!ok) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    REP(ri, R) {
      cout << field[ri] << endl;
    }
  } 
  return 0;
}

