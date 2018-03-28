// ------------------------------------
// Date:2018/ 3/17
// Problem:C- Blue Bird d.cpp
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

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)
static const int INF = 1000000001;
static const int MAX_N = 301;

int N, M;
int d[MAX_N][MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  REP(i, N) {
    d[i][i] = 0;
  }
  REP(i, N) {
    REP(j, N) {
      if (i == j) d[i][j] = 0;
      else d[i][j] = INF;
    }
  }
  REP(i, M) {
    CIN(u, v, l);
    d[u - 1][v - 1] = l;
    d[v - 1][u - 1] = l;
  }


  FOR(k, 1, N) {
    FOR(i, 1, N) {
      FOR(j, 1, N) {
	d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
      }
    }
  }

  ll ans = INF;
  FOR(i, 1, N) {
    FOR(j, 1, N) {
      if (i == j) continue;
      if (d[0][i] == INF or d[j][0] == INF) continue;
      ll tmp = d[0][i] + d[i][j] + d[j][0];
      // debug(i);
      // debug(j);
      // debug(tmp);
      ans = min(ans, tmp);
    }
    // debug(i);
    // debug(ans);
  }

  if (ans >= INF) ans = -1;
  cout << ans << endl;

  /*
  REP(i, N) {
    REP(j, N) {
      cout << i << ":" << j << "->" << d[i][j] << endl;
    }
  }
  */

  return 0;
}

