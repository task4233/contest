// ------------------------------------
// Date:2018/ 3/ 2
// Problem:JOI '07 カードゲーム c.cpp
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
  bool t[101];
  bool h[101];
  int n, tmp;
  scanf("%d", &n);
  memset(h, true, n);
  while(scanf("%d", &tmp) != EOF) {
    --tmp;
    t[tmp] = true;
  };
  REP(i, n) {
    if (t[i]) h[i] = false;
  }
  // turn(taro:false / hanako:true)
  bool turn = false;
  int cnt, field = 0;
  REP(i, 2*n) {
    cnt = 0;
    if (!turn) {
      turn = !turn;
      REP(j, n) {
        if (t[j] && j > field) {
          t[j] = false;
          field = j;
          break;
        }
        if (j == n-1) {
          field = -1;
        }
      }
      REP(j, n) {
        if (t[j]) ++cnt;
      }
      if (cnt == 0) {
        cnt = 0;
        REP(j, n) {
          if (h[j]) ++cnt;
        }
        printf("%d\n0\n", cnt);
        return 0;
      }
    } else {
      turn = !turn;
      REP(j, n) {
        if (h[j] && j > field) {
          h[j] = false;
          field = j;
          break;
        }
        if (j == n-1) {
          field = -1;
        }
      }
      REP(j, n) {
        if (h[j]) ++cnt;
      }
      if (cnt == 0) {
        cnt = 0;
        REP(j, n) {
          if (t[j]) ++cnt;
        }
        printf("%d\n0\n", cnt);
        return 0;
      }
    }
  }
  return 0;
}

