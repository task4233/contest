// ------------------------------------
// Date:2018/ 2/27
// Problem:ATC 001 深さ優先探索 a.cpp
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

using ll = long long;

#define MOD 1000000007

int H,W;
char city[500][500];
bool state[500][500];
int vx[4] = {1,-1, 0, 0};
int vy[4] = {0, 0, 1,-1};

bool solve(pair<int, int> pos)
{
  queue< pair< int, int > > q;
  q.push(pos);
  while (!q.empty()) {
    auto tmp = q.front();
    q.pop();
    int x, y;
    tie(x, y) = tmp;
    if (city[y][x] == 'g') return true;
    REP(i, 4) {
      int nextX = x + vx[i];
      int nextY = y + vy[i];
      
      if (0 <= nextX && nextX < W &&
          0 <= nextY && nextY < H &&
          city[nextY][nextX] != '#' &&
          state[nextY][nextX] == false) {
        state[nextY][nextX] = true;
        //city[nextY][nextX] = 'X';
        q.push({nextX, nextY});
      }
    }
  }
  return false;
}

int main()
{
  pair<int, int> pos;
  memset(city, 0, sizeof(city));
  memset(state, false, sizeof(state));
  cin >> H >> W;
  REP(hi, H) {
    REP(wi, W) {
      cin >> city[hi][wi];
      if (city[hi][wi] == 's') {
        pos.first = wi;
        pos.second = hi;
        state[hi][wi] = true;
      }
    }
  }
  cout << (solve(pos) ? "Yes" : "No") << endl;
  return 0;
}

