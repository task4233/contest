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

template< class Type > struct UnionFind {
  vector< int > par;
  vector< Type > diff_weight;
  UnionFind(int n = 1, Type SUM_UNITY = 0) {
    init(n, SUM_UNITY);
  }

  void init(int n, Type SUM_UNITY) {
    par.resize(n); diff_weight(n);
    fill_n(par, n, -1);
    REP(i, n)
      diff_weight[i] = SUM_UNITY;
  }
  
  int root(int n) {
    if (par[n] < 0) return n;
    // 累積和をとる
    diff_weight[n] += diff_weight[par[n]];
    return par[n] = root(par[n]);
  }

  int weight(int n) {
    // 経路圧縮をする
    root(n);
    return diff_weight[n];
  }

  // weight(x) - weight(y) = wとなるようにmerge
  bool merge(int x, int y, int w) {
    // xとyそれぞれについてrootとの重み付き補正
    w -= weight(x); w += weight(y);
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) {
      swap(x, y);
      w *= -1;
    }
    par[x] += par[y];
    par[y] = x;

    // xがyの大和になるので、xとyの差分をdiff_weight[y]に記録
    diff_weight[y] = w;
    return true;
  }
};


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  bool ok = true;
  CIN(N, M);
  UnionFind< int > uf(N);
  REP(i, M) {
    CIN(l, r, d);
    if (uf.root(l) == uf.root(r)) {
      int diff = uf.weight(l) - uf.weight(r);
      if (diff != d) ok = false;
    } else {
      uf.unite(l, r, d);
    }
    if (!ok) break;
  }

  OK(ok);

  return 0;
}


