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

int N;

struct Edge {
  Edge(int _from, int _to, int _cost)
    : from(_from), to(_to), cost(_cost){}
  int from;
  int to;
  int cost;
};

vector< Edge > e;
// bool state[MAX_N];

struct UnionFind {
  vector< int > par;
  UnionFind(int n = 1) {
    init(n);
  }

  void init(int n) {
    par.resize(n);
    for(int i = 0; i < n; i++)
      par[i] = -1;
  }
  
  int root(int n) {
    if (par[n] < 0) return n;
    return par[n] = root(par[n]);
  }

  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;

    return true;
  }
};

int kruscal()
{
  sort(ALL(e), [](Edge x, Edge y) {
      return x.cost < y.cost;
    });

  UnionFind uf(N);
  int res = 0;
  EACH(ei, e) {
    // if (state[ei.from] && state[ei.to]) continue;
    if (uf.root(ei.from) != uf.root(ei.to)){
      uf.unite(ei.from, ei.to);
      // state[ei.from] = state[ei.to] = true;
      res += ei.cost;
    }
  }

  return res;
}


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  // x, y, i
  vector< tuple< int, int, int > > x(N);
  // y, x, i
  vector< tuple< int, int, int > > y(N);
  REP(i, N) {
    CIN(p, q);
    x[i] = make_tuple(p, q, i);
    y[i] = make_tuple(q, p, i);
  }
  
  sort(ALL(x));
  sort(ALL(y));

  REP(i, N - 1) {
    // x
    int tmp1, tmp2, from, to, cost;
    tie(tmp1, tmp2, from) = x[i];
    tie(tmp2, cost, to) = x[i + 1];
    e.emplace_back(Edge(from, to, abs(tmp2 - tmp1)));
  }
  
  REP(i, N) {
    // y
    int tmp1, tmp2, from, to, cost;
    tie(tmp1, tmp2, from) = y[i];
    tie(tmp2, cost, to) = y[i + 1];
    e.emplace_back(Edge(from, to, abs(tmp2 - tmp1)));    
  }

  int ans = kruscal();
  cout << ans << endl;
  
  return 0;
}

