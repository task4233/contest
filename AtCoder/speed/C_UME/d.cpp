#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Found" : "Nothing") << endl;
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
const int MAX_N = 10;

int N, K;
int T[MAX_N][MAX_N];
bitset< 8 > dp[MAX_N][MAX_N][MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  REP(i, N) {
    REP(j, K) {
      cin >> T[i][j];
    }
  }
  
  REP(i, N) {
    REP(j, N) {
      REP(k, N) {
	dp[i + 1][j][k] = dp[i][j][k] ^ bitset< 8 >(T[i][j]);
      }
    }
  }

  bool ok = false;
  REP(i, N) {
    REP(j, K) {
    if (dp[N][i][j] == bitset< 8 >(0)) ok = true;
    debug(dp[N][i][j]);
    }
  }

  OK(ok);

 
  
  return 0;
}

