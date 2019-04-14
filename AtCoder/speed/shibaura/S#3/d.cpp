#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 3e5 + 1;

// init/input
#define int int64
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...) type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T &t) {cin>>t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<endl;
#define zero(n) cout<<setfill('0')<<right<<setw(n)
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

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

signed main() {
  INIT;
	VAR(int,n,m);
  UnionFind<int> uf(202020);
  bool ok=true;
  REP(i,m) {
    VAR(int,l,r,d);
    if(uf.issame(l,r)) {
      ok &= (uf.diff(l,r) == d);
    } else {
      uf.merge(l,r,d);
    }
  }
  OUT((ok?"Yes":"No"))BR;
  
  return 0;
}
