// ------------------------------------
// Date:2018/ 3/31
// Problem:Ice Tea Store 019.cpp
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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long double a[3], d;
  cin >> a[0] >> a[1] >> a[2] >> d;

  a[0] *= 4.0;
  a[1] *= 2.0;
  d /= 2.0;
  CIN(N);

  
  long double t = INF;
  EACH(ai, a)
    t = min(t, ai);

  debug(t);
  ll ans = 0ll;
  if (N & 1) {
    // OK(true);
    // odd number
    if (t <= d) ans = N * t;
    else ans = (int)(N / 2) * d * 2 + t;
  } else {
    // OK(false);
    // even number
    if (t <= d) ans = N * t;
    else ans = N * d;
  }

  cout << ans << endl;

  return 0;
}

