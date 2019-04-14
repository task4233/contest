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

int d[55][55];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

signed main() {
  INIT;
	VAR(int, H, W);
	vector< string > s(H);
	REP(hi, H) {
		cin >> s[hi];
	}

	REP(hi, H) REP(wi, W) d[hi][wi] = INF;
	
	queue< PAIR > q;
	q.push({0, 0});
	d[0][0] = 0;

	while (!q.empty()) {
		int fx, fy;
		tie(fy, fx)= q.front(); q.pop();

		REP(i, 4) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];

			if (!(0 <= nx && nx < W &&
						0 <= ny && ny < H) || s[ny][nx] == '#') continue;
			
			if (d[ny][nx] > d[fy][fx] + 1) {
				
				d[ny][nx] = d[fy][fx] + 1;
				q.push({ny, nx});
			}
		}
		
	}
	
	if (d[H - 1][W - 1] == INF) {
		OUT(-1)BR;
		return 0;
	}
	
	
	int ans = H * W - d[H - 1][W - 1] - 1;
	REP(hi, H) {
		REP(wi, W) {
			// OUT(d[hi][wi])SP;
			if (s[hi][wi] == '#') ans--;
		}
		// BR;
	}
	OUT(ans)BR;
	
	
  return 0;
}
