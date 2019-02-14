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
	VAR(string, s);
	VAR(int, n);

	int cnt = 0, last = -1;
	REP(si, s.size()) {
		if (s[si] == '*') last = si;
		else if (s[si] == '?' || s[si] == '*') {
			--cnt;
			continue;
		}
		
		++cnt;
	}
	if (cnt > n) {
		OUT("Impossible")BR;
		return 0;
	}
	//debug(last);
	debug(cnt);
	string ans = "";
	if (last > -1) {
		REP(si, s.size()) {
			if (si+1 == last)  {
				ans += string(min(n-cnt, 5LL), s[si]);
				//OUT(string(min(n-cnt, 5LL), s[si]));
				++si;
				cnt += min(n-cnt, 5LL);
				debug(cnt);
			}
			else if (s[si+1] == '?' || s[si+1] == '*') {
				++si;
				continue;
			}else ans += s[si];//OUT(s[si]);
		}
		BR;
		return 0;
	} else {
		REP(si, s.size()) {
			if (s[si+1] == '?' || s[si+1] == '*') {
				if (cnt < n) {
					ans += s[si];//OUT(s[si]);
					++cnt;
				}
				++si;
				continue;
			} else ans += s[si];//OUT(s[si]);
		}
		BR;
		return 0;
	}
	if (ans == "" || ans.size() != n) ans = "Impossible";
	OUT(ans)BR;
	
  return 0;
}
