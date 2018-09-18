#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
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
#define debug(x) cerr << #x << ":" << (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

struct Edge {
	int from;
	int to;
	int cost;
};

vector< Edge > e;
int d[MAX_N];

signed main() {
  INIT;
	VAR(int, n, m);
	REP(i, m) {
		VAR(int, a, b, c);
		a--; b--;
		e.push_back(Edge{a, b, -c});
	}
	fill(d, d + n, LINF);

	d[0] = 0;
	REP(i, n) {
		EACH(t, e) {
			if (d[t.from] != LINF && d[t.to] > d[t.from] + t.cost) {
				// 更新できる時は更新
				d[t.to] = d[t.from] + t.cost;

				if (i == n - 1 && t.to == n - 1) {
					// 閉路ができちゃってるとき
					OUT("inf")BR;
					return 0;
				}
			}
		}
	}
	int ans = -d[n - 1];
	OUT(ans)BR;
  
  return 0;
}
