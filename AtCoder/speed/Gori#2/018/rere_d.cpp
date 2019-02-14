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

template< class Abel > class RMQ {
public:
  RMQ(int _n) {
    init(_n);
  }

  void init(int _n) {
    N = 1;
    while (N < _n) {
      // 頂点数を2のべき乗にする
      N <<= 1;
    }
    d.resize(2 * N - 1);
    for (int i = 0; i < 2 * N - 1; ++i) {
      d[i] = INF;
    }
  }

  void update(int k, Abel a) {
    // kの位置を葉まで移動
    k += N - 1;
    d[k] = a;
    // 頂点まで値を更新する
    while (k > 0) {
      k = (k - 1) / 2;
      d[k] = min(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }

  // 呼び出しは[a, b)の!!!半開区間!!!
  Abel _query(int _a, int _b) {
    return query(_a, _b, 0, 0, N);
  }
  
  
private:
  int N;
  vector< Abel > d;

  // 呼び出しでミスをする可能性があるので、privateにしておく
  Abel query(int a, int b, int k, int l, int r) {
    // [a, b)に対して、[l, r)が範囲として成立していない
    if (!(a < r && l < b)) return INF;
    
    // [a, b)が[l, r)を完全にカバーしている(queryを再帰的に呼び出しても範囲は狭まるだけ)
    if (a <= l && r <= b) return d[k];
    
    // それ以外の時、葉の2つの子の最小値を再帰的に求める
    Abel vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    Abel vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
  
};

signed main() {
  INIT;
	VAR(int, n);
	RMQ< int > rmq(101010);

	vector< PAIR > d(n);
	REP(i, n) cin >> d[i].first >> d[i].second;

	sort(ALL(d));

	int ans = 0;
	REP(i, n) {
		ans = max(ans, rmq._query(1, d[i].second) + 1);
		rmq.update(d[i].second, rmq._query(1, d[i].second) + 1);
	}
	cout << ans << endl;
  
  return 0;
}
