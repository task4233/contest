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

  VAR(string, S);
  int N = S.size();
  
  REP(si, N) {
    //  debug(si);
    string tmp = S.substr(si, 5);
    if (tmp == "erase") {
      //debug(S[si + 5]);
      if (si + 5 < N && S[si + 5] == 'r') si++;
      si += 4;
    } else if (tmp == "dream") {
      if (si + 8 < N) {
	string tmp2 = S.substr(si + 5, 3);
	// debug(tmp2);
	if (tmp2 == "era");
	else if (tmp2.substr(0, 2) == "er") si += 2;
      } else if (si + 7 < N) {
	string tmp2 = S.substr(si + 5, 2);
	if (tmp2 == "er") si += 2;
      }
      si += 4;
    } else {
      OUT("NO")BR;
      return 0;
    }
    //debug(si);
  }
  OUT("YES")BR;
  return 0;
}
