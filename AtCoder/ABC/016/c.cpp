
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
const int MAX_N = 11;

int N, M;
int e[MAX_N][MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  REP(i, N) {
    fill_n(e[i], MAX_N, INF);
    e[i][i] = 0;
  }
  
  vector< int > a(M);
  vector< int > b(M);
  REP(i, M) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    e[a[i]][b[i]] = e[b[i]][a[i]] = 1;
  }
  
  REP(k, N) {
    REP(i, N) {
      REP(j, N) {
	e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
      }
    }
  }

  REP(i, N) {
    int ans = 0;
    REP(j, N) {
      // if (i == j) continue;
      if (e[i][j] == 2) ans++;
      // debug(e[i][j]);
    }
    cout << ans << endl;
  }
  

  return 0;
}

