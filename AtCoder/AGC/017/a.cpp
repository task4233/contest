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
const int MAX_N = 55;

int n, P;
ll fact[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll odd, even, ans;
  odd = even = ans = 0ll;
  
  cin >> n >> P;
  fact[1] = fact[0] = 1ll;

  REP(i, 50) {
    fact[i + 2] = fact[i + 1] * (i + 2);
  }
  
  REP(i, n) {
    CIN(a);
    if (a & 1) odd++;
    else even++;
  }
  debug(odd);
  debug(even);

  if (P == 0) {
    ans++;
    FOR(i, 1, odd + 1) {
      if (!(i & 1)) ans += fact[n] / (fact[n - i] * fact[i]) * (even + 1);
      debug(ans);
    }
  } else {
    FOR(i, 1, odd + 1) {
      if (i & 1) ans += fact[n] / (fact[n - i] * fact[i]) * (even + 1);
    }
  }

  cout << ans << endl;
  
  return 0;
}

