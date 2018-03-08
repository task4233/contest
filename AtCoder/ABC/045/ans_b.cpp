// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 045 GameForThree b.cpp
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

using ll = long long;

int main()
{
  string a,b,c;
  char card = 'a';
  char output;
  int aCnt,bCnt,cCnt;
  bool flag = false;
  cin >> a;
  cin >> b;
  cin >> c;
  aCnt = bCnt = cCnt = 0;
  REP(i,a.size()+b.size()+c.size()) {
    switch(card) {
      case 'a':
        card = a[aCnt];
        if (++aCnt == a.size()+1) {
          flag = true;
          output = 'A';
        }
        break;
      case 'b':
        card = b[bCnt];
        if (++bCnt == b.size()+1) {
          flag = true;
          output = 'B';
        }
        break;
      case 'c':
        card = c[cCnt];
        if (++cCnt == c.size()+1) {
          flag = true;
          output = 'C';
        }
        break;
    }
    if (flag) break;
  }
  cout << output << endl;
  return 0;
}

