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

/*
template< class Abel > struct WeightedUnionFind {
  vector< int > par;
  vector< int > rank;
  vector< Abel > diff_weight;

  WeightedUnionFind(int n = 1, Abel SUM_UNITY = 0) {
    init(n, SUM_UNITY);
  }

  void init(int n = 1, Abel SUM_UNITY = 0) {
    par.resize(n); rank.resize(n); diff_weight.resize(n);
    REP(i, n) {
      par[i] = i;
      rank[i] = 0;
      diff_weight[i] = SUM_UNITY;
    }
  }

  int root(int x) {
    if (par[x] == x) {
      // 根がそれ自身だった時にそれを返す
      return x;
    } else {
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  Abel weight(int x) {
    // 経路圧縮
    root(x);
    return diff_weight[x];
  }

  Abel diff(int x, int y) {
    return weight(y) - weight(x);
  }

  // xにyをつなぐ
  // weight(y) - weight(x) = wとなるようにmergeする
  bool merge(int x, int y, Abel w) {
    // xとyそれぞれについて、rootとの重み差分を補正
    w += weight(x); w-= weight(y);
    x = root(x); y = root(y);
    if (x == y) {
      // 既に連結である
      return false;
    }
    if (rank[x] < rank[y]) {
      // xにyを連結する設定
      swap(x, y);
      w *= -1;
    }
    if (rank[x] == rank[y]) {
      // xとyが同じ時、xの根にyの根を連結する
      ++rank[x];
    }
    par[y] = x;

    diff_weight[y] = w;
    return true;
  }
};
*/

template< class Abel > struct WeightedUnionFind {
  vector< int > par;
  vector< Abel > diff_weight;
  WeightedUnionFind(int n = 1, Abel SUM_UNITY = 0) {
    init(n, SUM_UNITY);
  }

  void init(int n, Abel SUM_UNITY = 0) {
    par.resize(n); diff_weight.resize(n);
    for(int i = 0; i < n; i++) {
      par[i] = -1;
      diff_weight[i] = SUM_UNITY;
    }
  }
  
  int root(int n) {
    if (par[n] < 0) return n;
    diff_weight[n] += diff_weight[par[n]];
    return par[n] = root(par[n]);
  }

  Abel weight(int n) {
    root(n);
    return diff_weight[n];
  }

  Abel diff(int x, int y) {
    return weight(y) - weight(x);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }
  
  bool unite(int x, int y, Abel w) {
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) {
      swap(x, y);
      w = -w;
    }
    par[x] += par[y];
    par[y] = x;
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
  WeightedUnionFind< int > uf(N);
  REP(i, M) {
    CIN(l, r, d);
    --l; --r;
    if (uf.issame(l, r)) {
      int diff = uf.diff(l, r);
      if (diff != d) ok = false;
      // debug(diff);
      // debug(d);
    } else {
      uf.unite(l, r, d);
    }
  }

  OK(ok);

  return 0;
}

