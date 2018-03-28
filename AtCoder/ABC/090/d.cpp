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

bool state[101010];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, K;
  cin >> N >> K;

  ll cnt = 0ll;
  cnt += (N - K) * (N - K + 1) / 2;
  // a > b -> a % b >= K
  FOR(i, K + 1, N) {
    if (N % i >= K) {
      cnt += i - K;
    }
  }
  
  cout << cnt << endl;
  
  return 0;
}

