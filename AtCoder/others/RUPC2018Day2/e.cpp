// ------------------------------------
// Date:2018/ 4/ 6
// Problem:Light / / e.cpp
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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 101;

int W, H, N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> W >> H >> N;
  vector< int > x(1, 1);
  vector< int > y(1, 1);
  x.emplace_back(W);
  y.emplace_back(H);
  REP(i, N) {
    CIN(p, q);
    x.emplace_back(p);
    y.emplace_back(q);
  }

  int ans = 0;
  REP(from, N + 2) {
    int cost = INF;
    REP(to, from) {
      if (from == to) continue;
      cost = min(cost, abs(x[to] - x[from]) + abs(y[to] - x[from]));
    }
    debug(cost);
    if (cost == INF) continue;
    ans = max(ans, cost);
    debug(ans);
  }

  cout << ans << endl;

  return 0;
}

