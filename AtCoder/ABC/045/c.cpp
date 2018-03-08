// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 045 ManyFormulas c.cpp
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
  string S;
  int N;
  cin >> S;
  N = S.size();
  
  ll ans = 0ll;
  // 全探索はbitを立てるor立てないの2通りで2^(N-1)
  REP(i,(1<<N-1)) {
    ll sum = 0;
    REP(j,N) {
      sum = sum*10 + (S[j] - '0');
      if (i & (1<<j)) {
        ans += sum;
        // リセット
        sum = 0;
      }
    }
    ans += sum;
  }
  cout << ans << endl;
  return 0;
}

