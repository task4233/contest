// ------------------------------------
// Date:2018/ 3/24
// Problem:Katana Thrower _ re_d.cpp
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

int main()
{
  LCIN(N, H);
  vector< pair< ll, ll > > d(N);
  ll aMax = 0;
  REP(i, N) {
    scanf("%d %d", &d[i].first, &d[i].second);
    aMax = max(aMax, d[i].first);
  }

  sort(ALL(d), [](pair< ll, ll > x, pair< ll, ll > y) {
      return x.second > y.second;
  });

  ll ans = 0ll;
  ll sum = 0ll;
  REP(i, 1e9) {
    if (sum >= H) break;
    if (d[i].second > aMax) {
      sum += d[i].second;
      ans++;
    } else {
      ans += (H - sum) / aMax + ((H - sum) % aMax == 0?0:1);
      break;
    }
    //  debug(sum);
    // debug(ans);
  }

  cout << ans << endl;

  return 0;
}

