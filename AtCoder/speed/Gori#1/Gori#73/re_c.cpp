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
string adversity ="dream",thinking="dreamer",disadvantage="erase",behavior="eraser";
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout <<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<"\n";
#define debug(x) cerr << #x << ":" << (x);BR;

// utility
#define ALL_of(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

signed main() {
  INIT;

  VAR(string, you);

  // just a joke
  // --------------------------------------
  reverse(ALL_of(adversity));
  reverse(ALL_of(thinking));
  reverse(ALL_of(disadvantage));
  reverse(ALL_of(behavior));
  reverse(ALL_of(you));
  // --------------------------------------

  #define _dream (adversity)
  #define _dreamer (thinking)
  #define _erase (disadvantage)
  #define _eraser (behavior)
  #define _s (you)
  
  while (_s.size() > 0) {
    if (_s.substr(0, 5) == _dream || _s.substr(0, 5) == _erase) _s.erase(0, 5);
    else if (_s.substr(0, 6) == _eraser) _s.erase(0, 6);
    else if (_s.substr(0, 7) == _dreamer) _s.erase(0, 7);
    else break;
  }

  if (_s.empty()) OUT("YES")
  else OUT("NO")
  BR;
  
  return 0;
}
