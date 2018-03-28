// ------------------------------------
// Date:2018/ 3/17
// Problem:A B S e.cpp
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

  int N, Z, W;
  cin >> N >> Z >> W;
  vector< int > a(N);
  REP(i, N) {
    cin >> a[i];
  }

  ll tmp1, tmp2;
  tmp1 = tmp2 = 0ll;
  tmp1 = abs(a[N - 1] - W);
  if (N > 1) tmp2 = abs(a[N - 2] - a[N - 1]);
  ll ans = max(tmp1, tmp2);

  cout << ans << endl;
  
  return 0;
}

