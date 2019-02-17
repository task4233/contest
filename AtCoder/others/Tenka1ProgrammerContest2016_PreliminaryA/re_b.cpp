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
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

// 2 \leq N \leq 1000なので, N^2くらいは行けそう?
// 点に重みを持たせて, 辺を後から与えてやればいいやつ?
// 0に最も上にある頂点から, 最小値をその重みにしてあげれば良さそう

//  0
// 1 2
// 0 1 5
// 0 2 10
// 0-1 5
// 0-2 10

//   0
//  1 2
// 3 4
// 2 5
// 3 3
// 4 7

// 0->1
// 0->1->3 3
// 3
// 0->1->4 7
// 最小値(3)を一番上にする
// 0->2 5

//  0
// 1 2
//  3 4
// 5 6
// 1 3
// 4 2
// 5 8
// 6 6
// 0->1 3
// 0->2 2
// 0->2->4 2
// 0->2->3->5 8
// 0->2->3->5 6
// 2->3 6
// 3->5 2

// 下まで行って, そこから上のパスを決めていく感じ?

vector< int > e[1010];
map<int,int> mp;

int dfs(int fr){
  if (mp.count(fr) > 0) return mp[fr];

	int cost = INF;
	EACH(to, e[fr]){
		cost = min(cost, dfs(to));
	}
	return mp[fr] = cost;
}

int solve(int fr){	
	int res = 0;
	EACH(to, e[fr]){
		res += solve(to);
		// 頂点0について, 頂点自体に重みを持たせられないので, 0を返す
		if (fr==0) res += mp[to];
		else res += mp[to] - mp[fr];
	}
	return res;
}

signed main() {
  INIT;

	VAR(int,n,m);
	vector< int > p(n-1);
	REP(i,n-1){
		cin>>p[i];
		e[p[i]].push_back(i+1);
	}
	REP(i,m) {
		VAR(int,b,c);
		mp[b] = c;
	}

	dfs(0);
	/*
	EACH(mi,mp){
		debug(mi.first);
		debug(mi.second);
	}
	*/
	int ans = solve(0);
	OUT(ans)BR;
	
  return 0;
}
