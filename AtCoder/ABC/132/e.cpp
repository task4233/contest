#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
using PAIR = pair<int64, int64>;
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

vector<int> e[MAX_N];
int d[MAX_N];
int s[MAX_N];
int f[MAX_N];
vector<int> re[MAX_N];
int rd[MAX_N];
int rs[MAX_N];

signed main() {
  INIT;
  VAR(int,n,m);
  REP(i,m){
    VAR(int,u,v);
    --u; --v;
    e[u].push_back(v);
    re[v].push_back(u);
  }
  VAR(int,st,gl);
  --st; --gl;

  memset(s,-1,sizeof(s));
  s[st] = 0;
  d[st] = 0;
  queue<int> q;
  q.push(st);
  while(!q.empty()){
    int fr = q.front(); q.pop();

    EACH(to, e[fr]){
      if (s[to] == 3) continue;

      if (s[to] != -1){
        if (s[to]==s[fr]) continue;
        // 平路完成
        f[to] = abs(s[to]-s[fr]) * (d[to] - d[fr] + 1);
        s[to] = 3;
        q.push(to);
        continue;
      }

      s[to] = (s[fr]+1)%3;
      d[to] = d[fr] + 1;
      q.push(to);
    }
  }

  // 到達しない
  if (s[gl]==-1){
    OUT(-1)BR;
    return 0;
  }

  memset(rs,-1,sizeof(rs));
  rs[gl] = 0;
  rd[gl] = 0;
  queue<int> rq;
  swap(q,rq);
  q.push(gl);
  while(!q.empty()){
    int fr = q.front(); q.pop();

    EACH(to, re[fr]){
      if (rs[to] == 3) continue;

      if (rs[to] != -1){
        continue;
      }

      rs[to] = (rs[fr]+1)%3;
      rd[to] = rd[fr] + 1;
      q.push(to);
    }
  }

  int fff = INF;
  REP(i,n){
    if (rs[i] < 0) continue;
    fff = min(f[i], fff);
  }
  
  int ans = rd[st] + (int)abs(rs[gl]-rs[st])*fff;
  OUT(ans)BR;


  
  
  return 0;
}
