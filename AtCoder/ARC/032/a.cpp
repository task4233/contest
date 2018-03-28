// ------------------------------------
// Date:2018/ 3/10
// Problem:ARC 032 ホリドッグ a.cpp
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
static const int MAX_N = 505050;

bool prime[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(prime, true, sizeof(prime));
  FOR(i, 2, sqrt(MAX_N)) {
    // if (!prime[i]) continue; 
    for(int j = 0; i * (j + 2) < MAX_N; ++j) {
      prime[i * (j + 2)] = false;
    }
  }

  prime[0] = prime[1] = false;
  int n;
  cin >> n;
  int tmp = ((1 + n) * n) / 2;
  cout << (prime[tmp] ? "WANWAN" : "BOWWOW") << endl;
  
  return 0;
}

