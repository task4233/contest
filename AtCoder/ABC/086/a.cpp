// ------------------------------------
// Date:2018/ 2/17
// Problem:ABC 086 Product a.cpp
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
  int a,b;
  cin >> a >>b;
  if (a%2==1 && b%2==1) cout << "Odd" << endl;
  else cout << "Even" << endl;
  return 0;
}

