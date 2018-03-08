// ------------------------------------
// Date:2018/ 2/18
// Problem:ARC 013 切り分けできるかな？ d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int N;
int X[100];
int Y[100];
int Z[100];

int main()
{
  cin >> N;
  REP(i,N) {
    cin >> X[i] >> Y[i] >> Z[i];
  }
  
  return 0;
}

