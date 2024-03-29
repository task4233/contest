// ------------------------------------
// Date:2018/ 3/11
// Problem:ABC 090 . d.cpp
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

  int N, K;
  cin >> N >> K;

  ll cnt = 0ll;
  cnt += (N - K + 1) * (N - K) / 2;
  // a > b
  FOR(a, 1, N) {
    FOR(b, K, a) {
      if (a % b >= K) cnt++;
    }
  }

  cout << cnt << endl;
  
  return 0;
}

