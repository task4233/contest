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

ll N, K;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  vector< ll > s(N);
  ll mn = INF;
  REP(i, N) {
    cin >> s[i];
    mn = min(s[i], mn);
  }

  if (mn == 0) {
    cout << N << endl;
    return 0;
  }

  if (mn > K) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0ll;
  ll ub = -1;
  ll current = -1;
  REP(lb, N) {
    ub = max((ll)lb, ub);
    if (lb == 0) current = s[lb];
    else {
      current /= s[lb - 1];
    }

    if (lb == ub) current = s[lb];
    while(ub < N) {
      debug(current);
      debug(lb);
      debug(ub);
      if (K / current >= s[ub + 1]) {
	ub++;
	current *= s[ub];
      } else break;
    }
    // debug(lb);
    // debug(ub);
    // OK(true);
    ans = max(ans, (ll)(ub - lb + (ub == N ? 0 : 1)));
    debug(ans);
  }

  cout << ans << endl;

  return 0;
}

