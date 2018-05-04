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
const int MAX_N = 1e2 + 1;

int N, M;

int e[MAX_N][MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, MAX_N)
    REP(j, MAX_N)
    if (i == j) e[i][j] == 0;
    else e[i][j] = INF;
  
  cin >> N >> M;
  vector< int > a(M);
  vector< int > b(M);
  vector< int > c(M);
  REP(i, M) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
    e[a[i]][b[i]] = e[b[i]][a[i]] = c[i];
  }

  

  REP(k, N) {
    REP(i, N) {
      REP(j, N) {
	e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
      }
    }
  }

  int ans = 0;
  REP(i, M) {
    if (e[a[i]][b[i]] < c[i]) ans++;
  }

  cout << ans << endl;
  return 0;
}

