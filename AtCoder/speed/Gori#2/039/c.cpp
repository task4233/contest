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

struct Compare {
	constexpr bool operator()(pair<int, int> const & a,
														pair<int, int> const & b) const noexcept
	{ if(a.first==b.first) return a.second>b.second; return a.first > b.first; }
};

signed main() {
  INIT;
	VAR(int,n,k);

	priority_queue<pair<int,int>,vector< pair<int,int> >, Compare > q;
	REP(i,n){
		VAR(int,a,b);
		q.push(make_pair(a,b));
	}

	int ans=0;
	REP(i,k){
	  auto tmp = q.top();q.pop();
		//debug(tmp.first);
		//debug(tmp.second);
		ans += tmp.first;
		tmp.first += tmp.second;
		q.push(tmp);
		//debug(ans);
	}
	OUT(ans)BR;
	
  return 0;
}
