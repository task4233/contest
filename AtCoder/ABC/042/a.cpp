// ------------------------------------
// Date:2018/ 2/22
// Problem:ABC 042 IrohaAndHaiku a.cpp
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
  int fCnt,sCnt,n;
  fCnt = sCnt = 0;
  REP(i,3) {
    cin >> n;
    if (n == 5) ++fCnt;
    if (n == 7) ++sCnt;
  }
  if (fCnt == 2 && sCnt == 1) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}

