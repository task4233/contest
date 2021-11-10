// ------------------------------------
// Date:2018/ 2/21
// Problem:. . . dp_sample.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

// 横の数X / 縦の数Y
int X,Y;
vector<vector<int>> dp;

int dfs(int x,int y)
{
  if (x  > X || y  > Y) return 0;
  if (x == X && y == Y) return 1;
  if (dp[x][y] != 0) return dp[x][y];
  return dp[x][y] = dfs(x+1, y) + dfs(x,y+1);
}

int main()
{
  cin >> X >>  Y;
  vector<int> elem(Y+1,0);
  REP(xi,X+1) dp.emplace_back(elem);
  dp[0][0] = 1;
  REP(xi,X+1) {
    REP(yi,Y+1) {
      if (xi != 0) dp[xi][yi] += dp[xi-1][yi];
      if (yi != 0) dp[xi][yi] += dp[xi][yi-1];
    }
  }
  cout << dp[X][Y] << endl;
  return 0;
}

