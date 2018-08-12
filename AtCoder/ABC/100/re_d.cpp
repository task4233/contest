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

int N, M;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  vector< ll > x(N);
  vector< ll > y(N);
  vector< ll > z(N);
  REP(i, N) {
    cin >> x[i] >> y[i] >> z[i];
  }

  ll ans = 0ll;
  REP(bit, (1 << 3)) {
    vector< ll > d(N);
    REP(i, N) {
      d[i] += (bit & (1 << 0)) ? x[i] : -x[i];
      d[i] += (bit & (1 << 1)) ? y[i] : -y[i];
      d[i] += (bit & (1 << 2)) ? z[i] : -z[i];
    }
    sort(ALL(d));
    reverse(ALL(d));

    ll tmp = 0ll;
    REP(i, M) {
      tmp += d[i];
    }
    ans = max(ans, tmp);
  }

  cout << ans << endl;
  
  

  return 0;
}

