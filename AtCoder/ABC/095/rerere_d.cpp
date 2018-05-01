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

const ll  LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int N;
ll C;
ll lMax[MAX_N];
ll lSum[MAX_N];
ll rSum[MAX_N];

ll solve(vector< ll > x, vector< ll > v)
{
  ll mx = 0ll;
  RREP(i, N) {
    ll sum = v[i + 1] - (C - x[i + 1]);
    lSum[i + 1] = lSum[i + 2] + sum;
    mx = max(mx, lSum[i + 1]);
    lMax[i] = mx;
  }

  mx = 0ll;
  REP(i, N) {
    ll sum = v[i + 1] - x[i + 1] + x[i];
    // debug(v[i + 1]);
    rSum[i + 1] = rSum[i] + sum;
    // debug(sum);
  }

  /*
  REP(i, N + 1) {
    debug(lMax[i]);
    debug(rSum[i]);
  }
  */
  
  ll res = -LINF;
  REP(i, N + 1) {
    ll sum = lMax[i] + rSum[i];
    // debug(i);
    // debug(sum);
    res = max(res, sum - min(x[i], lMax[i]));
  }

  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> C;
  vector< ll > x(N + 2, 0ll);
  vector< ll > v(N + 2, 0ll);
  REP(i, N) {
    cin >> x[i + 1] >> v[i + 1];
  }

  ll ans = solve(x, v);


  /*
  REP(i, N + 2)
    debug(x[i]);
  */

  // 逆転
  reverse(ALL(x));
  REP(i, N + 2) {
    if (x[i] == 0) continue;
    x[i] = C - x[i];
    // x[i] = (x[i] == 0 ? 0 : C - x[i]);
    // debug(x[i]);
  }
  reverse(ALL(v));

  ans = max(solve(x, v), ans);

  cout << ans << endl;

  return 0;
}

