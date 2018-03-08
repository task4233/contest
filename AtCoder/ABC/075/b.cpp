// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 075 Minesweeper b.cpp
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
  int dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
  int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};
  int H, W;
  cin >> H >> W;
  string field[60];
  char ans[50][50];
  memset(ans, -1, sizeof(ans));
  REP(hi, H) cin >> field[hi];
  int cnt;
  REP(hi, H) {
    REP(wi, W) {
      cnt = 0;
      if (field[hi][wi] == '#') {
        ans[hi][wi] = '#';
        continue;
      }
      REP(dist, 8) {
        if (0 <= hi + dy[dist] && hi + dy[dist] <= H - 1 &&
            0 <= wi + dx[dist] && wi + dx[dist] <= W - 1 &&
            field[hi + dy[dist]][wi + dx[dist]] == '#') {
          ++cnt;
        }
      }
      ans[hi][wi] = cnt + '0';
    }
  }
  REP(hi, H) {
    REP(wi, W) {
      cout << ans[hi][wi];
    }
    cout << endl;
  }
  return 0;
}

