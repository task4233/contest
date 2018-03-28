// ------------------------------------
// Date:2018/ 3/25
// Problem:A - コンテスト a.cpp
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

const int MOD = 1e9 + 7;
const int MAX_N = 1e2 + 1;
const int MAX_SUM = 1e4 + 101;

ll dp[MAX_N][MAX_SUM];


int N;

int main()
{
  scanf("%d", &N);
  vector< ll > p(N);
  REP(i, N) scanf("%d", &p[i]);
  memset(dp, 0, sizeof(dp));
  
  dp[0][0] = 1ll;
  REP(i, N) {
    REP(j, MAX_SUM + 1) {
      if (j < p[i]) {
	dp[i + 1][j] = dp[i][j] > 0 ? 1 : 0;
      } else {
	dp[i + 1][j] = (dp[i][j] > 0 or dp[i][j - p[i]]) ? 1 : 0;
      }
    }
  }

  int ans = 0;
  REP(i, MAX_SUM) {
    debug(dp[N][i]);
    if (dp[N][i] > 0) ans++;
  }

  cout << ans << endl;

  return 0;
}

