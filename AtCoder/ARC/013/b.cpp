// ------------------------------------
// Date:2018/ 2/18
// Problem:ARC 013 引越しできるかな？ b.cpp
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
  int C;
  vector<int> data(3,0);
  vector<int> ans(3,0);
  cin >> C;
  REP(i,C) {
    cin >> data.at(0) >> data.at(1) >> data.at(2);
    sort(data.begin(),data.end());
    ans.at(0) = max(ans.at(0),data.at(0));
    ans.at(1) = max(ans.at(1),data.at(1));
    ans.at(2) = max(ans.at(2),data.at(2));
  }
  cout << ans.at(0)*ans.at(1)*ans.at(2) << endl;
  
  
  return 0;
}

