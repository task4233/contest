// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 003 WannaGoBackHome a.cpp
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

#define MOD 1000000007

int main()
{
  string S;
  bool check[4];
  cin >> S;
  memset(check,false,sizeof(check));
  REP(i,S.size()) {
    switch(S[i]) {
      case 'N':
        check[0] = true;
        break;
      case 'S':
        check[1] = true;
        break;
      case 'E':
        check[2] = true;
        break;
      case 'W':
        check[3] = true;
        break;
    }
  }
  if (!(check[0] == check[1])) {
    cout << "No" << endl;
    return 0;
  }
  if (!(check[2] == check[3])) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}

