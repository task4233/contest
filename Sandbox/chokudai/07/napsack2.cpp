// ------------------------------------
// Date:2018/ 2/ 3
// Problem:. . . napsack.cpp
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

const int Ws[5] = {3,4,1,2,3};
const int Ps[5] = {2,3,2,3,6};
const int Maxw = 10;

int dp[6][Maxw+1];

int ret = 0;

int dfs(int n,int w)
{
  if (w > Maxw) return -1;
  if (n >= 5) return 0;
  return dp[n][w] = max(dfs(n+1,w),dfs(n+1,w+Ws[n])+Ps[n]);
}


int main()
{
  cout << dfs(0,0) << endl;
  return 0;
}

