// ------------------------------------
// Date:2018/ 3/21
// Problem:A- Multiple Array a.cpp
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

static const int MOD = 1e9 + 7;
static const int MAX_N = 1;

typedef pair< ll, ll > PL;

int main()
{
  CIN(N);
  vector< PL > a(N);
  REP(i, N) {
    LCIN(p, q);
    a[i] = make_pair(q - (p + q) % q, q);
  }
  
  ll ans = 0ll;
  ll bias = 0;
  RREP(i, N) {
    ll tmp;
    if (a[i].second == 1) {
      // OK(true);
      tmp = 0;
    } else if ((((a[i].first - bias) % a[i].second + a[i].second) % a[i].second) == 0) {
      // OK(false);
      tmp = 0;
    } else tmp = ((a[i].first - bias) % a[i].second + a[i].second) % a[i].second;
    ans += tmp;
    bias += tmp;
    // debug(ans);
    // debug(tmp);
  }

  cout << ans << endl;
  return 0;
}

