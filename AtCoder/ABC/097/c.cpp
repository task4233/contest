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

int N, M;

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

ll cnt[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> N >> M;
  vector< int > p(N);
  REP(i, N) {
    cin >> p[i];
    p[i]--;
  }

  UnionFind uf(N);

  fill_n(cnt, MAX_N, -INF);
  ll tmp = 0ll;
  REP(i, M) {
    CIN(x, y);
    x--; y--;
    uf.unite(x, y);
  }

  ll ans = 0ll;

  REP(i, N) {
    if (uf.root(i) == uf.root(p[i]))
      ans++;
  }
  
  cout << ans << endl;

  /*
  REP(i, N + 1) {
    debug(cnt[i]);
  }
  */

  return 0;
}

