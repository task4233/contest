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
const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e8 + 1;

struct Edge {
  int from;
  int to;
  ll cost;
};

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

int N;

int kruskal(vector< tuple< int, int, int > > e)
{
  UnionFind uf(N);
  ll res = 0ll;
  EACH(ei, e) {
    int cost, n1, n2;
    tie(cost, n1, n2) = ei;

    if (uf.root(n1) != uf.root(n2)) {
      uf.unite(n1, n2);
      res += cost;
    }
  }
  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> N;
  vector< pair< int, int > > x, y;
  REP(i, N) {
    CIN(a, b);
    x.emplace_back(make_pair(a, i));
    y.emplace_back(make_pair(b, i));
  }

  vector< tuple< int, int, int > > e;
  sort(ALL(x));
  sort(ALL(y));

  REP(i, N - 1) {
    e.emplace_back(make_tuple(x[i + 1].first - x[i].first, x[i].second, x[i + 1].second));
    e.emplace_back(make_tuple(y[i + 1].first - y[i].first, y[i].second, y[i + 1].second));
  }

  sort(ALL(e));

  /*
  EACH(ei, e) {
    int cost, num1, num2;
    tie(cost, num1, num2) = ei;
    debug(cost);
    debug(num1);
    debug(num2);
    cout << endl;
  }
  */
  
  ll ans = kruskal(e);

  cout << ans << endl;

  return 0;
}
