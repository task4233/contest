// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 005 STring a.cpp
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

using ll = long long;

#define MOD 1000000007

int main()
{
  int cnt,sCnt,tCnt;
  string s;
  bool lastch = false;
  cnt = sCnt = tCnt = 0;
  cin >> s;
  REP(i,s.size()) {
    if (s[i] == 'S') {
      ++sCnt;
    }
    if (s[i] == 'T') {
      ++tCnt;
      if (sCnt > 0) {
        --sCnt;
        --tCnt;
      }
    }
  }
  
  cout << sCnt+tCnt << endl;
  return 0;
}

