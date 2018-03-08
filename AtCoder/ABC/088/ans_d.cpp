// ------------------------------------
// Date:2018/ 2/18
// Problem:ABC 088 _ d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int H, W;
// Board[H][W];
string B[50];
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};

vector<vector<int>> memo(50,vector<int>(50,0));
bool state[50][50] = {false};

int solve()
{
  // queueXとqueueYのpair
  queue<pair<int,int>> q;
  q.push({0,0});
  state[0][0] = true;
  //memo[0][0] = 0;
  
  while (!q.empty()) {
    auto tmp = q.front();
    q.pop();
    int x,y;
    tie(x,y) = tmp;
    if (x == W-1 && y == H-1) return memo[y][x];
    REP(i,4) {
      int nextX = x + vx[i];
      int nextY = y + vy[i];
      
      if (0 <= nextX && nextX < W
      &&  0 <= nextY && nextY < H
      //&& memo[nextY][nextX] == -1
      &&  state[nextY][nextX] == false
      &&  B[nextY][nextX] == '.') {
        state[nextY][nextX] = true;
        memo[nextY][nextX] = memo[y][x] + 1;
        q.push({nextX,nextY});
      }
    }
  }
  return 0;
}


int main()
{
  int cnt = 0;
  cin >> H >> W;
  REP(hi,H) {
    cin >> B[hi];
    REP(si,B[hi].size()) if (B[hi][si] == '#') ++cnt;
  }
  
  int ans, res = solve();
  if (res == 0) {
    ans = -1;
  } else {
    //ans = H*W - (#の数) - (すぬけ君が通るマスの数);
    ans = H*W - cnt - res - 1;
  }
  cout << ans << endl;
  return 0;
}

