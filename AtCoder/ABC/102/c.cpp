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

ll N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< ll > a(N);
  REP(i, N) {
    cin >> a[i];
  }

  ll sum = 0ll;
  vector< ll > tmpN(N);
  REP(i, N) {
    tmpN[i] = a[i] - i - 1;
    sum += abs(tmpN[i]);
  }
  sort(ALL(tmpN));
  ll cnt = 0;
  REP(i, N) {
    if (tmpN[i] < 0) cnt++;
    else break;
  }

  ll ans = sum;
  REP(i, N - 1) {
    if (tmpN[i + 1] == tmpN[i]) continue;
    ll tmp = lower_bound(ALL(tmpN), tmpN[i]) - tmpN.begin();
    ll tmp2 = sum;
    tmp2 -= min(tmp, cnt);
    tmp2 += max(N - tmp, cnt);
    // REP(j, tmpN.size()) {
      
      // tmp += abs(tmpN[j] - tmpN[i]);
    // }
    ans = min(tmp2, ans);
    debug(i);
    debug(tmp);
    debug(ans);
  }
  
  cout << ans << endl;
  
  return 0;
}

