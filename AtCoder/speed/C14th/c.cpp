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
const int MAX_N = 2e5 + 1;
const ll LINF = 1e18 + 1;

int N;
ll sum[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< ll > a(N);
  REP(i, N) {
    cin >> a[i];
  }

  memset(sum, 0, sizeof(sum));
  REP(i, N) {
    if (i > 0) sum[i] = sum[i - 1] + a[i];
    else sum[i] = a[i];
    //  debug(sum[i]);
  }

  ll ans = LINF ;
  REP(i, N - 1) {
    ans = min(ans, abs((sum[N - 1] - sum[i]) - sum[i]));
  }

  cout << ans << endl;

  return 0;
}

