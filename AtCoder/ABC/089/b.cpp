// ------------------------------------
// Date:2018/ 3/ 4
// Problem:ABC 089 _ b.cpp
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
  char ch;
  int cnt = 0;
  bool p, w, g, y;
  p = w = g = y = false;
  REP(i, N) {
    cin >> ch;
    switch (ch) {
      case 'P':
        p = true;
        break;
      case 'W':
        w = true;
        break;
      case 'G':
        g = true;
        break;
      case 'Y':
        y = true;
        break;
    }
  }
  if (p) ++cnt;
  if (w) ++cnt;
  if (g) ++cnt;
  if (y) ++cnt;
  
  if (cnt == 3) {
    cout << "Three" << endl;
  } else if (cnt == 4) {
    cout << "Four" << endl;
  }
  return 0;
}

