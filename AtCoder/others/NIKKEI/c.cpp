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

// aがiをたべるとa[i],
// bがiを食べるとb[i]
// 「最終的に自分が得る幸福度の総和」から「最終的に相手が得る幸福度の総和」を最大化
// Aは,
// A[i] < B[i]となるものをとりたい?
// 全て同じな場合, 大きいものからとりたい?
// max(A[i]) - B[i]と, max(B[j]) - A[j]を考えて大きい方を取る?


struct P {
	// diffはa-b
	int a, b, diff;
};
vector< P > dat_a;

signed main() {
  INIT;
	VAR(int, n);
	vector< int > a(n), b(n);
	int mn, t;
	REP(i, n) {
		cin >> a[i] >> b[i];
		if (mn > a[i]) {
			mn = a[i];
			t = i;
		} else if (mn == a[i]) {
			if (b[t] > b[i]) {
				mn = a[i];
				t = i;
			}
		}
	}

	REP(i, n) {
		if (n%2 == 1 && i == t) continue;
		dat_a.push_back(P{a[i],b[i],a[i]-b[i]});
	}

	sort(ALL(dat_a), [](P p1, P p2){ if (p1.diff == p2.diff) return p1.a > p2.a; return p1.diff < p2.diff;});

	int ans = 0;
	if (n%2==1) {
		ans += a[t];
		REP(i, dat_a.size()/2) {
			ans += dat_a[i].a;
			ans -= dat_a[dat_a.size()-1-i].b;
		}
	} else {
		REP(i, n/2) {
			ans += dat_a[i].a;
			ans -= dat_a[n-1-i].b;
		}
	}
	cout << ans << endl;
  
  return 0;
}
