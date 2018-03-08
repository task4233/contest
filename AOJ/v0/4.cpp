// ------------------------------------
// Date:2018/ 2/13
// Problem:0004 : SimulataneousEquation 4.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

int main()
{
  double a,b,c,d,e,f;
  while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f) != EOF) {
    cin >> a >> b >> c >> d >> e >> f;
    printf("%.3lf %.3lf\n",(c*e-b*f)/(a*e-b*d), (c*d-a*f)/(b*d-a*e));
  }
  return 0;
}

