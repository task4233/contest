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

int d[MAX_N];
vector< int > e[MAX_N];

signed main() {
  INIT;
	VAR(int, n);
	map< int, int > mp;
	REP(i, n - 1) {
		VAR(int, a, b);
		a--; b--;
		mp[a]++; mp[b]++;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	vector< int > v;
	int a = 0;
	EACH(mi, mp) {
		if (mi.second > 1) {
			a += (mi.second + 1) / 2;
			v.push_back(mi.first);
		}
	}
	
	auto check = [=](int b) {
		fill_n(d, n, INF);
		
		vector< bool > visited(n, false);
		REP(i, v.size()) {
			visited[v[i]] = true;
		}

		REP(i, n) {
			if (visited[i]) continue;
			queue< int > q;
			q.push(i);
			d[i] = 0;
			while (!q.empty()) {
				int from = q.front(); q.pop();
				EACH(ei, e[from]) {
					if (visited[ei]) continue;
					d[ei] = d[from] + 1;
					q.push(ei);
				}
			}
		}
		
	};
	
	int ng = 0, ok = MAX_N;
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		if (check(mid)) ok = mid;
		else ng = mid;
	}
	OUT(ok)BR;
  return 0;
}
