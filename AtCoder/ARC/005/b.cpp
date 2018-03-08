// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ARC 005 P-CASカードと高橋君 b.cpp
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
  int x, y;
  string W;
  string c[9];
  pair< int, int > v;
  
  cin >> x >> y;
  --x;
  --y;
  cin >> W;
  REP(hi, 9) {
    cin >> c[hi];
  }
  if (W == "R")       v = { 1, 0};
  else if (W ==  "L") v = {-1, 0};
  else if (W ==  "U") v = { 0,-1};
  else if (W ==  "D") v = { 0, 1};
  else if (W == "RU") v = { 1,-1};
  else if (W == "RD") v = { 1, 1};
  else if (W == "LU") v = {-1,-1};
  else if (W == "LD") v = {-1, 1};
  
  REP(i, 4) {
    cout << c[y][x];
    x += v.first;
    y += v.second;
    if (0 > x || 8 < x) {
      x += x>8 ? -2: 2;
      v.first = -1 * v.first;
    }
    if (0 > y || 8 < y) {
      y += y>8 ? -2: 2;
      v.second = -1 * v.second;
    }
  }
  cout << endl;
  return 0;
}
