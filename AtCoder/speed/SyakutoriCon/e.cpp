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
const int MAX_N = 1e5 + 1;

int N, M;

int memo[MAX_N];

int solve(int lb, int ub)
{
  int res = 0;
  FOR(i, lb, ub) {
    
  }
  return memo[ub] = res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  set< int > d;
  vector< int > f(N);
  bool ok = true;
  cin >> N >> M;
  REP(i, N) {
    cin >> f[i];
  }

  reverse(ALL(f));

  int ans = 0;
  int ub = 0;
  
  REP(lb, N) {
    if (lb == ub) {
      d.clear();
    }
    ub = max(lb + 1, ub);
    while (ub < N) {
      if (d.erase(f[ub])) break;
      d.insert(f[ub]);
    }
    (ans += solve(lb, ub)) %= MOD;
  }

  cout << ans << endl;

  return 0;
}

