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

int N;
ll K;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  vector< ll > s(N);
  ll mn = INF;
  REP(i, N) {
    cin >> s[i];
    mn = min(mn, s[i]);
  }

  if (mn == 0) {
    cout << N << endl;
    return 0;
  }

  if (mn > K) {
    cout << 0 << endl;
    return 0;
  }

    
  ll product = 1ll;
  int ub = 0;
  int ans = 0;
  REP(lb, N) {
    ub = max(ub, lb);
    if (lb > 0) product /= s[lb - 1];
    if (ub == lb) product = s[lb];
    while(ub < N) {
      if (K / product >= s[ub + 1]) {
	ub++;
	product *= s[ub];
      } else {
	// debug(lb)
	// debug(ub);
	// debug(product);
	break;
      }
    }
    ans = max(ans, ub - lb + (ub == N ? 0 : 1));
    // debug(ans);
  }

  cout << ans << endl;

  return 0;
}

