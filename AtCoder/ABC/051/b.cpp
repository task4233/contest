// ------------------------------------
// Date:2018/ 2/26
// Problem:ABC 051 SumOfThreeIntegers b.cpp
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

typedef long long ll;

#define MOD 1000000007

int main()
{
  int K,S,cnt = 0;
  cin >> K >> S;
  REP(i,K+1) {
    REP(j,K+1) {
      if (S-i-j >= 0 && S-i-j <= K) {
        ++cnt;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}

