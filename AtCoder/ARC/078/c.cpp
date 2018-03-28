// ------------------------------------
// Date:2018/ 3/14
// Problem:ARC 078 SplittingPile c.cpp
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

static const int INF = 1000000001;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  
  vector< int > A(N);
  ll sum = 0ll;
  REP(i, N) {
    cin >> A[i];
    sum += A[i];
  }

  ll ans = INF;
  ll tmp = 0ll;
  RFOR(i, 1, N) {
    tmp += A[i];
    sum -= A[i];
    ans = min(ans, abs(sum - tmp));
  }
  if (N == 2) {
    ans = abs(A[1] - A[0]);
  }

  cout << ans << endl;
  return 0;
}

