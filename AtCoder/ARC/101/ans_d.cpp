#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;

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

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

template< class Abel > class BIT {
public:
  BIT() : N(0) {}
  // 以下[1, N]なので+1する必要がある(1-indexed)
  BIT(int n) : N(n), bit(N + 1, 0) {}
  BIT(int n, Abel init) : N(n), bit(N + 1, init) {}

  void add(int i, Abel x) {
    i++;
    // for (int t = ++i; t < N; t += t & -t) bit[t] += x;
    while (i <= N) { bit[i] += x; i += i & -i; }
  }

  Abel sum(int i) {
    Abel res = 0; int t = i;
    while (t > 0) {
      res += bit[t];
      t -= t & -t;
    }
    return res;
  }

  // [i, j)の半開区間
  Abel sum(int i, int j) {
    return sum(j) - sum(i);
  }

private:
  int N;
  vector< Abel > bit;
};

int n;
vector< int > x;

bool check(int mid_n) {
  vector< int > b(n);
  REP(i, n) b[i] = (x[i] >= mid_n) ? 1 : -1;
  
  vector< int > sm(n + 1, n);
  REP(i, n) sm[i + 1] = sm[i] + b[i];
  
  BIT< int > bit(2 * n);
  
  int res = 0;
  RREP(i, n + 1) {
    res += bit.sum(sm[i], 2 * n);
    bit.add(sm[i], 1);
  }
  
  return res >= (n * (n + 1) / 2 + 1) / 2;
}

signed main() {
  INIT;

  cin >> n;
  x.resize(n);
  EACH(xi, x) cin >> xi;
  
  if (n == 1) {
    OUT(x[0])BR;
    return 0;
  }
  
  int ok = 0, ng = 1e9 + 1;
  while (abs(ng - ok) > 1) {
    int mid = (ok + ng) / 2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  OUT(ok)BR;
  return 0;
}
