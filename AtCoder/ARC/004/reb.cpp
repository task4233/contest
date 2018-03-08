// ------------------------------------
// Date:2018/ 2/20
// Problem:ARC 004 TheLongestDistance a.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int main()
{
  int N;
  double ans_M = 0.0;
  double ans_m = 30000.0;
  cin >> N;
  vector<double> x(N);
  REP(i,N) {
    cin >> x[i];
  }
  REP(i,N) {
    REP(j,N) {
      if (j == i) continue;
      ans_M = max(sqrt(pow(x[j],2) - pow(x[i],2)),ans_M);
      ans_m = min(sqrt(pow(x[j],2) - pow(x[i],2)),ans_m);
    }
  }
  printf("%.4lf\n",ans_M);
  printf("%.4lf\n",ans_m);
  return 0;
}

