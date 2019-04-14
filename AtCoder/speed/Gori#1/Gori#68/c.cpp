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
const int MAX_N = 55;

ll d[MAX_N][MAX_N][MAX_N * MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, A);
  vector< int > x(N);
  REP(i, N) {
    cin >> x[i];
  }

  ll ans = 0;
  d[0][0][0] = 1;
  REP(i, N) {
    REP(j, N) {
      REP(k, MAX_N * MAX_N) {
	d[i + 1][j + 1][k + x[i]] += d[i][j][k];
	d[i + 1][j][k] += d[i][j][k];
      }
    }
  }

  FOR(i, 1, N + 1) {
    ans += d[N][i][A * i];
    // debug(i);
    // debug(ans);
    // debug(d[N][i][A * i]);
  }
  cout << ans << endl;
  

  return 0;
}

