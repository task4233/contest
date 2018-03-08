// ------------------------------------
// Date:2018/ 3/ 5
// Problem:ABC 083 SomeSums b.cpp
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
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, n, ans = 0;
  cin >> n >> a >> b;
  REP(i, n + 1) {
    int tmp = i;
    int sum = 0;
    while (tmp > 9) {
      sum += tmp % 10;
      tmp /= 10;
    }
    sum += tmp;
    //cout << i << ":" << sum << endl;
    if (a <= sum and sum <= b) {
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}

