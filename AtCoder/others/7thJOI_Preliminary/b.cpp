// ------------------------------------
// Date:2018/ 3/ 2
// Problem:JOI '07 JOIとIOI b.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

static const int MOD = 1000000007;

int main()
{
  char inputStr[10101];
  scanf("%s", inputStr);
  int jCnt, iCnt;
  jCnt = iCnt = 0;
  
  for (int i=0; inputStr[i] != '\0'; ++i) {
    if (inputStr[i - 2] == 'J' and
        inputStr[i - 1] == 'O' and
        inputStr[i]     == 'I') {
      ++jCnt;
    }
    if (inputStr[i - 2] == 'I' and
        inputStr[i - 1] == 'O' and
        inputStr[i]     == 'I') {
      ++iCnt;
    }
  }
  printf("%d\n%d\n", jCnt, iCnt);
  return 0;
}
