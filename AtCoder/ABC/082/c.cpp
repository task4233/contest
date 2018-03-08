// ------------------------------------
// Date:2018/ 3/ 5
// Problem:ABC 082 GoodSequence c.cpp
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

static const int MOD = 1000000007;

int memo[101010];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(memo, 0, sizeof(memo));
  int N, tmp, cnt = 0;
  cin >> N;
  vector< int > a;
  REP(i, N) {
    cin >> tmp;
    if (tmp > N) {
      // NG
      ++cnt;
    } else {
      // OK
      ++memo[tmp];
    }
  }
  
  REP(i, N + 1) {
    if (memo[i] < i) {
      cnt += memo[i];
    } else {
      cnt += memo[i] - i;
    }
  }

  cout << cnt << endl;
  return 0;
}

