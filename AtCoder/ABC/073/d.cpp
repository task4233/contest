// ------------------------------------
// Date:2018/ 4/ 3
// Problem:D- joisino's travel d.cpp
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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 201;

int N, M, R;

int e[MAX_N][MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M >> R;

  REP(i, N) {
    REP(j, N) {
      if (i == j) e[i][j] = 0;
      else e[i][j] = INF;
    }
  }
  
  vector< int > r(R);
  REP(i, R) {
    cin >> r[i];
    r[i]--;
  }
  sort(ALL(r));

  bool f, t;
  REP(i, M) {
    CIN(a, b, c);
    a--; b--;
    /*
    EACH(ri, r) {
      if (ri == a) f = true;
      if (ri == b) t = true;
    }
    if (!(f && t)) continue; 
    */
    e[a][b] = c;
    e[b][a] = c;
  }

 
  REP(k, N) {
    REP(i, N) {
      REP(j, N) {
	e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
      }
    }
  }

  int ans = INF;
  /*
  REP(i, N) {
    REP(j, N) {
      ans = max(ans, e[i][j]);
    }
  }
  */
  do {
    int tmp = 0;
    REP(i, r.size() - 1) {
      tmp += e[r[i + 1]][r[i]];
    }
    ans = min(ans, tmp);
  } while(next_permutation(ALL(r)));
  
  cout << ans << endl;

  /*
  REP(i, N) {
    REP(j, N) {
      cout << e[i][j];
      if (j != N - 1) cout << " ";
    }
    cout << endl;
  }
  */
    
  return 0;
}

