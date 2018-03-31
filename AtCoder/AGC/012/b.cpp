// ------------------------------------
// Date:2018/ 3/30
// Problem:- Splatter Painting b.cpp
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
const int MAX_N = 1e5 + 1;

struct Edge {
  Edge(int _to, int _cost)
    : to(_to), cost(_cost){}
  int to;
  int cost;
};

vector< Edge > e[MAX_N];
int color[MAX_N];

int N, M, Q;

void bfs(int s)
{
  vector< bool > state(N, false);
  // q{from, cost}
  queue< pair< int, int > > q;
  q.push({s, 0});
  /*
  EACH(ei, e[s]) {
    if (ei.cost > -1) state[ei.to] = true;
  }
  */
  state[s] = true;

  while(!q.empty()) {
    int from, cost;
    tie(from, cost) = q.front(); q.pop();
    if (state[from]) continue;
    state[from] = true;

    EACH(ei, e[from]) {
      if (state[ei.to]) continue;
      if (ei.cost > -1) {
	// すでに調べてある
	EACH(ej, e[s]) {
	  if (ej.cost < 0 && ej.to == ei.to) {
	    ej.cost = cost + 1;
	    break;
	  }
	}
	continue;
      }
      {
	EACH(ej, e[s]) {
	  if (ej.cost < 0 && ej.to == ei.to) {
	    ej.cost = cost + 1;
	    debug(ej.to);
	    debug(ej.cost);
	    break;
	  }
	}
      }
      ei.cost = cost + 1;
      q.push({ei.to, cost + 1});
    }
  }
  
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  RREP(i, N) {
    REP(j, i) {
      // 自己ループは0, それ以外は-1で初期化
      if (N - i - 1 == j) e[N - i - 1].emplace_back(Edge(j, 0));
      else e[N - i - 1].emplace_back(Edge(j, -1));
    }
  }
  
  REP(i, M) {
    CIN(a, b);
    a--; b--;
    int from = min(a, b);
    int to = max(a, b);
    EACH(ei, e[from]) {
      if (ei.to == to) {
	ei.cost = 1;
	break;
      }
    }
  }

  REP(i, N)
    bfs(i);

  cin >> Q;

  REP(i, Q) {
    CIN(from, dist, _color);
    EACH(ei, e[from]) {
      if (ei.cost <= dist) color[ei.to] = _color;
    }
  }

  REP(i, N)
    cout << color[i] << endl;
  

  REP(from, N) {
    EACH(ei, e[from]) {
      debug(from);
      debug(ei.to);
      debug(ei.cost);
    }
  }
  
  return 0;
}

