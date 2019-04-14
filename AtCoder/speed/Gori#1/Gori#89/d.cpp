#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1e5 + 1;

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
#define BR cout<<"\n";
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)



struct Edge {
  Edge(int _from, int _to, int _cost)
    : from(_from), to(_to), cost(_cost){}
  int from, to, cost;
};
 
vector< Edge > e;

struct UnionFind {
  vector< int > par;
  UnionFind(int n = 1) {
    init(n);
  }

  void init(int n = 1) {
    par.resize(n);
    for(int i = 0; i < n; i++)
      par[i] = -1;
  }
  
  int root(int n) {
    if (par[n] < 0) return n;
    return par[n] = root(par[n]);
  }

  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;

    return true;
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }
};

signed main() {
  INIT;
	VAR(int, n);
	vector< tuple< int, int, int > > x(n), y(n);
	REP(i, n) {
		VAR(int, p, q);
		x[i] = make_tuple(p, q, i);
		y[i] = make_tuple(q, p, i);
	}

	sort(ALL(x));
	sort(ALL(y));

	REP(i, n - 1) {
		int p, q, from, to, cost, tmp;
		tie(p, tmp, from) = x[i];
		tie(q, cost, to) = x[i + 1];
		e.push_back(Edge(from, to, abs(p - q)));

		tie(p, tmp, from) = y[i];
		tie(q, cost, to) = y[i + 1];
		e.push_back(Edge(from, to, abs(p - q)));
	}

	auto kruscal = [=](){
		sort(ALL(e), [](Edge x, Edge y) {
				return x.cost < y.cost;
			});
		
		UnionFind uf(n + 1);
		int res = 0;
		EACH(ei, e) {
			if (uf.root(ei.from) != uf.root(ei.to)){
				uf.merge(ei.from, ei.to);
				res += ei.cost;
			}
		}
		return res;
	};
	
	int ans = kruscal();
	OUT(ans)BR;
	
  return 0;
}
