// ------------------------------------
// Date:2018/ 3/15
// Problem:ARC 062 AtCoderAndRockPaper d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

static const int INF = 1000000001;
static const int MAX_N = 101010;

string s;
int N;
// dp[num]
int memo[MAX_N];

void solve(int pCnt, int num)
{
  if (num == N) return;
  if (num == 0) {
    if (s[num] == 'p') {
      memo[num] = -1;
    } else {
      memo[num] = 0;
    }
    solve(0, 1);
  } else {
    if (s[num] == 'p') {
      if (pCnt ==  num - pCnt) {
	// グーしか出せない
	memo[num + 1] = memo[num] - 1;
      } else {
	memo[num + 1] = max(memo[num], memo[num] - 1);
	if (memo[num + 1] == memo[num]) pCnt++;
      }
    } else {
      if (pCnt == num - pCnt) {
	// グーしか出せない
	memo[num + 1] = memo[num];
      } else {
	memo[num + 1] = max(memo[num], memo[num] + 1);
	if (memo[num + 1] == memo[num] + 1) pCnt++;
      }
    }
    solve(pCnt, num + 1);
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  fill_n(memo, MAX_N, 0);
  cin >> s;
  N = s.size();

  solve(0, 0);
  int ans = memo[N];
  /*
  REP(i, N + 1) {
    printf("memo[%d] = %d\n", i, memo[i]);
  }
  */
  cout << ans << endl;
  
  return 0;
}

