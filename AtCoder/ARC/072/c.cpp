// ------------------------------------
// Date:2018/ 3/15
// Problem:ARC 072 Sequence c.cpp
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

  ll N;
  cin >> N;
  vector< ll > a(N);
  REP(i, N) cin >> a[i];

  ll opSum, epSum, opCnt, epCnt;
  opSum = epSum = opCnt = epCnt = 0ll;
  REP(i, N) {
    opSum += a[i];
    epSum += a[i];
    if (i % 2 == 0) {
      // opSum < 0 / epSum > 0
      if (opSum >= 0) {
	opCnt += abs(opSum) + 1;
	opSum = -1;
      }
      if (epSum <= 0) {
	epCnt += abs(epSum) + 1;
	epSum = 1;
      }
    } else {
      // opSum > 0 / epSum < 0
      if (opSum <= 0) {
	opCnt += abs(opSum) + 1;
	opSum = 1;
      }
      if (epSum >= 0) {
	epCnt += abs(epSum) + 1;
	epSum = -1;
      }
    }
    //  debug(opSum);
    // debug(opCnt);
    // debug(epSum);
    // debug(epCnt);
  }

  ll ans = min(opCnt, epCnt);

  cout << ans << endl;
  
  return 0;
}

