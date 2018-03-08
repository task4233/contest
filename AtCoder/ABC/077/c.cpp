// ------------------------------------
// Date:2018/ 3/ 7
// Problem:ABC 077 SnukeFestival c.cpp
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

  int N, tmp;
  cin >> N;
  vector< int > A(N);
  vector< int > B(N);
  vector< int > C(N);
  REP(i, N) {
    cin >> A[i];
  }
  REP(i, N) {
    cin >> B[i];
  }
  REP(i, N) {
    cin >> C[i];
  }

  sort(ALL(A));
  sort(ALL(B));
  sort(ALL(C));

  ll ans = 0ll;
  // O(NlogN)
  REP(i, N) {
    ll tmp1 = lower_bound(ALL(A), B[i]) - A.begin();
    ll tmp2 = N - (upper_bound(ALL(C), B[i]) - C.begin());
    ans += tmp1 * tmp2;
  }

  cout << ans << endl;
  
  return 0;
}

