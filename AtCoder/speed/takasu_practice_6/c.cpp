// ------------------------------------
// Date:2018/ 3/26
// Problem:塗り絵 _ _ c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "YES" : "NO") << endl;
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

#define re(n) (n + 100)
#define rere(n) n + 100

int d[200][200];

int x[3], y[3], r;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(d, 0, sizeof(d));

  cin >> x[0] >> y[0] >> r >> x[1] >> y[1] >> x[2] >> y[2];

  REP(xi, 200) {
    REP(yi, 200) {
      int distx = xi - re(x[0]);
      int disty = yi - re(y[0]);
      // debug(xi);
      // debug(x[0]);
      // debug(re(x[0]));
      // debug(distx);
      //debug(disty);
      if (distx * distx + disty * disty <= r * r) {
	d[xi][yi]++;
	// debug(xi - 100);
	// debug(yi - 100);
      }
    }
  }

  FOR(xi, re(x[1]), re(x[2]) + 1) {
    FOR(yi, re(y[1]), re(y[2]) + 1) {
      d[xi][yi] += 2;
    }
  }

  bool r, b;
  r = b = false;
  REP(xi, 200) {
    REP(yi, 200) {
      if (d[xi][yi] == 1) r = true;
      if (d[xi][yi] == 2) b = true;
    }
  }

  OK(r);
  OK(b);

  return 0;
}

