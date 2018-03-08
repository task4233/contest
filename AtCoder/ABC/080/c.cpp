// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ABC 080 ShoppingStreet c.cpp
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

//static const int MOD = 1000000007;
static const int INF = 1e9 + 1;

// F[店舗番号][曜日*時間帯]
int F[101][10];
// P[店舗番号][曜日*時間帯]
int P[101][11];
// C[店舗番号]
int C[101];


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(F, 0, sizeof(F));
  memset(P, 0, sizeof(P));
  
  int N;
  cin >> N;
  REP(i, N) {
    REP(j, 10) {
      cin >> F[i][j];
    }
  }
  REP(i, N) {
    REP(j, 11) {
      cin >> P[i][j];
    }
  }
  ll ans = -INF;
  ll tmp;
  FOR(i, 1, (1 << 10)) {
    tmp = 0ll;
    memset(C, 0, sizeof(C));
    REP(j, 10) {
      if (i >> j & 1) {
	REP(k, N) {
	  if (F[k][j] == 1) C[k]++;
	}
      }
    }
    REP(j, N) {
      tmp += P[j][C[j]];
    }
    ans = max(ans, tmp);
  }

  cout << ans << endl;
  
  return 0;
}

