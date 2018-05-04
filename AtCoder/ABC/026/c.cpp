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
const int MAX_N = 21;

int N;
int e[MAX_N][MAX_N];
int cost[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(cost, 0, sizeof(cost));
  
  cin >> N;
  FOR(i, 1, N) {
    CIN(b); b--;
    e[i][b] = e[b][i] = 1;
  }

  RREP(i, N) {
    int mx = 0;
    int mn = INF;
    FOR(j, i, N) {
      int tmp = 0;
      if (e[i][j]) {
	// debug(j);
	// debug(cost[j]);
	tmp = cost[j];
	mx = max(mx, tmp);
	mn = min(mn, tmp);
      }
      // debug(mx);
      // debug(mn);
    }
    if (mn == INF) mn = 0;
    cost[i] = mx + mn + 1;
  }

  int ans = cost[0];
  /*
  REP(i, N) {
    REP(j, N) {
      cout << e[i][j] << " ";
    }
    cout << endl;
  }
  
  REP(i, N) {
    debug(cost[i]);
  }
  */
  cout << ans << endl;

  return 0;
}

