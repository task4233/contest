// ------------------------------------
// Date:2018/ 3/ 2
// Problem:01 ナップサック問題 j 2_3_1.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

//static const int MOD = 1000000007;

// N:品物の個数 / W:ナップサックの容量
int N, W;
// v:value of good / w:weight of good
int v[101];
int w[101];

// dp[今見ている品物の番号][まだ入れられる量]
int dp[101][101010];

// num:今見ている品物の番号 / weight:まだ入れられる重さの総和
int rec(int num, int weight)
{
  if (dp[num][weight] != -1) {
    // すでに調べていれば、その値を再利用する。
    return dp[num][weight];
  }
  int res;
  if (num == N) {
    // 品物を全て見尽くした状態。
    // 何もすることがないため、返り値は0となる。
    res = 0;
  } else if (weight < w[num]) {
    // まだ入れられる重さの総和よりも、今見ている品物の重さの方が大きい状態。
    // この状態では、これ以上ナップサックには入らない。
    // したがって、返り値は次の品物の返り値に委ねられる。
    res = rec(num + 1, j);
  } else {
    // ナップサックに入れることができる状態。
    // 入れる　or 入れない　を選択することができる。
    // 両者のうちより価値が高くなる方を選ぶ。
    res = max(rec(num + 1, weight),
              rec(num + 1, weight - w[num]) + v[num]);
  }
  return dp[num][weight] = res;
}

int main()
{
  memset(dp, -1, sizeof(dp));
  printf("%d\n", rec(0, W));
  return 0;
}

