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
char B[50][50];

vector<vector<int>> memo(50,vector<int>(50,-1));

int dfs(int hi,int wi) {
  if (B[hi][wi] == '#') return 0;
  if (B[hi][wi] != -1) return memo[hi][wi];
  int res = 1e9;
  if (hi != 0)   res = min(dfs(hi-1,wi),res);
  if (wi != 0)   res = min(dfs(hi,wi-1),res);
  if (hi != H-1) res = min(dfs(hi+1,wi),res);
  if (wi != W-1) res = min(dfs(hi,wi+1),res);
  return memo[hi][wi] = res;
}

int main()
{
  int bCnt,wCnt,routeCnt;
  bCnt = wCnt = routeCnt = 0;
  cin >> H >> W;
  REP(hi,H) {
    REP(wi,W) {
      cin >> B[hi][wi];
      if (B[hi][wi] == '.') ++wCnt;
      else ++bCnt;
    }
  }
  routeCnt = dfs(0,0);
  REP(i,50) {
    REP(j,50) {
      cout << memo[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}

