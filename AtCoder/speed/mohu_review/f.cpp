// ------------------------------------
// Date:2018/ 4/ 3
// Problem:Hashira _ ] f.cpp
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
const int MAX_N = 1e5 + 1;

int N;

int dp[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> N;

  fill_n(dp, N, 0);
  
  vector< int > a(N);
  REP(i, N)
    cin >> a[i];


  REP(i, N) {
    if (i > 1) {
      dp[i] += min(dp[i - 1] + abs(a[i] - a[i - 1]),
		   dp[i - 2] + abs(a[i] - a[i - 2]));
    } else if (i > 0){
      dp[i] += dp[i - 1] + abs(a[i] - a[i - 1]);
    }
  }

  int ans = dp[N - 1];
  cout << ans << endl;
  
  /*
  REP(i, N) {
    debug(dp[i]);
  }
  */

  return 0;
}

