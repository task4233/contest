// ------------------------------------
// Date:2018/ 4/ 2
// Problem:C - 柱柱柱柱柱 rere_c.cpp
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

int dp[MAX_N];
int N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< int > a(N);
  REP(i, N)
    cin >> a[i];

  memset(dp, 0, sizeof(dp));
  
  REP(i, N) {
    if (i < 1) dp[i + 1] = dp[i] + abs(a[i + 1] - a[i]);
    else dp[i + 1] = min(dp[i - 1] + abs(a[i + 1] - a[i - 1]),
			 dp[i] + abs(a[i + 1] - a[i]));
  }

  int ans = dp[N - 1];
  cout << ans << endl;


  return 0;
}

