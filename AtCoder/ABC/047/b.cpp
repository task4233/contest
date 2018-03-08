// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 047 Snuke'sColoring2 b.cpp
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
  int W,H,N,x,y,a,res = 0;
  cin >> W >> H >> N;
  
  vector<vector<int>> Ans(H, vector<int>(W,0));
  REP(i,N) {
    cin >> x >> y >> a;
    if (a == 1) {
      REP(j,H) {
        REP(k,x) {
          ++Ans[j][k];
        }
      }
    } else if (a == 2) {
      REP(j,H) {
        FOR(k,x,W) {
          ++Ans[j][k];
        }
      }
    } else if (a == 3) {
      REP(j,y) {
        REP(k,W) {
          ++Ans[j][k];
        }
      }
    } else if (a == 4) {
      FOR(j,y,H) {
        REP(k,W) {
          ++Ans[j][k];
        }
      }
    }
  }
  REP(l,H) {
    REP(m,W) {
      if (Ans[l][m] == 0) ++res;
    }
  }
  cout << res << endl;
  return 0;
}

