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

int N;
ll C;

ll rSum[MAX_N];
ll lSum[MAX_N];
ll lMax[MAX_N];

ll solve(vector< ll > x, vector< ll > v)
{
  // 原点から右方向に進んだ時の、摂取できるカロリーの累積和を求める
  REP(i, N) {
    if (i > 0) rSum[i] = rSum[i - 1] + v[i];
    else rSum[i] = v[i];
  }

  // 原点から左方向に進んだ時の、摂取できるカロリーと消費するカロリーの差の最大値を求める
  // mxは原点から左方向に進んだ時に得られる最大のカロリー
  ll mx = 0ll;
  RREP(i, N) {
    ll cal = (i < N - 1 ? x[i + 1] - x[i] : C - x[i]);
    if (i < N - 1) lSum[i] = lSum[i + 1] + v[i] - cal;
    else lSum[i] = v[i] - cal;
    mx = max(mx, lSum[i]);
    lMax[i] = mx;
  }

  // 右に行く範囲を大きくしていって、最大値を求める
  ll res = 0ll;
  REP(ub, N) {
    ll sum = 0ll;

    // printf("ub = %d\n", ub);
    
    sum -= x[ub];
    // debug(sum);
    sum += rSum[ub];

    // 左に戻らずに出る場合
    res = max(res, sum);

    sum -= x[ub];
    // debug(sum);

    if (ub < N - 1) sum += lMax[ub + 1];

    // printf("sum = %ld\n", sum);
    // printf("res = %ld\n", res);
    res = max(res, sum);
  }
  // cout << endl;

  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> C;
  vector< ll > x(N);
  vector< ll > v(N);
  REP(i, N) {
    cin >> x[i] >> v[i];
  }

  ll ans = solve(x, v);

  reverse(ALL(x));
  REP(i, N) {
    x[i] = C - x[i];
  }
  reverse(ALL(v));

  ans = max(ans, solve(x, v));

  cout << ans << endl;
  
  return 0;
}

