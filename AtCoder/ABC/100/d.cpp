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

int N, M;
// x:綺麗さ/ y:おいしさ/ z:人気度
ll d[3][MAX_N];

// dp[評価基準][みてるとこ][とった数][4]/0 - 2:それぞれの/ 3:合計
ll dp[8][MAX_N][MAX_N][4] = {-1};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  REP(i, N) {
    REP(j, 3) {
      cin >> d[j][i];
    }
  }
  // memset(dp, -1, sizeof(dp));
  REP(i, N) {
    REP(j, M) {
      REP(bit, 8) {
	REP(k, 3) {
	  dp[bit][i][j][k] = 0;
	}
	dp[bit][i][0][3] = 0;
      }
    }
  }
  OK(true);

  ll ans = 0ll;
  // i: 見てるとこ/ j:とった数
  REP(bit, (1 << 3)) {
    // 0: 負/ 1:正
    REP(j, M) {
      REP(i, N) {
	dp[bit][i + 1][j + 1][3] = max(dp[bit][i + 1][j + 1][3], // そこ
				       dp[bit][i][j + 1][3]); // 1つ前
	ll sum = 0ll;
	bool ng = false;
	REP(k, 3) {
	  if ((bit >> k) & 1) {
	    // 正
	    sum += dp[bit][i + 1][j][k] + d[k][i];
	    // dp[bit][i + 1][j + 1][k] = max(dp[bit][i + 1][j + 1][k], // 取らない
	      // 				   dp[bit][i + 1][j][k] + d[k][i]); // とる
	  } else {
	    // 負
	    sum -= dp[bit][i + 1][j][k] + d[k][i];
	    // dp[bit][i + 1][j + 1][k] = min(dp[bit][i + 1][j + 1][k], // 取らない
	    //					   dp[bit][i + 1][j][k] + d[k][i]); // とる
	  }
	  sum += abs(dp[bit][i + 1][j + 1][k]);
	  // if (bit == 8) {
	    // debug(sum);
	  // }
	}
	if (sum > dp[bit][i + 1][j + 1][3]) {
	  REP(k, 3) {
	    dp[bit][i + 1][j + 1][k] = dp[bit][i + 1][j][k] + d[k][i];
	  }
	  dp[bit][i + 1][j + 1][3] = sum;
	}
	// dp[bit][i + 1][j + 1][3] = max(dp[bit][i + 1][j + 1][3],
	// 			       sum);
      }
    }
    debug(dp[bit][N][M][3]);
    ans = max(ans, dp[bit][N][M][3]);
  }

  cout << ans << endl;

  REP(i, N + 1) {
    REP(j, M + 1) {
      cout << dp[7][i][j][3] << " ";
    }
    cout << endl;
  }
  

  return 0;
}

