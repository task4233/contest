// ------------------------------------
// Date:2018/ 3/10
// Problem:ABC 070 TransitTreePath d.cpp
//
// ------------------------------------

// dijkstraはパスが一意に定まらない時に使う。

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

struct Line {
  Line(int _to, int _cost)
    : to(_to), cost(_cost) {}
  int to;
  int cost;
};

vector< Line > l[MAX_N];
// d[to]
ll d[MAX_N];


int N;

void bfs(int start)
{
  // q(to)
  queue< int > q;
  q.push(start);
  while(!q.empty()) {
    int from = q.front();
    q.pop();
    REP(to, l[from].size()) {
      Line ml = l[from][to];
      if (d[ml.to] >= 0) continue;
      d[ml.to] = d[from] + ml.cost;
      q.push(ml.to);
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(d, -1ll, sizeof(d));
  cin >> N;

  REP(i, N - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    l[a].emplace_back(Line(b, c));
    l[b].emplace_back(Line(a, c));
  }

  
  int Q, K;
  cin >> Q >> K;

  d[K - 1] = 0;
  bfs(K - 1);
  
  REP(i, Q) {
    int x, y;
    cin >> x >> y;
    cout << d[x - 1] + d[y - 1] << endl;
  }
  
  
  return 0;
}

