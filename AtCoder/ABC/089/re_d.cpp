#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 333;

int H, W, D;

pair< int, int > d[MAX_N * MAX_N];
int memo[MAX_N * MAX_N];

ll dfs(int x)
{
  if (memo[x] > -1) return memo[x];
  if (x<D) return 0ll;
  
  ll res = 0ll;
  res += abs(d[x].first - d[x-D].first);
  res += abs(d[x].second - d[x-D].second);
  
  res += dfs(x-D);

  return memo[x] = res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(memo, -1, sizeof(memo));
  
  cin >> H >> W >> D;
  REP(hi, H) {
    REP(wi, W) {
      CIN(a); a--;
      d[a] = make_pair(hi, wi);
    }
  }

  ll ans = 0ll;
  CIN(Q);
  REP(i, Q) {
    CIN(l, r);
    l--; r--;
    ans = dfs(r) - dfs(l);
    cout << ans << endl;
  }

  return 0;
}

