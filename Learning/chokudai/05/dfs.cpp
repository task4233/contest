// ------------------------------------
// Date:2018/ 2/19
// Problem:dfs : 深さ優先探索 dfs.cpp
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

// 深さ優先探索

int dfs(int now)
{
  if (nowの終了条件) {
    return nowの答え;
  }
  int res = -1;
  REP(i,次の状態の個数) {
    int next = i番目の次の状態;
    if (nextが条件を満たしている) ret = max(dfs(next), ret);
  }
  return ret;
}

int main()
{
  // 幅優先探索
  Queue<T> q;
  q.push(初期状態);
  while(!q.empty()) {
    T now = q.front();
    q.pop();
    状態nowに対する処理
    REP(i,次の状態の個数) {
      T next = i番目の次の状態;
      if (nextが訪問済みかの判定) {
        q.push(next);
      }
    }
  }
  return 0;
}

