#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, K);

  vector< ll > x(N);
  vector< ll > y(N);
  REP(i, N) {
    cin >> x[i] >> y[i];
  }

  vector< ll > sortX(x);
  vector< ll > sortY(y);
  sort(ALL(sortX));
  sort(ALL(sortY));

  ll ans = (sortX.back() - sortX[0]) * (sortY.back() - sortY[0]);

  REP(xi, N) {
    REP(yi, N) {
      FOR(xj, xi, N) {
	FOR(yj, yi, N) {

	  ll minX = sortX[xi];
	  ll minY = sortY[yi];
	  ll maxX = sortX[xj];
	  ll maxY = sortY[yj];

	  int cnt = 0;
	  // ここから範囲内全探索
	  REP(i, N) {
	    if (minX <= x[i] && x[i] <= maxX &&
		minY <= y[i] && y[i] <= maxY) {
	      cnt++;
	    }
	  }

	  if (cnt >= K) {
	    ans = min(ans, (maxX - minX) * (maxY - minY));
	  }
	  
	}
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}


