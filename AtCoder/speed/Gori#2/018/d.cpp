#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
#include <cfloat>
#include <set>
#include <map>

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

signed main() {
  INIT;
	VAR(int, n);
	vector<PAIR> d(n);
	REP(i,n) cin>>d[i].first>>d[i].second;

	// dの1つ目の要素で昇順ソート
	sort(ALL(d), [](PAIR p1, PAIR p2){
		if (p1.first == p2.first) return p1.second < p2.second;
		return p1.first < p2.first;
	});

	// bはdの2つ目の要素のみを格納するためのvector
	// (dの1つ目の要素が重複している時, 2つ目の要素が小さいものを採用)
	vector<int> b;
	REP(i, n) {
		if (i>0 && d[i].first == d[i-1].first) continue;
		b.push_back(d[i].second);
	}

	// 作った要素でLISを求める
	vector<int> dp(b.size()+1,LINF);
	REP(i,b.size()){
		*lower_bound(ALL(dp), b[i]) = b[i];
	}

	int ans = lower_bound(ALL(dp), INF) - dp.begin();
	OUT(ans)BR;
  
  return 0;
}
