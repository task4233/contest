// ------------------------------------
// Date:2018/ 3/15
// Problem:Discovery '16 正方形のチップ a.cpp
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

  int R, C;
  cin >> R >> C;
  int ans = 0;
  for (int xi = C; xi < R; xi += C) {
    for (int yi = C; yi < R; yi += C) {
      if (sqrt(xi * xi + yi * yi) > R) break;
      ans++;
    }
  }
  ans *= 4;
  cout << ans << endl;
  
  return 0;
}

