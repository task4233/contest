// ------------------------------------
// Date:2018/ 3/13
// Problem:ABC 068 BreakNumber b.cpp
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

int power(int x, int n)
{
  int res = 1;
  while(n > 0) {
    if (n & 1) {
      res = res * x;
    }
    x = x * x;
    n >>= 1;
  }
  //  debug(reas);
  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  int ans = 1;
  REP(i, 10) {
    if (power(2, i) > N){
      ans = power(2, i - 1);
      break;
    }
  }
  cout << ans << endl;
  
  return 0;
}

