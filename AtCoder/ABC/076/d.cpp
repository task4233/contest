#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

const int INF = 1e9 + 1;

int main()
{
  int N;
  scanf("%d", &N);
  vector< double > t(N);
  vector< double > v(N);
  REP(i, N) {
    scanf("%lf", &t[i]);
  }
  REP(i, N) {
    scanf("%lf", &v[i]);
  }

  // 全体のT秒を求める
  int T = 0;
  REP(i, N) {
    T += t[i];
  }
  
  vector< double > maxV(2 * T + 1, (double)INF);

  // maxのスピードをv[i]で初期化
  int nowT = 0;
  REP(i, N) {
    REP(ti, t[i]) {
      int t1 = nowT + ti * 2;
      int t2 = nowT + ti * 2 + 1;
      maxV[t1] = min(maxV[t1], v[i]);
      maxV[t2] = min(maxV[t2], v[i]);
    }
    nowT += t[i] * 2;
    maxV[nowT] = min(maxV[nowT], v[i]);
  }

  // 0秒とT秒は0(静止)
  maxV[0] = maxV[T * 2] = 0.0;
  
  // 前から比較
  REP(ti, 2 * T + 1) {
    maxV[ti + 1] = min(maxV[ti + 1], maxV[ti] + 0.5);
  } 
  
  // 後ろから比較
  RREP(ti, 2 * T + 1) {
    maxV[ti] = min(maxV[ti], maxV[ti + 1] + 0.5);
  }
  
  double ans = 0.0;
  REP(i, 2 * T + 1) {
    // (上底 + 下底) * 高さ / 2
    ans += (maxV[i] + maxV[i + 1]) * 0.5 / 2.0;
  }

  printf("%.4f\n", ans);

  return 0;
}

