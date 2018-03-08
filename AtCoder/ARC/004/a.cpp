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
  double ans = 0.0;
  cin >> N;
  vector<double> x(N);
  vector<double> y(N);
  REP(i,N) {
    cin >> x[i] >> y[i];
  }
  REP(i,N) {
    REP(j,N) {
      ans = max(sqrt(pow(x[j]-x[i],2) + pow(y[j]-y[i],2)),ans);
    }
  }
  printf("%.4lf\n",ans);
  return 0;
}

