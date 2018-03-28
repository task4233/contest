// ------------------------------------
// Date:2018/ 3/15
// Problem:APC 001 TwoArrays re_b.cpp
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
  vector< int > a(N);
  vector< int > b(N);
  REP(i, N) {
    cin >> a[i];
  }
  REP(i, N) {
    cin >> b[i];
  }
  
  ll cost = 0ll;
  REP(i, N) {
    // debug(a[i]);
    // debug(b[i]);
    ll tmp = b[i] - a[i];
    if (tmp < 0) cost += tmp;
    else {
      if (tmp <= 1) continue;
      cost += tmp / 2;
    }
    // debug(i);
    // debug(cost);
  }

  bool ok = true;
  if (cost < 0) ok = false;

  cout << (ok ? "Yes" : "No") << endl;
  
  return 0;
}

