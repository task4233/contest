// ------------------------------------
// Date:2018/ 3/23
// Problem:_ _ _ rere_1_g.cpp
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

const int MOD = 1e9 + 7;
const int MAX_N = 1e2 + 1;
const int MAX_W = 1e4 + 1;

#define v(i) d[i].first
#define w(i) d[i].second.first
#define m(i) d[i].second.second

pair< int, int > dp[MAX_N][MAX_W];
int N, W;

int main()
{
  scanf("%d %d", &N, &W);
  vector< pair< int, pair< int, int > > > d(N);
  // vector< int > v(N);
  // vector< int > w(N);
  // vector< int > m(N);
  REP(i, N) {
    scanf("%d %d %d", &v(i), &w(i), &m(i));
    // scanf("%d %d %d", &v[i], &w[i], &m[i]);
  }

  memset(dp, 0, sizeof(dp));

  sort(ALL(d), [](pair< int, pair< int, int > > x, pair< int, pair< int, int > > y) {
      return x.first / x.second.first > y.first / y.second.first;
  });
  
  int ans = 0;
  REP(num, N) {
    REP(weight, W + 1) {
      // f: dp[num + 1][weight].first
      // s: dp[num + 1][weight].second
      int f, s;
      if (weight < w(num)) {
	// 上からしか遷移できない
	s = dp[num][weight].second;
	f = 0;
      } else if (dp[num + 1][weight - w(num)].first >= m(num)) {
	//	printf("1-");
	// numからか、dp[num + 1][weight - 1]から遷移
	s = max(dp[num][weight].second, dp[num + 1][weight - 1].second);
	if (s == dp[num][weight].second) {
	  //  printf("1\n");
	  // 選ばれたのが上からのとき
	  f = 0;
	} else {
	  // printf("2\n");
	  f = dp[num + 1][weight - 1].first;
	}
      } else {
	// printf("2-");
	s = max(dp[num][weight].second, dp[num + 1][weight - w(num)].second + v(num));
	if (s == dp[num][weight].second) {
	  // printf("1\n");
	  f = 0;
	} else {
	  // printf("2\n");
	  f = dp[num + 1][weight - w(num)].first + 1;
	}
      }
      dp[num + 1][weight] = make_pair(f, s);
      ans = max(ans, dp[num + 1][weight].second);
      // printf("dp[%d][%d] = {%d, %d}\n", num + 1, weight, dp[num + 1][weight].first, dp[num + 1][weight].second);
    }
  }


  printf("\n");
  REP(i, N + 1) {
    REP(j, W + 1) {
      printf("dp[%d][%d] = {%d, %d}\n", i, j, dp[i][j].first, dp[i][j].second);
    }
  }

  printf("%d\n", ans);

  return 0;
}

