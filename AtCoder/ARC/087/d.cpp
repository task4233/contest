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
// #define int int64
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

  VAR(string, s);
  VAR(int, x, y);
  int N = s.size();

  bitset< 2 * 8000 > dpx;
  bitset< 2 * 8000 > dpy;
  int cnt = 0, first = 0;
  while (s[first++] == 'F');
  dpx[8000 + --first] = dpy[8000] = 1;

  bool isX = true;
  FOR(i, first, N) {
    if (s[i] == 'F') cnt++;
    if (s[i] == 'T' || i == N - 1) {
      bitset< 2 * 8000 > pd;
      if (isX) {
	pd = (dpx << cnt) | (dpx >> cnt);
	swap(dpx, pd);
      } else {
	pd = (dpy >> cnt) | (dpy << cnt);
	swap(dpy, pd);
      }
      isX = !isX;
      cnt = 0;
    }
  }

  if (dpx[x + 8000] && dpy[y + 8000]) OUT("Yes")
  else OUT("No");
  BR;
  return 0;
}
