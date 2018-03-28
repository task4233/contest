// ------------------------------------
// Date:2018/ 3/24
// Problem:B- Contiguous Repainting b.cpp
//
// ------------------------------------

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

static const int INF = 1e9 + 1;
static const int MAX_N = 1;

int main()
{
  CIN(N, K);
  vector< ll > t(N + 1, 0ll);
  // 全体の累積和
  vector< ll > a(N + 1, 0ll);
  // 正の数字だけを取った時の累積和
  vector< ll > b(N + 1, 0ll);
  REP(i, N) {
    cin >> t[i + 1];
    a[i + 1] = a[i] + t[i + 1];
    b[i + 1] = b[i] + max(0ll, t[i + 1]);
  }

  /*
  REP(i, N) {
    printf("a[%d] = %d\nb[%d] = %d\n", i + 1, a[i + 1], i + 1, b[i + 1]);
  }
  */

  ll ans = -INF;

  // a[i + 1]: i番目までの累積和
  REP(i, N - K + 1) {
    ll sum = 0ll;
    // [i, i + K] = [0, i + K - 1] - [0, i - 1] = a[i + K] - a[i];
    ll tmp = a[i + K] - a[i];

    sum += max(0ll, tmp);
    // [0, i - 1] = [0, i - 2] = b[i - 1];
    sum += b[i];
    // [i + K, N] = [0, N + 1 - 1] - [0, i + K + 1 - 1] = b[N] - b[i + K] 
    sum += b[N] - b[i + K];
    ans = max(ans, sum);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}

