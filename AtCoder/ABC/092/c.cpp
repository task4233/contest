// ------------------------------------
// Date:2018/ 3/25
// Problem:_ _ _ c.cpp
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

  CIN(N);
  vector< int > a(N + 1);

  ll sum = 0ll;
  
  FOR(i, 1, N + 1) {
    cin >> a[i];
  }

  a[0] = 0;
  REP(i, N) {
    sum += abs(a[i + 1] - a[i]);
  }
  sum += abs(a[N]);
  // debug(sum);
  
  FOR(i, 1, N + 1) {
    int s = (i - 1) % (N + 1);
    int t = (i) % (N + 1);
    int u = (i + 1) % (N + 1);
    ll ans = sum - abs(a[t] - a[s]) - abs(a[u] - a[t]) + abs(a[u] - a[s]);
    /*
    debug(s);
    debug(t);
    debug(u);
    debug(abs(a[t] - a[s]));
    debug(abs(a[u] - a[t]));
    debug(abs(a[s] - a[u]))
    */
    cout << ans << endl;
  }

  return 0;
}

