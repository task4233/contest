// ------------------------------------
// Date:2018/ 3/17
// Problem:_ _ _ c.cpp
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
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int MOD = 1e9 + 7;
static const int MAX_N = 102;
typedef pair< int, int > PI;

int N;
vector< PI > r;
vector< PI > b;

// memo[今見ている点][残りの頂点数]
int memo[MAX_N][MAX_N];
// state[今見ている点][残りの頂点数][頂点]
int dp[MAX_N][MAX_N];
bool state[MAX_N][MAX_N][MAX_N];


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(state, false, sizeof(state));
  memset(dp, 0, sizeof(dp));
  cin >> N;
  r.resize(N);
  REP(i, N) {
    CIN(x, y);
    r[i] = make_pair(x, y);
  }
  b.resize(N);
  REP(i, N) {
    CIN(x, y);
    b[i] = make_pair(x, y);
  }

  sort(ALL(r), [](PI x, PI y) {
      if (x.first == y.first) return x.second > y.second;
      return x.first < y.first;
  });
  sort(ALL(b), [](PI x, PI y) {
      if (x.first == y.first) return x.second > y.second;
      return x.first < y.first;
  });

  int ans = 0;
  {
    RFOR(remain, 1, N) {
      REP(num, N) {
	int tmp = 101;
	REP(ri, N) {
	  if (state[num][remain][ri]) continue;
	  if (r[ri].first < b[num].first and r[ri].second < b[num].second) {
	    // 入れられる
	    dp[num][remain - 1] = max(dp[num][remain - 1],
				      dp[num][remain] + 1);
	    if (dp[num][remain] = dp[num][remain + 1] + 1) {
	      tmp = ri;
	    }
	  }
	  if (state[num][remain][ri]) state[num][remain - 1][ri] = true;
      	}
	state[num][remain - 1][tmp] = true;
	ans = max(ans, dp[num][remain - 1]);
      }
    }
  }
  // solve(0, N);
  
  cout << ans << endl;

  return 0;
}

