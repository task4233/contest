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

signed main() {
  INIT;
  VAR(int,n,k);
  VEC(int,a,k);
  VEC(string,s,n);
  if(n==k){
    OUT("")BR;
    return 0;
  }

  vector<string> res(k);
  int len=INF;
  REP(i,k){
    res[i] = s[a[i]-1];
    s[a[i]-1] = "-1";
    len = min(len,(int)res[i].size());
  }

  vector<string> rest;
  REP(i,n){
    if(s[i]=="-1") continue;
    rest.emplace_back(s[i]);
  }

  int ans = 0;
  REP(i,len){
    bool ok = true;
    REP(j,k-1){
      ok &= res[j][i] == res[j+1][i];
    }
    if(!ok) break;
    ans = i+1;
  }

  if(ans==0){
    OUT("-1")BR;
    return 0;
  }

  string ans_str = res[0].substr(0,ans); 

  bool ok = true;
  EACH(ri,rest){
    ok &= ri.substr(0,ans) != ans_str;
  }

  OUT((ok?ans_str:"-1"))BR;
  
  return 0;
}
