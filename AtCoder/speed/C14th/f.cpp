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

ll lcm(ll x, ll y)
{
  ll r0, r1, a0, a1, b0, b1, q0, q1, tmp;
  r0 = x; r1 = y;
  a0 = 1; a1 = 0;
  b0 = 0; b1 = 1;
 
  while(r1 > 0) {
    q1 = r0 / r1;
 
    // a2 = a0 - q1 * a1
    tmp = a1;
    // a1 := a2
    a1 = a0 - q1 * a1;
    a0 = tmp;
 
    // b2 = b0 - q1 * b1
    tmp = b1;
    // b1 := b2
    b1 = b0 - q1 * b1;
    b0 = tmp;
 
    // r2 = r0 - q1 * r1
    tmp = r1;
    // r1 := r2
    r1 = r0 - q1 * r1;
    r0 = tmp;
  }
  return (x / r0) * y;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< ll > t(N);
  ll ans;
  REP(i, N) {
    cin >> t[i];
    if (i > 0) ans = lcm(ans, t[i]);
    else ans = t[i];
  }

  cout << ans << endl;
  return 0;
}

