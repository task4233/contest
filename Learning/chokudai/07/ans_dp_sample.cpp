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
int dfs(int nowX, int nowY)
{
  if (nowX  > X || nowY  > Y) return 0;
  if (nowX == X && nowY == Y) return 1;
  if (dp[nowX][nowY] != 0) return dp[nowX][nowY];
  return dp[nowX][nowY] = dfs(nowX + 1, nowY) + dfs(nowX, nowY + 1);
}

int main()
{
  cin >> X >> Y;
  vector<int> elem(Y+1,0);
  REP(xi,X+1) dp.emplace_back(elem);
  cout << dfs(0,0) << endl;
  return 0;
}

