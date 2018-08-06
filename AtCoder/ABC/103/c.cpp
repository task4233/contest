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

ll f(ll p, ll q) {
  return q ? f(q, p % q) : p;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  vector< ll > a(N);
  REP(i, N)
    cin >> a[i];

  sort(ALL(a), [](ll p, ll q) { return p > q; });

  ll tmp = a[0];
  REP(i, N) {
    tmp = tmp * a[i] / f(tmp, a[i]);
  }
// debug(tmp);

  ll ans = 0ll;
  REP(i, N) {
    ans += tmp - 1ll > a[i] ? (tmp - 1) % a[i] : (tmp - 1);
  }
  cout << ans << endl;
  
       
  return 0;
}

