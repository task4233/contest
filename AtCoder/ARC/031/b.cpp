// ------------------------------------
// Date:2018/ 2/27
// Problem:ARC 031 埋め立て b.cpp
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

const int H = 10;
const int W = 10;

char mapData[H][W];
// state[y][x][全探索で固定y][全探索で固定x]
bool state[H][W][H][W];

int dx[4] = { 1,-1, 0, 0};
int dy[4] = { 0, 0, 1,-1};

bool solve(int x, int y)
{
  bool ans = true;
  queue< pair<int, int> > q;
  q.push({x, y});
  
  state[y][x][y][x] = true;
  
  while(!q.empty()) {
    auto tmp = q.front();
    q.pop();
    int mx, my;
    tie(mx, my) = tmp;
    REP(dist, 4) {
      int nextX = mx + dx[dist];
      int nextY = my + dy[dist];
      
      if (mapData[nextY][nextX] == 'x') continue;
      if (0 <= nextX && nextX < 10 &&
          0 <= nextY && nextY < 10 &&
          state[nextY][nextX][y][x] == false &&
          mapData[nextY][nextX] == 'o') {
        state[nextY][nextX][y][x] = true;
        q.push({nextX, nextY});
      }
    }
  }
  REP(hi, H) {
    REP(wi, W) {
      if (mapData[hi][wi] == 'o' && !state[hi][wi][y][x]) {
        ans = false;
      }
    }
  }
  return ans;
}

int main()
{
  memset(state, false, sizeof(state));
  REP(hi, H) {
    REP(wi, W) {
      cin >> mapData[hi][wi];
    }
  }
  
  bool ok = false;
  REP(hi, H) {
    REP(wi, W) {
      if (mapData[hi][wi] == 'o') continue;
      if (solve(wi, hi)) {
        ok = true;
      }
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}

