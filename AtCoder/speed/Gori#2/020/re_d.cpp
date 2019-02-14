template< class Abel > struct UnionFind {
  vector< int > par;
  vector< int > rank;
  vector< Abel > diff_weight;
  
  UnionFind(int n = 1, Abel SUM_UNITY = 0) {
    init(n, SUM_UNITY);
  }

  void init(int n = 1, Abel SUM_UNITY = 0) {
    par.resize(n); rank.resize(n), diff_weight.resize(n);
    for(int i = 0; i < n; i++) {
      par[i] = i;
      rank[i] = 0;
      diff_weight[i] = SUM_UNITY;
    }
  }
  
  int root(int x) {
    if (par[x] == x) return x;
    // 累積和をとる
    int r = root(par[x]);
    diff_weight[x] += diff_weight[par[x]];
    return par[x] = r;
  }

  Abel weight(int x) {
    // 経路圧縮をする
    root(x);
    return diff_weight[x];
  }

  Abel diff(int x, int y) {
    return weight(y) - weight(x);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  // weight(x) - weight(y) = wとなるようにmerge
  bool merge(int x, int y, Abel w) {
    // xとyそれぞれについてrootとの重み付き補正
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) {
      swap(x, y);
      w = -w;
    }
    if (rank[x] == rank[y]) {
      ++rank[x];
    }
    par[y] = x;

    // xがyの大和になるので、xとyの差分をdiff_weight[y]に記録
    diff_weight[y] = w;
    return true;
  }
};
