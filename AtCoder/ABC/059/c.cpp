// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 059 Sequence c.cpp
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
  int n;
  cin >> n;
  vector< int > a(n);
  REP(ai, n) cin >> a[ai];
  vector< int > data(n - 1);
  data[0] = a[i];
  FOR(i, 1, n) {
    data[i] += data[i - 1] + a[i - 1];
  }
  // 正と負のパターンを試して、少ない方を取る
  // positiveCount
  int pCnt;
  bool state;
  state = true;
  // positive
  REP(i, n - 1) {
    if (state) {
      if (data[i] <= 0) {
        pCnt +=
      }
    }
  }
  return 0;
}

