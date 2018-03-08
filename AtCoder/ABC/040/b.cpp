// ------------------------------------
// Date:2018/ 2/25
// Problem:ABC 040 □□□□□ b.cpp
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
  int n,ans = 10e7;
  cin >> n;
  REP(i,400) {
    REP(j,i+1) {
      if (i*j <= n) ans = std::min(ans,(n - i*j + i-j));
    }
  }
  cout << ans << endl;
  return 0;
}
