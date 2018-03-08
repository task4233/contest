// ------------------------------------
// Date:2018/ 2/22
// Problem:ABC 043 UnhappyHacking b.cpp
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
  string s;
  vector<int> output;
  cin >> s;
  REP(i,s.size()) {
    if (s[i] == 'B') {
      if (output.size() != 0) output.pop_back();
    } else {
      output.emplace_back(s[i] - '0');
    }
  }
  REP(i,output.size()) {
    cout << output[i];
  }
  cout << endl;
  return 0;
}

