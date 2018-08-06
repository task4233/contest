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

int F[575][77];
int P[575][77];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  REP(i, N) {
    REP(j, 10) {
      //REP(k, 2) {
	cin >> F[i][j];
	// }
    }
  }
  REP(i, N) {
    REP(j, 10) {
      cin >> P[i][j];
    }
  }

  int ans = -INF;
  FOR(bit, 1, (1 << 10)) {
    int cnt = 0;
    int tmp = 0;
    REP(h, N) {
      int cnt = 0;
      REP(i, 10) {
	if (((bit >> i) & 1) && (F[h][i] == 1)) {
	  cnt++;
	  if (bit == 32)
	    debug(cnt);
	}
      }
      if (bit == 32)
	debug(cnt);
      tmp += P[h + 1][cnt];
      if (bit == 32)
	debug(h);
      //debug(P[h][cnt]);
    }
    // debug(tmp);
    if (tmp == 0)
      debug(bit);
    ans = max(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}

