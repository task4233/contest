// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 007 幅優先探索 c.cpp
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

int R, C;
pair< int, int > start;
int gx, gy;

char maze[50][50];
bool state[50][50];

int memo[50][50];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solve()
{
  queue< pair< int, int > > q;
  q.push(start);
  state[start.first][start.second] = true;
  while (!q.empty()) {
    int fromX, fromY;
    auto tmp = q.front();
    q.pop();
    tie(fromX, fromY) = tmp;
    if (fromX == gx && fromY == gy) return memo[fromY][fromX];
    REP(dist, 4) {
      int nextX, nextY;
      nextX = fromX + dx[dist];
      nextY = fromY + dy[dist];
      if (0 <= nextX && nextX < C &&
          0 <= nextY && nextY < R &&
          !state[nextY][nextX]    &&
          maze[nextY][nextX] != '#') {
        state[nextY][nextX] = true;
        memo[nextY][nextX] = memo[fromY][fromX] + 1;
        q.push({nextX, nextY});
      }
    }
  }
  return 0;
}

int main()
{
  int x, y;
  memset(maze, '#', sizeof(maze));
  memset(state, false, sizeof(state));
  memset(memo, 0, sizeof(memo));
  cin >> R >> C;
  cin >> y >> x;
  start.first = --x;
  start.second = --y;
  cin >> y >> x;
  gx = --x;
  gy = --y;
  
  REP(hi, R) {
    REP(wi, C) {
      cin >> maze[hi][wi];
    }
  }
  
  cout << solve() << endl;
  return 0;
}

