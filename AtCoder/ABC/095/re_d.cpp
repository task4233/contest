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

ll edge[101][101];
int N;
ll C;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> C;
  vector< ll > x(N);
  vector< ll > v(N);
  REP(i, N) {
    cin >> x[i] >> v[i];
    x[i]--; v[i]--;
  }

  REP(from, N) {
    REP(to, N) {
      if (from == to) edge[from][to] = 0;
      edge[from][to] = (min(x[to] - x[from], C + x[from] - x[to])) - v[to];
    }
  }

  REP(i, N) {
    REP(j, N) 
      cout << edge[i][j] << "";
  cout << endl;
  }


  REP(k, N) {
    REP(i, N) {
      REP(j, N) {
	edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
      }
    }
  }

  ll ans = INF;
  REP(i, N) {
    ans = min(ans, edge[0][i]);
  }
  ans *= -1;
  cout << ans << endl;

  REP(i, N) {
    REP(j, N) 
    cout << edge[i][j];
  cout << endl;
  }

  return 0;
}

