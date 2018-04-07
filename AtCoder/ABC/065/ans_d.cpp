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

int kruskal(vector< tuple< ll, int, int > > e)
{
  ll res = 0ll;
  UnionFind uf(N);
  EACH(ei, e) {
    ll cost;
    int e1, e2;
    tie(cost, e1, e2) = ei;
    if (uf.root(e1) != uf.root(e2)) {
      uf.unite(e1, e2);
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
  vector< pair< int, ll > > x, y;
  REP(i, N) {
    CIN(p, q);
    x.emplace_back(make_pair(p, i));
    y.emplace_back(make_pair(q, i));
  }

  sort(ALL(x));
  sort(ALL(y));

  vector< tuple< ll, int, int > > e;
  REP(i, N) {
    e.emplace_back(make_tuple(abs(x[i + 1].first - x[i].first), x[i].second, x[i + 1].second));
    e.emplace_back(make_tuple(abs(y[i + 1].first - y[i].first), y[i].second, y[i + 1].second));
  }

  sort(ALL(e));

  ll ans = kruskal(e);

  cout << ans << endl;

  return 0;
}

