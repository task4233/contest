// ------------------------------------
// Date:2018/ 2/28
// Problem:ABC 063 Bugged c.cpp
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

static const int MOD = 1000000007;

int main()
{
  int N;
  cin >> N;
  vector< int > s(N);
  REP(i, N) {
    cin >> s[i];
  }
  ll sum,ans = 0ll;
  FOR(bit, 1, (1 << N)) {
    sum = 0ll;
    REP(i, N) {
      if ((bit >> i) & 1) {
        sum += s[i];
        //debug(i);
        //debug(s[i]);
        //debug(sum);
      }
    }
    if (sum % 10 == 0) sum = 0;
    //debug(sum);
    //cout << endl;
    if (sum > ans) ans = sum;
    //ans = max(sum, ans);
  }
  cout << ans << endl;
  return 0;
}

