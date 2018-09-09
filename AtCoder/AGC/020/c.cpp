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
#define FOUT(n, dist) cout <<fixed<<setprecision(n)<<(dist);
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

signed main() {
  INIT;

  VAR(int, n);
  VEC(int, a, n);

  int sm = 0;
  REP(i, n) sm += a[i];

  // dp[i]:=i番目までの要素を使って要素をjに出来る時は下j桁目が1になって居るビット列
  bitset< 2020 * 2020 > dp;
  dp.set(0);
  REP(i, n) {
    bitset< 2020 * 2020 > pd;
    // 前の要素をもらってくる
    pd |= dp;
    // 前の要素のA[i]ずらしたものを上書き
    pd |= dp << a[i];
    // dpの遷移
    swap(dp, pd);
  }

  // 半分以上の要素から選んで最小のものが答え
  FOR(i, (sm + 1) / 2, 2020 * 2020) {
    // bitsetのアクセスは配列のように行える
    if (dp[i]) {
      OUT(i)BR;
      return 0;
    }
  }
  
  return 0;
}
