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
const int MAX_A = 1e4 + 1;

int N, A;
bool dp[MAX_N][MAX_A];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> A;
  vector< int > a(N);
  REP(i, N)
    cin >> a[i];

  dp[0][0] = true;
  
  REP(i, N) {
    REP(j, A + 1) {
      dp[i + 1][j] |= dp[i][j];
      if (j >= a[i]) dp[i + 1][j] |= dp[i][j - a[i]];

      /*
      if (j + a[i] <= A) {
	dp[i + 1][j + a[i]] |= dp[i][j];
      }
      */
      /*
      if (dp[i][j]) {
	dp[i + 1][j] = true;
	if (j + a[i] <= A)
	  dp[i + 1][j + a[i]] = true;
      }
      */
    }
  }

  bool ok = dp[N][A];

  /*
  REP(i, N + 1) {
    if (dp[i][A]) ok = true;
  }
  */

  OK(ok);
  
  

  return 0;
}

