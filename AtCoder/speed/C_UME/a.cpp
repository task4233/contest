#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "YES" : "NO") << endl;
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
const int MAX_N = 575;

int dp[101][MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector< int > NG(3);
  bool ng = false;
  REP(i, 3) {
    cin >> NG[i];
    if (NG[i] == N) ng = true;
  }

  if (ng) {
    cout << "NO" << endl;
    return 0;
  }

  dp[0][N] = 1;
  
  REP(i, 100) {
    REP(j, MAX_N) {
      if (j > 0) dp[i + 1][j - 1] += dp[i][j];
      if (j > 1) dp[i + 1][j - 2] += dp[i][j];
      if (j > 2) dp[i + 1][j - 3] += dp[i][j];
    }

    REP(j, 3) {
      dp[i + 1][NG[j]] = 0;
    }
  }

  bool ok = false;
  REP(i, 101) {
    // debug(dp[i][0]);
    if (dp[i][0] > 0) ok = true;
  }
  OK(ok);

  

  return 0;
}

