// ------------------------------------
// Date:2018/ 2/27
// Problem:ABC 079 GoodInteger a.cpp
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
  char lastNum;
  int cnt = 0;
  string inputStr;
  cin >> inputStr;
  
  REP(i, inputStr.size()) {
    if (i == 0) {
      lastNum = inputStr[0];
    } else {
      if (lastNum != inputStr[i]) {
        if (i == 1) {
          lastNum = inputStr[1];
        } else {
          cout << "No" << endl;
          return 0;
        }
      } else {
        ++cnt;
        if (cnt >= 2) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}

