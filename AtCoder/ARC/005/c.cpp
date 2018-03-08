// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ARC 005 器物損壊！高橋君 c.cpp
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

int H, W;
int sx, sy;
int gx, gy;

char city[500][500];
// state[y][x][壊した回数]
bool state[500][500][3];

int vx[4] = {-1, 1, 0, 0};
int vy[4] = {0, 0, -1, 1};

void solve()
{
  // q(x, y, 壊した回数)
  queue< tuple< int, int, int > >  q;
  q.push(make_tuple(sx, sy, 0));
  state[sy][sx][0] = true;
  while(!q.empty()) {
    auto tmp = q.front();
    q.pop();
    int fromX, fromY, times;
    tie(fromX, fromY, times) = tmp;
    if (fromX == gx && fromY == gy) {
      break;
    }
    REP(i, 4) {
      int nextX, nextY;
      nextX = fromX + vx[i];
      nextY = fromY + vy[i];
      if (0 <= nextX && nextX < W &&
          0 <= nextY && nextY < H &&
          !state[nextY][nextX][times]) {
        if (city[nextY][nextX] == '#') {
          // 道がないとき
          if (times == 2) continue;
          state[nextY][nextX][times + 1] = true;
          q.push(make_tuple(nextX, nextY, times + 1));
        } else {
          // 道があるとき
          state[nextY][nextX][times] = true;
          q.push(make_tuple(nextX, nextY, times));
        }
      }
    }
  }
}

int main()
{
  memset(city, '#', sizeof(city));
  memset(state, false, sizeof(state));
  cin >> H >> W;
  REP(hi, H) {
    REP(wi, W) {
      cin >> city[hi][wi];
      if (city[hi][wi] == 's') {
        sx = wi;
        sy = hi;
      }
      if (city[hi][wi] == 'g') {
        gx = wi;
        gy = hi;
      }
    }
  }
  // 探索
  solve();
  bool ok = false;
  REP(ti, 3) {
    if (state[gy][gx][ti]) {
      ok = true;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}

