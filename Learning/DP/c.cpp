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
const int MAX_N = 55;
const int MAX_W = 1e4 + 1;

int W, N, K;

// value, amount
pair< int, int > dp[MAX_N][MAX_N][MAX_W];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> W >> N >> K;
  vector< int > A(N), B(N);
  REP(i, N)
    cin >> A[i] >> B[i];

  memset(dp, -1, sizeof(dp));

  REP(i, N) {
    REP(j, K + 1) {
      RREP(k, W + 1) {
	if (j >= K) {
	  // 超えちゃったとき
	  dp[i + 1][j][k] = max(dp[i + 1][j][k],
				dp[i][j][k]);
	} else {
	  if ()
	}
	  if (j < A[i]) {
	    dp[i + 1][j] = dp[i][j];
	  } else {
	    dp[i + 1][j].first = max(dp[i][j - A[i]].first + B[i],
				     dp[i][j].first);
	  if (dp[i + 1][j - A[i]].first == dp[i][j - A[i]].first + B[i]) {
	    dp[i + 1][j - A[i]].second = dp[i][j - A[i]].second + 1;
	  }
	}
	}
      }
    }
  }

  int ans = 0;
  REP(i, N + 1) {
    if (dp[i][W].second > K) continue;
    ans = max(ans, dp[i][W].first);
    debug(dp[i][W].first);
  }

  cout << ans << endl;
  
  return 0;
}

