// ------------------------------------
// Date:2018/ 2/22
// Problem:ABC 044 BeautifulStrings b.cpp
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
  string w;
  int cnt[26] = {0};
  cin >> w;
  REP(i,w.size()) {
    ++cnt[w[i]-97];
  }
  REP(i,26) {
    if (cnt[i]%2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

