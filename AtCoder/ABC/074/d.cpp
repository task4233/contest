// ------------------------------------
// Date:2018/ 3/11
// Problem:ABC 074 RestoringRoadNetwork d.cpp
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
const int MAX_N = 300;

int N;
int A[MAX_N][MAX_N];
bool state[MAX_N][MAX_N];

int main()
{
  // cin.tie(0);
  //ios::sync_with_stdio(false);

  cin >> N;

  REP(hi, N) {
    REP(wi, N) {
      cin >> A[hi][wi];
    }
  }
  
  bool ok = true;
  REP(k, N) {
    REP(i, N) {
      REP(j, N) {
	if (i == j || k == j || i == k) continue;
	if (A[i][k] + A[k][j] == A[i][j]) {
	  if (A[i][k] == 0 || A[k][j] == 0) continue;
	  A[i][j] = 0;
	} else if (A[i][k] + A[k][j] < A[i][j]) {
	  if (A[i][k] == 0 || A[k][j] == 0) continue;
	  ok = false;
	}
      }
    }
  }

  /*
  cout << endl;

  REP(i, N) {
    REP(j, N) {
      printf("%3d", A[i][j]);
    }
    cout << endl;
  }
  */

  ll ans = 0ll;
  REP(to, N) {
    REP(from, to) {
      ans += A[from][to];
    }
  }

  if (!ok) ans = -1ll;

  cout << ans << endl;
  
  return 0;
}

