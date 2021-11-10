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

int ret = 0;

void dfs(int n,int w,int p)
{
  if (w > Maxw) return;
  ret = max(ret, p);
  if (n >= 5) return;
  dfs(n + 1, w, p);
  dfs(n + 1, w + Ws[n], p + Ps[n]);
}

int main()
{
  dfs(0,0,0);
  cout << ret << endl;
  return 0;
}

