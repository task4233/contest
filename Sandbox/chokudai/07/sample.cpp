// ------------------------------------
// Date:2018/ 2/ 3
// Problem:p174 . . sample.cpp
//
// ------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

int dfs(int nowh,int noww)
{
  int h,w;
  h = 5;
  w = 4;
  if (nowh>h || noww>w) return 0;
  if (nowh==h && noww==w) return 1;
  return dfs(nowh+1, noww) + dfs(nowh,noww+1);
}

const int h=5, w=4;
int dp[h+1][w+1];

int memoDfs(int nowh,int noww)
{
  if (nowh>h || noww>w) return 0;
  if (nowh==h && noww==w) return 1;
  if (dp[nowh][noww]!=0) return dp[nowh][noww];
  return dp[nowh][noww] = memoDfs(nowh+1, noww) + memoDfs(nowh,noww+1);  
}

void calc()
{
  dp[0][0] = 1;
  REP(i,h+1) {
    REP(j,w+1) {
      if (i!=0) dp[i][j] += dp[i-1][j];
      if (j!=0) dp[i][j] += dp[i][j-1];
    }
  }
}

int main()
{
  cout << dfs(0,0) << endl;
  cout << memoDfs(0,0) << endl;
  //cout << calc() << endl;
  return 0;
}

