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
#define BR cout<<endl;
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

string angles[16] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};

signed main() {
  INIT;
	VAR(double, deg, dis);

	deg *= 10;
	int ans_angle = 0;
	for (int angle = 1125, ans = 0; angle <= 34875; angle += 2250, ans++) {
		if ((int)deg < angle) {
			ans_angle = ans;
			break;
		}
		// debug(angle);
	}

	// debug(ans_angle);
	//debug(angles[ans_angle]);

	dis /= 60.0;
	// debug(dis);
	int ans_wind = 0;
	if (dis < 0.25) ans_wind = 0;
	else if (dis < 1.55) ans_wind = 1;
	else if (dis < 3.35) ans_wind = 2;
	else if (dis < 5.45) ans_wind = 3;
	else if (dis < 7.95) ans_wind = 4;
	else if (dis < 10.75) ans_wind = 5;
	else if (dis < 13.85) ans_wind = 6;
	else if (dis < 17.15) ans_wind = 7;
	else if (dis < 20.75) ans_wind = 8;
	else if (dis < 24.45) ans_wind = 9;
	else if (dis < 28.45) ans_wind = 10;
	else if (dis < 32.65) ans_wind = 11;
	else ans_wind = 12;

	if (ans_wind == 0) {
		OUT("C 0")BR; 
	} else {
		OUT(angles[ans_angle])SP;OUT(ans_wind)BR;
	}
	
  
  return 0;
}
