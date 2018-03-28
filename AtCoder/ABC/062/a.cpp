// ------------------------------------
// Date:2018/ 3/ 9
// Problem:ABC 062 Grouping a.cpp
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

  int x, y;
  cin >> x >> y;
  int a[7] = {1, 3, 5, 7, 8, 10, 12};
  int b[4] = {4, 6, 9, 11};

  bool ok1 = false;
  bool ok2 = false;
  REP(i, 7) {
    if (a[i] == x) ok1 = true;
    if (a[i] == y) ok2 = true;
  }
  if (ok1 ^ ok2) {
    cout << "No" << endl;
    return 0;
  }
  if (ok1 && ok2) {
    cout << "Yes" << endl;
    return 0;
  }

  REP(i, 4) {
    if (b[i] == x) ok1 = true;
    if (b[i] == y) ok2 = true;
  }
  if (ok1 ^ ok2) {
    cout << "No" << endl;
    return 0;
  }
  if (ok1 && ok2) {
    cout << "Yes" << endl;
    return 0;
  }

  if (x == 2 && y == 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

