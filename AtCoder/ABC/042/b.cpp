// ------------------------------------
// Date:2018/ 2/22
// Problem:ABC 042 IrohaLovesStrings b.cpp
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

int main()
{
  int N,L;
  cin >> N >> L;
  vector<string> S(N);
  REP(i,N) {
    cin >> S[i];
  }
  sort(ALL(S));
  REP(i,N) cout << S[i];
  cout << endl;
  return 0;
}

