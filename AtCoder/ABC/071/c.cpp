// ------------------------------------
// Date:2018/ 3/12
// Problem:ABC 071 MakeARectangle c.cpp
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
static const int INF = 1e9 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  pair< int, int > *A;
  A = new pair< int, int >[N];
  REP(i, N) {
    int tmp;
    cin >> tmp;
    A[
  }

  /*
  REP(i, A.size()) {
    debug(A[i]);
  }
  */

  set< int > st;
  REP(ai, A.size()) {
    if (A[ai] >= 2) {
      if (st.size() < 2) {
	st.insert(ai);
	// cout << A[ai] << endl;
      } else {
	int minNum = INF;
	for(auto itr = st.begin(); itr != st.end(); ++itr) {
	  minNum = min(minNum, *itr);
	  // cout << *itr << endl;
	}
	st.erase(minNum);
	st.insert(ai);
      }
    }
  }

  ll ans = 1ll;
  if (st.size() < 2) ans = 0ll;
  else {
    for(auto itr = st.begin(); itr != st.end(); ++itr) {
      ans *= *itr;
      
    }
  }

  cout << ans << endl;
  
  return 0;
}

