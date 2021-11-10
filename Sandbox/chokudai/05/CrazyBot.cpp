cexit
// ------------------------------------
// Date:2018/ 2/19
// Problem:SRM425 Div2 Level2 CrazyBot.cpp
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


bool grid[100][100] = {false};
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};
double prob[4];

class CrazyBot {
public:
  double getProbability(int n,int east,int west,int south,int north)
  {
    prob[0] = east / 100.0;
    prob[1] = west / 100.0;
    prob[2] = south/ 100.0;
    prob[3] = north/ 100.0;
    
    return dfs(50,50,n);
  }
  
  double dfs(int x,int y,int n)
  {
    if(grid[x][y]) return 0;
    if (n == 0) return 1;
    grid[x][y] = true;
    double res = 0.0;
    REP(i,4) {
      res += dfs(x+vx[i], y+vy[i], n-1)*prob[i];
    }
    grid[x][y] = false;
    return res;
  }
};

int main()
{
  CrazyBot c;
  int n,east,west,south,north;
  cin >> n >> east >> west >> south >> north;
  cout << c.getProbability(n,east,west,south,north) << endl;
  return 0;
}

