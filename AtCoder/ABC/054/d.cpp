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
const int MAX_M = 575;
const int MAX_N = 77;

int dp[MAX_N][MAX_M][MAX_M];
// int dpB[MAX_N][MAX_N * MAX_C];

int N, A, B;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> A >> B;
  vector< int > a(N), b(N), c(N);
  REP(i, N)
    cin >> a[i] >> b[i] >> c[i];

  REP(i, MAX_N) {
    REP(j, MAX_M) {
      REP(k, MAX_M) {
	dp[i][j][k] = INF;
      }
    }
  }

  REP(i, MAX_N) {
    dp[i][0][0] = 0;
  }
 
  REP(i, N) {
    REP(j, MAX_M) {
      REP(k, MAX_M) {
	// 入れる時
	dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]],
					    dp[i][j][k] + c[i]);
	// 入れない時
	dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
      }
    }
  }

  int ans = INF;

  FOR(i, 1, MAX_M) {
    int ai = A * i;
    int bi = B * i;
    if (max(ai, bi) >= MAX_M) break;
    ans = min(ans, dp[N][ai][bi]);
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;

  
  
  return 0;
}

