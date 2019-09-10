#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
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
#define RALL(a) (a).rbegin(), (a).rend()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int dps[201010101];
int dpt[201010101];

// O(10^8)
// i文字目以降で最初にjが出現するindex(存在しないときはn)
vector<vector<int> > calcNext(const vector<int> s) {
  int n = s.size();
  vector<vector<int> > res(n+1, vector<int>(101010, n));
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < 101010; ++j) res[i][j] = res[i+1][j];
    res[i][s[i]] = i;
  }
  return res;
}

signed main() {
  INIT;
  VAR(int,n,m);
  VEC(int,s,n);
  VEC(int,t,m);
  REP(i,n) s[i]--;
  REP(i,m) t[i]--;

  vector<vector<int> > nexts = calcNext(s);
  vector<vector<int> > nextt = calcNext(t);

  dps[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 100000; ++j) {
      if (nexts[i][j] >= n) continue; // 次の文字 j がもうない場合はスルー
      (dps[nexts[i][j] + 100000] += dps[i]) %= MOD;
    }
  }

  dpt[0] = 1;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 100000; ++j) {
      if (nextt[i][j] >= m) continue; // 次の文字 j がもうない場合はスルー
      (dpt[nextt[i][j] + 100000] += dpt[i]) %= MOD;
    }
  }

  int ans = 0;
  REP(i,201010101){
    if (dps[i]==0 || dpt[i]==0) continue;
    debug(dps[i]);
    debug(dpt[i]);
    debug(ans);
    (ans += (dps[i]%MOD) * (dpt[i]%MOD) % MOD) %= MOD;
  }
  OUT(ans)BR;
  
  return 0;
}
