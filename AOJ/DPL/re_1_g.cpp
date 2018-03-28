// ------------------------------------
// Date:2018/ 3/22
// Problem:Problem with Limitations re_1_g.cpp
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

// dp[num][weight]{remains, value}
pair< int, int > dp[MAX_N][MAX_W];
int N, W;

int main()
{
  scanf("%d %d", &N, &W);
  // d{v, w, m}
  vector< pair< int, pair< int, int > > > d(N);
  REP(i, N) {
    scanf("%d %d %d", &v(i), &w(i), &m(i));
  }

  memset(dp, 0, sizeof(dp));
  sort(ALL(d), [](pair< int, pair< int, int > > x, pair< int, pair< int, int > > y) {
      return x.first > y.first;
  });

  REP(i, N) {
    debug(v(i));
    debug(w(i));
    debug(m(i));
  }
  
  int ans = 0;
  REP(num, N) {
    dp[num + 1][0].first = m(num + 1);
    REP(weight, W + 1) {
      int f, s;
      if (weight < w(num)) {
	f = m(num);
	s = dp[num][weight].second;
      } else if (dp[num + 1][weight - w(num)].first <= 0) {
	f = 0;
	printf("1-");
	if (dp[num + 1][weight - 1].second > dp[num][weight].second + v(num)) {
	  // 隣から
	  printf("1\n");
	  s = dp[num + 1][weight - 1].second;
	} else {
	  // 上から
	  printf("2\n");
	  f = m(num) - 1;
	  s = dp[num][weight].second + v(num);
	}
      } else if (dp[num + 1][weight - w(num)].second + v(num) > dp[num][weight].second) {
	printf("2\n");
	f = dp[num + 1][weight - w(num)].first - 1;
	s = dp[num + 1][weight - w(num)].second + v(num);
	debug(v(num));
	debug(s);
      } else {
	printf("3\n");
	f = m(num);
	s = dp[num][weight].second;
      }
      dp[num + 1][weight] = make_pair(f, s);
      printf("dp[%03d][%03d] = {%03d, %03d}\n", num + 1, weight, dp[num + 1][weight].first, dp[num + 1][weight].second);
      ans = max(ans, dp[num + 1][weight].second);
    }
  }

  printf("\n");
  REP(i, N + 1) {
    REP(j, W + 1) {
      printf("dp[%03d][%03d] = {%03d, %03d}\n", i, j, dp[i][j].first, dp[i][j].second);
    }
  }
  printf("%d\n", ans);
  

  return 0;
}

