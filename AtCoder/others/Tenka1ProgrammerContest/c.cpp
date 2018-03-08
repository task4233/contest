// ------------------------------------
// Date:2018/ 3/ 8
// Problem:Tenka1ProgrammerContest 4 /N c.cpp
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
  
  FOR(hi, 1, 3501) {
    FOR(ni, 1, 3501) {
      ll tmp1 = N * hi * ni;
      ll tmp2 = 4 * hi * ni - N * ni - N * hi;
      if (tmp2 == 0) continue;
      if (not(tmp1 % tmp2 == 0)) continue;
      ll w = tmp1 / tmp2;
      // w
      if (w > 0 and w <= 3500) {
	// ok
        cout << hi << " " << ni <<  " " << w << endl;
	return 0;
	}
    }
  }
  
  return 0;
}

