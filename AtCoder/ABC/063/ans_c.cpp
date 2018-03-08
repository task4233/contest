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
  int N, s, diff, sum, ans;
  cin >> N;
  sum = 0;
  diff = 1e9;
  REP(i, N) {
    cin >> s;
    sum += s;
    // debug(s);
    // 必要のない数字1つをdiffにストック
    if (s % 10 != 0 && s < diff) diff = s;
  }
  ans = sum - (sum % 10 == 0 ? diff : 0);
  cout << (ans < 0 ? 0 : ans) << endl;
  return 0;
}

