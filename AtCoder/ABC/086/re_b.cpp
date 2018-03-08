// ------------------------------------
// Date:2018/ 2/18
// Problem:ABC 086 1_21 b.cpp
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
  string a,b,s;
  cin >> a >> b;
  s = a + b;
  int x = 0;
  REP(i,s.length()) {
    x = x * 10 + (s[i]-'0');
  }
  // 続きは省略

  return 0;
}

