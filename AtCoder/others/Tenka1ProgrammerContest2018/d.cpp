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

signed main() {
  INIT;

	VAR(int, n);

	if (n == 1) {
		OUT("Yes")BR;
		OUT(2)BR;
		OUT("1 1 ")BR;
		OUT("1 1 ")BR;
		return 0;
	}
	
	int k;
	bool ok = false;
	REP(i, MAX_N) {
		if (2 * n == i * (i - 1)) {
			ok = true;
			k = i;
			break;
		}
	}
	if (!ok) {
		OUT("No")BR;
		return 0;
	}

	int last = 2;
	
	vector< vector< int > > ans;
	ans.push_back(vector< int >{1, 2});
	ans.push_back(vector< int >{2, 3});
	ans.push_back(vector< int >{3, 1});

	
	for (int range = 2; range < k - 1; range++) {
		last += range;
		vector< int > tmp;
		// debug(range);
		REP(j, range) {
			tmp.push_back(j + last);
		}
		// 新しい部分の追加
		ans.push_back(tmp);

		// last = 4
		REP(j, ans.size()) {
			ans[j].push_back(j + last - 1 + (j < ans.size() - 1 ? 1 : 0));
		}

	}

	OUT("Yes")BR;
	OUT(ans.size())BR;
	// debug(k);
	REP(i, ans.size()) {
		OUT(ans[i].size());
		SP;
		REP(j, ans[i].size()) {
			OUT(ans[i][j])SP;
		}
		BR;
	}

	
  return 0;
}
