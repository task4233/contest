// ------------------------------------
// Date:2018/ 4/ 2
// Problem:D - Wall d.cpp
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
const int MAX_N = 2e2 + 1;

int H, W;
int c[10][10];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W;
  REP(hi, 10)
    REP(wi, 10)
      cin >> c[hi][wi];

  REP(k, 10) {
    REP(i, 10) {
      REP(j, 10) {
	c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }

  ll ans = 0ll;
  REP(hi, H) { 
    REP(wi, W) {
      CIN(a);
      if (a < 0) continue;
      ans += c[a][1];
    }
  }

  cout << ans << endl;
  
  return 0;
}

