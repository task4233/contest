// ------------------------------------
// Date:2018/ 4/28
// Problem:/ / / a.cpp
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

int N;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< ll > sum(N + 1, 0ll);
  REP(i, N) {
    LCIN(a);
    if (i > 0) sum[i + 1] = sum[i] + a;
    else sum[i + 1] = a;
  }

  sort(ALL(sum));

  ll ans = 0ll;
  ll last = sum[0];
  ll tmp = 1ll;

  
  FOR(i, 1, N + 1) {
    // debug(sum[i]);
    if (sum[i] != last) {
      // OK(true);
      // debug(tmp);
      ans += tmp * (tmp - 1) / 2;
      last = sum[i];
      tmp = 0ll;
    }
    tmp++;
  }
  if (tmp > 1) ans += tmp * (tmp - 1) / 2;

  cout << ans << endl;
  
  return 0;
}

