// ------------------------------------
// Date:2018/ 3/11
// Problem:ABC 074 SugarWater c.cpp
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

int A, B, C, D, E, F;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> A >> B >> C >> D >> E >> F;

  int ansW, ansS;
  double rate = 0.0;
  
  // water
  REP(a, F / A * 100) {
    REP(b, F / B * 100) {
      double water = (a * A + b * B) * 100;
      if (water > F) break;
      // sugar
      REP(c, F / C) {
	REP(d, F / D) {
	  double sugar = c * C + d * D;

	  // 例外の処理
	  if (sugar + water == 0) continue;
	  if (sugar + water > F) break;
	  if (water * E < sugar * 100) break;
	  
	  double tmp = (100 * sugar) / (sugar + water);

	  if (tmp >= rate) {
	    ansW = water;
	    ansS = sugar;
	    rate = tmp;
	  }
	}
      }
    }
  }

  cout << ansW + ansS << " " << ansS << endl;
  
  return 0;
}

