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

typedef map< int, int > MP;

struct UnionFind {
  vector< int > par;
  UnionFind(int n) {
    init(n);
  }

  void init(int n) {
    par.resize(n);
    REP(i, n)
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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, M);
  UnionFind uf(N);
  MP mp;
  REP(i, M) {
    CIN(u, v);
    u--; v--;
    if (!uf.unite(u, v)) mp[uf.root(u)] = -1;
  }

  REP(i, N)
    if (mp[uf.root(i)] > -1) mp[uf.root(i)]++;

  int ans = 0;
  REP(i, N)
    if (mp[i] > 0) ans++;

  cout << ans << endl;

  return 0;
}

