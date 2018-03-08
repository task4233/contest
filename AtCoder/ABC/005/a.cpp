// ------------------------------------
// Date:2018/ 2/16
// Problem:ABC 005 oishiitakoyakinotsukurikata a.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int x,y;

int main()
{
  cin >> x >> y;
  cout << y/x << endl;
  return 0;
}

