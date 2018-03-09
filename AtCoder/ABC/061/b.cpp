// ------------------------------------
// Date:2018/ 3/ 8
// Problem:ABC 061 CountingRoads b.cpp
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

// static const int MOD = 1000000007;

// line[from][to]
int line[55][55];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(line, 0, sizeof(line));
  int N, M;
  cin >> N >> M;
  int from, to;
  REP(i, M) {
    cin >> from >> to;
    --from;
    --to;
    ++line[from][to];
    ++line[to][from];
  }

  int cnt;
  REP(from, N) {
    cnt = 0;
    REP(to, N) {
      cnt += line[from][to];
    }
    cout << cnt << endl;
  }
  
  return 0;
}

