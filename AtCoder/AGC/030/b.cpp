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

int L, n;
int d[MAX_N];


int f(int last,  vector< bool > state) {
	int cnt = 0;
	REP(i, n) {
		if (state[i]) cnt++;
	}
	if (cnt > 0) return 0;



	// right
	int r;
	REP(j, n) {
		if (!state[((last < 0 ? 0 : last)+j)%n]) {
			r = ((last < 0 ? 0 : last)+j)%n;
			break;
			if (j == n-1) r = -1;
		}
	}
	int r_d;
	if (r == -1) r_d = -1;
	else if (last == -1) r_d = d[r];
	else r_d = d[r] - d[last] + (d[r] < d[last] ? L : 0);

	
	// left
	int l;
	RREP(j, n) {
		if (!state[((last < 0 ? 0 : last)+j+n)%n]) {
			l = ((last < 0 ? 0 : last)+j+n)%n;
			break;
		}
		if (j == n-1) l = -1;
	}
	int l_d;
	if (l == -1) l_d = -1;
	else if (last == -1) l_d = L - d[l];
	else l_d = d[last] - d[l] + (d[l] > d[last] ? L : 0);
	debug(l);
	debug(r);
	REP(i, n) {
		OUT(state[i] ? 1:0);
	}
	BR;
	
	int ans = 0;
	if (l_d < 0 && r_d < 0) return 0;
	else if (l_d == r_d) {
		ans += l_d;
		if (f(l, state | (1 << l)) > f(r, state | (1 << r))) {
			state[l] = true;
			last = l;
			ans += f(last, state);
		} else {
			state[r] = true;
			last = r;
			ans += f(last, state);
		}
	} else if (l_d > r_d) {
		ans += l_d;
		state[l] = true;
		last = l;
		ans += f(last, state);
		// debug(l);
	} else {
		ans += r_d;
		state[r] = true;
		last = r;
		ans += f(last, state);
		// debug(r);
	}
	return ans;
}



signed main() {
  INIT;
	cin >> L >> n;
	REP(i, n) {
		cin >> d[i];
	}

	vector< bool > state(n, false);
	int ans = f(-1, state);
	
	/*
	
	vector< bool > state(n, false);
	int ans = 0;
	int last = 0;
	REP(i, n) {
		// right
		int r;
		REP(j, n) {
			if (!state[(last+j)%n]) {
				r = j;
				break;
			}
		}
		int r_d = d[r] - d[last] + (d[r] < d[last] ? L : 0);
		if (i == 0) r_d = d[r];
		
		// left
		int l;
		RREP(j, n) {
			if (!state[(last-j+n)%n]) {
				l = j;
				break;
			}
		}
		int l_d = d[last] - d[l] + (d[l] > d[last] ? L : 0);
		if (i == 0) l_d = L - d[l];

		if (l_d > r_d) {
			ans += l_d;
			state[l] = true;
			last = l;
			// debug(l);
		} else {
			ans += r_d;
			state[r] = true;
			last = r;
			// debug(r);
		}
		debug(r);
		debug(r_d);
		debug(l);
		debug(l_d);
		debug(ans);
		BR;
	}
	*/
							
	OUT(ans)BR;
	
  return 0;
}
