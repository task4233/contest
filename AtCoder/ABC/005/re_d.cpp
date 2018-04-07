// ------------------------------------
// Date:2018/ 4/ 3
// Problem:D - おいしいたこ焼きの焼き方 re_d.cpp
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
const int MAX_N = 51;

// cumulative_sum[height][width]
int cumulative_sum[MAX_N][MAX_N];
int d[MAX_N][MAX_N];
int area[MAX_N * MAX_N];

int N, Q;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  // input
  cin >> N;
  REP(hi, N) {
    REP(wi, N) {
      cin >> d[hi][wi];
    }
  }
  
  // init
  REP(i, N) {
    REP(j, N) {
      cumulative_sum[i][j] = 0;
      area[i * j] = 0;
    }
  }
  
  
  // accumulate
  REP(hi, N) {
    int res = 0;
    cumulative_sum[hi + 1][0] = 0;
    REP(wi, N) {
      res += d[hi][wi];
      cumulative_sum[hi + 1][wi + 1] = cumulative_sum[hi][wi + 1] + res;
    }
  }

  
  /*
  REP(hi, N + 1) {
    REP(wi, N + 1) {
      // cin >> d[hi][wi];
      cout << cumulative_sum[hi][wi];
      if (wi != N) cout << " ";
    }
    cout << endl;
  }
  */

  // update
  FOR(hi, 1, N + 1) {
    FOR(wi, 1, N + 1) {
      REP(height, N + 1 - hi) {
	REP(width, N + 1 - wi) {
	  // debug(hi);
	  // debug(wi);
	  // debug(height);
	  // debug(width);
	  int tmp = cumulative_sum[hi + height][wi + width];
	  // debug(tmp);
	  tmp -= cumulative_sum[hi + height][width];
	  // debug(tmp);
	  tmp -= cumulative_sum[height][wi + width];
	  // debug(tmp);
	  tmp += cumulative_sum[height][width];
	  // debug(tmp);
	  area[hi * wi] = max(area[hi * wi], tmp);
	  // debug(area[height * width])
	}
      }
    }
  }

  REP(i, N * N) {
    // debug(i);
    // debug(area[i]);
    if (i > 0) area[i + 1] = max(area[i], area[i + 1]);
  }
  
  CIN(Q);
  while(Q--) {
    CIN(p);
    int ans = area[p];
    cout << ans << endl;
  }
  return 0;
}

