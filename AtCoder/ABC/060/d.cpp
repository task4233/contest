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
const int MAX_N = 575;

// dp[見てるとこ][重さ]
ll dp[MAX_N][MAX_N * MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, W);
  vector< ll > w(N);
  vector< ll > v(N);
  REP(i, N) {
    cin >> w[i] >> v[i];
  }
  vector< ll > diff_w(N);
  REP(i, N) {
    diff_w[i] = w[i] - w[0];
  }

  ll sm = 0;
  // 見ているとこ
  REP(i, N) {
    RREP(j, N) {
      if (j > i) {
	// iまでで作るので
	continue;
      }
      RREP(k, sm + 1) {
	dp[j + 1][k + diff_w[i]] = max(dp[j + 1][k + diff_w[i]],
				       dp[j][k] + v[i]);
      }
    }
    sm += diff_w[i];
  }

  ll ans = 0ll;
  REP(i, N + 1) {
    REP(j, 3 * N) {
      if (w[0] * i + j > W) {
	// 重さがWを超えた時には入れない
	continue;
      }
      debug(dp[i][j]);
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  
  return 0;
}

