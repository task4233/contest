// ------------------------------------
// Date:2018/ 3/15
// Problem:AGC 012 AtCoderGroupContest a.cpp
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

  int N;
  cin >> N;
  vector< int > A(3 * N);
  REP(i, 3 * N) cin >> A[i];

  sort(ALL(A));

  ll ans = 0ll;
  for (int i = N; i < 3 * N; i += 2) {
    ans += A[i];
  }
  cout << ans << endl;
  
  return 0;
}

