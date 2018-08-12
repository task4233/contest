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

const ll INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

// 0:a/ 1:ab/ 2:abc/ 3:総数
ll dp[MAX_N][4];
string S;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  dp[0][3] = 1;
  cin >> S;
  REP(i, S.size()) {
    switch(S[i]) {
    case 'A':
      dp[i + 1][0] = dp[i][0] + dp[i][3];
      dp[i + 1][1] = dp[i][1];
      dp[i + 1][2] = dp[i][2];
      dp[i + 1][3] = dp[i][3];
      break;
    case 'B':
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1] + dp[i][0];
      dp[i + 1][2] = dp[i][2];
      dp[i + 1][3] = dp[i][3];
      break;
    case 'C':
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1];
      dp[i + 1][2] = dp[i][2] + dp[i][1];
      dp[i + 1][3] = dp[i][3];
      break;
    case '?':
      dp[i + 1][2] = dp[i][2] * 3 + dp[i][1];
      dp[i + 1][1] = dp[i][1] * 3 + dp[i][0];
      dp[i + 1][0] = dp[i][0] * 3 + dp[i][3];
      dp[i + 1][3] = dp[i][3] * 3;
      break;
    }
    REP(j, 4) {
      dp[i + 1][j] %= MOD;
    }
  }

  cout << dp[S.size()][2] << endl;
  
  return 0;
}

