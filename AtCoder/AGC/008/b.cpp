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
  vector< int > a(N);
  vector< bool > state(N, false);
  REP(i, N) cin >> a[i];

  ll ans = 0ll;
  REP(i, N - K + 1) {
    bool ok = false;
    REP(j, K) {
      if (a[i + j] > 0) ok = true;
    }
    if (!ok) {
      REP(j, K) {
	// debug(a[i + j]);
	a[i + j] = INF;
      }
    }
  }
  
  REP(i, N - K + 1) {
    if (a[i] > 0) {
      REP(j, K) {
	state[i + j] = true;
      }
    } else {
      REP(j, K) {
	state[i + j] = false;
      }
    }
  }

  REP(i, N) {
    // debug(a[i]);
    // OK(state[i]);
    if (state[i] and a[i] != INF) ans += a[i];
  }
  printf("%lld\n", ans);
  
  return 0;
}

