// ------------------------------------
// Date:2018/ 3/24
// Problem:C - 正直者の高橋くん a.cpp
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

struct Edge {
  Edge(int _to)
    : to(_to) {}
  int to;
};

vector< Edge > e[MAX_N];
int dist[MAX_N];
int cnt[MAX_N];

int solve(int s, int g)
{
  queue< int > q;
  q.push(s);
  fill_n(dist, MAX_N, INF);
  dist[s] = 0;
  fill_n(cnt, MAX_N, 0);
  cnt[s] = 1;

  int minCost = 0;
  while(!q.empty()) {
    int from = q.front();
    q.pop();
    if (from == g) continue;
    EACH(to, e[from]) {
      if (dist[to.to] == INF) {
	dist[to.to] = dist[from] + 1;
	cnt[to.to] = cnt[from] % MOD + cnt[to.to] % MOD;
	q.push(to.to);
      } else {
	if (dist[to.to] == dist[from] + 1) {
	  cnt[to.to] = cnt[from] % MOD + cnt[to.to] % MOD;
	}
      }
    }
  }

  return cnt[g] % MOD;
}

int main()
{
  CIN(N, A, B, M);
  REP(i, M) {
    CIN(a, b);
    e[a - 1].emplace_back(Edge(b - 1));
    e[b - 1].emplace_back(Edge(a - 1));
  }
  
  int ans = solve(A - 1, B - 1);
  cout << ans << endl;
  
  return 0;
}

