// ------------------------------------
// Date:2018/ 3/ 7
// Problem:ABC 077 SmallMultiple d.cpp
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
#define MIN(a, b) ((a) < (b) ? a : b)

typedef long long ll;

// static const int MOD = 1000000007;
static const int INF = 1e9 + 1;

// V:頂点 / line[from][to]:辺
struct Line {
  Line(int _cost, int _to)
    : cost(_cost), to(_to){}
  int cost;
  int to;
};

vector< Line > l[101010];
int d[101010];

void dijkstra()
{
  // q{cost, from}
  priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > > q;
  fill(d, d + 101010, INF);
  d[1] = 0;
  q.push(make_pair(0, 1));
  
  while (!q.empty()) {
    int cost, from;
    tie(cost, from) = q.top();
    q.pop();

    if (d[from] < cost) continue;

    REP(to, l[from].size()) {
      Line ml = l[from][to];
      if (d[from] + ml.cost < d[ml.to]) {
	d[ml.to] = d[from] + ml.cost;
	q.push(make_pair(d[ml.to], ml.to));
      }
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int K;
  cin >> K;
  REP(i, K) {

    // 次の頂点に対して重み1の辺を追加(K本目の線は最後用に作っておく)
    l[i].emplace_back(Line(1, (i + 1) % K));

    // 10倍の頂点に対して重み0の辺を追加
    l[i].emplace_back(Line(0, (i * 10) % K));
  }

  int ans = 1;
  dijkstra();

  ans += d[0];
  cout << ans << endl;
  
  return 0;
}

