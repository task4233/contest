// ------------------------------------
// Date:2018/ 3/ 7
// Problem:ABC 078 ABS d.cpp
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

// static const int MOD = 1000000007;
static const int INF = 1e9 + 1;

// memo[2010]
// int memo[2010];


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  // memset(memo, 0, sizeof(memo));
  int N, Z, W;
  cin >> N >> Z >> W;
  vector< int > a(N);
  REP(i, N) {
    cin >> a[i];
  }

  // int mMin = INF, mMax = -INF;
  int ans = 0;
  if (N == 1) {
    ans = abs(a[0] - W);
  } else {
    ans = max(abs(a[N - 1] - a[N - 2]),
	      abs(a[N - 1] - W));
      /*
      mMin = min(mMin, a[i]);
      mMax = max(mMax, a[i]);
      // 最小値
      memo[i][0] = abs(mMin - a[N - 1]);
      // 最大値
      memo[i][1] = abs(mMax - a[N - 1]);
      */
  }

  /*
  int tmp;
  if (mMin < a[N - 1]) {
    // 最後のカードが最大値
    tmp = 1;
    ans = max(ans, abs(a[N - 1] - W));
  } else {
    // 最後のカードが最大値じゃない
    tmp = 0;
  }

  REP(i, N) {
    ans = max(ans, memo[i]);
  }
  */

  
  cout << ans << endl;
  
  return 0;
}

