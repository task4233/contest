// ------------------------------------
// Date:2018/ 2/25
// Problem:ABC 049 Thin b.cpp
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
  int H,W;
  char ch;
  cin >> H >> W;
  char C[252][252];
  memset(C,'.',sizeof(C));
  REP(hi,H) {
    REP(wi,W) {
      cin >> ch;
      C[2*hi][wi] = ch;
      C[2*hi+1][wi] = ch;
    }
  }
  REP(hi,2*H) {
    REP(wi,W) {
      cout << C[hi][wi];
    }
    cout << endl;
  }
  return 0;
}

