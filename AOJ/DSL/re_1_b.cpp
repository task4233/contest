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

    // xがyの和になるので、xとyの差分をdiff_weight[y]に記録
    diff_weight[y] = w;
    return true;
  }

  // templateですよ！！！
  
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, Q);
  UnionFind< int > uf(N + 1);

  REP(qi, Q) {
    CIN(c);
    if (c == 0) {
      CIN(x, y, w);
      // merge
      uf.merge(x, y, w);
    } else {
      // judge
      CIN(x, y);
      if (!uf.issame(x, y)) {
	cout << "?" << endl;
      } else {
	cout << uf.diff(x, y) << endl;
      }
    }
  }
  
  return 0;
}

