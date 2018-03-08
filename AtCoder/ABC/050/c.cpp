// ------------------------------------
// Date:2018/ 2/25
// Problem:ABC 050 LiningUp c.cpp
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

#define MOD 1000000007

int main()
{
  int N;
  int cnt = 1;
  cin >> N;
  vector<int> A(N);
  vector<int> Ans(N);
  REP(i,N) {
    cin >> A[i];
    // N人の時の報告は左にi人,右にN-i-1人いる
    Ans[i] = abs(N-i-1-i);
  }
  sort(ALL(A));
  sort(ALL(Ans));

  if (A == Ans) {
    REP(i,N/2) {
      cnt <<= 1;
      cnt %= MOD;
    }
  } else {
    cnt = 0;
  }
  cout << cnt << endl;
  return 0;
}

