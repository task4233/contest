// ------------------------------------
// Date:2018/ 2/18
// Problem:ABC 088 _ a.cpp
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
  int N,A,x;
  cin >> N >> A;
  x = N%500;
  if (x<=A) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

