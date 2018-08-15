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

const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LCIN(N, S);
  vector< int > a(N);
  REP(i, N) {
    cin >> a[i];
  }

  int ub = 0;
  ll ans = LINF;
  ll sm = 0ll;
  REP(lb, N) {
    while (ub < N) {
      if (sm + a[ub] >= S) {
	break;
      }
      sm += a[ub++];
    }
    if (ub == N) break;
    if (sm + a[ub] >= S) {
      ans = min(ans, (ub >= N ? N - 1 : ub) - lb + 1ll);
    }

    /*
    debug(lb);
    debug(ub);
    debug(sm);
    debug(ans);
    */
    sm -= a[lb];
    // cout << endl;
  }
  if (ans == LINF) ans = 0;
  cout << ans << endl;

  

  return 0;
}

