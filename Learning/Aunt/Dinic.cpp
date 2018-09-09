#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int MAX_V = 1e5 + 1;

// O(|E||V|^2)
struct Edge {
  Edge(int _to, int _cap, int _rev)
    : to(_to), cap(_cap), rev(_rev) {}
  int to;
  int cap; // 容量
  int rev; // 逆辺
};

vector< Edge > G[MAX_V]; // グラフの隣接リスト表現
int level[MAX_V];        // sからの距離
int iter[MAX_V];         // どこまで調べ終わったか

// fromからtoに向かう容量capの辺グラフに追加する
void add_edge(int _from, int _to, int _cap) {
  G[_from].emplace_back(Edge(_to, _cap, G[_to].size()));
  G[_to].emplace_back(Edge(_from, 0, G[_from].size() - 1));
}

// sからの最短距離をBFSで探す
void bfs(int s) {
  memset(level, -1, sizeof(level));
  queue< int > q;
  level[s] = 0;
  q.push(s);

  while (!q.empty()) {
    int from = q.front(); q.pop();
    for (int i = 0; i < G[from].size(); ++i) {
      Edge &e = G[from][i];
      if (e.cap > 0 && level[e.to] < 0) {
	level[e.to] = level[from] + 1;
	q.push(e.to);
      }
    }
  }
}


// 増加パスをDFSで探す
int dfs(int from, int to, int cost) {
  if (from == to) return cost;
  for (int &i = iter[from]; i < G[from].size(); ++i) {
    Edge &e = G[from][i];
    if (level[from] < level[e.to] && e.cap > 0) {
      int d = dfs(e.to, to, min(cost, e.cap));
      if (d > 0) {
	e.cap = -d;
	G[e.to][e.rev].cap += d;
	return d;
      }
    }
  }
  return 0;
}


// sからtへの最大流を求める
int max_flow(int s, int t) {
  int flow = 0;
  for ( ; ; ) {
    bfs(s);
    if (level[t] < 0) return flow;
    memset(iter, 0, sizeof(iter));
    int f;
    while ((f = dfs(s, t, INF)) > 0) { 
      flow += f;
    }
  }
}


int main()
{
  return 0;
}

