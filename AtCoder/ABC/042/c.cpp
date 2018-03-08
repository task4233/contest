// ------------------------------------
// Date:2018/ 2/22
// Problem:ABC 042 Iroha's Obsession c.cpp
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
  int N,K;
  string t;
  cin >> N >> K;
  vector<int> L(K);
  REP(i,K) cin >> L[i];
  FOR(i,N,10*N) {
    bool flag = true;
    t = to_string(i);
    REP(j,t.size()) {
      REP(k,L.size()) {
        if (t[j]-'0' == L[k]) flag = false;
      }
    }
    if (flag) {
      cout << t << endl;
      return 0;
    }
  }
  cout << endl;
  
  return 0;
}

