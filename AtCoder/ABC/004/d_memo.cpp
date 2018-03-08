// ------------------------------------
// Date:2018/ 2/15
// Problem:ABC 004 マーブル d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define debug(x) cerr << #x << ": " << x << '\n';
#define MOD 1000000007

int R,G,B;
//  memo[lookAt][leftSum]
int memo[1000][1000];

// 移動距離を返す
inline int cost(int lookAt,int leftSum)
{
  if (leftSum >= G+B) return abs(400-lookAt);
  else if (leftSum >= B) return abs(500-lookAt);
  else return abs(600-lookAt);
}

// solve(0,1)でブチ込む
int solve(int lookAt,int leftSum)
{
  if (memo[lookAt][leftSum] != -1) return memo[lookAt][leftSum];
  int res;
  if (leftSum == 0) {
    res = 0;
  } else {
    // 移動させないときと、移動させたときのうち少ない方をmemoに記憶する。
    res = max(solve(lookAt+1,leftSum),
              solve(lookAt+1,leftSum-1) + cost(lookAt,leftSum)
              );
  }
  debug(res)
  return memo[lookAt][leftSum] = res;
}

int main()
{
  cin >> R >> G >> B;
  memset(memo, -1, sizeof(memo));
  //REP(lookAt,1000) memo[lookAt][R+G+B] = 0;
  cout << solve(1,R+G+B) << endl;
  
  return 0;
}

