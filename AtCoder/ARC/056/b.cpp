// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ARC 056 駐車場 b.cpp
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

bool state[201010];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(state, false, sizeof(state));
  
  // N: 人数 かつ 注射スペースの数 / M:駐車スペースを結ぶ道の数
  // S:駐車場の入り口と繋がっている駐車場の番号(+1されている状態)
  int N, M, S;
  cin >> N >> M >> S;

  int from, to, last;
  // uv道 : 辺
  vector< pair< int, int > > uv(M, {0, 0});
  REP(i, M) {
    cin >> from >> to;
    from--;
    to--;
    uv[i] = make_pair(from, to);
  }
  sort(ALL(uv));

  // q(last, from)
  queue< int, int > q;
  q.push(-1, S - 1);
  while (!q.empty()) {
    tie(last, from) = q.front();
    q.pop();
  }
  
  
  return 0;
}

