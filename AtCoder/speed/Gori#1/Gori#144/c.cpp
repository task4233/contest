#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
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

int d[55][55];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

signed main() {
  INIT;

	VAR(int, R, C);
	VAR(int, sy, sx);
	VAR(int, gy, gx);
	sy--; sx--; gx--; gy--;
	VEC(string, c, R);

	REP(i, 55) fill_n(d[i], 55, INF);
	
	queue< PAIR > q;
	q.push({sy, sx});
	d[sy][sx] = 0;

	while (!q.empty()) {
		int fx, fy;
		tie(fy, fx)= q.front(); q.pop();

		if (fy == gy && fx == gx) break;
		
		REP(i, 4) {
			int ny = fy + dy[i];
			int nx = fx + dx[i];

			if (!(0 <= ny && ny < R &&
						0 <= nx && nx < C)) continue;

			if (c[ny][nx] == '.' && d[ny][nx] > d[fy][fx] + 1) {
				d[ny][nx] = d[fy][fx] + 1;
				q.push({ny, nx});
			}
		}
	}

	int ans = d[gy][gx] == INF ? -1 : d[gy][gx];
	OUT(ans)BR;
	/*
	REP(i, R) {
		REP(j, C) {
		OUT(d[i][j])SP;
	}
	BR
	}
	*/
	
  
  return 0;
}
