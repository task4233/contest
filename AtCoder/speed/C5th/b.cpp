// ------------------------------------
// Date:2018/ 3/24
// Problem:C - Blue b.cpp
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

static const int INF = 1e9 + 1;
static const int MAX_N = 3e2 + 1;

// dist[from][to]
int dist[MAX_N][MAX_N];

int main()
{
  CIN(N, M);
  REP(i, N) {
    fill_n(dist[i], N, INF);
    dist[i][i] = 0;
  }
  REP(i, M) {
    CIN(p, q, r);
    dist[p - 1][q - 1] = r;
    dist[q - 1][p - 1] = r;
  }

  REP(k, N) {
    REP(i, N) {
      REP(j, N) {
	if (i == 0 or j == 0 or k == 0) continue;
	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  ll ans = INF;
  FOR(i, 1, N) {
    FOR (j, 1, N) {
      if (i == j) continue;
      if (dist[0][i] == INF or dist[0][j] == INF) continue;
      ll all_path = dist[0][i] + dist[i][j] + dist[j][0];
      ans = min(ans, all_path);
    }
  }

  if (ans >= INF) ans = -1;
  cout << ans << endl;

  return 0;
}

