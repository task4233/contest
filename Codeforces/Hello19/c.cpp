#include <bits/stdc++.h>

// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 5e5 + 1;

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
	map< int, int > mp;
	int zero = 0;
	REP(ni, n) {
		VAR(string, s);
		int cnt = 0;
		vector< int > sm(s.size()+1, 0);
		REP(si, s.size()) {
			if (s[si] == '(') ++cnt;
			else --cnt;
			sm[si+1] = cnt;
			//debug(sm[si]);
		}

		// 1: inc, -1: dec
		// left
		int left = 0;
		REP(i, sm.size()) {
			if (sm[i] == 0 && sm[i] > sm[i+1]) {
				left = -1;
				break;
			}
		}

		// right
		int right = 0;
		RREP(i, sm.size()) {
			if (sm[sm.size()-1] == sm[i+1] && sm[i] < sm[i+1]) {
				right = -1;
				break;
			}
		}

		//debug(right);
		//debug(left);
		if (right<0 && left<0) continue;
		
		if (cnt == 0) ++zero;
		else mp[cnt]++;
		//debug(cnt);
	}

	int ans = 0;
	EACH(mi, mp) {
		// OUT("mi:" + to_string(mi.first))BR;
		if (mi.first > 0) break;
		if (mp.count(-mi.first)) {
			// OUT(mi.first);
			int tmp = mp[-(mi.first)];
			ans += min(tmp, mi.second);
			//debug(mi.first);
			//debug(mi.second);
			//debug(mp[-(mi.first)]);
		}
	}
	ans += zero / 2;
	OUT(ans)BR;
  
  return 0;
}
