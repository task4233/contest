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

int N;
int dp[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< int > a(N);
  REP(i, N) {
    cin >> a[i];
  }

  REP(i, N - 1) {
    // debug(i);
    if (i < 1) {
      dp[i + 1] = abs(a[i + 1] - a[i]);
    } else {
      // debug(a[i + 1]);
      // debug(a[i]);
      dp[i + 1] = min(dp[i] + abs(a[i + 1] - a[i]),
		      dp[i - 1] + abs(a[i + 1] - a[i - 1]));
    }
    // debug(dp[i + 1]);
  }

  /*
  REP(i, N + 1) {
    debug(i);
    debug(dp[i]);
    }
  */
  
  cout << dp[N - 1] << endl;

  return 0;
}

