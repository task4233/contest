// ------------------------------------
// Date:2018/ 4/30
// Problem:Recursive Queries / b.cpp
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
const int MAX_N = 1e6 + 1;

int cnt[10][MAX_N];
int f[MAX_N];
int g[MAX_N];

int main()
{

  REP(i, MAX_N) {
    int x = i;
    int tmp = 1;
    while(x > 0) {
      int t = x % 10;
      x /= 10;
      if (t > 0) tmp *= t;
    }
    
    f[i] = tmp;
  }
  
  REP(i, MAX_N) {
    if (i < 10) g[i] = i;
    else g[i] = g[f[i]];
  }

  REP(i, 10) {
    REP(j, MAX_N) {
      cnt[i][j + 1] = cnt[i][j] + (i == g[j + 1] ? 1 : 0);
    }
  }

  /*
  REP(i, 10) {
    REP(j, 100) {
      debug(cnt[i][j]);
    }
    cout << endl;
  }
  */

  int Q;
  scanf("%d", &Q);
  while(Q--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);

    int ans = cnt[k][r] - cnt[k][l - 1];
    printf("%d\n", ans);
  }
  
  return 0;
}

