w// ------------------------------------
// Date:2018/ 3/25
// Problem:_ _ _ d.cpp
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
const int MAX_N = 1e5 + 1;

int a, b;

char g[100][100];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 50) {
    REP(j, 100) {
      g[i][j] = '.';
    }
  }
  FOR(i, 50, 100) {
    REP(j, 100) {
      g[i][j] = '#';
    }
  }

  /*
    cout << "100 100" << endl;
  REP(i, 100) {
    REP(j, 100) {
      cout << g[i][j];
    }
    cout << endl;
  }
  */
  
  cin >> a >> b;
  
  REP(h, a - 1) {
    int hi, wi;
    hi = 98 - h / 50 * 2;
    wi = (h % 50) * 2 + (hi & 1 ? 0 : 1);
    g[hi][wi] = '.';
  }

  REP(h, b - 1){
    int hi, wi;
    hi = h / 50 * 2 + 1;
    wi = (h % 50) * 2 + (hi & 1 ? 1 : 0);
    g[hi][wi] = '#';
  }

  cout << "100 100" << endl;
  REP(i, 100) {
    REP(j, 100) {
      cout << g[i][j];
    }
    cout << endl;
  }
  
  return 0;
}

