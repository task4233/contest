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
const int MAX_N = 1e3 + 1;

int N, P;

ll memo[MAX_N][MAX_N];

ll nCr(ll n, ll r)
{
  if (r == 0 || n == r) return 1;
  if (memo[n][r] >= 0) return memo[n][r];
  return memo[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int odd, even;
  odd = even = 0;
  memset(memo, -1, sizeof(memo));
  
  cin >> N >> P;
  REP(i, N) {
    CIN(a);
    if (a & 1) odd++;
    else even++;
  }

  ll ans = 0ll;
  
  REP(i, odd + 1) {
    if (i % 2 == P) {
      ans += nCr(odd, i);
    }
  }
  REP(i, even) {
    ans *= 2;
  }
  cout << ans << endl;

  return 0;
}

