// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 047 1DReversi c.cpp
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
  int cnt = 0;
  cin >> S;
  FOR(i,1,S.size()) {
    if (S[i-1] != S[i]) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
