#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
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
#define debug(x) cerr << #x << ":" << (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

int a[575][575];

signed main() {
  INIT;

	VAR(int, H, W);
	REP(hi, H) {
		REP(wi, W) {
			cin >> a[hi][wi];
			a[hi][wi] %= 2;
		}
	}

	vector< string > ans;
	REP(hi, H) {
		REP(wi, W) {
			if (wi == W - 1) {
				if (hi < H - 1) {
					if (a[hi][wi] % 2 == 1) {
						string t = to_string(hi + 1) + " ";
						t += to_string(wi + 1) + " ";
						t += to_string(hi + 2) + " ";
						t += to_string(wi + 1);
						ans.push_back(t);
						a[hi + 1][wi]++;
					}
				}
			} else {
				if (a[hi][wi] == 1) {
					string t = to_string(hi + 1) + " ";
					t += to_string(wi + 1) + " ";
					t += to_string(hi + 1) + " ";
					t += to_string(wi + 2);
					ans.push_back(t);
					a[hi][wi + 1]++;
				}
			}
		}
	}

	OUT(ans.size())BR;
	EACH(ai, ans) {
		OUT(ai)BR;
	}

  return 0;
}
