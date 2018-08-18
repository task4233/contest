#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;

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

ll f(ll b, ll n) {
  if (n < b) {
    return n;
  } else {
    return f(b, floor(n / b)) + n % b;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LCIN(N, S);

  if (N == S) {
    cout << N + 1 << endl;
    return 0;
  }

  // b ≦ √n(bが小さい時)
  FOR(bi, 2, sqrt(N) + 1ll) {
    if (f(bi, N) == S) {
      cout << bi << endl;
      return 0;
    }
  }

  ll ans = LINF;
  // b > √n(bが大きい時)
  FOR(pi, 1, sqrt(N - S) + 1ll) {

    // piが約数でない時は適していない
    if (abs(N - S) % pi != 0) {
      continue;
    }

    // n - s = p(b - 1)より、
    // b = (n - s) / pi + 1として表せる
    ll b = (N - S) / pi + 1;

    // 条件(b > √n)を満たしていない時は適していない
    if (b <= sqrt(N)) {
      continue;
    }
    // 解は最小値である
    if (f(b, N) == S) {
      ans = min(ans, b);
    }
  }

  
  if (ans < LINF) {
    cout << ans << endl;
  } else {
    // 最小値が更新されていない時は解なし
    cout << -1 << endl;
  }
  
  return 0;
}

