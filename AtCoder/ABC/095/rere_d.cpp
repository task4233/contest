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
const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int N;
ll C;
ll asc[MAX_N];
ll desc[MAX_N];
ll dX[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> C;
  vector< ll > x(N + 1, 0ll);
  vector< ll > v(N + 1, 0ll);
  REP(i, N) {
    cin >> x[i + 1] >> v[i + 1];
  }
  
  REP(i, N) {
    asc[i + 1] = asc[i] + v[i + 1];
  }

  RREP(i, N) {
    desc[i] = desc[i + 1] + v[i + 1];
  }

  REP(i, N + 1) {
    debug(asc[i]);
  }
  REP(i, N + 1) {
    debug(desc[i]);
  }

  ll ans = -LINF;
  int d = 0;
  REP(ub, N) {
    debug(ub);
    FOR(d, 1, N + 1) {
      debug(d);
      ll lr = abs(2 * x[ub] + (C - x[ub + d]));
      ll rl = abs(2 * (C - x[ub + d]) + x[ub]);
      ll tmp = asc[ub] + desc[(ub + d > N ? ub + d - N + 1 : ub + d - 1)] - min(lr, rl);
      
      // if (ans > tmp) break;
      debug(lr);
      debug(rl);
      debug(asc[ub]);
      debug(desc[(ub + d > N ? ub + d - N + 1 : ub + d - 1)]);
      ans = max(ans, tmp);
      debug(tmp);
      cout << endl;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}

