// ------------------------------------
// Date:2018/ 3/15
// Problem:Tenka1'16 PreliminaryA PackDrop b.cpp
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
static const int MAX_N = 1010;

int N, M;
vector< int> g[MAX_N];
int weight[MAX_N];

int dfs(int from)
{
  // すでに訪れている時
  if (weight[from] > 0) return weight[from];

  // debug(from);
  int _min = INF;
  EACH(to, g[from]) {
    // 各頂点から深さ優先探索して最大コストを導出
    _min = min(_min, dfs(to));
  }

  // メモ化
  return weight[from] = _min;
}

ll ans = 0ll;
void dfs2(int from)
{
  EACH(to, g[from]) {
    dfs2(to);
    // 頂点から頂点への重みは変化量なので、その分をansに加える
    ans += weight[to] - weight[from];
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  fill_n(weight, MAX_N, 0);
  cin >> N >> M;
  REP(i, N - 1) {
    int p;
    cin >> p;
    g[p].emplace_back(i + 1);
  }
  REP(i, M) {
    int b, c;
    cin >> b >> c;
    weight[b] = c;
  }

  // cout << "ok" << endl;
  dfs(0);
  weight[0] = 0;
  // cout << "ok2" << endl;
  dfs2(0);
  
  cout << ans << endl;
  
  
  return 0;
}

