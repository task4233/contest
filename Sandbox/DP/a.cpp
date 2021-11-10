// ------------------------------------
// Date:2018/ 5/10
// Problem:0-1 knapsack problem a.cpp
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
const int MAX_N = 1e2 + 1;
const int MAX_W = 1e4 + 1;

int N, W;

int dp[MAX_N][MAX_W];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> W;
  vector< int > v(N), w(N);
  REP(i, N)
    cin >> v[i] >> w[i];
  
  
  REP(i, N) {
    REP(j, W + 1) {
      if (j < w[i]) dp[i + 1][j] = dp[i][j];
      else dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
    }
  }

  int ans = dp[N][W];

  cout << ans << endl;
  
  return 0;
}

