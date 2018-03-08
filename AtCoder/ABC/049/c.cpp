// ------------------------------------
// Date:2018/ 2/25
// Problem:ABC 049 DayDream c.cpp
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
  string inputStr,tmp;
  // state 0: ,1:dream, 2:erase, 3:e, 4:r
  int state = 0;
  bool output = true;
  
  cin >> inputStr;
  REP(num, inputStr.size()) {
    switch(state) {
      case 0:
        tmp = inputStr.substr(num,5);
        if (tmp == "dream") state = 1;
        else if (tmp == "erase") state = 2;
        else output = false;
        num += 4;
        break;
        // dream
      case 1:
        tmp = inputStr.substr(num,5);
        if (tmp == "dream") num += 4;
        else if (tmp == "erase")
        {
          state = 2;
          num += 4;
        } else if (tmp[0] == 'e') state = 3;
        else output = false;
        break;
        // erase
      case 2:
        tmp = inputStr.substr(num,5);
        if (tmp == "dream") {
          state = 1;
          num += 4;
        }
        else if (tmp == "erase") num += 4;
        else if (tmp[0] == 'r') state = 4;
        else output = false;
        break;
        // e
      case 3:
        if (inputStr[num] == 'r') state = 4;
        else output = false;
        break;
        // r
      case 4:
        tmp = inputStr.substr(num,5);
        if (tmp == "dream") state = 1;
        else if (tmp == "erase") state = 2;
        else output = false;
        num += 4;
        break;
    }
  }
  if (state == 3) output = false;
  cout << (output?"YES":"NO") << endl;
  return 0;
}

