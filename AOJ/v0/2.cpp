// ------------------------------------
// Date:2018/ 2/11
// Problem:0002 : DigitNumber 2.cpp
//
// ------------------------------------

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

int main()
{
  int a,b,cnt;
  while (scanf("%d %d", &a, &b) != EOF) {
    cnt = 0;
    a += b;
    while(a>0) {
      a/=10;
      ++cnt;
    }
    printf("%d\n", cnt);
  }
  return 0;
}

