// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ABC 081 NotSoDiverse c.cpp
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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  scanf("%d %d", &N, &K);
  vector< int > A(N);
  REP(i, N) {
    scanf("%d", &A[i]);
  }

  // d[i]{num(-1), value}
  vector< pair< int, int > > d;
  int cnt = 0;
  REP(i, N) {
    d.emplace_back(make_pair(i, 0));
  }
  REP(i, N) {
    if (A[i] > N) {
      --cnt;
    } else {
      d[A[i] - 1].second++;
    }
  }

  sort(ALL(d), [](pair< int, int > x, pair< int, int > y) { return x.second > y.second; });
  
  FOR(i, K, N) {
    cnt += d[i].second;
  }

  printf("%d\n", cnt);

  return 0;
}

